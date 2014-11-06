#include <iostream>

using namespace std;

int main()
{
	int arr[5];
	for(int i = 0; i < 5; i++) arr[i] = (i+1);;
	for(int i = 0; i < 5; i++) cout << arr[i] << "\n";
	cout << "-------";
	reverse(arr, 0, 4);
	for(int i = 0; i < 5; i++) cout << arr[i] << "\n";
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int* arr, int start, int end) //This is useful for rotations
{
        for(int i = ((start+end)/2) - 1; i >= 0; i--)
        {
                swap(arr[start+i], arr[end-i-1]);
        }
}

