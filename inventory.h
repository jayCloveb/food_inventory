#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <iostream>
#include "product.h"
#include <mutex>
#include <thread>
#include <vector>
#include "iobserver.h"
#include <unordered_map>
#include <string>

/**
 * The Inventory class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Inventory 
{

    /**
     * The Inventory's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
private:
    static Inventory * pinstance_;
    static std::mutex mutex_;

    std::vector<std::unique_ptr<Product>> products;
    std::unordered_map<std::string, int> thresholds;
    IObserver* observer;


protected:
    Inventory(const std::string value, IObserver* obs): value_(value),observer(obs)
    {
    }
    ~Inventory();
    std::string value_;

public:
    /**
     * Inventorys should not be cloneable.
     */
    Inventory(Inventory &other) = delete;
    /**
     * Inventorys should not be assignable.
     */
    void operator=(const Inventory &) = delete;
    /**
     * This is the static method that controls the access to the Inventory
     * instance. On the first run, it creates a Inventory object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Inventory *GetInstance(const std::string& value, IObserver* obs);
    
    /**
     * Finally, any Inventory should define some methods, which can be
     * executed on its instance.
     */

    int addProduct(std::unique_ptr<Product> product, int threshold);
    int removeProduct(const std::string productName);
    int removeProductQuantity(const std::string productName, int quantity);
    int addProductQuantity(const std::string productName, int quantity);

    void displayProducts();
    std::unique_ptr<Product>* findProduct(const std::string productName);
 

    
    std::string value() const{
        return value_;
    }

    std::unordered_map<std::string, int> getThresholds() const { return thresholds; }
    void setThresholds(const std::unordered_map<std::string, int> &thresholds_) { thresholds = thresholds_; }

    
};

#endif // INVENTORY_H
