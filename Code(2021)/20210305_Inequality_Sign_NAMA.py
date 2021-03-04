import sys

len_ineq = int(sys.stdin.readline().strip())
tmp_ineq_list = sys.stdin.readline().split()

def give_me_answer(ineq_list, num_set, sep, ineq_num):

    # 끝 길이를 맞추기 위한 작업
    ineq_list.append(' =')
    arr_result = []
    
    # 각 Max, Min값 별로 구분해야할 seperator 따로 지정
    if sep == '<':
        flag = False
    else:
        flag = True
    
    sep_cnt = 0
    for seq_idx in range(ineq_num):
        # 구분해야 할(순서를 달리 해야 할 구분자 구분)
        if ineq_list[seq_idx] == sep:
            sep_cnt += 1
        else:
            if sep_cnt != 0:
                arr_result.extend(sorted(num_set[seq_idx - sep_cnt:seq_idx+1], reverse = flag))
                sep_cnt = 0
            else:
                arr_result.extend([num_set[seq_idx]])

    print("".join(map(str,arr_result)))

# Main Function
if __name__ == "__main__":

    # 각 연산에 필요한 list 
    nums = list(range(0,10))

    give_me_answer(tmp_ineq_list, sorted(nums,reverse=True), '<', len_ineq+1)
    give_me_answer(tmp_ineq_list, nums, '>', len_ineq+1)