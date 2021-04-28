#pragma once

template <typename T>
class Bag
{
    struct Node
    {
        T data;
        Node *next;
    };

public:
    void add(T data)
    {
        Node *old_first = first;
        first = new Node{data, old_first};
        N++;
    }

private:
    Node *first{nullptr};
    unsigned N{0};
};