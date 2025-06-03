#include "ukol_pole_cisel.h"
#include <stdio.h> // Pro případné ladění nebo budoucí rozšíření, i když pro tyto funkce není striktně nutné
#include <limits.h> // Pro INT_MAX a INT_MIN

// Pomocná funkce pro tisk pole čísel
void printArray(int pole_cisel[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", pole_cisel[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

// Funkce pro otočení pořadí čísel v poli
void reverseArray(int arr[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Funkce pro výpočet průměrné hodnoty čísel v poli
double calculateAverage(int arr[], int length) {
    if (length == 0) {
        return 0.0;
    }
    long long sum = 0; // Použijeme long long pro součet, abychom předešli přetečení
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (double)sum / length;
}

// Funkce pro hledání maximálního a minimálního čísla v poli
void findMinMax(int arr[], int length, int *max, int *min) {
    if (length == 0) {
        *max = 0; // Nebo jiná vhodná výchozí hodnota, např. INT_MIN
        *min = 0; // Nebo jiná vhodná výchozí hodnota, např. INT_MAX
        return;
    }

    *max = INT_MIN;
    *min = INT_MAX;

    for (int i = 0; i < length; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
