#include "ImPureF.h"
template<typename T>
void printArray(const T* arr, const unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << *(arr + i) << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
void printMatrix(T** m, const unsigned int rows, const unsigned int cols)
{
	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int j = 0; j < cols; ++j)
		{
			std::cout << m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void task1()
{
	int size = 0;
	std::cout << "enter array size:";
	std::cin >> size;
	if (size <= 0)
	{
		std::cout << "cannot create array of such size!\n";
		return;
	}
	int* arr = new int[size];
	std::cout << "\nenter sequence of integers:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	if (isSortedAsc(arr, size)) std::cout << "this sequence is ordered!\n";
	else std::cout << "this sequence is NOT ordered!\n";
	delete[] arr;
}
void task2()
{
	int size = 0;
	std::cout << "enter array size:";
	std::cin >> size;
	if (size <= 0)
	{
		std::cout << "cannot create array of such size!\n";
		return;
	}
	double* arr = new double[size];
	std::cout << "\nenter sequence of integers:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	insertionSort(arr, size);
	printArray(arr, size);
	delete[] arr;
}
void task3()
{
	int size = 0;
	std::cout << "enter array size:";
	std::cin >> size;
	if (size <= 0)
	{
		std::cout << "cannot create array of such size!\n";
		return;
	}
	double* arr = new double[size];
	std::cout << "\nenter sequence of numbers:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	if (!isSortedAsc(arr, size)) {
		qSort(arr, 0, size - 1);
		std::cout << "array was sorted!\n";
		printArray(arr, size);
	}
	double toFind = 0;
	std::cout << "enter a number to find (if it's not in the sequence, find closest)\n";
	std::cin >> toFind;
	const unsigned int ind = binarySearch(arr, 0, size-1, toFind);
	std::cout << "found closest number at " << ind << ": " << arr[ind] <<'\n';
	delete[] arr;
}
void task4()
{
	const int SIZE = 256;
	char* str = new char[SIZE];
	std::cout << "enter a string (size <= 256)\n";
	std::cin.ignore();
	std::cin.getline(str, SIZE);
	if (isValidName(str))
		std::cout << "Name can be used in a c++ variable\n";
	else
		std::cout << "Name can't be used in a c++ variable\n";
	std::cout << isValidName("");
	delete[] str;
}
void task5()
{
	const unsigned int SIZE = 256;
	char* str = new char[SIZE];
	std::cout << "enter a string (size <= 256)\n";
	std::cin.ignore(1, '\n');
	std::cin.getline(str, SIZE);
	char* newStr = new char[SIZE];
	char toRemove;
	std::cout << "enter a symbol to remove from string: ";
	std::cin >> toRemove;
	removeChar(str, toRemove, newStr);
	std::cout << "new string:\n" << newStr << '\n';
	delete[] str;
	delete[] newStr;
}
void task6()
{
	int size = 0;
	std::cout << "enter array size:";
	std::cin >> size;
	if (size <= 0)
	{
		std::cout << "cannot create array of such size!\n";
		return;
	}
	double* arr = new double[size];
	std::cout << "\nenter sequence of numbers:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	qSort<double>(arr, 0, size-1);
	printArray(arr, size);
	delete[] arr;
}
void task7()
{
	int r1 = 0,
		c1 = 0,
		r2 = 0,
		c2 = 0;
	int mode = 1;
	std::cout << "enter rows and columns for the first matrix:\n";
	std::cin >> r1 >> c1;
	if (r1 < 1 || c1 < 1)
	{
		std::cout << "incorrect size! defaulting to 3x3\n";
		r1 = 3;
		c1 = 3;
	}
	double** mat1 = new double* [r1];
	for (int i = 0; i< r1; ++i)
	{
		mat1[i] = new double[c1];
	}
	std::cout << "enter 0 to randomize matrix, anything else to manually input\n";
	std::cin >> mode;
	if (mode) {
		std::cout << "enter values for " << r1 << 'x' << c1 << " matrix (" << r1 * c1 << " in total)\n";
		for (int i = 0; i < r1; ++i)
		{
			for (int j = 0; j < c1; ++j)
			{
				std::cin >> mat1[i][j];
			}
		}
	}
	else
	{
		randomizeMatrix(mat1, r1, c1);
		printMatrix(mat1, r1, c1);
	}
	std::cout << "enter rows and columns for the second matrix:\n";
	std::cin >> r2 >> c2;
	if (r2 < 1 || c2 < 1)
	{
		std::cout << "incorrect size! defaulting to 3x3\n";
		r2 = 3;
		c2 = 3;
	}
	double** mat2 = new double* [r2];
	for (int i = 0; i < r2; ++i)
	{
		mat2[i] = new double[c2];
	}
	std::cout << "enter 0 to randomize matrix, anything else to manually input\n";
	std::cin >> mode;
	if (mode) {
		std::cout << "enter values for " << r2 << 'x' << c2 << " matrix (" << r2 * c2 << " in total)\n";
		for (int i = 0; i < r2; ++i)
		{
			for (int j = 0; j < c2; ++j)
			{
				std::cin >> mat2[i][j];
			}
		}
	}
	else
	{
		randomizeMatrix(mat2, r2, c2);
		printMatrix(mat2, r2, c2);
	}
	if (c1 == r2)
	{
		double** newMat = multiplyMatrices(mat1, r1, c1, mat2, r2, c2);
		printMatrix(newMat, r1, c2);
		for (int i = 0; i < r1; ++i)
		{
			delete[] newMat[i];
		}
		delete[] newMat;
	}
	else
		std::cout << "cannot multiply matrices! wrong sizes!\n";
	for (int i = 0; i < r1; ++i)
	{
		delete[] mat1[i];
	}
	delete[] mat1;
	for (int i = 0; i < r2; ++i)
	{
		delete[] mat2[i];
	}
	delete[] mat2;
}