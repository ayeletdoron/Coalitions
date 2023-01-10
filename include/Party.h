#pragma once
#include <string>
#include "Coalition.h"

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party& other);
    Party& operator=(const Party& other);
    Party(Party&& other) noexcept;
    Party& operator=(Party&&) noexcept;
    ~Party();
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void addOffer(int coalitionId, int step);
    const vector<int>& getVectorOfOffers() const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int firstIter;
    vector<int> offers;
};
