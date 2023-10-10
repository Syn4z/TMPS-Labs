#pragma once

#include <vector>
#include <string>

class Product {
public:
    std::vector<std::string> parts_;
    void ShowParts() const;
};
