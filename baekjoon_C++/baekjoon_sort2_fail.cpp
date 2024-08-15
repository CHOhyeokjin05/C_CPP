#include <iostream>
using namespace std;
int main()
{
    int *arr = (int*)malloc(sizeof(int) * 5);
    int sum = 0;
    for(int i=0; i<5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum / 5 << endl;
    
}