#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	Record* arr;
    int n = getSize(arr, "random100.txt");
	arr = malloc(n * sizeof(Record));
	long long count = 0;
	if (arr == NULL) 
	{
    printf("Failed to allocate memory for the array.\n");
    exit(1);
	}	
	readFile(arr, "random100.txt");
	//insertionSort(arr, n, &count);
	//selectionSort(arr, n, &count);
	//mergeSort(arr, 0, n - 1, &count);
    //combSort(arr, n, &count);
    
    long startTime, endTime, executionTime;
	startTime = currentTimeMillis(); // store the current time
	mergeSort(arr, 0, n - 1);
	endTime = currentTimeMillis(); // store the current time
	executionTime = (endTime - startTime);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].idNumber, arr[i].name);
    }
    printf("\nComb Sort");
    printf("\nExecution time: %ld milliseconds", executionTime);
    printf("\nFrequency count: %lld", count);
    return 0;
}