#include "../include/vehicle/CarIterator.h"

CarIterator::CarIterator(std::vector<std::shared_ptr<CarInterface>>::iterator it) : current_it(it) {}

CarIterator::reference CarIterator::operator*() {
    return *current_it;
}

CarIterator::pointer CarIterator::operator->() {
    return *current_it;
}

CarIterator& CarIterator::operator++() {
    ++current_it;
    return *this;
}

const CarIterator CarIterator::operator++(int) {
    CarIterator tmp = *this;
    ++current_it;
    return tmp;
}

bool CarIterator::operator==(const CarIterator& other) const {
    return current_it == other.current_it;
}

bool CarIterator::operator!=(const CarIterator& other) const {
    return current_it != other.current_it;
}
