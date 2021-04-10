import sys

if __name__ == '__main__':
    for data in sys.stdin:
        cnt = 1
        while True:
            # 나누어 떨어지는 경우
            if int(cnt*'1') % int(data) == 0:
                print(cnt)
                break
            else:
                cnt += 1