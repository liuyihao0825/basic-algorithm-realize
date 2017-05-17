#include "iostream"
#include "vector"
#include "iterator"
using namespace std;

typedef struct BinSearchTree
{
        struct BinSearchTree *lChild;
        struct BinSearchTree *rChild;
        int data;
}BinTree;

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

void FindPath(BinTree *node, vector<int> &Path, int number, int &sum)
{
     if (NULL == node)
     {
              return;
     }
     
     sum += node->data;
     Path.push_back(node->data);
     
     vector<int>::iterator ite;
     
     if (node->lChild == NULL && node->rChild == NULL)
     {
                      if (sum == number)
                      {
                              cout << "There exist one path!" << endl;
                              for (ite = Path.begin(); ite != Path.end(); ite++)
                              {
                                  cout << *ite << " ";
                              }
                              cout << endl;
                      }
     }
     if (node->lChild != NULL)
     {
                      FindPath(node->lChild, Path, number, sum);
     }
     if (node->rChild != NULL)
     {
                      FindPath(node->rChild, Path, number, sum);
     }
     
     sum -= node->data;
     Path.pop_back();
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
    
    int number;
    int sum = 0;
    vector<int> Path;
    cout << "input the found num:";
    cin >> number;
    FindPath(head, Path, number, sum);
    
    getchar();
    getchar();
    
    return 0;
}
