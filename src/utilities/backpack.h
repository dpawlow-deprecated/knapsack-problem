#ifndef KNAPSACK_PROBLEM_BACKPACK_H
#define KNAPSACK_PROBLEM_BACKPACK_H

#include <vector>
#include "item.h"

using namespace std;

class Backpack {
public:
    vector<Item> items;

    Backpack();
    explicit Backpack(unsigned long size);

    void addItem(Item const &item);

    void setSize(unsigned long size);
    void setValue(unsigned long value);
    void setLoad(unsigned long load);

    unsigned long getSize() const;
    unsigned long getValue() const;
    unsigned long getLoad() const;

    bool operator<(const Backpack& bkp) const;

private:
    unsigned long size;
    unsigned long load;
    unsigned long value;
};


#endif //KNAPSACK_PROBLEM_BACKPACK_H
