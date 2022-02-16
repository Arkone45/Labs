#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <clocale>
#include "12.h"

using namespace std;

template <class TYPE> UList<TYPE>::UList () : first(nullptr)
{}

template <class TYPE> UList<TYPE>::~UList ()
{
    Node<TYPE> *temp;
    while (first != nullptr)
    {
        temp = first->next;
        delete first;
        first = temp;
    }
}

template <class TYPE> boolean UList<TYPE>::isempty ()
{
    return first == nullptr;
}

template <class TYPE> void UList<TYPE>::remove_item (TYPE v)
{
    if (this->isempty())
    {
        return;
    }
    else
    {
        Node<TYPE> *cur = first;
        Node<TYPE> *temp;
        if (v == first->val)
        {
            first = first->next;
            delete cur;
        }
        else
        {
            while ((cur != nullptr) & (cur->next->val != v))
            {
                cur = cur->next;
            }
            if (cur != nullptr)
            {
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
        }
    }
}

template <class TYPE> TYPE UList<TYPE>::get_max ()
{
    Node<TYPE> *cur = first;;
    TYPE max = (TYPE)32;
    while (cur != nullptr)
    {
        if (cur->val > max)
            max = cur->val;
        cur = cur->next;
    }
    return max;
}

template <class TYPE> Node<TYPE> *UList<TYPE>::get_first ()
{
    return this->first;
}

template <class TYPE> Node<TYPE> *get_next (Node<TYPE> *cur)
{
    return cur->next;
}

template <class TYPE> TYPE get_value (Node<TYPE> *cur)
{
    return cur->val;
}

template <class TYPE> ostream& operator<< (ostream &os, const UList<TYPE> &l)
{
    const Node<TYPE> *cur = l.first;
    while (cur != NULL)
    {
        os << cur->val;
        cur = cur->next;
    }
    os << endl;
    return os;
}

template <class TYPE> ifstream& operator>> (ifstream &is, UList<TYPE> &l)
{
    if (is.is_open())
    {
        Node<TYPE> *p;
        while (!is.eof())
        {
            p = new Node<TYPE>;
            is >> p->val;
            p->next = l.first;
            l.first = p;
            is.peek();
        }
    }
    return is;
}

//======================================================================================================================

template <class TYPE> UDeq<TYPE>::UDeq () : tail(-1), mas(nullptr)
{}

template <class TYPE> UDeq<TYPE>::~UDeq ()
{
    tail = 0;
    free (mas);
}

template <class TYPE> boolean UDeq<TYPE>::isempty ()
{
    return tail < 0;
}

template <class TYPE> TYPE UDeq<TYPE>::take_first ()
{
    if (tail < 0)
        return NULL;
    TYPE temp = mas[0];
    tail -= 1;
    for (int i = 0; i <= tail; i++)
        mas[i] = mas[i+1];
    mas = (TYPE*)realloc (mas, (tail + 1)*sizeof(TYPE));
    return temp;
}

template <class TYPE> TYPE UDeq<TYPE>::take_last ()
{
    if (tail < 0)
        return NULL;
    TYPE temp = mas[tail];
    tail -= 1;
    mas = (TYPE*)realloc (mas, (tail + 1)*sizeof(TYPE));
    return temp;
}

template <class TYPE> void UDeq<TYPE>::add_last (TYPE inp)
{
    tail += 1;
    mas = (TYPE*)realloc (mas, (tail + 1)*sizeof(TYPE));
    mas[tail] = inp;
}

template <class TYPE> void UDeq<TYPE>::add_first (TYPE inp)
{
    tail += 1;
    mas = (TYPE*)realloc (mas, (tail + 1)*sizeof(TYPE));
    for (int i = tail; i > 0; i--)
        mas[i] = mas[i-1];
    mas[0] = inp;
}

template <class TYPE> std::ostream& operator<< (std::ostream &os, const UDeq<TYPE> &d)
{
    for (int i = 0; i <= d.tail; i++)
        os << d.mas[i] << " ";
    return os;
}

template <class TYPE> std::ifstream& operator>> (std::ifstream &is, UDeq<TYPE> &d)
{
    if (is.is_open())
    {
        TYPE temp;
        while (!is.eof())
        {
            is >> temp;
            d.add_last (temp);
            is.peek();
        }
    }
    return is;
}

//=============================================================================================
