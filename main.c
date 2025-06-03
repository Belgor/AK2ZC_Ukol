#include <stdio.h>
#include <stdlib.h> // Pro malloc a free
#include "ukol_pole.h"

#define MAX_ARRAY_SIZE 100 // Maximální povolená velikost pole

// Pomocná funkce pro tisk pole
void printArray(int arr[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    int length;
    char again;

    do {
        printf("Zadejte delku pole (max %d): ", MAX_ARRAY_SIZE);
        if (scanf("%d", &length) != 1 || length <= 0 || length > MAX_ARRAY_SIZE) {
            printf("Neplatna delka pole. Program bude ukoncen.\n");
            return 1; // Ukončí program, pokud je délka neplatná
        }

        int *arr = (int *)malloc(length * sizeof(int));
        if (arr == NULL) {
            printf("Chyba alokace pameti.\n");
            return 1;
        }

        printf("Zadejte %d cela cisla:\n", length);
        for (int i = 0; i < length; i++) {
            printf("Zadejte cislo %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Neplatny vstup. Zadejte cele cislo.\n");
                free(arr);
                return 1;
            }
        }

        printf("\nPuvodni pole: ");
        printArray(arr, length);

        // Demonstrace funkce pro otočení pole
        int *reversed_arr = (int *)malloc(length * sizeof(int));
        if (reversed_arr == NULL) {
            printf("Chyba alokace pameti pro obracene pole.\n");
            free(arr);
            return 1;
        }
        // Zkopírujeme původní pole, abychom mohli demonstrovat otočení bez změny originálu
        for (int i = 0; i < length; i++) {
            reversed_arr[i] = arr[i];
        }
        reverseArray(reversed_arr, length);
        printf("Obracene pole: ");
        printArray(reversed_arr, length);
        free(reversed_arr);

        // Demonstrace funkce pro průměr
        double average = calculateAverage(arr, length);
        printf("Prumerna hodnota pole: %.2f\n", average);

        // Demonstrace funkce pro min/max
        int max_val, min_val;
        findMinMax(arr, length, &max_val, &min_val);
        printf("Maximalni hodnota v poli: %d\n", max_val);
        printf("Minimalni hodnota v poli: %d\n", min_val);

        free(arr); // Uvolnění alokované paměti

        printf("\nChcete zadat nove pole a spustit program znovu? (A/N): ");
        // Vyčistíme vstupní buffer před čtením znaku
        while ((getchar()) != '\n'); 
        scanf(" %c", &again); // Mezera před %c ignoruje bílé znaky (včetně nového řádku)
    } while (again == 'a' || again == 'A');

    return 0;
}
