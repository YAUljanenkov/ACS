from typing import TextIO, List
from numbers import Number, get_number, get_random_number


class Container:
    cont: List[Number]

    def __init__(self):
        self.cont = []

    def random_fill(self, n: int):
        for i in range(n):
            self.cont.append(get_random_number())

    def read_numbers(self, file: TextIO):
        n = int(file.readline())
        for i in range(n):
            new_number = get_number(file)
            if new_number:
                self.cont.append(new_number)

    def print_container(self, file: TextIO):
        file.write(f'container contains {len(self.cont)} elements.\n')
        for index, number in enumerate(self.cont):
            file.write(f'{index}: {number}\n')

    @staticmethod
    def _merge(a: List[Number], left_border: int, divider: int, right_border: int):
        left = left_border
        middle = divider + 1
        temp = []
        while left <= divider and middle <= right_border:
            if a[left].decimal() < a[middle].decimal():
                temp.append(a[left])
                left += 1
            else:
                temp.append(a[middle])
                middle += 1

        while middle < right_border:
            temp.append(a[middle])
            middle += 1

        while left <= divider:
            temp.append(a[left])
            left += 1

        for i, _ in enumerate(temp):
            a[left_border + i] = temp[i]

    @staticmethod
    def _sort(a: List[Number], left_border: int, right_border: int):
        divider: int
        if left_border < right_border:
            divider = int((left_border + right_border) / 2)
            Container._sort(a, left_border, divider)
            Container._sort(a, divider + 1, right_border)
            Container._merge(a, left_border, divider, right_border)

    def straight_merge(self, file: TextIO):
        Container._sort(self.cont, 0, len(self.cont) - 1)
        file.write('Container was sorted by straight merge sort\n')
        self.print_container(file)
