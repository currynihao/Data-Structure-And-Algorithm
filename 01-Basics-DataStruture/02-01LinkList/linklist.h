#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
using namespace std;
template<typename DataType> class ListNode;

//构造链表
template<typename DataType>
class LinkList
{
public:
    LinkList()
    {
        head = new ListNode();
    }
    LinkList(ListNode *node)
    {
        head = node;
    }
    ~LinkList()
    {
        delete head;
    }
    //插入节点
    bool insertNode( int i , DataType newData);
    //插入节点
    bool insertNode( DataType newData);
    //删除节点
    bool removeNode(ListNode<DataType> *q);
    //查找指定值的节点并返回地址
    ListNode* findNode(DataType  value);
    //清空链表
    bool cleanLink();
    //获取节点数据
    DataType getNodeData(ListNode<DataType> *p);

private:
    ListNode *head;
};

//构造链表节点
template<typename DataType>
class ListNode
{
public:
    ListNode()
    {
        next = NULL;
    }
    ListNode(DataType item , ListNode<DataType> *nextNode=NULL)
    {
        data = item;
        next = nextNode;
    }
    ~ListNode()
    {
        next = NULL;
    }
    //获取节点内的数据
    DataType getData()
    {
        return data;
    }
    //获取指针
    ListNode* getNext()
    {
        return next;
    }

private:
    friend typename LinkList<DataType>;
    DataType *next;
    DataType data;
};

#endif // LINKLISTHEADER_H
