#pragma once

#include <string>

//Memento Class

struct Memento
{
    Memento() = default;
    Memento(std::string model, std::string color):
        Model(model), Color(color)
    { }

    void SetState(std::string model, std::string color)
    {
        Model = model;
        Color = color;
    }

    std::string GetState()
    {
        return Color + " " + Model;
    }

    std::string AsString()
    {
        return Color + " " + Model;
    }

    std::string Model;
    std::string Color;
};
