#!/bin/bash

PROGRAM="./PmergeMe"

# TEST INPUTS ARRAY
TEST_INPUTS=(
    # " "                     # Empty input
    # "-1"                    # Single negative element
    # "3 1 4 -1 5"            # Negative element in list
    # "3 1 4 e 5"             # Non-int element
    # "1 5 5 3 6 5 2 3 5 4000000000000000000000000" # Overflow
    # "0"                     # Single 0
    # "1"                     # Single element
    # "1 2"                   # Two elements, sorted order
    # "2 1"                   # Two elements, reversed order
    # "1 1 1 1 1"             # All same elements
    # "1 2 3 4 5"             # Sorted input
    # "5 4 3 2 1"             # Reversed input
    # "3 1 4 0 5"             # Random order, with 0
    # "3 1 4 2 5"             # Random order
    # "1 2 3 3 4 5 5 5 5 6"   # Repeated elements, sorted
    # "1 5 5 3 6 5 2 3 5 4"   # Repeated elements, unsorted
    # "1 3 5 7 9 2 4 6 8 10"  # Sorted subsequences
    "$(seq 1 100000 | sort -R | head -n 3000 | tr "\n" " ")"
)

# ITERATE THROUGH TEST INPUT ARRAY AND RUN THE PROGRAM FOR EACH INPUT
for input in "${TEST_INPUTS[@]}"; do
  echo -e "[RUNNING]\t\t\t: $PROGRAM $input"
  $PROGRAM $input

done