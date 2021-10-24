from random import randint

min_int = -2**32+1
max_int = 2**32-1
for i in range(10):
    with open(f"./in/test{i}.txt", 'w') as file:
        n = randint(0, 10000)
        file.write(f"{n}\n")
        for j in range(n):
            file.write(f"{randint(1, 3)} {randint(min_int, max_int)} {randint(min_int, max_int)}\n")
