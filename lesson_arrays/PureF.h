#pragma once
#include <cctype>
#include <ctime>
#include <cstdlib>
//non-template functions
bool isValidName(const char* str);
void removeChar(const char* oldStr, const char toRemove, char* newStr);
//template functions
template <typename T>
bool isSortedAsc(const T* arr, const unsigned int size);
template<typename T>
void insertionSort(T* arr, const unsigned int size);
template<typename T>
void swap(T* one, T* two);
template<typename T>
void qSort(T* arr, unsigned int low, unsigned int high);
template<typename T>
unsigned int binarySearch(const T* arr, const unsigned int size, const T toFind);
template <typename T>
void randomizeMatrix(T** m, const unsigned int rows, const unsigned int cols);
template <typename T>
T** multiplyMatrices(T** m1, const unsigned int r1, const unsigned int c1, T** m2, const unsigned int r2, const unsigned int c2);
template<typename T>
unsigned int binarySearch(const T* arr, unsigned int left, unsigned int right, const T toFind);
//instantiations of template functions
template
bool isSortedAsc(const int* arr, const unsigned int size);
template
bool isSortedAsc(const double* arr, const unsigned int size);
template
void insertionSort(double* arr, const unsigned int size);
template
void insertionSort(double* arr, const unsigned int size);
template
void swap(double* one, double* two);
template
void qSort(double* arr, unsigned int low, unsigned int high);
template
unsigned int binarySearch(const double* arr, const unsigned int size, const double toFind);
template
void randomizeMatrix(double** m, const unsigned int rows, const unsigned int cols);
template
double** multiplyMatrices(double **m1, const unsigned int r1, const unsigned int c1, double** m2, const unsigned int r2, const unsigned int c2);
template
unsigned int binarySearch(const double* arr, unsigned int left, unsigned int right, const double toFind);