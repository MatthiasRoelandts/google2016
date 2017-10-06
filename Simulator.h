#pragma once


class Simulator {
        public:
                Simulator(World & world, OutputParser output);

                void start();

        private:
                World & m_world;
                OutputParser output;
};
