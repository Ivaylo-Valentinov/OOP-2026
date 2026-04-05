#include "Book.h"
#include <cstring>

Book::Book()
{
	title[0] = '\0';
	author[0] = '\0';
	id = 0;
}

Book::Book(const char* titleStr, const char* authorStr, unsigned bookId)
{
	std::strcpy(title, titleStr);
	std::strcpy(author, authorStr);
	id = bookId;
}

void Book::serialize(std::ostream& os) const
{
	os << title << '\n' << author << '\n' << id << '\n';
}

void Book::deserialize(std::istream& is)
{
	is.getline(title, sizeof(title));
	is.getline(author, sizeof(author));
	is >> id;
	is.ignore();
}

void Book::serialize_binary(std::ostream& os) const
{
	os.write((const char*)(this), sizeof(*this));
}

void Book::deserialize_binary(std::istream& is)
{
	is.read((char*)(this), sizeof(*this));
}

void Book::serialize_at(std::ostream& os, std::size_t pos) const
{
	const size_t cur = os.tellp();
	os.seekp(pos);
	serialize_binary(os);
	os.seekp(cur);
}

void Book::deserialize_at(std::istream& is, std::size_t pos)
{
	const size_t cur = is.tellg();
	is.seekg(pos);
	deserialize_binary(is);
	is.seekg(cur);
}
