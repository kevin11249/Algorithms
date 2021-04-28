#pragma once

template <typename T>
class Queue
{
    struct Node
    {
        T data;
        Node *next;
    };

public:
    bool isEmpty()
    {
        return first == nullptr;
    }

    unsigned size()
    {
        return N;
    }

    void enqueue(T data)
    {
        Node *old_last = last;
        last = new Node{data, nullptr};
        if (isEmpty())
            first = last;
        else
            old_last->next = last;
        N++;
    }

    T dequeue()
    {
        T data = first->data;
        Node *new_first = first->next;
        delete first;
        first = new_first;
        if (isEmpty())
            last = nullptr;
        N--;
        return data;
    }

private:
    Node *first{nullptr};
    Node *last{nullptr};
    unsigned N{0};
};