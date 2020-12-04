#include <linklist.h>

//在链表的第i个节点后插入新的节点
template<typename DataType>
bool   LinkList<DataType>::insertNode( int i , DataType newData)
{
    ListNode<DataType> *p = head;
    int j;
    for(j=1 ; j<=i-1 ; j++)
    {
        p = p->next;
        if(p == NULL)
        {
            break;
        }
    }
    if(p==NULL && j<(i-1))
    {
        cout << "插入位置无效" << endl;
        return false;
    }
    ListNode<DataType> *node = new ListNode<DataType>(newData);

    node->next = p->next;
    p->next = node;
    return true;
}

//在链表末尾插入节点
template<typename DataType>
bool   LinkList<DataType>::insertNode( DataType newData)
{
    ListNode<DataType> *p = head;
    ListNode<DataType> *node = new  ListNode<DataType>(newData);
    if(node == NULL)
    {
        return false;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = node;
    return true;
}

//删除节点
template<typename DataType>
bool LinkList<DataType>::removeNode(ListNode<DataType> *q)
{
    if(q == NULL)
    {
        cout << "待删除节点不存在" << endl;
        return true;
    }
    ListNode<DataType> *tempPionter = head;
    while(tempPionter->next != q)
    {
        tempPionter = tempPionter->next;
    }
    tempPionter->next = q->next;
    delete q;
    return true;
}

//查找指定值的节点并返回地址
template<typename DataType>
ListNode<DataType>*  LinkList<DataType>::findNode(DataType  value)
{
    ListNode<DataType> *currentPointer = head;
    while(currentPointer != NULL && currentPointer->data != value)
    {
        currentPointer = currentPointer->next;
    }
    if(currentPointer == NULL)
    {
        cout << "erro" << endl;
        exit(1);
    }
    else
    {
        return currentPointer;
    }
}

//清空链表
template<typename DataType>
bool LinkList<DataType>::cleanLink()
{
    ListNode<DataType> *current = head;
    while(head->next != NULL)
    {
        current = head->next;
        head->next = current->next;
        delete current;
    }
}

//获取节点数据
template<typename DataType>
DataType LinkList<DataType>::getNodeData(ListNode<DataType> *p)
{
    return p->getData();
}
