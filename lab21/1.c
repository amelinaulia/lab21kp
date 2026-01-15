#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define SIZE 5

typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[20];
} cornice_t;


void print_cornice(cornice_t cornice) {
    printf("| %3d || %3d || %3d || %-10s |\n",
        cornice.length,
        cornice.ceilingWidth,
        cornice.wallHeight,
        cornice.material);
}


void print_array(cornice_t* cornices, int size) {
    printf("------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        print_cornice(cornices[i]);
    }
    printf("------------------------------------------\n");
}


void fill_array(cornice_t* cornices, int size) {
    cornice_t data[SIZE] = {
        {10, 5, 3, "Wood"},
        {8, 4, 2, "Aluminium"},
        {12, 5, 4, "Plastic"},
        {6, 3, 2, "Steel"},
        {9, 6, 3, "Metal"}
    };

    for (int i = 0; i < size; i++) {
        cornices[i] = data[i];
    }
}

/* --- main --- */
int main() {
    setlocale(LC_ALL, "RUS");
    cornice_t cornices[SIZE];

    fill_array(cornices, SIZE);
    print_array(cornices, SIZE);

    return 0;
}

