#ifndef _HALL_H
#define _HALL_H

class Hall {
private:
    char* name;
    unsigned int seats;

public:
    Hall(const char* t, double c);
    Hall(const Hall& other);
    Hall(Hall&& other) noexcept;
    Hall& operator=(const Hall& other);
    Hall& operator=(Hall&& other) noexcept;
    ~Hall();
    double getSeats() const { return seats; }
    void print() const;
};

#endif
