#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    virtual string getType() = 0;
    virtual string getName() { return getType(); }
    virtual void attack() = 0;
    virtual int getHealth() = 0;
    virtual ~Character() {}
};

class Warrior : public Character {
public:
    string getType() override { return "Воин"; }
    void attack() override { cout << "Воин атакует мечом!" << endl; }
    int getHealth() override { return 100; }
};

class Mage : public Character {
public:
    string getType() override { return "Мар"; }
    void attack() override { cout << "Мар кастует огненный шар!" << endl; }
    int getHealth() override { return 50; }
};

class Archer : public Character {
public:
    string getType() override { return "Лучник"; }
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }
    int getHealth() override { return 70; }
};

class Knight : public Character {
public:
    string getType() override { return "Рыцарь"; }
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
    int getHealth() override { return 80; }
};

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    virtual ~CharacterFactory() {}

    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getName() << " с здоровьем " << chara->getHealth() << ". ";
        chara->attack();
        delete chara;
    }
};

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Archer(); }
};

class KnightFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Knight(); }
};

int main() {
    setlocale(LC_ALL, "rus");

    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack();
    delete factory;

    factory = new MageFactory();
    factory->spawnAndAttack();
    delete factory;

    factory = new ArcherFactory();
    factory->spawnAndAttack();
    delete factory;

    factory = new KnightFactory();
    factory->spawnAndAttack();
    delete factory;

    return 0;
}