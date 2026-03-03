#include "Time.h"

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds)
{
}

void Time::add(const Time& other)
{
	int resultInSeconds = other.getTimeInSeconds() + this->getTimeInSeconds();

	this->hours = resultInSeconds / (60 * 60);
	resultInSeconds -= this->hours * 60 * 60;
	this->minutes = resultInSeconds / 60;
	resultInSeconds -= this->minutes * 60;
	this->seconds = resultInSeconds;
}

Time Time::getDifference(const Time& other) const
{
	int resultInSeconds = other.getTimeInSeconds() - this->getTimeInSeconds();

	Time result;
	result.hours = resultInSeconds / (60 * 60);
	resultInSeconds -= result.hours * 60 * 60;
	result.minutes = resultInSeconds / 60;
	resultInSeconds -= result.minutes * 60;
	result.seconds = resultInSeconds;
	return result;
}

void Time::setHours(int hours)
{
	this->hours = hours;
}

int Time::getHours() const
{
	return this->hours;
}

void Time::setMinutes(int minutes)
{
	this->minutes = minutes;
}

int Time::getMinutes() const
{
	return this->minutes;
}

void Time::setSeconds(int seconds)
{
	this->seconds = seconds;
}

int Time::getSeconds() const
{
	return this->seconds;
}

int Time::getTimeInSeconds() const
{
	return this->seconds + 60 * (this->minutes + 60 * this->hours);
}
