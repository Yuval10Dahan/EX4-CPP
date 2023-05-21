#pragma once
#include <iostream>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Character.hpp"



namespace ariel{}


class YoungNinja : public Ninja
{
    public:

        // constructor
        YoungNinja(const std::string &name, const Point &location);

        YoungNinja(const YoungNinja& other) = delete;  // Deleted copy constructor
        YoungNinja& operator=(const YoungNinja& other) = delete;  // Deleted copy assignment operator
        YoungNinja(YoungNinja&& other) = delete;  // Deleted move constructor
        YoungNinja& operator=(YoungNinja&& other) = delete;  // Deleted move assignment operator

        // distructor
        ~YoungNinja() override;
};