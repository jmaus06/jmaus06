/*Joel Maus*/
/*converts integer to binary*/
#include <stdio.h>
#include <math.h>

int main(){

int i,current;
int bit,digit;

printf("Enter integer: ");
scanf("%d",&i);

bit=7;

while (bit>=0){

	current = pow(16,bit);/*find value of highest bit position to test*/
	
	if (current<=i){
		digit=i/current;
		i=i%current;/*use remainder for next calculation*/
		if (digit<10)
			printf("%d ",digit);
		else {

			switch (digit){

			case 10:
				printf("A ");
				break;
			case 11:
				printf("B ");
				break;
			case 12:
				printf("C ");
				break;
			case 13:
				printf("D ");
				break;
			case 14:
				printf("E ");
				break;
			case 15:
				printf("F ");
				break;
			default:
				break;
			}
		}
}
	else{
		printf("0 ");
	}
	bit = bit -1; /*go to next smallest bit*/
}
printf("\n");

return 0;
}
