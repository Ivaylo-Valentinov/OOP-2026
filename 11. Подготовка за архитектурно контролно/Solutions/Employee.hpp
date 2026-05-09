#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include "User.hpp"

class Employee : public User {
private:
    double salary;
public:
    Employee(const char* f, const char* m, const char* l, Date d, double sal);
    
    // За служители цената, която трябва да платят, е винаги 0.
    double pay(double price) {
        return 0.0;
    }
};

#endif
