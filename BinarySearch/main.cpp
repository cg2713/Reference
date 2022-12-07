#include <iostream>
#include "myClass.hpp"
#include "myClass.cpp"
/*
File : main.cpp
Description : this is just the main file for the interactivity of myClass
witch incorporates the binary search

*/
using namespace std;

int main(int argc, char * argv[]){
	
	myClass a(100);
	cout << a.binarySearch(a.array,67,0,100) << endl;
	return 0;
	
}