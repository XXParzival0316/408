#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType* data;
    int length;
}SeqList;


SeqList* initList(){
    SeqList* L = (SeqList*)malloc(sizeof(SeqList));
    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    return L;
}

//查找元素
int findElem(SeqList *L,ElemType e){
    for (int i = 0; i < L->length; i++) {
        if(L->data[i] == e){
            return i + 1;
        }
     } 
    return  0;
}

//尾部添加元素
int appendElem(SeqList *L, ElemType e){
    if(L->length >= MAXSIZE){
       printf("顺序表已满");
    }

    L->data[L->length] = e;
    L->length++;
    return 0;
}

//遍历
void listElem(SeqList *L){
    for(int i = 0;i < L->length; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//插入数据
int insertElem(SeqList *L, int pos, ElemType e){
    if(pos <= L->length){
        for (int i = L->length-1; i >= pos -1 ; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
    }
    return 1;
}

int deleteElem(SeqList *L,int pos, ElemType *e){
   *e = L->data[pos - 1]; 
   if(pos < L->length){
        for (int i = pos; i < L->length; i++) {
            L->data[i-1] = L->data[i];
        }
   }
   L->length--;
   return 1;
}

int main(int argc, char *argv[])
{
    //声明一个顺序表并初始化
    SeqList* list = initList();
    printf("初始化成功，目前长度占用%d\n",list->length);
    printf("目前占用内存%zu字节\n",sizeof(list->data));
    appendElem(list,88);
    appendElem(list,42);
    appendElem(list,23);
    appendElem(list,24);
    listElem(list);
    insertElem(list, 2, 18);
    listElem(list);
    ElemType deldata;
    deleteElem(list, 2, &deldata);
    printf("被删除的数据为:%d\n",deldata);
    listElem(list);
    printf("该元素的位置为:%d\n", findElem(list, 88));
    return 0;
}
