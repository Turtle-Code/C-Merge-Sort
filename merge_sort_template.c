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
	//ii. fill temporary arrays
	//iii. merge the temporary arrays into a final sorted array
		
}

void merge_sort(int data[], unsigned int first, unsigned int last){
	//recursive calls to merge_sort
	//this will reduce the size of the input array until it holds 1 element 
	//from here merge the arrays of size 1 to form an array of size two
	//as a result of merging the the newly formed array of two elements will be sorted and so forth	
}

void main () {
	printf("testing merge sort... \n");
	int A[] = {7, 8, 9, 5, 6};
	int items_a = sizeof(A) / sizeof(A[0]);
	//print array
		int p;
	    for (p = 0; p < items_a; p++) {
        printf(" %d", A[p]);
		}
	
}