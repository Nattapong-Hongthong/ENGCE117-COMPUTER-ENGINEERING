#include<stdio.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int size){
	int i, j;

	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j+1]);		
			}
		}		
	}
}


int checkIndex(int index[], int size, int val){
	int result = 0;
	for(int k=0; k < size; k++){
		if(index[k] == val){
			result = 1;
			break;
		}
	}

	return result;
}

int main(){

	int length = 0;
	int count = 0;
	int index[100];
	int value[100];

	printf("in array: ");
	scanf("%d", &length);
	
	// Init array
	int demo[length];

	for(int z = 0; z < length; z++){
		printf("Element[%d]: ", z+1);
		scanf("%d", &demo[z]);
	}

	// Sort
	bubbleSort(demo, length);
	
	for(int i = 0; i < length; i++){
		printf("Index %d: %d and %d\n",i,demo[i],demo[i+1]);
		if(demo[i] == demo[i+1]){
			// Check index is exists
			if(checkIndex(index, count, demo[i]) == 0){
				index[count] = demo[i];
				value[demo[i]] = 1;
				count += 1;
			}
			
			value[demo[i]] += 1;
		}else{
			if(checkIndex(index, count, demo[i]) == 0){
				index[count] = demo[i];
				value[demo[i]] = 1;
				count += 1;
			}
		}
	}	
	
	for(int j = 0; j < count; j++){
		printf("%d -> %d\n",index[j],  value[index[j]]);
	}

	return 0;
}