*This project has been created as part of the 42 curriculum by ahmounsi*

# Description

## Problem:
Having two stacks, Stack_A, and Stack_B, with A containing random integer values.
and using the following moves:


- **sa (swap a) :**
    Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one element or none.

- **sb (swap b  :**
    Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one element or none.

- **ss:**
     sa and sb at the same time.

- **pa (push a) :**
    Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.

- **pb (push b) :**
    Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.

- **ra (rotate a):**
    Shift up all elements of stack a by 1.
    The first element becomes the last one.
- **rb (rotate b):**
    Shift up all elements of stack b by 1.
    The first element becomes the last one.
- **rr :**
    ra and rb at the same time.
- **rra (reverse rotate a):**
     Shift down all elements of stack a by 1.
    The last element becomes the first one.
- **rrb (reverse rotate b):**
     Shift down all elements of stack b by 1.
    The last element becomes the first one.
- **rrr :**
     rra and rrb at the same time

## Goal:
We need to use the least possible moves count to sort stack A
in a descending order (small to big).

The push_swap program job is to calculate and output those least amount of moves.
## The Turk Algo:
This algo is all about keeping track of the cost of move, then picking the cheapest.

First, we push all element in stack `a` to `b` (leaving 3 elements, or less if no more than 3 exists)

For each element in `b`, find its duo in stack `a` (the target), to move them both to the 
top end (or bottom end for stack `a`), possibly oposite directions too, then `pa`

The target is the smallest element in stack `a` which remains bigger than the one being proccessed for in stack `b`

example:
```
|       | .     | 8     | 1     |
| 1     | 9     | 9     | 3     |
| 3     | 1     | 1     | 7     |
| 7<    | 3     | 3     | 8     |
| 9   6 | 7<  8 | 7     | 9     |
_________________________________
| a - b | a - b | a - b | a - b |
```

We do that for every element in `b` ending up with stack `a` sorted

The cost of each element is saved in every recursion call of each node in stack b
using the following struct:
```c
typedef struct  s_cheapest
{
	size_t			index;
	size_t			cost;
	short			applied;
}		t_cheapest;
```
Where `index` is the stack_b element under calculation proccess to count the `cost`, then apply the neccesary instructions and marking them as `applied`

# Instructions

### 1 - run `make` or `make clean`

### 2 - inpu a series of numbers, you can use:
```
shuf -i 1-500 -n 500 | tr "\n" " "
```
or
```
seq -250 250 | shuf -n 500 | tr "\n" " "
```
### 3 - pass it to push_swap binary
```
./push_swap `seq -250 250 | shuf -n 500 | tr "\n" " "`
```
or
```
arg=`seq -250 250 | shuf -n 500 | tr "\n" " "` && ./push_swap $arg
```
### 4 - examine the instructinos with 42's checker
```
arg=`seq -250 250 | shuf -n 500 | tr "\n" " "` && ./push_swap $arg | ./checker $arg
```

# Resources
to learn about array of pointers to functions
- https://learn.microsoft.com/en-us/troubleshoot/developer/visualstudio/cpp/language-compilers/declare-pointers-to-functions

to learn about turk algo
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- https://github.com/alx-sch/push_swap

Proudly, No AI has been used to raise this project, heh.
