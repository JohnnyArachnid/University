#include <iostream>
#include <memory>
#include <string>

class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Kawa";
    }

    double getCost() const override {
        return 5.0;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> decoratedCoffee;

public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee)
        : decoratedCoffee(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription();
    }

    double getCost() const override {
        return decoratedCoffee->getCost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee)
        : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription() + ", mleko";
    }

    double getCost() const override {
        return decoratedCoffee->getCost() + 1.5;
    }
};

class ChocolateDecorator : public CoffeeDecorator {
public:
    ChocolateDecorator(std::shared_ptr<Coffee> coffee)
        : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription() + ", czekolada";
    }

    double getCost() const override {
        return decoratedCoffee->getCost() + 2.0;
    }
};

int main() {
    std::shared_ptr<Coffee> coffee = std::make_shared<SimpleCoffee>();
    std::cout << coffee->getDescription() << " kosztuje " << coffee->getCost() << " zl\n";

    coffee = std::make_shared<MilkDecorator>(coffee);
    std::cout << coffee->getDescription() << " kosztuje " << coffee->getCost() << " zl\n";

    coffee = std::make_shared<ChocolateDecorator>(coffee);
    std::cout << coffee->getDescription() << " kosztuje " << coffee->getCost() << " zl\n";

    return 0;
}
