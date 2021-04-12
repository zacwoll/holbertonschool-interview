#!/usr/bin/python3
""" Rain Module """


def rain(walls):
    """ Return the maximum of water
        that can be stored
    """
    # Stores indices of the walls
    stack = []

    # size of the walls array
    n = len(walls)

    # Store final result
    result = 0

    # Loop through each wall in walls
    for i in range(n):

        # Remove bars from the stack
        while (len(stack) != 0 and (walls[stack[-1]] < walls[i])):

            # store the height of the top wall
            pop_height = walls[stack[-1]]
            stack.pop()

            # If the stack does not have any walls
            # or the popped bar has no left boundary
            if (len(stack) == 0):
                break

            # get the distance between the left
            # and right boundary of the popped wall
            distance = i - stack[-1] - 1

            # Calculate the minimum height
            min_height = min(walls[stack[-1]], walls[i]) - pop_height

            result += distance * min_height

        stack.append(i)

    return result


if __name__ == "__main__":
    arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(rain(arr))
