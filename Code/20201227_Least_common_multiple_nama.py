def solution(arr):
    answer = 0
    
    flag = 0
    answer = max(arr)
    
    while True:
        flag = 0
        for num in arr:
            if answer % num == 0:
                flag = flag + 1
                
        if flag == len(arr):
            break
    
        answer = answer + 1
    
    return answer