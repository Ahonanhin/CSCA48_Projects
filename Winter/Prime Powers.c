#include <stdio.h>

float power( float x, int p) {
    int a = 1;
    float y = x;
    while(a < p){
        y = y * x;
        a = a + 1;
    }
    return y;
}

int main(){
    float num = 1.4142f;
    int i, j, k;
    for (i =2; i <=100; i = i + 1){
      k = 0;
      for (j = 2; j < i; j = j + 1){
        if( (i % j) == 0){
          k = k + 1;
        }
      }
    if (k == 0){
        printf("p=%d, %.4f^%d = %f\n",i, num, i, power(num, i));
      }
    }
}
