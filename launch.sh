#!/bin/sh
export DYLD_LIBRARY_PATH=lib/SFML-2.2/lib

make && ./Client $*


