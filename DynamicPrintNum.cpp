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
		
		// ��printf("\b")�����൱�ڰ�һ��backspace����ÿһ�д�ӡ���ټ����ɸ�printf("\b")

		printf("tr:   %d packet/s  "  ,i--);
				
		printf("tx:   %d packet/s  "  ,j++);

		fflush(stdout);
		
		
	}
	
	return 1;
}
