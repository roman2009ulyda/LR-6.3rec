#include <iostream>
#include <iomanip> 
#include <time.h> 
#include <cmath>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(3) << a[i] << ",";
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
void Max(int* a, const int size, int& max, int& imax, int j)
{
	if (max < a[j])
	{
		max = a[j];
		imax = j;
	}

	if (j < size - 1)
		Max(a, size, max, imax, j + 1);
}
void Sort(int* a, const int size, int i)
{
	int max = a[i];
	int imax = i;

	Max(a, size, max, imax, i + 1);

	a[imax] = a[i];
	a[i] = max;

	if (i < size - 2)
		Sort(a, size, i + 1);
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 20;
	int a[n];
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	Sort(a, n, 0);
	Print(a, n, 0);
	return 0;
}