#include "car.h"
#include "Caretaker.h"


#include<iostream>
#include<vector>
#include<memory>
#include<string>

int main()
{
    Caretaker caretaker;


    Car car("Truck", "Grey");

    caretaker.CreateSnapShot(car.SaveMemento());

    car.SetColor("Red");

    caretaker.CreateSnapShot(car.SaveMemento());

    car.SetModel("SUV");

    caretaker.CreateSnapShot(car.SaveMemento());

    std::cout << "Stared as Built: " << caretaker.GetFirstSnapShot().AsString() << "\n";
    std::cout << "Ended as Built: " << caretaker.GetLastSnapShot().AsString() << "\n";

    car.RestoreMemento(caretaker.GetFirstSnapShot());

    std::cout << "Restored as Built: " << car.AsString() << "\n";

    getchar();
    getchar();
}