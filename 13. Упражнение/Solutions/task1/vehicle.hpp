#ifndef FMI_OOP_VEHICLE_HPP
#define FMI_OOP_VEHICLE_HPP
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cassert>


class Vehicle {
protected:
	size_t id;
	char model[33]; // +1 '\0'
	double maxRange;

public:
	Vehicle(size_t id, const char* const model, const double maxRange):
		id(id), maxRange(maxRange) {
		if (strlen(model) > 32) {
			throw std::invalid_argument("Model name too long!");
		}
		strncpy(this->model, model, 32);
	}

	virtual ~Vehicle() = default;

	virtual double getRange() const {
		return maxRange;
	}

	virtual void print(std::ostream& out) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Vehicle& v) {
	v.print(out);
	return out;
}

#endif /* FMI_OOP_VEHICLE_HPP */
