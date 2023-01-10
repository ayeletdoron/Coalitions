#include "../include/SelectionPolicy.h"

EdgeWeightSelectionPolicy:: EdgeWeightSelectionPolicy()
{

}

EdgeWeightSelectionPolicy:: ~EdgeWeightSelectionPolicy()
{
    
}

int EdgeWeightSelectionPolicy:: selectByPolicy(int myPartyId, const Graph& myGraph, int coalitionId) const
{
    int maxWeight (-1);
    int maxIndex (-1);
    for (int i = 0; i < myGraph.getNumVertices();i++ )
    {
        int currentEdgeWeight (myGraph.getEdgeWeight(myPartyId,i));
        if (currentEdgeWeight > 0 && currentEdgeWeight > maxWeight)
        {
            Party currentParty (myGraph.getParty(i));
            bool canIOffer ((*this).canIOffer(currentParty, coalitionId));
            if(canIOffer)
            {
                maxIndex = i;
                maxWeight = currentEdgeWeight;
            }
        }    
    }
    return maxIndex;
}

SelectionPolicy* EdgeWeightSelectionPolicy:: clone() const
{
    return new EdgeWeightSelectionPolicy;
}