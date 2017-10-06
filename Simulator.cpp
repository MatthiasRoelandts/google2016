

#include "Simulator.h"
#include "World.h"

Simulator::Simulator(World & world, OutputParser output) : m_world(world), m_output(output) {}

void Simulator::start() {
        const std::size_t max_turns = m_world.getMaxTurns();
        
        for(int turn = 0; turn < max_turns; turn++) {
                // TODO somewhere the output parser should reach the output,
                // don't know where exactly though
                m_world.tick();
        }
}
