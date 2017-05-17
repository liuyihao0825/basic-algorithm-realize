#include "iostream"
using namespace std;

bool FindTwoNum(int a[], int len, int EqualNum, int &num1, int &num2)
{
     int sum;
     bool found = false;
     int i = 0;
     int j = len-1;
     
     while (i < j)
     {
           sum = a[i] + a[j];
           
           if (sum == EqualNum)
           {
                   num1 = a[i];
                   num2 = a[j];
                   found = true;
                   break;
           }
           else if (sum > EqualNum)
           {
                   j--;
           }
           else
           {
                   i++;
           }
     }
     
     return found;
}

int main()
{
    int array[30];
    int input;
    int len = 0;
    int equalNum;
    bool found;
    int num1 = 0;
    int num2 = 0;
    
    cin >> input;
    while (input != 0)
    {
          array[len++] = input;
          cin >> input;
    }
    cout << "len=" << len << endl;
    cout << "input the equal num:";
    cin >> equalNum;
    
    found = FindTwoNum(array, len, equalNum, num1, num2);
    if (found == true)
    {
              cout << num1 << " + " << num2 << " = " << equalNum << endl;
    }
    else
    {
              cout << "Not Found!" << endl; 
    }
    
    getchar();
    getchar();
    return 0;
}
