#include "Hero.hpp"
#include <iostream>

Hero::Hero(size_t threshold) 
    : hp(100), xp(0), level(1), xpThreshold(threshold) {}

void Hero::takeDamage(size_t damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    std::cout << "RPG hero took " << damage << " damage!" << std::endl;
}

void Hero::heal(size_t amount) {
    if (hp > 0) {
        hp += amount;
        if (hp > 100) hp = 100; // Примерна граница на здравето
        std::cout << "RPG Hero healed for " << amount << " HP." << std::endl;
    } else {
        std::cout << "RPG Hero is dead and cannot be healed." << std::endl;
    }
}

void Hero::gainXP(size_t points) {
    xp += points;
    while (xp >= xpThreshold) {
        xp -= xpThreshold;
        level++;
        std::cout << "LEVEL UP! RPG Hero is now level " << level << "!" << std::endl;
    }
}

void Hero::print() const {
    std::cout << "--- Hero Stats ---" << std::endl;
    std::cout << "LVL: " << level << "\nHP: " << hp 
              << "\nXP: " << xp << "/" << xpThreshold << std::endl;
}
