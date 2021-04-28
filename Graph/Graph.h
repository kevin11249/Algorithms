#pragma once

#include <vector>

#include "../Container/Bag.h"

class Graph
{
public:
    Graph(unsigned V) : V{V}, E{0}, adj(V) {}

    unsigned getV() const
    {
        return V;
    }

    unsigned getE() const
    {
        return E;
    }

    void addEdge(unsigned v, unsigned w)
    {
        adj[v].add(w);
        adj[w].add(v);
        E++;
    }

    Bag<int> getBag(unsigned v) const
    {
        return adj[v];
    }

private:
    unsigned V;

    unsigned E;

    std::vector<Bag<int>> adj;
};