#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2);

int main(void) {
    int vp1[] = {11, 13, 45, 7};
    int vp2[] = {24, 4, 16, 81,10, 12};
    
    int *vt1 = vp1, *vt2=vp2;
    int *vt3 = NULL;
    int tam1 = 4, tam2 = 6, TAM = tam1 + tam2;

    vt3 = (int*) malloc(sizeof(int) * TAM);
    vt3 = uniao(vt1, tam1, vt2, tam2);

    for (int j=0; j<(TAM); j++){
        printf("%d\n", vt3[j]);
    }

    free(vt3);
return 0;
}


int *uniao(int *v1, int n1, int *v2, int n2){
  int n3 = n1+n2;
  int *v3=NULL;

  v3 = (int*) malloc(sizeof(int)* n3);;

  for (int i=0; i<n3; i++){
    if (i<n1){
      v3[i]=v1[i];
    }
    else {
      v3[i]=v2[i-n1];
    }
  }
  return v3;
}


