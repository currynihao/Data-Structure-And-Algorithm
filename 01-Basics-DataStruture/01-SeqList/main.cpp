#include <QCoreApplication>
#include <iostream>
using namespace std;

//线性表的结构
template<typename DataType>
class SeqList
{
public:
    SeqList(int size = defaultSize)
    {
        if(size > 0)
        {
            maxSize = size;
            length = 0;
            elements = new DataType[maxSize];
            for(int i=0 ; i<maxSize ; i++)
            {
                elements[i] = NULL;
            }
        }
    }

    ~SeqList()
    {
        delete[] elements;
    }

    bool insertElement(DataType data);
    bool deleteElement(int location);
    DataType getElement(int location);
    bool changeElement(int location , DataType newData);

    int getLength()
    {
        return length;
    }
private:
    static const int defaultSize = 10;
    DataType *elements;
    int maxSize;
    int length;
};

//顺序表插入操作
template<typename DataType>
bool SeqList<DataType>::insertElement(DataType data)
{
    int currentIndex = length;
    if(length >= maxSize)
    {
        return false;
    }
    else
    {
        elements[currentIndex] = data;
        length++;
        return true;
    }
}

//获取指定位置的元素
template<typename DataType>
DataType SeqList<DataType>::getElement(int location)
{
    if(location < 0 || location > length)
    {
        cout << "参数无效" << endl;
        return 0;
    }
    else
    {
        return elements[location];
    }
}

//删除指定位置的元素
template<typename DataType>
bool SeqList<DataType>::deleteElement(int location)
{
    if(location >= length || location < 0)
    {
        return false;
    }
    else
    {
        for(int i=location ; i<length ; i++)
        {
            elements[i] = elements[i+1];
        }
        length--;
        return true;
    }
}
//修改指定位置的元素值
template<typename DataType>
bool SeqList<DataType>::changeElement(int location, DataType newData)
{
    if(location<0 || location >= length)
    {
        return false;
    }
    else
    {
        elements[location] = newData;
        return true;
    }
}
//主程序
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SeqList<int> list(10);
    for(int i=0 ; i<10 ; i++)
    {
        list.insertElement(i*10);
    }
    for(int i=0 ; i<list.getLength() ; i++)
    {
        cout << list.getElement(i) << endl;
    }

    list.deleteElement(3);

    for(int i=0 ; i<list.getLength() ; i++)
    {
        cout << list.getElement(i) << endl;
    }
    return a.exec();
}
