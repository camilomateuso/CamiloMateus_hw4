
# coding: utf-8

# In[101]:

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys
import os
i=0
lines= open('onda.dat').readlines()
posicion = []
while(i<len(lines)):
    a = lines[i]
    posicion.append(a.rstrip('\n'))
    i+=1
    
posicionFinal = np.zeros(shape =(200,100))

i=0   
while(i<200):
    j=0
    while(j<100):
        posicionFinal[i,j] = posicion[i*100+ j]
        j+=1
    i+=1 


os.makedirs("./pngs")

maxed = [max(posicionFinal[n]) for n in range(200)]
maxi = max(maxed)
for i in range(200):
    for n in range(100):
        plt.xlim(0,101)
        plt.ylim(-maxi,maxi)
        plt.scatter(n,posicionFinal[i,n])
    plt.savefig("./pngs/image-" +str(i) +'.png')
    plt.close()

import shutil
os.chdir("./pngs")
os.system("convert image-%d.png[1-199] cuerda.gif")
os.chdir("..")
shutil.move("./pngs/cuerda.gif","./cuerda.gif")


# In[ ]:



