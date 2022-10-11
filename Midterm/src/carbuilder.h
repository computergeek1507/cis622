#pragma once

#include "car.h"
#include <string>
#include <memory>

struct CarBuilder
{
    CarBuilder() = default;
    virtual ~CarBuilder() = default;
    virtual void buildModel() = 0;
    virtual void buildEngine() = 0;
    virtual void buildColor() = 0;
    virtual void buildAddon() = 0;

    virtual std::unique_ptr<Car> getCar() = 0;
};
