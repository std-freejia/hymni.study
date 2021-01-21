import sys
import math
import numpy as np
        
light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

# 현재 위치를 기준으로 light의 사분면 파악하기
remain_x = light_x - initial_tx
remain_y = light_y - initial_ty

dir_arr = ['N','S','E','W','']
val_arr = [[0,1], [0,-1], [1,0], [-1,0], [0,0]]

# game loop
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.
 
    condition_arr = [(remain_y < 0), (remain_y > 0), \
                 (remain_x > 0), (remain_x < 0), \
                 (remain_x == 0 or remain_y == 0)]

    ch_dir = ''
    # True인 값만 찾아 index 가져오기
    for cond_idx in np.where(condition_arr)[0]:
        ch_dir += str(dir_arr[cond_idx])

        remain_x += -1 * val_arr[cond_idx][0]
        remain_y += val_arr[cond_idx][1]

    print(ch_dir)
    