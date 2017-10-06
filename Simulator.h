#pragma once

#include "OutputParser.h"

class World;

class Simulator {
        public:
                Simulator(World & world, OutputParser output);

                void start();

        private:
                World & m_world;
                OutputParser m_output;
};
