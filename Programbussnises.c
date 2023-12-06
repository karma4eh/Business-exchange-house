#include <stdio.h>
#include <stdlib.h>

// Declaration of constants with data type
const int EXCHANGE_RATE_BUY = 90;
const int EXCHANGE_RATE_SELL = 100;
const int EXCHANGE_RATE_BS_SELL = 110;

// Declaration of functions
int convertToPeso(int amount);
int convertToBs(int amount);
int sellBs(int amount);

// Structure to store statistics
struct Status {
    int conversionProfits; // Profits from Bs to pesos conversion
    int sellingProfits;    // Profits from Bs selling
    int movements;         // Total number of movements made
};

// Function to print the frame
void printFrame() {
    int i;
    for (i = 0; i < 30; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int op = 1;
    int response;
    int quantityPesos, result;

    // Initialization of the statistics structure
    struct Status stats = {0, 0, 0};

    do {
        system("cls");
        printFrame();
        printf("| Currency Exchange AGG-LA NENA |\n");
        printFrame();

        printf("|1. Cambio                |\n");
        printf("|2. Venta de pesos con bs |\n");
        printf("|3. Vender BS             |\n");
        printf("|4. estadisticas          |\n");
        printf("|5. Salir                 |\n");

        printFrame();

        scanf("%d", &response);

        switch (response) {
            case 1:
                system("cls");
                printf("Ingrese la cantidad de pesos:\n");
                scanf("%d", &quantityPesos);
                result = convertToBs(quantityPesos);
                printf("%d pesos son: %d Bs\n", quantityPesos, result);
                stats.conversionProfits += quantityPesos;
                stats.movements++;
                system("pause");
                break;
            case 2:
                system("cls");
                int bs;
                printf("Cuantos pesos necesita el cliente\n");
                scanf("%d", &quantityPesos);
                bs = quantityPesos / EXCHANGE_RATE_BUY;
                result = convertToPeso(bs);
                printf("%d pesos son: %d Bs \n", quantityPesos, bs);
                stats.conversionProfits += result;
                stats.movements++;
                system("pause");
                break;
            case 3:
                system("cls");
                int bs2;
                printf("Cuantos Bs vamos a Vender\n");
                scanf("%d", &bs2);
                result = sellBs(bs2);
                printf("%d bolivares son %d pesos \n", bs2, result);
                stats.sellingProfits += result;
                stats.movements++;
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Estadisticas:\n");
                printf("Ganancias por conversion de Bs a pesos: %d\n", stats.conversionProfits);
                printf("Ganancias por vender Bs.: %d\n", stats.sellingProfits);
                printf("Numero total de movimientos: %d\n", stats.movements);
                system("pause");
                break;
            case 5:
                op = 0; // Set op to 0 to exit the loop
                break;
            default:
                system("cls");
                printf("Seleccione una opcion valida\n");
                system("pause");
        }
    } while (op == 1);

    return 0;
}

int convertToBs(int amount) {
    return amount / EXCHANGE_RATE_SELL;
}

int convertToPeso(int amount) {
    return amount * EXCHANGE_RATE_BUY;
}

int sellBs(int amount) {
    return amount * EXCHANGE_RATE_BS_SELL;
}
