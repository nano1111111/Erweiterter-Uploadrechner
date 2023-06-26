#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 4
#pragma warning(disable : 4996)

int main()
{
	FILE* fp;
	int upload;
	long long int datei;
	long long groesse;
	long long int zeit;
	double minuten;
	int auswahl;
	double stunden;
	double tag;
	int switchcase;
	int bandbreite;
	int dateizeile_1 = 0;
	char dateieinheit[200];

	fp = fopen("Data_1.txt", "r");

	if (fp == NULL) 									//Sollte Data_1.txt nicht gefunden gibt es hier eine Anleitung diese Datei zu erstellen und abzuspeichern
	{											//Den diese Datei fehlt um weiter im Programmcode voranzuschreiten
		printf("\nFehler beim auslesen von wichtigen Dateien!\n");
		printf("\nBitte lege eine .txt Datei mit den folgenden Inhalten an und dem Namen Data_1");
		printf("\nBitte schreibe jedes wort in eine Zeile und nicht hintereinander!\n");
		printf("------------------");
		printf("\nKilobyte");
		printf("\nMegabyte");
		printf("\nGigabyte");
		printf("\nTerabyte\n");	
		printf("------------------");							
		return 1;									
	}

	printf("\nBitte waehle die Groesseneinheit aus"); 					//Hier wird der User gefragt, die einheit der Datei auszuwählen
	printf("\nAuswahl 1 ist Kbyte = Kilobyte");		  				//Das dient dazu damit nicht Text ausgewertet werden muss
	printf("\nAuswahl 2 ist Mbyte = Megabyte");
	printf("\nAuswahl 3 ist Gbyte = Gigabyte");
	printf("\nAuswahl 4 ist Tbyte = Terabyte");

	do {
		printf("\nDeine Auswahl ist: ");
		scanf("%d", &auswahl);								//Das hier ist eine Eingabeprüfung welche				
		if (auswahl <= 0 || auswahl > 4)						//in einer schlaufe läuft damit die eingabe nur 1 bis 4 ist
		{
			printf("\nBitte gib eine Zahl von 1 bis 4 nur an!");
		}
	} while (auswahl <= 0 || auswahl > 4);

	while (fgets(dateieinheit, sizeof(dateieinheit), fp))
	{
		dateizeile_1++;									//ist die Datei vorhanden wird diese hier geöffnet
		if (dateizeile_1 == auswahl) {							//im reinem Lesemodus wo je nach auswahl die bestimmte 
			dateieinheit[strcspn(dateieinheit, "\n")] = '\0';			//Zeile ausgelesen wird und abgespeichert wird
			break;
		}
	}

	fclose(fp);   

	printf("\nWie gross ist deine Datei? Bitte angeben:  ");
	scanf("%lld", &groesse);

	switch (auswahl)
	{
	case 1:
		printf("\nDie Datei ist %d %s gross\n", groesse, dateieinheit);			//In diesen Fällen wird nur die Dateigröße wiedergegeben
		break;										//mit der jeweiligen einheit

	case 2:
		printf("\nDie Datei ist %d %s gross\n", groesse, dateieinheit);
		break;

	case 3:
		printf("\nDie Datei ist %d %s gross\n", groesse, dateieinheit);
		break;

	case 4:
		printf("\nDie Datei ist %d %s gross\n", groesse, dateieinheit);
		break;
	}
	printf("\nBitte gib deine Uploadbandbreiteneinheit an\n");				//Hier wird der User gefragt, die einheit vom Upload auszuwählen
	printf("\nAuswahl 1 ist Kb = Kilobit");							//da dies von der jeweiligen bandbreite abhängt die verfügbar ist
	printf("\nAuswahl 2 ist Mb = Megabit");
	printf("\nAuswahl 3 ist Gb = Gigabit");
	printf("\nAuswahl 4 ist Tb = Terabit");

	do {
		printf("\nDeine Auswahl ist: ");						//Hier wird wieder die eingabe überprüft damit dieser nicht 
		scanf("%d", &upload);								//unter 1 oder über 4 geht in einer schleife welche man nur 	
		if (upload <= 0 || upload > 4)							//verlassen kann wenn die Bedingung richtig ist
		{
			printf("\nBitte gib eine Zahl von 1 bis 4 nur an!");
		}
	} while (upload <= 0 || upload > 4);


	printf("\nwie viel upload hast du?");							//hier wird nach der menge an verfügbarer Bandbreite gefragt
	printf("\nBandbreite betraegt: ");
	scanf("%d", &bandbreite);

	switchcase = (auswahl * 10) + upload;

	switch (switchcase)
	{

	case 11:										//In diesen Fällen wird individuell je nach vorheriger auswahl
		datei = groesse * 8;								//der richtige Fall angewendet um zum richtigen
		zeit = datei / bandbreite;							//Ergebnis zu kommen
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Kilobit\n", bandbreite);
		break;

	case 12:
		datei = groesse / 125;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Megabit\n", bandbreite);
		break;

	case 13:
		datei = groesse / 125000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Gigabit\n", bandbreite);
		break;

	case 14:
		datei = groesse / 125000000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Terabit\n", bandbreite);
		break;

	case 21:
		datei = groesse * 8000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 24;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Kilobit\n", bandbreite);
		break;

	case 22:
		datei = groesse * 8;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Megabit\n", bandbreite);
		break;

	case 23:
		datei = groesse / 125;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Gigabit\n", bandbreite);
		break;

	case 24:
		datei = groesse / 125000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Terabit\n", bandbreite);
		break;

	case 31:
		datei = groesse / 8000000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Kilobit\n", bandbreite);
		break;

	case 32:
		datei = groesse * 8000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Megabit\n", bandbreite);
		break;


	case 33:
		datei = groesse * 8;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Gigabit\n", bandbreite);
		break;

	case 34:
		datei = groesse / 125;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Terabit\n", bandbreite);
		break;

	case 41:
		datei = groesse * 8000000000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Kilobit\n", bandbreite);
		break;

	case 42:
		datei = groesse * 8000000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Megabit\n", bandbreite);
		break;

	case 43:
		datei = groesse * 8000;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Gigabit\n", bandbreite);
		break;

	case 44:
		datei = groesse * 8;
		zeit = datei / bandbreite;
		minuten = zeit / 60;
		stunden = minuten / 60;
		tag = stunden / 60;
		printf("\nDein Upload von deiner Datei mit der Grosse %lld %s dauert %lld Sekunden, %.2f Minuten, %.8f Stunden oder %.8f Tage", groesse, dateieinheit, zeit, minuten, stunden, tag);
		printf("\nmit einer Bandbreite von %d Terabit\n", bandbreite);
		break;
	default:
		printf("\nDu hast aus Gruenden es geschaft die Logik des Programms komplett zu umgehen. Herzlichen Glueckwunsch Mastermind\n");
	}			//Diese Nachricht dient dem Fall falls es geschafft wurde die Logik des Programs komplett zu umgehen
	return 0;
}
