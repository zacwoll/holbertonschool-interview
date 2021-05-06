#!/usr/bin/python3
"""
    Queries Reddit API for top ten
    posts for a given subreddit
"""


def get_user_agent():
    """ create/return a user_agent """
    platform = "linux"
    app_id = "for_science"
    version = "v0.0.1"
    username = "Almost_Irish"
    user_agent = '{}:{}:{} (by /u/{})'.format(
        platform, app_id, version, username
    )
    return user_agent


def count_words(subreddit, word_list, **kwargs):
    """Prints a sorted count of given keywords listed for a subreddit"""
    import requests

    count = kwargs['count'] if 'count' in kwargs else 0
    after = kwargs['after'] if 'after' in kwargs else {}
    memo = kwargs['memo'] if 'memo' in kwargs else {}
    word_count = kwargs['word_count'] if 'word_count' in kwargs else {}

    url = [
        "https://www.reddit.com/r/",
        "{}/hot/.json".format(subreddit),
        "?limit=100&after={}".format(after)
    ]
    url = "".join(url)
    headers = {
        'user-agent': get_user_agent()
    }
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        print('error', response.status_code, response.url)
        return None

    after = response.json()['data']['after']
    children = response.json()['data']['children']

    for child in children:
        title = child['data']['title'].lower().split()

        for word in word_list:
            word = word.lower()
            counted = memo[word] if word in memo else None
            word_count = counted if counted is not None else 0
            word_count += title.count(word)
            memo.update({word: word_count})

    count += len(children)

    if after is not None:
        # print('Call')
        count_words(
            subreddit, word_list,
            count=count,
            after=after,
            memo=memo,
            word_count=word_count
        )
    else:
        values = list(memo.values())
        keys = list(memo.keys())

        while values != []:
            max_index = values.index(max(values))
            key, value = keys.pop(max_index), values.pop(max_index)
            if value > 0:
                print("{}: {}".format(key, value))