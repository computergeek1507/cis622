#include<iostream>
#include<vector>
#include<string>

struct boatstate {
    int brewers;
    int drinkers;
    bool onLeft{true};

    boatstate(int brewers_, int drinker_, bool onleft_):brewers(brewers_), drinkers(drinker_), onLeft(onleft_)
    {}
    
    bool isEndState() const
    {
        return brewers == 0 && drinkers == 0 && !onLeft;
    }

    bool isGoodState(boatstate currentBoat, int boatsize, int totalbrewers, int totaldrinkers) const
    {
        if (drinkers > brewers)
            return false;
        if (drinkers < 0)
            return false;
        if (brewers < 0)
            return false;
        if (drinkers > totaldrinkers)
            return false;
        if (brewers > totalbrewers)
            return false;

        if (!onLeft) {
            if ((currentBoat.brewers - brewers) + (currentBoat.drinkers - drinkers) > boatsize)
            {
                return false;
            }
            if ((currentBoat.brewers - brewers) + (currentBoat.drinkers - drinkers) <= 0)
            {
                return false;
            }
        }
        else
        {
            //2,2
            int rightbrewers = totalbrewers - currentBoat.brewers;
            int rightdrinkers = totaldrinkers - currentBoat.brewers;

            if (rightbrewers + brewers > totalbrewers) {
                return false;
            }
            if (rightdrinkers + drinkers > totaldrinkers) {
                return false;
            }
            if ((totalbrewers - brewers) + (totaldrinkers - drinkers) > boatsize)
            {
                return false;
            }
        }

        return true;
    }

    std::string toString() const 
    {
        return "B=" + std::to_string( brewers) + ",D=" + std::to_string(drinkers) + "," + std::string(onLeft ? "left" : "right") + "\n";
    }

    bool operator==(const boatstate& c1) {
        return brewers == c1.brewers && drinkers == c1.drinkers && onLeft == c1.onLeft;
    }
};

std::vector<boatstate> generateValidMoves(boatstate currentBoat, int boatsize, int totalbrewers, int totaldrinkers, std::vector<boatstate> oldMoves)
{
    std::vector <boatstate> validStates;
    for (int brewers = 0; brewers <= totalbrewers; ++brewers)
    {
        for (int drinkers = 0; drinkers <= totaldrinkers; ++drinkers)
        {
            boatstate newboat(brewers, drinkers, !currentBoat.onLeft);
            if (newboat.isGoodState(currentBoat, boatsize, totalbrewers, totaldrinkers) && std::find(oldMoves.begin(), oldMoves.end(), newboat) == oldMoves.end())
            {
                validStates.push_back(newboat);
                //std::cout << boat.toString();
            }
        }
    }
    return validStates;
}

bool solveBoat(boatstate curBoat, int boatsize, int totalbrewers, int totaldrinkers, std::vector<boatstate> oldMoves)
{
    auto states = generateValidMoves(curBoat, boatsize, totalbrewers, totaldrinkers, oldMoves);
    if (states.empty()) { return false; }

    for (auto const& state : states)
    {
        oldMoves.push_back(state);
        if(state.isEndState())
        {
            for (auto const& old : oldMoves)
            {
                std::cout << old.toString();
            }
            return true;
        }
        
        if (solveBoat(state, boatsize, totalbrewers, totaldrinkers, oldMoves))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int brewers{ 3 };
    int drinkers{ 3 };
    int capacity{ 2 };
    //std::cout << "Number of Brewers :\n ";
    //std::cin >> brewers;
    //std::cout << "Number of Beer Drinkers :\n ";
    //std::cin >> drinkers;
    //std::cout << "Boat Capacity :\n ";
    //std::cin >> capacity;

    std::vector<boatstate> prevousMoves;

    boatstate startBoat(brewers, drinkers, true);
    prevousMoves.push_back(startBoat);

    if (solveBoat(startBoat, capacity, brewers, drinkers, prevousMoves))
    {
        std::cout << "Worked\n";
    }

    getchar();
}