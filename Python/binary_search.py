def binary_search_recursive(arr, target):
    if len(arr) == 0:
        return -1
    else:
        return __binary_search_recursive(arr, 0, len(arr) - 1, target)


# 查找[l, r]区间中是否有target
def __binary_search_recursive(arr, l, r, target):
    
    if(l > r):
        return -1
    
    mid = l + (r - l) // 2
    #mid将arr分为[l, mid - 1], [mid + 1, r]
    if arr[mid] == target:
        return mid
    elif arr[mid] > target:
        return __binary_search_recursive(arr, l, mid - 1, target)
    else:
        return __binary_search_recursive(arr, mid + 1, r, target)


def binary_search_iterative(arr, target):
    if(len(arr) == 0):
        return -1
    
    # 在[l, r]中寻找arr中是否有target
    l, r = 0, len(arr) - 1
    while(l <= r):
        mid = l + (r - l) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
            
    return -1


import random

if __name__ == '__main__':
    arr = [random.randint(0, 10) for _ in range(10)]
    arr.sort()
    print(arr)
    print(binary_search_recursive(arr, 5))
    print(binary_search_iterative(arr, 5))