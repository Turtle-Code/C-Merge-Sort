//compile
//gcc -c main.c
//link the object file and create the executable
//gcc -o merge_sort main.o
//run the file
//merge_sort

#include <stdio.h>
#include <stdlib.h>

void merge(int data[], int first,int last){
	//i. initialize temporary arrays
	int m = first + (last - first) /2 ; //index of middle element
	int itemsL = m - first +1; //items in left array
	int itemsR = last - m;
	
	int *tempL;
	int * tempR;
	
	tempL = (int *) calloc(itemsL, sizeof(int));
	tempR = (int *) calloc(itemsR, sizeof(int));
	

	//ii. fill temporary arrays
	for (int cL = 0; cL < itemsL; cL ++){
		tempL[cL] = data[cL + first];
	}
	for (int cR = 0; cR < itemsR; cR ++){
		tempR[cR] = data[m+1+cR];
	}
	//iii. merge the temporary arrays into a final sorted array
	int tempL_count = 0, tempR_count = 0, data_count = first;
	//loop until one of the arrays is empty
	while(tempL_count < itemsL && tempR_count < itemsR){
		if(tempL[tempL_count] >= tempR[tempR_count]){			
			data[data_count] = tempR[tempR_count];
			tempR_count++;
		}
		else{			
			data[data_count] = tempL[tempL_count];			
			tempL_count++;
		}
		data_count++;
	}
	//copy over the remaining elments
	while(tempL_count < itemsL){
		data[data_count] = tempL[tempL_count];
		tempL_count++;
		data_count++;
	}
	while(tempR_count < itemsR){
		data[data_count] = tempR[tempR_count];
		tempR_count++;
		data_count++;
	}
	free(tempL);
	free(tempR);
	
}

void merge_sort(int data[], unsigned int first, unsigned int last){
	//recursive calls to merge_sort
	//this will reduce the size of the input array until it holds 1 element 
	//from here merge the arrays of size 1 to form an array of size two
	//as a result of merging the the newly formed array of two elements will be sorted and so forth	
	if(first<last){
	int new_mid = first + (last - first) /2 ;
	merge_sort(data,first,new_mid);
	merge_sort(data,new_mid+1,last);
	merge(data,first,last);
	
	
	
	}
}

int main () {
	printf("testing merge sort... \n");
	int A[] = {7, 8, 9, 5, 6,-1, 0,100,-10};
	int items_a = sizeof(A) / sizeof(A[0]);
	merge_sort(A,0,items_a-1);
	int p;
	//print array
	    for (p = 0; p < items_a; p++) {
        printf(" %d", A[p]);
		}
	return 0;
}