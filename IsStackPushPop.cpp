#include "iostream"
#include "stack"
using namespace std;

bool IsStackPushPop(int *push, int *pop, int len)
{
     if (push == NULL || pop == NULL || len <= 0)
     {
              return false;
     }
     
     bool bIsRight = false;
     int *nextPush = push;
     int *nextPop = pop;
     stack<int> Stack;
     
     while (nextPop - pop < len)
     {
           if (Stack.size() == 0 || Stack.top() != *nextPop)
           {
                            while (nextPush - push < len)
                            {
                                  Stack.push(*nextPush);
                                  
                                  if (*nextPush == *nextPop)
                                  {
                                                nextPush++;
                                                break;
                                  }
                                  
                                  nextPush++;
                            }
           }
           
           if (Stack.top() != *nextPop)
           {
                           break;
           }
           
           Stack.pop();
           nextPop++;
     }
     
     if (Stack.size() == 0 &&
         nextPop - pop == len)
     {
         bIsRight = true;
     }
         
     return bIsRight;    
}

int main()
{
    int push[20];
    int pop[20];
    int input_1;
    int input_2;
    int len = 0;
    int i;
    
    cout << "input the push array: ";
    cin >> input_1;
    while (input_1 != 0)
    {
          push[len++] = input_1;
          cin >> input_1;
    }
    cout << "len=" << len << endl;
    
    cout << "input the pop  array: ";
    for (i = 0; i < len; i++)
    {
        cin >> input_2;
        pop[i] = input_2;
    }
    for (i = 0; i < len; i++)
    {
        cout << pop[i] << " ";
    }
    cout << endl;
    
    bool bIsRight = IsStackPushPop(push, pop, len);
    if (bIsRight == true)
    {
                 cout << "It meets the push & pop sequence" << endl;
    }
    else
    {
                 cout << "It doesn't matter!" << endl;
    }
    
    getchar();
    getchar();
    return 0;
}
