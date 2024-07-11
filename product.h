#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <iostream>
#include "subject.h"


class Product {
private:
    /// @brief 
    int productID;
    std::string productName;
    double price;
    int quantity;

    // DiscountStrategy *discountStrategy; // Uncomment this when implementing Strategy Pattern
public:
    Product(int productID, std::string productName, double price, int quantity);
    /// @brief 
    ~Product();
    int getProductID() const { return productID; }
    void setProductID(int productID_) { productID = productID_; }
    std::string getProductName() const { return productName; }
    void setProductName(const std::string &productName_) { productName = productName_; }
    double getPrice() const { return price; }
    void setPrice(double price_) { price = price_; }
    int getQuantity() { return quantity; }
    void setQuantity(int quantity_);// { quantity = quantity_; }

    

};

#endif // PRODUCT_H
