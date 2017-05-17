#include "iostream"
using namespace std;

int main()
{
    char str[30];
    gets(str);
    int len = strlen(str);
    cout << "len=" << len << endl;
    
    int i,k;
    bool bIsFirstSpace = true;
    
    i = 0;
    k = 0;
    
    while (i < len)
    {
          if (str[i] != ' ')
          {
                     bIsFirstSpace = true;
                     str[i - k] = str[i];
          }
          else
          {
              if (bIsFirstSpace == false)
              {
                                k++;
              }
              else
              {
                                bIsFirstSpace = false;
                                str[i - k] = str[i];        
              }
          }
          i++;
    }
    str[i - k] = '\0';
    
    cout << "after modify:" << str << endl;
    
    getchar();
    return 0;
}
