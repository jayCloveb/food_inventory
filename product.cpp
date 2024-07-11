#include "product.h"

Product::Product(int productID, std::string productName, double price, int quantity) 
{
        this->productID = productID;
        this->productName = productName;
        this->price = price;
        this->quantity = quantity;
}


Product::~Product()
{
    //free any dynamically allocated memory
}

void Product::setQuantity(int quantity_)
{
    this->quantity = quantity_;
}


