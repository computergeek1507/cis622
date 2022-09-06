#include<iostream>

bool isValidBoat( int rbankbrewers, int rbankdrinkers, int lbankbrewers, int lbankdrinkers, int numInBoat, int boatsize, int totalbrewers, int totaldrinkers )
{
    return ( rbankbrewers >= rbankdrinkers || rbankbrewers == 0 || rbankdrinkers == 0 ) 
        && ( lbankbrewers >= lbankdrinkers || lbankbrewers == 0 || lbankdrinkers == 0 ) 
        && numInBoat <= boatsize && numInBoat >= 1 
        && rbankbrewers >= 0 && lbankbrewers >= 0 && rbankdrinkers >= 0 && lbankdrinkers >= 0
        && rbankbrewers <= totalbrewers && lbankbrewers <= totalbrewers 
        && rbankdrinkers <= totaldrinkers && lbankdrinkers <= totaldrinkers;
}

bool isEndState(int rb, int sb, int rd, int sd)
{
    return rb == sb && rd == sd;
}

std::pair< int, int > generateBoat( int rbankbrewers, int rbankdrinkers, int lbankbrewers, int lbankdrinkers, int boatsize, bool ltoR, int totalbrewers, int totaldrinkers )
{
    //int boatBrewers{0};
    //int boatDrinkers{ 0 };
    if( ltoR )
    {
        for( int i = boatsize; i >= 0; --i )
        {
            for( int boatDrinkers = boatsize; boatDrinkers >= 0; --boatDrinkers )
            {
                for( int boatBrewers = 0; boatBrewers <= boatsize - boatDrinkers; ++boatBrewers )
                {
                    if( isValidBoat( rbankbrewers + boatBrewers, rbankdrinkers + boatDrinkers,
                                     lbankbrewers - boatBrewers, lbankdrinkers - boatDrinkers, boatDrinkers + boatBrewers, boatsize, totalbrewers, totaldrinkers ) )
                    {
                        return { boatDrinkers, boatBrewers };
                    }
                }
            }
        }
    }
    else
    {
        for( int i = 1; i <= boatsize; ++i )
        {
            for( int boatDrinkers = i; boatDrinkers <= boatsize; ++boatDrinkers )
            {
                for( int boatBrewers = 0; boatBrewers <= boatsize - boatDrinkers; ++boatBrewers )
                {
                    if( isValidBoat( rbankbrewers - boatBrewers, rbankdrinkers - boatDrinkers,
                                     lbankbrewers + boatBrewers, lbankdrinkers + boatDrinkers, boatDrinkers + boatBrewers, boatsize, totalbrewers, totaldrinkers ) )
                    {
                        return { boatDrinkers, boatBrewers };
                    }
                }
            }
        }
    }

    return {-1,-1};
}

void printBoat( int drinkers, int brewers )
{
    std::cout << "B=" << brewers << ",D=" << drinkers << "\n";
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

    int left_brewers{ brewers };
    int left_drinkers{ drinkers };
    int right_brewers{0};
    int right_drinkers{0};
    bool ltoR{ true };

    while(true)
    {
        std::cout << "Left Bank\n";
        printBoat( left_drinkers, left_brewers );
        std::cout << "Right Bank\n";
        printBoat( right_drinkers, right_brewers );

        if( isEndState( right_brewers, brewers, right_drinkers, drinkers ) )
        {
            std::cout << "worked\n";
            break;
        }

        auto boat = generateBoat( right_brewers, right_drinkers, left_brewers, left_drinkers, capacity, ltoR, brewers, drinkers );
        std::cout << "Boat\n";
        printBoat( boat.first, boat.second );
        std::cout << "\n";
        if( ltoR )
        {
            left_brewers -= boat.second;
            right_brewers += boat.second;
            left_drinkers -= boat.first;
            right_drinkers += boat.first;
        }
        else
        {
            left_brewers += boat.second;
            right_brewers -= boat.second;
            left_drinkers += boat.first;
            right_drinkers -= boat.first;
        }
        ltoR = !ltoR;
    }

    getchar();
}