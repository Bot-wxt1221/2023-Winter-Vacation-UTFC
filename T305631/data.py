import cyaron as c
import random as r
for i in range(1,3):
     test_data = c.IO(file_prefix="b", data_id=i)
     n=r.randint(90,100)
     m=r.randint(90,100)
     test_data.input_writeln(n,m)
     for j in range(n):
         test_data.input_write(r.randint(-10**2,10**2))
     for j in range(m):
         l=r.randint(1,n)
         rr=r.randint(l,n)
         test_data.input_writeln(l,rr)
     test_data.input_writeln()
     test_data.output_gen("a.exe")
     test_data.close()
for i in range(3,5):
     test_data = c.IO(file_prefix="b", data_id=i)
     n=r.randint(900,1000)
     m=r.randint(900,1000)
     test_data.input_writeln(n,m)
     for j in range(n):
         test_data.input_write(r.randint(-10**2,10**2))
     for j in range(m):
         l=r.randint(1,n)
         rr=r.randint(l,n)
         test_data.input_writeln(l,rr)
     test_data.input_writeln()
     test_data.output_gen("a.exe")
     test_data.close()
for i in range(5,11):
     test_data = c.IO(file_prefix="b", data_id=i)
     n=r.randint(9*(10**5),10**6)
     m=r.randint(9*(10**4),10**5)
     test_data.input_writeln(n,m)
     for j in range(n):
         test_data.input_write(r.randint(-10**2,10**2))
     for j in range(m):
         l=r.randint(1,n)
         rr=r.randint(l,n)
         test_data.input_writeln(l,rr)
     test_data.input_writeln()
     test_data.output_gen("a.exe")
     test_data.close()
     
