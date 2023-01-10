#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& other);
    Agent& operator=(const Agent& other);
    Agent(Agent&& other) noexcept;
    Agent& operator=(Agent&& other) noexcept;
    ~Agent();
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Agent cloneAgent(int mId, int partyId) const;
    void setCoalitionId(int cId);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
