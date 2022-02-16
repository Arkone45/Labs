#ifndef mod
#define mod

template <class TYPE> struct Node
{
    TYPE val;
    Node *next;
    Node *prev;
};

template <class TYPE = char> class UDList
{
private:
    Node<TYPE> *first;
    Node<TYPE> *last;
public:
    UList ();
    ~UList ();
    boolean isempty ();
    void remove_item (TYPE v);
    TYPE get_max ();
    Node<TYPE> *get_first ();
    friend Node<TYPE> *get_next <> (Node<TYPE> *cur);
    friend TYPE get_value <> (Node<TYPE> *cur);
    friend std::ostream& operator<< <> (std::ostream &os, const UList<TYPE> &l);
    friend std::ifstream& operator>> <> (std::ifstream &is, UList<TYPE> &l);
};

template <class TYPE = float> struct UQueue
{
    int tail;
    TYPE *mas;
    UDeq ();
    ~UDeq ();
    boolean isempty ();
    TYPE take_first ();
    TYPE take_last ();
    void add_first (TYPE inp);
    void add_last (TYPE inp);
};

template <class TYPE> std::ostream& operator<< (std::ostream &os, const UDeq<TYPE> &d);
template <class TYPE> std::ifstream& operator>> (std::ifstream &is, UDeq<TYPE> &d);

#endif // mod
