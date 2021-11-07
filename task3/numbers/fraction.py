from . import Number


class Fraction(Number):
    def __init__(self, a: int, b: int):
        super().__init__(a, b)
        if b < 0:
            b *= -1
            a *= -1
        self.x = a
        self.y = b

    def decimal(self) -> float:
        return self.x / self.y

    def __str__(self) -> str:
        return f'It\'s a fraction: {self.x} / {self.y}. It\'s distance: {self.decimal()}.'
