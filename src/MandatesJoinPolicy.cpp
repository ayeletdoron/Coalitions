#include "../include/JoinPolicy.h"

MandatesJoinPolicy:: MandatesJoinPolicy()
{

}

MandatesJoinPolicy:: ~MandatesJoinPolicy()
{
    
}

int MandatesJoinPolicy::selectByPolicy(const vector<int> &offers, const vector<Coalition> &coalitions) const
{
    int maxIndex(-1);
    int maxMandates(-1);
    int i (0);
    for (auto &coalitionId: offers)
    {
        int currCoalitionId (coalitionId);
        if (coalitions.at(currCoalitionId).getNumOfMandates() > maxMandates)
        {
            maxIndex = i;
            maxMandates = coalitions.at(currCoalitionId).getNumOfMandates();
        }
        i++;
    }
    return offers.at(maxIndex);
}

JoinPolicy* MandatesJoinPolicy:: clone() const
{
    return new MandatesJoinPolicy;
}