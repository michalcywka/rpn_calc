#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modul.h"
/*

Funkcja push

Dodaje podany element na wybrany stos.

PRE: wskaznik na wskaznik na T_stos i liczba stalopozycyjna

POST: nowy element na wybranym stosie

*/
void push(T_stos **pierwszy, int liczba)
{
    T_stos *nowy;
    nowy = (T_stos *)malloc(sizeof(T_stos)); /*alokacja pamieci dla nowego elementu listy*/
    nowy->wartosc = liczba; /*przypisanie liczby podanej jako argument funkcji do nowego elementu listy*/
    nowy->poprz=NULL; /*zaznaczenie, ze jest to ostatni element*/
    if(pierwszy == NULL)/* sprawdzenie czy lista jest pusta*/
    *pierwszy = nowy; /*jesli tak to nowy element jest pierwszym*/
    else {
    nowy->poprz=*pierwszy;/*jesli nie to nowy element jest pierwszy, a stary jest dalej w kolejnosci na stosie*/
    *pierwszy = nowy;
         }
}
/*

Funkcja pop

Zdejmuje pierwszy element ze stosu.

PRE: wskaznik na wskaznik na T_stos

POST:Funkcja zwraca 0 gdy stos jest pusty lub liczbe sciagnieta ze stosu.

*/
int pop(T_stos **pierwszy)
{
     T_stos *tmp;
     int liczba;
     if (*pierwszy == NULL)
     return -999;/*jesli stos jest pusty, zwroc 0*/
     else{
     tmp = *pierwszy;
     liczba =(*pierwszy)->wartosc;
     *pierwszy =(*pierwszy)->poprz;/*poprzedni element staje sie pierwszym*/
     free(tmp);/*pamiec zaalokowana dla poprzedniego pierwszego elementu zostaje zwolniona*/
     }
     return liczba;
}
/*

Funkcja print

Wyswietla na ekranie elementy na stosie od gory do dolu

PRE: wskaznik na T_stos

POST: Zawartosc stosu od elemntu na samej gorze

*/
void print(T_stos *pierwszy)
{	printf("--------------------------\n");
	printf("Zawartosc stosu od gory:\n");
     while (pierwszy!=NULL){
     printf("%d\n", pierwszy->wartosc);
     pierwszy=pierwszy->poprz; }
	printf("--------------------------\n");
}

/* 

Funkcja czydwa

Sprawdza czy na stosie sa przynajmniej dwa elementy, aby wykonac jakas operacje

PRE: wskaznik na wskaznik na T_stos

POST: 0 i odpowiedni komunikat jesli jest mniej niz 2 elementy na stosie lub 1 w przeciwnym wypadku

*/
int czydwa(T_stos **pierwszy)
{
	int a,b;
	a=pop(pierwszy);
	b=pop(pierwszy);
	if(a==-999)
	{
	fprintf(stderr,"Blad: Wprowadz dwie liczby\n");
	return 0;
	}
	else if(b==-999)
	{
	push(pierwszy,a);
	fprintf(stderr,"Blad: Wprowadz jeszcze jedna liczbe\n");
	return 0;	
	}
	else{
	push(pierwszy,b);
    push(pierwszy,a);
	return 1;
	} 
}
/*
 
Funkcja zamien

Zamienia miejscami dwa elementy na szczycie stosu

PRE: wskaznik na wskaznik na T_stos z min. dwoma elementami

POST: stos z zamienionymi elementami na gorze


*/

void zamien(T_stos **pierwszy)
{
  if(czydwa(pierwszy))
	{
	int a,b;
	a=pop(pierwszy);
	b=pop(pierwszy);
	push(pierwszy,a);
	push(pierwszy,b);			
	}
}

/*

Funkcja duplikuj

Duplikuje argument na szczycie stosu

PRE: wskaznik na wskaznik na T_stos

POST: dwa elementy na szczycie stosu o tej samej wartosci

*/
void duplikuj(T_stos **pierwszy)
{
	int a;
	a=pop(pierwszy);
	if(a==-999)
	{
		fprintf(stderr,"Brak argumentow na stosie\n");
	}
	else
	{
	push(pierwszy,a);
	push(pierwszy,a);	
	}
}


