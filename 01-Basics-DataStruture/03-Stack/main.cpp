#include <QCoreApplication>
#include <iostream>
using namespace std;

template<typename DataType>
class Stack
{
public:
    Stack(int size)
    {
        maxSize = size;
        top = -1;
        elements = new DataType[size];
    }
    ~Stack()
    {
        delete [] elements;
    }

    bool push(DataType data);

    DataType pop();

private:
    DataType *elements;
    int top;
    int maxSize;
};

//入栈操作
template<typename DataType>
bool   Stack<DataType>:: push(DataType data)
{
    if(top == maxSize)
    {
        return false;
    }
    elements[++top] = data;
    return true;
}

//出栈操作
template<typename DataType>
DataType Stack<DataType>::pop()
{
    if(top == -1)
    {
        exit(1);
    }
    return elements[top--];
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "hello" << endl;
    Stack<int> s = Stack<int>(6);
    int temp = 0;
    s.push(23);
    s.push(56);
    s.push(11);
    temp = s.pop();
    cout << temp << endl;
    return a.exec();

}

