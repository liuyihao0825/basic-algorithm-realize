#include "iostream"
using namespace std;

typedef struct LinkList
{
        struct LinkList *next;
        int data;
}LinkNode;

LinkNode *CreateLinkList(int a[], int len)
{
     if (a == NULL || len <= 0)
     {
           return NULL;
     }
     
     LinkNode *head = NULL;
     head = (LinkNode *)malloc(sizeof(LinkNode));
     head->data = a[0];
     head->next=NULL;
     
     LinkNode *p;
     LinkNode *end = head;
     int i;
     for (i = 1; i < len; i++)
     {
         p = (LinkNode *)malloc(sizeof(LinkNode));
         p->data = a[i];
         p->next = NULL;
         
         end->next = p;
         end = p;
     }
     end->next = head;
     
     return head;
}

void PrintLinkList(LinkNode *head)
{
     if (head == NULL)
     {
              return;
     }
     
     LinkNode *p = head;
     while ((p != NULL) && (p->next != head))
     {
           cout << p->data << "  ";
           p = p->next;
     }
     cout << p->data << endl;
}

void GetLastNum(LinkNode *&head, int n, int m, int &LastNum)
{
     if (head == NULL || m <= 0)
     {
              return;
     }
     
     int count = 0;
     LinkNode *p = head;
     LinkNode *q;
     
     //考虑 m=1 时的特殊情况，此时为最后一个节点留下 
     LinkNode *r = head;
     if (m == 1)
     {
           while (r->next != head)
           {
                 r = r->next;
           }
           LastNum = r->data;
           return;
     }
     
     while (p->next != p)
     {
           count++;
           if (count == m-1)
           {
                 q = p->next;
                 p->next = q->next;
                 free(q);
                 count = 0;    
           }
           p = p->next;
     }
     
     if (p != NULL)
     {
           LastNum = p->data;
     }
     
     return;
}

int main()
{
    int array[30];
    int input;
    int len = 0;
    
    cin >> input;
    while (input != -1)
    {
          array[len++] = input;
          cin >> input;
    }
    cout << "len=" << len << endl;
    
    LinkNode *head = CreateLinkList(array, len);
    PrintLinkList(head);
    
    int LastNum = -1;
    int m;
    cout << "input m:";
    cin >> m;
    GetLastNum(head, len, m, LastNum);
    cout << "the LastNum is " << LastNum << endl;
    
    getchar();
    getchar();
    return 0;
}
