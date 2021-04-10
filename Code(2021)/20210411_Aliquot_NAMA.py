# 입략 받은 자연수 x보다 작거나 같은 수의 약수의 합의 합 구하기

import sys

if __name__ == '__main__':
    x = int(sys.stdin.readline())
    
    g_x = 0
    for idx in range(1, x+1):
        g_x += (idx * (x // idx))

    print(int(g_x))