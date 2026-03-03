#pragma once
#include "Time.h"
const size_t MAX_SIZE = 129;

class Event
{
public:
    Event();
    Event(const Time& startTime, const Time& endTime, const char* title, const char* organizer);
    Time getDuration() const;

private:
    Time startTime;
    Time endTime;
    char title[MAX_SIZE];
    char organizer[MAX_SIZE];
};

