
def partition(Array, low, high):
    pivot = Array[high]
    i = low - 1

    for j in range(low,high):
        if Array[j] <= pivot:
            i += 1
            #(array[i], array[j]) = (array[j], array[i])
            t = Array[j]
            Array[j] = Array[i]
            Array[i] = t

    #(array[i + 1], array[high]) = (array[high], array[i + 1])
    t = Array[high]
    Array[high] = Array[i+1]
    Array[i+1] = t

    return i + 1



def QuickSort(Array, low, high):
    if low < high:
        Part = partition(Array, low, high)
        QuickSort(Array,low,Part-1)
        QuickSort(Array, Part+1,high)




array = [10, 7, 8, 9, 1, 5]
QuickSort(array, 0, len(array) - 1)
 
print(f'Sorted array: {array}')