#pragma once


class Point {
        public:
                Point(int x, int y);

                int distance(Point other) const;

                static int distance(Point first, Point other);

        private:
                int m_x, m_y;
};
