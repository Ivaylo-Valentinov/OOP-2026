#ifndef _MOVIE_H
#define _MOVIE_H
#include "Date.hpp"

class Movie {
private:
    char* title;
    char* genre;
    unsigned int lenInMinutes;
    Date premiere;
    double cost;
public:
    Movie(const char* t, const char* g, unsigned int l, double c);
    Movie(const Movie& other);
    Movie(Movie&& other) noexcept;
    Movie& operator=(const Movie& other);
    Movie& operator=(Movie&& other) noexcept;
    ~Movie();
    double getAcquisitionCost() const { return cost; }
    void print() const;
};

#endif
