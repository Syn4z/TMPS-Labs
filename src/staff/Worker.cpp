#include <utility>

#include "../../include/staff/Worker.h"

Worker::Worker(std::string  name) : name(std::move(name)) { }

void Worker::work() const {
    std::cout << "Worker " << name << " is working on the car." << std::endl;
}
