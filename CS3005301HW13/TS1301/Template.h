#pragma once
#include <iostream>
#include <string>

using namespace std;


template <class N>
void ItrBinarySearch(const N* a, int begin, int end, N key, bool& found, int& location)   //Binary Search
{
	found = false;
	while (end >= begin)
	{
		int mid = (begin + end) / 2;
		if (a[mid] == key)
		{
			found = true;
			location = mid;
			break;
		}
		else if (a[mid] < key)begin = mid + 1;
		else end = mid - 1;
	}
}

template <class N>
void RecBinarySearch(const N* a, int begin, int end, N key, bool& found, int& location)   //Recursive Search
{
	found = false;
	if (begin > end)
	{
		found = false;
		return 0;
	}
	int mid = (begin + end) / 2;
	if (a[mid] == key)
	{
		found = true;
		location = mid;
		return 1;
	}
	else if (a[mid] > key)
	{
		return RecBinarySearch(a, begin, mid - 1, key, found, location);
	}
	else
		return RecBinarySearch(a, mid + 1, end, key, found, location);
}

