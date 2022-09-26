#include<stdio.h>

#define N 100

typedef int DataType;
typedef int Status;
Status OK = 1,ERROR = 0;

typedef struct {
    DataType datas[N];
    int length;
} SqList;

Status InitList(SqList* L){
    if(L != NULL)
        return ERROR;
    DataType* datas = (DataType*) malloc(N * sizeof(DataType))
    L->length = 0;
    L->datas = datas;
    return OK;
}

Status InsertData(DataType data,SqList* L,int position){
    int i;
    if(position < 0 || L->length +1 < position || L->length < 100)
        return ERROR;
    for(i = L->length,i >= position,i --){
        L->datas[i] ^= L->datas[i +1];
        L->datas[i +1] ^= L->datas[i];
        L->datas[i] ^= L->datas[i +1];
    }
    L->datas[i +1] = data;
    ++ L->length;
    return OK;
}

int GetLength(SqList* L){
    return L->length;
}

// Status DeleteData(SqList* L,int position){
//     if(position < 0 || position > L->length)
//         return ERROR;
    
// }