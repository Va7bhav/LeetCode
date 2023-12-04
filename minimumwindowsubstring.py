class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "": return ""
        countW, countT = {}, {}  
        for c in s:
            countT[c] = 1 + countT.get(c, 0)
        l, r = 0, 0
        have, need = 0, len(t)
        res, reslen = "", float("infinity")
        while r < len(s):
            c = s[r]
            countW[c] += 1
            if c in countT:
                if countW[c] == countT[c]:
                    have += 1
            while have == need:
                if (r - l + 1) < reslen: 
                    resLen = (r - l + 1)
                    res = s[l : r + 1]
                countW[l] -= 1
                if s[l] in countT:
                    if countW[s[l]] < countT[s[l]]:
                        have -= 1
                l += 1
            r += 1
        return res