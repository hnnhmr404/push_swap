*This project has been created as part of the 42 curriculum by hbinti-d.*

# push_swap

## Description

Push_swap is a sorting algorithm project that sort a list of integers using two stacks and a limited set of operations, while producing the smallest possible number of moves.

The program receives a list of integers as arguments and outputs a sequence of valid operations that sorts the numbers in ascending order.

To achieve efficiency, different strategies are used depending on the size of the input:
- Small datasets (≤ 5 numbers) are sorted with optimized hard-coded logic, based on indexed values to maintain order.
- Large datasets are sorted using a chunk based algorithm.The stack is divided into ranges (chunks) of indexed values. Elements are pushed from stack `a` to stack `b`, and then carefully repositioned back into `a` in sorted order

The project focuses on:
- Algorithmic optimization
- Memory management
- Error handling

## Instructions

### Compilation

Compile the project using:
```shell
make
```

Recompile the project using:
```shell
make re
```

Compile the bonus checker program using:
```shell
make bonus
```

Remove object files (while keeping the compiled project) using:
```shell
make clean
```

Remove all build files (including the compiled project) using:
```shell
make fclean
```

### Usage

Run the program with a list of integers.
For example:
```shell
./push_swap 2 1 3
```

Run the program to count the number of operations used to sort the numbers.
For example:
```shell
ARG="2 1 0"; ./push_swap $ARG | wc -l
```
or
```shell
./push_swap 2 1 0 | wc -l
```

Verify correctness using the provided checker.
For example:
```shell
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
```

Run the program with 100 random number:
```shell
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG
```

## Resources

- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e (Push_Swap Tutorial by Leo Fu)
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a (Push_Swap: The least amount of moves with two stacks)
- https://visualgo.net/en/sorting (visualiser)
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

## Use of AI

AI assistance was used strictly as a learning and debugging tool, not for generating complete solutions.

It was used for:
- Clarifying algorithmic concepts such as chunk-based sorting strategies
- Debugging compilation errors and understanding compiler messages
- Reviewing function prototypes and C syntax issues
- Discussing optimization strategies for large datasets (100 and 500 numbers)
All algorithm design decisions, implementation logic, and final code structure were written, tested, and understood independently.
