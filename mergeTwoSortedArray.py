class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        k = m + n - 1
        i = m - 1
        j = n - 1
        while i >= 0 and j >= 0:
            if nums1[i] >= nums2[j]:
                nums1[k] = nums1[i]
                k -= 1
                i -= 1
            elif nums2[j] > nums1[i]:
                nums1[k] = nums2[j]
                k -= 1
                j -= 1
        print(j)
        while j >= 0:
            nums1[k] = nums2[j]
            n, k = n - 1, k - 1
        return nums1
            
            
sally = Solution()
list1 = [1, 2, 3, 0, 0, 0]
list2 = [2, 5, 6]
n = 3
sally.merge(list1, list2, n)