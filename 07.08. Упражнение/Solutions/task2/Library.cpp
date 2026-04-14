#include "Library.h"
#include <cstring>

Library::Library()
	: name(nullptr)
	, books(nullptr)
	, size(0)
	, capacity(0)
{
	name = new char[1];
	name[0] = '\0';
}

Library::Library(const char* libName)
	: Library()
{
	if (libName) {
		delete[] name;
		const std::size_t len = std::strlen(libName) + 1;
		name = new char[len];
		std::strcpy(name, libName);
	}
}

Library::Library(const Library& other)
	: name(nullptr)
	, books(nullptr)
	, size(0)
	, capacity(0)
{
	copy_from(other);
}

Library& Library::operator=(const Library& other)
{
	if (this == &other) {
		return *this;
	}
	free_storage();
	name = nullptr;
	books = nullptr;
	size = 0;
	capacity = 0;
	copy_from(other);
	return *this;
}

Library::~Library()
{
	free_storage();
}

void Library::free_storage()
{
	delete[] name;
	delete[] books;
	name = nullptr;
	books = nullptr;
	size = 0;
	capacity = 0;
}

void Library::copy_from(const Library& other)
{
	if (other.name) {
		const std::size_t len = std::strlen(other.name) + 1;
		name = new char[len];
		std::strcpy(name, other.name);
	} else {
		name = new char[1];
		name[0] = '\0';
	}

	size = other.size;
	capacity = other.capacity;
	books = nullptr;
	if (capacity > 0) {
		books = new Book[capacity];
		for (std::size_t i = 0; i < size; ++i) {
			books[i] = other.books[i];
		}
	}
}

void Library::grow()
{
	std::size_t newCap = (capacity == 0) ? 4 : capacity * 2;
	Book* next = new Book[newCap];
	for (std::size_t i = 0; i < size; ++i) {
		next[i] = books[i];
	}
	delete[] books;
	books = next;
	capacity = newCap;
}

void Library::add(const Book& book)
{
	if (size == capacity) {
		grow();
	}
	books[size++] = book;
}

std::size_t Library::get_list_size() const
{
	return size;
}

const char* Library::get_name() const
{
	return name ? name : "";
}

void Library::serialize(std::ostream& os) const
{
	const std::size_t nameLen = name ? std::strlen(name) : 0;
	os << nameLen << '\n';
	if (nameLen > 0) {
		os << name;
	}
	os << '\n' << size << '\n';
	for (std::size_t i = 0; i < size; ++i) {
		books[i].serialize(os);
	}
}

void Library::deserialize(std::istream& is)
{
	std::size_t nameLen = 0;
	is >> nameLen;
	is.ignore();

	delete[] name;
	name = new char[nameLen + 1];
	if (nameLen > 0) {
		is.getline(name, nameLen + 1);
	}

	std::size_t n = 0;
	is >> n;
	is.ignore();

	delete[] books;
	books = nullptr;
	size = 0;
	capacity = 0;

	if (n > 0) {
		capacity = n;
		books = new Book[capacity];
		for (std::size_t i = 0; i < n; ++i) {
			books[i].deserialize(is);
			++size;
		}
	}
}
