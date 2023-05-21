#pragma once
#include <iostream>
#include "Ninja.hpp"
// #include "Cowboy.hpp"
#include "Character.hpp"



namespace ariel{}


class YoungNinja : public Ninja
{
    public:

        // constructor
        YoungNinja(std::string name, const Point &location);
};