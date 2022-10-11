#pragma once

#include <string>
#include <vector>


struct Car
{
    Car() = default;

    void SetModel(std::string model) 
    {
        m_model = model;
    }
    void SetEngine(std::string engine)
    {
        m_engine = engine;
    }
    void SetColor(std::string color) 
    { 
        m_color = color; 
    }
    void SetAddon(std::string addon)
    { 
        m_addon = addon; 
    }

    std::string AsString()
    {
        return m_color + " " + m_model + " with " + m_engine + " and " + m_addon;
    }
private:
    std::string m_model;
    std::string m_engine;
    std::string m_color;
    std::string m_addon;
};
/*
struct Car
{
    Car() = default;

    void SetModel(std::string model)
    {
        m_props.push_back( model );
    }
    void SetEngine(std::string engine)
    {
        m_props.push_back( engine );
    }
    void SetColor(std::string color)
    {
        m_props.push_back( color );
    }
    void SetAddon(std::string addon)
    {
        m_props.push_back( addon );
    }

    std::string AsString()
    {
        std::string returnVal;
        for (auto const& p : m_props)
        {
            returnVal += p;
            returnVal += " ";
        }
        return returnVal;
    }
private:
    std::vector<std::string> m_props;
};*/