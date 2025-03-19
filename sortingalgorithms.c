#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void insertionSort(Record* arr, int n) 
{
    Record temp;
    
    for (int i = 1; i < n; i++)
	{
        temp = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j].idNumber > temp.idNumber)
		{
            arr[j + 1] = arr[j];
            j--;												
        }
        
        arr[j + 1] = temp;									
    }
}																											

void selectionSort(Record* arr, int n)
{
    Record temp;
    
    for (int i = 0; i < n - 1; i++)
	{
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++)
		{
            if (arr[j].idNumber < arr[minIndex].idNumber)
			{
                minIndex = j;
            }
        }
        
        if (minIndex != i)
		{
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void merge(Record* arr, int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Record* L = malloc(n1 * sizeof(Record));
    Record* R = malloc(n2 * sizeof(Record));

    if (L == NULL || R == NULL) 
	{
        printf("Failed to allocate memory for temporary arrays.\n");
        exit(1);
    }
    
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) 
	{
        if (L[i].idNumber <= R[j].idNumber) 
		{
            arr[k] = L[i];
            i++;
        } 
		else 
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) 
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Record* arr, int left, int right) 
{
    if (left < right)
	{
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

void swap(Record* x, Record* y) 
{
    Record temp = *x;
    *x = *y;
    *y = temp;
}

int getNextGap(int gap)
{
    
    gap = (gap * 10) / 13;
    if (gap < 1)
    {
        return 1;
    }
    return gap;
}

void combSort(Record* arr, int n) 
{
    int gap = n;
    int swapped = 1;
    
    while (gap > 1 || swapped) 
	{
        gap = getNextGap(gap);
        
        swapped = 0;
        
        for (int i = 0; i < n - gap; i++) 
		{
            if (arr[i].idNumber > arr[i + gap].idNumber) 
			{
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}
#endif