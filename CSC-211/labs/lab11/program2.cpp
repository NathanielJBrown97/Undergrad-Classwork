#include <iostream>
#include <string>

class Car
{
private:
    std::string make;
    std::string model;
    std::string color;
    int year;
    double mileage;

public:
    Car(std::string make, std::string model, std::string color, int year)
    {
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
        this->mileage = 0;
    }
    // setCharacteristic
    void setMake(std::string someMake)
    {
        this->make = someMake;
    }
    void setModel(std::string someModel)
    {
        this->model = someModel;
    }
    void setColor(std::string someColor)
    {
        this->color = someColor;
    }
    void setYear(int someYear)
    {
        this->year = someYear;
    }
    void setMileage(double someMileage)
    {
        this->mileage = someMileage;
    }
    // getCharacteristic
    std::string getMake()
    {
        return this->make;
    }
    std::string getModel()
    {
        return this->model;
    }
    std::string getColor()
    {
        return this->color;
    }
    int getYear()
    {
        return this->year;
    }
    double getMileage()
    {
        return this->mileage;
    }

    void printCarDetails()
    {
        std::cout << "Make: " << this->make << std::endl;
        std::cout << "Model: " << this->model << std::endl;
        std::cout << "Color: " << this->color << std::endl;
        std::cout << "Year: " << this->year << std::endl;
        std::cout << "Mileage: " << this->mileage << std::endl;
    }
};

// Constructs a car object
int main()
{
    // constructors and outputs

    // car 1
    Car car1("Lincoln", "Zephyr", "Black", 2006);
    car1.setMileage(241666);
    std::cout << "First Car: " << std::endl;
    car1.printCarDetails();
    std::cout << std::endl;

    // car 2

    Car car2("Tesla", "Model S", "Red", 2020);
    car2.setMileage(49653);
    std::cout << "Second Car: " << std::endl;
    car2.printCarDetails();
    std::cout << std::endl;

    // car 3
    std::cout << "Third Car: " << std::endl;
    Car car3("Volkswagen", "Golf", "Red", 1997);
    car3.setMileage(88350);
    car3.printCarDetails();
    std::cout << std::endl;
}
