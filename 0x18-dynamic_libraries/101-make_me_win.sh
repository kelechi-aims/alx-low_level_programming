#!/bin/bash
wget -P /tmp https://raw.github.com/kelechi-aims/alx-low_level_programming/master/0x18-dynamic_libraries/random_nums.so
export LD_PRELOAD=/tmp/random_nums.so
