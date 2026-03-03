#pragma once
class Time
{
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    void add(const Time& other);
    Time getDifference(const Time& other) const;
    void setHours(int hours);
    int getHours() const;
    void setMinutes(int minutes);
    int getMinutes() const;
    void setSeconds(int seconds);
    int getSeconds() const;

private:
    int hours;
    int minutes;
    int seconds;

    int getTimeInSeconds() const;
};

