#include "iostream"
using namespace std;

void swap(char *a, char *b)
{
     char temp;
     temp = *a;
     *a = *b;
     *b = temp;
}

void PrintAllStr(char *str, char *begin)
{
     if (str == NULL || begin == NULL)
     {
             return;
     }
     
     if (*begin == '\0')
     {
                puts(str);
     }
     
     char *pc;
     for (pc = begin; *pc != '\0'; pc++)
     {
         swap(begin, pc);
         PrintAllStr(str, begin+1);
         swap(begin, pc);
     }
}

int main()
{
    char str[30];
    cout << "input the string: ";
    gets(str);
    
    PrintAllStr(str, str);
    
    getchar();
    getchar();
    return 0;
}
