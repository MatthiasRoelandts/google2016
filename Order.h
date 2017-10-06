#pragma once


class Order {
        public:
                Order(int id, Point location, std::vector<Product> items);

                int getId() const;
                Point getLocation() const;
                std::vector<Product> getItems() const;

        private:
                int m_id;
                Point m_location;
                std::vector<Product> m_items;
};
