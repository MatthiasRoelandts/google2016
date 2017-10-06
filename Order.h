#pragma once

#include <map>
#include <vector>

#include "Product.h"
#include "Point.h"

enum OrderState { OPEN, OFFERED, CLAIMED };

class Drone;

class Order {
        public:
                Order(int id, Point location, std::vector<Product> items);

                int getId() const;
                Point getLocation() const;
                std::vector<Product> getItems() const;

                bool operator<(const Order&) const;

                // Order Processing
                void makeOffer(Drone * drone, int cost);
                void accept();
                void reject();
                
                static bool hasOpen(std::vector<Order> & orders);
                bool isClaimed() const;

        private:
                int m_id;
                Point m_location;
                std::vector<Product> m_items;

                // State
                OrderState m_state;
                std::map<Drone*, int> m_offers;
                // TODO maybe retrun to Drone&
                Drone * m_accepted_drone;
};
