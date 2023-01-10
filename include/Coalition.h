#pragma once
#include <vector>
using std::vector;

class Coalition{
    public:
    Coalition(int id, int mandates, int firstPartyId);

    vector<int> getParties() const;
    void addParty(int partyId, int pMandates);
    int getNumOfMandates() const;

    private:
    int cId;
    int cMandates;
    vector<int> partiesAtCoalition;
};