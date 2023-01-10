#include "../include/Party.h"
#include "../include/Simulation.h"
#include "../include/JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), firstIter(-1), offers() 
{
    // You can change the implementation of the constructor, but not the signature!
}

//copy constructor
Party:: Party(const Party& other): mId(other.mId), mName(other.getName()), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), firstIter(other.firstIter), offers(other.offers)
{
         
}

//copy assignment operator
Party& Party:: operator=(const Party& other)
{
    if(this != &other)
    {
        delete this->mJoinPolicy;
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        mState = other.mState;
        firstIter = other.firstIter;
        offers = other.offers;
    }
    return *this;
}

//move constructor
Party::Party(Party&& other) noexcept: mId(other.mId), mName(std::move(other.mName)), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), firstIter(other.firstIter), offers(std::move(other.offers))
{
    other.mJoinPolicy = nullptr;
}

//move assignment operator
Party& Party:: operator=(Party&& other) noexcept
{
    if(this != &other)
    {
        delete mJoinPolicy;
        mId = other.mId;
        mName = std::move(other.mName);
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        firstIter = other.firstIter;
        offers = std::move(other.offers);
        other.mJoinPolicy = nullptr;
    }
    return *this;
}

//distructor
Party:: ~Party()
{
    delete mJoinPolicy;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
    switch(mState)
    {
        case Waiting:
            break;
        case Joined:
            break;
        case CollectingOffers:
        {
            if(s.getIterNum() == firstIter + 3)
            {
                //select a coalition by join policy
                int coalitionId ((*mJoinPolicy).selectByPolicy(offers, s.getCoalitions()));
                s.addPartyToCoalition(mId, mMandates, coalitionId);
                //clone and add agent
                Agent originAgent(s.getAgents().at(coalitionId));
                Agent clonedAgent(originAgent.cloneAgent(s.getAgents().size(), mId));
                s.addAgent(clonedAgent);
                //clear the offers the party got
                offers.clear();
                //set the state of the party
                setState(Joined);
            }
        }
    }
}

void Party::addOffer(int coalitionId, int step)
{
    switch(mState)
    {
        case Waiting:
        {
            setState(CollectingOffers);
            firstIter = step;
            break;
        }
        case CollectingOffers:
            break;
        case Joined:
            break;
    }
    offers.push_back(coalitionId);
}

const vector<int>& Party::getVectorOfOffers() const
{
    return offers;
}
