class Solution(object):
    def lengthOfLongestSubstring(self, s):
        store = set()
        left = 0
        res = 0
        for r in range(len(s)):
            while s[r] in store:
                store.remove(s[left]) 
                left += 1
            store.add(s[r])
            res = max(res, r-left+1)
        return res