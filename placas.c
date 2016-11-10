#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int L = 5;
  int l = 2;
  int d=1;
  float h = 0.02;
  int V0  = 100;
  float N = 2*pow(L/h,2.0);
  float *matriz;
  matriz = malloc (sizeof(float) * N/2);
  float *matriz2;
  matriz2 = malloc (sizeof(float) * N/2);
  float *matrizEx;
  matrizEx = malloc (sizeof(float) * N/2);
  float *matrizEy;
  matrizEy = malloc (sizeof(float) * N/2);
  int i = 0;
  int j = 0;
  int k = 0;
  
  while(k< N){
    
    k=k+1;
    for(i=0;i<(L/h -1);i++){
      for(j=0;j<(L/h -1);j++){
        
	if((j==0)||(i==0)||(i==(int)((L/h)-1))||(j==(int)((L/h)-1))){
	  matriz2[(int)(i*L/h + j)] = 0;
	  
	}
	else if((i==(int)(((L/2.0) -(d/2.0))/0.02))&&(j>(int)(((L/2.0)-(l/2.0))/0.02))&&(j<(int)(((L/2.0)+(l/2.0))/0.02))){
	  matriz2[(int)(i*L/h + j)] = 100/2.0;
	  
	}
      
	else if((i==(int)(((L/2.0) +(d/2.0))/0.02))&&(j>(int)(((L/2.0)-(l/2.0))/0.02))&&(j<(int)(((L/2.0)+(l/2.0))/0.02))){
	  matriz2[(int)(i*L/h + j)] = -100/2.0;
	}
        else{

	  matriz2[(int)(i*L/h + j)]= (matriz[(int)(i*L/h +(j+1))]+matriz[(int)(i*L/h +(j-1))]+matriz[(int)((i+1)*L/h +j)]+matriz[(int)((i-1)*L/h +j)])/4.0;
	 
	}

      }
      
    }
    
    for(i=0;i<(L/h);i++){
      for(j=0;j<(L/h);j++){

         
	matriz[(int)(i*L/h +j)] = matriz2[(int)(i*L/h +j)];
         }
         }
        
  }

  for(i=0;i<(L/h);i++){
      for(j=0;j<(L/h);j++){

	if(j==0){
	  matrizEx[(int)(i*L/h +j)]= -(matriz[(int)(i*L/h +j+1)]-0)/(2*h);
	}
	else if(j==(int)((L/h)-1)){
	  matrizEx[(int)(i*L/h +j)]= -(0-matriz[(int)(i*L/h +j-1)])/(2*h);
	}
	else{	
	matrizEx[(int)(i*L/h +j)]= -(matriz[(int)(i*L/h +j+1)]-matriz[(int)(i*L/h +j-1)])/(2*h);
	}
      }
  }
  
  for(i=0;i<(L/h);i++){
      for(j=0;j<(L/h);j++){

	if(i==0){
	  matrizEy[(int)(i*L/h +j)]= -(matriz[(int)((i+1)*L/h +j)]-0)/(2*h);
	}
	else if(i==(int)((L/h)-1)){
	  matrizEy[(int)(i*L/h +j)]= -(0-matriz[(int)((i-1)*L/h +j)])/(2*h);
	}
	else{	
	  matrizEy[(int)(i*L/h +j)]= -(matriz[(int)((i+1)*L/h +j)]-matriz[(int)((i-1)*L/h +j)])/(2*h);
	}
      }
  }



  for(i=0;i<(L/h);i++){
      for(j=0;j<(L/h);j++){

        
        printf("%f %f %f\n", matriz[(int)(i*L/h +j)],  matrizEx[(int)(i*L/h +j)],  matrizEy[(int)(i*L/h +j)]);
         }
         }

}

    
    
    

