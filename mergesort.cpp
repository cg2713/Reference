#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

void print_vec(const vector<int>& vec)
{
  for(const int i: vec)
  { cout << i << ' '; }
  cout << endl;
};

void printLn(string output)
{
  cout << "<< " << output << " >>" << endl;
};

void merge(vector<int>& original, size_t l, size_t mid, size_t r)
{

  auto origin = begin(original);

  // the '+1' is necessary for the end condition for the copy constructor
  const vector<int> left  ( origin + l, origin + mid + 1);
  const vector<int> right ( origin + mid + 1, origin + r + 1);

  //printLn("left array [in merge]");
  //print_vec(left);
  //printLn("right array [in merge]");
  //print_vec(right);

  // iters for left, right, and original
  size_t i, j, k;
  i = 0;
  j = 0;
  k = l;

  // 1. compare values, and write
  while ( i < left.size() && j < right.size() )
  {
    original[k] = ( left[i] <= right[j] ? left[i++] : right[j++]);
    k++;
  }

  // fill in "leftover" values
  while ( i < left.size() )
  {
    original[k] = left[i];
    i++;
    k++;
  }

  while ( j < right.size() )
  {
    original[k] = right[j];
    j++;
    k++;
  }

  // 3. done
}

void mergesort(vector<int>& vec, size_t l, size_t r)
{
  // this guarantees there's at least two values to compare
  if (l < r)
  {
    // prevents overflow in the case that l,r are large
    size_t mid = l + (r-l) / 2;

    // left
    mergesort(vec, l, mid);
    // right
    mergesort(vec, mid+1, r);

    merge(vec, l, mid, r);
  }

  return;
}

int main(int argc, char *argv[])
{
  vector<int> my_list {54,26,93,17,77,31,44,55,20,101,67,44};
  //vector<int> my_list {54,26};


  printLn("original vector");
  print_vec(my_list);

  mergesort(my_list, 0, my_list.size() - 1);


  cout << '\n';

  printLn("sorted vector");
  print_vec(my_list);


  return 0;
}
