#pragma once

template <class T>
class Bag
{
public:
    Bag() = default;

    void add(T item)
    {
        Node *oldFirst = first;
        first = new Node{item, oldFirst};
    }

private:
    struct Node
    {
        T item;
        Node *next{nullptr};
    };

    Node *first {nullptr};

public:
    class Iterator
    {
        friend class Bag; 
    public:
        Iterator() = default;

        bool operator==(const Iterator &iter) const
        {
            return current == iter.current;
        }

        bool operator!=(const Iterator &iter) const
        {
            return current != iter.current;
        }

        T &operator*() const
        {
            return current->item;
        }

        Iterator operator++(int) const
        {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        bool atEnd() const
        {
            return current == nullptr;
        }

    private:
        Iterator(Node *p) : current(p) {} //上面声明了友元，所以才能调用这个构造函数

        Node *current {nullptr};
    };

    Iterator begin()
    {
        return Iterator(first);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};