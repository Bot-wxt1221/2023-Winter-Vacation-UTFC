import cyaron as c
import random as r
for i in range(1,3):
     test_data = c.IO(file_prefix="e", data_id=i)
     n=r.randint(5,10)
     m=10
     test_data.input_writeln(n,m)
     graph = c.Graph.graph(n, m,self_loop=True, repeated_edges=False)
     for j in range(n-1):
         test_data.input_write(r.randint(1,100))
     test_data.input_writeln(r.randint(1,100))
     test_data.input_writeln(graph.to_str(shuffle=True,output=c.Edge.unweighted_edge))
     test_data.output_gen("e.exe")
     test_data.close()
for i in range(3,5):
     test_data = c.IO(file_prefix="e", data_id=i)
     n=r.randint(2000,5000)
     m=5000
     test_data.input_writeln(n,m)
     graph = c.Graph.graph(n, m,self_loop=True, repeated_edges=False)
     for j in range(n-1):
         test_data.input_write(r.randint(1,100))
     test_data.input_writeln(r.randint(1,100))
     test_data.input_writeln(graph.to_str(shuffle=True,output=c.Edge.unweighted_edge))
     test_data.output_gen("e.exe")
     test_data.close()
for i in range(5,11):
     test_data = c.IO(file_prefix="e", data_id=i)
     n=r.randint(5*(10**3),10**4)
     m=10**6
     test_data.input_writeln(n,m)
     graph = c.Graph.graph(n, m,self_loop=True, repeated_edges=False)
     for j in range(n-1):
         test_data.input_write(r.randint(1,100))
     test_data.input_writeln(r.randint(1,100))
     test_data.input_writeln(graph.to_str(shuffle=True,output=c.Edge.unweighted_edge))
     print("ok")
     test_data.output_gen("e.exe")
     test_data.close()
