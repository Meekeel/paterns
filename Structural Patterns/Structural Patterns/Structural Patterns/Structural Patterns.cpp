#include <iostream>
#include <string>
using namespace std;

/// \brief Абстрактный базовый класс для всех напитков (паттерн "Декоратор")
class Beverage {
public:
    /// \brief Получить описание напитка
    /// \return Строка с описанием
    virtual string getDescription() = 0;

    /// \brief Получить стоимость напитка
    /// \return Цена в долларах
    virtual double cost() = 0;

    /// \brief Виртуальный деструктор
    virtual ~Beverage() {}
};

/// \brief Класс Эспрессо (конкретный компонент)
class Espresso : public Beverage {
public:
    /// \brief Получить описание эспрессо
    /// \return Строка "Эспрессо"
    string getDescription() override { return "Эспрессо"; }

    /// \brief Получить стоимость эспрессо
    /// \return 1.99$
    double cost() override { return 1.99; }
};

/// \brief Класс Чай (конкретный компонент)
class Tea : public Beverage {
public:
    /// \brief Получить описание чая
    /// \return Строка "Чай"
    string getDescription() override { return "Чай"; }

    /// \brief Получить стоимость чая
    /// \return 1.50$
    double cost() override { return 1.50; }
};

/// \brief Абстрактный класс декоратора для добавок
/// \note Является одновременно и напитком, и содержит ссылку на декорируемый объект
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage; ///< Указатель на декорируемый напиток

public:
    /// \brief Конструктор декоратора
    /// \param b Указатель на напиток, который нужно декорировать
    CondimentDecorator(Beverage* b) : beverage(b) {}

    /// \brief Получить описание (делегирует внутреннему объекту)
    /// \return Описание внутреннего напитка
    string getDescription() override { return beverage->getDescription(); }

    /// \brief Получить стоимость (делегирует внутреннему объекту)
    /// \return Стоимость внутреннего напитка
    double cost() override { return beverage->cost(); }
};

/// \brief Декоратор "Молоко"
class Milk : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Напиток, в который добавляется молоко
    Milk(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Добавить молоко к описанию
    /// \return Описание напитка с добавкой ", Молоко"
    string getDescription() override {
        return beverage->getDescription() + ", Молоко";
    }

    /// \brief Добавить стоимость молока
    /// \return Стоимость напитка + 0.10$
    double cost() override {
        return beverage->cost() + 0.10;
    }
};

/// \brief Декоратор "Сахар"
class Sugar : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Напиток, в который добавляется сахар
    Sugar(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Добавить сахар к описанию
    /// \return Описание напитка с добавкой ", Сахар"
    string getDescription() override {
        return beverage->getDescription() + ", Сахар";
    }

    /// \brief Добавить стоимость сахара
    /// \return Стоимость напитка + 0.05$
    double cost() override {
        return beverage->cost() + 0.05;
    }
};

/// \brief Декоратор "Сироп"
class Syrup : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Напиток, в который добавляется сироп
    Syrup(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Добавить сироп к описанию
    /// \return Описание напитка с добавкой ", Сироп"
    string getDescription() override {
        return beverage->getDescription() + ", Сироп";
    }

    /// \brief Добавить стоимость сиропа
    /// \return Стоимость напитка + 0.15$
    double cost() override {
        return beverage->cost() + 0.15;
    }
};

/// \brief Декоратор "Шоколад"
class Chocolate : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Напиток, в который добавляется шоколад
    Chocolate(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Добавить шоколад к описанию
    /// \return Описание напитка с добавкой ", Шоколад"
    string getDescription() override {
        return beverage->getDescription() + ", Шоколад";
    }

    /// \brief Добавить стоимость шоколада
    /// \return Стоимость напитка + 0.20$
    double cost() override {
        return beverage->cost() + 0.20;
    }
};

/// \brief Главная функция для демонстрации работы паттерна "Декоратор"
/// \note Используется для учебного кода
int main()
{
    setlocale(LC_ALL, "rus");  // Устанавливаем русскую локаль

    // Пример 1: Создаем эспрессо с молоком, сахаром и шоколадом
    Beverage* drink1 = new Espresso();
    drink1 = new Milk(drink1);      // Добавляем молоко
    drink1 = new Sugar(drink1);     // Добавляем сахар  
    drink1 = new Chocolate(drink1); // Добавляем шоколад
    cout << drink1->getDescription() << " стоит $" << drink1->cost() << endl;

    // Пример 2: Создаем чай с молоком и сиропом
    Beverage* drink2 = new Tea();
    drink2 = new Milk(drink2);  // Добавляем молоко
    drink2 = new Syrup(drink2); // Добавляем сироп
    cout << drink2->getDescription() << " стоит $" << drink2->cost() << endl;

    // Пример 3: Простой чай без добавок
    Beverage* simpleTea = new Tea();
    cout << simpleTea->getDescription() << " стоит $" << simpleTea->cost() << endl;

    // Освобождаем память
    delete drink1;
    delete drink2;
    delete simpleTea;

    return 0;
}