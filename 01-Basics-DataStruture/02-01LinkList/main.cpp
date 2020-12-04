#include <QCoreApplication>
#include "linklist.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ListNode<int>  *node = new ListNode<int>;
    LinkList<int> aLinkList();
//    aLinkList.insertNode(24);
//    cout << a << endl;

//    LinkList<int> linka(node);
//    a.insertNode(1,1);
//    cout << a << endl;

    cout << "hello" << endl;
    return a.exec();
}
