/*****************************************************************
Question:
Reverse digits of an integer.

Case:
Example1: x = 123, return 321
Example2: x = -123, return -321
*****************************************************************/

class Solution 
{
public:
    bool bIsOverFlow(char str[], int len)
    {
        if (len < 10)
        {
            return false;
        }

        char max[] = "2147483647";

        if (strcmp(str, max) > 0)
        {
            return true;
        }

        return false;
    }

    int reverse(int x) 
    {
        if (x == 0)
        {
            return 0;
        }

        bool bIsNegative = (x > 0) ? false : true;

        if (bIsNegative)
        {
            x = x * (-1);
        }

        char str[20];
        int len = 0;
        while (x > 0)
        {
            str[len++] = x % 10 + '0';
            x = x / 10;
        }
        str[len] = '\0';

        int i = 0;
        while (i < len && str[i] == '0')
        {
            i++;
        }

        int j;
        if (i > 0)
        {
            for (j = 0; j < len - i; j++)
            {
                str[j] = str[j + i];
            }
            str[j] = '\0';
        }
        else
        {
            j = len;
        }

        if (bIsOverFlow(str, j))
        {
            return 0;
        }

        int result = 0;
        for (int k = 0; k < j; k++)
        {
            result = result * 10 + str[k] - '0';
        }

        if (bIsNegative)
        {
            result = result * (-1);
        }

        return result;
    }
};