       #include "../include/Agent.h"
    #include "../include/SelectionPolicy.h"
    #include "../include/Simulation.h"

    Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(-1)
    {
        // You can change the implementation of the constructor, but not the signature!
    }

    //copy constructor
    Agent:: Agent(const Agent& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), mCoalitionId(other.mCoalitionId)
    {
        
    }

    //copy assignment operator
    Agent& Agent:: operator=(const Agent& other)
    {
        if(this != &other)
        {
            delete this->mSelectionPolicy;
            mAgentId = other.mAgentId;
            mPartyId = other.mPartyId;
            mSelectionPolicy = other.mSelectionPolicy->clone();
            mCoalitionId = other.mCoalitionId;
        }
        return *this;
    }

    //move constructor
    Agent::Agent(Agent&& other) noexcept: mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId)
    {
        other.mSelectionPolicy = nullptr;
    }

    //move assignment operator
    Agent& Agent:: operator=(Agent&& other) noexcept
    {
        if(this != &other)
        {
            delete this->mSelectionPolicy;
            mAgentId = other.mAgentId;
            mPartyId = other.mPartyId;
            mSelectionPolicy = other.mSelectionPolicy;
            mCoalitionId = other.mCoalitionId;
            other.mSelectionPolicy = nullptr;
        }
        return *this;
    }

    //distructor
    Agent:: ~Agent()
    {
        delete mSelectionPolicy;
    }

    int Agent::getId() const
    {
        return mAgentId;
    }

    int Agent::getPartyId() const
    {
        return mPartyId;
    }

    void Agent::step(Simulation &sim)
    {
        // TODO: implement this method
        //select a party by selection policy
        int partyId ((*mSelectionPolicy).selectByPolicy(mPartyId, sim.getGraph(), mCoalitionId));
        if(partyId != -1)
        {
            sim.addOfferToParty(partyId, mCoalitionId);
        }
    }

    //clone an agent when a party joines a coalition
    Agent Agent:: cloneAgent(int mId, int partyId) const
    {
        SelectionPolicy* clonedPolicy = (*mSelectionPolicy).clone();
        Agent clonedAgent(mId, partyId, clonedPolicy);
        clonedAgent.setCoalitionId(mCoalitionId);
        return clonedAgent;
    }

    void Agent:: setCoalitionId(int cId)
    {
        mCoalitionId = cId;
    }
