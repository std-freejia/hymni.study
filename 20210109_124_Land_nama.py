def solution(n):
    answer = []
    
    # 진법 변환
    while n > 0:  
        # 4가 나와야할 경우
        # 3진수 - 자리올림 대신 4로 대체 (몫 - 1)
        if n % 3 == 0:
            answer.insert(0,'4')
            n = (n // 3) - 1
        else:
            # 3진법 계산
            answer.insert(0, str(n % 3))
            n = n // 3

    
    return ''.join(answer)