#include "iostream"
using namespace std;

int GetSum(int a, int b)
{
    if (a >= b)
    {
          return 0;
    }
    
    return (a+b)*(b-a+1)/2;
    
}

void FindSequence(int n)
{
     if (n < 2)
     {
           return;
     }
     
     int small = 1;
     int big = 2;
     int i;
     
     while (small < (n+1)/2 && small < big)
     {
           if (GetSum(small, big) > n)
           {
                             small++;
           }
           else if (GetSum(small, big) < n)
           {
                             big++;
           }
           else
           {
                             cout << n << "=";
                             for (i = small; i <= big; i++)
                             {
                                 cout << i << "+";
                             }
                             cout << endl;
                             small++;
           }
     }
}

int main()
{
    int n;
    cout << "input n (n>2): ";
    cin >> n;
    FindSequence(n);
    
    getchar();
    getchar();
    return 0;
}
