#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main ()
{
  int lunghezza_m, lunghezza_k,lunghezza_c,lunghezza_cif;
  char m[128];
  puts("inserisci il plaintext:");
  fgets(m,128,stdin);
  while(getchar()!='\n');
  lunghezza_m=strlen(m);
  printf("IL PLAINTEXT HA %d CARATTERI\n", lunghezza_m);
  int a;
  printf("\nInserisci 1 per inserire la chiave manualmente\nInserisci 2 per generarla casualmente\nInserisci un altro numero per tornare indietro\n" );
  scanf("%d", &a);
  getchar();
  if(a==1)    //SE PREMI UNO FAI TUTTO QUELLO DENTRO L'IF
  {
    char k[128];
    do
    {
      printf("\n");
      puts("inserisci la chiave:");
      fgets(k,128,stdin);
      lunghezza_k=strlen(k);
    }
    while(lunghezza_k<lunghezza_m); //FINO A CHE LA LUNGHEZZA DI K RISULTA MINORE DI QUELLA DI M INSERISCI K
    lunghezza_k=strlen(k);
    printf("LA NOSTRA CHIAVE HA %d CARATTERI\n", lunghezza_k);
    char c[128];
    printf("\nil plaintext cifrato in esadecimale è: ");
    for(int i=0;i<lunghezza_m;i++)  //CICLO FOR PER EFFETTUARE L'OPERAZIONE DI CIFRATURA DEL TESTO
    {
        c[i]=m[i]^k[i];
        c[i]=c[i]+32;
        printf("%X", c[i]);
    }
    printf("\nil plaintext cifrato come stringa è: %s", c);
    lunghezza_c=strlen(c);
    printf("\nIL PLAINTEXT CIFRATO HA %d CARATTERI\n", lunghezza_c);
    printf("\nil plaintext decifrato in esadecimale è: ");
    for (int i=0; i<lunghezza_m; i++)  //CICLO FOR PER EFFETTUARE LA DECIFRATURA DEL TESTO
    {
      c[i]=c[i]-32;
      m[i]=c[i]^k[i];
      printf("%X", m[i]);
    }
    printf("\nil plaintext decifrato come stringa è: %s", m);
    lunghezza_m=strlen(m);
    printf("IL PLAINTEXT DECIFRATO HA %d CARATTERI\n", lunghezza_m);
    getchar();
  }
  else if(a==2) //SE A RISULTA UGUALE A 2 ALLORA FAI LE OPERAZIONI DENTRO ALL'ELSE IF
  {
    char *chiave_gen;
    chiave_gen=(char *)calloc(lunghezza_m,sizeof(char));
    srand((unsigned)time(NULL));  //GENERA UNA STRINGA CASUALE
    printf("\nLa chiave generata casualmente è:");
    for (int i=0;i<lunghezza_m;i++)
    {
      chiave_gen[i]= 32 + rand()%96;
    }
    printf("\n");
    printf("%s", chiave_gen);
    printf("\nLA NOSTRA CHIAVE RANDOMICA HA %lu CARATTERI\n", strlen(chiave_gen));
    char cif[128];
    printf("\nIl plaintext cifrato in esadecimale tramite la chiave random è:");
    for(int i=0;i<lunghezza_m;i++)
    {
        cif[i]=m[i]^chiave_gen[i];     //CIFRIAMO IL TESTO
        printf("%X",cif[i]);
    }
    printf("\n");
    printf("Il plaintext cifrato in stringa tramite la chiave random è:%s", cif);
    getchar();
    lunghezza_cif=strlen(cif);
    printf("IL PLAINTEXT CIFRATO HA %d CARATTERI\n", lunghezza_cif);
    printf("\nIl plaintext decifrato in esadecimale tramite la chiave random è:");
    for (int i=0; i<lunghezza_m; i++)
    {
      m[i]=cif[i]^chiave_gen[i]; //DECIFRA IL TESTO
      printf("%X", m[i]);
    }
    printf("\n");
    printf("Il plaintext decifrato in stringa tramite la chiave random è:%s", m);
    lunghezza_m=strlen(m);
    printf("IL PLAINTEXT DECIFRATO HA %d CARATTERI\n", lunghezza_m);
    getchar();
  }
  else
  printf ("Errore!! Tornare indietro");  //SE A RISULTA DIVERSO DA 2 E DA 1 ALLORA TORNA IDIETRO
  return 0;
}
