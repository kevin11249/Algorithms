#pragma once
#include <vector>

#include "Graph.h"
#include "./Container/Stack.h"
#include "./Container/Queue.h"

class BreadthFirstPaths
{
public:
    BreadthFirstPaths(const Graph &G, unsigned s);

    bool hasPathTo(int v) const;

    Stack<int> pathTo(int v) const;

private:
    void bfs(const Graph &G, unsigned s);

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
    Queue<int> queue{};
    marked[s] = true;
    queue.enqueue(s);
    while (!queue.isEmpty())
    {
        int v = queue.dequeue();
        for (int w : G.getBag(v))
            if (!marked[w])
            {
                edgeTo[w] = v;
                marked[w] = true;
                queue.enqueue(w);
            }
    }
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