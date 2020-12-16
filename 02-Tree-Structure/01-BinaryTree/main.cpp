#include <QCoreApplication>
#include <iostream>
using namespace std;


template<typename DataType>
class BinaryTreeNode
{
public:
    BinaryTreeNode()
    {
        data = NULL;
        lchild = NULL;
        rchild = NULL;
    }
    BinaryTreeNode(DataType newData)
    {
        data = newData;
        lchild = rchild = NULL;
    }

private:
    DataType data;
    BinaryTreeNode *lchild;
    BinaryTreeNode *rchild;
};

template<typename DataType>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = new BinaryTreeNode<DataType>();
    }

    void preOrder();

    void inOrder();

    void postOrder();

    void layOrder();



private:
    BinaryTreeNode<DataType> *root;
};

template<typename DataType>
void





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "ddd" << endl;
    return a.exec();
}
