#include <iostream>
//#include <vector>

using namespace std;

class myClass {
	public:
		int size;
		int* array;// = (int*)malloc(sizeof(int)*size);
	
	public:
		myClass(int s);
		int binarySearch(int* arr,int target,size_t low,size_t high);
		void fillarray(int *a);
		
};

myClass::myClass(int s = 10){
	size = s;
	array = (int*)malloc(sizeof(int)*s);
	fillarray(array);
}

void myClass::fillarray(int *a){
	for(int i = 1; i <= size; i++){
		a[i-1] = i;
	}
}

int myClass::binarySearch(int* arr,int target,size_t low,size_t high){
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

int main(int argc, char * argv[]){
	
	myClass a(100);
	cout << a.binarySearch(a.array,67,0,100) << endl;
	
	
	/*for(int i =0; i < 100; i++){
		cout << a[i] << ",";
	}
	cout << endl;
	int indexofserch = binarySearch(a,100,0,100);
	cout << indexofserch << endl;*/
}