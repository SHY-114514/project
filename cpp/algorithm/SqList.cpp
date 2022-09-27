#include <iostream>

#define N 10
#define OK 1
#define ERROR 0

using namespace std;

typedef int Status;
typedef int DataType;

typedef struct
{
    DataType *datas;
    int length;
} SqList;

Status InitList(SqList &L)
{
    L = *(new SqList());
    L.length = 0;
    L.datas = new DataType[N];
    return OK;
}

Status Insert(SqList &L, DataType data, int position)
{
    if (position <= 0 || position > L.length + 1 || L.length > N - 1)
        return ERROR;
    int p = L.length;
    while (p > 0 && p >= position)
    {
        L.datas[p] = L.datas[p - 1];
        --p;
    }
    L.datas[p] = data;
    ++L.length;
    return OK;
}

Status Delete(SqList &L,int position)
{
    if(position < 1 || position > L.length)
        return ERROR;
    for(int p = position;p < L.length;p ++)
        L.datas[p -1] = L.datas[p];
    -- L.length;
    return OK;
}

void PrintList(SqList &L)
{
    int i = 0;
    while (i < L.length)
        cout << L.datas[i++] << "\t";
    cout << "\n";
}

int main(void)
{
    SqList L;
    InitList(L);
    for (int i = 0; i < 6; i++)
        Insert(L, (i + 11) * i, i + 1);
    PrintList(L);
    Insert(L, 666, 3);
    PrintList(L);
    Delete(L,3);
    PrintList(L);
    return 0;
}
