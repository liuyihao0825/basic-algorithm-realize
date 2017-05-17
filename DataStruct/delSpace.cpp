#include "iostream"
#include "string"
using namespace std;

int main()
{
    char str[20];
    gets(str);
    
    int i,k,j;
    i = 0;
    k = 0;
    j = 0;
    
    int len = strlen(str);
    cout << "len=" << len << endl;
    
    while (j < len)
    {
          if (str[j] != ' ')
          {
              str[j - k] = str[j];
          }
          else
          {
              k++;
          }
          j++;
    }
    str[j - k] = '\0';
    
    cout << "after modify:";
    cout << str;
}
