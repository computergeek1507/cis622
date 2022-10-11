#pragma once

#include <string>

struct Car
{
    Car() = default;
    std::string Model;
    std::string Engine;
    std::string Color;
    std::string Addon;
    std::string AsString()
    {
        return Color + " " + Model + " with " + Engine + " and " + Addon;
    }
};