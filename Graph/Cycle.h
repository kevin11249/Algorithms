#pragma once

#include <vector>

#include "Graph.h"

class Cycle
{
public:
    Cycle(const Graph &G) : marked(G.getV())
    {
        for (unsigned s = 0; s < G.getV(); ++s)
        {
            if (!marked[s])
                dfs(G, s, s);
        }
    }

private:
    void dfs(const Graph &G, unsigned v, unsigned u)
    {
        // marked[v] = true;
        // for (int w : G.getBag(v))
    }

private:
    std::vector<bool> marked;
    bool hasCycle;
};