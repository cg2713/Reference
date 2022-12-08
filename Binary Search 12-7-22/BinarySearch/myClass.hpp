#ifndef myClass_hpp
#define myClass_hpp

/*
File : myClass.hpp
Description : this is the file with the declaration of the class

*/

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