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
        if (drinkers < 0)
            return false;
        if (brewers < 0)
            return false;
        if (drinkers > totaldrinkers)
            return false;
        if (brewers > totalbrewers)
            return false;

        //curent brewers/drinkers to next brewers/drinkers must be within boat size
        if (abs(currentBoat.brewers - brewers) + abs(currentBoat.drinkers - drinkers) > boatsize)
        {
            return false;
        }
        if (abs(currentBoat.brewers - brewers) + abs(currentBoat.drinkers - drinkers) <= 0)
        {
            return false;
        }

        if (!onLeft) {
            if (currentBoat.brewers < brewers || currentBoat.drinkers < drinkers)
            {
                return false;
            }
        }
        else
        {
            if (currentBoat.brewers > brewers || currentBoat.drinkers > drinkers)
            {
                return false;
            }
        }

        //leftside ratio
        if (drinkers > brewers && drinkers != 0 && brewers != 0)
            return false;

        //rightside ratio
        if ((totaldrinkers - drinkers) > (totalbrewers - brewers) && (totaldrinkers - drinkers) != 0 && (totalbrewers - brewers) != 0 )
            return false;

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
            }
        }
    }
    return validStates;
}

//pass oldMoves by copy for recursion
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