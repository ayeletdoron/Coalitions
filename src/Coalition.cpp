#include "../include/Coalition.h"

Coalition::Coalition(int id, int mandates, int firstPartyId):cId(id), cMandates(mandates), partiesAtCoalition()
{
   partiesAtCoalition.push_back(firstPartyId);
} 
vector<int> Coalition:: getParties() const
{
   return partiesAtCoalition;
}

int Coalition:: getNumOfMandates() const
{
   return cMandates;
}
void Coalition:: addParty(int partyId, int pMandates){
   partiesAtCoalition.push_back(partyId);
   cMandates += pMandates;
}