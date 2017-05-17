#include "iostream"
using namespace std;

void AdjustArray(int a[], int len)
{
     if (a == NULL || len <= 0)
     {
           return;
     }
     
     int pre = 0;
     int end = len - 1;
     int temp;
     
     while (pre < end)
     {
           while (pre < end && a[pre] %2 != 0)
           {
                 pre++;
           }
           while (pre < end && a[end] %2 == 0)
           {
                 end--;
           }
           
           temp = a[pre];
           a[pre] = a[end];
           a[end] = temp;
           
           pre++;
           end--;
     }
}

int main()
{
    int array[20];
    int len = 0;
    int input;
    
    cout << "input the array: ";
    cin >> input;
    while (input != 0)
    {
          array[len++] = input;
          cin >> input;
    }
    
    AdjustArray(array, len);
    cout << "After  Reversed: ";
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    getchar();
    getchar();
    return 0;
}
