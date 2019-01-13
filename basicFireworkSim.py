# module imports
from collections import defaultdict
import random
import numpy as np
np.set_printoptions(suppress=True)
%matplotlib inline

class Firework():
    #define constants for all fireworks
    iterate=50
    damping = 0.9
    gravity = [0,0.01]
    fade = [-0.005]
    
    def genrand(x,low=-10,up=10,div=100):
        #determines firework colour
        x = np.random.randint(low, up)
        return x
    
    def __init__(self,x,y):
        #for matrix x=num particles ,y=2 
  
        self.position_xy = np.full((x,y) ,self.genrand())
        self.velocities = np.random.normal(loc=0, scale=0.5, size=(x,y))
        self.colour = np.tile([self.genrand(10,100)/100,self.genrand(10,100)/100,self.genrand(10,100)/100], (x,1))

    def ignite(self):
        #this could be recursive however if a firework has
        # 100 particles then this will require more memory
        #than a basic loop
        count = 0
        while count < self.iterate:
           
           #Do physics on np arrays
            plot_array(self.position_xy,self.colour)
            self.position_xy = self.position_xy + self.velocities
            self.velocities = (self.damping*self.velocities - self.gravity)/1.1
            self.colour = self.colour + self.fade

            count+=1
    

fireworks= defaultdict(object)

for i in range(5):
    fireworks[i] = Firework(50,2)

for id,firework in fireworks.items():
    firework.ignite()
