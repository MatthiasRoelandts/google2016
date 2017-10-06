
#include "Drone.h"

Drone::Drone(int id, Point starting_location, size_t capacity) : m_id(id), m_location(starting_location), m_capacity(capacity) {}

int Drone::getId const { return m_id; }

Point Drone::getLocation const { return m_location; }

size_t getCapacity() const { return m_capacity; }
