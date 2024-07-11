#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <iostream>


// Observer interface
class IObserver {
public:
    virtual void Update(const std::string& food, int quantity) = 0;
};

// Concrete Observer
class Notification : public IObserver {
public:
    void Update(const std::string& food, int quantity) override {
        std::cout << "Notification: " << food << " quantity is below threshold: " << quantity << std::endl;
    }
};

#endif // IOBSERVER_H
