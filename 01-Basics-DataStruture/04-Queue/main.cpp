#include <QCoreApplication>
#include <iostream>
using namespace std;
//构建队列对象
template<typename DataType>
class Queue
{
public:
    //构造函数
    Queue(int size)
    {
        maxSize = size;
        front = 0;
        rear = 0;
        count = 0;
        elements = new DataType[size];
        if(elements ==NULL)
        {
            exit(1);
        }
    }
    //析构函数
    ~Queue()
    {
        delete [] elements;
    }
    //入队操作
    bool insert(DataType);
    //出队操作
    DataType delElement();
private:
    int count;
    int maxSize;
    int front;
    int rear;
    DataType *elements;
};

template<typename DataType>
bool Queue<DataType>::insert(DataType data)
{
    if(count == maxSize)
    {
        return false;
    }
    elements[rear] = data;
    rear = (rear + 1)% maxSize;
    count++;
    return true;
}

template<typename DataType>
DataType Queue<DataType>::delElement()
{
    if(count == 0)
    {
        exit(1);
    }
    DataType temp = elements[front];
    front = (front + 1) % maxSize;
    count--;
    return temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "hello" << endl;

    Queue<int> queue = Queue<int>(6);
    for(int i=0 ; i<6 ; i++)
    {
        queue.insert(i*3);
    }
    for(int i=0 ; i<6; i++)
    {
        int  temp = queue.delElement();
        cout << temp << ":::" << endl;
    }

    return a.exec();
}

