#include "iostream"
using namespace std;

void PrintReverseStr(char *p)
{
     if ('\0' == *p)
     {
           return;
     }
     
     if (*(p + 1) != '\0')
     {
             PrintReverseStr(p+1);
     }
     
     cout << *p << " ";
}

int GetStrLenByStack(char *p)
{
    if ('\0' == *p)
        return 0;
    
    return 1 + GetStrLenByStack(p+1);
}

int main()
{
    char str[30];
    gets(str);
    
    cout << "strlen(str)=" << strlen(str) << endl;
    int len = GetStrLenByStack(str);
    cout << endl << "len=" << len << endl;
    
    PrintReverseStr(str);
    cout << endl;
    
    getchar();
    return 0;
}
