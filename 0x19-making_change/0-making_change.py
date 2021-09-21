""" 0. Change comes from within """


# coins is an array of denominations such as [1, 5, 10, 25, 50] for the values of standard coins
# total is amount I need to make using the denominations
# def makeChange(coins, total):
#     """ buttsex """
#     pass


def _get_change_making_matrix(set_of_coins, r: int):
    m = [[0 for _ in range(r + 1)] for _ in range(len(set_of_coins) + 1)]
    for i in range(1, r + 1):
        m[0][i] = float('inf')  # By default there is no way of making change
    return m

# set_of_coins = [1, 2, 25]
# r = 37
# m = [
    [0, 'inf' x 37],
    [0 x 37 + 1],
    [0 x 37 + 1],
    [0 x 37 + 1],
# ]

# for coin in [1, 3]
#   for r in [1, 37]
#       if coins[0] == 1
#            m[coin][1] == 1 # easy
#        elif coins[coint - 1] > 1:
#           m[coin][1] = m[coin - 1][1]



def makeChange(coins, n: int):
    """This function assumes that all coins are available infinitely.
    n is the number to obtain with the fewest coins.
    coins is a list or tuple with the available denominations.
    """
    m = _get_change_making_matrix(coins, n)
    for c in range(1, len(coins) + 1):
        for r in range(1, n + 1):
            # Just use the coin coins[c - 1].
            if coins[c - 1] == r:
                m[c][r] = 1
            # coins[c - 1] cannot be included.
            # Use the previous solution for making r,
            # excluding coins[c - 1].
            elif coins[c - 1] > r:
                m[c][r] = m[c - 1][r]
            # coins[c - 1] can be used.
            # Decide which one of the following solutions is the best:
            # 1. Using the previous solution for making r (without using coins[c - 1]).
            # 2. Using the previous solution for making r - coins[c - 1] (without
            #      using coins[c - 1]) plus this 1 extra coin.
            else:
                m[c][r] = min(m[c - 1][r], 1 + m[c][r - coins[c - 1]])
    return m[-1][-1]


if __name__ == "__main__":
    print(makeChange([1, 2, 25], 37))

    print(makeChange([1256, 54, 48, 16, 102], 1453))
