/*Joel Maus*/
/*converts integer to binary*/
#include <stdio.h>
#include <math.h>

int main(){

int i,current;
int bit,bits,bytevalue;

printf("Enter integer: ");
scanf("%d",&i);

bits=0;

do{

bits=bits+8;

bytevalue =(pow(2,bits)-1);

} while (i > bytevalue);/*gets size of bits that the output should be*/

bits=bits-1;/*start with the bit below the amount, which will be the highest*/
while (bits>=0){

	current = pow(2,bits);

	if (current<=i){
		i=i-current;
		printf("1 ");
	}
	else{
		printf("0 ");
	}
	bits = bits -1; /*go to next smallest bit*/
}
printf("\n");

return 0;
}
