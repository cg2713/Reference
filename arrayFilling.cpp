#include <iostream>

using namespace std;

void fillarray(int *a){
	for(int i = 0; i <= 99; i++){
		a[i] = i+1;
	}
}

int main(int argc, char * argv[]){
	int a[100];
	//int *ptr = &a[0]
	fillarray(a);
	cout << a[0] << endl;
}

binarySearch(int* arr,int target,size_t low,size_t high){
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