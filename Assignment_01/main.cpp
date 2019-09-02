//Created by Bradley Morton for CS471 on 9/1/2019


#include <vector>
using std::vector;
#include <algorithm>
using std::swap;
using std::is_sorted;
#include <iostream>
using std::cout;
using std::endl;

#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "test.cpp"


//This is the algorithm to partition 
int partition(vector<int>& A, int low, int high)
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


void quickSort(vector<int> & A, int low, int high)
{
	if(low < high)
	{
		int p = partition(A, low, high);
		quickSort(A, low, p-1);
		quickSort(A, p+1, high);
	}
}





//Main is where the tests will be run; much of this has been taken from a 311 homework. 
int main(int argc, char *argv[])
{
	Catch::Session session;
	int catchResult;

	catchResult = session.applyCommandLine(argc, argv);

	if(!catchResult)
	{
		cout <<"Beginning quicksort testing" <<endl<<endl;
		catchResult = session.run();
		cout<<"Tests ended"<<endl<<endl;
	}



	return 0;
}