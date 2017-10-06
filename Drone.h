#pragma once

//#include <size_t>

#include "Point.h"

class Drone {
        public:
                Drone(int id, Point starting_location, std::size_t capacity);

                int getId() const;
                Point getLocation() const;
                std::size_t getCapacity() const;

        private:
                int m_id;
                Point m_location;
                std::size_t m_capacity;
};
