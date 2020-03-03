def quick_sort(arr):
    __quick_sort(arr, 0, len(arr) - 1)


def __quick_sort(arr, l, r):
    
    if l >= r:
        return
    
    mid = __partition(arr, l, r)
    __quick_sort(arr, l, mid -1)
    __quick_sort(arr, mid + 1, r)


def __partition(arr, l, r):
    j = l
    for i in range(l + 1, r + 1):
        if arr[i] < arr[l]:
            arr[i], arr[j + 1] = arr[j + 1], arr[i]
            j += 1
            
    arr[j], arr[l] = arr[l], arr[j]
    
    return j


import random

if __name__ == '__main__':
    arr = [random.randint(1, 10) for _ in range(10)]
    print(arr)
    quick_sort(arr)
    print(arr)