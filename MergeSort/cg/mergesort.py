import random

def merge(array,Left,right):
    #iterators for left and right indexes
    i = 0
    j = 0
    #iterators for original array
    k = 0

    #now copy data from the new arrays to the originel
    while i < len(Left) and j < len(right):
        if Left[i] <= right[j]:
            array[k] = Left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1
    #fianlly copy all remaining data in the temp arrays into the originel array
    while i < len(Left):
        array[k] = Left[i]
        i += 1
        k += 1
    while j < len(right):
        array[k] = right[j]
        j += 1
        k += 1


def mergeSort(array):
    if len(array)>1:
        m = len(array) // 2

        Left = array[m:]
        right = array[:m]
        mergeSort(Left)
        mergeSort(right)
        merge(array,Left,right)

MAX = 100000

if __name__ == '__main__':
    array = [random.randint(1,MAX) for _ in range(MAX)]
    print(f"originel array is: {array}")
    print("sorting...")
    mergeSort(array)
    print(f"sorted array is: {array}")