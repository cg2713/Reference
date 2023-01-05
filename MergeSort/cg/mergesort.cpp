#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, vector<int> &left, vector<int> &right){
    //iterators for left and right indexes and originel array witch is k
    unsigned int i = 0,j = 0,k = 0;
    //now copy data from the new arrays to the originel
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
        k++;
    }
    //fianlly copy all remaining data in the temp arrays into the originel array
    while(i < left.size()){
        array[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size()){
        array[k] = right[i];
        j++;
        k++;
    }
}

// left at first is 0 right at first is array -1
void mergesort(vector<int> &array, int L, int R){
    //here is where the merger sort algorithum will be held
    if(L < R){
        unsigned int mid = L + (R - L) / 2;
        
        vector<int> *left = new vector<int>;
        vector<int> *right = new vector<int>;
        for (unsigned int i=0; i < mid; i++){
            left->push_back(array[i]);
            if(mid+i < array.size())
                right->push_back(array[mid + i]);
        }
        mergesort(*left,L,mid);
        mergesort(*right,mid+1,R);
        merge(array, *left, *right);
        delete left;
        delete right;
    }
    return;
}

int main(int argc, char * argv[]){
    // create array here
    vector<int> array {0,1};
}