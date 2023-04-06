#include <stdio.h>
#include <stdlib.h>

int actual_calc(float a, float b){
    float c;
    if(b != 0)
    {
        c=a/b;
        printf("%.2f \n", c);
    }
     
    else 
        printf("Não é possível realizar divisão por 0! \n");
    return 0;
}

int calc(){
  float a;
  float b;
  a=13;
  b=0;
  actual_calc(a, b);
  return 0;
}

int main(){
  calc();
  return 0;
}
