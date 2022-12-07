#include <iostream>
#include <vector>

using namespace std;

signed long long linear_search(const vector<int>& vec, const int target)
{

  int front = 0;
  int back = vec.size() - 1;

  for(; front <= back; front++, back--)
  {
    if (vec.at(front) == target) { return front; }
    if (vec.at(back) == target) { return back; }
  }
  return -1;
}

int main(int argc, char *argv[])
{
  vector<int> array {1, 2, 3, 4, 5, 6, 7, 8};

  int x = 8;

  for (int i: array)
  {
    cout << "Searching for " << i << ": " << linear_search(array, i) << endl;
  }

  return 0;
}
