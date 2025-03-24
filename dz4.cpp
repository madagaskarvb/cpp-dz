#include <iostream>
#include <vector>

class Package
{
private:
    std::string name;
    float weight;

    Package() : name("apple"), weight(100) {}

    Package(Package const& other) {
        name = other.name;
        weight = other.weight;
    }

public:


    ~Package() = default;

    float getWeight() const {
        return weight;
    }

    friend class Truck;
};

class Car
{
protected:
    std::string manufacturer;
    std::string model;
    int year;
    std::string colour;
    int kms;
    int price;

public:

    Car() : manufacturer("Ford"), model("F150"), year(2000), colour("white"), kms(1000), price(10000) {}

    ~Car() = default;

    Car(Car const& other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
    }

    Car& operator=(Car const& other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
        return *this;
    }

    void setColour(const char* c) {
        colour = c;
    }

    void setKms(int km) {
        kms = kms;
    }

    void setPrice(int p) {
        price = p;
    }

    std::string getColour() const {
        return colour;
    }

    int getKms() const {
        return kms;
    }

    int getPrice() const {
        return price;
    }
};


class Truck final : public Car
{
private:
    float max_payload;
    std::vector<Package> packages;

public:
    Truck()
        : Car()
        , max_payload(10000)
        , packages({})
    { }

    Truck(Truck const& other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
    }

    Truck& operator=(Truck const& other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
        return *this;
    }

    ~Truck() = default;

    bool isReady() {
        float sum = 0;
        for (int i = 0; i < packages.size(); i++) {
            sum += packages[i].getWeight();
        }
        if (sum > max_payload) {
            return false;
        }
    }

    void addPackage() {
        Package p;
        packages.push_back(p);
    }
};



int main()
{
    Car c;
    Truck t;
    std::cout << t.getColour() << std::endl;
}