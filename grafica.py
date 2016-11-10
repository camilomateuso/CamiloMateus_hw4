
# coding: utf-8

# In[1]:

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
i=0
lines= open('datos.dat').readlines()
potencial = []
Ex = []
Ey=[]
while(i<len(lines)):
    a = lines[i].split(' ')
    potencial.append(a[0].rstrip('\n'))
    Ex.append(a[1].rstrip('\n'))
    Ey.append(a[2].rstrip('\n'))
    i+=1

potencialFinal = np.zeros(shape =(250,250))
ExFinal=np.zeros(shape =(250,250))
EyFinal=np.zeros(shape =(250,250))
i=0

while(i<250):
    j=0
    while(j<250):
        potencialFinal[i,j] = potencial[i*250+ j]
        j+=1
    i+=1
i=0   
while(i<250):
    j=0
    while(j<250):
        ExFinal[i,j] = Ex[i*250+ j]
        j+=1
    i+=1 
i=0
while(i<250):
    j=0
    while(j<250):
        EyFinal[i,j] = Ey[i*250+ j]
        j+=1
    i+=1  
    
X = range(250)
im = plt.imshow(potencialFinal, cmap='hot')
plt.ylim(250,0)
plt.xlim(0,250)
plt.colorbar(im, orientation='horizontal')
plt.streamplot(np.array(X),np.array(X),np.array(ExFinal),np.array(EyFinal),density=1.2,linewidth = 0.5,color='b')
pp = PdfPages('placas.pdf')
plt.savefig(pp, format='pdf')
pp.close()


# In[ ]:



