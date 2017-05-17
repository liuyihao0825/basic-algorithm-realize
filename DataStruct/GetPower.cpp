#include "iostream"
using namespace std;

int getPower(int x)
{
    int i;
    int result = 1;
    for (i = 0; i < x; i++)
    {
        result = result * 2;
    }
    return result;
}

int main()
{
    int i,j,k,n;
    int m;
    int temp,step;
    m = 16;
    n = 4;
    cin >> n;
    cout << "n=" << n << endl;
    m = getPower(n);
    int array[m][n];
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            array[i][j] = 0; 
        }
    }
    
    for (k = 1; k < m; k++)
    {
        temp = k;
        step = 0;
        while (temp > 0)
        {
              if ((temp % 2) == 1)
              {
                     array[k][n - step -1] = 1;
              }
              temp = temp / 2;
              step++;
        }
    }
    
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << array[i][j];
        }
        cout << "\n";
    }
    getchar();
    getchar();
    return 0;
}
