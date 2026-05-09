#ifndef _DATE_H
#define _DATE_H

struct Date {
    int day, month, year;
};

struct DateTime: public Date {
    int hour, minute;
};

#endif
