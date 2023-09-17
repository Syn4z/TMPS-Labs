#pragma once

#include <string>


class Advertisement {
public:
    virtual ~Advertisement() = default;
    virtual std::string getTitle() const = 0;
    virtual std::string getContent() const = 0;
    virtual int getFeedback() const = 0;
};
