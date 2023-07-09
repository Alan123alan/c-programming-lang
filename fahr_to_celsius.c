#include <stdio.h>

int main(){
int lower_limit, upper_limit;
float celsius;
lower_limit = 0;
upper_limit = 300;
printf("Fahrenheit Celsius\n");
for(int fahr = lower_limit;fahr <= upper_limit;fahr += 20){
celsius = (5.0/9.0)*(fahr-32);
printf("%10d %7.1f\n",fahr,celsius);
}

return 0;
}
