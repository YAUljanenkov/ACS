from abc import ABC


class Number(ABC):
    x: int
    y: int

    def __init__(self, a: int, b: int):
        pass

    def decimal(self) -> float:
        pass

    def __str__(self) -> str:
        pass
