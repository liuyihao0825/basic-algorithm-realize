#include "iostream"
using namespace std;

bool VerifyPostTree(int a[], int len)
{
     if ((a == NULL) || (len <= 0))
     {
            return false;
     }
     
     int root = a[len - 1];
     
     //�����з�Ϊǰ�������֣�ǰ����С��root���󲿷ִ���root 
     int i = 0;
     for (; i < len-1; i++)
     {
         if (a[i] > root)
         {
                  break;
         }
     }
     
     //�жϺ󲿷��Ƿ���������������
     int j = i;
     for (; j < len-1; j++) 
     {
         if (a[j] < root)
         {
                  return false;
         }
     }
     
     //�ݹ������벿�֣����Ƿ�����������
     bool left = true;
     if (i > 0)
     {
           left = VerifyPostTree(a, i);
     }
     
     //�ݹ�����Ұ벿�֣����Ƿ�����������
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
