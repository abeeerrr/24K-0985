#include <iostream>
#include <string>
using namespace std;

const int MAX_CHARACTERS = 100;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void displayStats() const {
        cout << "Character ID: " << characterID << "\nName: " << name
             << "\nLevel: " << level << "\nHealth Points: " << healthPoints
             << "\nWeapon Type: " << weaponType << endl;
    }

    virtual ~Character() {}
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int damage, string weapon = "Sword")
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() const override {
        cout << name << " attacks with melee weapon causing " << meleeDamage << " damage." << endl;
    }

    void defend() const override {
        cout << name << " defends with armor of strength " << armorStrength << "." << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int spell, string weapon = "Staff")
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void attack() const override {
        cout << name << " casts a spell with power " << spellPower << "." << endl;
    }

    void defend() const override {
        cout << name << " defends using a magical barrier with " << manaPoints << " mana points." << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy, string weapon = "Bow")
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() const override {
        cout << name << " attacks from range with accuracy " << rangedAccuracy << "." << endl;
    }

    void defend() const override {
        cout << name << " dodges the attack using agility." << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agi, string weapon = "Dagger")
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void attack() const override {
        cout << name << " attacks with stealth, inflicting critical damage." << endl;
    }

    void defend() const override {
        cout << name << " uses agility to evade attacks." << endl;
    }

    void displayStats() const override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior warrior(1, "Arthur", 10, 100, 50, 30);
    Mage mage(2, "Merlin", 12, 80, 100, 40);
    Archer archer(3, "Robin", 9, 70, 30, 85);
    Rogue rogue(4, "Shade", 8, 60, 90, 80);

    Character* characters[MAX_CHARACTERS];
    int characterCount = 0;

    characters[characterCount++] = &warrior;
    characters[characterCount++] = &mage;
    characters[characterCount++] = &archer;
    characters[characterCount++] = &rogue;

    for (int i = 0; i < characterCount; ++i) {
        characters[i]->displayStats();
        characters[i]->attack();
        characters[i]->defend();
        cout << "\n";
    }

    return 0;
}
