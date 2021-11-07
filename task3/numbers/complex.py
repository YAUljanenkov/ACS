from . import Number
from math import hypot


class Complex(Number):
    def __init__(self, a: int, b: int):
        super().__init__(a, b)
        self.x = a
        self.y = b

    def decimal(self) -> float:
        return hypot(self.x, self.y)

    def __str__(self) -> str:
        return f'It\'s a complex number: {self.x} + {self.y}*i. It\'s distance: {self.decimal()}.'
