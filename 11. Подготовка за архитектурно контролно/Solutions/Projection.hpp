#ifndef _PROJECTION_H
#define _PROJECTION_H
#include "Movie.hpp"
#include "Hall.hpp"
#include "Date.hpp"

class Projection {
private:
    Movie* movie; // Връзка към филм от списъка в CinemaManager
    Hall* hall;
    DateTime time;
    unsigned int takenSeats;
    double price;

public:
    Projection(Movie* m, Hall* h, DateTime t, double p) {
        // За прожекциите не е нужно да пишем голяма шестица, защото
        // Movie е указател към филм, но за паметта на всички филми се грижи CinemaManager.
        // Тоест CinemaManager трябва да освободи паметта за филма.
        // Същото се отнася и за Hall.

        // Ако m или h са nullptr, тогава се хвърля грешка.
        // Проверява се дали t е валиден час и година. Ако не е, тогава се хвърля грешка.
    }
    bool hasFreeSeats() const { return takenSeats < hall->getSeats(); }
    void bookSeat() { takenSeats++; }
    double getPrice() const { return price; }
    void print() const {
        // Принтира се информацията за прожекцията като се извикват и функциите print на Movie и Hall.
    }
};

#endif
