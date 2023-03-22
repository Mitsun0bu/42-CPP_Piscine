#!/bin/bash

PROGRAM="./RPN"

# TEST INPUTS ARRAY
TEST_INPUTS=(
  "(1 + 1)"
  "1 2 # 3 + *"
  "1 2 3 4 *"
  "1 2 3 4 /"
  "1 2 3 + + +"
  "1 2 + 3 4"
  "4 2 0 / *"
  "0"
  "1 2 - 3 4 + *"
  "1 2 3 * /"
  "1 2 3 * + 4 -"
  "5 3 + 2 /"
  "9 3 / 2 +"
  "7 7 * 7 -"
  "8 9 * 9 - 9 - 9 - 4 - 1 +"
)

# ITERATE THROUGH TEST INPUT ARRAY AND RUN THE PROGRAM FOR EACH INPUT
i=0
for input in "${TEST_INPUTS[@]}"; do
  echo "[RUNNING]: $PROGRAM \"$input\""
  $PROGRAM "$input"
  echo -e "\n"
  ((i++))
done