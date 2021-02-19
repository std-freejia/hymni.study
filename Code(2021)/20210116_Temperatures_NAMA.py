import sys
import math
import numpy as np

n = int(input())  # the number of temperatures to analyse
if n == 0:
    print(0)
else:
    arr = list(map(float,input().split()))
    arr_abs_min = min(list(map(abs,arr)))
    bool_arr = np.where([(abs(x) == arr_abs_min) for x in arr])
    
    if len(bool_arr[0]) > 1:
        if arr[bool_arr[0][0]] > arr[bool_arr[0][1]]:
            print(int(arr[bool_arr[0][0]]))
        else:
            print(int(arr[bool_arr[0][1]]))
    else:
        print(int(arr[bool_arr[0][0]]))
