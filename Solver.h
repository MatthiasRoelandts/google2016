#pragma once



class Solver {
        public:
                Solver();
                virtual ~Solver();

                virtual void solve() = 0;
};
