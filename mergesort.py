"""
Mergesort:

  Paradigm: Divide and Conquer

  Complexities
    Time: O(n log n)
    Space: O(n)
    Stable: Yes

  Pros:
    1. Good for larger tasks since division allows for logarithmic growth.
  Cons:
    1. Slower compared to other algorithms for smaller tasks.
    2. additional space of O(n)

"""
def merge(array, left, right):
    # iterators for the left and right array
    i = 0
    j = 0
    # iterator for the original array
    k = 0


    # iterate through, compare each value, write the smaller one into
    # the original array first
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        # either way, move to the next space
        k += 1

    # now we need to get any "leftover" values
    while i < len(left):
        array[k] = left[i]
        k += 1
        i += 1

    while j < len(right):
        array[k] = right[j]
        k += 1
        j += 1

def mergesort(array):
    if len(array) > 1:
        mid = len(array) // 2

        # this creates a shallow copy that can be
        # modified during each call
        left =  array[ : mid ]
        right = array[ mid : ]

        mergesort(left)
        mergesort(right)
        merge(array, left, right)



my_list = [54,26,93,17,77,31,44,55,20,101,67,44]
print(my_list)
mergesort(my_list)
print(my_list)
