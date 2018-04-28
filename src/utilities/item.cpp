#include "item.h"

Item::Item() {
    Item::size = 0;
    Item::value = 0;
}

Item::Item(unsigned long v, unsigned long s) {
    size = s;
    value = v;
}

bool Item::isLighter(Item const &item) const {
    return size < item.getSize();
}


unsigned long Item::getSize() const {
    return size;
}

unsigned long Item::getValue() const {
    return value;
}