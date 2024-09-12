from queue import Queue
class Solution:
    def isOneDistance(self, elem, word):
        diff = 0
        for i in range(len(elem)):
            if elem[i] != word[i]:
                diff+=1
            if diff > 1:
                return False
        return diff == 1

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        visitedSet = set()
        queue = Queue()
        queue.put((beginWord, 1))
        while not queue.empty():
            (elem, curr_depth) = queue.get()
            to_rem = []
            for word in wordSet:
                if self.isOneDistance(elem, word):
                    queue.put((word, curr_depth+1))
                    to_rem.append(word)               
                    if word == endWord:
                        return curr_depth + 1
            for rem in to_rem:
                wordSet.remove(rem)
        return 0

from queue import Queue
class Solution2:
    def isOneDistance(self, elem, word):
        diff = 0
        for i in range(len(elem)):
            if elem[i] != word[i]:
                diff+=1
            if diff > 1:
                return False
        return diff == 1

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set([beginWord] + wordList)
        word_to_mask = {}
        mask_to_word = {}
        for word in wordSet:
            for i in range(len(word)):
                mask = word[0:i] + '_' + word[i+1:]
                if mask not in mask_to_word:
                    mask_to_word[mask] = set()
                mask_to_word[mask].add(word)
                if word not in word_to_mask:
                    word_to_mask[word] = set()
                word_to_mask[word].add(mask)

        visitedSet = set()
        queue = Queue()

        queue.put((beginWord, 1))
        while not queue.empty():
            word, curr_len = queue.get()
            visitedSet.add(word)
            if word == endWord:
                return curr_len
            masks = word_to_mask[word]

            for mask in masks:
                words = mask_to_word[mask]
                for word in words:
                    if word in visitedSet:
                        continue
                    queue.put((word, curr_len+1))

        return 0
