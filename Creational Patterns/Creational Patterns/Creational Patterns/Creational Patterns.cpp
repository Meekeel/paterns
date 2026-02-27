#include <iostream>
#include <string>
using namespace std;

// Абстрактный базовый класс (интерфейс) для всех персонажей
class Character {
public:
    // Чисто виртуальные методы - должны быть реализованы в классах-наследниках
    virtual string getType() = 0;           // Возвращает тип персонажа
    virtual string getName() { return getType(); }  // Возвращает имя (по умолчанию - тип)
    virtual void attack() = 0;               // Метод атаки
    virtual int getHealth() = 0;              // Возвращает здоровье
    virtual ~Character() {}                    // Виртуальный деструктор
};

// Конкретный класс Воина
class Warrior : public Character {
public:
    string getType() override { return "Воин"; }  // Переопределяем тип
    void attack() override { cout << "Воин атакует мечом!" << endl; }  // Своя реализация атаки
    int getHealth() override { return 100; }  // Своё значение здоровья
};

// Конкретный класс Мага (обратите внимание: в оригинале было "Мар" - опечатка)
class Mage : public Character {
public:
    string getType() override { return "Маг"; }  // Исправлено с "Мар" на "Маг"
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }
    int getHealth() override { return 50; }
};

// Конкретный класс Лучника
class Archer : public Character {
public:
    string getType() override { return "Лучник"; }
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }
    int getHealth() override { return 70; }
};

// Конкретный класс Рыцаря
class Knight : public Character {
public:
    string getType() override { return "Рыцарь"; }
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
    int getHealth() override { return 80; }
};

// Абстрактная фабрика для создания персонажей (паттерн "Фабричный метод")
class CharacterFactory {
public:
    // Фабричный метод - создает персонажа (чисто виртуальный)
    virtual Character* createCharacter() = 0;
    virtual ~CharacterFactory() {}

    // Шаблонный метод, использующий фабричный метод
    void spawnAndAttack() {
        Character* chara = createCharacter();  // Создаем персонажа через фабрику
        cout << "Создан " << chara->getName() << " с здоровьем " << chara->getHealth() << ". ";
        chara->attack();  // Вызываем атаку
        delete chara;      // Освобождаем память
    }
};

// Конкретная фабрика для создания Воина
class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Warrior(); }
};

// Конкретная фабрика для создания Мага
class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};

// Конкретная фабрика для создания Лучника
class ArcherFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Archer(); }
};

// Конкретная фабрика для создания Рыцаря
class KnightFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Knight(); }
};

int main() {
    setlocale(LC_ALL, "rus");  // Устанавливаем русскую локализацию для вывода

    // Создаем воина через фабрику
    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack();  // Создаем и атакуем
    delete factory;  // Освобождаем память фабрики

    // Создаем мага через фабрику
    factory = new MageFactory();
    factory->spawnAndAttack();
    delete factory;

    // Создаем лучника через фабрику
    factory = new ArcherFactory();
    factory->spawnAndAttack();
    delete factory;

    // Создаем рыцаря через фабрику
    factory = new KnightFactory();
    factory->spawnAndAttack();
    delete factory;

    return 0;
}