#define NMAX 10 //macro per pile

/*Questa libreria contiene gli abstact data type visti a lezione.
Le definizioni sono commentate poiché si ripetono nella gandolib.h*/

/////////////////////////////////////////////////////////////
/*                          LISTE                          */
/////////////////////////////////////////////////////////////

typedef struct nodo
{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuova_lista(Lista *l);
int vuota(Lista l);
void inserimento_testa(Lista *l, int numero);
void inserimento_ordinato(Lista *l, int numero);
void inserimento_coda(Lista *l, int numero);
void inversa(Lista l1, Lista *l2);
int ricerca(Lista l, int numero);
void elimina(Lista *l, int numero);
int lunghezza(Lista l);
void stampa(Lista l);
void svuota(Lista *l);
void concatena(Lista *l1, Lista l2);
void somma(Lista l1, Lista l2, Lista *l3);
void somma_efficiente(Lista l1, Lista l2, Lista *l3);

/////////////////////////////////////////////////////////////
/*                          QUEUE                          */
/////////////////////////////////////////////////////////////

// typedef struct nodo
// {
//     char dato[21];
//     struct nodo *next;
// } Nodo;

typedef struct
{
    Nodo *first;
    Nodo *last;
} Coda;

int isEmptyQueue(Coda c);
Coda newQueue();
void enqueue(Coda *c, char *s);
void dequeue(Coda *c, char *s);
void print(Coda c);

/////////////////////////////////////////////////////////////
/*                          PILA                           */
/////////////////////////////////////////////////////////////

typedef struct
{
    float dati[NMAX];
    int nElem;
} Pila;

void nuova_Pila(Pila *p);
int vuota_Pila(Pila p);
int piena_Pila(Pila p);
void push(Pila *p, float elemento);
float pop(Pila *p);