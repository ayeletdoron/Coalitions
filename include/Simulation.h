#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    int getIterNum() const;
    const vector<Coalition>& getCoalitions() const;
    void addAgent(Agent a);
    void addOfferToParty(int partyId, int coalitionId);
    void addPartyToCoalition(int partyId, int pMandates, int coalitionId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    int iterNum;
    vector<Coalition> mCoalitions;
};
