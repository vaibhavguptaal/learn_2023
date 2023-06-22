#include <stdio.h>
int main(){
int num;
printf("Enter your mark ");
scanf("%d",&num);
printf(" You entered %d", num); 

	if(num >= 90){
	printf(" Grade A");
		}
	else if ( num >=75){ 
		printf(" Grade B");
		}
	else if ( num >= 60){
		printf(" Grade C");
		}
	else if ( num >= 50){
		printf(" Grade D");
		}
	else{
	    printf(" Grade F");
	}
return 0;
}