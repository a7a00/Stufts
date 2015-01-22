#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int MAX_SIZE = 25;
	int min = 0;
	ifstream in;
	in.open("../input.txt");					
	while (!in.eof())
	{
		char* array = new char[MAX_SIZE];
		for (int i = min; i <= MAX_SIZE; i++)
		{
			in >> array[i];
			//cout << hexarray[i];
		}
		for (int i = min; i <= MAX_SIZE; i++)
		{
			//hexa >> hexarray[i];
			cout << array[i];
		}
		min += MAX_SIZE;
		delete[] array;
	}
	in.close();
	return 0;
}
