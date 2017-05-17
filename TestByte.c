#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[4] = {0};
    int y[4] = {1};
    int i;
    
    for (i = 0; i < 4; i++)
    {
        printf("%d %d", x[i], y[i]);
    }
    
    getchar();
    return 0;
}
