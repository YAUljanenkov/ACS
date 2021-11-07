#! /usr/bin/python3

import sys
import time
from container import Container

if __name__ == '__main__':
    start_time = time.time() * 1000.0
    arguments = sys.argv
    if len(arguments) != 4:
        print(f"Incorrect number of arguments: expected 2, got {len(arguments) - 1}.")
        exit(3)

    container = Container()

    if arguments[1] == '-n':
        container.random_fill(int(arguments[2]))

        with open(arguments[3], 'w') as out:
            container.print_container(out)
            container.straight_merge(out)

    elif arguments[1] == '-f':

        with open(arguments[2], 'r') as test:
            container.read_numbers(test)

        with open(arguments[3], 'w') as out:
            container.print_container(out)
            container.straight_merge(out)

    else:
        print('incorrect flag.')
        exit(3)
    print(f"Program finished working. It worked {time.time() * 1000.0 - start_time} ms.")
    input()
