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
		car->SetModel("Mustang");
	}

	void buildEngine() override
	{
		car->SetEngine("V6 2L");
	}

	void buildColor() override
	{
		car->SetColor("Black");
	}

	void buildAddon() override
	{
		car->SetAddon("Moon Roof");
	}

	std::unique_ptr<Car> getCar() override
	{
		return std::move(car);
	}
};