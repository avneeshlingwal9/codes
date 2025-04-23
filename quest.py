import numpy as np

f = open('q.txt' , 'r')

lst = f.readlines()

n = len(lst)
index =  int(n*np.random.rand())
print(lst[index])



