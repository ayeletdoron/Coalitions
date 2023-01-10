#include "../include/SelectionPolicy.h"

MandatesSelectionPolicy:: MandatesSelectionPolicy()
{

}

MandatesSelectionPolicy:: ~MandatesSelectionPolicy()
{
    
}

int MandatesSelectionPolicy:: selectByPolicy(int myPartyId, const Graph& myGraph, int coalitionId) const
{
    int maxMandates (-1);
    int maxIndex (-1);
    for (int i = 0; i < myGraph.getNumVertices(); i++)
    {
        int currentMandates (myGraph.getParty(i).getMandates());
        if (currentMandates > maxMandates && myGraph.getEdgeWeight(myPartyId, i) > 0)
        {
            Party currentParty (myGraph.getParty(i));
            bool canIOffer ((*this).canIOffer(currentParty, coalitionId));
            if(canIOffer)
            {
                maxIndex = i;
                maxMandates = currentMandates;
            }
        }
    } 
    return maxIndex;
}

SelectionPolicy* MandatesSelectionPolicy:: clone() const
{
    SelectionPolicy* p = new MandatesSelectionPolicy;
    return p;
}