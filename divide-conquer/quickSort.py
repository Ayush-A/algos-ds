from random import randint

# Saving the contents of a file containing numbers, in a list
with open("text.txt", "r") as arrayfile:
    arr = list(map(int, arrayfile.read().split()))

# Implementing randomized quick sort algorithm
# Subroutine to partition the array on the basis of pivot element
def partition(arr, left, right):

    # Randomly generate a position in the array to swap with first element
    # We will make the random pivot as first element and then proceed further
    pivot_position = randint(left, right)
    arr[left], arr[pivot_position] = arr[pivot_position], arr[left]
    pivot = arr[left]
    
    # In-place swapping the appropriate elements
    i = left + 1
    for j in range(left + 1, right + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    
    # Finally placing the pivot on its correct position
    arr[left], arr[i - 1] = arr[i - 1], arr[left]
    return i

# Recusive function to make recursive calls upon the partitions
def quicksort(arr, left, right):
    if left < right:
        pivot_position = partition(arr, left, right)
        quicksort(arr, left, pivot_position - 2)
        quicksort(arr, pivot_position, right)

if __name__ == "__main__":
    quicksort(arr, 0, len(arr) - 1)

    # Writing the output to a file
    with open("output.txt", "w") as fileout:
        for i in arr:
            fileout.write(f"{i}\n")
