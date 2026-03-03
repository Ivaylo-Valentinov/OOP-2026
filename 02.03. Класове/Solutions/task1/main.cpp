#include <iostream>
#include <cstring>
#include "Time.h"
#include "Event.h"

int main() {
    size_t n; Time duration = { 0,0,0 };
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin.ignore(); //std::cin.get();
        char title[MAX_SIZE];
        char organizer[MAX_SIZE];
        std::cin.getline(title, MAX_SIZE);
        std::cin.getline(organizer, MAX_SIZE);
        int hours, minutes, seconds;
        std::cin >> hours >> minutes >> seconds;
        Time startTime(hours, minutes, seconds);
        std::cin >> hours >> minutes >> seconds;
        Time endTime(hours, minutes, seconds);
        Event e(startTime, endTime, title, organizer);
        duration.add(e.getDuration());
    }
    std::cout << "Duration: " << duration.getHours() << ":" << duration.getMinutes() << ":" << duration.getSeconds() << std::endl;

    return 0;
}
