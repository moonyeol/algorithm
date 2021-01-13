class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = None
        self.value = 0
        self.children = {}


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head
        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            curr_node = curr_node.children[char]
            curr_node.value += 1
        curr_node.data = string

    def dfs(self, n, curr_node):
        if not curr_node:
            curr_node = self.head
        if curr_node.value == 1:
            return n
        result = 0
        if curr_node.data:
            result += n

        for child in curr_node.children.values():
            result += self.dfs(n + 1, child)
        return result


def solution(words):
    answer = 0
    trie = Trie()
    for w in words:
        trie.insert(w)
    answer = trie.dfs(0, None)

    return answer