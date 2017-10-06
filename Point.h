#pragma once

#include <string>

class Point {
        public:
                Point(int x, int y) : m_x(x), m_y(y) {}

                int distance(Point other) const;

                static int distance(Point first, Point other);
                
                std::string toString();

        private:
                int m_x, m_y;
};
