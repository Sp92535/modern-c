#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], size_t l, size_t r);
void printArr(int arr[], size_t n);

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
	// return if one or less elements in array
	if(l >= r - 1) return;
	
	size_t mid = l + (r - l) / 2;
	sort(arr,l,mid);
	sort(arr,mid,r);
	
	int temp[r-l];
	
	int i = l, j = mid, k = 0;
	
	for(;i<mid && j<r;k++){
		if(arr[i]<arr[j]){
			temp[k] = arr[i++];
		}else{
			temp[k] = arr[j++];
		}
	}
	
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<r){
		temp[k++] = arr[j++];
	}

	for(int z = 0; z < r-l; z++){
		arr[l+z] = temp[z];
	}
}

// utility to print array
void printArr(int arr[], size_t n){
	printf("[ ");
	for(size_t i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("]\n");
}
