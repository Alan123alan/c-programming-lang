#include <stdio.h>

int main(){
int lower_limit, upper_limit;
float celsius;
lower_limit = 0;
upper_limit = 300;
for(int fahr = lower_limit;fahr <= upper_limit;fahr += 20){
celsius = (5.0/9.0)*(fahr-32);
printf("%3d %6.1f\n",fahr,celsius);
}

return 0;
}
