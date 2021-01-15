def solution(s):
    answer = []
    
    # 시도 횟수
    try_num = 0
    # 0 갯수
    zero_num = 0
    
    # 1일때까지 반복
    while(s != '1'):
        try_num += 1
        
        # 0 갯수 세기
        zero_num += s.count('0')
        
        # 0 없애기
        s = s.replace('0','')
        
        # 이진 변환
        len_bin = len(s)
        tmp_bin = []
        while len_bin > 0:
            tmp_bin.insert(0, str(len_bin % 2))
            len_bin //= 2
            
        # 이진 변환 결과 담기
        s = ''.join(tmp_bin)

    answer = [try_num, zero_num]
    return answer