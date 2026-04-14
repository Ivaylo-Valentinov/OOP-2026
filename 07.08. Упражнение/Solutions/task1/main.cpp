#include "SharedNote.h"
#include <iostream>

int main()
{
	SharedNote a("Hello");
	SharedNote b = a;

	std::cout << "Shallow copy:\n";
	std::cout << "a: " << a.getContent() << '\n';
	std::cout << "b: " << b.getContent() << '\n';

	std::cout << "\nappend:\n";
	b.append(", world");
	std::cout << "a: " << a.getContent() << '\n';
	std::cout << "b: " << b.getContent() << '\n';

	std::cout << "\nsetContent:\n";
	a.setContent("Shared note");
	std::cout << "a: " << a.getContent() << '\n';
	std::cout << "b: " << b.getContent() << '\n';

	SharedNote c(std::move(a));
	std::cout << "\nc after a is moved: " << c.getContent() << '\n';

	b = std::move(c);
	std::cout << "b after move assign: " << b.getContent() << '\n';

	return 0;
}
