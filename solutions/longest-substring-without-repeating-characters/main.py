class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_map = dict()
        start = 0
        maxlen = 0

        for end in range(len(s)):
            if s[end] in char_map and char_map[s[end]] >= start:
                start = char_map[s[end]] + 1
            char_map[s[end]] = end
            maxlen = max(maxlen, end - start + 1)
        return maxlen
