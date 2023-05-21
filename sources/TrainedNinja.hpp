#pragma once
#include <iostream>
#include "Ninja.hpp"
#include "Character.hpp"



namespace ariel{}


class TrainedNinja : public Ninja
{
    public:

        // constructor
        TrainedNinja(std::string name, const Point &location);
};