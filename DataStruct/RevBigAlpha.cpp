#include "iostream"
using namespace std;

bool bIsBigAlpha(char c)
{
     if ((c >= 'A') && (c <= 'Z'))
     {
            return true;
     }
     else
     {
            return false;
     }
}

int main()
{
    char str[30];
    gets(str);
    int len = strlen(str);
    int i,j,k;
    int temp;
    k = 0;
    
    for (i = 0; i < len; i++)
    {
        if (false == bIsBigAlpha(str[k]))
        {
                  k++;
        }
        else
        {
                  temp = str[k];
                  for (j = k; j < len - 1; j++)
                  {
                      str[j] = str[j + 1];
                  }
                  str[len - 1] = temp;
        }
    }
    
    cout << "after modify:";
    cout << str;
    
    getchar();
    getchar();
    return 0;
}
