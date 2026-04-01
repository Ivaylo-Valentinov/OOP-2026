#include "SharedNote.h"
#include <cstring>

SharedNote::SharedNote(const char* note)
{
	size_t length = strlen(note);
	this->note = new char[length + 1];
	strcpy(this->note, note);

	counter = new size_t(1);
}

SharedNote::SharedNote(const SharedNote& other)
{
	note = other.note;
	counter = other.counter;

	(*counter)++;
}

SharedNote& SharedNote::operator=(const SharedNote& other)
{
	if (this->note != other.note) {
		decreaseCounter();

		this->note = other.note;
		this->counter = other.counter;
		(*counter)++;
	}

	return *this;
}

SharedNote::SharedNote(SharedNote&& other) noexcept
{
	note = other.note;
	counter = other.counter;

	(*counter)++;
}

SharedNote& SharedNote::operator=(SharedNote&& other) noexcept
{
	if (this->note != other.note) {
		decreaseCounter();

		this->note = other.note;
		this->counter = other.counter;
		(*counter)++;
	}

	return *this;
}

SharedNote::~SharedNote()
{
	decreaseCounter();
}

void SharedNote::decreaseCounter()
{
	if (*counter > 1) {
		(*counter)--;
		return;
	}

	delete[] note;
	delete counter;
}
