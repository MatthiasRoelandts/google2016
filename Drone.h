#pragma once

//#include <size_t>
#include <vector>

#include "Point.h"

enum DroneState { FREE, BUSY, ACCEPTED };

class Drone {
        public:
                Drone(int id, Point starting_location, std::size_t capacity);

                int getId() const;
                Point getLocation() const;
                std::size_t getCapacity() const;

                // Simulation
                void tick();

                // Order Processing
                void announce(std::vector<Order> &orders);
                void makeReservations(std::vector<Warehouse> &warehouses);
                void accept(Order & order);

                static bool hasUnaccepted(std::vector<Drone> &drones);
                static bool hasFree(std::vector<Drone> &drones);

        private:
                int m_id;
                Point m_location;
                std::size_t m_capacity;

                // State
                DroneState m_state;
};
