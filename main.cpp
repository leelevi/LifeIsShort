#include<iostream>
#include<string>
#include<cstdio>
#include"test.h"
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int temp[100000];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left,
    int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
(if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
int getInvCount(std::vector<int> arr, int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr.at(i) > arr.at(j))
				inv_count++;

	return inv_count;
}
int main()
{
	std::vector<int> arr ;
	load_data(".\\IntegerArray.txt", arr);
	//std::vector<int> arr = { 9,8,7,6,5,4,3,2,1 };
	//MergeSort(arr);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
	std::vector<int> arr1 = {9,8, 4,5,1,3,7,2};
	std::cout << countReverse(arr) << std::endl;
	std::vector<int> arr2 = { 9,8, 4,5,1,3,7,2 };
	std::cout << getInvCount(arr2,arr2.size()) << std::endl;
    int a[100000];
    load_data_array(".\\IntegerArray.txt", a);
    std::cout << a[0] << std::endl;
   long ans = mergeSort(a, 100000);
    return 0;
}
