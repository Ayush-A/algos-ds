# Saving the contents of a file containing numbers, in a list
with open("text.txt", "r") as arrayfile:
    arrfile = list(map(int, arrayfile.read().split()))

# Subroutine to count the number of split inversions
def splitinv(arr, first, mid, last):
    i = first
    j = mid + 1
    inversions = 0
    tmpar = []
    while i <= mid and j <= last:
        if arr[i] <= arr[j]:
            tmpar.append(arr[i])
            i+=1
        else:
            tmpar.append(arr[j])
            inversions += mid - i + 1
            j+=1
    while i<=mid:
        tmpar.append(arr[i])
        i+=1
    while j<=last:
        tmpar.append(arr[j])
        j+=1
    for i in range(last-first+1):
        arr[i + first] = tmpar[i]
    return inversions

# Implement Divide and Conquer to merge and sort the lists whilst calculating inversions 
def sortmerge(arr, first, last):
    x = 0
    if first < last:
        mid = (first + last) // 2
        x = sortmerge(arr, first, mid)
        x += sortmerge(arr, mid + 1, last)
        x += splitinv(arr, first, mid, last)
    return x

if __name__ == "__main__":
    print(sortmerge(arrfile, 0, len(arrfile) - 1))