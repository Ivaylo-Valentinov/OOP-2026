#ifndef _USER_H
#define _USER_H
#include "Date.hpp"
#include "Projection.hpp"
#include <vector>

class User {
protected:
    char* firstName;
    char* middleName;
    char* lastName;
    Date birthDate;
    std::vector<Projection*> reservations;

    void addReservation(const Projection& projection) {
        // Добавя прожекцията към reservations.
    }

public:
    User(const char* f, const char* m, const char* l, Date d);
    User(const User& other);
    User(User&& other) noexcept;
    User& operator=(const User& other);
    User& operator=(User&& other) noexcept;
    ~User();

    void printReservations() const {
        // Обхожда всички резервация и вика функцията print() от Projection. 
    }
};

#endif
