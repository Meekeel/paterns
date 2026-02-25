#include <iostream>
#include <string>
using namespace std;

class Beverage {
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage {
public:
    string getDescription() override { return "Эспрессо"; }
    double cost() override { return 1.99; }
};


class Tea : public Beverage {
public:
    string getDescription() override { return "Чай"; }
    double cost() override { return 1.50; }
};


class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;
public:
    CondimentDecorator(Beverage* b) : beverage(b) {}
    string getDescription() override { return beverage->getDescription(); }
    double cost() override { return beverage->cost(); }
};

class Milk : public CondimentDecorator {
public:
    Milk(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Молоко"; }
    double cost() override { return beverage->cost() + 0.10; }
};

class Sugar : public CondimentDecorator {
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Сахар"; }
    double cost() override { return beverage->cost() + 0.05; }
};

class Syrup : public CondimentDecorator {
public:
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Сироп"; }
    double cost() override { return beverage->cost() + 0.15; }
};

class Chocolate : public CondimentDecorator {
public:
    Chocolate(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Шоколад"; }
    double cost() override { return beverage->cost() + 0.20; }
};

int main()
{
    setlocale(LC_ALL, "rus");

    Beverage* drink1 = new Espresso();
    drink1 = new Milk(drink1);
    drink1 = new Sugar(drink1);
    drink1 = new Chocolate(drink1);
    cout << drink1->getDescription() << " стоит $" << drink1->cost() << endl;
  

    Beverage* drink2 = new Tea();
    drink2 = new Milk(drink2);
    drink2 = new Syrup(drink2);
    cout << drink2->getDescription() << " стоит $" << drink2->cost() << endl;

    Beverage* simpleTea = new Tea();
    cout << simpleTea->getDescription() << " стоит $" << simpleTea->cost() << endl;

    delete drink1;
    delete drink2;
    delete simpleTea;

    return 0;
}