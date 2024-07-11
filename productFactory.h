#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

// #include <iostream>
#include <memory>
#include "product.h"

class ProductFactory {
public:
    static std::unique_ptr<Product> CreateProduct(int id, const std::string& name, double price, int quantity) {
        return std::make_unique<Product>(id, name, price, quantity);
    }
};


#endif // PRODUCTFACTORY_H
