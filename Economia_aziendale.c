#include <stdio.h>
#define dimnome 81
#define dimdescrizione 256
#define dimpezzi 1000
#define IVA 22
#include <stdlib.h>

typedef struct
{
  float quantita;
  char nome[dimnome];
  float prezzo;
  char descrizione[dimdescrizione];
  float sconto;
  float iva;
  float imponibile2;
  float imponibile3;

}pezzo;

typedef struct
{
  pezzo pezzi[dimpezzi];
  char nomeazienda[dimdescrizione];
  char riferimenti[dimnome];
  char consegna[dimnome];
  char partita_iva[dimnome];
  char codicefiscale[dimnome];
  char numerofattura[dimnome];
  char data[dimnome];
  char note[dimdescrizione];
  float spese_di_trasporto;
} blueprint_fattura;

int intro()
{ int n;
  printf("Benvenuto nel programma per calcolare e gestire le fatture\n Hai due possibilità di scelta:\n1) Inserisci 1 e premi invio per accedereal programma lungo\ndove inserireai prima i dati dell'azienda, poi quelli \ndegli articoli, potrai anche scegliere di salvare il tutto\nin un formato di testo txt;\n2) Inserisci 2 e premi invio per accedere al programma corto\ndove inserirai solo i dati degli oggetti ed elaborerai i dati;\n\nInserisci un numero: ");
    scanf("%d",&n);
    return n;
}

void operazioni_iniziali(blueprint_fattura *fattura)
{
printf("Inserire il numero di fattura: ");
scanf("%s",fattura->numerofattura);
printf("Inserire il nome dell'azienda: ");
scanf("%s",fattura->nomeazienda);
printf("Inserire la partita iva: ");
scanf("%s",fattura->partita_iva);
printf("Inserire il codicefiscale: ");
scanf("%s",fattura->codicefiscale);
printf("Inserire il metodo di consegna: ");
scanf("%s",fattura->consegna);
printf("Inserire la data di oggi: ");
scanf("%s",fattura->data);
printf("Inserire i riferimenti: ");
scanf("%s",fattura->riferimenti);
printf("Inserire eventuali note aggiuntive: ");
scanf("%s",fattura->note);



}

void calcoli(int cicli, blueprint_fattura *fattura)
{
    printf("Inserire il nome del prodotto (non mettere spazi, per indicare uno spazio inserire '_'): ");
    scanf("\n%s",fattura->pezzi[cicli].nome);
    printf("Inserire la quantita del prodotto: ");
    scanf("\n%f",&fattura->pezzi[cicli].quantita);
    printf("Inserire il prezzo del prodotto: ");
    scanf("\n%f",&fattura->pezzi[cicli].prezzo);
    printf("Inserire la descrizione del prodotto (non mettere spazi, per indicare uno spazio inserire '_'):  ");
    scanf("%s",fattura->pezzi[cicli].descrizione);
    printf("Inserire lo sconto da applicare al prodotto: ");
    scanf("\n%f",&fattura->pezzi[cicli].sconto);

}

int inserimento(blueprint_fattura *fattura)
{ int cicli=0;

  int scelta;
  int logicdimpezzi;

  for(cicli=0;cicli<dimpezzi;cicli++)

    {
        calcoli(cicli,fattura);

        printf("Inserire 0 per fermare l'inserimento o 1 per continuare: ");
        scanf("%d",&scelta);

        if(scelta==0)
        { logicdimpezzi=cicli;
            cicli=dimpezzi;
          }
          }
return logicdimpezzi;}

  int menuswtch()
  { int scelta;
    printf("Inserire il numero dell'indice per compiere le seguenti azioni:\n" );
    printf("1) Stampa fattura a schermo\n");
    printf("2) Modifica un prodotto cercandolo per nome\n");
    printf("3) Modifica l'iva da usare in tutti i prodotti\n");
    printf("4) Aggiungi un imponibile (secondo imponibile) a un prodotto cercandolo per nome\n");
    printf("5) Aggiungi un imponibile (secondo imponibile) a tutti i prodotti\n");
    printf("6) Aggiungi un imponibile (terzo imponibile) a un prodotto cercandolo per nome\n");
    printf("7) Aggiungi un imponibile (terzo imponibile) a tutti i prodotti\n");
    printf("8) Richiedi il prezzo finale di un prodotto\n");
    printf("9) Richiedi il prezzo finale della fattura\n");
    printf("10) Stampa la fattura su un txt\n");
    printf("\n");
    printf("0) Esci dal programma\n\n");
    printf("Inserisci la scelta: ");
    scanf("%d",&scelta);
    return scelta;
  }

  void inizializzazione(blueprint_fattura *fattura)
  {
    int i=0;

    for(i=0;i<dimpezzi;i++)
        fattura->pezzi[i].iva=IVA;

  }

  void stampa(blueprint_fattura fattura, int logicdimpezzi)
  { int i=0;
    printf("Fattura n°: %s\n",fattura.numerofattura);
    printf("Nome dell'Azienda: %s\n",fattura.nomeazienda);
    printf("Partita Iva: %s\n",fattura.partita_iva);
    printf("Codice Fiscale: %s\n",fattura.codicefiscale);
    printf("Data: %s\n",fattura.data);
    printf("Riferimenti: %s\n",fattura.riferimenti);
    printf("Note: %s\n",fattura.note);

    for (i = 0; i < logicdimpezzi+1; i++)
    {
      printf("Quantita: %.0f\tNome: %s\tPrezzo: %.2f\tSconto: %.2f\tIva: %.2f\tImpo2: %.2f\tImpo3: %.2f\nDescrizione: %s\n",fattura.pezzi[i].quantita,fattura.pezzi[i].nome,fattura.pezzi[i].prezzo,fattura.pezzi[i].sconto,fattura.pezzi[i].iva,fattura.pezzi[i].imponibile2,fattura.pezzi[i].imponibile3,fattura.pezzi[i].descrizione);

    }


  }


int main(int argc, char *argv[])
{
    int scelta;
  int flag=0;
  int logicdimpezzi=0;


  blueprint_fattura fattura;

inizializzazione(&fattura);

  scelta=intro();


  if(scelta==1)
    operazioni_iniziali(&fattura);

    logicdimpezzi=inserimento(&fattura);

    while (flag==0) {

      scelta= menuswtch();

      switch(scelta)
      {case 1:

          {
            stampa(fattura, logicdimpezzi); 
            system("PAUSE");
            system("cls");
          }

      break;
    }

    }


  system("PAUSE");	
  return 0;
}
