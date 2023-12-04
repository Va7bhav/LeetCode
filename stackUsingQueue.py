from collections import deque
from re import X


class MyStack:

    def __init__(self):
        self.q = deque()

    def pushie(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        for i in range(len(self.q) - 1):
            element = self.q.pop()
            self.q.append(element)
        return self.q.pop()        

    def top(self) -> int:
        return self.q[-1]

    def empty(self) -> bool:
        if len(self.q) == 0:
            return True
        return False