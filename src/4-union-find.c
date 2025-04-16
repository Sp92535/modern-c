#include <stdio.h>
#include <stdlib.h>

/*
	I won't be using SIZE_MAX to represent root but if parent[i]==i then it is root
*/
#define N 100

void Union(size_t parent[], size_t left, size_t right);
void findReplace(size_t parent[], size_t x, size_t val);
void findCompress(size_t parent[], size_t x);
void printArr(size_t arr[], size_t n);
size_t find(size_t parent[], size_t ele);

int main()
{
	size_t parent[N] = {0};
	for (size_t i = 1; i < N; i++)
	{
		// replacing with a random function value that came in my mind
		findReplace(parent, i, i - 1);
	}
	printArr(parent,N);
	Union(parent, 58, 79);
	printArr(parent, N);
	return EXIT_SUCCESS;
}

void findReplace(size_t parent[], size_t x, size_t val)
{
	do
	{
		size_t p = parent[x];
		parent[x] = val;
		x = p;
	} while (parent[x] != x);
}

void findCompress(size_t parent[], size_t x)
{
	size_t root = find(parent, x);
	while (x != root)
	{
		size_t p = parent[x];
		parent[x] = root;
		x = p;
	}
}

size_t find(size_t parent[], size_t ele)
{
	while (parent[ele] != ele)
	{
		ele = parent[ele];
	}
	return ele;
}

void Union(size_t parent[], size_t left, size_t right)
{
	findCompress(parent, left);
	size_t root = find(parent, left);
	findReplace(parent, right, root);
}

// utility to print array
void printArr(size_t arr[], size_t n)
{
	printf("[ ");
	for (size_t i = 0; i < n; i++)
	{
		printf("%ld ", arr[i]);
	}
	printf("]\n");
}