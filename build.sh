#!/bin/bash
cpp=$1
echo $cpp
g++ $cpp -o run
./run