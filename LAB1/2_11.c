#include<stdio.h>

int caculate(int raw){
	return (raw * 10) - 1;
}

int sum(int rawarray[], int count){
	//return 0;
	int total = 0;
	
	for(int j = 0; j < count; j++){
		total += rawarray[j];
	}

	return total;
}

int main(){
	// Init variable
	int count = 0;
	int raw_value = 10;

	printf("User Input: ");
	scanf("%d", &count);

	// Create new array
	int store[count];
	
	for(int i = 0; i < count; i++){
		store[i] = caculate(raw_value);
		printf("%d", store[i]);
		raw_value = raw_value * 10;
		if(i < count-1) printf(" + ");
	}
	
	printf(" = %d\n", sum(store, count));

	 
	return 0;

}