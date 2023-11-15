#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char nome[11];
    float x;
    float y;
    float raio;
}Circulo;

Circulo *criaCirculo(char *n, float vx, float vy, float r);

int contem(Circulo * var1, Circulo * var2);

/*______________________________________________________________*/

int main(void)  {
    Circulo *c1=NULL,*c2=NULL,*c3=NULL;
    c1 = criaCirculo("Circulo01",3.0,4.0,2.0);
    c2 = criaCirculo("Circulo02",3.0,3.0,1.0);
    c3 = criaCirculo("Circulo03",1.0,5.0,1.0);
    printf("%d\n",contem(c1,c2));
    printf("%d\n",contem(c1,c3));
    free(c1);
    free(c2); 
    free(c3);
    return 0;  
}

Circulo *criaCirculo(char *n, float vx, float vy, float r){
    Circulo *c=NULL;
    c=(Circulo *) malloc(sizeof(Circulo));

    strcpy(c->nome, n);
    c->x=vx;
    c->y=vy;
    c->raio=r;

    return c;
}

int contem(Circulo *var1, Circulo *var2){
    float d=0, vx1=var1->x, vx2=var2->x, vy1=var1->y, vy2=var2->y;
    float r2=var2->raio, r1=var1->raio;

    d= sqrt(((vx2-vx1)*(vx2-vx1))+((vy2-vy1)*(vy2-vy1)));
       
    if (d + r2 <= r1)return 0;
    
    else return 1;
}
