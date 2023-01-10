#pragma once
#include "Agent.h"
#include "Graph.h"
#include "Party.h"

class SelectionPolicy { 
    public:
    SelectionPolicy();
    virtual ~SelectionPolicy();
    virtual int selectByPolicy(int myPartyId, const Graph& myGraph, int coalitionId) const =0;
    virtual SelectionPolicy* clone() const = 0;
    protected:
    bool canIOffer(const Party& currParty, int myCoalitionId) const;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 
public:
    MandatesSelectionPolicy();
    ~MandatesSelectionPolicy();
    int selectByPolicy(int myPartyId, const Graph& myGraph, int coalitionId) const;
    SelectionPolicy* clone() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy();
    int selectByPolicy(int myPartyId, const Graph& myGraph, int coalitionId) const;
    SelectionPolicy* clone() const;
};