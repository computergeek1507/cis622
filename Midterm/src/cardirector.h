#pragma once

#include "car.h"
#include "carbuilder.h"
#include <string>
#include <memory>

struct CarDirector
{
    CarBuilder* carBuilder;

    void SetBuilder(CarBuilder* carBuilder_)
    {
        carBuilder = carBuilder_;
    }

    std::unique_ptr <Car> getCar()
    {
        return std::move(carBuilder->getCar());
    }

    void BuildCar()
    {
        carBuilder->buildModel();
        carBuilder->buildColor();
        carBuilder->buildEngine();
        carBuilder->buildAddon();
    }
};

