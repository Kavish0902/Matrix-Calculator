#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void print_matrix(int** a, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void matrix_multiplier() {
	printf("input matrix 1 and 2 dimensions\n");
	printf("row1 column1 row2 column2\n");

	int row_one = 0;
	int column_one = 0;
	int row_two = 0;
	int column_two = 0;
	int valid = 0;

	scanf_s("%d", &row_one);
	scanf_s("%d", &column_one);
	scanf_s("%d", &row_two);
	scanf_s("%d", &column_two);

	if (column_one != row_two) {
		printf("not compatable");
		exit(1);
	}

	int** matrix_one = malloc(row_one * sizeof(int*));
	int** matrix_two = malloc(row_two * sizeof(int*));
	printf("input matrix1 components\n");
	for (int i = 0; i < row_one; i++) {
		matrix_one[i] = malloc(column_one * sizeof(int));
		for (int j = 0; j < column_one; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("input matrix2 components\n");
	for (int i = 0; i < row_two; i++) {
		matrix_two[i] = malloc(column_two * sizeof(int));
		for (int j = 0; j < column_two; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_two[i][j] = temp;
		}
	}

	printf("matrix 1\n");
	print_matrix(matrix_one, row_one, column_one);

	printf("matrix 2\n");
	print_matrix(matrix_two, row_two, column_two);

	int** multi_matrix = malloc(row_one * sizeof(int*));

	for (int i = 0; i < row_one; i++) {
		multi_matrix[i] = calloc(column_two, sizeof(int));
	}

	for (int i = 0; i < row_one; i++) {
		for (int j = 0; j < column_two; j++) {
			for (int k = 0; k < row_two; k++) {
				multi_matrix[i][j] += (matrix_one[i][k] * matrix_two[k][j]);
			}
		}
	}

	printf("multi matrix\n");
	print_matrix(multi_matrix, row_one, column_two);


	for (int i = 0; i < row_one; i++) {
		free(matrix_one[i]);
	}

	for (int i = 0; i < row_two; i++) {
		free(matrix_two[i]);
	}

	for (int i = 0; i < row_one; i++) {
		free(multi_matrix[i]);
	}

	free(matrix_one);
	free(matrix_two);
	free(multi_matrix);
}

// Determinant Helper
void cofactor(int** a, int** b, int p, int q, int dim) {

	int i = 0, j = 0;

	for (int row = 0; row < dim; row++) {

		for (int col = 0; col < dim; col++) {
			if (row != p && col != q) {
				b[i][j++] = a[row][col];

				if (j == dim - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

// Determinant Helper
int getdeterminant(int** a, int dim) {
	int D = 0;

	if (dim == 1) {
		return a[0][0];
	}

	int** temp = malloc(dim * sizeof(int*));

	for (int i = 0; i < dim; i++) {
		temp[i] = malloc(dim * sizeof(int));
		for (int j = 0; j < dim; j++) {
			temp[i][j] = 0;
		}
	}

	int sign = 1;

	for (int f = 0; f < dim; f++) {
		cofactor(a, temp, 0, f, dim);
		D += sign * a[0][f] * getdeterminant(temp, dim - 1);

		sign = -sign;
	}
	return D;
}

void determinant_matrix() {
	printf("input matrix dimension\n");
	int row = 0;
	int column = 0;
	int determinant = 0;

	scanf_s("%d", &row);
	column = row;

	if (column != row) {
		printf("not compatable");
		exit(1);
	}

	int** matrix_one = malloc(row * sizeof(int*));

	for (int i = 0; i < row; i++) {
		matrix_one[i] = malloc(column * sizeof(int));
		for (int j = 0; j < column; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("matrix\n");
	print_matrix(matrix_one, row, column);

	determinant = getdeterminant(matrix_one, row);
	printf("Determinant: %d \n", determinant);

	for (int i = 0; i < row; i++) {
		free(matrix_one[i]);
	}
	free(matrix_one);
}

// Not Done
void Gauss_Jordan_Elimination() {

}

// Not Done
void RREF_Matrix() {

}

// Not Done
void invert_matrix() {
	printf("input matrix dimension\n");
	int row = 0;
	int column = 0;

	scanf_s("%d", &row);
	column = row;

	int** matrix_one = malloc(row * sizeof(int*));

	for (int i = 0; i < row; i++) {
		matrix_one[i] = malloc(column * sizeof(int));
		for (int j = 0; j < column; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("matrix\n");
	print_matrix(matrix_one, row, column);

	if (getdeterminant(matrix_one, row) == 0) {
		printf("No Inverse");
		for (int i = 0; i < row; i++) {
			free(matrix_one[i]);
		}
		free(matrix_one);
		exit(1);
	}

	//invert code

	printf("Inverted matrix\n");
	print_matrix(matrix_one, row, column);

	for (int i = 0; i < row; i++) {
		free(matrix_one[i]);
	}

	free(matrix_one);
}

void matrix_transpose() {
	printf("input Matrix Dimensions Row then Column\n");
	int row = 0;
	int column = 0;

	scanf_s("%d", &row);
	scanf_s("%d", &column);

	int** matrix_one = malloc(row * sizeof(int*));
	int** transpose_matrix = malloc(column * sizeof(int*));

	printf("input matrix components\n");
	for (int i = 0; i < row; i++) {
		matrix_one[i] = malloc(column * sizeof(int));
		for (int j = 0; j < column; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	for (int i = 0; i < column; i++) {
		transpose_matrix[i] = calloc(row, sizeof(int));
	}

	printf("matrix\n");
	print_matrix(matrix_one, row, column);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			transpose_matrix[j][i] = matrix_one[i][j];
		}
	}

	printf("transpose of matrix\n");
	print_matrix(transpose_matrix, column, row);

	for (int i = 0; i < row; i++) {
		free(matrix_one[i]);
	}

	for (int i = 0; i < column; i++) {
		free(transpose_matrix[i]);
	}

	free(transpose_matrix);
	free(matrix_one);

}

// Not Done
void matrix_power() {

}

void matrix_addition() {
	printf("input matrix 1 and 2 dimensions\n");
	printf("row1 column1 row2 column2\n");

	int row_one = 0;
	int column_one = 0;
	int row_two = 0;
	int column_two = 0;
	int valid = 0;

	scanf_s("%d", &row_one);
	scanf_s("%d", &column_one);
	scanf_s("%d", &row_two);
	scanf_s("%d", &column_two);

	if ((column_one != column_two) || (row_one != row_two)) {
		printf("not compatable");
		exit(1);
	}

	int** matrix_one = malloc(row_one * sizeof(int*));
	int** matrix_two = malloc(row_two * sizeof(int*));
	printf("input matrix1 components\n");
	for (int i = 0; i < row_one; i++) {
		matrix_one[i] = malloc(column_one * sizeof(int));
		for (int j = 0; j < column_one; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("input matrix2 components\n");
	for (int i = 0; i < row_two; i++) {
		matrix_two[i] = malloc(column_two * sizeof(int));
		for (int j = 0; j < column_two; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_two[i][j] = temp;
		}
	}

	printf("matrix 1\n");
	print_matrix(matrix_one, row_one, column_one);

	printf("matrix 2\n");
	print_matrix(matrix_two, row_two, column_two);

	int** add_matrix = malloc(row_one * sizeof(int*));

	for (int i = 0; i < row_one; i++) {
		add_matrix[i] = calloc(column_two, sizeof(int));
	}

	for (int i = 0; i < row_one; i++) {
		for (int j = 0; j < column_two; j++) {
			add_matrix[i][j] = matrix_one[i][j] + matrix_two[i][j];
		}
	}

	printf("Added matrix\n");
	print_matrix(add_matrix, row_one, column_two);


	for (int i = 0; i < row_one; i++) {
		free(matrix_one[i]);
	}

	for (int i = 0; i < row_two; i++) {
		free(matrix_two[i]);
	}

	for (int i = 0; i < row_one; i++) {
		free(add_matrix[i]);
	}
	free(matrix_one);
	free(matrix_two);
	free(add_matrix);
}

void matrix_subtraction() {
	printf("input matrix 1 and 2 dimensions\n");
	printf("row1 column1 row2 column2\n");

	int row_one = 0;
	int column_one = 0;
	int row_two = 0;
	int column_two = 0;
	int valid = 0;

	scanf_s("%d", &row_one);
	scanf_s("%d", &column_one);
	scanf_s("%d", &row_two);
	scanf_s("%d", &column_two);

	if ((column_one != column_two) || (row_one != row_two)) {
		printf("not compatable");
		exit(1);
	}

	int** matrix_one = malloc(row_one * sizeof(int*));
	int** matrix_two = malloc(row_two * sizeof(int*));
	printf("input matrix1 components\n");
	for (int i = 0; i < row_one; i++) {
		matrix_one[i] = malloc(column_one * sizeof(int));
		for (int j = 0; j < column_one; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("input matrix2 components\n");
	for (int i = 0; i < row_two; i++) {
		matrix_two[i] = malloc(column_two * sizeof(int));
		for (int j = 0; j < column_two; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_two[i][j] = temp;
		}
	}

	printf("matrix 1\n");
	print_matrix(matrix_one, row_one, column_one);

	printf("matrix 2\n");
	print_matrix(matrix_two, row_two, column_two);

	int** sub_matrix = malloc(row_one * sizeof(int*));

	for (int i = 0; i < row_one; i++) {
		sub_matrix[i] = calloc(column_two, sizeof(int));
	}

	for (int i = 0; i < row_one; i++) {
		for (int j = 0; j < column_two; j++) {
			sub_matrix[i][j] = matrix_one[i][j] - matrix_two[i][j];
		}
	}

	printf("Added matrix\n");
	print_matrix(sub_matrix, row_one, column_two);


	for (int i = 0; i < row_one; i++) {
		free(matrix_one[i]);
	}

	for (int i = 0; i < row_two; i++) {
		free(matrix_two[i]);
	}

	for (int i = 0; i < row_one; i++) {
		free(sub_matrix[i]);
	}
	free(matrix_one);
	free(matrix_two);
	free(sub_matrix);
}

void trace_matrix() {
	printf("input matrix dimension\n");
	int row = 0;
	int column = 0;
	int trace = 0;

	scanf_s("%d", &row);
	column = row;

	if (column != row) {
		printf("not compatable");
		exit(1);
	}

	int** matrix_one = malloc(row * sizeof(int*));

	for (int i = 0; i < row; i++) {
		matrix_one[i] = malloc(column * sizeof(int));
		for (int j = 0; j < column; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			matrix_one[i][j] = temp;
		}
	}

	printf("matrix\n");
	print_matrix(matrix_one, row, column);

	for (int i = 0; i < column; i++) {
		trace += matrix_one[i][i];
	}

	printf("Trace: %d \n", trace);

	for (int i = 0; i < row; i++) {
		free(matrix_one[i]);
	}
	free(matrix_one);
}

void main() {
	printf("Matrix Calculator\n");
	printf("type MM for matrix multiplcation, or Det for determinant calculation,\n or Inv for matrix inverse or Trace for the trace of a matrix,\n or MA for matrix addition or Trans for matrix transpose or MS for matrix subtraction or Exit to quit\n");
	char command[42] = "";
	while (scanf_s("%s", command, 11) == 1 && strcmp(command, "Exit")) {
		if (strcmp(command, "MM") == 0) {
			matrix_multiplier();
			printf("\n");
		}
		else if (strcmp(command, "Det") == 0) {
			determinant_matrix();
			printf("\n");
		}
		else if (strcmp(command, "Inv") == 0) {
			invert_matrix();
			printf("\n");
		}
		else if (strcmp(command, "Trace") == 0) {
			trace_matrix();
			printf("\n");
		}
		else if (strcmp(command, "MA") == 0) {
			matrix_addition();
			printf("\n");
		}
		else if (strcmp(command, "MS") == 0) {
			matrix_subtraction();
			printf("\n");
		}
		else if (strcmp(command, "Trans") == 0) {
			matrix_transpose();
			printf("\n");
		}
	}
	return 0;
}