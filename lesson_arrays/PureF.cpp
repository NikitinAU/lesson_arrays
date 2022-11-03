#include "PureF.h"
//non-template functions
bool isValidName(const char* str)
{
	if (*str != '_' && !std::isalpha(*str))
		return false;
	++str;
	while (*str)
	{
		if (!std::isalnum(*str) && *str != '_')
			return false;
		++str;
	}
	return true;
}
void removeChar(const char* oldStr, const char toRemove, char* newStr)
{
	while(*oldStr)
	{
		if (*oldStr != toRemove) {
			*newStr = *oldStr;
			++newStr;
		}
		++oldStr;
	}
	*newStr = '\0';
}
//template functions
template <typename T>
bool isSortedAsc(const T* arr, const unsigned int size)
{
	for (unsigned int i = 1; i < size; ++i)
	{
		if (*(arr + i) < *(arr + i - 1)) return false;
	}
	return true;
}
template<typename T>
void insertionSort(T* arr, const unsigned int size)
{
	for (unsigned int j = 1; j < size; ++j)
	{
		T key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}
}
template<typename T>
void swap(T* one, T* two)
{
	T tmp = *one;
	*one = *two;
	*two = tmp;
}
template<typename T>
void qSort(T* arr, unsigned int low, unsigned int high)
{
	if ((high - low < 2) && low <= high)
	{
		if (arr[low] > arr[high])
			swap(arr + low, arr + high);
	}
	else {
		T pivot = arr[(low + high) / 2];
		//filter array
		unsigned int i = low,
					 j = high;
		while (i <= j)
		{
			while (arr[i] < pivot)
				++i;
			while (arr[j] > pivot)
				--j;
			if (i >= j)
				break;
			swap(arr + i++, arr + j--);
		}
		//call on 2 parts
		qSort(arr, low, j);
		qSort(arr, j+1, high);
	}
}
template<typename T>
unsigned int binarySearch(const T* arr, const unsigned int size, const T toFind)
{
	unsigned int left = 0,
				 right = size-1,
				 i = right / 2;
	do
	{
		if (arr[i] == toFind)
			return i;
		else if (arr[i] < toFind)
			left = i;
		else
			right = i;
		i = (right + left) / 2;
	} while (left < right && i!=left && i!=right);
	if (arr[i] < toFind)
		++i;
	if (i != 1)
	return i;
}
//TODO
template<typename T>
unsigned int binarySearch(const T* arr, unsigned int left, unsigned int right, const T toFind)
{
	unsigned int i = (right + left) / 2;
	if (arr[i] == toFind)
		return i;
	else if (arr[i] < toFind)
		left = i;
	else
		right = i;
	if (left < right && right!=left)
		binarySearch(arr, left, right, toFind);
	return i;
}
template <typename T>
void randomizeMatrix(T** m, const unsigned int rows, const unsigned int cols)
{
	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int j = 0; j < cols; ++j)
		{
			m[i][j] = std::rand() % 50;
		}
	}
}
//TODO
//Delete r2
//Make throw call
template <typename T>
T** multiplyMatrices(T** m1, const unsigned int r1, const unsigned int c1, T** m2, const unsigned int r2, const unsigned int c2)
{
	T** matrix = new T* [r1];
	for (int i = 0; i < r1; ++i)
	{
		matrix[i] = new T[c2];
	}
	for (unsigned int i = 0; i< r1; ++i)
	{
		for (unsigned int j = 0; j< c2; ++j)
		{
			T sum = 0;
			for(unsigned int k = 0; k< c1; ++k)
			{
				sum += m1[i][k] * m2[k][j];
			}
			matrix[i][j] = sum;
		}
	}
	return matrix;
}