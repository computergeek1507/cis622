#include<iostream>
#include<vector>
#include<string>

/***********************************
*
*           State
*
************************************/
struct boatstate
{
    int brewers;
    int drinkers;
    bool onLeft{ true };

    boatstate(int brewers_, int drinker_, bool onleft_) :
        brewers(brewers_), drinkers(drinker_), onLeft(onleft_)
    { }    

    std::string toString() const
    {
        return "B=" + std::to_string(brewers) + ",D=" + std::to_string(drinkers) + "," + std::string(onLeft ? "left" : "right") + "\n";
    }

    std::string printMove(boatstate const& prevous) const
    {
        return "B=" + std::to_string(abs(prevous.brewers - brewers)) + ",D=" + std::to_string(abs(prevous.drinkers - drinkers)) + "\n";
    }

    bool operator==(const boatstate& c1) {
        return brewers == c1.brewers && drinkers == c1.drinkers && onLeft == c1.onLeft;
    }
};

/***********************************
* 
*           Observers
*
************************************/

bool isEndState(boatstate currentBoat)
{
    return currentBoat.brewers == 0 && currentBoat.drinkers == 0 && !currentBoat.onLeft;
}

bool isValidState(boatstate currentBoat, boatstate nextBoat, int boatsize, int totalbrewers, int totaldrinkers)
{
    if (nextBoat.drinkers > totaldrinkers)
        return false;
    if (nextBoat.brewers > totalbrewers)
        return false;

    //curent brewers/drinkers to next brewers/drinkers must be within boat size
    if (abs(currentBoat.brewers - nextBoat.brewers) + abs(currentBoat.drinkers - nextBoat.drinkers) > boatsize)
    {
        return false;
    }
    if (abs(currentBoat.brewers - nextBoat.brewers) + abs(currentBoat.drinkers - nextBoat.drinkers) <= 0)
    {
        return false;
    }

    if (!nextBoat.onLeft) {
        if (currentBoat.brewers < nextBoat.brewers || currentBoat.drinkers < nextBoat.drinkers)
        {
            return false;
        }
    }
    else
    {
        if (currentBoat.brewers > nextBoat.brewers || currentBoat.drinkers > nextBoat.drinkers)
        {
            return false;
        }
    }

    //leftside ratio
    if (nextBoat.drinkers > nextBoat.brewers && nextBoat.drinkers != 0 && nextBoat.brewers != 0)
        return false;

    //rightside ratio
    if ((totaldrinkers - nextBoat.drinkers) > (totalbrewers - nextBoat.brewers) && (totaldrinkers - nextBoat.drinkers) != 0 && (totalbrewers - nextBoat.brewers) != 0)
        return false;

    return true;    
}

/***********************************
*
*           Process Event
*
************************************/

std::vector<boatstate> generateValidMoves(boatstate currentBoat, int boatsize, int totalbrewers, int totaldrinkers, std::vector<boatstate> oldMoves)
{
    std::vector <boatstate> validStates;
    for (int brewers = 0; brewers <= totalbrewers; ++brewers)
    {
        for (int drinkers = 0; drinkers <= totaldrinkers; ++drinkers)
        {
            boatstate newboat(brewers, drinkers, !currentBoat.onLeft);
            if (isValidState(currentBoat, newboat, boatsize, totalbrewers, totaldrinkers) && std::find(oldMoves.begin(), oldMoves.end(), newboat) == oldMoves.end())
            {
                validStates.push_back(newboat);
            }
        }
    }
    return validStates;
}

//depth first search
//pass oldMoves by copy for recursion
//values
bool solveBoat(boatstate curBoat, int boatsize, int totalbrewers, int totaldrinkers, std::vector<boatstate> oldMoves, int depth, int maxDepth)
{
    if (depth >= maxDepth) 
    {
        return false; 
    }
    auto states = generateValidMoves(curBoat, boatsize, totalbrewers, totaldrinkers, oldMoves);
    if (states.empty()) { return false; }

    //for (auto const& state : states)
    //{
        auto const& state = states[0];
        oldMoves.push_back(state);
        if(isEndState(state))
        {
            for (int i = 1; i < oldMoves.size(); ++i)
            {
                 std::cout << oldMoves[i].printMove(oldMoves[i - 1]);
            }
            return true;
        }
        
        if (solveBoat(state, boatsize, totalbrewers, totaldrinkers, oldMoves, depth+1, maxDepth))
        {
            return true;
        }
    //}
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

    //identity
    std::vector<boatstate> prevousMoves;

    //values
    boatstate startBoat(brewers, drinkers, true);
    prevousMoves.push_back(startBoat);
    int maxdepth = 1000;
    for(int i = 0; i < maxdepth; ++i)
    {
        if (solveBoat(startBoat, capacity, brewers, drinkers, prevousMoves,0, i))
        {
            std::cout << "Depth " << i << "\n";
            std::cout << "Worked\n";
            break;
        }
    }

    getchar();
    getchar();
}