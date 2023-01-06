import cyaron as c
import random as r

for i in range(3,5):
     test_data = c.IO(file_prefix="b", data_id=i)
     n=r.randint(900,1000)
     m=r.randint(900,1000)
     test_data.input_writeln(n,m)
     for j in range(n):
         test_data.input_write(r.randint(-10**2,10**2))
     for j in range(m):
         l=r.randint(1,10)
         rr=r.randint(l,10)
         test_data.input_writeln(l,rr)
     test_data.input_writeln()
     test_data.output_gen("a.exe")
     test_data.close()
