#include "iostream"
using namespace std;

void ReverseStr(char str[], int m, int n)
{
     if ((str == NULL) || (m >= n))
     {
              return;
     }
     
     int i = m;
     int j = n;
     char temp;
     while (i < j)
     {
           temp = str[i];
           str[i] = str[j];
           str[j] = temp;
           i++;
           j--;
     }
}

void ReverseWord(char str[], int len)
{
     if ((str == NULL) || (len <= 0))
     {
              return;
     }
     
     int pre;
     int end;
     bool bIsSpace = true;
     int i = 0;
     
     while (i < len)
     {
           if (str[i] != ' ')
           {
                      if (bIsSpace == true)
                      {
                                   pre = i;
                      }
                      bIsSpace = false;
           }
           else
           {
                      if (bIsSpace == false)
                      {
                                   end = i-1;
                                   ReverseStr(str, pre, end);
                      }
                      bIsSpace = true;
           }
           
           i++;
     }
}

int main()
{
    char str[30];
    gets(str);
    int len = strlen(str);
    cout << "len=" << len << endl;
    
    cout << "Reverst all the string :";
    ReverseStr(str, 0, len-1);
    puts(str);
    
    cout << "After reversed it come :";
    ReverseWord(str, len);
    puts(str);
    
    getchar();
    getchar();
    return 0;
}
