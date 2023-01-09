#!/usr/bin/env python

from cyaron import *

for i in range(1, 11):
    print("started generating")
    test_data = IO(file_prefix="sequence", data_id=i)
    if i<=2:
        n=100
    elif i<=8:
        n=1000
    else:
        n=500000
    test_data.input_writeln(n)
    for j in range(0,n):
        test_data.input_write(randint(1,10**9))
    print("finished generating")
    print("started running")
    test_data.output_gen("std.exe")
    print("finished running")