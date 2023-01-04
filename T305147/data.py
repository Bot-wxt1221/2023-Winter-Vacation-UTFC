import cyaron as c
import random as r
for i in range(1,4):
    test_data = c.IO(file_prefix="f", data_id=i)
    n=r.randint(30,50)
    m=r.randint(30,50)
    test_data.input_writeln(n,m)
    for i in range(m):
        l=r.randint(1,50)
        rr=r.randint(1,50)
        if(l>rr):
            temp=l
            l=rr
            rr=temp
        test_data.input_writeln(l,rr,r.randint(1,10),r.randint(1,50))
    test_data.output_gen("a.exe")
    test_data.close()
for i in range(4,11):
    test_data = c.IO(file_prefix="f", data_id=i)
    n=r.randint(5*(10**5),10**6)
    m=r.randint(5*(10**5),10**6)
    test_data.input_writeln(n,m)
    for i in range(m):
        l=r.randint(1,50)
        rr=r.randint(1,50)
        if(l>rr):
            temp=l
            l=rr
            rr=temp
        test_data.input_writeln(l,rr,r.randint(1,50),r.randint(1,5))
    test_data.output_gen("a.exe")
    test_data.close()
