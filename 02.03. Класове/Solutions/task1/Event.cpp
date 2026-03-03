#include "Event.h"
#include <cstring>

Event::Event()
{
    strcpy(title, "");
    strcpy(organizer, "");
}

Event::Event(const Time& startTime, const Time& endTime, const char* title, const char* organizer): startTime(startTime), endTime(endTime)
{
    strcpy(this->title, title);
    strcpy(this->organizer, organizer);
}

Time Event::getDuration() const
{
    return startTime.getDifference(endTime);
}
