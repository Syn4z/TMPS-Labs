#pragma once

#include <vector>
#include <memory>
#include "CarInterface.h"

class CarIterator {
public:
    using pointer = std::shared_ptr<CarInterface>;
    using reference = std::shared_ptr<CarInterface>;
    explicit CarIterator(std::vector<std::shared_ptr<CarInterface>>::iterator it);
    reference operator*();
    pointer operator->();
    CarIterator& operator++();
    const CarIterator operator++(int);
    bool operator==(const CarIterator& other) const;
    bool operator!=(const CarIterator& other) const;

private:
    std::vector<std::shared_ptr<CarInterface>>::iterator current_it;
};
