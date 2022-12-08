"""

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


"""

def recursive_binarysearch(array, target, min, max):

    if min > max:
        return -1

    mid = int( (min + max) / 2 )

    if array[mid] == target:
        return mid

    if target < array[mid]:
        return binarysearch(array, target, min, mid - 1)
    else:
        return binarysearch(array, target, mid + 1, max)


def interative_binarysearch(array, target, min, max):

    while min <= max:
        mid = int( (min + max) / 2 )

        if array[mid] == target:
            return mid

        if target < array[mid]:
            max = mid - 1
        if target > array[mid]:
            min = mid + 1


    #default, no value found
    return -1

a = [i for i in range(1, 11)]

print('Array: ' + ' '.join( [str(i) for i in a] ))

print()
print("Binary searching using interative method")
for i in a:
    print(f"Searching for {i:0>2}: ", interative_binarysearch(a, i, 0, len(a)))

print()
print("Binary searching using recursive method")
for i in a:
    print(f"Searching for {i:0>2}: ", interative_binarysearch(a, i, 0, len(a)))
