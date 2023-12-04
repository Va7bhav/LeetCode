class Solution:
    
    def splitArray(self, nums: List[int], k: int) -> int:
        def isPossible(m):
            cur = 0
            groups = 1
            for num in nums:
                cur += num
                if cur > m:
                    groups += 1
                    cur = 0
            if groups > k: return False
            
        nums.sort()

        l = nums[0]
        r = sum(nums)

        while l < r:
            m = (l + r) / 2

            if isPossible(m):
                r = m - 1
            else:
                l = m + 1

        
       

