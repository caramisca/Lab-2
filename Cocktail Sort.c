#include <stdio.h>  
#include <time.h>

/* function to implement Cocktail sort */  
void cocktail(int a[], int n)  
{   
    
    int swap = 1;  
    int beg = 0;  
    int end = n - 1;  
    int i, temp;  
    while (swap)  
    {  
        swap = 0;    
        for (i = beg; i < end; ++i)  
        {  
            if (a[i] > a[i + 1]) {  
                temp = a[i];    
                a[i] = a[i+1];    
                a[i+1] = temp;     
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
            if (a[i] > a[i + 1]) {  
                temp = a[i];    
                a[i] = a[i+1];    
                a[i+1] = temp;     
                swap = 1;  
            }  
        }  
        /* increase the beg point by one position.  
        It is because the item at the first position is at its correct position */  
        ++beg;  
    }  
    int i;  
    for(i = 0; i < n; i++)    
    {    
        printf("%d ", a[i]);    
    }        
}  
  
 void print(int a[], int n) //function to print array elements  
    {  
    
    }  
  
  
int main()  
{   
    int n;
    printf("Enter the size of the array: ");// input the length from the user
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array (separated by spaces): ");
    // Input array elements separated by spaces
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    } 
    printf("\n\n");  
    printf("Before sorting array elements are - \n");  
    print(a, n);  
    clock_t start_time = clock(); 
    cocktail(a, n);  
    clock_t end_time = clock();
    printf("\n\nAfter sorting array elements are - \n");    
    print(a, n);  
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Cocktail Sort: %.6f seconds\n", elapsed_time);
    return 0;  
}  