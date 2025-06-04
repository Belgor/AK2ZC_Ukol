#include <stdio.h>
#include <stdlib.h> // Pro malloc a free
#include "ukol_pole_cisel.h"

#define MAX_SIZE 100 // Maximální povolená velikost pole čísel

int main() {
    int length;
    char again;

    do {
        int valid_length = 0; // Pomocná proměnná pro kontrolu platné délky
        do {
            printf("Zadejte delku pole cisel (max %d): ", MAX_SIZE);
            // Pokud se program opakuje vyčistíme vstupní buffer
            if (again == 'a' || again == 'A')
            {
                while ((getchar()) != '\n');
            }
            if (scanf("%d", &length) != 1 || length <= 0 || length > MAX_SIZE) {
                printf("Spatne zadana delka pole cisel. Musi byt cislo od 1 do %d.\n", MAX_SIZE);
                printf("Chcete zkusit zadat delku znovu (A) nebo ukoncit program (N)? ");
                char retry_choice;
                while ((getchar()) != '\n'); // Vyčistíme buffer
                scanf(" %c", &retry_choice);
                if (retry_choice != 'a' && retry_choice != 'A') {
                    return 0; // Ukončí program, pokud uživatel nechce zkusit znovu
                }
            } else {
                valid_length = 1; // Délka je platná, můžeme pokračovat
            }
        } while (!valid_length); // Opakujeme, dokud nezískáme platnou délku

        int *pole_cisel = (int *)malloc(length * sizeof(int));
        if (pole_cisel == NULL) {
            printf("Chyba alokace pameti.\n");
            return 1;
        }

        printf("Zadejte %d cela cisla:\n", length);
        for (int i = 0; i < length; i++) {
            printf("Zadejte cislo %d: ", i + 1);
            if (scanf("%d", &pole_cisel[i]) != 1) {
                printf("Neplatny vstup. Zadejte prosim cele cislo.\n");
                free(pole_cisel);
                return 1; 
            }
        }

        printf("\nPuvodni pole cisel: ");
        printArray(pole_cisel, length);

        // Funkce pro otočení pole čísel
        int *reversed_pole_cisel = (int *)malloc(length * sizeof(int));
        if (reversed_pole_cisel == NULL) {
            printf("Chyba alokace pameti pro obracene pole cisel.\n");
            free(pole_cisel);
            return 1;
        }
        // Zkopírujeme původní pole čísel, abychom mohli demonstrovat otočit bez změny originálu
        for (int i = 0; i < length; i++) {
            reversed_pole_cisel[i] = pole_cisel[i];
        }
        reverseArray(reversed_pole_cisel, length);
        printf("Obracene pole_cisel: ");
        printArray(reversed_pole_cisel, length);
        free(reversed_pole_cisel);

        // Funkce pro průměr
        double average = calculateAverage(pole_cisel, length);
        printf("Prumerna hodnota pole cisel: %.2f\n", average);

        // Funkce pro min/max
        int max_val, min_val;
        findMinMax(pole_cisel, length, &max_val, &min_val);
        printf("Maximalni hodnota v poli: %d\n", max_val);
        printf("Minimalni hodnota v poli: %d\n", min_val);

        free(pole_cisel);

        printf("\nChcete opakovat s novym polem cisel? (A/N): ");
        // Vyčistíme vstupní buffer před čtením znaku
        while ((getchar()) != '\n'); 
        scanf(" %c", &again); // Mezera před %c ignoruje bílé znaky (včetně nového řádku)
    } while (again == 'a' || again == 'A'); // Opakuje program, pokud uživatel zadá 'A' nebo 'a'

    return 0;
}
