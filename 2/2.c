#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
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


cornice_t* search_material(cornice_t* cornices, int size, char* material) {
    for (int i = 0; i < size; i++) {
        if (strcmp(cornices[i].material, material) == 0)
            return &cornices[i];
    }
    return NULL;
}


int compare(const void* a, const void* b) {
    const cornice_t* A = (const cornice_t*)a;
    const cornice_t* B = (const cornice_t*)b;

    int areaA = A->length * A->ceilingWidth;
    int areaB = B->length * B->ceilingWidth;

    if (areaA < areaB) return -1;
    if (areaA > areaB) return 1;
    return 0;
}



int main() {
    setlocale(LC_ALL, "RUS");
    cornice_t cornices[SIZE];
    fill_array(cornices, SIZE);

    printf("Исходный массив:\n");
    print_array(cornices, SIZE);


    char target[] = "Plastic";
    cornice_t* found = search_material(cornices, SIZE, target);

    if (found) {
        printf("\nНайден материал \"%s\":\n", target);
        print_cornice(*found);
    }
    else {
        printf("\nМатериал \"%s\" не найден.\n", target);
    }


    qsort(cornices, SIZE, sizeof(cornice_t), compare);

    printf("\nОтсортировано по площади (length * ceilingWidth):\n");
    print_array(cornices, SIZE);

    return 0;
}