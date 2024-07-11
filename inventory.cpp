#include "inventory.h"
#include "productFactory.h"


/**
 * Static methods should be defined outside the class.
 */

Inventory* Inventory::pinstance_{nullptr};
std::mutex Inventory::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Inventory::~Inventory()
{
    delete pinstance_;
}
Inventory *Inventory::GetInstance(const std::string &value, IObserver* obs)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Inventory(value, obs);
    }
    return pinstance_;
}


int Inventory::addProduct(std::unique_ptr<Product> product, int threshold)
{        
    thresholds[product->getProductName()] = threshold;
    products.push_back(std::move(product));
    // products.push_back(product);
    return 0;
}

int Inventory::removeProduct(const std::string productName)
{    
    int index = 0;
    for (auto &product : products)
    {
        if(product->getProductName() == productName)
        {          
            products.erase(products.begin()+index); 
            return 0;
        }
        index++;
    }    
    return 1;
}

int Inventory::removeProductQuantity(const std::string productName, int quantity)
{    
    for (auto &product : products)
    {
        if(product->getProductName() == productName)
        {
            int currentQuantity = product->getQuantity();
            if (currentQuantity >= quantity)
            {
                product->setQuantity(currentQuantity - quantity);
                std::cout << "Used " << quantity << " of " << productName << ". Remaining: " << product->getQuantity() << std::endl;
                if (product->getQuantity() < thresholds[productName])
                {
                    observer->Update(productName, product->getQuantity());
                }
            }
            else
            {
                std::cout << "Not enough " << product->getProductName() << " to remove " << quantity << std::endl;
            }

            return 0;
        }
    }    
    return 1;
}

int Inventory::addProductQuantity(const std::string productName, int quantity)
{    
    for (auto &product : products)
    {
        if (product->getProductName() == productName)
        {
            int currentQuantity = product->getQuantity();
            product->setQuantity(currentQuantity + quantity);
            std::cout << "Added " << quantity << " of " << productName << ". Total: " <<  product->getQuantity() << std::endl;

            return 0;
        }
    }
    return 1;
}


std::unique_ptr<Product>* Inventory::findProduct(const std::string productName)
{
    int index = 0;
    for (auto &product : products)
    {
        if(product->getProductName() == productName)
        {          
            return &product;
        }
        index++;
    }    

    return nullptr;
}


// Method to display all products in the inventory
void Inventory::displayProducts()
{
    for (const auto &product : products)
    {
        // Print product details
        std::cout << product->getProductName() << " " << product->getQuantity() << " " <<  thresholds[product->getProductName()] << std::endl;
    }
}
