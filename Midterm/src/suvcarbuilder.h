#pragma once

#include "car.h"
#include "carbuilder.h"
#include <string>
#include <memory>

struct SUVCarBuilder : CarBuilder
{
    std::unique_ptr <Car> car;

    SUVCarBuilder()
    {
        car = std::make_unique<Car>();
    }

    void buildModel() override
    {
        car->Model = "SUV";
    }

    void buildEngine() override
    {
        car->Engine = "V8 4L";
    }

    void buildColor() override
    {
        car->Color = "Blue";
    }

    void buildAddon() override
    {
        car->Addon = "Winter Package";
    }

    std::unique_ptr<Car> getCar() override
    {
        return std::move(car);
    }
};