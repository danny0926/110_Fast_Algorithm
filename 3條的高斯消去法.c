#include<stdio.h> 
#include<stdlib.h>
//�e�a�x�}���������h�k

float* BandGaussianElimination(float **A, float *B, int M, int N){
	//begin from A[M][M], end to A[N-1][N-1] , doing in this submatrix
	//N by N matrix
	//solve Ax = B
	int i, j, k, n;
	float a, b, c;
	a = A[0][0];
	b = A[1][0];
	c = A[0][1];
	//a, b, c �����ۦP 
	//�ѤW�ӤU 
	
	for(i = 0; i < N-1; ++i){
		a = A[i][i];
		b = A[i+1][i];
		c = A[i][i+1];
		
	
		A[i+1][i] = 0;
		A[i+1][i+1] -= b*c/a;
		
		B[i+1] -= B[i]*b/a;
		
		
		
	}
	
	
	//�ѤU�ӤW
	for(i = N-1; i >= 1; --i){
		a = A[i][i];
		b = A[i-1][i];
		
	
		A[i-1][i] = 0;
		B[i-1] -= B[i]* b/a;;
	} 
	
	for(i = 0; i < N; ++i){
		a = A[i][i];
		A[i][i] = 1;
		B[i] /= a;
	}
	
	return B;	
	
}







int main(){
	int i, j, N;
	N = 3;
	
	float **A = (float**)malloc(N*sizeof(float*));
	for(i = 0; i < N; i++){
		A[i] = (float*)malloc(N*sizeof(float));
	}
	
	float *b = (float*)malloc(N*sizeof(float));
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%f", &A[i][j]);
		}
	}
	
	for(i = 0; i < N; i++){
		scanf("%f", &b[i]);
	}
	
	float *x = (float*)malloc(N*sizeof(float));
	
	x = BandGaussianElimination(A, b, 0, N);
	
	for(i = 0; i < N; i++){
		printf("%f ", x[i]);
	}
	
	
	return 0;
}
