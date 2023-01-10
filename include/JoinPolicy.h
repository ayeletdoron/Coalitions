#pragma once
#include "Coalition.h"
#include "Party.h"
#include <vector>
using std::vector;

class JoinPolicy {
public:
    JoinPolicy();
    virtual ~JoinPolicy();
    virtual int selectByPolicy(const vector<int>& offers, const vector<Coalition>& coalitions) const =0;
    virtual JoinPolicy* clone() const = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    MandatesJoinPolicy();
    ~MandatesJoinPolicy();
    int selectByPolicy(const vector<int>& offers, const vector<Coalition>& coalitions) const;
    JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    LastOfferJoinPolicy();
    ~LastOfferJoinPolicy();
    int selectByPolicy(const vector<int>& offers, const vector<Coalition>& coalitions) const;
    JoinPolicy* clone() const;
};