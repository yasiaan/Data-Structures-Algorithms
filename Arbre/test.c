#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void solution_equation2( float a, float b, float c) {
    float delta, x1, x2, x, x1_2, x12, x22;
    delta = (b*b)- (4*a*c);
    if (delta<0){
        x1_2 = -b/2*a;
        x12 = sqrt(-delta)/2*a;
        x22 = -sqrt(-delta)/2*a;
        printf("\n L'équation admet une solution complexe double : x1 = %f + %f.i , x2 = %f + %f.i\n",x1_2,x12,x1_2,x22);
    }
    else if (delta == 0) {
        x = -b/(2*a);
        printf("\n L'équation admet une solution réel simple : x = %f. \n",x);
    }
    else {
        x1 = (-b+sqrt(delta))/2*a;
        x2 = (-b-sqrt(delta))/2*a;
        printf("\n L'équation admet une solution réel double : x1 = %f, x2 = %f. \n",x1,x2);
    }
}
int main(){
    float a, b, c;
    printf("Entrer le premier coefficient :");
    scanf("%f",&a);
    printf("Entrer le deuxieme coefficient :");
    scanf("%f",&b);
    printf("Entrer le troisieme coefficient :");
    scanf("%f",&c);
    solution_equation2(a,b,c);
    return 0;
}

