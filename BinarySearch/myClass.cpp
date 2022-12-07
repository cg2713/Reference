#include "myClass.hpp"
/*
File : myClass.cpp
Description : this is the file that contains all the function definition of myClass

*/

myClass::myClass(int s = 10){ //constructs myClass 
	size = s;
	array = (int*)malloc(sizeof(int)*s);
	fillarray(array);
}

void myClass::fillarray(int *a){ // fill array with numbers in ascending order
	for(int i = 1; i <= size; i++){
		a[i-1] = i;
	}
}

int myClass::binarySearch(int* arr,int target,size_t low,size_t high){ // Binary search reference https://www.geeksforgeeks.org/binary-search/
	if(low > high)
		return -1;
	else{
		size_t mid = (low + high)/2;
		if (target == arr[mid])
			return mid;
		else if(target > arr[mid])
			return binarySearch(arr, target, mid + 1, high);
		else
			return binarySearch(arr, target, low, mid - 1);
	}
}