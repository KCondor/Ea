#include <stdio.h>
#include "gandolib.h"

int main(int argc, char *argv[])
{
    cliente arr[DIM_ARR];
    Lista l;
    unsigned int dim_log;
    nuova_lista_cliente(&l);    //inizializzo la lista

    unsigned int request;
    do
    {
        printf("%s", "Scegliere un'opzione:\n"
                     "1 - Inserimento su array\n"
                     "2 - Inserimento su lista\n"
                     "3 - Salva array su file\n"
                     "4 - Salva lista su file\n"
                     "5 - Apri array da file\n"
                     "6 - Apri lista da file\n"
                     "7 - Stampa array\n"
                     "8 - Stampa lista\n"
                     "9 - Elimina cliente da array\n"
                     "10- Elimina cliente da lista\n"
                     "11- ++ DEBUG ++\n"
                     "12- Arresta il programma\n"
                     "? : ");
        scanf("%u", &request);
        puts("");

        switch (request)
        {
        default:
            puts("Opzione non riconosciuta.");
            break;
        case 1:
            loop_inserimento_arr(arr, &dim_log);
            break;
        case 2:
            loop_inserimento_list(&l);
            break;
        case 3:
            ArraytoFile(arr, dim_log);
            break;
        case 4:
            ListtoFile(l);
            break;
        case 5:
            FiletoArray(arr, &dim_log);
            break;
        case 6:
            FiletoList(&l);
            break;
        case 7:
            stampaTabella_arr(arr, dim_log);
            break;
        case 8:
            stampaTabella_list(l);
            break;
        case 9:
            elimina_cliente_arr(arr, &dim_log);
            break;
        case 10:
            elimina_cliente_list(&l);
            break;
        case 11:
        // Case vuoto per punto di interruzione nel debugger
            break;
        case 12:
            puts("Chiusura del programma.");
            break;
        }
        printf("Operazione completata.\n\n");
    } while (request != 12);
    return 0;
}