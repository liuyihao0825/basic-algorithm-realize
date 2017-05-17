#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec_int;
    
    for (int i = 1; i <= 5; i++)
    {
        vec_int.push_back(i);
    }
    
    vector<int>::iterator ite;
    
    for (ite = vec_int.begin(); ite != vec_int.end(); ite++)
    {
        cout << *ite << " ";
    }
    
    vec_int.pop_back();
    
    cout << endl;
    for (ite = vec_int.begin(); ite != vec_int.end(); ite++)
    {
        cout << *ite << " ";
    }
    
    char str[] = "abcdefg";
    cout << endl << sizeof(str) << endl;
    
    getchar();
    return 0;
}
