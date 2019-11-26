#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "lista.h"


void ask_value(int *value)
{
	printf("\nPodaj wartosc: ");
	scanf("%d", value);
}
void find_value(int *value)
{
	printf("\nPodaj wartosc do wyszukania: ");
	scanf("%d", value);
}


int main()
{
	list *head = NULL;
	list *second = NULL;
	int chose = 0;
	int value;
	int find;
	do
	{
		system("CLS");
		printf("11)Dodaj element na poczatku listy do listy pierwszej\n");
		printf("12)Dodaj element na poczatku listy do listy drugiej\n");
		printf("21)Dodaj element na koncu listy do listy pierwszej\n");
		printf("22)Dodaj element na koncu listy do listy drugiej\n");
		printf("31)Usun pierwszy element listy do listy pierwszej\n");
		printf("32)Usun pierwszy element listy do listy drugiej\n");
		printf("41)Usun ostatni element listy do listy pierwszej\n");
		printf("42)Usun ostatni element listy do listy drugiej\n");
		printf("51)Wczytaj zawartosc listy z pliku do listy pierwszej\n");
		printf("52)Wczytaj zawartosc listy z pliku do listy drugiej\n");
		printf("61)Wyswietl zawartosc listy pierwszej\n");
		printf("62)Wyswietl zawartosc listy drugiej\n");
		printf("34)ZADANIE 12\n");
		printf("0)Wyjscie\n");
		scanf("%d", &chose);
		switch (chose)
		{
		case 11:
			ask_value(&value);
			list_add_start(&head, value);
			continue;
		case 12:
			ask_value(&value);
			list_add_start(&second, value);
			continue;
		case 21:
			ask_value(&value);
			list_add_end(&head, value);
			continue;
		case 22:
			ask_value(&value);
			list_add_end(&second, value);
			continue;
		case 31:
			list_delete_first(&head);
			continue;
		case 32:
			list_delete_first(&second);
			continue;
		case 41:
			list_delete_last(&head);
			continue;
		case 42:
			list_delete_last(&second);
			continue;
		case 51:
			list_from_file(&head);
			continue;
		case 52:
			list_from_file(&second);
			continue;
		case 61:
			list_show(head);
			system("PAUSE");
			continue;
		case 62:
			list_show(second);
			system("PAUSE");
			continue;
		case 34:
			list_delete_from_first_second(&head, &second);
			system("PAUSE");
			continue;
		default:
			continue;
		}
	} while (chose != 0);

	free(head);
	return 0;
}