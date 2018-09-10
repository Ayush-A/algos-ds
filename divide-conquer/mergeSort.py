# Saving the contents of a file containing numbers in a list
with open("text.txt", "r") as arrayfile:
    arr = list(map(int, arrayfile.read().split()))

# Merge subroutine to merge the two arrays
def merge(arr, first, mid, last):
    temparr = []
    i = first
    j = mid + 1
    while i <= mid and j <= last:
        if arr[i] < arr[j]:
            temparr.append(arr[i])
            i += 1
        else:
            temparr.append(arr[j])
            j += 1
    while i <= mid:
        temparr.append(arr[i])
        i += 1
    while j <= last:
        temparr.append(arr[j])
        j += 1
    for i in range(last-first+1):
        arr[i + first] = temparr[i]

# This function implements Divide and Conquer
def mergesort(arr, first, last):
    if first < last:
        mid = (first + last) // 2
        mergesort(arr, first, mid)
        mergesort(arr, mid + 1, last)
        merge(arr, first, mid, last)

if __name__ == "__main__":
    mergesort(arr, 0, len(arr) - 1)
    with open("output.txt", "w") as fileout:
        for i in arr:
            fileout.write(f"{i}\n")
            