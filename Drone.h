#pragma once

#include <size_t>

#include "Point.h"

class Drone {
        public:
                Drone(int id, Point starting_location, size_t capacity);

                int getId() const;
                Point getLocation() const;
                size_t getCapacity() const;

        private:
                int m_id;
                Point m_location;
                size_t m_capacity;
};
