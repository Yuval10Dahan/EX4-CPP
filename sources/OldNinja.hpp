#pragma once
#include <iostream>
#include "Ninja.hpp"
#include "Cowboy.hpp"



namespace ariel{}
 

class OldNinja : public Ninja
{
    public:

        // constructor
        OldNinja(const std::string &name, const Point &location);

        OldNinja(const OldNinja& other) = delete;  // Deleted copy constructor
        OldNinja& operator=(const OldNinja& other) = delete;  // Deleted copy assignment operator
        OldNinja(OldNinja&& other) = delete;  // Deleted move constructor
        OldNinja& operator=(OldNinja&& other) = delete;  // Deleted move assignment operator

        // distructor
        ~OldNinja() override;
};