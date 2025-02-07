#include <iostream>
using namespace std;

int main() {
	
    int n;
    cout << "take the number of integers you want to enter: ";
    cin >> n;
    
    
    int *ptr = new int[n];
    for (int i= 0; i<n; i++)
    {
        cout << "take number " << i + 1 << ": ";
        cin >> *(ptr + i);
    }
    cout << "take the array of integers:" << endl;
    for (int i=0; i<n; i++)
    {
        cout << *(ptr + i) << " ";
    }
    int sum=0;
    for (int i=0; i<n; i++)
    {
        sum = sum + *(ptr + i);
    }
    cout << "the sum of entered array of integers si:" << sum << endl;
    delete[] ptr;
    return 0;
                     }