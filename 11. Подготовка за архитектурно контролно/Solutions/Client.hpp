#ifndef _CLIENT_H
#define _CLIENT_H
#include "User.hpp"
#include "Projection.hpp"

class Client : public User {
private:
    char* discountType;
    double balance;

public:
    Client(const char* f, const char* m, const char* l, Date d, const char* disc, double bal);
    // Голямата шестица е нужна заради discountType:
    Client(const Client& other);
    Client(Client&& other) noexcept;
    Client& operator=(const Client& other);
    Client& operator=(Client&& other) noexcept;
    ~Client();

    void deposit(double sum) {
        // Проверявам дали сумата, която искам да се внесе е по-голяма от нула.
        // Ако да, тогава добавям сумата към баланса на потребителя. Ако не, хвърлям грешка.
    }

    // Връща платената сума за прожекцията, изважда я от баланса
    // и после добавя прожекцията 
    double pay(const Projection& proj) {
        // Цената се смята по следния алгоритъм:
        // - Взима се цената от прожекцията.
        // - Изважда се отстъпката. В условието не е написано по какъв начин, затова предполагам, че просто се изважда определен процент от цената на база на типа отстъпка.
        // Проверявам каква е отстъпката използвайки strcmp, и ако не е нито една от тези, които се разпознават, хвърлям грешка. Ако се разпознае типа на отстъпката, смятам каква е цената с отстъпката (например отстъпка 20% -> 0.8 по price)
        // - След това проверявам дали има достатъчно пари в сметката. Ако няма, хвърлям грешка.
        // Ако има, тогава намалям сумата в баланса.
        // Добавя се прожекцията използвайки функцията addReservation от базовия клас.
        // Връща се сумата, която е била платена.
    }
};

#endif
