#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#define MAX 2000 + 10

using namespace std;

namespace MySort {
	clock_t start, finish;
	static int max;
	template<typename T>
	void swapA(T& rhs, T& lfh)
	{
		T temp;
		temp = rhs;
		rhs = lfh;
		lfh = temp;
	}
/*
 *  排序算法
 */
	//Bubble
	template<typename T>
	void BubbleSort1(vector<T> &a, int size = MAX)
	{
		int i,j;
		for(i=0; i<size; ++i)
			for(j=1; j<size-i; j++)
				if(a[j-1] > a[j])
					swapA(a[j-1], a[j]);
	}
	template<typename T>
	void BubbleSort2(vector<T> &a, int size = MAX)
	{
		int j,k;
		bool flag;

		k = size;
		flag = true;
		while( flag )
		{
			flag = false;
			for(j=1; j<k; j++)
				if(a[j-1] < a[j])
				{
					swapA(a[j-1], a[j]);
					flag = true;
				}
			k--;
		}
	}
	template<typename T>
	void BubbleSort3(vector<T> &a, int size = MAX)
	{
		int j,k;
		int flag;

		flag = size;
		while(flag > 0)
		{
			k = flag;
			flag = 0;
			for(j=1; j<k; j++)
				if(a[j-1] > a[j])
				{
					swap(a[j-1], a[j]);
					flag = j;
				}
		}
	}

	//Merge
	template<typename T>
  	void mergeArray(vector<T> &a,const int first, const int mid, const int last, vector<int> &temp)
  	{
  		int i = first, j = mid+1;
  		int m = mid, n = last;
  		int k = 0;
  		while(i<=m && j<=n)
  		{
  			if(a[i] < a[j])
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
  		}

  		while(i<=m)
			temp[k++] = a[i++];
		while(j<=n)
			temp[k++] = a[j++];
		for(i=0; i<k; i++)
			a[first+i] = temp[i];
  	}
	template<typename T>
  	void mergesort(vector<T> &a, int first, int last, vector<T> &temp)
  	{
  		if(first < last)
  		{
  			int mid = (first + last) / 2;
  			mergesort(a, first, mid, temp);
  			mergesort(a, mid+1, last, temp);
  			mergeArray(a, first, mid, last, temp);
  		}
  	}
	template<typename T>
	void MergeSort(vector<T> &a, int size = MAX)
	{
		vector<T> tempArray(size);
		mergesort(a, 0, size-1, tempArray);
  	}


/*
 *  初始化和处理的函数
 */
	//Create rand vector.
	template<typename T>
	void InitVec(vector<T> &a, int size = MAX)
	{
		srand((unsigned)time(NULL));
		while(size--)
			a.push_back(rand());
	}
	//Print result vector.
	template<typename T>
	void PrintVec(const vector<T>& a)
	{
		for(auto num: a)
			std::cout << num << " ";
		std::cout << std::endl;
	}
	//Init start time.
	void TimeInit()
	{
		start = clock();
	}
	//Print result time.
	void TimeCount()
	{
		finish = clock();
		cout << finish - start << "/" <<CLOCKS_PER_SEC << "(s)" << endl;
	}

/*
 *  分别测试以上几种排序的时间
 */
    void TestSort(string str)
    {
    	vector<int> ivec(max);
    	if(str == "B")
		{
			InitVec(ivec,MAX);
			TimeInit();
			BubbleSort1(ivec, max);
			TimeCount();
		}
		else if(str == "B1")
		{
			InitVec(ivec,MAX);
			TimeInit();
			BubbleSort2(ivec, max);
			TimeCount();
		}
		else if(str == "B2")
		{
			InitVec(ivec,MAX);
			TimeInit();
			BubbleSort3(ivec, max);
			TimeCount();
		}
		else if(str == "M")
		{
			InitVec(ivec,MAX);
			TimeInit();
			MergeSort(ivec, max);
			TimeCount();
		}
    }
}
int main()
{
	vector<int> ivec;
	string testType;

	cout << "|--------------------------------------------|\n";
	cout << "|                ZQQQ SORT                   |\n";
	cout << "| Method\t->\tSymbol               |\n";
	cout << "|--------------------------------------------|" << endl;
	cout << "| Bubble Sort\t->\t(B) or (B1) or (B2)  |\n";
	cout << "| Merge  Sort\t->\t(M)                  |\n";
	cout << "| Exit       \t->\t(e)                  |\n";
	cout << "|--------------------------------------------|\n";
	cout << "| Please input test type:(Symbol)\t     |\n";
	cout << "|--------------------------------------------|" << endl;
	cout << "| Default number size: (2000)\t             |\n";
	cout << "|--------------------------------------------|\n\n" << endl;
	while(cin >> testType)
	{
		if(testType == "e")
			break;
		cout << "---------------------------------\n Please input test number size:";
		cin >> MySort::max;
		MySort::TestSort(testType);
		cout <<"----------------------------------\n";
	}

	return 0;
}
