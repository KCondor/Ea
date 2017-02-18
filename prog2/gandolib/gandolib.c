#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "gandolib.h"

/*Stampa a video un loop in do-while per l'inserimento su array. Parte da indice 0 di default. Si interrompe con STOP 
da input oppure quando l'array è pieno.*/
void loop_inserimento_arr(cliente arr[], unsigned int *dim_log)
{
  char input[DIM_CHAR];
  int flag = 0;
  unsigned int i = 0;
  do
  {
    puts("Digitare il nome del cliente (STOP interrompe l'inserimento):");
    scanf("%s", input);
    if (strcmp(input, "STOP") == 0)
      flag = 1;
    else
    {
      strcpy(arr[i].nome, input);
      puts("Digitare il bilancio del cliente:");
      scanf("%ld", &arr[i].bilancio);
      ++i;
    }
  } while (flag != 1 && i != DIM_ARR);
  *dim_log = i;
}

/*Stampa a video un loop in do-while per l'inserimento su lista. L'inserimento avviene attraverso inserimento_coda_cliente.
Si interrompe con STOP da input.*/
void loop_inserimento_list(Lista *l)
{
  int flag = 0;
  cliente var;
  do
  {
    puts("Digitare il nome del cliente (STOP interrompe l'inserimento):");
    scanf("%s", var.nome);
    if (strcmp(var.nome, "STOP") == 0)
      flag = 1;
    else
    {
      puts("Digitare il bilancio del cliente:");
      scanf("%ld", &var.bilancio);
      inserimento_coda_cliente(l, var);
    }
  } while (flag != 1);
}

/*Algoritmo di ordinamento. Richiede l'array e la sua dimensione logica.*/
void bubblesort(int arr[], unsigned int dim_log)
{
  unsigned int i, k;
  int temp;
  for (i = 0; i < dim_log - 1; i++)
  {
    for (k = 0; k < dim_log - 1 - i; k++)
    {
      if (arr[k] > arr[k + 1])
      {
        temp = arr[k];
        arr[k] = arr[k + 1];
        arr[k + 1] = temp;
      }
    }
  }
}

/*Algoritmo di ordinamento. Richiede l'array di tipo cliente e la sua dimensione logica. Riordina alfabeticamente l'array.*/
void bubblesort_cliente(cliente arr[], unsigned int dim_log)
{
  unsigned int i, k;
  cliente temp;
  for (i = 0; i < dim_log - 1; i++)
  {
    for (k = 0; k < dim_log - 1 - i; k++)
    {
      if (strcmp(arr[k].nome, arr[k + 1].nome) > 0)
      {
        temp = arr[k];
        arr[k] = arr[k + 1];
        arr[k + 1] = temp;
      }
    }
  }
}

/*Algoritmo di ricerca. Richiede l'array di interi, i suoi estremi e l'elemento da ricercare. Ritorna -1 se non trovato,
altrimenti ritorna la posizione nell'array.*/
int binary_search_int(int arr[], int low, int high, int target)
{
  int mid;

  if (low > high)
  {
    return -1;
  }
  mid = (low + high) / 2;
  if (arr[mid] == target)
    return mid;
  else if (arr[mid] > target)
    binary_search_int(arr, low, mid - 1, target);
  else if (arr[mid] < target)
    binary_search_int(arr, mid + 1, high, target);
}

/*Algoritmo di ricerca. Richiede l'array di tipo cliente, i suoi estremi e la stringa da ricercare. Ritorna -1 se non
trovata, altrimenti ritorna la posizione nell'array.*/
int binary_search_str(cliente arr[], int low, int high, const char target[])
{
  int mid;

  if (low > high)
  {
    return -1;
  }
  mid = (low + high) / 2;
  if (strcmp(arr[mid].nome, target) == 0)
    return mid;
  else if (strcmp(arr[mid].nome, target) > 0)
    binary_search_str(arr, low, mid - 1, target);
  else if (strcmp(arr[mid].nome, target) < 0)
    binary_search_str(arr, mid + 1, high, target);
}

/*Apre il file richiedendo il puntatore, il nome del file, e la modalità di lettura. In caso di fallimento termina
l'esecuzione.*/
void open_file(FILE **fp, const char nomeFile[], const char modalita[])
{
  if ((*fp = fopen(nomeFile, modalita)) == NULL)
  {
    printf("Errore nel caricamento!\n");
    exit(-1);
  }
}

/*Esegue l'inserimento ordinato del contenuto del file in una lista. Richiede il nome del file, il tipo di file (b=binary;
t=text) e la lista su cui salvare i dati.*/
void FiletoList(Lista *l)
{
  FILE *fp;
  cliente var;
  unsigned int i;
  char nomeFile[DIM_ARR];
  char filetype;

  do
  {
    printf("Scegliere la modalità di apertura del file (b=binary, t=text): ");
    scanf(" %c", &filetype);
    if (filetype != 'b' && filetype != 't')
      puts("Modalità di apertura non valida");
    else
    {
      printf("Scegliere il nome del file da aprire: ");
      scanf("%s", nomeFile);
    }
  } while (filetype != 'b' && filetype != 't');

  switch (filetype)
  {
  case 'b':
    open_file(&fp, nomeFile, "rb");
    while (fread(&var, sizeof(cliente), 1, fp) > 0) //finché fread legge i dati con successo
      inserimento_ordinato_cliente(l, var);         //inserisce il dato nella lista ordinata
    break;

  case 't':
    open_file(&fp, nomeFile, "r");
    while (fscanf(fp, " %s%ld", var.nome, &var.bilancio) > 0) //finché fscanf legge i dati con successo
      inserimento_ordinato_cliente(l, var);                   //inserisco il dato nella lista ordinata
    break;
  }
  fclose(fp);
}

/*Esegue l'inserimento ordinato del contenuto del file in un array (utilizzando bubblesort). Richiede il nome del file,
il tipo di file (b=binary; t=text) e la lista su cui salvare i dati.*/
void FiletoArray(cliente arr[], unsigned int *dim_log)
{
  FILE *fp;
  cliente var;
  unsigned int i = 0;
  char nomeFile[DIM_ARR];
  char filetype;

  do
  {
    printf("Scegliere la modalità di apertura del file (b=binary, t=text): ");
    scanf(" %c", &filetype);
    if (filetype != 'b' && filetype != 't')
      puts("Modalità di apertura non valida");
    else
    {
      printf("Scegliere il nome del file da aprire: "); //rimane all'interno del do-while per leggibilità
      scanf("%s", nomeFile);
    }
  } while (filetype != 'b' && filetype != 't');

  switch (filetype)
  {
  case 'b':
    open_file(&fp, nomeFile, "rb");
    while (fread(&arr[i], sizeof(cliente), 1, fp) > 0 && i < DIM_ARR)
    { //finché fread legge i dati con successo e il contatore è minore della dimensione dell'array
      i++;
      bubblesort_cliente(arr, i); //inserisco il dato nell'array ordinato tenendo conto della nuova dimensione logica
    }
    *dim_log = i; //pareggio la dimensione logica dell'array con il contatore
    break;

  case 't':
    open_file(&fp, nomeFile, "r");
    while (fscanf(fp, " %s%ld", arr[i].nome, &arr[i].bilancio) == 2 && i < DIM_ARR)
    { //finché fscanf legge i dati con successo e il contatore è minore della dimensione dell'array
      i++;
      bubblesort_cliente(arr, i); //inserisco il dato nell'array ordinato tenendo conto della nuova dimensione logica
    }
    *dim_log = i; //pareggio la dimensione logica con il contatore
    break;
  }
  fclose(fp);
}

/*Salva il contenuto della lista in un file. Richiede il nome del file, il tipo di file(b=binary; t=text) e la lista da cui
salvare i dati.*/
void ListtoFile(Lista l)
{
  FILE *fp;
  Nodo *n = l;
  cliente var;
  char nomeFile[DIM_ARR];
  char filetype;

  if (!n)
    puts("La lista è vuota.");
  else
  {
    do
    {
      printf("Scegliere la modalità di apertura del file (b=binary, t=text): ");
      scanf(" %c", &filetype);
      if (filetype != 'b' && filetype != 't')
        puts("Modalità di apertura non valida");
      else
      {
        printf("Scegliere il nome del file su cui salvare: ");
        scanf("%s", nomeFile);
      }
    } while (filetype != 'b' && filetype != 't');

    switch (filetype)
    {
    case 'b':
      open_file(&fp, nomeFile, "wb");
      while (n) //finché il nodo esiste
      {
        var = n->dato;                        //ne copio il dato in una variabile dello stesso tipo (cliente)
        fwrite(&var, sizeof(cliente), 1, fp); //scrivo la variabile
        n = n->next;                          //infine avanzo al nodo successivo
        //questa scelta è dettata dal fatto che nel momento in cui leggo il file per inserire i dati nella lista
        //non posso lavorare con degli struct nodo.
      }
      break;

    case 't':
      open_file(&fp, nomeFile, "w");
      while (n)
      {
        fprintf(fp, "%s %ld\n", n->dato.nome, n->dato.bilancio); //stampo nel file i dati direttamente dal nodo
        n = n->next;                                             //infine avanzo al nodo successivo
      }
      break;
    }
    fclose(fp);
  }
}

/*Salva il contenuto dell'array in un file. Richiede il nome del file, il tipo di file(b=binary; t=text), l'array da cui 
salvare i dati e la sua dimensione logica.*/
void ArraytoFile(const cliente arr[], unsigned int dim_log)
{
  FILE *fp;
  cliente var;
  unsigned int i;
  char nomeFile[DIM_ARR];
  char filetype;

  if (dim_log == 0)
    puts("L'array è vuoto");
  else
  {
    do
    {
      printf("Scegliere la modalità di apertura del file (b=binary, t=text): ");
      scanf(" %c", &filetype);
      if (filetype != 'b' && filetype != 't')
        puts("Modalità di apertura non valida");
      else
      {
        printf("Scegliere il nome del file su cui salvare: ");
        scanf("%s", nomeFile);
      }
    } while (filetype != 'b' && filetype != 't');

    switch (filetype)
    {
    case 'b':
      open_file(&fp, nomeFile, "wb");
      for (i = 0; i < dim_log; i++)
        fwrite(&arr[i], sizeof(cliente), 1, fp); //scrivo nel file il contenuto della i-esima cella dell'array
      break;

    case 't':
      open_file(&fp, nomeFile, "w");
      for (i = 0; i < dim_log; i++)
        fprintf(fp, "%s %ld\n", arr[i].nome, arr[i].bilancio); //scrivo nel file il contenuto della i-esima cella dell'array
      break;
    }
    fclose(fp);
  }
}

/*Algoritmo di ricerca. Richiede la lista e la stringa da ricercare. Ritorna il puntatore al nodo della lista se trovato,
altrimenti NULL.*/
cliente *getClientPointer(Lista l, const char target[]) // MAI TESTATA
{
  while (l != NULL)
  {
    if (strcmp(l->dato.nome, target) == 0)
      return &l->dato;
    l = l->next;
  }
  return NULL;
}

/*Stampa la lista in una tabella avente per riga: posizione nella lista, nome e bilancio. La scrittura è formattata.*/
void stampaTabella_list(Lista l)
{
  unsigned int i = 0;
  Nodo *n = l;
  if (!n)
    puts("La lista è vuota.");
  else
  {
    printf("%-5s%-15s%-15s\n", "Num", "Cliente", "Bilancio");
    while (n)
    {
      i++;
      printf("%-5u%-15s%-15lu\n", i, n->dato.nome, n->dato.bilancio);
      n = n->next;
    }
  }
}

/*Stampa la lista in una tabella avente per riga: posizione nella lista, nome e bilancio. La scrittura è formattata.*/
void stampaTabella_arr(const cliente arr[], unsigned int dim_log)
{
  unsigned int i = 0;
  if (dim_log == 0)
    puts("L'array è vuoto.");
  else
  {
    printf("%-5s%-15s%-15s\n", "Num", "Cliente", "Bilancio");
    while (i < dim_log)
    {
      i++;
      printf("%-5u%-15s%-15lu\n", i, arr[i - 1].nome, arr[i - 1].bilancio);
    }
  }
}
/* Algoritmo di ricerca ed eliminazione. Scorre l'array fino ad al più una corrispondenza. In caso di array molto grandi
si potrebbe modificarte l'algortimo con un binary search. Richiede l'array e il puntatore alla sua dimensione logica.*/
void elimina_cliente_arr(cliente arr[], unsigned int *dim_log)
{
  unsigned short flag = 0; //questo sistema può essere sostituito da 2 return differenti;
  unsigned int i;
  char target[DIM_CHAR];

  if (!dim_log) //==0
    puts("L'array è vuoto");
  else
  {
    puts("Inserire il nome del cliente da eliminare: ");
    scanf("%s", target);
    for (i = 0; !flag; i++)
    {
      if (strcmp(arr[i].nome, target) == 0) //se trovo la corrispondenza
      {
        flag = 1;
        for (; i < *dim_log; i++) //non ho bisogno della condizione iniziale in questo ciclo
          arr[i] = arr[i + 1];
      }
    }
    if (flag)
    {
      *dim_log -= 1; //pericolo
      puts("Eliminazione completata.");
    }
    else
      puts("Cliente non trovato.");
  }
}

///////////////////////////////////////////////////////////////////////////////////////
/* Seguono le principali funzioni della ADTlib convertite per i dati di tipo cliente */
///////////////////////////////////////////////////////////////////////////////////////

/* Algoritmo di ricerca ed eliminazione. Scorre la lista fino ad al più una corrispondenza. Richiede il puntatore a lista.*/
void elimina_cliente_list(Lista *l) //rispetto alla funzione della ADTlib, non richiede la variabile dal main
{
  Nodo **n = l, *aux;
  unsigned short flag = 0; //questo sistema può essere sostituito da 2 return differenti;
  char target[DIM_CHAR];
  if (!n)
    puts("La lista è vuota.");
  else
  {
    puts("Inserire il nome del cliente da eliminare: ");
    scanf("%s", target);
    while (*n && !flag)
    {
      if (strcmp((*n)->dato.nome, target) == 0) //se trovo la corrispondenza
      {
        aux = *n;
        *n = aux->next;
        free(aux);
        flag = 1; //la segnalo con una variabile flag
      }
      else
        n = &((*n)->next);
    }
    if (flag)
      puts("Eliminazione completata.");
    else
      puts("Cliente non trovato.");
  }
}

void nuova_lista_cliente(Lista *l) //non necessaria se si usa ADTlib
{
  *l = NULL;
}

int lunghezza_lista_cliente(Lista l) //non necessaria se si usa ADTlib
{
  unsigned int i = 0;
  Nodo *n = l;
  while (n)
  {
    i++;
    n = n->next;
  }
  return i;
}

void inserimento_testa_cliente(Lista *l, cliente var)
{
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = var;
  aux->next = *l;
  *l = aux;
}

void inserimento_coda_cliente(Lista *l, cliente var)
{
  Nodo **n = l;
  while (*n)
    n = &((*n)->next);
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = var;
  aux->next = NULL;
  *n = aux;
}

void inserimento_ordinato_cliente(Lista *l, cliente var)
{
  Nodo **n = l;
  while (*n && strcmp((*n)->dato.nome, var.nome) <= 0)
    n = &((*n)->next);
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = var;
  aux->next = *n;
  *n = aux;
}
