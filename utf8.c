#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"

int unicode2UTF8(unsigned int unicode, unsigned char *UTF8){
	
	int Maximun_1bit=0x007F;
	int Maximun_2bit=0x07FF;
	/*int Maximun_3bit=0xFFFF;*/
	int mask=0;
	/*int mask2;*/
	int bits,octets;
	
	if(unicode<0 || unicode > UTF8_MAX) return (NULL);

	if(unicode<Maximun_1bit+1) {
		UTF8[0]=unicode;    /*UTF8[0]=unicode;*/
		UTF8[1]='\0';        /*UTF8[1]=0;*/
	}
	if(unicode>Maximun_1bit){
		mask=Maximun_2bit;
		bits=11;octets=2;
		while((unicode&mask)!=unicode){
		mask<<=5;
		mask |= 0x1F;          /*s'augementer le mask avec 5 bits*/
		bits += 5;octets++;
		}
		UTF8[octets]=0;     /* ajouter le 0 a la fin de chaine de caratère*/
        }
	
	
	if(bits==21){
            *UTF8=0xf0+((unicode&0x1c0000)>>18);
            *(UTF8+1)=0x80+((unicode&0x3f000)>>12);
            *(UTF8+2)=0x80+((unicode&0xfc0)>>6);
            *(UTF8+3)=0x80+(unicode&0x3f);
        }
        if(bits==16){
            *(UTF8)=0xe0+((unicode&0x3f000)>>12);
            *(UTF8+1)=0x80+((unicode&0xfc0)>>6);
            *(UTF8+2)=0x80+(unicode&0x3f);
        }
        if(bits==11){
            UTF8[0]=0xc0+((unicode&0xfc0)>>6);
            UTF8[1]=0x80+(unicode&0x3f);
        }
        
	/*
         temp = unicode;
         while(octets){
            UTF8[octets]=(temp & 0x3f) | 0x80)
            temp>>=6;
             octets--;
             
}
         
        */
	




	return(UTF8);
}
