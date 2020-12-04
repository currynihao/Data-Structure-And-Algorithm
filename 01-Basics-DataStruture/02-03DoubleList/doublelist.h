#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>
using namespace std;

template<typename DataType> class DoubleList;

//构造双向链表数据节点
template<typename DataType>
class DoubleListNode
{
public:
    DataType getData();

public:
    friend class DoubleList<DataType>;
    DoubleListNode() : m_pprior(NULL),m_pnext(NULL){ }

    DoubleListNode(const DataType item , DoubleListNode<DataType> *prior = NULL, DoubleListNode<DataType> *next = NULL)
        :m_data(item),m_pprior(prior),m_pnext(next){}

    ~DoubleListNode()
    {
        m_pprior = NULL;
        m_pnext = NULL;
    }

    DataType m_data;
    DoubleListNode *m_pprior;
    DoubleListNode *m_pnext;
};
//构造双向链表
template<typename DataType>
class DoubleList
{
public:
    DoubleList()
    {
        head = new DoubleListNode<DataType>();
    }
    ~DoubleList()
    {
        cleanDoubleLink();
        delete head;
    }

public:
    void cleanDoubleLink();
    int getLength();
    DoubleListNode<DataType>* findNode(int i=0);
    DoubleListNode<DataType>* findNode(DataType item);

    bool insertNode(DataType item , int i=0);
    bool removeNode(int i=0);
    DataType getData(int i=0);

private:
    DoubleListNode<DataType> *head;
};

#endif // DOUBLELIST_H
