#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void setName(std::string name) { _name = name; }
    void printID() { std::cout << "Vehicle ID=" << _id << std::endl; }
    void printName() { std::cout << "Vehicle name=" << _name << std::endl; }
private:
    int _id;
    std::string _name;
};

int main() {
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 1); // call member function on object v
    std::thread t2 = std::thread(&Vehicle::setName, v, "car");

    // wait for thread to finish
    t.join();
    t2.join();
    
    // print Vehicle id
    v->printID();
    v->printName();
    
    return 0;
}