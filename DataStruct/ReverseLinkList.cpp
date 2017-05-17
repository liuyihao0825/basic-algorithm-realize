#include "iostream"
using namespace std;

typedef struct LinkList
{
        struct LinkList *next;
        int data;
}LinkNode;

//创建带有头结点的单链表 尾插法 
LinkNode *CreateList(int a[], int len)
{
     LinkNode *head = NULL;
     head = (LinkNode *)malloc(sizeof(LinkNode));
     head->next = NULL;
     
     LinkNode *end = head;
     LinkNode *p;
     
     for (int i = 0; i < len; i++)
     {
         p = (LinkNode *)malloc(sizeof(LinkNode));
         p->data = a[i];
         p->next = NULL;
         
         end->next = p;
         end = p;
     }
     
     return head;
}

//打印单链表 
void PrintList(LinkNode *head)
{
     if (head == NULL)
     {
              return;
     }
     
     LinkNode *p = head->next;
     while (p != NULL)
     {
           cout << p->data << "  ";
           p = p->next;
     }
}

void PrintList_2(LinkNode *head)
{
     if (head == NULL)
     {
              return;
     }
     
     LinkNode *p = head;
     while (p != NULL)
     {
           cout << p->data << "  ";
           p = p->next;
     }
}

//将单链表逆置，返回头结点指针 （头插法逆置 ） 
LinkNode *ReverseList(LinkNode* &head)
{
         if (head == NULL || head->next == NULL)
         {
                  return NULL;
         }
         
         LinkNode *p = head->next;
         LinkNode *q;
         
         while (p != NULL && p->next != NULL)
         {
               q = p->next;
               p->next = q->next;
               
               q->next = head->next;
               head->next = q;
         }
         
         return head;
}

//方法2，将单链表逆置，返回最后一个节点（依次改变节点指针逆置）
LinkNode *ReverseList_2(LinkNode *FirstNode)
{
         if (FirstNode == NULL && FirstNode->next == NULL)
         {
                       return FirstNode;
         }
         
         LinkNode *p = FirstNode;
         LinkNode *q = NULL;
         LinkNode *r;
         
         while (p != NULL && p->next != NULL)
         {
               r = p->next;
               p->next = q;
               q = p;
               p = r;
         }
         
         p->next = q;
         return p;
}

//方法3，将单链表逆置，递归实现，从后往前 
LinkNode *ReverseList_3(LinkNode *node)
{        
         LinkNode *head;
         if (node == NULL || node->next == NULL)
         {
                       return node;
         }
         
         head = ReverseList_3(node->next);
         node->next->next = node;
         node->next = NULL;
         
         return head;
}

int main()
{
    int array[30];
    int len = 0;
    int input;
    
    cin >> input;
    while (input != 0)
    {
          array[len++] = input;
          cin >> input;
    }
    cout << "len=" << len << endl;
    
    LinkNode *head;
    head = CreateList(array, len);
    PrintList(head);
    
    /*****
    cout << endl << "After Reversed:" << endl;
    head = ReverseList(head);
    PrintList(head);
    ******/
    cout << endl << "After Reversed:" << endl;
    LinkNode *FirstNode = head->next;
    /*******
    LinkNode *newHead = ReverseList_2(FirstNode);
    PrintList_2(newHead);
    *******/
    
    LinkNode *newHead = ReverseList_3(FirstNode);
    PrintList_2(newHead);
    
    getchar();
    getchar();
    return 0;
}
