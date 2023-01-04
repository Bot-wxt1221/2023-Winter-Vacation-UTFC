import cyaron as c
import random as r
for i in range(1,11):
    test_data = c.IO(file_prefix="f", data_id=i)
    n=r.randint(5*(10**5),10**6)
    test_data.input_writeln(n,r.randint(100,3000))
    for i in range(n):
        a=r.randint(1,25)*10
        b=r.randint(1,25)*10
        cc=(a*b)//100
        test_data.input_writeln(a,b,cc)
    test_data.output_gen("a.exe")
    test_data.close()
