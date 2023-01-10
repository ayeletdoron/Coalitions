#include "../include/Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), iterNum(0), mCoalitions()
{
    // You can change the implementation of the constructor, but not the signature!
    //initialize the coalitions vector
    int i(0);
    for(auto &agent: mAgents)
    {
        int partyId(agent.getPartyId());
        int pMandates (graph.getMandates(partyId));
        mCoalitions.push_back(Coalition(i, pMandates, partyId));
        //set the agent's coalition Id
        agent.setCoalitionId(i);
        i++;
    }
}

void Simulation::step()
{
    // TODO: implement this method
    mGraph.partiesStep(*this);
    for(auto &agent: mAgents)
    {
        agent.step(*this);
    }
    iterNum++;
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for(auto &coalition: mCoalitions)
    {
        if(coalition.getNumOfMandates() > 60)
        {
            return true;
        }
    }
    for(int i = 0; i < mGraph.getNumVertices(); i++)
    {
        State currState (mGraph.getParty(i).getState());
        {
            switch(currState)
            {
                case Waiting:
                {
                    return false;
                    break;
                }
                case CollectingOffers:
                {
                    return false;
                    break;
                }
                case Joined:
                    break;
            }
        }
    }
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> output;
    for(auto &coalition: mCoalitions)
    {
        //using coalition's vector of parties
        vector<int> currentCoalitionsParty (coalition.getParties());
        output.push_back(currentCoalitionsParty);
    }
    return output;
}

int Simulation::getIterNum() const
{
    return iterNum;
}

const vector<Coalition> &Simulation::getCoalitions() const
{
    return mCoalitions;
}

void Simulation:: addAgent(Agent a)
{
    mAgents.push_back(a);
}

void Simulation:: addOfferToParty(int partyId, int coalitionId)
{
    mGraph.addOfferToParty(partyId, coalitionId, iterNum);
}

void Simulation:: addPartyToCoalition(int partyId, int pMandates, int coalitionId)
{
    mCoalitions.at(coalitionId).addParty(partyId, pMandates);
}
