//Created by Bradley Morton for CS471 on 9/1/2019


#include <vector>
using std::vector;
#include <algorithm>
using std::swap;


int partition(vector<int> A, int low, int high)
{
	int pivot= A[high];
	int i = low;
	int j =low;
	for(j; j<= high-1; ++j)
	{
		if(A[j]<pivot)
		{
			swap(A[i], A[j]);
			++i;
		}
	}
	swap(A[j], A[i]);
	return i;
}


void quicksort(vector<int> A, int low, int high)
{
	if(low < high)
	{
		int p = partition(A, low, high);
		quicksort(A, low, p-1);
		quicksort(A, p+1, high);
	}
}






int main()
{
	return 0;
}