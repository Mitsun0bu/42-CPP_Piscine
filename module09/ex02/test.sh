#!/bin/bash

PROGRAM="./PmergeMe"

# TEST INPUTS ARRAY
TEST_INPUTS=(
    "1"                     # Single element
    "1 2"                   # Two elements, sorted order
    "2 1"                   # Two elements, reversed order
    "1 1 1 1 1"             # All same elements
    "1 2 3 4 5"             # Sorted input
    "5 4 3 2 1"             # Reversed input
    "3 1 4 2 5"             # Random order
    "1 2 3 3 4 5 5 5 5 6"   # Repeated elements, sorted
    "1 5 5 3 6 5 2 3 5 4"   # Repeated elements, unsorted
    "1 3 5 7 9 2 4 6 8 10"  # Sorted subsequences
    # $(seq 1 100000 | sort -R | head -n 3000 | tr "\n" " ")
)

# ITERATE THROUGH TEST INPUT ARRAY AND RUN THE PROGRAM FOR EACH INPUT
for input in "${TEST_INPUTS[@]}"; do
  echo "[RUNNING]: $PROGRAM $input"
  $PROGRAM $input
  echo -e "\n"
done