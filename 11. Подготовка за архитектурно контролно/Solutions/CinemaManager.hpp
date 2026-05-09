#ifndef _CINENA_MANAGER_H
#define _CINENA_MANAGER_H
#include "Movie.hpp"
#include "Projection.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include <vector>

class CinemaManager {
private:
    double cinemaVault;
    
    // Списъци от обекти
    std::vector<Hall> halls;
    std::vector<Movie> movies;
    std::vector<Projection> schedule;
    std::vector<Client> clients;
    std::vector<Employee> employees;

public:
    CinemaManager(std::vector<Hall> h, double initialCapital) {
        //Инициализираме списъка от зали използвайки този, който е подаден при създаването на обекта.
        // Инициализираме cinemaVault в първоначалния капитал (initialCapital)
    }

    // Шаблонна функция за закупуване на билет
    template <typename T>
    void buyTicket(T& user, Projection& proj) {
        // Ако прожекцията няма свободни места, функцията хвърля грешка.

        // Разчитаме, че user има имплементирана функция pay, която ще се използва за запазване на място:
        double paidAmount = user.pay(proj);
        cinemaVault += paidAmount;
        proj.bookSeat();
    }

    void addClient(const char* f, const char* m, const char* l, Date d, const char* disc, double bal) {
        // Използвайките подадените параметри се създава Client обект, който се добавя към масива clients.
    }

    void addEmployee(const char* f, const char* m, const char* l, Date d, double sal) {
        // Използвайките подадените параметри се създава Employee обект, който се добавя към масива employees.
    }

    void addMovie(const char* t, const char* g, unsigned int l, double c) {
        // Използвайките подадените параметри се създава Movie обект, който се добавя към масива movies.
        // Ако се използваше Movie* movies. Тогава трябва да се разпише, че:
        // - създава се временен масив с по-голям размер
        // - копират се стойностите от стария и се добавя новия обект в края
        // - освобождават се данните от стария масив
        // - пренасочва се movies да сочи към новосъздадения масив.
    }

    void addProjection(unsigned int movieId, unsigned int hallId, DateTime t, double p) {
        // Използвайки индексите се намират правилните обекти за movie и hall.
        // Използвайки тези обекти се създава нов Projection обект, който се добавя към projections масива.
    }

    void depositMoneyForClient(unsigned int clientIndex, double money) {
        // Ако clientIndex е твърде голямо число (масивът clients няма толкова елементи) ще се хвърли грешка.
        // След като се достъпи правилния елемент, тогава се вика deposit използвайки money като параметър.
    }

    void printSchedule() const {
        // Обхождат се всички резервации и се изписва информацията за всяка една от тях.
        // По принцип може да се направи и по-умно и да се изпише например по зали, но не е нужно.
    }

    void printClientReservations(unsigned int clientIndex) const {
        // Ако clientIndex е твърде голямо число (масивът clients няма толкова елементи) ще се хвърли грешка.
        // След като се достъпи правилния елемент, тогава се вика printReservations.
    }

    void printEmployeeReservations(unsigned int employeeIndex) const {
        // Ако employeeIndex е твърде голямо число (масивът employees няма толкова елементи) ще се хвърли грешка.
        // След като се достъпи правилния елемент, тогава се вика printReservations.
    }

    // За пълнота би било добре да се добави и намиране на индексите за client, employee, movie и hall по някакви лесни за запомняне данни
    // като име например, но реално не се изискват по условие. 
};

#endif
