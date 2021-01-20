import sys
sys.setrecursionlimit(10**7)

class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.value = 0
        self.children = {}


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head
        curr_node.value +=1
        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            curr_node = curr_node.children[char]
            curr_node.value += 1

    def dfs(self, query, level, curr_node):
        if not curr_node:
            curr_node = self.head
        if query[level] == '?':
            return curr_node.value
        if not query[level] in curr_node.children:
            return 0
        return self.dfs(query, level+1, curr_node.children[query[level]])



def solution(words, queries):
    answer = []
    sorted_dict = dict()
    reversed_dict = dict()
    for w in words:
        if not len(w) in sorted_dict:
            sorted_dict[len(w)] = Trie()
            reversed_dict[len(w)] = Trie()
        sorted_dict[len(w)].insert(w)
        reversed_dict[len(w)].insert(w[::-1])
        
    for q in queries:
        len_dict = sorted_dict
        len_q = len(q)
        if not len_q in len_dict:
            answer.append(0)
            continue
        if q[0]=='?':
            q = q[::-1]
            len_dict = reversed_dict
        answer.append(len_dict[len_q].dfs(q,0,None))
        

    return answer