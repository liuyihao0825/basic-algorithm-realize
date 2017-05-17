#include "iostream"
using namespace std;

bool VerifyPostTree(int a[], int len)
{
     if ((a == NULL) || (len <= 0))
     {
            return false;
     }
     
     int root = a[len - 1];
     
     //将序列分为前后两部分，前部分小于root，后部分大于root 
     int i = 0;
     for (; i < len-1; i++)
     {
         if (a[i] > root)
         {
                  break;
         }
     }
     
     //判断后部分是否满足后序遍历条件
     int j = i;
     for (; j < len-1; j++) 
     {
         if (a[j] < root)
         {
                  return false;
         }
     }
     
     //递归遍历左半部分，看是否满足后序遍历
     bool left = true;
     if (i > 0)
     {
           left = VerifyPostTree(a, i);
     }
     
     //递归遍历右半部分，看是否满足后序遍历
     bool right = true;
     if (i < len - 1)
     {
           right = VerifyPostTree(a+i, len-i-1);
     }
     
     return (left && right);
}

int main()
{
    int array[20];
    int input;
    int len = 0;
    
    cin >> input;
    while (input != 0)
    {
          array[len++] = input;
          cin >> input;
    }
    
    bool bIsPostTree = VerifyPostTree(array, len);
    if (true == bIsPostTree)
    {
             cout << "The array is a PostTree" << endl;
    }
    else
    {
             cout << "The array is not a PostTree" << endl;
    }
    
    getchar();
    getchar();
    return 0;
}
