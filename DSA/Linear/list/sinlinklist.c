#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}Node;

Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
//头插法
int insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}
//获取尾节点
Node* gettail(Node* L){
    Node* p = L;
    while (L->next != NULL) {
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node *tail, ElemType e){
   Node* p = (Node*)malloc(sizeof(Node));
   p->data = e;
   tail->next = p;
   p->next = NULL;
   return p;
}

//指定位置插入节点 
int insertNode(Node *L,int pos,ElemType e){
    //用来保存插入位置的前驱节点
    Node *p = L;
    int i = 0;
    //遍历链表找到插入位置的前驱
    while (i < pos-1) {
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }
    
    //插入新的节点
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int isCycle(Node *head){
    Node *fast = head;
    Node *slow= head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

//找到链表环的入口
Node* findBegin(Node* head){
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        //找到快慢指针相遇的节点
        if(fast == slow){
            Node* p = fast;
            int count = 1;
            //用p指针数环内节点个数 
            while (p->next != slow) {
                count++;
                p = p->next;
            }
            
            fast = head;
            slow = head;
            //让快指针先走count步
            for(int i = 0; i < count; i++){
                fast = fast->next;
            }
            
            //快慢指针再次相遇则找到链表环入口
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

//删除节点
int deleteNode(Node *L, int pos){
    //找到删除的前驱
    Node *p = L;
    int i = 0;
    while (i < pos -1) {
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }

    if(p->next == NULL){
        printf("要删除的位置错误\n");
        return 0;
    }
    //q指向要删除的节点,随后释放
    Node* q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//删除中间节点
int delMiddleNode(Node* head){
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
    return 1;
}

//链表重新排序
void reOrderList(Node* head){
    Node* fast = head->next;
    Node* slow = head;
    //找到中间节点
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //创建三个指针管理后半段节点
    Node* first = NULL;
    Node* second = slow->next;
    slow->next = NULL;
    Node *third = NULL;
    //反转列表
    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node* p1 = head->next;
    Node* q1 = first;
    Node *p2,*q2;
    //后半段列表插缝进入前半段
    while (p1 != NULL && q1 != NULL){
        p2 = p1->next;
        q2 = q1->next;
        
        p1->next = q1; 
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }



}

// 遍历链表
void listNode(Node* L){
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ",p->data);
        p  = p->next;
    }
    printf("\n");
}

int listLength(Node* L){
    Node *p = L;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

//释放链表
void freeList(Node* L){
    Node* p = L->next;
    Node *q;

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

//双指针(快慢指针)寻找倒数K节点
int findNodeFS(Node *L, int k){
    Node *fast = L->next;
    Node *slow = L->next;
    for(int i = 0; i < k;i++){
        fast = fast->next;
    }

    while (fast != NULL) {
       fast = fast ->next; 
       slow = slow->next; 
    }

    printf("倒数第%d个节点值为:%d\n", k, slow->data);
    return 1;
}

//删除绝对值相同的节点
void removeNode(Node *L, int n){
    Node* p = L;
    int index;//作为数组下标使用
    int* q = (int*)malloc(sizeof(int)*(n+1));

    //遍历数组，初始化值为0
    for(int i = 0; i < n+1; i++){
        *(q + i) = 0;
    }

    while (p->next != NULL) {
        //abs获取绝对值
        index = abs(p->next->data);
        if(*(q + index) == 0){
            *(q + index) = 1;
            p = p->next;
        }else{
            Node* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

void reverselist(Node *L){
    listNode(L);
    printf("反转链表\n");
    Node* first = NULL;
    Node* second = L->next;
    Node* third;
    
    first = NULL; 
    second = L->next;
    
    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    L->next = first;
    listNode(L);
}

int main(int argc, char *argv[])
{
    Node *list = initList();
    Node* tail = gettail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node* three = tail;
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->next = three;
    if(isCycle(list)){
        printf("有环\n");
    }else{
        printf("无环\n");
    }
    Node *p = findBegin(list);
    printf("环入口的值为%d\n",p->data);
    /*
    reOrderList(list);
    delMiddleNode(list);
    reverselist(list);
    listNode(list);
    insertNode(list, 2, 20);
    listNode(list);
    removeNode(list, listLength(list));
    printf("去重过后,");
    listNode(list);
    findNodeFS(list, 2);
    deleteNode(list, 3);
    listNode(list);
    printf("链表的长度是%d\n",listLength(list));
    freeList(list);
    printf("free链表过后,");
    printf("链表的长度是%d\n",listLength(list));
    */
    return 0;
}
