#pragma once
#include <vector>

#include "Graph.h"
#include "./Container/Stack.h"

class BreadthFirstPaths
{
public:
    BreadthFirstPaths(const Graph &G, unsigned s);

    bool hasPathTo(int v) const;

    Stack<int> pathTo(int v) const;

private:
    void bfs(const Graph &G, unsigned v);

private:
    std::vector<bool> marked;

    std::vector<int> edgeTo;

    unsigned s; //start point
};

BreadthFirstPaths::BreadthFirstPaths(const Graph &G, unsigned s)
    : marked(G.getV(), false), edgeTo(G.getV(), 0), s{s}
{
    bfs(G, s);
}

void BreadthFirstPaths::bfs(const Graph &G, unsigned s)
{
    // marked[v] = true;
    // for (int w : G.getBag(v))
    //     if (!marked[w])
    //     {
    //         edgeTo[w] = v;
    //         dfs(G, w);
    //     }
}

inline bool BreadthFirstPaths::hasPathTo(int v) const
{
    return marked[v];
}

Stack<int> BreadthFirstPaths::pathTo(int v) const
{

    if (!hasPathTo(v))
        return Stack<int>{};

    Stack<int> path{};
    for (int x = v; x != s; x = edgeTo[x])
        path.push(x);
    path.push(s);
    return path;
}