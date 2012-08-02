#include <iostream>
#include <vector>
#include <algorithm>

namespace Exercises
{
	template<class T> void QSort(std::vector<T>& list, int start, int end)
	{
		using std::swap;

		if(start >= end) return;

		// For simplicity, use the middle element as the pivot
		int pivotIdx = start + (end - start) / 2;
		T pivot = list[pivotIdx];
		swap(list[pivotIdx], list[end]);

		int s = start;
		for(int i = start; i < end; i++)
		{
			if(list[i] < pivot)
			{
				swap(list[i], list[s]);
				s++;
			}
		}
		swap(list[s], list[end]);

		QSort(list, start, s-1);
		QSort(list, s+1, end);
	}

	// Implements qsort for a vector of items of type T.
	template<class T> void QSort(std::vector<T>& list)
	{
		QSort(list, 0, list.size()-1);
	}
}

int main()
{
	using namespace std;
	using namespace Exercises;

	vector<int> list;
	list.push_back(4);
	list.push_back(1);
	list.push_back(5);
	list.push_back(3);

	cout << "Before sort: " << endl;
	for(vector<int>::const_iterator i = list.begin(); i != list.end(); i++)
		cout << *i << endl;

	QSort(list);
	cout << "After sort: " << endl;
	for(vector<int>::const_iterator i = list.begin(); i != list.end(); i++)
		cout << *i << endl;

	return 0;
}