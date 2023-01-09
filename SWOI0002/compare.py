#!/usr/bin/env python

from cyaron import *

while True:
    print("started generating")
    test_data = IO(file_prefix="sequence")
    n=1000
    test_data.input_writeln(n)
    for j in range(0,n):
        test_data.input_write(randint(1,10**9))
    print("finished generating")
    print("started running")
    Compare.program("std.exe",input=test_data,std_program="std-f.exe")
    print("finished running")