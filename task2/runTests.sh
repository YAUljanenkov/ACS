#!/bin/bash

for i in {0..10}
do
  echo "test $i"
  ./cmake-build-debug/ACS_task_2 in/test"$i".txt out/test"$i".txt
  clear
done