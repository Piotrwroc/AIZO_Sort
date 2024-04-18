#ifndef SORTING_H
#define SORTING_H

template <typename T>
class Sorting
{
public:
	void sorting_menu(T tab[], int size);
	double f_sorting(T* tab, int size, int wybor_algorytmu);
	void s_InsertionSort(T tab[], int size);
	void heapify(T tab[], int size, int i);
	void s_HeapSort(T tab[], int size);
	void s_ShellSort(T tab[], int size, int mode);
	int partition(T tab[], int low, int high, char pivotType);
	void s_QuickSort(T tab[], int low, int high, char pivotType);
	
};

#endif SORTING_H