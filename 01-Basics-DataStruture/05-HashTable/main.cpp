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
        if(i<=0)
        {
            cout << "索引值错误，必须为正整数" << endl;
        }
        return elements[i-1];
    }

    //插入操作
    bool insertHash(DataType value);

private:
    int maxSize;
    int count;
    DataType *elements;
};

//hash函数
template<typename DataType>
int HashTable<DataType>::hash(DataType value)
{
    return value % 13;
}

//查找函数
template<typename DataType>
int HashTable<DataType>::searchHash(DataType value)
{
    int p = hash(value);
    if(elements[p] == value)
    {
        return p;
    }
    int rp = (p+1) % maxSize;
    while(rp != p)
    {
        if(elements[rp] == value)
        {
            return rp;
        }
        if(elements[rp] == NULL)
        {
            break;
        }
        rp = (rp+1) % maxSize;
    }
    if(rp == p)
    {
        return -2;
    }
    else
    {
        return rp;
    }
}

//插入函数
template<typename DataType>
bool HashTable<DataType>::insertHash(DataType value)
{
    int pos = searchHash(value);
    if(pos < 0)
    {
        return false;
    }
    else if(elements[pos] == value)
    {
        cout << "sdf" << endl;
        return false;
    }
    else
    {
        elements[pos] = value;
        return true;
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HashTable<int> hashtable = HashTable<int>(13);

    hashtable.insertHash(66);
    hashtable.insertHash(32);
    hashtable.insertHash(98);
    hashtable.insertHash(470);
    hashtable.insertHash(11);
    hashtable.insertHash(10);
    hashtable.insertHash(55);
    hashtable.insertHash(525);

    cout << "the locale number: "<< endl;
    for(int i=1 ; i<=13 ; i++)
    {
        cout << hashtable.getData(i) << endl;
    }
    cout << "the 55 number is:" << hashtable.searchHash(55) << endl;


    return a.exec();
}
