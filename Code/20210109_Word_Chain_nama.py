def solution(n, words):
    answer = []

    # 단어 하나씩 가져오기
    for idx, word in enumerate(words):
        # 현재 단어의 index보다 작으면 나왔던 단어
        if(words.index(word) < idx):
            answer = [idx % n + 1, idx // n + 1]
            return answer
        # 끝말잇기 규칙 모르는 친구
        elif(idx != 0 and words[idx-1][-1] != word[0]):
            answer = [idx % n + 1, idx // n + 1]
            return answer
        
    # 결격 사유 X, 무난한 게임
    answer = [0,0]

    return answer