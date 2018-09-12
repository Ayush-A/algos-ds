# The median-of-three pivot rule is used with quick sort to decrease the time complexity of the algorithm

# Saving the contents of a file containing numbers, in a list
with open("quick.txt", "r") as arrayfile:
    arr = list(map(int, arrayfile.read().split()))

# Implementing median-of-three pivot rule to sort the list using quick sort
# Subroutine to partition the array on the basis of pivot element
def partition(arr, left, right):
    
    # find the median (pivot) element among the first, middle and last element of every partition
    a = arr[left]
    b = arr[left + ((right - left) // 2)]
    c = arr[right]
    if a > b:
        if a < c:
            median = left
        elif b > c:
            median = left + ((right - left) // 2)
        else:
            median = right
    else:
        if a > c:
            median = left
        elif b < c:
            median = left + ((right - left) // 2)
        else:
            median = right 

    # Making the median element as the pivot and swapping it with the first element
    arr[left], arr[median] = arr[median], arr[left]
    pivot = arr[left]
    
    # In-place swapping the appropriate elements to sort
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
    global comparison
    if left < right:
        pivot_position = partition(arr, left, right)
        
        # Counting the number of comparisons
        comparison += right - left

        quicksort(arr, left, pivot_position - 2)
        quicksort(arr, pivot_position, right)
        return comparison

if __name__ == "__main__":
    comparison = 0
    print(quicksort(arr, 0, len(arr) - 1))
    
    # Writing the output to a file
    with open("output.txt", "w") as fileout:
        for i in arr:
            fileout.write(f"{i}\n")
