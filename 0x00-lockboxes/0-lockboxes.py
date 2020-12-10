def canUnlockAll(boxes):
    open = [False] * len(boxes)
    open[0] = True
    key_stack = [0]
    while key_stack:
        node = key_stack.pop()
        for key in boxes[node]:
            if not open[key]:
                open[key] = True
                key_stack.append(key)
    return all(open)
