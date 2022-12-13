#include "car.h"
#include "suvcarbuilder.h"
#include "sportscarbuilder.h"
#include "cardirector.h"

#include<iostream>
#include<vector>
#include<memory>
#include<string>

int main()
{
    CarDirector director;

    auto suvBuilder = std::make_unique<SUVCarBuilder>();

    director.SetBuilder(suvBuilder.get());
    director.BuildCar();
    auto car = director.getCar();

    std::cout << "Car Built: " << car->AsString() << "\n";

    auto sportsBuilder = std::make_unique<SportsCarBuilder>();

    director.SetBuilder(sportsBuilder.get());
    director.BuildCar();
    auto car2 = director.getCar();

    std::cout << "Car Built: " << car2->AsString() << "\n";


    getchar();
    getchar();
}