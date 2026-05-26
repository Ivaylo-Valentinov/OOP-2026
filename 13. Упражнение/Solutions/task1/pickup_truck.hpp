#ifndef FMI_OOP_PICKUP_TRUCK_HPP
#define FMI_OOP_PICKUP_TRUCK_HPP
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include "car.hpp"
#include "truck.hpp"

constexpr double CAR_KM_PER_PSG = 50;
constexpr double CAR_KM_PER_KG = 2;
class PickupTruck: public Car, public Truck {
private:
	std::vector<char*> schedule;

public:
	PickupTruck(size_t id, const char* const model, const double range,
			const unsigned seats, const double capacity):
		Vehicle(id, model, range),
		Car(id, model, range, seats),
		Truck(id, model, range, capacity) {}

	// TODO: Copy ctor + operator= + move semantics.

	~PickupTruck() {
		for (char* entry: schedule) {
			delete entry;
		}
	}

	void setSchedule(const std::vector<const char*>& tasks) {
		if (!schedule.empty()) {
			throw std::runtime_error("Not empty!");
		}

		for (const char* task: tasks) {
			const size_t len = strlen(task);
			char *entry = new char[len + 1];
			strncpy(entry, task, len);
			schedule.push_back(entry);
		}
	}

	char *getNextTask() {
		if (schedule.empty()) {
			throw std::runtime_error("Nothing to do!");
		}

		char* front = schedule.front();
		schedule.erase(schedule.begin());
		return front;
	}

	double getRange() const override {
		return maxRange - CAR_KM_PER_PSG * numPassengers - CAR_KM_PER_KG * currentLoad;
	}

	void print(std::ostream& out) const override {
		out << "PICKUP model: " << model
			<< ", range: " << getRange() << "/" << maxRange
			<< ", load: " << currentLoad << "/" << loadCapacity
			<< std::endl << "Passengers:";

		for (size_t i = 0; i < seats; i++) {
			if (passengers[i]) {
				out << std::endl << passengers[i];
			}
		}

		out << std::endl << "Schedule:";
		for(const char* entry: schedule) {
			out << std::endl << entry;
		}
	}
};

#endif /* FMI_OOP_PICKUP_TRUCK_HPP */