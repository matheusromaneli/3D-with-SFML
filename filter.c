#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void filter(char* in, char* out){
    FILE* fe = fopen(in, "r");
    FILE* fs = fopen(out, "w");
    char type[3];
    float f1,f2,f3;
    do{
        fscanf(fe, "%s %f %f %f\n", type, &f1, &f2, &f3);

        if(!strcmp(type, "v")) fprintf(fs, "%s %f %f %f\n", type, f1,f2,f3);
    }while(!strcmp(type, "v"));
    char n1[50], n2[50], n3[50];
    puts("entrouwhile");
    while(fscanf(fe,"%s %s %s %s\n", type, n1,n2,n3) != -1 && strcmp(type, "f"));
    puts("achou o tal do f");
    do{
        char *t1, *t2, *t3;
        t1 = strtok(n1, "/");
        t2 = strtok(n2, "/");
        t3 = strtok(n3, "/");
        fprintf(fs, "%s %s %s %s\n", type, t1, t2, t3);
    }while(fscanf(fe,"%s %s %s %s\n", type, n1,n2,n3) != -1);

    fclose(fe);
    fclose(fs);
}

int main(){
    char input[50];
    char output[50];
    puts("nome do arquivo a ser filtrado:");
    scanf("%s", input);
    puts("nome do arquivo a ser salvo");
    scanf("%s", output);
    filter(input,output);
    return 1;
}