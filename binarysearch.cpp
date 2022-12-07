/*

Binary Search:

  Paradigm: Divide and Conquer

  Complexities
    Time: O(log n)
    Space: O(1)

  Pros:
    1. Perfect for an already sorted list.
    2. Growth is only logarithmic, best case.
  Cons:
    1. List must be sorted, lmao.
    
*/

#include <iostream>
#include <array>

using namespace std;

signed long long recursive_binarysearch(const int* const array, const int target, const size_t min, const size_t max)
{
  if ( min > max )
    return -1;

  size_t mid = static_cast<size_t> ( (min + max) / 2 );

  if (target == array[mid])
    return mid;

  if (target < array[mid])
    return recursive_binarysearch(array, target, min, mid - 1);
  else
    return recursive_binarysearch(array, target, mid + 1, max);
}

signed long long interative_binarysearch(const int* const array, const int target, size_t min, size_t max)
{
  while (min <= max)
  {
    size_t mid = static_cast<size_t> ( (min + max) / 2);

    if (target == array[mid]) return mid;

    if (target < array[mid]) max = mid - 1;
    if (target > array[mid]) min = mid + 1;
  }

  // default, no value found
  return -1;

}



int main(int argc, char * argv[])
{
  array<int, 10> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int x = 11;

  cout << "Array: ";
  for(int i: a)
  {
    cout << i << ' ';
  }
  cout << '\n';
  cout << endl; // flush buffer

  cout << "Binary searching using interative method" << '\n';
  for(int i: a)
  {
    cout << "Searching for " << i << ": " << interative_binarysearch(a.data(), i, 0, a.size()) << endl;
  }
  cout << '\n';

  cout << "Binary searching using recursive method" << '\n';
  for(int i: a)
  {
    cout << "Searching for " << i << ": " << recursive_binarysearch(a.data(), i, 0, a.size()) << endl;
  }
  cout << '\n';

  cout << "Searching for " << x << ": " << interative_binarysearch(a.data(), x, 0, a.size()) << endl;


  return 0;
}
