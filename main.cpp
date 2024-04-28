/**================================================================================================
 * *                                           INFO
 *  Autore: Francesco Zeno
 *  @email: kekkoz.dev@gmail.com
 *  File:   main.cpp
 *  Vers:   1.0
 *  Data:  26/04/2024
 *  Descrizione: Lavoro file Manno e Zeno
 * ?
 *================================================================================================**/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

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
    char nome[100], password[100];
    int canc;
};
enum TipoRicerca
{
    RICERCA_CODICE,
    RICERCA_DESCRIZIONE,
    ELIMINAZIONE_LOGICA,
    ELIMINAZIONE_LOGICA_UTENTE,
    MODIFICA_NOME,
    MODIFICA_PASSWORD
};

/*VARIBILI GLOBALI*/
articoli bufarticoli;
articoli bufcarrello;
utenti bufutenti;
string nome_file;
FILE *fp;
FILE *fputenti;
FILE *fpcarrello;
char nome[100], password[100];
/*FUNZIONI ACCESSO*/
void registrazione_utente(string nome, string password);
bool accesso_utente(string nome, string password);
bool accesso_admin(string password);

/*FUNZIONI CATALOGO*/
void caricamento_prodotto();
void visualizza_catalogo();
FILE *ricerca(const char *parametro_ricerca, int tipo);
FILE *ricerca_utenti(const char *parametro_ricerca, int tipo);

// acquisto
// eliminazione utente
// impostazioni utente
// conferma carrello
int main()
{
    system("cls");
    fputenti = fopen("utenti.dat", "a");
    fclose(fputenti);
    int scelta_uno, scelta_utente, scelta_admin, scelta_utente2;

    do
    {
        system("cls");
        cout << "Benvenuto nel MediShop!" << endl;
        cout << "1. Accedere come ADMIN\n2. Registrarsi come nuovo utente\n3. Accedi come utente gia' esistente\n0. Esci\n > ";
        cin >> scelta_uno;
        switch (scelta_uno)
        {
            /*-----ACCESSO ADMIN-----*/
        case 1:
            cout << "Inserisci password > ";
            cin >> password;
            if (accesso_admin(password))
            {
                cout << "Accesso autorizzato" << endl;
                do
                {
                    system("cls");
                    cout << "Menu: " << endl;
                    cout << "1. Inserire\n2. Visualizza\n3. Ordina\n4. Modifica prodotto\n5. Elimina prodotto\n0. Esci\n > ";
                    cin >> scelta_admin;
                    switch (scelta_admin)
                    {
                        /*-----MENU ADMIN-----*/
                    case 1:
                        caricamento_prodotto();
                        system("pause");
                        break;
                    case 2:
                        visualizza_catalogo();
                        system("pause");
                        break;
                    case 4:
                        int codice;
                        cout << "Inserisci il codice > ";
                        cin >> codice;
                        fp = ricerca(to_string(codice).c_str(), RICERCA_CODICE);
                        if (fp != NULL)
                        {
                            cout << "Inserisci il nuovo codice > ";
                            cin >> bufarticoli.codice;
                            cout << "Inserisci la nuova descrizione > ";
                            fflush(stdin);
                            gets(bufarticoli.descrizione);
                            cout << "Inserisci il nuovo prezzo > ";
                            cin >> bufarticoli.prezzo;
                            cout << "Inserisci la nuova quantita > ";
                            cin >> bufarticoli.quantita;
                            bufarticoli.canc = 0;
                            fseek(fp, -sizeof(articoli), SEEK_CUR);
                            fwrite(&bufarticoli, sizeof(articoli), 1, fp);
                            fseek(fp, sizeof(articoli), SEEK_CUR);
                        }
                        else
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    case 5:
                        cout << "Inserisci il codice > ";
                        cin >> codice;
                        fp = ricerca(to_string(codice).c_str(), RICERCA_CODICE);
                        if (fp != NULL)
                        {
                            bufarticoli.canc = 1;
                            cout << "Articolo eliminato. " << endl;
                            fseek(fp, -sizeof(articoli), SEEK_CUR);
                            fwrite(&bufarticoli, sizeof(articoli), 1, fp);
                            fseek(fp, sizeof(articoli), SEEK_CUR);
                            fclose(fp);
                            fp = fopen("articoli.dat", "r");
                            FILE *fp2 = fopen("articoli2.dat", "w");
                            while (fread(&bufarticoli, sizeof(articoli), 1, fp))
                            {
                                if (bufarticoli.canc == 0)
                                {
                                    fwrite(&bufarticoli, sizeof(articoli), 1, fp2);
                                }
                            }
                            fclose(fp);
                            fclose(fp2);
                            remove("articoli.dat");
                            rename("articoli2.dat", "articoli.dat");
                        }
                        else
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    default:
                        break;
                    }
                } while (scelta_admin != 0);
            }
            else
            {
                cout << "Password errata!" << endl;
                cout << "Accesso negato";
            }
            system("pause");
            break;
            /*-----REGISTRAZIONE UTENTE-----*/
        case 2:
            cout << "Inserisci il nome > ";
            cin >> nome;
            cout << "Inserire password > ";
            cin >> password;
            registrazione_utente(nome, password);
            system("pause");
            break;
            /*-----ACCESSO UTENTE-----*/
        case 3:
            cout << "Inserisci il nome > ";
            cin >> nome;
            cout << "Inserire password > ";
            cin >> password;
            if (accesso_utente(nome, password))
            {
                cout << "Accesso effettuato con successo!" << nome << endl;
                do
                {
                    system("cls");
                    cout << "Menu utente: " << endl;
                    cout << "1. Visualizza catalogo\n2. Ricerca prodotto per codice\n3. Ricerca prodotto per descrizione\n4. Ricerca prodotto per prezzo maggiore\n5. Ricerca prodotto per prezzo minore\n6. Acquista prodotto\n7. Profilo\n0. Esci\n > ";
                    cin >> scelta_utente;
                    switch (scelta_utente)
                    {
                        /*-----MENU UTENTE-----*/
                    case 1:
                    {
                        visualizza_catalogo();
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        int codice;
                        cout << "Inserisci il codice: ";
                        cin >> codice;
                        fp = ricerca(to_string(codice).c_str(), RICERCA_CODICE);
                        if (fp != NULL)
                        {
                            cout << "-----*-----*-----" << endl;
                            cout << "Codice >  ";
                            cout << bufarticoli.codice << endl;
                            cout << "Descrizione >  ";
                            puts(bufarticoli.descrizione);
                            cout << "Prezzo >  ";
                            cout << bufarticoli.prezzo << endl;
                            cout << "Quantita > ";
                            cout << bufarticoli.quantita << endl;
                            fclose(fp);
                        }
                        else
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        string descrizione;
                        cout << "Inserisci la descrizione: ";
                        cin.ignore();
                        getline(cin, descrizione);
                        fp = ricerca(descrizione.c_str(), RICERCA_DESCRIZIONE);
                        if (fp != NULL)
                        {
                            cout << "-----*-----*-----" << endl;
                            cout << "Codice >  ";
                            cout << bufarticoli.codice << endl;
                            cout << "Descrizione >  ";
                            puts(bufarticoli.descrizione);
                            cout << "Prezzo >  ";
                            cout << bufarticoli.prezzo << endl;
                            cout << "Quantita > ";
                            cout << bufarticoli.quantita << endl;
                        }
                        else
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    }
                    case 4:
                    {
                        float prezzo;
                        bool trv = false;
                        cout << "Inserisci il prezzo: ";
                        cin >> prezzo;
                        fp = fopen("articoli.dat", "r");
                        if (fp != NULL)
                        {
                            while (fread(&bufarticoli, sizeof(articoli), 1, fp))
                            {
                                if (bufarticoli.prezzo >= prezzo)
                                {
                                    cout << "-----*-----*-----" << endl;
                                    cout << "Codice >  ";
                                    cout << bufarticoli.codice << endl;
                                    cout << "Descrizione >  ";
                                    puts(bufarticoli.descrizione);
                                    cout << "Prezzo >  ";
                                    cout << bufarticoli.prezzo << endl;
                                    cout << "Quantita > ";
                                    cout << bufarticoli.quantita << endl;
                                    trv = true;
                                }
                            }
                            fclose(fp);
                        }
                        if (!trv)
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    }
                    case 5:
                    {
                        float prezzo;
                        bool trv = false;
                        cout << "Inserisci il prezzo: ";
                        cin >> prezzo;
                        fp = fopen("articoli.dat", "r");
                        if (fp != NULL)
                        {
                            while (fread(&bufarticoli, sizeof(articoli), 1, fp))
                            {
                                if (bufarticoli.prezzo <= prezzo)
                                {
                                    cout << "-----*-----*-----" << endl;
                                    cout << "Codice >  ";
                                    cout << bufarticoli.codice << endl;
                                    cout << "Descrizione >  ";
                                    puts(bufarticoli.descrizione);
                                    cout << "Prezzo >  ";
                                    cout << bufarticoli.prezzo << endl;
                                    cout << "Quantita > ";
                                    cout << bufarticoli.quantita << endl;
                                    trv = true;
                                }
                            }
                            fclose(fp);
                        }
                        if (!trv)
                        {
                            cout << "Articolo non trovato." << endl;
                        }
                        system("pause");
                        break;
                    }
                    case 7:
                    {
                        do
                        {
                            system("cls");
                            cout << "Menu impostazioni" << endl;
                            cout << "1. Cambiare nome\n2. Cambiare password\n3. Elimina profilo\n0. Esci\n > ";
                            cin >> scelta_utente2;
                            switch (scelta_utente2)
                            {
                            case 1:
                                fputenti = ricerca_utenti(nome, MODIFICA_NOME);
                                cout << "Inserisci un nuovo nome utente > ";
                                fflush(stdin);
                                gets(bufutenti.nome);
                                bufutenti.canc = 0;
                                fseek(fputenti, -sizeof(utenti), SEEK_CUR);
                                fwrite(&bufutenti, sizeof(utenti), 1, fputenti);
                                fseek(fputenti, sizeof(utenti), SEEK_CUR);
                                strcpy(nome, bufutenti.nome);
                                cout << "Nome utente modificato con successo. " << endl;
                                system("pause");
                                break;
                            case 2:
                                fputenti = ricerca_utenti(nome, MODIFICA_PASSWORD);
                                cout << "Inserisci nuova password > ";
                                fflush(stdin);
                                gets(bufutenti.password);
                                bufutenti.canc = 0;
                                fseek(fputenti, -sizeof(utenti), SEEK_CUR);
                                fwrite(&bufutenti, sizeof(utenti), 1, fputenti);
                                fseek(fputenti, sizeof(utenti), SEEK_CUR);
                                strcpy(password, bufutenti.password);
                                cout << "Password modificata con successo. " << endl;
                                system("pause");
                                break;
                            case 3:

                            default:
                                break;
                            }
                        } while (scelta_utente2 != 0);
                    }
                    default:
                        break;
                    }
                } while (scelta_utente != 0);
            }
            else
            {
                cout << "Nome utente o password non corretti!" << endl;
            }
            system("pause");
            break;
        default:
            break;
        }
    } while (scelta_uno != 0);

    cin.get();
    return 0;
}

/*----------REGISTRAZIONE UTENTE----------*/
void registrazione_utente(string nome, string password)
{
    nome_file = nome + ".dat";
    fp = fopen(nome_file.c_str(), "a");
    fclose(fp);
    fputenti = fopen("utenti.dat", "r");
    if (fputenti == NULL)
    {
        cout << "Errore nell'apertura del file degli utenti!" << endl;
        return;
    }

    while (fread(&bufutenti, sizeof(utenti), 1, fputenti))
    {
        if (nome == bufutenti.nome)
        {
            cout << "Utente gia' esistente!" << endl;
            fclose(fputenti);
            return;
        }
    }
    fclose(fputenti);

    fputenti = fopen("utenti.dat", "a+");
    if (fputenti == NULL)
    {
        cout << "Errore nell'apertura del file degli utenti!" << endl;
        return;
    }

    strcpy(bufutenti.nome, nome.c_str());
    strcpy(bufutenti.password, password.c_str());
    bufutenti.canc = 0;
    fwrite(&bufutenti, sizeof(utenti), 1, fputenti);

    fclose(fputenti);

    cout << "Registrazione avvenuta con successo!" << endl;
}
/*----------ACCESSO UTENTE----------*/
bool accesso_utente(string nome, string password)
{
    fputenti = fopen("utenti.dat", "r");
    if (fputenti == NULL)
    {
        cout << "Errore nell'apertura del file degli utenti!" << endl;
        return false;
    }

    while (fread(&bufutenti, sizeof(utenti), 1, fputenti))
    {
        if (strcmp(nome.c_str(), bufutenti.nome) == 0 && strcmp(password.c_str(), bufutenti.password) == 0)
        {
            return true;
            break;
        }
    }
    fclose(fputenti);
}
/*----------ACCESSO ADMIN----------*/
bool accesso_admin(string password)
{
    if (password == "admin")
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*----------CARICAMENTO PRODOTTO----------*/
void caricamento_prodotto()
{
    fp = fopen("articoli.dat", "a+");
    int codice;
    bool trovato = false;
    cout << "Inserisci il codice >  ";
    cin >> codice;
    fseek(fp, 0, SEEK_SET);
    while (fread(&bufarticoli, sizeof(articoli), 1, fp) and !trovato)
    {
        if (codice == bufarticoli.codice)
        {
            trovato = true;
            cout << "Codice gia' esistente. Inseriscine un altro! " << endl;
        }
    }
    if (!trovato)
    {
        bufarticoli.codice = codice;
        cout << "Inserisci la descrizione >  ";
        fflush(stdin);
        gets(bufarticoli.descrizione);
        cout << "Inserisci il prezzo >  ";
        cin >> bufarticoli.prezzo;
        cout << "Inserisci la quantita >  ";
        cin >> bufarticoli.quantita;
        bufarticoli.canc = 0;
        fwrite(&bufarticoli, sizeof(articoli), 1, fp);
        cout << "Prodotto aggiunto!" << endl;
    }
    fclose(fp);
}
/*----------VISUALIZZAZIONE----------*/
void visualizza_catalogo()
{
    fp = fopen("articoli.dat", "r");
    if (fp == NULL)
    {
        cout << "Il file e' vuoto. " << endl;
        return;
    }
    fread(&bufarticoli, sizeof(articoli), 1, fp);
    while (!feof(fp))
    {
        cout << "-----*-----*-----" << endl;
        cout << "Codice >  ";
        cout << bufarticoli.codice << endl;
        cout << "Descrizione >  ";
        puts(bufarticoli.descrizione);
        cout << "Prezzo >  ";
        cout << bufarticoli.prezzo << endl;
        cout << "Quantita > ";
        cout << bufarticoli.quantita << endl;
        fread(&bufarticoli, sizeof(articoli), 1, fp);
    }
    fclose(fp);
}
/*----------RICERCA----------*/
FILE *ricerca(const char *parametro_ricerca, int tipo)
{
    fp = fopen("articoli.dat", "r+");
    if (fp == NULL)
    {
        cout << "Errore nell'apertura del file articoli.dat" << endl;
        return NULL;
    }

    while (fread(&bufarticoli, sizeof(articoli), 1, fp))
    {
        if (tipo == RICERCA_CODICE && atoi(parametro_ricerca) == bufarticoli.codice)
        {
            return fp;
        }
        else if (tipo == RICERCA_DESCRIZIONE && strcmp(parametro_ricerca, bufarticoli.descrizione) == 0)
        {
            return fp;
        }
    }
    fclose(fp);
    return NULL;
}
FILE *ricerca_utenti(const char *parametro_ricerca, int tipo)
{
    fputenti = fopen("utenti.dat", "r+");
    if (fputenti == NULL)
    {
        cout << "Errore nell'apertura del file utenti.dat" << endl;
        return NULL;
    }
    while (fread(&bufutenti, sizeof(utenti), 1, fputenti))
    {
        if (tipo == MODIFICA_NOME && strcmp(parametro_ricerca, bufutenti.nome) == 0)
        {
            return fputenti;
        }
        else if (tipo == MODIFICA_PASSWORD && strcmp(parametro_ricerca, bufutenti.password) == 0)
        {
            return fputenti;
        }
    }
    fclose(fputenti);
    return NULL;
}
