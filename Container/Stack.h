#pragma once

template <typename T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
    };

public:
    void push(T data)
    {
        Node *old_first = first;
        first = new Node{data, old_first};
        N++;
    }

    T pop()
    {
        T data = first->data;
        Node* new_first = first->next;
        delete first;
        first = new_first;
        N--;
        return data;
    }

private:
    Node *first{nullptr};
    unsigned N{0};
};