#include "../include/JoinPolicy.h"

LastOfferJoinPolicy:: LastOfferJoinPolicy()
{

}

LastOfferJoinPolicy:: ~LastOfferJoinPolicy()
{
    
}

int LastOfferJoinPolicy:: selectByPolicy(const vector<int>& offers, const vector<Coalition>& coalitions) const
{
    return offers.back();
}

JoinPolicy* LastOfferJoinPolicy::clone() const
{
    return new LastOfferJoinPolicy;
}