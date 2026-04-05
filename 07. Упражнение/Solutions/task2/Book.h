#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <iostream>

constexpr size_t TITLE_MAX = 100;
constexpr size_t AUTHOR_MAX = 50;

class Book
{
public:
	Book();
	Book(const char* title, const char* author, unsigned id);

	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);
	void serialize_binary(std::ostream& os) const;
	void deserialize_binary(std::istream& is);
	void serialize_at(std::ostream& os, std::size_t pos) const;
	void deserialize_at(std::istream& is, std::size_t pos);

private:
	char title[TITLE_MAX + 1];
	char author[AUTHOR_MAX + 1];
	unsigned id;
};

#endif
