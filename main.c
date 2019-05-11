/*

Kalkulator RPN 

Autor: Michal Cywka

Data utworzenia: 23.01.2017 r.

Kompilacja: W folderze z programem wywolac polecenie "make" w konsoli. Program skompiluje sie pod nazwa a.out.

Sposob uzycia:

1)Uruchomic program wpisujac ./a.out w konsoli

2)Przeksztalcic dzialanie na odwrotna notacje polska (np. (3+4)*3 w ONP wyglada nastepujaco: 4 3 + 3 *)

Dostepne funkcje:

+ - dodanie dwoch argumentow poprzednio wpisanych
- - odjecie dwoch poprzednich argumentow
* - pomnozenie dwoch ostatnich argumentow
/ - dzielnie calkowite dwoch poprzedzajacych liczb
= - wyswietlenie wyniku poprzedniej operacji(wyswietlenie ze stosu pierwszego elementu bez ingerencji w zawartosc stosu)
# - usuniecie ostatnio wprowadzonej liczby(argumentu ze stosu) BEZ jej wyswietlenia
$ - zamiana miejscami dwoch argumentow na szczycie stosu
& - duplikuje argument na szczycie stosu
? - wypisanie zawartosci stosu argumentow
q - zakonczenie pracy programu

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modul.h"
int main ()
{
  int wynik=0;
  int liczba=0;
  char buff[16];
    T_stos *lista=NULL;
    while(buff[0]!='q')   /*wczytywanie elemntow*/
      {
    scanf("%s",buff);
    if(buff[0]>='0'&& buff[0]<='9')
      {
	sscanf(buff,"%d",&liczba);
	push(&lista,liczba);
      }
    else if(buff[0]=='+')
    {
	if(czydwa(&lista))
	{
	wynik=pop(&lista)+pop(&lista);
	push(&lista,wynik);
	}
    }
    else if(buff[0]=='-')
    {
	 if(buff[1]>='0'&& buff[1]<='9')
      {
	sscanf(buff,"%d",&liczba);
	push(&lista,liczba);
      }
	else{
	if(czydwa(&lista))
	{
      wynik=pop(&lista)-pop(&lista);
      push(&lista,wynik);
	}
	}
}
    else if(buff[0]=='/')
    {
	if(czydwa(&lista))
	{
		wynik=pop(&lista);
		liczba=pop(&lista);
		if(liczba==0)
		{
			fprintf(stderr,"Blad: dzielenie przez 0\n");
			push(&lista,liczba);
			push(&lista,wynik);
		}
		else{ 
	wynik=wynik/liczba;
	push(&lista,wynik);
	}
	}
    }
    else if(buff[0]=='*')
    {
	if(czydwa(&lista))
	{
     wynik=pop(&lista)*pop(&lista);
    push(&lista,wynik);
	}
   	}
    else if(buff[0]=='#')
	{
    if(pop(&lista)==-999) fprintf(stderr,"Stos jest pusty\n");
	}
    else if(buff[0]=='=')
	{
	liczba=pop(&lista);
	push(&lista,liczba);
	printf("%i\n",liczba);
	}
    else if(buff[0]=='?')
	{
	print(lista);
	}
    else if(buff[0]=='$')
	{
	zamien(&lista);
	}
    else if(buff[0]=='&')
	{
	duplikuj(&lista);
	}
    else if(buff[0]=='q')
	{
	}
    else
    {
      fprintf(stderr,"Nieznana liczba/opcja\n");
    }
    }
    return 0;
}

