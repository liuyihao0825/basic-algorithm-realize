#include "iostream"
using namespace std;

int main()
{
    int max = -9999;
    int max_2 = 0;
    int pre = 0;
    int end = 0;
    int i,j,k;
    int a[20];
    int input;
    int len = 0;
    int sum = 0;
    
    cout << "input the array(end of 0):";
    cin >> input;
    while (input != 0)
    {
          a[len++] = input;
          cin >> input;
    }
    
    //solution_1，穷举，O(n3) 
    /**********
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            sum = 0;
            for (k = i; k <= j; k++)
            {
                sum += a[k];
                if (sum > max)
                {
                        max = sum;
                        pre = i;
                        end = j;
                }
            }
        }
    }
    cout << endl;
    cout << "max=" << max << " pre=" << pre << " end=" << end;
    **********/
    
    //solution_2，时间复杂度为 o(n) 
    for (i = 0; i < len; i++)
    {
        sum += a[i];
        
        if (sum < 0)
        {
                sum = 0;
        }
        
        if (sum > max_2)
        {
                max_2 = sum;
        }
    }
    
    //特殊情况下，数组全为负数，此时取数组的最大值
    if (max_2 == 0)
    {
           max_2 = a[0]; 
           for (i = 1; i < len; i++)
           {
               if (a[i] > max_2)
               {
                        max_2 = a[i];
               }
           }
    }
    
    cout << endl << "max=" << max_2;
    
    getchar();
    getchar();
    
    return 0;
}
