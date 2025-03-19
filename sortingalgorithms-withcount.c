#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/






void insertionSort(Record* arr, int n, long long *count) 
{
    Record temp; (*count)++;
    
    for (int i = 1; i < n; i++)
	{
		(*count)++; 	
        temp = arr[i]; (*count)++;
        int j = i - 1; (*count)++;
        
        while (j >= 0 && arr[j].idNumber > temp.idNumber)
		{
			(*count)++;
            arr[j + 1] = arr[j]; (*count)++;
            j--; (*count)++;												
        }
        
        arr[j + 1] = temp; (*count)++;										
    }
}																	

void selectionSort(Record* arr, int n, long long *count)
{
    Record temp; (*count)++;
    
    for (int i = 0; i < n - 1; i++)
	{
		(*count)++;
        int minIndex = i; (*count)++;
        
        for (int j = i + 1; j < n; j++)
		{
			(*count)++;
            if (arr[j].idNumber < arr[minIndex].idNumber)
			{
				(*count)++;
                minIndex = j; (*count)++;
            }
        }
        
        if (minIndex != i)
		{
			(*count)++;
            temp = arr[i]; (*count)++;
            arr[i] = arr[minIndex]; (*count)++;
            arr[minIndex] = temp; (*count)++;
        }
    }
}

void merge(Record* arr, int left, int mid, int right, int *count) 
{
    int i, j, k; (*count)++;
    int n1 = mid - left + 1; (*count)++;
    int n2 = right - mid; (*count)++;
    
    // Create temporary arrays
    Record* L = malloc(n1 * sizeof(Record)); (*count)++;
    Record* R = malloc(n2 * sizeof(Record)); (*count)++;

    // Check if memory allocation was successful
    if (L == NULL || R == NULL) {
    	(*count)++; 
        printf("Failed to allocate memory for temporary arrays.\n"); (*count)++;
        exit(1); (*count)++;
    }
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
    {
    	(*count)++;
        L[i] = arr[left + i]; (*count)++;
    }
    for (j = 0; j < n2; j++)
    {
    	(*count)++;
        R[j] = arr[mid + 1 + j]; (*count)++;
    }
    
    // Merge the temporary arrays back into arr[]
    i = 0; (*count)++;// Initial index of first subarray
    j = 0; (*count)++;// Initial index of second subarray
    k = left; (*count)++;// Initial index of merged subarray
    
    while (i < n1 && j < n2) 
	{
		(*count)++;
        if (L[i].idNumber <= R[j].idNumber) 
		{
			(*count)++;
            arr[k] = L[i];(*count)++;
            i++;(*count)++;
        } 
		else 
		{
			(*count)++;
            arr[k] = R[j]; (*count)++;
            j++; (*count)++;
        }
        k++; (*count)++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) 
	{
		(*count)++;
        arr[k] = L[i]; (*count)++;
        i++; (*count)++;
        k++; (*count)++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) 
	{
		(*count)++;
        arr[k] = R[j]; (*count)++;
        j++; (*count)++;
        k++; (*count)++;
    }
}

void mergeSort(Record* arr, int left, int right, int *count) 
{
    if (left < right)
	{
		(*count)++;
        int mid = left + (right - left) / 2; (*count)++;
        
        // Sort first and second halves
        mergeSort(arr, left, mid, &(*count)); (*count)++;
        mergeSort(arr, mid + 1, right, &(*count)); (*count)++;
        
        // Merge the sorted halves
        merge(arr, left, mid, right, &(*count)); (*count)++;
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

void swap(Record* x, Record* y, int *count) 
{
    Record temp = *x;
    *x = *y;
    *y = temp;
}

int getNextGap(int gap, int *count)
{
    
    gap = (gap * 10) / 13; (*count)++;
    if (gap < 1)
    {
    	(*count)++;
        return 1; (*count)++;
    }
    return gap; (*count)++;
}

void combSort(Record* arr, int n, int *count) 
{
    int gap = n; (*count)++;
    int swapped = 1; (*count)++;
    
    while (gap > 1 || swapped) 
	{
		(*count)++;
        gap = getNextGap(gap, &(*count)); (*count)++;
        
        swapped = 0; (*count)++;
        
        for (int i = 0; i < n - gap; i++) 
		{
			(*count)++;
            if (arr[i].idNumber > arr[i + gap].idNumber) 
			{
				(*count)++;
                swap(&arr[i], &arr[i + gap], &(*count)); (*count)++;
                swapped = 1; (*count)++;
            }
        }
    }
}











#endif