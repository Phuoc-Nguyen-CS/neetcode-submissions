class Node:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class PrefixTree:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        # Start from the root we check if the letter exists
        curr = self.root 

        for c in word:
            # Check the children of the root
            i = ord(c) - ord("a")
            if not curr.children.get(i):
                curr.children[i] = Node()
            curr = curr.children[i]
        curr.is_end_of_word = True

    def search(self, word: str) -> bool:
        curr = self.root 

        for c in word:
            i = ord(c) - ord("a")
            if not curr.children.get(i):
                return False
            curr = curr.children[i]
        return curr.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for c in prefix:
            i = ord(c) - ord("a")   
            if not curr.children.get(i):
                return False
            curr = curr.children[i]
        return True
        
        