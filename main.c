#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "matrix.h"
#include "array.h"
//Найти наибольший отрицательный элемент массива А (23) и матрицы B (7х5).

int main()
{
	int menu;
	printf("Choose menu item:\n");
	printf("1. Array\n");
	printf("2. Matrix\n\n");
	while(!scanf("%d", &menu) || menu < 1 || menu > 2)
	{
		printf("Repeat the input:\n");
		while(getchar() != '\n');
	}
	srand(time(NULL));
	switch(menu)
	{
		case 1:
		{
			void * lib;
			void (*funV)(int[]);
			int (*funI)(int[]);
			lib = LoadLibrary("libarr.dll");
			if (!lib)
			{
				printf("Cannot open library '%s'\n", "libarr.dll");
				return 1;
			}

			int A[23];
			funV = (void (*)(int[]))GetProcAddress((HINSTANCE)lib, "Array_Creation");
			if (funV == NULL)
				printf("Cannot load function %s\n", "Array_Creation");
			else
				funV(A);

			funI = (int (*)(int[], int))GetProcAddress((HINSTANCE)lib, "Array_Operation");
			if (funV == NULL)
				printf("Cannot load function %s\n", "Array_Operation");
			else
			{
				printf("Array max = %d\n", funI(A));
			}
			FreeLibrary((HINSTANCE)lib);
			break;
		}
		case 2:
		{
			void * lib;
			void (*funV)(int *);
			int (*funI)(int *);
			lib = LoadLibrary("libmatr.dll");
			if (!lib)
			{
				printf("Cannot open library '%s'\n", "libmatr.dll");
				return 1;
			}

			int B[7][5];
			funV = (void (*)(int *))GetProcAddress((HINSTANCE)lib, "Matrix_Create");
			if (funV == NULL)
				printf("Cannot load function %s\n", "Matrix_Create");
			else
				funV(&B[0][0]);

			funI = (int (*)(int *))GetProcAddress((HINSTANCE)lib, "Matrix_Operation");
			if (funV == NULL)
				printf("Cannot load function %s\n", "Matrix_Operation");
			else
			{
				printf("Matrix max = %d\n", funI(&B[0][0]));
			}
			FreeLibrary((HINSTANCE)lib);
			break;
		}
	}
	return 0;
}


