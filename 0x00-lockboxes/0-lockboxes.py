#!/usr/bin/python3
'''DFS algo to check if all boxes can be opened'''


def canUnlockAll(boxes):
    ''' Opens all boxes, returns T/F '''
    if not boxes:
        return False
    open = [False] * len(boxes)
    open[0] = True
    key_stack = [0]
    while key_stack:
        node = key_stack.pop()
        for key in boxes[node]:
            if key < len(boxes) and not open[key]:
                open[key] = True
                key_stack.append(key)
    return all(open)
