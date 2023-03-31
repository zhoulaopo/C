#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;
typedef struct STList              //����ģ��
{
    SLDateType date;
    struct STList* next;
}STLnode;

void menu()
{
    printf("\n***********************************************************************************************************\n\n");
    printf("                            1��PushBackβ��                     2��PopBackβɾ               \n");
    printf("                            3��Revice�޸�                       4��Find����                   \n");
    printf("                            5��Popfrontͷɾ                     6��Pushfrontͷ��              \n");
    printf("                            7��Insertָ��λ�ò���               8��Afterָ��λ�ò���(��) 11��(ǰ)       \n");
    printf("                            9��InsertEraseɾ��ָ��λ��         10��ɾ��ָ��λ�ú�һ��           \n");
    printf("                            11��Print��ӡ                       0��Exit�˳�                    \n");
    printf("\n************************************************************************************************************\n\n");
}

enum STL
{
    EXIT,           //�˳�
    PUSHBACK,       //β��
    POPBACK,
    REVICE,
    FIND,
    POPFRONT,
    PUSHFRONT,
    INSERT,
    INSERTAFTER,
    INSERTERASE,
    INSERTERASEAFTER,   //ָ��λ��ɾ������һ����
    PRINT,
    INSERT2,          //12ָ��λ�ò��루ǰ��
    INTFIND,       //13���ҵڼ�����
};



STLnode* STListCheck(SLDateType x);             //�����½ڵ�
void STListPushFront(STLnode** head, SLDateType x);    //ͷ��
void STListPopFront(STLnode** head);                  //ͷɾ
void STListPushBack(STLnode** head, SLDateType x);    //β��
void STListPopBack(STLnode** head);     //βɾ
STLnode* STListFind(STLnode* head, SLDateType x);        //����
void STListRevice(STLnode** head, SLDateType num);      //�޸�
void STListInsert(STLnode** head, SLDateType num, SLDateType x);       //�±귨ָ��λ�ò���;
void STListInsert_(STLnode** head, STLnode* place, SLDateType x);        //ָ��λ�ò�����ϲ��Һ���ʹ��(�ڲ���λ��֮ǰ)
void STListInsertAfter(STLnode* place, SLDateType x);  //�ڲ���λ�õĺ������
void STListErase(STLnode** head, STLnode* place);      //ָ��λ��ɾ��
void STListEraseAfter(STLnode** head, STLnode* place); //ָ��λ�õĺ�һ��ɾ��
void STListDestroy(STLnode** head);       //����
void Find(STLnode* head, SLDateType x);  //�����ڵڼ�����
void STLPrint(STLnode* head);           //��ӡ



int main()
{
    menu();
    STLnode* head = NULL;
    int input = 0, num = 0, x = 0, count = 0;;
    do {
        count++;
        if (count % 5 == 0) menu();
        printf("����������Ҫ�Ĳ���:");
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            STListDestroy(&head);
            break;

        case PUSHBACK:
            printf("��������Ҫ�����ֵ��");
            scanf("%d", &num);
            STListPushBack(&head, num);
            break;

        case POPBACK:
            STListPopBack(&head);
            break;

        case REVICE:
            printf("��������Ҫ�޸ĵ���:");
            scanf("%d", &num);
            STListRevice(&head, num);
            break;

        case FIND:
            printf("��������Ҫ���ҵ���:");
            scanf("%d", &num);
            STListFind(head, num);
            break;

        case POPFRONT:
            STListPopFront(&head);
            break;

        case PUSHFRONT:
            printf("��������Ҫ�����ֵ��");
            scanf("%d", &num);
            STListPushFront(&head, num);
            break;

        case INSERT:
            printf("��������Ҫ��ʲôλ�ò���:");
            scanf("%d", &num);
            printf("��������Ҫ����ʲô����");
            scanf("%d", &x);
            STListInsert(&head, num, x);
            break;

        case INSERTAFTER:
            printf("��������Ҫ���ĸ����ĺ������:");
            scanf("%d", &num);
            printf("��������Ҫ�������:");
            scanf("%d", &x);
            STListInsertAfter(STListFind(head, num), x);
            break;

        case INSERTERASE:
            printf("��������Ҫɾ���ĸ���:");
            scanf("%d", &num);
            STListErase(&head, STListFind(head, num));
            break;

        case INSERTERASEAFTER:
            printf("��������Ҫɾ���ĸ����ĺ���(�����������һ����):");
            scanf("%d", &num);
            STListEraseAfter(&head, STListFind(head, num));
            break;

        case PRINT:
            STLPrint(head);
            break;

        case INSERT2:
            printf("��������Ҫ�������ĸ�����ǰ��:");
            scanf("%d", &num);
            printf("��������Ҫ���������");
            scanf("%d", &x);
            STListInsert_(&head, STListFind(head, num), x);
            break;

        case INTFIND:
            printf("��������Ҫ���ҵ���:");
            scanf("%d", &x);
            Find(head, x);
            break;

        default: printf("�ϱ�û���������,������\n");
            break;

        }
    } while (input);
    return 0;
}


STLnode* STListCheck(SLDateType x)           //����һ���µĽ��
{
    STLnode* NewNode = (STLnode*)malloc(sizeof(STLnode));
    if (NewNode == NULL) {
        printf("�ռ䴴��ʧ��\n");
        exit(-1);
    }
    NewNode->date = x;
    NewNode->next = NULL;
    return NewNode;
}


void STListPushFront(STLnode** head, SLDateType x)       //ͷ��
{
    assert(head);   //��ַ��Զ����Ϊ��,������Ҫ�Ƿ�ֹ��ֵ����
    STLnode* NewNode = STListCheck(x);
    NewNode->next = *head;
    *head = NewNode;

}

void STListPopFront(STLnode** head)              //ͷɾ
{
    if (*head == NULL) printf("��Ϊ��,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert(*head != NULL);    //���ж��Ƿ���ڿգ�����ǿ�����ֱ���˳�
    // STLnode *Newhead = *head;   //�ȴ���һ���µ�ָ�� ͬʱָ���һ�����
    // *head = Newhead->next;      //�õ�һ������¼��һ�����ĵ�ַ
    // free( Newhead );           //�ٰ�ͬʱָ���һ�����ĵ�ַ��Ԫ�ͷ�
    // Newhead = NULL;

    /*�ڶ��ַ�����һ����ԭ��*/
    STLnode* NewNode = (*head)->next;  //����һ��ָ�룬��¼�ڶ������
    free(*head);                  //��ͷ����ͷ�
    *head = NewNode;            /*�ͷ��˵�һ����㣬�ٰѵڶ������ĵ�ַ��ԭ����ͷ��㣬
                                  �൱��ͷ�������Ų��һ�����*/


}


void STListPushBack(STLnode** head, SLDateType x)    //β��
{
    assert(head);   //��ַ��Զ����Ϊ��,������Ҫ�Ƿ�ֹ��ֵ����
    STLnode* newnode = STListCheck(x);
    if (*head == NULL) {         //�����ͷָ��Ϊ�գ��Ǿ��ǿ������ǾͲ�����β�����
        *head = newnode;               //��ͷָ��ָ���´����Ľڵ㣬�͵õ���ͷָ��ָ��ĵ�һ���ڵ�
    }
    else {
        STLnode* tail = *head;             //����һ��Ҳ �� ָ��  ͷ�ڵ�  ��ָ��
        while (tail->next != NULL) {
            tail = tail->next;               //��������ʱ�� tail ��ľ������Ľڵ�͵õ���β�ڵ�
        }

        tail->next = newnode;         //��β�ڵ��next�����µĽڵ�ĵ�ַ��������
    }
}


void STListPopBack(STLnode** head)      //βɾ
{
    if (*head == NULL) printf("��Ϊ��,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert(*head != NULL);   //����ǿգ��Ǿ��˳�����
    STLnode* follow = NULL;     //�ȴ���һ���յ�ָ��
    STLnode* tail = *head;
    while (tail->next != NULL) {
        follow = tail;             //ÿ��ѭ�����ÿյ�ָ����ָ������ڵ㣨 ��һ����� ��
        tail = tail->next;
    }
    free(tail);             //������tail�������һ����㣬ֱ���ͷ�ɾ��
    tail = NULL;
    follow->next = NULL;      /*�������ʱ��follow����tail( Ҳ����ûɾ��֮ǰ�����һ��������һ����� )����һ�����
                                ����Ϊ���µ����Ľ�㣬��������nextָ���*/


}
void Find(STLnode* head, SLDateType x)       //���ҵڼ�����
{
    if (head == NULL) {
        printf("��Ϊ�գ�����ʧ��\n");
        return;
    }
    int count = 0;
    STLnode* next = head;
    while (next != NULL) {
        count++;
        if (next->date == x) {
            printf("��Ҫ�ҵ����ڵ�%d��", count);
            return;
        }
        next = next->next;
    }
    printf("û�������\n");
}

STLnode* STListFind(STLnode* head, SLDateType x)   //����
{
    STLnode* pos = head;
    while (pos != NULL) {
        if (pos->date == x) {          //һ��һ������ ���ҵ��ʹ���ַ
            return pos;
        }
        pos = pos->next;
    }
    return NULL;

}


void STListRevice(STLnode** head, SLDateType num)   //�޸�
{
    if (*head == NULL) printf("��Ϊ��,�޸�ʧ�ܣ�����ǿ���˳�\n");
    assert(*head != NULL);
    int input = 0, input1 = 0;
    printf("��������Ҫ�޸ĳɵ���:");
    scanf("%d", &input);
    printf("��1ֻ��һ����ǰ����Ҫ�޸ĵ���,��2�޸�����Ҫ�޸ĵ�ȫ��ֵ:");
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

void STListInsert(STLnode** head, SLDateType num, SLDateType x)   //�±귨ָ��λ�ò���
{
    assert(*head != NULL);

    num -= 1;  //�����±�
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
        prev = prev->next;            //������prev����Ҫ�������ǰһ�����
    }
    NewNode->next = prev->next;     //ע�����ӵ�˳��Ҫ�����µĽ��������һ�����,�������prev�������µĽ��,��ôԭ������һ�������Ҳ�����
    prev->next = NewNode;

}


void STListInsert_(STLnode** head, STLnode* place, SLDateType x)  //�������Ǹ�����ǰ��
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

void STListInsertAfter(STLnode* place, SLDateType x) //��λ�ú����
{
    if (place == NULL) printf("��ǰ��Ϊ��,�����Ϲ���,����ǿ���˳�\n");
    assert(place != NULL);
    STLnode* NewNode = STListCheck(x);
    NewNode->next = place->next;
    place->next = NewNode;

}

void STListErase(STLnode** head, STLnode* place)     //ָ��λ��ɾ��
{
    if (*head == NULL) printf("��Ϊ��,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert(*head != NULL);
    if (*head == place) {          //Ҫɾ��λ����ͷ���
        *head = place->next;     //����ͷָ��ָ����һ�����
        free(place);
        place = NULL;
        return;
    }
    STLnode* prev = *head;
    while (prev->next != place) {
        prev = prev->next;         //������prev������Ҫɾ������һ�����
    }
    // if (place->next == NULL) {     //β���
    //     free(place);
    //     place = NULL;
    //     prev->next = NULL;
    //     return;
    // }
    prev->next = place->next;   //��Ҫɾ������һ���������Ҫɾ������һ�����
    free(place);
    place = NULL;              //��������ϰ�ߣ����ͷŵ��ڴ��ÿ�~=��=  ��Ȼ������߲���Ҳ�У���Ϊplaceֻ��һ��ֵ����

}

void STListEraseAfter(STLnode** head, STLnode* place)   //ɾ����һ��
{
    if ((*head) == NULL) printf("����Ϊ��,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert((*head) != NULL);

    if (place == NULL) printf("Ҫɾ�������Ľ��Ϊ��,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert(place != NULL);

    if (place->next == NULL) printf("Ҫɾ���������������һ�����ĺ�һ����,ɾ��ʧ�ܣ�����ǿ���˳�\n");
    assert(place->next != NULL);

    STLnode* next = place->next;
    place->next = next->next;
    free(next);
    next = NULL;
}

void STLPrint(STLnode* head)       //��ӡ
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
        STLnode* next = follow->next;   //�ȴ���һ���ĵ�ַ
        free(follow);               //Ȼ������ڵĵ�ַ�ͷ�
        follow = next;               //�ڴ�һ����һ���ĵ�ַ������һ������
    }
    free(*head);
    *head = NULL;
}