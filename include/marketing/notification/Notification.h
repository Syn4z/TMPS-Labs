#pragma once

#include <string>
#include <utility>

class Notification {
public:
    explicit Notification(std::string  content) : content_(std::move(content)) {}
    std::string getContent() const {
        return content_;
    }

private:
    std::string content_;
};
