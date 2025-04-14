#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], size_t l, size_t r);
void printArr(int arr[], size_t n);
void swap(int *a, int *b);


int main(){
	
	int arr[] = {1,2,5,6,2,1,0,4,9};
	
	size_t n = sizeof(arr)/sizeof(arr[0]);

	printArr(arr,n);
	
	sort(arr,0,n);

	printArr(arr,n);

	return EXIT_SUCCESS;
}

// sort from [l,r)
void sort(int arr[], size_t l, size_t r){
	// return if size is 0 or 1
	if(l >= r - 1) return;
	
	size_t mid = l + (r - l) / 2;
	int pivot = arr[mid];
	
	size_t i = l, j = r-1;

	while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            if (j > 0) j--;
        }
    }
	
	sort(arr,l,j+1);
	sort(arr,i,r);

}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// utility to print array
void printArr(int arr[], size_t n){
	printf("[ ");
	for(size_t i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("]\n");
}
