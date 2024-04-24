#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation *m_pNextStation{};

    public:
        Workstation(const std::string &record);
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);

        // Copy Semantics
        Workstation(const Workstation &rOp) = delete;
        Workstation &operator=(const Workstation &rOp) = delete;

        // Move Semantics
        Workstation(Workstation &&rOp) = delete;
        Workstation &operator=(Workstation &&rOp) = delete;
    };

} // namespace sdds

#endif