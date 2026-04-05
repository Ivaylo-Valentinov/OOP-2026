#include "SharedNote.h"
#include <cstring>

SharedNote::SharedNote(const char* note)
{
	size_t length = strlen(note);
	char* noteContent = new char[length + 1];
	strcpy(noteContent, note);
	this->note = new char* (noteContent);
	this->counter = new size_t(1);
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
	: note(other.note)
	, counter(other.counter)
{
	other.note = nullptr;
	other.counter = nullptr;
}

SharedNote& SharedNote::operator=(SharedNote&& other) noexcept
{
	if (this == &other) {
		return *this;
	}

	decreaseCounter();

	note = other.note;
	counter = other.counter;

	other.note = nullptr;
	other.counter = nullptr;

	return *this;
}

SharedNote::~SharedNote()
{
	decreaseCounter();
}

void SharedNote::decreaseCounter()
{
	if (!counter) {
		return;
	}

	if (*counter > 1) {
		(*counter)--;
		return;
	}

	if (note) {
		delete[] * note;
		delete note;
	}
	delete counter;
	note = nullptr;
	counter = nullptr;
}

const char* SharedNote::getContent() const
{
	return *note;
}

void SharedNote::setContent(const char* noteStr)
{
	delete[] * note;
	size_t len = strlen(noteStr) + 1;
	*note = new char[len];
	strcpy(*note, noteStr);
}

void SharedNote::append(const char* str)
{
	size_t oldLen = strlen(*note);
	size_t addLen = strlen(str);
	char* buf = new char[oldLen + addLen + 1];
	strcpy(buf, *note);
	strcat(buf, str);
	delete[] * note;
	*note = buf;
}
