#ifndef FMI_OOP_TRUCK_HPP
#define FMI_OOP_TRUCK_HPP
#include <iostream>
#include <stdexcept>
#include "vehicle.hpp"

constexpr double TR_KM_PER_KG = 1;

class Truck: public virtual Vehicle {
protected:
	double currentLoad;
	double loadCapacity;

public:
	Truck(size_t id, const char* const model, const double range, const double capacity):
		Vehicle(id, model, range),
		currentLoad(0), loadCapacity(capacity) {}


	double getRange() const override {
		return maxRange - TR_KM_PER_KG * currentLoad;
	}

	void load(const double load) {
		if (currentLoad + load > loadCapacity) {
			throw std::out_of_range("Will overload capacity!");
		}

		currentLoad += load;
	}

	void unload(const double load) {
		if (currentLoad < load) {
			throw std::out_of_range("Trying to unload too much!");
		}

		currentLoad -= load;
	}

	void print(std::ostream& out) const override {
		out << "TRUCK model: " << model
			<< ", range: " << getRange() << "/" << maxRange
			<< ", load: " << currentLoad << "/" << loadCapacity;
	}
};

#endif /* FMI_OOP_TRUCK_HPP */