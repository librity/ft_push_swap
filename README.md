<h3 align="center">42 São Paulo - push_swap</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_push_swap?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_push_swap?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_push_swap?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_push_swap?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_push_swap?color=orange)

</div>

<div align="center">

[![Build](https://github.com/librity/ft_push_swap/actions/workflows/build.yml/badge.svg)](https://github.com/librity/ft_push_swap/actions/workflows/build.yml)
[![Norminette v3](https://github.com/librity/ft_push_swap/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_push_swap/actions/workflows/norminette_v3.yml)

</div>

<p align="center"> An exercise on Sorting Algorithms and Efficiency in pure C.
  <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Checklist](#checklist)
- [Getting Started](#getting_started)
- [Notes](#notes)
- [42 São Paulo](#ft_sp)
- [Resources](#resources)

## 🧐 About <a name = "about"></a>

### Sorter

This program that takes a list of `int`s as arguments:

```bash
$ ./push_swap 7 1 8 9 4 2 6 5 3
```

Parses them into `stack a`:

```elixir
|A: (top) 7 1 8 9 4 2 6 5 3 (bottom)|
|B: (top) (bottom)|
```

Then sorts them with `stack b` and the operations:

- `sa` (swap a): Swap the first 2 elements at the top of `stack a`:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
sa
|A: (top) 6 2 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
```

- `sb` (swap b): Swap the first 2 elements at the top of `stack b`:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
sb
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 1 7 8 9 4 (bottom)|
```

- `ss` : `sa` and `sb` at the same time:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
sb
|A: (top) 6 2 5 3 (bottom)|
|B: (top) 1 7 8 9 4 (bottom)|
```

- `pa` (push a): Take the first element at the top of b and put it at the top of a:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
pa
|A: (top) 7 2 6 5 3 (bottom)|
|B: (top) 1 8 9 4 (bottom)|
```

- `pb` (push b): Take the first element at the top of a and put it at the top of b:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
pa
|A: (top) 6 5 3 (bottom)|
|B: (top) 2 7 1 8 9 4 (bottom)|
```

- `ra` (rotate a): The first element becomes the last one:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
ra
|A: (top) 6 5 3 2 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
```

- `rb` (rotate b): The first element becomes the last one:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
rb
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 1 8 9 4 7 (bottom)|
```

- `rr` : `ra` and `rb` at the same time:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
rr
|A: (top) 6 5 3 2 (bottom)|
|B: (top) 1 8 9 4 7 (bottom)|
```

- `rra` (reverse rotate a): The last element becomes the first one:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
rra
|A: (top) 3 2 6 5 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
```

- `rrb` (reverse rotate b): The last element becomes the first one:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|

|A: (top) 2 6 5 3 (bottom)|
|B: (top) 4 7 1 8 9 (bottom)|
```

- `rrr` : `rra` and `rrb` at the same time:

```elixir
|A: (top) 2 6 5 3 (bottom)|
|B: (top) 7 1 8 9 4 (bottom)|
rrr
|A: (top) 3 2 6 5 (bottom)|
|B: (top) 4 7 1 8 9 (bottom)|
```

`stack a` must be sorted from smallest to largest:

```elixir
|A: (top) 0 1 2 3 4 5 6 7 8 (bottom)|
|B: (top) (bottom)|
Is sorted: YES
```

The more operations it takes to sort, the lower your grade.

I enjoyed the project and learned a lot about doubly linked lists,
sorting algorithms and optimizations.
I especially liked the optimization aspect of it:
it's not as easy as implementing some random sorting algorithm
with a good average performance when
[the cost of swapping two arbitrary numbers is so high](./sources/mandatory/sorters/quick.c).
The limitation of the stack and it's operations challenge you to
think outside the box and understand the entire workflow of your solutions.

### Checker

The checker program takes a list of `int`s as arguments and
a list of operations from `STDIN`.
It then executes all operations and checks if it properly sorts the stack:

```bash
$ ./checker 3 2 1 0
sa
rra
pb
KO
```

```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

## ✅ Checklist <a name = "checklist"></a>

### Mandatory

- [x] DON'T TURN IN LIBS AS SUBMODULES
- [x] MAKEFILE EXPLICIT SOURCE FILES (`echo M_SOURCES`)
- [x] Make must compile without relinking
  - [x] SHOOULDNT RECOMPILE/REARCHIVE OBJECTS WITH MAKE ALL
- [x] `.linux` file (42 Workspaces)
- [x] Test in workspaces
- [x] Follows `norminette 3.3.51`
- [x] Turn in `Makefile`, `*.h`, `*.c` , `.linux` , `.gitignore`
- [x] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [x] Program name `push_swap`
- [x] Compiles with `-Wall -Wextra -Werror`
- [x] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [x] All allocated heap memory properly freed, no memory leaks.
  - [x] Check memory leaks with `valgrind`
- [x] Allowed functions:
  - [x] `read`, `write`, `malloc`, `free`, `exit`
  - [x] `libft` allowed
  - [x] Your `ft_printf` (may be modified)
    - [x] No `printf` from `stdio.h`
- [x] Handle arguments `list of integers`
  - [x] If no arguments are specified (`argc == 1`) then exits with `EXIT_SUCCESS`
  - [x] If arguments aren’t all `int` then exits with `"Error\n"` to `STDERR_FILENO`
  - [x] If any argument is bigger than **`INT_MAX`** then exits with `"Error\n"` to `STDERR_FILENO`
  - [x] If any argument is smaller than **`INT_MIN`** then exits with `"Error\n"` to `STDERR_FILENO`
  - [x] If any argument is a duplicate then exits with `"Error\n"` to `STDERR_FILENO`
- [x] Implement stack `a` and `b`
- [x] Implement all operations
  - [x] `sa` (swap a): Swap the first 2 elements at the top of `stack a`. Do nothing if there is only one or no elements.
  - [x] `sb` (swap b): Swap the first 2 elements at the top of `stack b`. Do nothing if there is only one or no elements.
  - [x] `ss` : `sa` and `sb` at the same time.
  - [x] `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - [x] `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty
  - [x] `ra` (rotate a): Shift up all elements of `stack a` by 1. The first element becomes the last one.
  - [x] `rb` (rotate b): Shift up all elements of `stack b` by 1. The first element becomes the last one.
  - [x] `rr` : `ra` and `rb` at the same time.
  - [x] `rra` (reverse rotate a): Shift down all elements of `stack a` by 1. The last element becomes the first one.
  - [x] `rrb` (reverse rotate b): Shift down all elements of `stack b` by 1. The last element becomes the first one.
  - [x] `rrr` : `rra` and `rrb` at the same time.
- [x] Print the list of instructions separated by `'\n'` to `STDOUT_FILENO`
- [x] Implement radix sort for 84% score.
- [x] Implement best rotation sort for 100% score.
- [x] Pass all testers
  - [x] [https://github.com/laisarena/push_swap_tester](https://github.com/laisarena/push_swap_tester)
  - [x] [https://github.com/lmalki-h/push_swap_tester](https://github.com/lmalki-h/push_swap_tester)
  - [x] [https://github.com/minckim42/push_swap_tester](https://github.com/minckim42/push_swap_tester)
  - [x] [https://github.com/wwwwelton/push_swap/blob/master/tester.sh](https://github.com/wwwwelton/push_swap/blob/master/tester.sh)
  - [x] [https://github.com/VBrazhnik/Push_swap/blob/master/benchmark.sh](https://github.com/VBrazhnik/Push_swap/blob/master/benchmark.sh)

### Bonus

- [x] Create a checker program
  - [x] Takes the `stack a`s `argv`
  - [x] If the stack has any problem then exits with `"Error\n"` to `STDERR_FILENO`
  - [x] Takes the operations from `STDIN` up to `EOF` (`Ctrl+D`) and saves them to a linked list.
  - [x] If the operations have any problem then exits with `"Error\n"` to `STDERR_FILENO`
  - [x] If the operations sort the stack then exits with `"OK\n"` to `STDOUT_FILENO`
  - [x] If the operations doesn’t sort the stack then exits with `"KO\n"` to `STDOUT_FILENO`

## 🏁 Getting Started <a name = "getting_started"></a>

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone --recurse-submodules https://github.com/librity/ft_push_swap.git
$ cd ft_push_swap
$ make
```

### Sorter

You give it a list of integers and it prints the sorting instructions to `STDOUT`:

```bash
$ ./push_swap 7 1 8 9
ra
pb
rra
pa
```

You can also [compile it with `verbose` mode](./sources/mandatory/control/core.c) for more details:

```elixir
$ ./push_swap 7 1 8 9
|A: (top) 7 1 8 9 (bottom)|
|B: (top) (bottom)|
Is sorted: NO

NORMALIZED STACK
|A: (top) 1 0 2 3 (bottom)|
|B: (top) (bottom)|
Is sorted: NO

ra
|A: (top) 0 2 3 1 (bottom)|
|B: (top) (bottom)|
Is sorted: NO

pb
|A: (top) 2 3 1 (bottom)|
|B: (top) 0 (bottom)|
Is sorted: NO

rra
|A: (top) 1 2 3 (bottom)|
|B: (top) 0 (bottom)|
Is sorted: NO

pa
|A: (top) 0 1 2 3 (bottom)|
|B: (top) (bottom)|
Is sorted: YES
```

For more examples see the tester script:

```bash
$ ./scripts/run_bonus.sh
```

## 📝 Notes <a name = "notes"></a>

I implemented [many](./sources/mandatory/sorters)
[sorting](./sources/mandatory/insertion)
[algorithms](./sources/mandatory/best_rotation)
before I could reach a good enough solution for a full grade.

Due to the nature of this problem
something like insertion sort with chunks is one of the best options.
The [final sorter](./sources/mandatory/best_rotation) sends all
elements to `stack b` by group/chunk, so the biggest are at the top
and the smallest are at the bottom.
They're not completely sorted but they're roughly were they need to be.

It then pushes all the numbers back to `stack a`
while maintaining `stack a` in order.
That means we need to rotate some number to the top of `stack b`
and then rotate the greatest closest number to it to the top of `stack a`.
It finds the number of `stack b` that will take the least amount of rotations
before pushing it to `stack a`,
then executes that rotation and pushes it.

Calculating the rotations is [pretty straight forward](./sources/mandatory/best_rotation/set_rotations.c):

- The number of normal rotations (`ra` and `rb`) is the index of the number.
- The number of reverse rotations (`rra` and `rrb`) is the size of the stack minus the index.
- If we're doing the same type of rotation on both stacks we can optimize it further with `rr` and `rrr`.
- The total number of operations is the sum of all the rotations.

With a few while loops we can find the best rotation for each number,
and then find the best rotation for all numbers.

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>

### Linked Lists

- [https://visualgo.net/en/list](https://visualgo.net/en/list)
- [https://www.geeksforgeeks.org/linked-list-set-1-introduction/](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- [https://www.geeksforgeeks.org/circular-linked-list/](https://www.geeksforgeeks.org/circular-linked-list/)
- [https://www.geeksforgeeks.org/doubly-linked-list/](https://www.geeksforgeeks.org/doubly-linked-list/)
- [https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/](https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/)
- [https://www.geeksforgeeks.org/move-first-element-to-end-of-a-given-linked-list/](https://www.geeksforgeeks.org/move-first-element-to-end-of-a-given-linked-list/)
- [https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/](https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/)

### Stacks

- [https://wikiless.org/wiki/Stack\_(abstract_data_type)?lang=en](<https://wikiless.org/wiki/Stack_(abstract_data_type)?lang=en>)
- [https://www.geeksforgeeks.org/stack-data-structure/?ref=lbp](https://www.geeksforgeeks.org/stack-data-structure/?ref=lbp)

### Tutorials

- [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [https://docs.google.com/presentation/d/1c2PU6ZST7uMwNHl6aAz2WsJ5QFf1J7JJsMkW0VSTXc8/edit#slide=id.gc7df47266a_0_336](https://docs.google.com/presentation/d/1c2PU6ZST7uMwNHl6aAz2WsJ5QFf1J7JJsMkW0VSTXc8/edit#slide=id.gc7df47266a_0_336)
- [https://42born2code.slack.com/?redir=%2Farchives%2FC3QG85SG6%2Fp1629127318173200%3Fthread_ts%3D1629126645.172700%26cid%3DC3QG85SG6](https://42born2code.slack.com/?redir=%2Farchives%2FC3QG85SG6%2Fp1629127318173200%3Fthread_ts%3D1629126645.172700%26cid%3DC3QG85SG6)
- [https://github.com/VBrazhnik/Push_swap/wiki/Algorithm](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm)
- [https://github.com/LeoFu9487/push_swap_tutorial](https://github.com/LeoFu9487/push_swap_tutorial)

### Sorting Algorithms

- [https://visualgo.net/en/sorting](https://visualgo.net/en/sorting)
- [https://www.geeksforgeeks.org/sorting-algorithms/](https://www.geeksforgeeks.org/sorting-algorithms/)
- [https://www.crio.do/blog/top-10-sorting-algorithms/](https://www.crio.do/blog/top-10-sorting-algorithms/)
- [https://cs.stackexchange.com/questions/18536/what-is-a-the-fastest-sorting-algorithm-for-an-array-of-integers](https://cs.stackexchange.com/questions/18536/what-is-a-the-fastest-sorting-algorithm-for-an-array-of-integers)
- [https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- [https://www.toptal.com/developers/sorting-algorithms](https://www.toptal.com/developers/sorting-algorithms)
- [https://github.com/cjbt/Free-Algorithm-Books/blob/master/book/Grokking Algorithms - An illustrated guide for programmers and other curious people.pdf](https://github.com/cjbt/Free-Algorithm-Books/blob/master/book/Grokking%20Algorithms%20-%20An%20illustrated%20guide%20for%20programmers%20and%20other%20curious%20people.pdf)
- [https://pastebin.com/s6nn85KZ](https://pastebin.com/s6nn85KZ)
- https://en.wikipedia.org/wiki/Sorting_algorithm
- https://en.wikipedia.org/wiki/Quicksort
- https://en.wikipedia.org/wiki/Block_sort
- https://github.com/vbohush/SortingAlgorithmAnimations
- https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples
- https://github.com/cdmh/sorting_algorithms
- https://github.com/ismdeep/sort-algos-c
- https://www.sanfoundry.com/c-program-sort-array-ascending-order/
- https://www.dummies.com/programming/c/how-to-sort-arrays-in-c-programming/
- https://www.geeksforgeeks.org/c-program-to-sort-an-array-in-ascending-order/
- https://stackoverflow.com/questions/3893937/sorting-an-array-in-c
- https://www.edureka.co/blog/sorting-algorithms-in-c/
- https://codeforwin.org/2015/07/c-program-to-sort-array-in-ascending-order.html
- https://www.educba.com/sorting-in-c/
- http://www.firmcodes.com/sorting-algorithms-in-c/
- https://www.tutorialride.com/c-programming/sorting-in-c-programming.htm
- https://stackoverflow.com/questions/22186423/array-of-random-numbers-using-c-program

### Quick Sort

- [https://joaoarthurbm.github.io/eda/posts/quick-sort/](https://joaoarthurbm.github.io/eda/posts/quick-sort/)

### Radix Sort

- [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort)
- [https://www.geeksforgeeks.org/radix-sort/](https://www.geeksforgeeks.org/radix-sort/)

### **`INT_MIN` &** **`INT_MAX`**

- [https://www.geeksforgeeks.org/int_max-int_min-cc-applications/](https://www.geeksforgeeks.org/int_max-int_min-cc-applications/)
- [https://en.cppreference.com/w/c/types/limits](https://en.cppreference.com/w/c/types/limits)

```c
Value of INT_MAX is +2147483647.
Value of INT_MIN is -2147483648.
```

### `STDERR_FILENO`

- [https://www.cyberciti.biz/faq/how-to-redirect-output-and-errors-to-devnull/](https://www.cyberciti.biz/faq/how-to-redirect-output-and-errors-to-devnull/)

```bash
./push_swap > /dev/null 2>&1
./push_swap 1 2 3 > /dev/null 2>&1
./push_swap &> /dev/null
./push_swap 1 2 3 &> /dev/null

./push_swap 1 2 3 >stdout 2>stderr
./push_swap 3 14 -41 >stdout 2>stderr
```

### Testers

- [https://github.com/LeoFu9487/push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)
- [https://github.com/lmalki-h/push_swap_tester](https://github.com/lmalki-h/push_swap_tester)
- [https://github.com/laisarena/push_swap_tester](https://github.com/laisarena/push_swap_tester)
- [https://github.com/minckim42/push_swap_tester](https://github.com/minckim42/push_swap_tester)
- [https://github.com/wwwwelton/push_swap/blob/master/tester.sh](https://github.com/wwwwelton/push_swap/blob/master/tester.sh)
- [https://github.com/VBrazhnik/Push_swap/blob/master/benchmark.sh](https://github.com/VBrazhnik/Push_swap/blob/master/benchmark.sh)

### Visualizers

- [https://github.com/o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [https://github.com/elijahkash/push_swap_gui](https://github.com/elijahkash/push_swap_gui)
- [https://github.com/o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [https://phemsi-a.itch.io/push-swap](https://phemsi-a.itch.io/push-swap)

### Random Numbers

- [https://randomnumbergenerator.org/](https://randomnumbergenerator.org/)
- https://stackoverflow.com/questions/35613298/implicit-declaration-of-functions-srand-rand-and-system
- https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
- [https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c](https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c)
- [https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

```bash
LIST=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $LIST | ./checker_linux $LIST
LIST=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $LIST | wc -l
```

### Pseudo Random Number Generator

- [https://en.wikipedia.org/wiki/Linear-feedback_shift_register](https://en.wikipedia.org/wiki/Linear-feedback_shift_register)
- [https://stackoverflow.com/questions/7602919/how-do-i-generate-random-numbers-without-rand-function](https://stackoverflow.com/questions/7602919/how-do-i-generate-random-numbers-without-rand-function)
- [https://www.quora.com/How-do-I-generate-random-numbers-in-certain-range-without-using-rand-function-in-C](https://www.quora.com/How-do-I-generate-random-numbers-in-certain-range-without-using-rand-function-in-C)

### `scp`

- [https://stackoverflow.com/questions/11304895/how-do-i-copy-a-folder-from-remote-to-local-using-scp](https://stackoverflow.com/questions/11304895/how-do-i-copy-a-folder-from-remote-to-local-using-scp)

```bash
cheat scp
scp -r -P 31280 coder@codeserver.42sp.org.br:~/path/to/folder ~/path/to/destination
```

### `lalloc` - Listed Memory Allocation

A linked list in the control structure with all the allocated memory pointers.
The interface function `ft_lalloc` allocates memory and adds the pointer to the list.
The interface function `ft_free_lalloc` frees all pointers and the list.

### Git `submodule`

- `git clone --recurse-submodule REMOTE_REPO`
- `git submodule add REMOTE_REPO PATH`
- `git submodule foreach git pull`
- `git submodule update --init --recursive`
- [https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git](https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git)
- [https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions](https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions)
- [https://stackoverflow.com/questions/50254184/git-submodule-and-fetch](https://stackoverflow.com/questions/50254184/git-submodule-and-fetch)
- [https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html](https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html)
- [https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982](https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982)
- [https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits](https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits)

### Git Quirks

- [https://stackoverflow.com/questions/1125476/retrieve-a-single-file-from-a-repository](https://stackoverflow.com/questions/1125476/retrieve-a-single-file-from-a-repository)

### GDB Quirks

- [https://github.com/diegopatas/42-cheatsheet/blob/main/GDB_cheatsheet.md](https://github.com/diegopatas/42-cheatsheet/blob/main/GDB_cheatsheet.md)

### VSCode

- [https://code.visualstudio.com/docs/editor/debugging](https://code.visualstudio.com/docs/editor/debugging)
- [https://code.visualstudio.com/docs/editor/tasks](https://code.visualstudio.com/docs/editor/tasks)

### C quirks

- [https://stackoverflow.com/questions/48687315/warning-ignoring-return-value-of-write-declared-with-attribute-warn-unused-r](https://stackoverflow.com/questions/48687315/warning-ignoring-return-value-of-write-declared-with-attribute-warn-unused-r)
- [https://stackoverflow.com/questions/36645660/why-cant-i-cast-a-function-pointer-to-void](https://stackoverflow.com/questions/36645660/why-cant-i-cast-a-function-pointer-to-void)
- [https://stackoverflow.com/questions/689677/why-cast-unused-return-values-to-void](https://stackoverflow.com/questions/689677/why-cast-unused-return-values-to-void)
- [https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c)
- [https://stackoverflow.com/questions/3530771/passing-variable-arguments-to-another-function-that-accepts-a-variable-argument](https://stackoverflow.com/questions/3530771/passing-variable-arguments-to-another-function-that-accepts-a-variable-argument)
- [https://en.wikipedia.org/wiki/Stack_overflow](https://en.wikipedia.org/wiki/Stack_overflow)

### C Function Pointers

- [https://stackoverflow.com/questions/25671410/function-that-returns-a-function-pointer-syntax](https://stackoverflow.com/questions/25671410/function-that-returns-a-function-pointer-syntax)

```c
float (*function_name(unsigned id))(float value) {}

void (*function_name(char *operation))(void) {}
typedef void	(*t_name_cb)(void);
t_name_cb	function_name(char *operation)
```

### Make Quirks

- [https://stackoverflow.com/questions/2019989/how-to-assign-the-output-of-a-command-to-a-makefile-variable](https://stackoverflow.com/questions/2019989/how-to-assign-the-output-of-a-command-to-a-makefile-variable)

### Bash Quirks

- [https://stackoverflow.com/questions/11027679/capture-stdout-and-stderr-into-different-variables](https://stackoverflow.com/questions/11027679/capture-stdout-and-stderr-into-different-variables)
- [https://unix.stackexchange.com/questions/444935/execute-command-and-store-everything-to-variable-in-bash](https://unix.stackexchange.com/questions/444935/execute-command-and-store-everything-to-variable-in-bash)
- [https://www.cyberciti.biz/faq/bash-for-loop/](https://www.cyberciti.biz/faq/bash-for-loop/)
- [https://stackoverflow.com/questions/4651437/how-do-i-set-a-variable-to-the-output-of-a-command-in-bash](https://stackoverflow.com/questions/4651437/how-do-i-set-a-variable-to-the-output-of-a-command-in-bash)
- [https://stackoverflow.com/questions/525592/find-and-replace-inside-a-text-file-from-a-bash-command](https://stackoverflow.com/questions/525592/find-and-replace-inside-a-text-file-from-a-bash-command)

### Send `EOF` to `STDIN`

- [https://unix.stackexchange.com/questions/16333/how-to-signal-the-end-of-stdin-input](https://unix.stackexchange.com/questions/16333/how-to-signal-the-end-of-stdin-input)
- `Ctrl+D`

### SSH Key Fingerprint

- [https://stackoverflow.com/questions/9607295/calculate-rsa-key-fingerprint](https://stackoverflow.com/questions/9607295/calculate-rsa-key-fingerprint)

### Videos

- [https://invidious.weblibre.org/watch?v=Ee0HzlnIYWQ&ab_channel=freeCodeCamp.org](https://invidious.weblibre.org/watch?v=Ee0HzlnIYWQ&ab_channel=freeCodeCamp.org)
- [https://invidious.weblibre.org/watch?v=kPRA0W1kECg](https://invidious.weblibre.org/watch?v=kPRA0W1kECg)
- [https://invidious.weblibre.org/watch?v=Lb_1R6JGD6o&ab_channel=ComputaçãocomProf.Foleis](https://invidious.weblibre.org/watch?v=Lb_1R6JGD6o&ab_channel=Computa%C3%A7%C3%A3ocomProf.Foleis)
- [https://invidious.weblibre.org/watch?v=t5NszbIerYc](https://invidious.weblibre.org/watch?v=t5NszbIerYc)
- [https://invidious.weblibre.org/watch?v=XaqR3G_NVoo&t=6s](https://invidious.weblibre.org/watch?v=XaqR3G_NVoo&t=6s)
- [https://invidious.weblibre.org/watch?v=lyZQPjUT5B4](https://invidious.weblibre.org/watch?v=lyZQPjUT5B4)
- [https://invidious.weblibre.org/watch?v=7KW59UO55TQ](https://invidious.weblibre.org/watch?v=7KW59UO55TQ)
- https://www.youtube.com/watch?v=ZZuD6iUe3Pc
