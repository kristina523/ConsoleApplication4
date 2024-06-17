#include <iostream>
#include <vector>
#include <thread>
#include <wtypes.h>

using namespace std;

class MergeSort {
public:
	void Sort(vector<int>& arr)
	{
		if (arr.size() <= 1)
			return;

		int mid = arr.size() / 2;
		vector<int> left(arr.begin(), arr.begin() + mid);
		vector<int> right(arr.begin() + mid, arr.end());

		Sort(left);
		Sort(right);

		Merge(arr, left, right);
	}

private:
	void Merge(vector<int>& arr, vector<int>& left, vector<int>& right)
	{
		int i = 0, j = 0, k = 0;
		int n1 = left.size();
		int n2 = right.size();

		while (i < n1 && j < n2)
		{
			if (left[i] <= right[j])
			{
				arr[k] = left[i];
				i++;
			}
			else
			{
				arr[k] = right[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = left[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = right[j];
			j++;
			k++;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<int> arr(10);

	cout << "Введите 10 чисел для заполнения массива: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	MergeSort mergeSort;

	thread sortingThread([&]()
		{
			mergeSort.Sort(arr);
		});

	sortingThread.join();

	cout << "Отсортированный массив: ";
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}