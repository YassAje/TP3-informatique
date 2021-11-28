#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"



int main(int argc,char *argv[]){
	
	unsigned int codehex;
	unsigned char BUF[5]; 	
                /*déclaration de nombre a convertir*/
	printf("Entrez un code caratère unicode (hexadécimal) : ");
	scanf("%x",&codehex);
        printf("Le code 0x%X ",codehex); 
              /*conversion utf8*/
        if(unicode2UTF8(codehex,BUF)){
        /* si c'est possible on le fait*/
            printf("represente le caratère suvivant : %s \n",BUF);
          /* sinon c'est invalide*/
        }else{
            printf("est invalide\n");
        }
	


return (EXIT_SUCCESS);

}
/*
zone de réponse
*/
