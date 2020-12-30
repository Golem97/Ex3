#include <stdio.h>
#include<stdlib.h>
#include <mem.h>

#define SIZE 50

int insertionsort(int*,int);
void shift_element(int*, int);


//Compile as isort.o
    int main() {

    int f = 0, arr[SIZE];

    //TODO: replace scanf with fgets ?

    while (scanf("%d", arr + f) && f < SIZE) {
        f++;
        char ch = fgetc(stdin);
        if (ch == 0x0A) // If Enter is pressed
        {
            break;
        }
    }

    insertionsort(arr, f);

    for (int i = 0; i < f; i++) {
        printf("%d", *(arr + i));
        if (i != f - 1) printf(",");
    }


    /////////////// Shift_element Test ////
    /*
    int arr2[] = {0,1,2,3,4,5};
    shift_element(arr2+2,2);

    for(int i=0;i < 6;i++){
        printf("%d",*(arr2+i));
        if(i!= 5) printf(",");
    } */

}

    /**
     *
     * @param arr
     * @param i
     * @return moves i+1 elements to the right from a given pointer adress
     * Exemple: arr = {0,1,2,3,4,5} | shift_element(arr+2,2) will return {0,1,2,2,3,5}
     * (assuming there is memory for at least i+1 letters after the pointer given as parameter)
     */
    void shift_element(int *arr, int i) {

        for (; i > 0; i--) {
            *(arr + i) = *(arr + i - 1);
        }
    }

    /**
     *
     * @param arr
     * @param n
     * @return sorted arr using insertion sort algorithm
     */
    int insertionsort(int *arr, int len) {

        int i, j, temp;

        for (i = 1; i < len; i++) {
            temp = *(arr + i);
            j = i - 1;

            while (temp < *(arr + j) && j >= 0) {
                *(arr + (j + 1)) = *(arr + j);
                j--;
            }
            *(arr + (j + 1)) = temp;
        }
        return 0;
    }
