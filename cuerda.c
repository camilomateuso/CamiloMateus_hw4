#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

  float dx = 1.0;
  float dt = 1.0;
  int T =200;
  int L =100;
  float *posicion;
  posicion = malloc (sizeof(float) * (L/dx)*(T/dt));
  int i =1;
  int k = 0;
  float c = 1/2.0;

  while(k<L){

    if((k/100.0)<=0.8){
      posicion[k]=(1.25*(k/100.0));
      
    }
    else{
      posicion[k]=(5 - (5*k/100.0));
    }

    k=k+dx;
  }
  
  while(i<T){
    k=1;
      while(k<L){
	if((k==0)||k==(L-1)){
	  posicion[i*L +k] = 0;
	}
	else if(i==1){
	  posicion[i*L +k] = posicion[(i-1)*L+k]+ (pow((c*dt/dx),2)/2.0)*( posicion[(i-1)*L+k+1] - 2*posicion[(i-1)*L+k] + posicion[(i-1)*L+k-1]);
	   }
	else{

	  posicion[i*L +k] = 2*(1-pow((c*dt/dx),2)/2.0)*posicion[(i-1)*L +k] - posicion[(i-2)*L +k] + (pow((c*dt/dx),2)/2.0)*(posicion[(i-1)*L +k+1]+posicion[(i-1)*L +k-1]);
	}
	
	k = k+ dx;
								      
      }
      i = i+dt;		 
    }

 

   for(i=0;i<T;i++){
      for(k=0;k<L;k++){

        
        printf("%f\n",posicion[i*L + k]);
         }
         }
     



}
