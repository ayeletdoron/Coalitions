#include "../include/SelectionPolicy.h"

SelectionPolicy:: SelectionPolicy()
{

}

SelectionPolicy:: ~SelectionPolicy()
{

}

bool SelectionPolicy:: canIOffer(const Party& currParty, int myCoalitionId) const
{
    State currentState (currParty.getState());
    switch(currentState)
    {
        case Joined:
        {
            return false;
            break;
        }                    
        case CollectingOffers:
        {
            //check if my coalition hasn't offered the party yet
            for (auto &coalitionId: currParty.getVectorOfOffers())
            {
                if (coalitionId == myCoalitionId)
                {
                    return false;
                }
            }
            return true;
            break;
        }
        case Waiting:
        {
            return true;
            break;
        }
    }
    return true;
}