#pragma once
#include <iostream>
#include "Ninja.hpp"
#include "Cowboy.hpp"



namespace ariel{}


class TrainedNinja : public Ninja
{
    public:

        // constructor
        TrainedNinja(const std::string &name, const Point &location);

        TrainedNinja(const TrainedNinja& other) = delete;  // Deleted copy constructor
        TrainedNinja& operator=(const TrainedNinja& other) = delete;  // Deleted copy assignment operator
        TrainedNinja(TrainedNinja&& other) = delete;  // Deleted move constructor
        TrainedNinja& operator=(TrainedNinja&& other) = delete;  // Deleted move assignment operator

        // distructor
        ~TrainedNinja() override;
};