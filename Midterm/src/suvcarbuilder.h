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
		car->SetModel("SUV");
	}

	void buildEngine() override
	{
		car->SetEngine("V8 4L");
	}

	void buildColor() override
	{
		car->SetColor("Blue");
	}

	void buildAddon() override
	{
		car->SetAddon("Winter Package");
	}

	std::unique_ptr<Car> getCar() override
	{
		return std::move(car);
	}
};