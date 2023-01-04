import cyaron as c
import random as r
for i in range(1,11):
    test_data = c.IO(file_prefix="f", data_id=i)
    n=r.randint(5*(10**1),10**2)
    test_data.input_writeln(n,r.randint(1,1))
    for i in range(n):
        a=r.randint(9,11)*10
        b=r.randint(9,10)*10
        cc=(a*b)//100
        test_data.input_writeln(a,b,cc)
    test_data.output_gen("a.exe")
    test_data.close()
