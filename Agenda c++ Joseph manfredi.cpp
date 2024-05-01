// librerie
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

// inizializzazione dello struct
struct agenda
{
	string cognome;
	string nome;
	string telFisso;
	string telMobile;
	bool esisto;	
};

//prototipi delle funzioni
void inserisciVoce(agenda [], int&);
void cercaVoce(agenda [], int);
void stampaVoce(agenda [], int);
void cancellaVoce(agenda [], int& );
void stampaRubrica(agenda [], int);
void ordinaRubrica(agenda [], int );
void restoreRubrica(agenda [], int& );
void backupRubrica(agenda [], int);
void cancellaDefinitivamente(agenda [], int&);

//variabili globali
const int MAX=1000;
int nVoci=0;
int men=0;


//dichiarazione della variabile vet di tipo agenda
agenda vet[MAX];

int main()
{
	
	//menù con switch per gestire la scelta dell`utente
    cout << "RUBRICA: " << endl << endl;
    cout << "NUMERO VOCI: " << nVoci << endl << endl;
    cout << "1) immettere voce" << endl;
    cout << "2) cerca voce" << endl;
    cout << "3) stampa voce" << endl;
    cout << "4) cancella voce" << endl;
    cout << "5) stampa rubrica" << endl;
    cout << "6) backup" << endl;
    cout << "7) restore" << endl;
    cout << "8) ordina rubrica" << endl;
    cout << "9) cancella defenitivamente" << endl;
    cout << "10) uscita" << endl << endl;

    // ciclo do while per la scelta 
    do {
        cout << "Inserire numero azione: ";
        cin >> men;

        if (men < 1 || men > 10) {
            cout << "Opzione non valida. Inserire un numero compreso tra 1 e 10." << endl;
        }
    } while (men < 1 || men > 10);

    // switch che a seconda del valore della variabile globale men, chiama una funzione differente
    switch (men) {
    case 1:
    	// chiamata alla funzione inserisciVoce
        inserisciVoce(vet, nVoci);
        break;

    case 2:
    	// chiamata alla funzione cercaVoce
        cercaVoce(vet, nVoci);
        break;

    case 3:
    	// chiamata alla funzione stampaVoce
        stampaVoce(vet, nVoci);
        break;

    case 4:
    	// chiamata alla funzione cancellaVoce
        cancellaVoce(vet, nVoci);
        break;

    case 5:
    	// chiamata alla funzione stampaRubrica
        stampaRubrica(vet, nVoci);
        break;

    case 6:
    	// chiamata alla funzione backupRubrica
        backupRubrica(vet, nVoci);
        break;

    case 7:
    	// chiamata alla funzione restoreRubrica
        restoreRubrica(vet, nVoci);
        break;

    case 8:
    	// chiamata alla funzione ordinaRubrica
        ordinaRubrica(vet, nVoci);
        break;

    case 9:
    	// chiamata alla funzione cancellaDefinitivamente
        cancellaDefinitivamente(vet, nVoci);
    	break;
    
    case 10:
    	// uscita dal programma
		cout << endl<< "Uscita" << endl;
        break;

    default:
    	// se il numero inserito non è valido
        cout << "Opzione non valida" << endl;
    }

    return 0;
}

// Funzione per inserire una voce nella rubrica
void inserisciVoce(agenda vet[], int& numeroVoci)
{
	system("cls");
    
    cout << "IMMETTI VOCE: " << endl << endl;
    
	//lettura dati
	cout<<"Inserisci il Cognome: ";
	cin>>vet[numeroVoci].cognome;
	cout<<"Inserisci il Nome: " ;
	cin>>vet[numeroVoci].nome;
	cout<<"Inserisci il numero fisso: ";
	cin>>vet[numeroVoci].telFisso;
	cout<<"Inserisci il numero cellulare: ";
	cin>>vet[numeroVoci].telMobile;
	vet[numeroVoci].esisto=true;
	numeroVoci=numeroVoci+1;
	system ("cls");
	
	// richiesta di inserire un ulteriore voce
	cout << "VUOI IMMETTERE ALTRA VOCE?" << endl << endl;
	cout << "1) si" << endl;
	cout << "2) no (menu' principale)" << endl << endl;
	
	// ciclo do while per la scelta 
	do 
	{
	cout << "inserire numero azione: ";
	cin >> men;
	}
	while (men < 1 || men > 2);
	
    // inizio dello switch
	switch (men) 
	{
        case 1:
            inserisciVoce(vet, numeroVoci);
            break;
                
        case 2:
            system("cls");
            main();
    }
}

// Funzione per cercare una voce nella rubrica
void cercaVoce(agenda vet[], int numeroVoci) 
{
    system ("cls");
    // dichiarazione variabili
	string ricerca;
	int nVociTrovate = 0;
	
	cout << "CERCA VOCE: " << endl << endl;
    cout << "Inserisci il cognome da cercare: ";
    cin >> ricerca;
    cout << endl;
    
    // ciclo necessario per la ricerca del cognome
    for (int k = 0; k < numeroVoci+1; k++) 
	{
        if (vet[k].cognome == ricerca) 
		{
            nVociTrovate++;
        }
    }
    
    // caso in cui non si fosse trovata la voce
    if (nVociTrovate == 0) 
	{
        cout << "Nessuna voce trovata con il cognome " << ricerca << " in rubrica." << endl;
    } 
    
    // caso in cui si fosse trovata una voce
	else
	{ 
		if (nVociTrovate == 1) 
		{
        	cout << "E' stata trovata una voce con il cognome " << ricerca << " in rubrica." << endl;
        	cout << "VUOI VISUALIZZARLA A SCHERMO?" << endl << endl;
    	} 
    	
    // caso in cui si fossero trovate 2 o più voci con lo stesso cognome
		else 
		{
        	cout << "Sono state trovate " << nVociTrovate << " voci con il cognome " << ricerca << " in rubrica." << endl;
			cout << "VUOI VISUALIZZARLE A SCHERMO?" << endl << endl;        
    	}
    	
    	//scelta dell'utente
    	cout << "1) si" << endl;
		cout << "2) no" << endl << endl;
		
		//controllo della validità della scelta
		do 
		{
			cout << "inserire numero azione: ";
			cin >> men;
			system ("cls");
		}
		while (men < 1 || men > 2);
		
		//inizio switch
		switch (men) 
		{
           case 1:
        	    cout << "VOCI TROVATE: " << endl << endl;
        	    for (int k = 0; k < numeroVoci+1; k++) 
			    {
                   if (vet[k].cognome == ricerca) 
		            {	cout << k+1 << ")" << endl;
                        cout << "COGNOME: " << vet[k].cognome << endl;
                        cout << "NOME: " << vet[k].nome << endl;
                        cout << "NUMERO FISSO: " << vet[k].telFisso << endl;
                        cout <<"NUMERO CELLULARE: " << vet[k].telMobile << endl << endl;
                    }
                }
            
                break;
                
           case 2:
            break;
        }
	}
	
	// altra richiesta per l'utente
    cout << endl;
    cout << "VUOI CERCARE ALTRO COGNOME? " << endl << endl;
    cout << "1) si" << endl;
	cout << "2) no (menu' principale)" << endl << endl;
    
    //controllo della validità della scelta
    do 
	{
	cout << "inserire numero azione: ";
	cin >> men;
	}
	while (men < 1 || men > 2);
    
    //inizio switch
    switch (men) 
	{
        case 1:
        	system("cls");
            cercaVoce(vet, nVoci);
            break;
                
        case 2:
            system("cls");
            main();
    }
}


// Funzione per la stampa della rubrica su file
void stampaVoce(agenda vet[], int numeroVoci) {
    ofstream file("AGENDA.txt");
    if (!file.is_open()) {
        cout << "Impossibile aprire il file per la stampa." << endl;
        return;
    }
    
    // ciclo necessario per la stampa su file
    for (int k = 0; k < numeroVoci; k++)
	{
        if (vet[k].esisto) // Controlla il flag esisto prima di stampare la voce
		{ 	file << k+1 <<") " << endl;
            file << "COGNOME: " << vet[k].cognome << endl;
            file << "NOME: " << vet[k].nome << endl;
            file << "NUMERO FISSO: " << vet[k].telFisso << endl;
            file << "NUMERO CELLULARE: " << vet[k].telMobile << endl << endl;
        }
    }

    file.close(); // chiusura del file 
    
    // quando ha finito di chiudere il file stampa la frase e torna al main()
    cout << endl << "Stampa nel file eseguita con successo." << endl << endl;
    system ("pause");
    system ("cls");
    main();
}

// Funzione per cancellare una voce dalla rubrica
void cancellaVoce(agenda vet[], int& numeroVoci) 
{
	// dichiarazione variabili 
    string cognome;
    string nome;
    int nVociTrovate = 0;
    int pos;
    int x=0;
    
    system("cls");
    
    cout<<"CANCELLA VOCE:"<<endl;
    cout << endl << "Inserisci il cognome della voce da cancellare: ";
    cin >> cognome;

    // ciclo per inserire il cognome da cancellare
    for (int k = 0; k < numeroVoci; k++) 
	{
        if (vet[k].cognome == cognome && vet[k].esisto) 
		{
            pos = k;
            nVociTrovate++;
        }
    }

    // caso in cui non esista il cognome cercato
    if (nVociTrovate == 0)  
	{
	    cout << endl <<"Cognome non esistente." << endl<<endl;
    }
    
    // caso in cui ci sia solamente un cognome 
    if (nVociTrovate == 1) 
	{
        vet[pos].esisto = false;
        cout << endl << "Voce cancellata con successo." << endl<<endl;
        
    }

    // caso in cui esistessero più cognomi
    if (nVociTrovate > 1) 
	{
        cout << endl << endl << "Sono stati trovati " << nVociTrovate << " cognomi uguali in agenda" << endl << endl;
        
        for (int k = 0; k < numeroVoci; k++) 
		{
            if (vet[k].cognome == cognome && vet[k].esisto) // Controlla il flag esisto prima di stampare le voci
			{
                cout << k+1 << ")" << endl;
                cout << "COGNOME: " << vet[k].cognome << endl;
                cout << "NOME: " << vet[k].nome << endl;
                cout << "NUMERO FISSO: " << vet[k].telFisso << endl;
                cout << "NUMERO CELLULARE: " << vet[k].telMobile << endl << endl;
            }
        }

        // richiesta per l'inserimento del nome della voce che si vuole cancellare
        cout << "Immettere nome voce da cancellare: ";
        cin >> nome;

        // ciclo per la cancellazione della voce
        for (int k = 0; k < numeroVoci; k++) 
		{
            if (vet[k].nome == nome && vet[k].esisto && vet[k].cognome == cognome) 
			{
                vet[k].esisto = false;
                x++;
            }
    
        }
        
         // controllo se nome non trovato
        if(x == 0) cout << "Nome non trovato" << endl << endl;
        
        // terminato il ciclo stampa la frase
        else cout << endl << "Voci cancellate con successo." << endl << endl;
        
    }
    
    // ritorno al  main()
    system("pause");
    system("cls");
    main();
}

// Funzione che stampa la rubrica, controllando il flag 'esisto'
void stampaRubrica(agenda vet[], int numeroVoci) 
{
	
    system("cls");
    
    cout<<"STAMPA RUBRICA:"<<endl;
    cout << endl<< "Rubrica:" << endl << endl;
    
    // ciclo per iniziare la stampa delle voci
    for (int k = 0; k < numeroVoci; k++) 
	{
        if (vet[k].esisto) 
		
		{	cout << k+1 << ")" << endl;
            cout << "COGNOME: " << "\t\t" << vet[k].cognome << endl;
            cout << "NOME: " << "\t\t\t"<< vet[k].nome << endl;
            cout << "NUMERO FISSO: " <<"\t\t" <<  vet[k].telFisso << endl;
            cout <<"NUMERO CELLULARE: " <<"\t"<< vet[k].telMobile << endl << endl;
        }
    }
    
    // ritorno al main()
    system("pause");
    system("cls");
    main();
}

// Funzione per eseguire il restore della rubrica su file
void restoreRubrica(agenda vet[], int& numeroVoci) 
{
	system("cls");
	cout<<"RESTORE:"<<endl;
    ifstream file("backup_rubrica.txt");
    
    if (!file.is_open()) // controllo per vedere se il file è aperto
	{
        cout << endl<<"Impossibile aprire il file di backup." << endl;
        return;
    }

    numeroVoci = 0; // Resetta il numero di voci
    while (file >> vet[numeroVoci].cognome >> vet[numeroVoci].nome >> vet[numeroVoci].telFisso >> vet[numeroVoci].telMobile >> vet[numeroVoci].esisto)
	{
        numeroVoci++;
        // Verifica che non superi la dimensione massima della rubrica
        if (numeroVoci >= MAX) {
            cout << endl<<"Dimensione massima della rubrica raggiunta." << endl;
            break;
        }
    }

    file.close();
    cout << endl<< "Backup della rubrica ripristinato con successo." << endl<<endl;

    // Chiede all'utente se vuole ripristinare anche le voci cancellate
    
    cout << endl<<"VUOI RIPRISTINARE LE ALTRE VOCI CANCELLATE?  "<<endl<<endl;
    cout << "1) si" << endl;
	cout << "2) no(menu' principale)" << endl << endl;
	
	// ciclo di controllo
    do 
	{
	cout << "inserire numero azione: ";
	cin >> men;
	}
	
	while (men < 1 || men > 2);
    
    //inizio switch
    switch (men) 
	{
        case 1:
        	for (int k = 0; k < numeroVoci; k++) 
			{
            vet[k].esisto = true; // Ripristina le voci cancellate
            }
            
            cout << endl << "Voci cancellate ripristinate." << endl<<endl;
            system("pause");
            system("cls");
            main();
                
        case 2:
        	
            system("cls");
            main();
    }

}


// Funzione ordina rubrica che ordina la rubrica a secondo di cosa sceglie l'utente
void ordinaRubrica(agenda vet[], int numeroVoci) 
{
	// dichiarazione variabili
    int sceltaCampo, sceltaOrdine;
    
    system("cls");
    
    // scelta del campo
    cout<<"ORDINA RUBRICA:"<<endl;
    cout << endl << "Scegli il campo per l'ordinamento:" << endl<<endl;
    cout << "1) Cognome" << endl;
    cout << "2) Nome" << endl<<endl;
    cout <<"Inserire numero azione:";
    cin >> sceltaCampo;
    
    // scelta dell'ordinamento
    cout << endl << "Scegli l'ordine di ordinamento:" << endl<<endl;
    cout << "1) Crescente" << endl;
    cout << "2) Decrescente" << endl<<endl;
    cout <<"Inserire numero azione:";
    cin >> sceltaOrdine;
    
    bool scambio = true;
    while (scambio) 
	{
        scambio = false;
        for (int k = 0; k < numeroVoci - 1; k++) 
		{
            // Confronta i campi delle voci adiacenti
            if (sceltaCampo == 1) 
			{ // Ordinamento per cognome
                if (vet[k].esisto && vet[k + 1].esisto &&
                    ((sceltaOrdine == 1 && vet[k].cognome > vet[k + 1].cognome) ||
                    (sceltaOrdine == 2 && vet[k].cognome < vet[k + 1].cognome))) 
				{
                    // Se il campo della voce corrente è maggiore o minore del successivo, scambia le voci 
                    agenda temp = vet[k];
                    vet[k] = vet[k + 1];
                    vet[k + 1] = temp;
                    scambio = true;
                }
            } else if (sceltaCampo == 2)
			{ // Ordinamento per nome
                if (vet[k].esisto && vet[k + 1].esisto &&
                    ((sceltaOrdine == 1 && vet[k].nome > vet[k + 1].nome) ||
                    (sceltaOrdine == 2 && vet[k].nome < vet[k + 1].nome))) 
				{
                    // Se il campo della voce corrente è maggiore o minore del successivo, scambia le voci 
                    agenda temp = vet[k];
                    vet[k] = vet[k + 1];
                    vet[k + 1] = temp;
                    scambio = true;
                }
                
            } 
			
			else 
			{
                cout << "Scelta non valida." << endl;
                return;
            }
        }
    }
    system("cls");
    // Stampa il risultato dell'ordinamento
    cout << endl<< "RUBRICA ORDINATA:" << endl<<endl;
    for (int k = 0; k < numeroVoci; k++) 
	{
        if (vet[k].esisto) 
		{	cout << k+1 << ")" << endl;
            cout << "COGNOME: " << vet[k].cognome << endl;
            cout << "NOME: " << vet[k].nome << endl;
            cout << "NUMERO FISSO: " << vet[k].telFisso << endl;
            cout <<"NUMERO CELLULARE: " << vet[k].telMobile << endl << endl;
        }
    }
    
    // ritorno al main()
    system("pause");
    system("cls");
    main();
}

// Funzione per eseguire il backup della rubrica su file
void backupRubrica(agenda vet[], int numVoci) 
{
    ofstream file("backup_rubrica.txt"); // creazione di un file in modalità di scrittura
    if (file.is_open()) // contollo sei il file è aperto
	{
		// ciclo di stampa delle voci nel file
        for (int k = 0; k < numVoci; k++) 
		{
            file << vet[k].cognome << " "
                 << vet[k].nome << " "
                 << vet[k].telFisso << " "
                 << vet[k].telMobile << " "
                 << vet[k].esisto << endl;
        }
        cout << endl<< "Backup completato." << endl<<endl;
    } 
	else {cout << "Errore durante il salvataggio del backup." << endl;} // in caso ci fosse ststo un errore
	
	// ritorno al main()
    system("pause");
    system("cls");
    main();
}

// Funzione per cancella definitivamente una voce
void cancellaDefinitivamente(agenda vet[], int& numeroVoci) 
{
	// dichiarazione variabile
	int vociCancellate = 0;
    
    // ciclo per la cancellazione definitiva di una voce (cancellazione fisica)
    for (int k = 0; k < numeroVoci; ++k) 
	{
        if (!vet[k].esisto) 
		{
            vet[k] = vet[numeroVoci - 1]; // Sposta l'ultima voce cancellata nella posizione corrente
            vet[numeroVoci - 1] = {}; // Resetta l'ultima posizione
            numeroVoci--; // Riduci il numero di voci
            vociCancellate++;
        }
    }

    if (vociCancellate > 0) 
	{
        cout << endl<< "Sono state cancellate definitivamente " << vociCancellate << " voci." << endl;
    } 
	else {cout << endl<< "Non ci sono voci cancellate da cancellare definitivamente." << endl;}
	
    // Aggiorna il file di backup
    ofstream backupFile("backup_rubrica.txt");
    if (backupFile.is_open()) 
	{
        for (int k = 0; k < numeroVoci; k++) 
		{
            if (vet[k].esisto)
			{
                backupFile << vet[k].cognome << " "
                           << vet[k].nome << " "
                           << vet[k].telFisso << " "
                           << vet[k].telMobile << " "
                           << vet[k].esisto << endl;
            }
        }
        cout << endl << "Backup aggiornato con successo." << endl<<endl;
    } 
	
	else {cout << endl<<"Errore durante l'aggiornamento del backup." << endl;} // in caso ci fosse ststo un errore
    backupFile.close(); // chiusura del file

    // ritorno al main()
    system("pause");
    system("cls");
    main();
}

