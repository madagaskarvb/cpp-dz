#include <iostream>
#include <string>
#include <list>

class Vehicle {
public:
    virtual void move(double time) = 0;
    virtual ~Vehicle() = default;
};

class LandVehicle : public Vehicle {
protected:
    double currentVelocity;
    double distance;       

public:
    LandVehicle(double velocity) : currentVelocity(velocity), distance(0) {}

    double getCurrentVelocity() const {
        return currentVelocity;
    }

    double getDistance() const {
        return distance;
    }

    void move(double time) override {
        distance += currentVelocity * time;
    }
};

class Car : public LandVehicle {
public:
    Car(double velocity) : LandVehicle(velocity) {}

    void move(double time) override {
        distance += currentVelocity * time;
    }
};

class Truck : public LandVehicle {
public:
    Truck(double velocity) : LandVehicle(velocity) {}

    void move(double time) override {
        distance += currentVelocity * time;
    }
};

class Motorcycle : public LandVehicle {
public:
    Motorcycle(double velocity) : LandVehicle(velocity) {}

    void move(double time) override {
        distance += currentVelocity * time;
    }
};

class Bicycle : public LandVehicle {
public:
    Bicycle(double velocity) : LandVehicle(velocity) {}

    void move(double time) override {
        distance += currentVelocity * time;
    }
};

int main() {
    // Создаем объекты различных транспортных средств
    Car car(60);       // Скорость 60 км/ч
    Truck truck(50);   // Скорость 50 км/ч
    Motorcycle bike(80); // Скорость 80 км/ч
    Bicycle bicycle(20); // Скорость 20 км/ч

    car.move(342682);
    truck.move(9);
    bike.move(6);
    bicycle.move(2);

    
    std::cout << car.getDistance() << std::endl;
    std::cout << truck.getDistance() << std::endl;
    std::cout << bike.getDistance() << std::endl;
    std::cout << bicycle.getDistance() << std::endl;

    return 0;
}
