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

} while (i > bytevalue);

bits=bits-1;
while (bits>=0){

	current = pow(2,bits);
	/*printf("%d ",current);*/
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
