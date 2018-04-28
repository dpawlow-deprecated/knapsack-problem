#ifndef KNAPSACK_PROBLEM_ITEM_H
#define KNAPSACK_PROBLEM_ITEM_H


class Item {
public:
    Item();
    Item(unsigned long value, unsigned long size);

    bool isLighter(Item const &item) const;

    unsigned long getValue() const;
    unsigned long getSize() const;

private:
    unsigned long value;
    unsigned long size;
};


#endif //KNAPSACK_PROBLEM_ITEM_H
