from .number import Number
from .fraction import Fraction
from .polar import Polar
from .complex import Complex
from typing import TextIO
from random import randint


def get_number(file: TextIO) -> Number or None:
    n, x, y = map(int, file.readline().split())
    if n == 1:
        return Complex(x, y)
    elif n == 2:
        return Fraction(x, y)
    elif n == 3:
        return Polar(x, y)
    else:
        return None


def get_random_number() -> Number:
    number_type = randint(1, 3)
    min_int = -2 ** 32 + 1
    max_int = 2 ** 32 - 1
    x = randint(min_int, max_int)
    y = randint(min_int, max_int)
    if number_type == 1:
        return Complex(x, y)
    elif number_type == 2:
        return Fraction(x, y)
    elif number_type == 3:
        return Polar(x, y)
