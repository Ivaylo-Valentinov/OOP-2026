#ifndef HERO_H
#define HERO_H

class Hero {
private:
    int hp;
    size_t xp;
    size_t level;
    size_t xpThreshold;

public:
    Hero(size_t threshold);
    void takeDamage(size_t damage);
    void heal(size_t amount);
    void gainXP(size_t points);
    void print() const;
};

#endif
