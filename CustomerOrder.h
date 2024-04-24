#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"

namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };

    class CustomerOrder
    {
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item **m_lstItem;

        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string &record);

        CustomerOrder(const CustomerOrder &rOp) { throw "Copying is not allowed"; };
        CustomerOrder &operator=(const CustomerOrder &rOp) = delete;

        CustomerOrder(CustomerOrder &&src) noexcept;
        CustomerOrder &operator=(CustomerOrder &&src) noexcept;

        virtual ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };
} // namespace sdds

#endif