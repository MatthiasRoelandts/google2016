#pragma once

enum OrderState { OPEN, OFFERED, CLAIMED };

class Order {
        public:
                Order(int id, Point location, std::vector<Product> items);

                int getId() const;
                Point getLocation() const;
                std::vector<Product> getItems() const;

                // Order Processing
                void makeOffer(Drone & drone, int cost);
                void accept();
                
                static bool hasOpen(std::vector<Order> & orders);

        private:
                int m_id;
                Point m_location;
                std::vector<Product> m_items;

                // State
                OrderState m_state;
};
