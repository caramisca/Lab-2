#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int array[], int length)
{
    clock_t start_time = clock();  
    for ( int i = 0; i < length; i++)
    {
       for(int j = 0; j < length - 1 - i; j++)
       {
          if(array[j] > array[j+1])
          {
             int temp = array[j];
             array[j] = array[j+1];
             array[j+1] = temp;
          }
       }
    }
    printf("Sorted array using Bubble Sort:\n");
     for (int i = 0; i < length; i++)
         printf("%d ", array[i]);
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Bubble Sort: %.6f seconds\n", elapsed_time);
}

void SelectionSort(int array[], int length)
{
  clock_t start_time = clock();
  for (int i = 0 ; i < length - 1; i++)
  {
    int min = i;
    for(int j = i + 1 ; j < length ; j++)
        {
          if (array[j] < array[min])
          min = j;
        }
      if (min != i)
    {
      int temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }

  }
  printf("\nSorted array using Selection Sort:\n");
     for (int i = 0; i < length; i++)
         printf("%d ", array[i]);
  clock_t end_time = clock();
  double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("\nTime taken for Selection Sort: %.6f seconds\n", elapsed_time);
}

void InsertionSort(int array[], int length)
{
  
  srand(time(NULL));
  for (int i = 1; i < length; i++)
  {
     int key = array[i];
     int j = i - 1;
     while (j >= 0 && array[j] > key)
     {
        array[j + 1] = array[j]; 
        j = j - 1;
     }
     array[j + 1] = key;
  }
  printf("\nSorted array using Insertion Sort:\n");
    for (int i = 0; i < length; i++)
      printf("%d ", array[i]);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int low, int high)
{
    int pivot_index = low + (rand() % (high - low));

    if (pivot_index != high)
       swap(&array[pivot_index], & array[high]);

    int pivot_value = array[high];

    int i = low;

    for(int j = low; j < high; j++)
    {
      if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);

    return i;
}

void quicksort_recursion(int array[], int low, int high)
{
   if (low < high)
   {
     int pivot_index = partition(array, low, high);
     quicksort_recursion(array, low, pivot_index - 1);
     quicksort_recursion(array, pivot_index + 1, high);
   }
}

void QuickSort(int array[], int length)
{
  quicksort_recursion(array, 0, length - 1);
     printf("\nSorted array using Quick Sort:\n");
       for (int i = 0; i < length; i++)
          printf("%d ", array[i]);
  
}

void CocktailSort(int array[], int length)  
{   
    srand(time(NULL));
    int swap = 1;  
    int beg = 0;  
    int end = length - 1;  
    int i, temp;  
    while (swap)  
    {  
        swap = 0;    
        for (i = 0; i < end; ++i)  
        {  
            if (array[i] > array[i + 1]) {  
                temp = array[i];    
                array[i] = array[i+1];    
                array[i+1] = temp;     
                swap = 1;  
            }  
        }  
  
        if (!swap)  
            break;  
        swap = 0;  
           /* decrease the 'end' point by one position.  
        It is because the item at the last position is at its correct position */  
        --end;    
        /* This loop starts from right to left to perform the same comparison as in the previous loop */  
        for (int i = end - 1; i >= beg; --i)  
        {  
            if (array[i] > array[i + 1]) {  
                temp = array[i];    
                array[i] = array[i+1];    
                array[i+1] = temp;     
                swap = 1;  
            }  
        }  
        /* increase the beg point by one position.  
        It is because the item at the first position is at its correct position */  
        ++beg;  
    } 
    printf("\nSorted array using Cocktail Sort:\n");
     for (int i = 0; i < length; i++)
         printf("%d ", array[i]);
    
}

int main()
{
    int length;
    printf("Enter the size of the array: ");// input the length from the console
    scanf("%d", &length);
    int *array = (int *)malloc(length * sizeof(int));
    printf("Enter the elements of the array (separated by spaces): ");
    // Input array elements separated by spaces
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);

    } 
    printf("\n\n");

    BubbleSort(array , length);//swaps 2 elements that are next to each other, if they are not in order comparing...

    SelectionSort(array, length);//
    
    clock_t start_time = clock();
    InsertionSort(array, length);
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Insertion Sort: %.6f seconds\n", elapsed_time);
    
    start_time = clock();
    QuickSort(array, length);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Quick Sort: %.6f seconds\n", elapsed_time);
    
    start_time = clock(); 
    CocktailSort(array, length);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Cocktail Sort: %.6f seconds\n", elapsed_time);
   return 0;
}
 