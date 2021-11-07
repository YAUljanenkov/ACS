from . import Number


class Polar(Number):
    def __init__(self, a: int, b: int):
        super().__init__(a, b)
        self.x = a
        self.y = b

    def decimal(self) -> float:
        return self.y

    def __str__(self) -> str:
        return f'It\'s a polar number: r = {self.x}, phi = {self.y}. It\'s distance: {self.decimal()}.'
