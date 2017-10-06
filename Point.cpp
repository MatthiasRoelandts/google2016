#include "Point.h"

std::string Point::toString() {
        return "Point: " + std::to_string(m_x) + "x" + std::to_string(m_y);
}

