def solution(s):
    answer = []
    
    str_idx = 0
    for cont in s:
        if cont.isalpha() == True:
            if str_idx % 2 == 0:
                answer.append(cont.upper())
            else:
                answer.append(cont.lower())
            str_idx = str_idx + 1
            
        else:
            if cont == ' ':
                str_idx = 0
            answer.append(cont)

    return ''.join(answer)