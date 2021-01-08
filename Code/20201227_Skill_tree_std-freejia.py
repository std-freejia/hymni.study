def get_index(skill_list, target_list):
    res_list = list()

    for idx in range(len(skill_list)):
        if skill_list[idx] in target_list:
            if target_list.index(skill_list[idx]) < skill_list.index(skill_list[idx]):
                return False
            else:
                res_list.append(target_list.index(skill_list[idx]))

    is_sorted = (res_list == sorted(res_list))

    return is_sorted

def solution(skill, skill_trees):
    answer = 0

    skill_list = list(skill)

    for target_tree in skill_trees:
        target_list = list(target_tree)
        boolean_chk = get_index(skill_list, target_list)
        if boolean_chk:
            answer = answer + 1
    return answer