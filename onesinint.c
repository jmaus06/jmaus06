/*Joel Maus*/
/*finds number of 1's in a converted integer to binary*/
#include <stdio.h>
#include <math.h>

int main(){

int i,current;
int bit,bits,bytevalue;
int total;

printf("Enter integer: ");
scanf("%d",&i);

bits=0;
total =0;

do{
bits=bits+8;

bytevalue =(pow(2,bits)-1);

} while (i > bytevalue);

bits=bits-1;
while (bits>=0){

	current = pow(2,bits);
	if (current<=i){
		i=i-current;
		total = total + 1;
	}

	bits = bits -1; /*go to next smallest bit*/
}
printf("\nTotal number of 1's is %d\n",total);

return 0;
}
