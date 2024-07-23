#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
    List();
    ~List();

    void pushBack(T data);
    void deleteHead();
    void clear();

    int Length(){return this->Size;}
    T& operator[] (const int index);

private:
    template <typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node (T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    Node<T>* head;
    int Size;
};

template <typename T>
List<T>::List()
{
    this->Size = 0;
    this->head = nullptr;
}

template <typename T>
List<T>::~List()
{
    this->clear();
}

template <typename T>
void List<T>::pushBack(T data)
{
    if (this->head == nullptr)
        this->head = new Node<T>(data);

    else
    {
        Node<T>* cur = this->head;

        while (cur->pNext != nullptr)
            cur = cur->pNext;

        cur->pNext = new Node<T>(data);
    }

    Size++;
}

template <typename T>
T& List<T>::operator[] (const int index)
{
    Node<T>* cur = this->head;

    for (int i = 0; i < index; i++)
        cur = cur->pNext;
    return cur->data;
}

template <typename T>
void List<T>::deleteHead()
{
    Node<T>* temp = this->head;

    this->head = this->head->pNext;

    delete temp;

    Size--;
}

template <typename T>
void List<T>::clear()
{
    while(this->head != nullptr)
        this->deleteHead();
}

int main()
{
    

    return 0;
}