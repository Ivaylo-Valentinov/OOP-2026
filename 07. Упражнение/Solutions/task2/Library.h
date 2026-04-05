#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"
#include <iostream>

class Library
{
public:
	Library();
	Library(const char* name);
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	void add(const Book& book);
	size_t get_list_size() const;
	const char* get_name() const;

	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);

private:
	char* name;
	Book* books;
	size_t size;
	size_t capacity;

	void free_storage();
	void grow();
	void copy_from(const Library& other);
};

#endif
