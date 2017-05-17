#include <stdio.h>
#include <stdlib.h>

#include <windows.h>


int main()

{
	int i=10000;
	int j=10000;
	int k;
	int len=100;
	
	for(;;)
	{
		Sleep(1000);

        for(k=0;k<len;k++)
			printf("\b");
		
		// 用printf("\b")就是相当于按一下backspace键，每一行打印完再加若干个printf("\b")

		printf("tr:   %d packet/s  "  ,i--);
				
		printf("tx:   %d packet/s  "  ,j++);

		fflush(stdout);
		
		
	}
	
	return 1;
}
