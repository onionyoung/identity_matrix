#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print(float *arr1, int size);
void  identity_matrixF(float *arr1, int size);
void function(float *arr1, int row1, float num, int size);
void functionA(float *arr1, int row1, int row2, float num, int size);

int main(int argc, char *argv[]) {
	float *arr1, *identity_matrix;// = malloc(sizeof(int));
	int size, i, k;
	char ch;
	printf("是否字型輸入矩陣(Y/N)");
	scanf("%c", &ch);
	if(ch == 'y' || ch == 'Y'){
		printf("請輸入陣列長度：");
    	scanf("%d", &size);
    	arr1 = malloc(size * size * sizeof(float));
    	for(i = 0; i < size * size; i++){
    		scanf("%f", arr1 + i);
		}
		print(arr1, size);
		printf("~~~~~~~~~~~~~~~~~~~~~~\n"); 
	}else{
		printf("預設矩陣3*3\n");
		size = 3;
		arr1 = malloc(size * size * sizeof(float));
		*(arr1 + 0) = 1;
		*(arr1 + 1) = 4;
		*(arr1 + 2) = 3;
		*(arr1 + 3) = -1;
		*(arr1 + 4) = -2;
		*(arr1 + 5) = 0;
		*(arr1 + 6) = 2;
		*(arr1 + 7) = 2;
		*(arr1 + 8) = 3;
		print(arr1, size);
		printf("~~~~~~~~~~~~~~~~~~~~~~\n"); 
	}
	//printf("請輸入陣列長度：");
    //scanf("%d", &size);
	
	identity_matrix = malloc(size * size * sizeof(float));
	identity_matrixF(identity_matrix, size);
	
	/****************************************/
	for(k = 0; k < size; k++){
		//if(*(arr1 + k + (k * size)) == 0)k++;
		for(i = k; i + 1 < size; i++){
			if( *(arr1 + ((i+1) * size) + k) != 0){
				functionA(identity_matrix, k, i+1, *(arr1 + ((i+1) * size) + k) / *(arr1 + ((k) * size) + k) * -1, size);
				functionA(arr1, k, i+1, *(arr1 + ((i+1) * size) + k) / *(arr1 + ((k) * size) + k) * -1, size);
			}
		}
	}
	
	for(i = 0; i < size; i++){
		if(*(arr1 + i +(i * size)) != 1){
			function(identity_matrix, i, 1 / *(arr1 + i +(i * size)), size);
			function(arr1, i, 1 / *(arr1 + i +(i * size)), size);
		}
	}
	for(k = size; k >= 0; k--){
		for(i = k; i != 0; i--){
			if( *(arr1 + ((i-1) * size) + i) != 0){
					functionA(identity_matrix, k, i-1, *(arr1 + ((i-1) * size) + k) / *(arr1 + ((k) * size) + k) * -1, size);
					functionA(arr1, k, i-1, *(arr1 + ((i-1) * size) + k) / *(arr1 + ((k) * size) + k) * -1, size);
				}
		}
	}
	
	
	/****************************************/
	print(arr1, size);
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
	print(identity_matrix, size);
	
	system("pause");
	return 0;
}
void print(float *arr1, int size){
	int i;
	for(i = 0; i < size * size; i++) {
        printf(" %.3f, \t", *(arr1+i));
        if(i % size == size -1 )printf("\n");
    }
}
//init identity_matrixF
void  identity_matrixF(float *arr1, int size){
	int i,j;
	for(i = 0, j = 0; i < size * size; i++) {
        *(arr1 + i) = 0;
        if(i == j * size + j){
        	*(arr1 + i) = 1;
		}else if(i % size == size - 1){
			j++;
		}
	}
}
//row2 = row1 * size + row2
void functionA(float *arr1, int row1, int row2, float num, int size){
	int i = row1 * size;
	int j = row2 * size;
	for(;i < (row1 + 1) * size; j++, i++){
		*(arr1 + j) = *(arr1 + i) * num + *(arr1 + j);
	}
}
//row1 = row1 * num
void function(float *arr1, int row1, float num, int size){
	int i = row1 * size;
	for(;i < (row1 + 1) * size; i++){
		*(arr1 + i) = *(arr1 + i) * num;
	}
}


