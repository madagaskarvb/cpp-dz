#include <iostream>

class Car
{
private:
    std::string manufacturer;
    std::string model;
    int year;
    std::string colour;
    int kms;
    int price;

public:

    Car(std::string manufacturer, std::string model, int year, std::string colour, int kms, int price) {
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;
        this->colour = colour;
        this->kms = kms;
        this->price = price;
    }

    Car(Car const & other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
    }

    Car& operator=(Car const & other) {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        colour = other.colour;
        kms = other.kms;
        price = other.price;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Car& car);

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
}


int main()
{

}