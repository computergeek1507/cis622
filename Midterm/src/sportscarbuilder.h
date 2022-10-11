#pragma once

#include "car.h"
#include "carbuilder.h"
#include <string>
#include <memory>

struct SportsCarBuilder : CarBuilder
{
    std::unique_ptr <Car> car;

    SportsCarBuilder()
    {
        car = std::make_unique<Car>();
    }

    void buildModel() override
    {
        car->Model = "Mustang";
    }

    void buildEngine() override
    {
        car->Engine = "V6 2L";
    }

    void buildColor() override
    {
        car->Color = "Black";
    }

    void buildAddon() override
    {
        car->Addon = "Moon Roof";
    }

    std::unique_ptr<Car> getCar() override
    {
        return std::move(car);
    }
};