#include <QCoreApplication>
#include <iostream>

using namespace std;

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





private:
    ListNode *head;
};

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


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    return a.exec();
}
