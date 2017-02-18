#define DIM_CHAR 31
#define DIM_ARR 31

typedef struct
{
    char nome[DIM_CHAR];
    long int bilancio;
} cliente;

typedef struct nodo
{
    cliente dato;
    struct nodo *next;
} Nodo;
typedef Nodo *Lista;


void loop_inserimento_arr(cliente arr[], unsigned int *dim_log);
void loop_inserimento_list(Lista *l);

void bubblesort(int arr[], unsigned int dim_log);
void bubblesort_cliente(cliente arr[], unsigned int dim_log);
int binary_search_int(int arr[], int low, int high, int target);
int binary_search_str(cliente arr[], int low, int high, const char target[]);
void open_file(FILE **fp, const char nomeFile[], const char modalita[]);
void FiletoList(Lista *l);
void FiletoArray(cliente arr[], unsigned int *dim_log);
void ListtoFile(Lista l);
void ArraytoFile(const cliente arr[], unsigned int dim_log);
cliente *getClientPointer(Lista l, const char target[]);
void stampaTabella_list(Lista l);
void stampaTabella_arr(const cliente arr[], unsigned int dim_log);

void elimina_cliente_arr(cliente arr[], unsigned int *dim_log);
/*Seguono le funzioni della ADTlib convertite per i dati di
tipo cliente.*/
void elimina_cliente_list(Lista *l);

void nuova_lista_cliente(Lista *l);
int lunghezza_lista_cliente(Lista l);

void inserimento_testa_cliente(Lista *l, cliente var);
void inserimento_coda_cliente(Lista *l, cliente var);
void inserimento_ordinato_cliente(Lista *l, cliente var);