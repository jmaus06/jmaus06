/*converts integer to binary*/
#include <stdio.h>
#include <math.h>

main(){

int i;
int bit,bits,bytevalue;

printf("Enter integer: ");
scanf("%d",&i);

bits=0;

do{

bits=bits+8;

bytevalue =(pow(2,bits)-1)

} while (i > bytevalue);

printf("\nValue has been determined.\n");
}
