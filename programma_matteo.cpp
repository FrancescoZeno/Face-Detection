// scrivere la procedura acquisto
// la procedura "cancfisutenti" funziona solo se accedi solamente come admin
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void registrazione_accesso();
void visutenti();
void inserimento();
void visualizzazione();
void ricerca();
void modifica();
void cancellazionelogica();
void cancellazionefisica();
void canclogutenti();
void cancfisutenti();
void ordinamento();
void ordinamento2();
void eliminafile();
void acquisto();
void cambionomeutente();
void cambiopwd();
struct articoli
{
	int codice;
	char descrizione[100];
	float prezzo;
	int quantita;
	int canc;
};
struct utenti
{
	char nomeutente[100];
	char password[100];
	int canc;
};
articoli bufarticoli;
utenti bufutenti;
FILE * fp;
FILE * fputenti;
bool admin = false, utente = false;
char nomeutente[100], password[100];
int main()
{
	int scelta;
	do 
	{
		cout << "\n";
		cout << "Digita 1 per registrarti, accedere o uscire. " << endl;
		cout << "Digita 0 per uscire dal programma. " << endl;
		cout << "\n";
		cout << "SEZIONE ADMIN: " << endl;
		cout << "Digita 2 per visualizzare tutti gli utenti registrati. " << endl;
		cout << "Digita 3 per inserire un articolo. " << endl;
		cout << "Digita 4 per visualizzare tutti gli articoli. " << endl;
		cout << "Digita 5 per cercare un articolo. " << endl;
		cout << "Digita 6 per modificare un articolo. " << endl;
		cout << "Digita 7 per cancellare logicamente (articoli). " << endl;
		cout << "Digita 8 per cancellare fisicamente (articoli). " << endl;
		cout << "Digita 9 per cancellare logicamente (utenti). " << endl;
		cout << "Digita 10 per cancellare fisicamente (utenti). " << endl;
		cout << "Digita 11 per ordinare gli articoli in base al prezzo. " << endl;
		cout << "Digita 12 per ordinare gli articoli in base alla quantita'. " << endl;
		cout << "Digita 13 per eliminare uno o piu' file. " << endl;
		cout << "\n";
		cout << "SEZIONE UTENTE: " << endl;
		cout << "Digita 14 per visualizzare tutti gli articoli. " << endl;
		cout << "Digita 15 per cercare un articolo. " << endl;
		cout << "Digita 16 per acquistare uno o piu' articoli. " << endl;
		cout << "Digita 17 per cambiare il tuo nome utente. " << endl;
		cout << "Digita 18 per cambiare la tua password. " << endl;
		cout << "\n";
		cout << "Scelta: ";
		cin >> scelta;
		switch(scelta)
		{
			case 0:
				system("cls");
				cout << "\n";
				cout << "Sto uscendo dal programma! " << endl;
				break;
			case 1:
				registrazione_accesso();
				break;
			case 2:
				visutenti();
				break;
			case 3:
				inserimento();
				break;
			case 4:
				visualizzazione();
				break;
			case 5:
				ricerca();
				break;
			case 6:
				modifica();
				break;
			case 7:
				cancellazionelogica();
				break;
			case 8:
				cancellazionefisica();
				break;
			case 9:
				canclogutenti();
				break;
			case 10:
				cancfisutenti();
				break;
			case 11:
				ordinamento();
				break;
			case 12:
				ordinamento2();
				break;
			case 13:
				eliminafile();
				break;
			case 14:
				visualizzazione();
				break;
			case 15:
				ricerca();
				break;
			case 16:
				acquisto();
				break;
			case 17:
				cambionomeutente();
				break;
			case 18:
				cambiopwd();
				break;
			default:
				system("cls");
				cout << "\n";
				cout << "Scelta non valida. " << endl;
				cout << "\n";
				system("pause");
				system("cls");
		}
	}
	while(scelta != 0);
	return 0;
}
void acquisto()
{
	system("cls");
	if(!utente)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei un cliente! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r+");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "\n";
	cout << "Coming soon ... " << endl;
	cout << "\n";
	system("pause");
	system("cls");
}
void cambionomeutente()
{
	system("cls");
	if(!utente)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei un cliente! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fputenti = fopen("utenti.dat", "r+");
	if(fputenti == NULL)
	{
		cout << "\n";
		cout << "Il file degli utenti \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Hai fatto l'accesso con il profilo " << nomeutente << ". Vuoi procedere(1) o cambiare profilo(2)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		char pwd[100];
		cout << "\n";
		cout << "Inserisci la tua password: ";
		fflush(stdin);
		gets(pwd);
		if(strcmp(pwd, password) == 0)
		{
			while(fread( & bufutenti, sizeof(utenti), 1, fputenti))
			{
				if(strcmp(nomeutente, bufutenti.nomeutente) == 0)
				{
					cout << "\n";
					cout << "Inserisci un nuovo nome utente: ";
					fflush(stdin);
					gets(bufutenti.nomeutente);
					bufutenti.canc = 0;
					fseek(fputenti, -sizeof(utenti), SEEK_CUR);
					fwrite( & bufutenti, sizeof(utenti), 1, fputenti);
					fseek(fputenti, sizeof(utenti), SEEK_CUR);
					strcpy(nomeutente, bufutenti.nomeutente);
					cout << "\n";
					cout << "Nome utente modificato con successo. " << endl;
					cout << "\n";
					system("pause");
					system("cls");
				}
			}
		}
		else
		{
			cout << "\n";
			cout << "Password errata! " << endl;
			cout << "\n";
			system("pause");
			system("cls");
		}
	}
	else if(scelta == 2)
	{
		cout << "\n";
		cout << "Sto tornando al menu principale! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void cambiopwd()
{
	system("cls");
	if(!utente)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei un cliente! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fputenti = fopen("utenti.dat", "r+");
	if(fputenti == NULL)
	{
		cout << "\n";
		cout << "Il file degli utenti \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Hai fatto l'accesso con il profilo " << nomeutente << ". Vuoi procedere(1) o cambiare profilo(2)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		char pwd[100];
		cout << "\n";
		cout << "Inserisci la tua password: ";
		fflush(stdin);
		gets(pwd);
		if(strcmp(pwd, password) == 0)
		{
			while(fread( & bufutenti, sizeof(utenti), 1, fputenti))
			{
				if(strcmp(nomeutente, bufutenti.nomeutente) == 0)
				{
					cout << "\n";
					cout << "Inserisci una nuova password: ";
					fflush(stdin);
					gets(bufutenti.password);
					bufutenti.canc = 0;
					fseek(fputenti, -sizeof(utenti), SEEK_CUR);
					fwrite( & bufutenti, sizeof(utenti), 1, fputenti);
					fseek(fputenti, sizeof(utenti), SEEK_CUR);
					strcpy(password, bufutenti.password);
					cout << "\n";
					cout << "Password modificata con successo. " << endl;
					cout << "\n";
					system("pause");
					system("cls");
				}
			}
		}
		else
		{
			cout << "\n";
			cout << "Password errata! " << endl;
			cout << "\n";
			system("pause");
			system("cls");
		}
	}
	else if(scelta == 2)
	{
		cout << "\n";
		cout << "Sto tornando al menu principale! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void cancellazionefisica()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	bool trovato = false;
	while(fread( & bufarticoli, sizeof(articoli), 1, fp) and !trovato)
	{
		if(bufarticoli.canc == 1)
		{
			trovato = true;
		}
	}
	if(!trovato)
	{
		cout << "\n";
		cout << "Esegui prima la cancellazione logica. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fclose(fp);
	fp = fopen("articoli.dat", "r");
	FILE * fp2 = fopen("articoli2.dat", "w");
	while(fread( & bufarticoli, sizeof(articoli), 1, fp))
	{
		if(bufarticoli.canc == 0)
		{
			fwrite( & bufarticoli, sizeof(articoli), 1, fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	remove("articoli.dat");
	rename("articoli2.dat", "articoli.dat");
	cout << "\n";
	cout << "Procedura di cancellazione fisica (articoli) completata. " << endl;
	cout << "\n";
	system("pause");
	system("cls");
}
void cancellazionelogica()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r+");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Vuoi effettuare la cancellazione logica per codice(1) o categoria(2)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		int codice;
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci il codice: ";
		cin >> codice;
		while(fread( & bufarticoli, sizeof(articoli), 1, fp) and!trovato)
		{
			if(codice == bufarticoli.codice)
			{
				bufarticoli.canc = 1;
				cout << "\n";
				cout << "Articolo eliminato logicamente. " << endl;
				fseek(fp, -sizeof(articoli), SEEK_CUR);
				fwrite( & bufarticoli, sizeof(articoli), 1, fp);
				fseek(fp, sizeof(articoli), SEEK_CUR);
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 2)
	{
		char descrizione[100];
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci la categoria: ";
		fflush(stdin);
		gets(descrizione);
		while(fread( & bufarticoli, sizeof(articoli), 1, fp) and!trovato)
		{
			if(strcmp(descrizione, bufarticoli.descrizione) == 0)
			{
				bufarticoli.canc = 1;
				cout << "\n";
				cout << "Articolo eliminato logicamente. " << endl;
				fseek(fp, -sizeof(articoli), SEEK_CUR);
				fwrite( & bufarticoli, sizeof(articoli), 1, fp);
				fseek(fp, sizeof(articoli), SEEK_CUR);
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void cancfisutenti()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fputenti = fopen("utenti.dat", "r");
	if(fputenti == NULL)
	{
		cout << "\n";
		cout << "Il file degli utenti \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	bool trovato = false;
	while(fread( & bufutenti, sizeof(utenti), 1, fputenti) and !trovato)
	{
		if(bufutenti.canc == 1)
		{
			trovato = true;
		}
	}
	if(!trovato)
	{
		cout << "\n";
		cout << "Esegui prima la cancellazione logica. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fclose(fputenti);
	fputenti = fopen("utenti.dat", "r");
	FILE * fputenti2 = fopen("utenti2.dat", "w");
	while(fread( & bufutenti, sizeof(utenti), 1, fputenti))
	{
		if(bufutenti.canc == 0)
		{
			fwrite( & bufutenti, sizeof(utenti), 1, fputenti2);
		}
	}
	fclose(fputenti);
	fclose(fputenti2);
	remove("utenti.dat");
	rename("utenti2.dat", "utenti.dat");
	cout << "\n";
	cout << "Procedura di cancellazione fisica (utenti) completata. " << endl;
	cout << "\n";
	system("pause");
	system("cls");
}
void canclogutenti()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fputenti = fopen("utenti.dat", "r+");
	if(fputenti == NULL)
	{
		cout << "\n";
		cout << "Il file degli utenti \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	char nomeutente[100];
	bool trovato = false;
	cout << "\n";
	cout << "Inserisci il nome utente: ";
	fflush(stdin);
	gets(nomeutente);
	while(fread( & bufutenti, sizeof(utenti), 1, fputenti) and!trovato)
	{
		if(strcmp(nomeutente, bufutenti.nomeutente) == 0)
		{
			bufutenti.canc = 1;
			cout << "\n";
			cout << "Utente eliminato logicamente. " << endl;
			fseek(fputenti, -sizeof(utenti), SEEK_CUR);
			fwrite( & bufutenti, sizeof(utenti), 1, fputenti);
			fseek(fputenti, sizeof(utenti), SEEK_CUR);
			trovato = true;
		}
	}
	if(!trovato)
	{
		cout << "\n";
		cout << "Utente inesistente. ";
		cout << "\n";
	}
	fclose(fputenti);
	cout << "\n";
	system("pause");
	system("cls");
}
void eliminafile()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Vuoi eliminare il file degli articoli(1), il file degli utenti(2), o entrambi(3)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		fclose(fp);
		remove("articoli.dat");
		cout << "\n";
		cout << "Il file degli articoli \202 stato eliminato. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 2)
	{
		fclose(fputenti);
		remove("utenti.dat");
		cout << "\n";
		cout << "Il file degli utenti \202 stato eliminato. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 3)
	{
		fclose(fputenti);
		remove("utenti.dat");
		fclose(fp);
		remove("articoli.dat");
		cout << "\n";
		cout << "Entrambi i file sono stati eliminati. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void inserimento()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "a+");
	int codice;
	bool trovato = false;
	cout << "\n";
	cout << "Inserisci il codice: ";
	cin >> codice;
	fseek(fp, 0, SEEK_SET);
	while(fread( & bufarticoli, sizeof(articoli), 1, fp) and!trovato)
	{
		if(codice == bufarticoli.codice)
		{
			trovato = true;
			cout << "\n";
			cout << "Codice gia' esistente. Inseriscine un altro! " << endl;
		}
	}
	if(!trovato)
	{
		bufarticoli.codice = codice;
		cout << "Inserisci la descrizione: ";
		fflush(stdin);
		gets(bufarticoli.descrizione);
		cout << "Inserisci il prezzo: ";
		cin >> bufarticoli.prezzo;
		cout << "Inserisci la quantita: ";
		cin >> bufarticoli.quantita;
		bufarticoli.canc = 0;
		fwrite( & bufarticoli, sizeof(articoli), 1, fp);
	}
	fclose(fp);
	cout << "\n";
	system("pause");
	system("cls");
}
void modifica()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r+");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Vuoi effettuare la modifica per codice(1) o categoria(2)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		int codice;
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci il codice: ";
		cin >> codice;
		while(fread( & bufarticoli, sizeof(articoli), 1, fp) and!trovato)
		{
			if(codice == bufarticoli.codice)
			{
				cout << "\n";
				cout << "Inserisci il codice: ";
				cin >> bufarticoli.codice;
				cout << "Inserisci la descrizione: ";
				fflush(stdin);
				gets(bufarticoli.descrizione);
				cout << "Inserisci il prezzo: ";
				cin >> bufarticoli.prezzo;
				cout << "Inserisci la quantita: ";
				cin >> bufarticoli.quantita;
				bufarticoli.canc = 0;
				fseek(fp, -sizeof(articoli), SEEK_CUR);
				fwrite( & bufarticoli, sizeof(articoli), 1, fp);
				fseek(fp, sizeof(articoli), SEEK_CUR);
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 2)
	{
		char descrizione[100];
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci la categoria: ";
		fflush(stdin);
		gets(descrizione);
		while(fread( & bufarticoli, sizeof(articoli), 1, fp) and!trovato)
		{
			if(strcmp(descrizione, bufarticoli.descrizione) == 0)
			{
				cout << "\n";
				cout << "Inserisci il codice: ";
				cin >> bufarticoli.codice;
				cout << "Inserisci la descrizione: ";
				fflush(stdin);
				gets(bufarticoli.descrizione);
				cout << "Inserisci il prezzo: ";
				cin >> bufarticoli.prezzo;
				cout << "Inserisci la quantita: ";
				cin >> bufarticoli.quantita;
				bufarticoli.canc = 0;
				fseek(fp, -sizeof(articoli), SEEK_CUR);
				fwrite( & bufarticoli, sizeof(articoli), 1, fp);
				fseek(fp, sizeof(articoli), SEEK_CUR);
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void ordinamento()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r+");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fseek(fp, 0, SEEK_END);
	int n = ftell(fp) / sizeof(articoli);
	fseek(fp, 0, SEEK_SET);
	articoli a, b;
	bool scambio = true;
	while(scambio)
	{
		scambio = false;
		for(int i = 0; i < n - 1; i++)
		{
			fseek(fp, sizeof(articoli) * i, SEEK_SET);
			fread( & a, sizeof(articoli), 1, fp);
			fread( & b, sizeof(articoli), 1, fp);
			if(a.prezzo > b.prezzo)
			{
				fseek(fp, sizeof(articoli) * i, SEEK_SET);
				fwrite( & b, sizeof(articoli), 1, fp);
				fwrite( & a, sizeof(articoli), 1, fp);
				scambio = true;
			}
		}
	}
	fclose(fp);
	cout << "\n";
	cout << "Ordinamento completato. " << endl;
	cout << "\n";
	system("pause");
	system("cls");
}
void ordinamento2()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r+");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fseek(fp, 0, SEEK_END);
	int n = ftell(fp) / sizeof(articoli);
	fseek(fp, 0, SEEK_SET);
	articoli a, b;
	bool scambio = true;
	while(scambio)
	{
		scambio = false;
		for(int i = 0; i < n - 1; i++)
		{
			fseek(fp, sizeof(articoli) * i, SEEK_SET);
			fread( & a, sizeof(articoli), 1, fp);
			fread( & b, sizeof(articoli), 1, fp);
			if(a.quantita < b.quantita)
			{
				fseek(fp, sizeof(articoli) * i, SEEK_SET);
				fwrite( & b, sizeof(articoli), 1, fp);
				fwrite( & a, sizeof(articoli), 1, fp);
				scambio = true;
			}
		}
	}
	fclose(fp);
	cout << "\n";
	cout << "Ordinamento completato. " << endl;
	cout << "\n";
	system("pause");
	system("cls");
}
void registrazione_accesso()
{
	system("cls");
	int scelta;
	do {
		cout << "\n";
		cout << "Digita 1 per accedere come ADMIN. " << endl;
		cout << "Digita 2 per registrarti come UTENTE. " << endl;
		cout << "Digita 3 per accedere come UTENTE. " << endl;
		cout << "Digita 4 per uscire dal tuo account ADMIN. "<<endl;
		cout << "Digita 5 per uscire dal tuo account UTENTE. "<<endl;
		cout << "Digita 0 per uscire. " << endl;
		cout << "Scelta: ";
		cin >> scelta;
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				cout<<"\n";
				string nomeutente, password;
				if (admin)
				{
					cout<<"Hai gia' fatto l'accesso come ADMIN! "<<endl;
				}
				else
				{
					cout << "Inserisci il nome utente: ";
					cin >> nomeutente;
					cout << "Inserisci la password: ";
					cin >> password;
					if(nomeutente == "admin" and password == "password")
					{
						cout << "\n";
						cout << "Accesso effettuato come ADMIN. " << endl;
						admin = true;
					}
					else
					{
						cout << "\n";
						cout << "Credenziali errate, accesso bloccato! " << endl;
						admin = false;
					}
				}
				cout << "\n";
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				fputenti = fopen("utenti.dat", "a+");
				char nomeutente[100], password[100];
				bool trovato = false;
				cout << "\n";
				cout << "Inserisci un nome utente: ";
				fflush(stdin);
				gets(nomeutente);
				while(fread( & bufutenti, sizeof(utenti), 1, fputenti) and!trovato)
				{
					if(strcmp(nomeutente, bufutenti.nomeutente) == 0)
					{
						trovato = true;
						cout << "\n";
						cout << "Nome utente gia' esistente. Inseriscine un altro! " << endl;
					}
				}
				if(!trovato)
				{
					cout << "Inserisci una password: ";
					gets(password);
					strcpy(bufutenti.nomeutente, nomeutente);
					strcpy(bufutenti.password, password);
					bufutenti.canc = 0;
					fwrite( & bufutenti, sizeof(utenti), 1, fputenti);
					cout << "\n";
					cout << "Registrazione completata." << endl;
				}
				fclose(fputenti);
				cout << "\n";
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				system("cls");
				fputenti = fopen("utenti.dat", "r");
				if(fputenti == NULL)
				{
					cout << "\n";
					cout << "Non puoi accedere se prima non ti registri! " << endl;
				}
				else
				{
					bool trovato = false;
					cout << "\n";
					cout << "Inserisci il tuo nome utente: ";
					fflush(stdin);
					gets(nomeutente);
					cout << "Inserisci la tua password: ";
					gets(password);
					while(fread( & bufutenti, sizeof(utenti), 1, fputenti) and !trovato)
					{
						if(strcmp(nomeutente, bufutenti.nomeutente) == 0 and strcmp(password, bufutenti.password) == 0)
						{
							trovato = true;
						}
					}
					if(trovato)
					{
						cout << "\n";
						cout << "Accesso effettuato. Benvenuto " << nomeutente << "! " << endl;
						utente = true;
					}
					else
					{
						cout << "\n";
						cout << "Non risulta esserci nessun utente registrato con queste credenziali! " << endl;
						utente = false;
					}
				}
				cout << "\n";
				system("pause");
				system("cls");
				break;
			}
			case 4:
				system("cls");
				cout<<"\n";
				if (!admin)
				{
					cout<<"Non puoi uscire se prima non accedi! "<<endl;
				}
				else
				{
					admin=false;
					cout<<"Sei uscito dal tuo account ADMIN. "<<endl;
				}
				cout<<"\n";
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				cout<<"\n";
				if (!utente)
				{
					cout<<"Non puoi uscire se prima non accedi! "<<endl;
				}
				else
				{
					utente=false;
					cout<<"Sei uscito dal tuo account UTENTE. "<<endl;
				}
				cout<<"\n";
				system("pause");
				system("cls");
				break;
			case 0:
				system("cls");
				cout << "\n";
				cout << "Sto tornando al menu principale! " << endl;
				cout << "\n";
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				cout << "\n";
				cout << "Scelta non valida! " << endl;
				cout << "\n";
				system("pause");
				system("cls");
		}
	}
	while(scelta != 0);
}
void ricerca()
{
	system("cls");
	if(!admin and!utente)
	{
		cout << "\n";
		cout << "Devi accedere prima di poter ricercare un articolo. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	int scelta;
	cout << "\n";
	cout << "Vuoi effettuare la ricerca per codice(1), categoria(2) o prezzo(3)? ";
	cin >> scelta;
	if(scelta == 1)
	{
		int codice;
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci il codice: ";
		cin >> codice;
		while(fread( & bufarticoli, sizeof(articoli), 1, fp))
		{
			if(codice == bufarticoli.codice)
			{
				cout << "\n";
				cout << "Descrizione: ";
				puts(bufarticoli.descrizione);
				cout << "Prezzo: ";
				cout << bufarticoli.prezzo << endl;
				cout << "Quantita: ";
				cout << bufarticoli.quantita << endl;
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 2)
	{
		char descrizione[100];
		bool trovato = false;
		cout << "\n";
		cout << "Inserisci la categoria: ";
		fflush(stdin);
		gets(descrizione);
		while(fread( & bufarticoli, sizeof(articoli), 1, fp))
		{
			if(strcmp(descrizione, bufarticoli.descrizione) == 0)
			{
				cout << "\n";
				cout << "Codice: ";
				cout << bufarticoli.codice << endl;
				cout << "Prezzo: ";
				cout << bufarticoli.prezzo << endl;
				cout << "Quantita: ";
				cout << bufarticoli.quantita << endl;
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "\n";
			cout << "Articolo inesistente. ";
			cout << "\n";
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if(scelta == 3)
	{
		float prezzo;
		bool trovato = false;
		bool trovato2 = false;
		cout << "\n";
		cout << "Inserisci il prezzo: ";
		cin >> prezzo;
		cout << "\n";
		cout << "Articoli con un prezzo minore di " << prezzo << " euro: " << endl;
		while(fread( & bufarticoli, sizeof(articoli), 1, fp))
		{
			if(bufarticoli.prezzo < prezzo)
			{
				cout << "\n";
				cout << "Codice: " << bufarticoli.codice << endl;
				cout << "Descrizione: " << bufarticoli.descrizione << endl;
				cout << "Prezzo: " << bufarticoli.prezzo << endl;
				cout << "Quantita: " << bufarticoli.quantita << endl;
				trovato = true;
			}
		}
		if(!trovato)
		{
			cout << "Non c'\202 nessun articolo con un prezzo minore di " << prezzo << " euro. " << endl;
		}
		rewind(fp);
		cout << "\n";
		cout << "Articoli con un prezzo maggiore di " << prezzo << " euro: " << endl;
		while(fread( & bufarticoli, sizeof(articoli), 1, fp))
		{
			if(bufarticoli.prezzo > prezzo)
			{
				cout << "\n";
				cout << "Codice: " << bufarticoli.codice << endl;
				cout << "Descrizione: " << bufarticoli.descrizione << endl;
				cout << "Prezzo: " << bufarticoli.prezzo << endl;
				cout << "Quantita: " << bufarticoli.quantita << endl;
				trovato2 = true;
			}
		}
		if(!trovato2)
		{
			cout << "Non c'\202 nessun articolo con un prezzo maggiore di " << prezzo << " euro. " << endl;
		}
		fclose(fp);
		cout << "\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n";
		cout << "Scelta non valida. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
	}
}
void visualizzazione()
{
	system("cls");
	if(!admin and!utente)
	{
		cout << "\n";
		cout << "Devi accedere prima di poter visualizzare gli articoli. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fp = fopen("articoli.dat", "r");
	if(fp == NULL)
	{
		cout << "\n";
		cout << "Il file degli articoli \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fread( & bufarticoli, sizeof(articoli), 1, fp);
	while(!feof(fp))
	{
		cout << "\n";
		cout << "Codice: ";
		cout << bufarticoli.codice << endl;
		cout << "Descrizione: ";
		puts(bufarticoli.descrizione);
		cout << "Prezzo: ";
		cout << bufarticoli.prezzo << endl;
		cout << "Quantita: ";
		cout << bufarticoli.quantita << endl;
		fread( & bufarticoli, sizeof(articoli), 1, fp);
	}
	fclose(fp);
	cout << "\n";
	system("pause");
	system("cls");
}
void visutenti()
{
	system("cls");
	if(!admin)
	{
		cout << "\n";
		cout << "Accesso negato! Non sei l'admin! " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fputenti = fopen("utenti.dat", "r");
	if(fputenti == NULL)
	{
		cout << "\n";
		cout << "Il file degli utenti \202 vuoto. " << endl;
		cout << "\n";
		system("pause");
		system("cls");
		return;
	}
	fread( & bufutenti, sizeof(utenti), 1, fputenti);
	while(!feof(fputenti))
	{
		cout << "\n";
		cout << "Nome utente: ";
		cout << bufutenti.nomeutente << endl;
		cout << "Password: ";
		cout << bufutenti.password << endl;
		fread( & bufutenti, sizeof(utenti), 1, fputenti);
	}
	fclose(fputenti);
	cout << "\n";
	system("pause");
	system("cls");
}
