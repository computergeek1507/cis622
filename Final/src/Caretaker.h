#pragma once

#include "Memento.h"

#include <string>
#include <vector>

//Caretaker Class

struct Caretaker
{
    Caretaker() = default;

    void CreateSnapShot(Memento m)
    {
        m_history.push_back(m);
    }

    Memento GetLastSnapShot()
    {
        return m_history.back();
    }

    Memento GetFirstSnapShot()
    {
        return m_history.front();
    }

    std::vector<Memento> m_history;;
};
