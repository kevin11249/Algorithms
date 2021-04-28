#pragma once

#include <vector>

#include "Graph.h"

class Cycle
{
public:
    Cycle(const Graph &G) : marked(G.getV()), has_cycle{false}
    {
        for (unsigned s = 0; s < G.getV(); ++s)
        {
            if (!marked[s])
                dfs(G, s, s);
        }
    }

    bool hasCycle()
    {
        return has_cycle;
    }

private:
    void dfs(const Graph &G, unsigned v, unsigned u)
    {
        marked[v] = true;
        for (int w : G.getBag(v))
            if (!marked[w])
                dfs(G, w, v);
            else if (w != u)
                has_cycle = true;
    }

private:
    std::vector<bool> marked;
    bool has_cycle;
};