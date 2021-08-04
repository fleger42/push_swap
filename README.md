# **Push_swap:** 
## ***A 42 project... :***
## Requirement:
You must be on a Linux distribution.
## Usage:
Launch make in the repository and than use the following command:

ARG="10 2 8 7 30 3 1000" ; ./push_swap $ARG 

You can use any number you want and however many you want !

You can pipe push_swap with the checker to verify the solution:

ARG="10 2 8 7 30 3 1000" ; ./push_swap $ARG | ./checker $ARG

## Goal:

- [x] No memory leaks
- [x] Norm

The goal of this project is to make a basic sorter algorithm aswell as a checker.
# Sorter:

The sorter will be given a list of number and must sort them the fastest way.
To do so, you must obey a set of rules, you can only use specific instruction that interact with 2 piles, A and B.

At the end of the sort, the pile A must be sorted and B empty, otherwise its wrong.

Here are the commands that the sorter can use to interact with the pile A and B:

-sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

-sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

-ss : sa and sb at the same time.

-pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

-pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

-ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

-rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

-rr : ra and rb at the same time.

-rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

-rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

-rrr : rra and rrb at the same time

# checker :

The checker program will receive instruction and check if the pile A is sorted at the end and B empty. If so, he will display OK. In any other case, the program will display KO.

# Tester :

I made a tester that generate list of random number with different size and check if your push_swap and checker are working properly. To test this project you can enter the tester repository and launch ./push_swap_tester.sh (Only work on linux distribution)
## Final grade:
125/100
