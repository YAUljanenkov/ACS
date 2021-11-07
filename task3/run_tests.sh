#!/bin/bash

chmod +x main.py
for i in {0..10}
do
  echo "test $i"
  ./main.py -f in/test"$i".txt out/test"$i".txt
  clear
done