#ifndef myClass_hpp
#define myClass_hpp

class myClass {
	public:
		int size;
		int* array;// = (int*)malloc(sizeof(int)*size);
	
	public:
		myClass(int s);
		int binarySearch(int* arr,int target,size_t low,size_t high);
		void fillarray(int *a);
		
};

#endif