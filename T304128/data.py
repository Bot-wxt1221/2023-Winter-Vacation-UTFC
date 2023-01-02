import cyaron as c
import random as r
for i in range(1,3):
     test_data = c.IO(file_prefix="b", data_id=i)
     test_data.input_writeln(r.randint(6,10),r.randint(10000,50000),r.randint(10000,50000),r.randint(10000,50000))
     test_data.output_gen("b.exe")
     test_data.close()
for i in range(3,5):
     test_data = c.IO(file_prefix="b", data_id=i)
     test_data.input_writeln(r.randint(5000,10000),r.randint(10000,50000),r.randint(10000,50000),r.randint(10000,50000))
     test_data.output_gen("b.exe")
     test_data.close()
for i in range(5,11):
     test_data = c.IO(file_prefix="b", data_id=i)
     test_data.input_writeln(r.randint(5*(10**17),10**18),r.randint(10000,50000),r.randint(10000,50000),r.randint(10000,50000))
     test_data.output_gen("b.exe")
     test_data.close()
     