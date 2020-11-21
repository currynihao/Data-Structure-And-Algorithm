#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>
class Stack
{
public:
    vector<T>  value;
    T m_min;
public:
    const T& min();
    void pop();
    void push(const T &n);
    void prinValue();
    bool isEmpty();
};

template<typename T>
const T& Stack<T>::min()
{

}
template<typename T>
void  Stack<T>::push(const T &n)
{

}

template<typename T>
void  Stack<T>::pop()
{

}

template<typename T>
void  Stack<T>::prinValue()
{

}

template<typename T>
bool  Stack<T>::isEmpty()
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "hello" << endl;
    return a.exec();
}



