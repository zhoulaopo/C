#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;
typedef struct STList              //链表模型
{
    SLDateType date;
    struct STList* next;
}STLnode;

void menu()
{
    printf("\n***********************************************************************************************************\n\n");
    printf("                            1、PushBack尾插                     2、PopBack尾删               \n");
    printf("                            3、Revice修改                       4、Find查找                   \n");
    printf("                            5、Popfront头删                     6、Pushfront头插              \n");
    printf("                            7、Insert指定位置插入               8、After指定位置插入(后) 11、(前)       \n");
    printf("                            9、InsertErase删除指定位置         10、删除指定位置后一个           \n");
    printf("                            11、Print打印                       0、Exit退出                    \n");
    printf("\n************************************************************************************************************\n\n");
}

enum STL
{
    EXIT,           //退出
    PUSHBACK,       //尾插
    POPBACK,
    REVICE,
    FIND,
    POPFRONT,
    PUSHFRONT,
    INSERT,
    INSERTAFTER,
    INSERTERASE,
    INSERTERASEAFTER,   //指定位置删除（后一个）
    PRINT,
    INSERT2,          //12指定位置插入（前）
    INTFIND,       //13查找第几个数
};



STLnode* STListCheck(SLDateType x);             //创建新节点
void STListPushFront(STLnode** head, SLDateType x);    //头插
void STListPopFront(STLnode** head);                  //头删
void STListPushBack(STLnode** head, SLDateType x);    //尾插
void STListPopBack(STLnode** head);     //尾删
STLnode* STListFind(STLnode* head, SLDateType x);        //查找
void STListRevice(STLnode** head, SLDateType num);      //修改
void STListInsert(STLnode** head, SLDateType num, SLDateType x);       //下标法指定位置插入;
void STListInsert_(STLnode** head, STLnode* place, SLDateType x);        //指定位置插入配合查找函数使用(在插入位置之前)
void STListInsertAfter(STLnode* place, SLDateType x);  //在插入位置的后面插入
void STListErase(STLnode** head, STLnode* place);      //指定位置删除
void STListEraseAfter(STLnode** head, STLnode* place); //指定位置的后一个删除
void STListDestroy(STLnode** head);       //销毁
void Find(STLnode* head, SLDateType x);  //查找在第几个数
void STLPrint(STLnode* head);           //打印



int main()
{
    menu();
    STLnode* head = NULL;
    int input = 0, num = 0, x = 0, count = 0;;
    do {
        count++;
        if (count % 5 == 0) menu();
        printf("请输入你想要的操作:");
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            STListDestroy(&head);
            break;

        case PUSHBACK:
            printf("请输入你要插入的值：");
            scanf("%d", &num);
            STListPushBack(&head, num);
            break;

        case POPBACK:
            STListPopBack(&head);
            break;

        case REVICE:
            printf("请输入你要修改的数:");
            scanf("%d", &num);
            STListRevice(&head, num);
            break;

        case FIND:
            printf("请输入你要查找的数:");
            scanf("%d", &num);
            STListFind(head, num);
            break;

        case POPFRONT:
            STListPopFront(&head);
            break;

        case PUSHFRONT:
            printf("请输入你要插入的值：");
            scanf("%d", &num);
            STListPushFront(&head, num);
            break;

        case INSERT:
            printf("请输入你要在什么位置插入:");
            scanf("%d", &num);
            printf("请输入你要插入什么数：");
            scanf("%d", &x);
            STListInsert(&head, num, x);
            break;

        case INSERTAFTER:
            printf("请输入你要在哪个数的后面插入:");
            scanf("%d", &num);
            printf("请输入你要插入的数:");
            scanf("%d", &x);
            STListInsertAfter(STListFind(head, num), x);
            break;

        case INSERTERASE:
            printf("请输入你要删除哪个数:");
            scanf("%d", &num);
            STListErase(&head, STListFind(head, num));
            break;

        case INSERTERASEAFTER:
            printf("请输入你要删除哪个数的后面(不能输入最后一个数):");
            scanf("%d", &num);
            STListEraseAfter(&head, STListFind(head, num));
            break;

        case PRINT:
            STLPrint(head);
            break;

        case INSERT2:
            printf("请输入你要插入在哪个数的前面:");
            scanf("%d", &num);
            printf("请输入你要插入的数：");
            scanf("%d", &x);
            STListInsert_(&head, STListFind(head, num), x);
            break;

        case INTFIND:
            printf("请输入你要查找的数:");
            scanf("%d", &x);
            Find(head, x);
            break;

        default: printf("老表没有这个操作,重新输\n");
            break;

        }
    } while (input);
    return 0;
}


STLnode* STListCheck(SLDateType x)           //创建一个新的结点
{
    STLnode* NewNode = (STLnode*)malloc(sizeof(STLnode));
    if (NewNode == NULL) {
        printf("空间创建失败\n");
        exit(-1);
    }
    NewNode->date = x;
    NewNode->next = NULL;
    return NewNode;
}


void STListPushFront(STLnode** head, SLDateType x)       //头插
{
    assert(head);   //地址永远不会为空,这里主要是防止传值错误
    STLnode* NewNode = STListCheck(x);
    NewNode->next = *head;
    *head = NewNode;

}

void STListPopFront(STLnode** head)              //头删
{
    if (*head == NULL) printf("表为空,删除失败，程序强制退出\n");
    assert(*head != NULL);    //先判断是否等于空，如果是空链表，直接退出
    // STLnode *Newhead = *head;   //先创建一个新的指针 同时指向第一个结点
    // *head = Newhead->next;      //让第一个结点记录下一个结点的地址
    // free( Newhead );           //再把同时指向第一个结点的地址单元释放
    // Newhead = NULL;

    /*第二种方法，一样的原理*/
    STLnode* NewNode = (*head)->next;  //创建一个指针，记录第二个结点
    free(*head);                  //把头结点释放
    *head = NewNode;            /*释放了第一个结点，再把第二个结点的地址给原来的头结点，
                                  相当于头结点往后挪了一个结点*/


}


void STListPushBack(STLnode** head, SLDateType x)    //尾插
{
    assert(head);   //地址永远不会为空,这里主要是防止传值错误
    STLnode* newnode = STListCheck(x);
    if (*head == NULL) {         //如果是头指针为空，那就是空链表，那就不用找尾结点了
        *head = newnode;               //让头指针指向新创建的节点，就得到了头指针指向的第一个节点
    }
    else {
        STLnode* tail = *head;             //创建一个也 是 指向  头节点  的指针
        while (tail->next != NULL) {
            tail = tail->next;               //遍历完后此时的 tail 存的就是最后的节点就得到了尾节点
        }

        tail->next = newnode;         //让尾节点的next存入新的节点的地址就链接了
    }
}


void STListPopBack(STLnode** head)      //尾删
{
    if (*head == NULL) printf("表为空,删除失败，程序强制退出\n");
    assert(*head != NULL);   //如果是空，那就退出程序
    STLnode* follow = NULL;     //先创建一个空的指针
    STLnode* tail = *head;
    while (tail->next != NULL) {
        follow = tail;             //每次循环先让空的指针先指向这个节点（ 第一个结点 ）
        tail = tail->next;
    }
    free(tail);             //遍历完tail就是最后一个结点，直接释放删除
    tail = NULL;
    follow->next = NULL;      /*遍历完此时的follow就是tail( 也就是没删除之前的最后一个结点的上一个结点 )的上一个结点
                                就作为了新的最后的结点，让这个结点next指向空*/


}
void Find(STLnode* head, SLDateType x)       //查找第几个数
{
    if (head == NULL) {
        printf("表为空，查找失败\n");
        return;
    }
    int count = 0;
    STLnode* next = head;
    while (next != NULL) {
        count++;
        if (next->date == x) {
            printf("你要找的数在第%d个", count);
            return;
        }
        next = next->next;
    }
    printf("没有这个数\n");
}

STLnode* STListFind(STLnode* head, SLDateType x)   //查找
{
    STLnode* pos = head;
    while (pos != NULL) {
        if (pos->date == x) {          //一个一个查找 能找到就传地址
            return pos;
        }
        pos = pos->next;
    }
    return NULL;

}


void STListRevice(STLnode** head, SLDateType num)   //修改
{
    if (*head == NULL) printf("表为空,修改失败，程序强制退出\n");
    assert(*head != NULL);
    int input = 0, input1 = 0;
    printf("请输入你要修改成的数:");
    scanf("%d", &input);
    printf("按1只改一个最前面你要修改的数,按2修改你想要修改的全部值:");
    scanf("%d", &input1);
    if (input1 == 1) {
        STLnode* pos = STListFind(*head, num);
        if (pos) {
            pos->date = input;
        }
        return;
    }
    if (input1 == 2) {
        STLnode* pos = STListFind(*head, num);
        while (pos != NULL) {
            pos->date = input;
            pos = STListFind(pos->next, num);
        }
    }

}

void STListInsert(STLnode** head, SLDateType num, SLDateType x)   //下标法指定位置插入
{
    assert(*head != NULL);

    num -= 1;  //按照下标
    STLnode* NewNode = STListCheck(x);
    if (num == 0) {
        NewNode->next = *head;
        *head = NewNode;
        return;
    }
    if (num == 1) {
        NewNode->next = (*head)->next;
        (*head)->next = NewNode;
        return;
    }
    STLnode* prev = *head;
    while (num--) {
        prev = prev->next;            //遍历完prev就是要插入结点的前一个结点
    }
    NewNode->next = prev->next;     //注意链接的顺序，要先让新的结点链接下一个结点,如果先让prev先链接新的结点,那么原来的下一个结点就找不到了
    prev->next = NewNode;

}


void STListInsert_(STLnode** head, STLnode* place, SLDateType x)  //插入在那个数的前面
{
    assert(*head != NULL);
    STLnode* NewNode = STListCheck(x);
    if (*head == place) {
        NewNode->next = *head;
        *head = NewNode;
        return;
    }
    STLnode* prev = *head;
    while (prev->next != place) {
        prev = prev->next;
    }
    // NewNode->next = prev->next;
    // prev->next = NewNode;
    NewNode->next = place;
    prev->next = NewNode;
}

void STListInsertAfter(STLnode* place, SLDateType x) //在位置后面插
{
    if (place == NULL) printf("当前表为空,不符合功能,程序强制退出\n");
    assert(place != NULL);
    STLnode* NewNode = STListCheck(x);
    NewNode->next = place->next;
    place->next = NewNode;

}

void STListErase(STLnode** head, STLnode* place)     //指定位置删除
{
    if (*head == NULL) printf("表为空,删除失败，程序强制退出\n");
    assert(*head != NULL);
    if (*head == place) {          //要删的位置在头结点
        *head = place->next;     //先让头指针指向下一个结点
        free(place);
        place = NULL;
        return;
    }
    STLnode* prev = *head;
    while (prev->next != place) {
        prev = prev->next;         //遍历完prev结点就是要删除的上一个结点
    }
    // if (place->next == NULL) {     //尾结点
    //     free(place);
    //     place = NULL;
    //     prev->next = NULL;
    //     return;
    // }
    prev->next = place->next;   //把要删除的上一个结点链接要删除的下一个结点
    free(place);
    place = NULL;              //养成良好习惯，把释放的内存置空~=。=  当然在这里边不置也行，因为place只是一个值拷贝

}

void STListEraseAfter(STLnode** head, STLnode* place)   //删除后一个
{
    if ((*head) == NULL) printf("链表为空,删除失败，程序强制退出\n");
    assert((*head) != NULL);

    if (place == NULL) printf("要删除的数的结点为空,删除失败，程序强制退出\n");
    assert(place != NULL);

    if (place->next == NULL) printf("要删除的数不能是最后一个数的后一个数,删除失败，程序强制退出\n");
    assert(place->next != NULL);

    STLnode* next = place->next;
    place->next = next->next;
    free(next);
    next = NULL;
}

void STLPrint(STLnode* head)       //打印
{
    STLnode* p = head;
    while (p != NULL) {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}

void STListDestroy(STLnode** head)
{
    STLnode* follow = *head;
    assert(*head != NULL);
    while (follow != NULL) {
        STLnode* next = follow->next;   //先存下一个的地址
        free(follow);               //然后把现在的地址释放
        follow = next;               //在存一次下一个的地址，给下一个待用
    }
    free(*head);
    *head = NULL;
}