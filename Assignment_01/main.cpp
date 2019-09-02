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
	if(A.size()==0) return; 

	if(low < high)
	{
		int p = partition(A, low, high);
		quickSort(A, low, p-1);
		quickSort(A, p+1, high);
	}
}

TEST_CASE("Tests")
{
    vector<int> data_0{2,6,3,4,9,1};
    vector<int> data_1;
    vector<int> data_2{-1,6,-5,11,-72};
    vector<int> data_3{5,4,3,2,1,0,-1,-2,-3,-4,-5};
    vector<int> data_4{-5,-4,-3,-2,-1,0,1,2,3,4,5};
    {
    	INFO("Positive Integers");
    	quickSort(data_0, 0, data_0.size()-1);
    	REQUIRE(is_sorted(data_0.begin(), data_0.end()));
    }
    {
    	INFO("Empty vector");
    	quickSort(data_1, 0, 0);
    	REQUIRE(is_sorted(data_1.begin(), data_1.end()));
    }
    {
    	INFO("Positive and negative integers");
    	quickSort(data_2, 0, data_2.size()-1);
    	REQUIRE(is_sorted(data_2.begin(), data_2.end()));
    }
    {
    	INFO("Reverse order");
    	quickSort(data_3, 0, data_3.size()-1);
    	REQUIRE(is_sorted(data_3.begin(), data_3.end()));
    }
    {
    	INFO("In order");
    	quickSort(data_4, 0, data_4.size()-1);
    	REQUIRE(is_sorted(data_4.begin(), data_4.end()));
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