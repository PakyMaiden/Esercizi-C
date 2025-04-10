/*---------------------------------------------- TRACCIA 1 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di int e il suo size,
	determina e restituisce come parametro di output il secondo più grande elemento dell'array.
*/

int traccia1(int a[], int n)
{
    int max = a[0]; // Assumiamo che il primo elemento sia il più grande
    int max2 = a[0]; // Assumiamo che il primo elemento sia anche il secondo più grande
    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max2 = max; // Il vecchio massimo diventa il secondo più grande
            max = a[i]; // Il nuovo massimo viene aggiornato
        }
        else if (a[i] > max2 && a[i] < max)
        {
            max2 = a[i]; // Aggiorniamo il secondo più grande
        }
    }
    return max2;
}


/*---------------------------------------------- TRACCIA 2 -------------------------------------------*/
/*
	Sviluppare una function C che, dato come parametro di
 	input un array di tipo struct punto {double x; double y;} e il
 	suo size, determina e restituisce come parametri di output gli
 	indici dei due punti che hanno distanza minima tra loro. I campi
 	x e y contengono l'ascissa e l'ordinata, rispettivamente, di un
 	punto.
*/

struct punto
{
    double x;
    double y;
};

typedef struct punto Punto;

double calcolo_distanza(Punto p1, Punto p2) //se senza il typedef è di tipo "struct punto"
{
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

void traccia2(Punto a[], int n, int *p1, int *p2)
{
    double distanza_min, distanza;
    int i, j;
    *p1=-1; //inizializzo indici distanza 
    *p2=-1; //inizializzo indici distanza
    if(n>=2)
    {
        distanza_min=calcolo_distanza(a[0], a[1]);
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                distanza=calcolo_distanza(a[i], a[j]);
                if(distanza<distanza_min)
                    distanza_min=distanza;
                    *p1=i;
                    *p2=j;
            }
        }
    }
}


/*---------------------------------------------- TRACCIA 3 -------------------------------------------*/
/*
	Sviluppare una function C che, dato come parametro
 	di input un array di tipo struct punto {double x; double y;}
 	e il suo size, determina e restituisce come parametro di output
 	la massima distanza tra i punti. I campi x e y contengono
 	l'ascissa e l'ordinata, rispettivamente, di un punto.
*/

struct punto
{
    double x;
    double y;
};

typedef struct punto Punto;

double calcolo_distanza(Punto p1, Punto p2) //se senza il typedef è di tipo "struct punto"
{
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

double traccia3(Punto a[], int n)
{
    double distanza_max, distanza;
    int i, j;
    if(n>=2)
    {
        distanza_max=calcolo_distanza(a[0], a[1]);
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
			{
                distanza=calcolo_distanza(a[i], a[j]);
                if(distanza>distanza_max)
                    distanza_max=distanza;
			}
        }
    }
    return distanza_max;
}


/*---------------------------------------------- TRACCIA 4 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array 2D di double, il
	numero delle righe e il numero delle colonne, determina e restituisce come parametro
	di output il massimo tra le somme degli elementi di ogni colonna.
*/ 

double traccia4(double a[][100], int row, int col)
{
    int i, j;
    double somma=0.0, max=0.0;
    for(i=0; i<col; i++)
	{
        for(j=0; j<row; j++)
            somma+=a[j][i]; //somma=somma+a[j][i];
        if(somma>max)
            max=somma;
	}
    return max;
}


/*---------------------------------------------- TRACCIA 5 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array 2D di int,
	il numero delle righe e il numero delle colonne, determina e restituisce
	come parametro di output il massimo tra le somme degli elementi di ogni riga.
*/

int traccia5(int a[][100], int row, int col)
{
    int i, j, somma=0, max=0;
    for(i=0; i<row; i++)
	{
        for(j=0; j<col; j++)
            somma+=a[i][j];
        if(somma>max)
            max=somma;
	}
    return max;
}


/*---------------------------------------------- TRACCIA 6 -------------------------------------------*/
/*
	Scrivere una funzione che dati in input due array ordinati (rispetto al campo matricola)
	di elementi della seguente struttura:
	struct studente {
		char *nome;
		char *cognome;
		int matricola;
	};
	restituisca in output l'array fusione dei due array.
	La fusione deve avvenire in base al campo matricola.
 */

struct studente
{
    char *nome;
    char *cognome;
    int matricola;
};

typedef struct studente Studente;

void traccia6(Studente a[], int n_a, Studente b[], int n_b, Studente c[]) //se senza il typedef è di tipo "struct studente"
{
    int i_a=0, i_b=0, i_c=0;
    while(i_a<n_a && i_b<n_b)
    {
        if(a[i_a].matricola<b[i_b].matricola)
            c[i_c++]=a[i_a++];
        else
            c[i_c++]=b[i_b++];
    }
    while(i_a<n_a)
        c[i_c++]=a[i_a++];
    while(i_b<n_b)
        c[i_c++]=b[i_b++];
}


/*---------------------------------------------- TRACCIA 7 -------------------------------------------*/
/*
	Scrivere una funzione che dati in input due array di strutture del seguente tipo
	struct prodotto {char *nome; int codice; double prezzo;};
	restituisce in output 1 se i due array di struct sono uguali, 0 se non lo sono.
	Si noti che due dati struct sono uguali se sono uguali tutti i loro campi.
*/

struct prodotto
{
    char *nome;
    int codice;
    double prezzo;
};

typedef struct prodotto Prodotto;

int uguale(Prodotto p1, Prodotto p2) //se senza il typedef è di tipo "struct prodotto"
{
    if(strcmp(p1.nome, p2.nome) == 0 && p1.codice==p2.codice && p1.prezzo==p2.prezzo)
        return 1;
    else
        return 0;
}

int traccia7(Prodotto p1[], int n1, Prodotto p2[], int n2) //se senza il typedef è di tipo "struct prodotto"
{
    if(n1!=n2)
    {
        return 0;
    }
    for(int i=0; i<n1; i++)
    {
        if(!uguale(p1[i], p2[i]))
            return 0;
    }
    return 1;
}


/*---------------------------------------------- TRACCIA 8 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
	come parametro di output il numero di parole di tre lettere contenute nel
	testo. Nel testo le parole sono separate da un unico spazio.
*/

int traccia8(char *testo)
{
    char *token=strtok(testo, " "); //strtok: Spezza la stringa testo in una serie di stringhe chiamate "token" in corrispondenza dei carattere delimitatore(nel nostro caso " ", spazio vuoto)
    int count=0;
    while(token!=NULL)
    {
        if(strlen(token)==3)
            count++;
        token=strtok(NULL, " "); //estrae la prossima parola dal testo fino a quando non trova NULL o il delimitatore specificato.
    }
    return count;
}


/*---------------------------------------------- TRACCIA 9 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
	come parametro di output il numero di parole che terminano in are contenute nel
	testo. Nel testo le parole sono separate da un unico spazio.
*/

int traccia9(char *testo)
{
    int count=0;
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        if(strlen(token)>=3)
        {
            if(strcmp(&token[strlen(token)-3], "are")==0)
                count++;
        }
        token=strtok(NULL, " ");
    }
    return count;
}


/*---------------------------------------------- TRACCIA 10 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametro di output il numero di parole che iniziano con a e terminano
	con e contenute nel testo. Nel testo le parole sono separate
 	da un unico spazio.
*/

int traccia10(char *testo)
{
    int count=0;
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        if((token[0]=='a') && (token[strlen(token)-1]=='e'))
            count++;
        token=strtok(NULL, " ");
    }
    return count;
}


/*---------------------------------------------- TRACCIA 11 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametro di output il numero delle parole contenute nel testo che
	hanno almeno 5 vocali. Nel testo le parole sono separate da
 	un unico spazio.
*/

int check_vocali(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return 1;
    else
        return 0;
}

int traccia11(char *testo)
{
    int i, j=0, k=0;
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        for(i=0; i<strlen(token); i++)
        {
            if(check_vocali(token[i]))
                j++;
        }
        if(j>=5)
            k++;
        token=strtok(NULL, " ");
    }
    return k;
}


/*---------------------------------------------- TRACCIA 12 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametri di output la parola di lunghezza massima contenuta nel testo
	e la sua lunghezza. Nel testo le parole sono separate da un unico spazio. 
*/

void traccia12(char *testo, char *parola_max, int *max)
{
    *max=0;
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        if(strlen(token)>*max)
        {
            *max=strlen(token);
            strcpy(parola_max, token);
        }
        token=strtok(NULL, " ");
    }
}


/*---------------------------------------------- TRACCIA 13 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
 	rappresenta un testo in italiano, determina e restituisce come parametri di
	output la parola di lunghezza minima contenuta nel testo e la sua lunghezza.
	Nel testo le parole sono separate da un unico spazio.
*/

void traccia13(char *testo, char *parola_min, int *min)
{
    *min=strlen(testo);
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        if(strlen(token)<*min)
        {
            *min=strlen(token);
            strcpy(parola_min, token);
        }
        token=strtok(NULL, " ");
    }
}


/*---------------------------------------------- TRACCIA 14 -------------------------------------------*/
/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce come parametri di
	output la parola di lunghezza minima contenuta nel testo e la posizione di
	inizio della parola nella stringa. Nel testo le parole sono separate da un unico spazio.
*/

void traccia14(char *testo, char *parola_min, int *pos)
{
	int min=strlen(testo);
    char *token=strtok(testo, " ");
    while(token!=NULL)
    {
        if(strlen(token)<min)
        {
            min=strlen(token);
            strcpy(parola_min, token);
            *pos=token;
        }
        token=strtok(NULL, " ");
    }
}


/*---------------------------------------------- TRACCIA 15 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di char
 	e il suo size, determina e restituisce come parametro di output l'array
 	(di size 21) del numero delle occorrenze delle 21 lettere dell'alfabeto
 	italiano (per es. il numero di occorrenze della lettera a è il numero di
	volte in cui la lettera a compare nel testo).
*/

void traccia15(char testo[], int n, int *occorrenze)
{
    int i, j;
    char alfabeto[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
	strlwr(testo);
    for(i=0; testo[i]!=NULL; i++)
    {
        for (j=0; j<n; j++)
            if(testo[i]==alfabeto[j])
                occorrenze[j]++;
    }
}


/*---------------------------------------------- TRACCIA 16 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro di output l'array occorrenze 
	(di size 21) del numero delle occorrenze dell'evento a precede ognuna delle 21 
	lettere dell'alfabeto italiano (cioè occorrenze[0] è il numero di volte in cui 
	accade che a precede a, cioè che nel testo compare aa, occorrenze[1] è il 
	numero di volte in cui accade che a precede b, cioè che nel testo compare ab,
	occorrenze[2] è il numero di volte in cui accade che a precede c, cioè che 
	nel testo compare ac).
*/

void traccia16(char *testo, int n, int *occorrenze)
{
	int i;
    char *parola, alfabeto[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
	strlwr(testo);
    for(parola=strchr(testo, 'a'); parola!=NULL; parola=strchr(parola+1, 'a')) // Cerca la prima occorrenza di 'a' nel testo
    {
        for (i=0; i<n; i++) // Scorro l'alfabeto e verifico se il carattere successivo a 'a' corrisponde ad uno dei caratteri dell'alfabeto
            if (*(parola+1)==alfabeto[i])
                occorrenze[i]++; 
    }
}


/*---------------------------------------------- TRACCIA 17 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro un dato logico che
	indica se il testo nell'array è un pangramma, ovvero un testo che contiene,
	almeno una volta, tutte le 21 lettere dell'alfabeto italiano.
*/

typedef enum{false, true} boolean;

boolean traccia17(char *testo, int n)
{
    boolean alphabet[21] = {false}; // Array per tenere traccia delle lettere presenti
    int i;
    // Itera attraverso la stringa e segna le lettere presenti nell'alfabeto
    for (i = 1; i < n; i++) // inizia da 1, in modo che possiamo verificare se 'a' precede il carattere corrente.
    {
		char c = tolower(testo[i]);
        if (c >= 'a' && c <= 'z')
            alphabet[c - 'a'] = true; //conteggia quante volte ciascuna lettera dell'alfabeto italiano appare dopo la lettera 'a' nel testo.
    }
    // Controlla se tutte le lettere dell'alfabeto sono presenti
    for (i = 0; i < 21; i++)
    {
        if (!alphabet[i])
            return false;
    }
    return true;
}


/*---------------------------------------------- TRACCIA 18 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro di output il carattere 
	più frequente. 
*/

char traccia18(char *testo, int n)
{
    int i, frequenze[26]= {0}, max_frequenza = 0;
    char piu_comune = '\0';
    for (i = 0; i < n; i++)
    {
		char c = tolower(testo[i]);
        frequenze[c]++;
        if (frequenze[c] > max_frequenza)
		{
            max_frequenza = frequenze[c];
            piu_comune = c;
		}
    }
    return piu_comune;
}


/*---------------------------------------------- TRACCIA 19 -------------------------------------------*/
/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro di output il carattere 
	meno frequente. 
*/

char traccia19(char *testo, int n)
{
    int i, frequenze[26]={0}, min_frequenza = 0;
    char meno_comune = '\0';
    for (i = 0; i < n; i++)
    {
		c = tolower(testo[i]);
        frequenze[c]++;
        if (frequenze[c] < min_frequenza && frequenze[c] > 0)
		{
            min_frequenza = frequenze[c];
            meno_comune = c;
		}
    }
    return meno_comune;
}


/*---------------------------------------------- TRACCIA 20 -------------------------------------------*/
/*
	Dato un elenco (array) di persone partecipanti a un concorso, ordinare l'elenco in ordine alfabetico
 	in base al campo cognome. La struttura che identifica il partecipante come:
 	struct persona {char *nome; char *cognome;};
 	typedef struct persona id;
 	struct partecipante {id *utente; unsigned short codice; };
*/

struct persona
{
    char nome[100];
    char cognome[100];
};

typedef struct persona id;

struct partecipante
{
    id *utente;
    unsigned short codice;
};

typedef struct partecipante Partecipante;

void traccia20(Partecipante *lista, int n)
{
    Partecipante el_da_ins;
    int i, j;
    for(i=1; i<n; i++)
    {
        el_da_ins=lista[i];
        j=i-1;
        while(j>=0 && strcmp(el_da_ins.utente->cognome, lista[j].utente->cognome)<0)
        {
            lista[j+1]=lista[j];
            j--;
        }
        lista[j+1]=el_da_ins;
    }
}


/*---------------------------------------------- TRACCIA 21 -------------------------------------------*/
/*
	Scrivere un programma per simulare l'inserimento di un PIN per il telefonino.
	Nella prima fase viene costruito il PIN di riferimento,che deve essere di
	lunghezza 5 e che deve essere costruito in modo casuale.
	Nella seconda fase l'utente inserisce il codice di tentativo e ha al massimo
	3 tentativi per indovinarlo. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Inizializza il generatore di numeri casuali con il tempo attuale

    // Fase 1: Generazione del PIN di riferimento
    int pinDiRiferimento = 10000 + rand() % 90000; // Genera un numero casuale da 10000 a 99999

    // Fase 2: Tentativi dell'utente
    int tentativi = 3, tentativo;
	int pin_corretto=0; // Variabile per tenere traccia del PIN corretto

    printf("Inserisci il PIN di 5 cifre:\n");

    while (tentativi > 0 && !pin_corretto)
    {
        printf("Tentativi rimasti: %d\n", tentativi);
        scanf("%d", &tentativo);

        if (tentativo == pinDiRiferimento)
        {
            printf("PIN corretto! Accesso consentito.\n");
            pin_corretto = 1; // Imposta il flag a 1 per indicare che il PIN è corretto
		}
        else   
		{			
            printf("PIN errato. Riprova.\n");
            tentativi--;  
		}			
    }

    if (tentativi == 0)
    {
        printf("Tentativi esauriti. Accesso negato.\n");
    }

    return 0;
}


/*---------------------------------------------- TRACCIA 22 -------------------------------------------*/
/*
	Due giocatori si sfidano lanciando un dado truccato. Il dado ha dei valori
	interi nell'intervallo[5,15]. A ogni turno vince il giocatore che ottiene un
	puntaggio maggiore. In caso di parità il punto viene assegnato a entrambi.
 	Simulare 10 sfide e visualizzare il giocatore che vince più volte.  
*/

void main()
{
    srand(time(NULL));
    int i, dado1, dado2, player1=0, player2=0;
    for(i=0; i<10; i++)
    {
        dado1=5+rand()%11;
        dado2=5+rand()%11;
        if(dado1>dado2)
            player1++;
        else if(dado1<dado2)
            player2++;
        else
        {
            player1++;
            player2++;
        }
    }
    if(player1>player2)
        printf("Ha vinto player1\n");
    else if(player1<player2)
        printf("Ha vinto player2\n");
    else
        printf("Parità\n");
}


/*---------------------------------------------- TRACCIA 23 -------------------------------------------*/
/*
	Scrivere una function C che ha come input i dati che identificano uno studente 
	(nome, cognome, matricola) e che restituisce in output una struttura dati opportuna, che contiene 
	i dati di identificazione e il libretto universitario con al massimo 20 esami. 
	Ogni esame è caratterizzato	da denominazione, cfu e voto.   
*/

// Struttura per rappresentare un singolo esame
struct Esame
{
    char denominazione[50];
    int cfu;
    int voto;
};

// Struttura per rappresentare uno studente con il libretto universitario
struct Studente
{
    char nome[50];
    char cognome[50];
    int matricola;
    struct Esame libretto[20];
    int numEsami;
};

// Funzione per creare e restituire una struttura Studente
struct Studente creaStudente(char *nome, char *cognome, int matricola)
{
    struct Studente studente;
    strcpy(studente.nome, nome);
    strcpy(studente.cognome, cognome);
    studente.matricola = matricola;
    studente.numEsami = 0; // Inizialmente nessun esame nel libretto
    return studente;
}
