#!/bin/sh
g++ -I./Library/ -I./include/ Find.cpp FegeyaFind.cpp -std=c++17 -o ffind
./ffind --h
