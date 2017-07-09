#! /bin/sh

for i in {1..7}; do diff <(./sastantua $i) <(./sastantua_example $i) && echo "diff$i ok."; done
