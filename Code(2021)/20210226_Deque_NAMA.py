import sys

if __name__ == "__main__":
    
    # Deque
    deque = []

    # Define each action using dict.
    comm_dict = {'push_front': (lambda x: deque.insert(0,x)),\
                'push_back': (lambda x: deque.insert(len(deque), x)),\
                'pop_front': (lambda x: -1 if len(deque) == 0 else deque.pop(0)),\
                'pop_back': (lambda x: -1 if len(deque) == 0 else deque.pop(len(deque)-1)),\
                'size': (lambda x: len(deque)),\
                'empty': (lambda x: 1 if len(deque) == 0 else 0),\
                'front': (lambda x: -1 if len(deque) == 0 else deque[0]),\
                'back': (lambda x: -1 if len(deque) == 0 else deque[len(deque) - 1])}

    # stdin
    sel_num = list(map(int, sys.stdin.readline().split()))[0]
    
    # list for result
    results = []
    for comm_idx in range(sel_num):
        comm_str = sys.stdin.readline().split()

        if len(comm_str) >= 2:
            param = int(comm_str[1])
        else:
            param = 0

        result = comm_dict[comm_str[0]](param)
        if result is not None:
            results.append(result)

    # print results
    for data in results:
        print(data)