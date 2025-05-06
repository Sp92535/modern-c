#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int arr[], size_t l, size_t r);
void quick_sort(int arr[], size_t l, size_t r);
void swap(int *a, int *b);
void printArr(int arr[], size_t n);

int main()
{
    srand(time(NULL));

    int arr[1000000];

    for(int i=0; i<1000000; i++){
        arr[i] = rand();
    }

    size_t n = sizeof(arr) / sizeof(arr[0]);

    clock_t c1 = clock();
    merge_sort(arr, 0, n);
    clock_t c2 = clock();
    
    double diff = (double)(c2-c1)/CLOCKS_PER_SEC;
    printf("Merge sort :%lf\n",diff);


    c1 = clock();
    quick_sort(arr, 0, n);
    c2 = clock();
    
    diff = (double)(c2-c1)/CLOCKS_PER_SEC;
    printf("Quick sort :%lf\n",diff);


    return EXIT_SUCCESS;
}


// sort from [l,r)
void merge_sort(int arr[], size_t l, size_t r)
{
    // return if one or less elements in array
    if (l >= r - 1)
        return;

    size_t mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);

    int temp[r - l];

    int i = l, j = mid, k = 0;

    for (; i < mid && j < r; k++)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i++];
        }
        else
        {
            temp[k] = arr[j++];
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j < r)
    {
        temp[k++] = arr[j++];
    }

    for (int z = 0; z < r - l; z++)
    {
        arr[l + z] = temp[z];
    }
}

// sort from [l,r)
void quick_sort(int arr[], size_t l, size_t r)
{
    // return if size is 0 or 1
    if (l >= r - 1)
        return;

    size_t mid = l + (r - l) / 2;
    int pivot = arr[mid];

    size_t i = l, j = r - 1;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            if (j > 0)
                j--;
        }
    }

    quick_sort(arr, l, j + 1);
    quick_sort(arr, i, r);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// utility to print array
void printArr(int arr[], size_t n)
{
    printf("[ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
