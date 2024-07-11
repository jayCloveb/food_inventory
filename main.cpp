#include "product.h"
#include "productFactory.h"
#include "inventory.h"
#include <iostream>



int main() {

    Notification notification;
    Inventory* inventory = Inventory::GetInstance("MyFood", &notification);
    std::cout << inventory->value() << std::endl;
    // InventoryObserver observer2(6); // Set threshold to 5

    std::unique_ptr<Product> apple = ProductFactory::CreateProduct(0, "Apple", 0.99, 14);    
    std::unique_ptr<Product> orange = ProductFactory::CreateProduct(1, "Orange", 0.55, 5);
    std::unique_ptr<Product> bread = ProductFactory::CreateProduct(2, "Bread", 0.99, 20);
    std::unique_ptr<Product> rice = ProductFactory::CreateProduct(3, "Rice", 0.99, 25);
    std::unique_ptr<Product> icedTea = ProductFactory::CreateProduct(4, "Iced Tea", 1.99, 5);
    std::unique_ptr<Product> milk = ProductFactory::CreateProduct(5, "Milk", 1.55, 6);
    std::unique_ptr<Product> cornFlakes = ProductFactory::CreateProduct(6, "Corn Flakes", 3.99, 2);
    
    

    // Add the Product to the Inventory
    inventory->addProduct(std::move(apple), 5);
    inventory->addProduct(std::move(orange), 6);
    inventory->addProduct(std::move(bread), 7);
    inventory->addProduct(std::move(rice), 8);
    inventory->addProduct(std::move(icedTea), 9);
    inventory->addProduct(std::move(milk), 10);
    inventory->addProduct(std::move(cornFlakes), 11);

    inventory->removeProductQuantity("Apple", 10);
    inventory->removeProductQuantity("Rice", 20);

    
    // inventory->addProductQuantity("Apple", 2);


    inventory->findProduct("Apple");

    inventory->displayProducts();

    std::cout << "-----------------------------------------------------------------------------------" << std::endl;

    std::unique_ptr<Product>* productItem = inventory->findProduct("Apple");

    if (productItem)
    {
        std::cout << "Found: " << std::endl;
        std::cout << (*productItem)->getProductName() << std::endl;
        std::cout << "Price: " << (*productItem)->getPrice() << std::endl;
        std::cout << "Quantity: " << (*productItem)->getQuantity() << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    }

    if(!inventory->removeProduct("Milk")) 
    {
        std::cout << "Milk removed from inventory" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    }
    
    inventory->displayProducts();
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;

}
