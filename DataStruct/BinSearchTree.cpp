#include "iostream"
using namespace std;

typedef struct BinSearchTree
{
        struct BinSearchTree *lChild;
        struct BinSearchTree *rChild;
        int data;
}BinTree;

int num = 0;
BinTree *array[20];

void CreateNode(BinTree* &Tree, int data)
{
     if (Tree == NULL)
     {
              Tree = (BinTree *)malloc(sizeof(BinTree));
              Tree->data = data;
              Tree->lChild = NULL;
              Tree->rChild = NULL;
              return;
     }
     
     if (Tree->data < data)
     {
              CreateNode(Tree->rChild, data); 
     }
     else
     {
              CreateNode(Tree->lChild, data);
     }
}

BinTree *CreateTree(int a[], int len)
{
     BinTree *tree = NULL;
     BinTree *head = NULL;
     
     for (int i = 0; i < len; i++)
     {
         CreateNode(tree, a[i]);
         if (i == 0)
         {
               head = tree;
         }
     }
     return head;
}

void PrintTree(BinTree *Tree)
{
     if (Tree == NULL)
     {
          return;
     }
     
     PrintTree(Tree->lChild);
     cout << Tree->data << "--";
     PrintTree(Tree->rChild);
}

void StoreNode(BinTree *Tree)
{
     if (NULL == Tree)
     {
              return;
     }
     
     StoreNode(Tree->lChild);
     array[num++] = Tree;
     StoreNode(Tree->rChild);
}

void ConverNode(BinTree* pNode, BinTree* &pLastNode)
{
     if (NULL == pNode)
     {
              return;
     }
     
     if (pNode->lChild != NULL)
     {
                       ConverNode(pNode->lChild, pLastNode);
     }
     
     pNode->lChild = pLastNode;
     if (NULL != pLastNode)
     {
              pLastNode->rChild = pNode;
     }
     pLastNode = pNode;
     
     if (pNode->rChild != NULL)
     {
                       ConverNode(pNode->rChild, pLastNode);
     }
}

void ReverseTree(BinTree *node)
{
     if (NULL == node)
     {
              return;
     }
     
     if (node->lChild != NULL)
     {
                      ReverseTree(node->lChild);
     }
     if (node->rChild != NULL)
     {
                      ReverseTree(node->rChild);
     }
     
     BinTree *temp = NULL;
     if (node->lChild != NULL || node->rChild != NULL)
     {
                      temp = node->lChild;
                      node->lChild = node->rChild;
                      node->rChild = temp;
     }
}

BinTree *ConverSolution(BinTree *head)
{
        BinTree *pLastNode = NULL;
        ConverNode(head, pLastNode);
        
        BinTree *pFirstList = pLastNode;
        while (pFirstList && pFirstList->lChild)
        {
              pFirstList = pFirstList->lChild;
        }
        
        return pFirstList;
}

BinTree *ConverSolution_3(BinTree* pNode, bool bIsRight)
{
        if (NULL == pNode)
        {
                 return NULL;
        }
        
        BinTree *pLeft = NULL;
        BinTree *pRight = NULL;
        
        if (pNode->lChild)
        {
                          pLeft = ConverSolution_3(pNode->lChild, false);
        }
        if (pLeft != NULL)
        {
                  pLeft->rChild = pNode;
                  pNode->lChild = pLeft;
        }
        
        if (pNode->rChild)
        {
                          pRight = ConverSolution_3(pNode->rChild, true);
        }
        if (pRight != NULL)
        {
                   pRight->lChild = pNode;
                   pNode->rChild = pRight;
        }
        
        BinTree *pTemp = pNode;
        if (bIsRight)
        {
                     while(pTemp->lChild)
                     {
                                         pTemp = pTemp->lChild;
                     }
        }
        else
        {
                     while(pTemp->rChild)
                     {
                                         pTemp = pTemp->rChild;
                     }
        }
        
        return pTemp;
}

int GetHeight(BinTree *node)
{
    if (node == NULL)
    {
             return 0;
    }
    
    int left = 0;
    int right = 0;
    
    if (node->lChild != NULL)
    {
                     left = GetHeight(node->lChild);
    }
    if (node->rChild != NULL)
    {
                     right = GetHeight(node->rChild);
    }
    
    return (left > right)?(left+1):(right+1);
}

void PrintList(BinTree *Tree)
{
     if (NULL == Tree)
     {
              return;
     }
     
     BinTree *tmp = Tree;
     while (tmp != NULL)
     {
           cout << tmp->data << "==";
           tmp = tmp->rChild;
     }
}

int main()
{
    int a[20];
    int input;
    int len = 0;
    
    cin >> input;
    while (input != 0)
    {
          a[len++] = input;
          cin >> input;
    }
    
    cout << "len=" << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << "--";
    }
    cout << endl;
    
    BinTree *head = NULL;
    head = CreateTree(a, len);
    PrintTree(head);
    cout << endl;
    
    //打印二叉树的高度 
    cout << "height of tree is " << GetHeight(head) << endl;
    
    //将二叉树转化为双链表 方案一 
    /*********
    StoreNode(head);
    int j = 0;
    for (j = 0; j < num; j++)
    {
        if (0 == j)
        {
              array[j]->rChild = array[j+1];
        }
        else if (num - 1 == j)
        {
              array[j]->lChild = array[j-1];
        }
        else
        {
              array[j]->rChild = array[j+1];
              array[j]->lChild = array[j-1];
        }
    }
    BinTree *root = array[0];
    PrintList(root);
    cout << endl;
    *******/
    
    //将二叉树转化为双链表 方案二
    /*******
    BinTree *ListHead = ConverSolution(head);
    PrintList(ListHead);
    cout << endl;
    *******/
    
    //将二叉树转化为双链表 方案三
    /*********
    BinTree *ListHead = ConverSolution_3(head, true);
    PrintList(ListHead);
    cout << endl;
    *******/
    
    //将二叉树转化为它的镜像
    ReverseTree(head);
    PrintTree(head);
    cout << endl;
    
    getchar();
    getchar();
    
    return 0;
}





