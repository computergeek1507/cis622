#pragma once

#include "Memento.h"
#include <string>

//Originator Class

struct Car
{
    Car() = default;
    Car(std::string model, std::string color) 
    {
        SetModel(model);
        SetColor(color);
    }

    //Save the Internal State
    Memento SaveMemento()
    {
        return Memento(m_model, m_color);
    }
    // Restore the memento
    void RestoreMemento(Memento memento)
    {
        m_model = memento.Model;
        m_color = memento.Color;
    }

    void SetModel(std::string model) 
    {
        m_model = model;
    }

    void SetColor(std::string color) 
    { 
        m_color = color; 
    }
    std::string GetModel() const
    {
        return m_model;
    }
    std::string GetColor() const
    {
        return m_color;
    }

    std::string AsString()
    {
        return GetColor() + " " + GetModel();
    }
private:
    std::string m_model;
    std::string m_color;
};
