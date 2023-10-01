#include "../../include/assembly-line/Product.h"
#include <iostream>

void Product::ShowParts() const {
    for (const std::string& part : parts_) {
        std::cout << "\n" << part;
    }
    std::cout << std::endl;
}
