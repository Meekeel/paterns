#include <iostream>
#include <string>
using namespace std;

/// \brief Абстрактный базовый класс для всех персонажей
class Character {
public:
    /// \brief Получить тип персонажа
    /// \return Строка с типом персонажа
    virtual string getType() = 0;

    /// \brief Получить имя персонажа
    /// \return Строка с именем персонажа
    virtual string getName() { return getType(); }

    /// \brief Выполнить атаку персонажа
    virtual void attack() = 0;

    /// \brief Получить здоровье персонажа
    /// \return Количество здоровья
    virtual int getHealth() = 0;

    /// \brief Виртуальный деструктор
    virtual ~Character() {}
};

/// \brief Класс Воина
class Warrior : public Character {
public:
    /// \brief Получить тип персонажа
    /// \return Строка "Воин"
    string getType() override { return "Воин"; }

    /// \brief Выполнить атаку мечом
    void attack() override { cout << "Воин атакует мечом!" << endl; }

    /// \brief Получить здоровье воина
    /// \return 100 HP
    int getHealth() override { return 100; }
};

/// \brief Класс Мага
class Mage : public Character {
public:
    /// \brief Получить тип персонажа
    /// \return Строка "Маг"
    string getType() override { return "Маг"; }

    /// \brief Выполнить атаку огненным шаром
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }

    /// \brief Получить здоровье мага
    /// \return 50 HP
    int getHealth() override { return 50; }
};

/// \brief Класс Лучника
class Archer : public Character {
public:
    /// \brief Получить тип персонажа
    /// \return Строка "Лучник"
    string getType() override { return "Лучник"; }

    /// \brief Выполнить атаку из лука
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }

    /// \brief Получить здоровье лучника
    /// \return 70 HP
    int getHealth() override { return 70; }
};

/// \brief Класс Рыцаря
class Knight : public Character {
public:
    /// \brief Получить тип персонажа
    /// \return Строка "Рыцарь"
    string getType() override { return "Рыцарь"; }

    /// \brief Выполнить атаку копьём
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }

    /// \brief Получить здоровье рыцаря
    /// \return 80 HP
    int getHealth() override { return 80; }
};

/// \brief Абстрактная фабрика для создания персонажей (паттерн "Фабричный метод")
class CharacterFactory {
public:
    /// \brief Функция для выделения памяти на класс персонажа
    /// \return Возвращает указатель на созданного персонажа
    virtual Character* createCharacter() = 0;

    /// \brief Виртуальный деструктор
    virtual ~CharacterFactory() {}

    /// \brief Создать персонажа и выполнить атаку
    /// \note Используется для демонстрации работы фабрики
    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getName() << " с здоровьем " << chara->getHealth() << ". ";
        chara->attack();
        delete chara;
    }
};

/// \brief Класс для создания Воина
class WarriorFactory : public CharacterFactory {
public:
    /**
     * \brief Функция для выделения памяти на класс персонажа
     * \return Возвращает указатель на созданного персонажа
     */
    Character* createCharacter() override { return new Warrior(); }
};

/// \brief Класс для создания Мага
class MageFactory : public CharacterFactory {
public:
    /**
     * \brief Функция для выделения памяти на класс персонажа
     * \return Возвращает указатель на созданного персонажа
     */
    Character* createCharacter() override { return new Mage(); }
};

/// \brief Класс для создания Лучника
class ArcherFactory : public CharacterFactory {
public:
    /**
     * \brief Функция для выделения памяти на класс персонажа
     * \return Возвращает указатель на созданного персонажа
     */
    Character* createCharacter() override { return new Archer(); }
};

/// \brief Класс для создания Рыцаря
class KnightFactory : public CharacterFactory {
public:
    /**
     * \brief Функция для выделения памяти на класс персонажа
     * \return Возвращает указатель на созданного персонажа
     */
    Character* createCharacter() override { return new Knight(); }
};

/// \brief Функция для запуска конвейера с персонажами
/// \note Используется для учебного кода
int main()
{
    setlocale(LC_ALL, "rus");

    // Симуляция игры: создаем разных персонажей через фабрики
    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack(); // Вывод: Создан Воин с здоровьем 100. Воин атакует мечом!
    delete factory;

    factory = new MageFactory();
    factory->spawnAndAttack(); // Вывод: Создан Маг с здоровьем 50. Маг кастует огненный шар!
    delete factory;

    factory = new ArcherFactory();
    factory->spawnAndAttack(); // Вывод: Создан Лучник с здоровьем 70. Лучник стреляет из лука!
    delete factory;

    factory = new KnightFactory();
    factory->spawnAndAttack(); // Вывод: Создан Рыцарь с здоровьем 80. Рыцарь атакует копьём!
    delete factory;

    return 0;
}