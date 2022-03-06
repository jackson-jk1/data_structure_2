#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Função para mesclar o * arrl..m] e * arrm+1..r] para o * arry * arr */
void merge(int *arr, int l, int m, int r);

// Função de para encontrar o mínimo de dois inteiros
int min(int x, int y) { return (x < y) ? x : y; }

void insertionSort(int *arr, int n);

/* Função mergesort iterativa para classificar * arr0...n-1] */
void mergeSort(int *arr, int n)
{
    if (n <= 10)
    {
        void insertionSort(int *arr, int n);
        return;
    }
    int curr_size;  // For tamanho atual dos sub* arrys * arrserem mesclados
                    // curr_size varia de 1 * arrn/2
    int left_start; // For escolhendo o índice inicial do sub* arry esquerdo
                    // ser mesclado
    int left = 0;
    int right = n - 1;
    int r = right;
    int l = 0;
    bool sorted = false;
    do
    {
        sorted = true;
        left = 0;

        while (left < right)
        {
            l = left;
            while (l < right && arr[l] <= arr[l + 1])
            {
                l++;
            }
            r = l + 1;
            while (r == right - 1 || r < right && arr[r] <= arr[r + 1])
            {
                r++;
            }
            if (r <= right)
            {
                merge(arr, left, l, r);
                sorted = false;
            }
            left = r + 1;
        }
    } while (!sorted);

    // Mesclar submatrizes de maneira ascendente. Primeira mesclagem de submatrizes de
    // tamanho 1 para criar sub* arrys ordenados de tamanho 2, então mesclar sub* arrys
    // de tamanho 2 para criar sub* arrys ordenados de tamanho 4 e assim por diante.
}
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Mover elementos de * arr0..i-1], que são
          maior que a chave, para uma posição à frente
          de sua posição atual*/
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/* Função para mesclar os dois possui * arrl..m] e * arrm+1..r] do * arry * arr */
void merge(int *a, int left, int middle, int right)
{
    int l = left;
    int r = middle + 1;
    if (right + 1 <= 10)
    {
        insertionSort(a,right+1);
        return;
    }
   
    int n1 = middle - l + 1;
    int n2 = r - middle;
    int L[n1], R[n2];
    int i, j, k;
   
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[middle + 1 + j];
  
   
    i = 0; 
    j = 0; 
    k = l; 
    
    insertionSort(R,n2);

    if (L[n1-1] <= R[0])
    {
        for (i = 0; i < n1; i++)
        {
            a[i] = L[i];
        }
        for (j = 0; j < n2; j++)
        {
            a[middle + j] = R[j];
        }
        return;
    }
    
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
  
    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
  
    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
  
  
}

/* Função para imprimir um * arry */
void printArry(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int *arr;
    int n = 100;
    arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = abs(rand()) % n;
    printf("Given arry is \n");
    printArry(arr, n);

    mergeSort(arr, n);

    printf("\nSorted * arry is \n");
    printArry(arr, n);
    return 0;
}