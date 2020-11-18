#include <QCoreApplication>
#include <iostream>

using namespace std;

//散列表的定义
template<typename DataType> class HashTable
{
public:
    HashTable(int size)
    {
        maxSize = size;
        count = 0;
        elements = new DataType[size];
        if(elements == NULL)
        {
            exit(1);
        }
        for(int i=0 ; i<size ; i++)
        {
            elements[i] = NULL;
        }
    }
    ~HashTable()
    {
        delete[] elements;
    }

    //散列函数
    int hash(DataType value);

    //查找函数
    int searchHash(DataType value);

    //获取散列表的第i个元素
    DataType getData(int i)
    {
        if(i<=o)
        {
            cout << "索引值错误，必须为正整数" << endl;
        }
        return elements[i-1];
    }

    //插入操作


private:
    int maxSize;
    int count;
    DataType *elements;
};




















int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
