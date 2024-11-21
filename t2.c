/***************************************************************************************
 * 
 * t1.c: Experimento multiplicacion de matrices con  distintas formas de acceder a estas.
 *
 * Programmer: Vicente Santos Varas
 *
 * Santiago de Chile, 21/11/2024
 *
 **************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

void Usage(unsigned char *mess) {

    printf("\nUsage: %s -P -O < data.txt\n",mess);
    printf("P = {1: i-j-l, 2: j-i-;, 3: i-l-j, 4: j-l-i, 5: l-i-j, 6: l-j-i , 7: Aritmetica Punteros, 8: Unidimensional}\n");
    printf("O = {S: modo silencioso, V: modo verboso}\n\n");
}


/*
 *
 */ //Llenar matriz
float **FillMatrix(unsigned int r, unsigned int c) {
    unsigned int i, j;
    float **mat;

    mat = calloc(r, sizeof(float *));
    for (i = 0; i < r; i = i + 1)
        mat[i] = calloc(c, sizeof(float));
    for (i = 0; i < r; i = i + 1)
        for (j = 0; j < c; j = j + 1)
            scanf("%f", &mat[i][j]);
    return mat;
}


/*
 *
 */ // Llenar matriz unidimensional
float *FillMatrix1D(unsigned int r, unsigned int c) {
    unsigned int i, j;
    float *mat;

    mat = calloc(r * c, sizeof(float));

    for (i = 0; i < r; i = i + 1) {
        for (j = 0; j < c; j = j + 1) {
            scanf("%f", &mat[i * c + j]);
        }
    }
    return mat;
}


/*
 *
 */
void FreeMatrix(unsigned int r, float **mat) {

   unsigned int i;
   
   for (i = 0; i < r; i = i + 1)
      free(mat[i]);
   free(mat);
}


/*
 *
 */
void PrintMatrix(unsigned int r, unsigned int c, float **mat) {
    
   unsigned int i, j;
   
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1)
         printf(" %.2f ",mat[i][j]);
      printf("\n");
   }
}


/*
 *
 */ 
void PrintMatrix1D(unsigned int r, unsigned int c, float *mat) {
    unsigned int i, j;

    for (i = 0; i < r; i = i + 1) {
        for (j = 0; j < c; j = j + 1) {
            printf(" %.2f ", mat[i * c + j]);
        }
        printf("\n");
    }
}


/*
 *
 */ //Modo -1 i j l
float **Multiplicacion1(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    // Multiplicación clásica de matrices
    for (i = 0; i < m; i = i + 1) {          
        for (j = 0; j < n; j = j + 1) {       
            for (l = 0; l < k; l = l + 1) {   
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}


/*
 *
 */ // Modo -2: j i l
float **Multiplicacion2(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (j = 0; j < n; j = j + 1) {         
        for (i = 0; i < m; i = i + 1) {     
            for (l = 0; l < k; l = l + 1) { 
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}


/*
 *
 */ // Modo -3: i-l-j
float **Multiplicacion3(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (i = 0; i < m; i = i + 1) {          
        for (l = 0; l < k; l = l + 1) {       
            for (j = 0; j < n; j = j + 1) {   
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}


/*
 *
 */ // Modo -4: j-l-i
float **Multiplicacion4(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (j = 0; j < n; j = j + 1) {          
        for (l = 0; l < k; l = l + 1) {       
            for (i = 0; i < m; i = i + 1) {   
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}


/*
 *
 */ // Modo -5: l-i-j
float **Multiplicacion5(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (l = 0; l < k; l = l + 1) {          
        for (i = 0; i < m; i = i + 1) {       
            for (j = 0; j < n; j = j + 1) {   
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}


/*
 *
 */ // Modo -6: l-j-i
float **Multiplicacion6(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (l = 0; l < k; l = l + 1) {          
        for (j = 0; j < n; j = j + 1) {       
            for (i = 0; i < m; i = i + 1) {   
                Resultado[i][j] = Resultado[i][j] + A[i][l] * B[l][j];
            }
        }
    }
    return Resultado;
}

/*
 *
 */ // Modo -7: Aritmética de punteros para A, B y Resultado
float **Multiplicacion7(float **A, float **B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float **Resultado, *pResultado, *pA, *pB;

    Resultado = calloc(m, sizeof(float *));
    for (i = 0; i < m; i = i + 1)
        Resultado[i] = calloc(n, sizeof(float));

    for (i = 0; i < m; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            pResultado = &Resultado[i][j];
            pA = A[i];
            pB = &B[0][j]; 
            for (l = 0; l < k; l = l + 1) {
                *pResultado = *pResultado + *(pA + l) * *(pB + l * n);
            }
        }
    }
    return Resultado;
}



/*
 *
 */ // Modo -8: Matriz en arreglo unidimensional
float *Multiplicacion8(float *A, float *B, unsigned int m, unsigned int k, unsigned int n) {
    unsigned int i, j, l;
    float *Resultado;

    Resultado = calloc(m * n, sizeof(float));

    for (i = 0; i < m; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            for (l = 0; l < k; l = l + 1) {
                Resultado[i * n + j] += A[i * k + l] * B[l * n + j];
            }
        }
    }
    return Resultado;
}



int main(int argc, unsigned char **argv) {
    float E_cpu;
    long E_wall;  
    time_t ts, te;
    clock_t cs, ce;

    if (argc == 3) {
        float **Matrix1, **Matrix2, **Resultado, *Matrix11D, *Matrix21D, *Resultado1D;
        unsigned int m, k, n;
        scanf("%d", &m); // filas A
        scanf("%d", &k); // columnas A y filas B
        scanf("%d", &n); // columnas B

    

        if (strcmp(argv[1], "-1") == 0) { // Modo multiplicación clásico
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion1(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-2") == 0) { // Modo  j-i-l
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion2(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-3") == 0) { // Modo i-l-j
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion3(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-4") == 0) { // Modo j-l-i
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion4(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-5") == 0) { // Modo  l-i-j
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion5(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        }
        else if (strcmp(argv[1], "-6") == 0) { // Modo  l-j-i
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion6(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-7") == 0) { // Modo aritmetica punteros
            Matrix1 = FillMatrix(m, k);
            Matrix2 = FillMatrix(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix(m, k, Matrix1);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix(k, n, Matrix2);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado = Multiplicacion7(Matrix1, Matrix2, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else if (strcmp(argv[1], "-8") == 0) { // Modo  unidimensional
            Matrix11D = FillMatrix1D(m, k);
            Matrix21D = FillMatrix1D(k, n);

            if (strcmp(argv[2], "-V") == 0) {     // Verboso
                printf("A: \n");
                PrintMatrix1D(m, k, Matrix11D);
                printf("\n");
                printf("B: \n"); 
                PrintMatrix1D(k, n, Matrix21D);
                printf("\n");
            }
            ts = time(NULL);
            cs = clock();
            Resultado1D = Multiplicacion8(Matrix11D, Matrix21D, m, k, n);
            ce = clock();
            te = time(NULL);

        } 
        else {
            Usage(argv[0]);
            return 1;
        }

        if ((strcmp(argv[2], "-V") == 0) && (strcmp(argv[1], "-8")) == 0) {     // Verboso
            printf("Resultado: \n");
            PrintMatrix1D(m, n, Resultado1D);
            free(Matrix11D);
            free(Matrix21D);
            free(Resultado1D);
        }
        else if (strcmp(argv[2], "-V") == 0) {
            printf("Resultado : \n");
            PrintMatrix(m, n, Resultado);
            FreeMatrix(m, Matrix1);
            FreeMatrix(k, Matrix2);
            FreeMatrix(m, Resultado);
        }

        E_wall = (long) (te - ts);
        E_cpu = (float)(ce - cs) / CLOCKS_PER_SEC;
        printf("Elapsed CPU Time: %f Wall Time: %ld\n", E_cpu, E_wall);

    

    } else {
        Usage(argv[0]);
    }

    return 0;
}
