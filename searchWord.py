class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        res = [[]]
        products.sort()

        l, r = 0, len(products) - 1
        for i in range(len(searchWord)):
            c = searchWord[i]
            while l <= r:
                while products[l][0 : i] != searchWord[0 : i]:
                    l += 1
                while products[r][0 : i] != searchWord[0 : i]:
                    r -= 1
            
            lst = []
            lst.append(products[l : r])

            res.append(lst)

        return res