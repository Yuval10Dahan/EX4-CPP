#pragma once
#include <iostream>
#include "Ninja.hpp"
#include "Character.hpp"



namespace ariel{}
 

class OldNinja : public Ninja
{
    public:

        // constructor
        OldNinja(std::string name, const Point &location);
};