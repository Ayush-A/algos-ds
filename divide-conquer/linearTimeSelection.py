"""
This Program is an implementation of Linear time Selection Algorithm (Randomized) for finding n'th order statistic in O(n) time.
We divide the problem into subparts, thereby increasing the efficiency and reducing the search time. This is perfectly an example of a Randomized Algorithm.
"""

from random import randint

# Partition function to divide the array into subarrays
def partition(arr, left, right):

    # Selecting a random pivot and placing it in first position of list
    pivot_position = randint(left, right)
    arr[left], arr[pivot_position] = arr[pivot_position], arr[left]
    pivot = arr[left]
    
    i = left + 1
    for j in range(left + 1, right + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    
    # Adjust the pivot and return it's position
    arr[left], arr[i - 1] = arr[i - 1], arr[left]
    return i - 1

# Randomized Select function to find the n'th order statistic
def RSelect(lst, start, end, i):
    if end == start:
        print(f"{i}th order statistic is {lst[start]}")
        return
    pivot = partition(lst, start, end)
    k = pivot - start + 1
    if k == i:
        print(f"{i}th order statistic is {lst[pivot]}")
    elif k > i:
        RSelect(lst, start, pivot - 1, i)
    elif k < i:
        RSelect(lst, pivot + 1, end, i - k)

if __name__ == "__main__":
    lst = [7, 2, 4, 6, 6, 8, 5, 8, 9]
    lst = list(set(lst))

    """
    Arguments of RSelect:
    RSelect(Array/List, Starting index, Last index, Desired Order Statistic)
    """
    RSelect(lst, 0, len(lst) - 1, 7)