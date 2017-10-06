
#include <climits>

#include "Order.h"
#include "Drone.h"

// Constructors



// Getters



// Order Processing
void Order::makeOffer(Drone & drone, int cost) {
        // A CLAIMED order cannot be made an offer
        if(m_state == CLAIMED) {
                // TODO throw fitting exception
                return;
        }
        m_state = OFFERED;
        m_offers.insert({drone, cost});
}

void Order::accept() {
        // When already claimed, this does nothing
        if(m_state == CLAIMED) {
                return;
        }

        // Find best offer
        int min_cost = INT_MAX;
        int optimal_drone_id = -1;

        for(auto e : m_offers) {
                if(e.second < min_cost) {
                        optimal_drone_id = e.first.getId();
                }
        }
        // Get correct reference
        for(auto e : m_offers) {
                if(e.first.getId() == optimal_drone_id) {
                        // Accept Offer
                        e.first.accept(*this);
                        break;
                }
        }
}

static bool Order::hasOpen(std::vector<Order> &orders) {
        for(auto it : orders) {
                if(it.m_state == OPEN) {
                        return true;
                }
        }
        return false;
}


