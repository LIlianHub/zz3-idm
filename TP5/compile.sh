#!/bin/bash

CLHEP_DIR=/home/liballejos/.clhep

g++ $PWD/src/*.cpp -o TP5_BALLEJOS -I$CLHEP_DIR/include -L$CLHEP_DIR/lib -lCLHEP-Random-2.1.0.0 -static 
