class Node:
    def __init__(self):
        self.children = {}
        self.keys_present = set()
        self.end_of_word = False

class WordDictionary:

    def __init__(self):
        self.root = Node()
        

    def addWord(self, word: str) -> None:
        
        curr = self.root

        for c in word:
            # c = ord(letter) - ord('a')
            # If we don't have it we create it 
            if not curr.children.get(c):
                curr.children[c] = Node()
                curr.keys_present.add(c)
            # If we have it we go to it
            curr = curr.children[c]
        curr.end_of_word = True

    def search(self, word: str) -> bool:
        def dfs(j, root):
            cur = root

            for i in range(j, len(word)):
                c = word[i]
                if c == ".":
                    for child in cur.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    if c not in cur.children:
                        return False
                    cur = cur.children[c]
            return cur.end_of_word

        return dfs(0, self.root)