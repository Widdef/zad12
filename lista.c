﻿#include "lista.h"


void list_add_end(list **p, int value)
{
	list *new_el = (list*)malloc(sizeof(list));
	new_el->data = value;
	new_el->next = NULL;

	list *temp = *p;

	if ((*p) == NULL)
	{
		(*p) = new_el;
		new_el->next = new_el;
	}
	else
	{
		while (temp->next != (*p))
		{
			temp = temp->next;
		}

		temp->next = new_el;
		new_el->next = (*p);
	}
}

void list_add_start(list **p, int value)
{
	if (*p == NULL)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = new_el;
		*p = new_el;
	}
	else
	{
		list *marker = *p;
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = *p;
		while ((*p)->next != marker)
		{
			(*p) = (*p)->next;
		}
		(*p)->next = new_el;
		(*p) = new_el;
	}
}

void list_show(list *p)
{
	printf("\n\n");
	if (p != NULL)
	{
		list *head = p;
		do
		{
			printf("%d\n", p->data);
			p = p->next;
		} while (p != head);
	}
}

void list_delete_first(list **p)
{
	if (*p != NULL)
	{
		list *tmp = *p;
		list *head = *p;
		while (tmp->next != *p)
		{
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
		(*p) = tmp->next;
		free(head);
	}
}

void list_delete_last(list **p)
{
	if (*p != NULL)
	{
		list **marker = p;
		while ((*marker)->next->next != *p)
		{
			marker = &(*marker)->next;
		}
		list *tmp = (*marker)->next;
		(*marker)->next = *p;
		free(tmp);
	}
}

int check_sting(char *str)
{
	int len = (int)strlen(str);
	if ((str[len - 3] == 't') && (str[len - 4] == '.') && (str[len - 2] == 'x') && (str[len - 1] == 't'))
		return 1;
	return 0;
}

void list_from_file(list **head)
{
	int value = 0;
	char file[256];
	FILE *fptr;
	do {
		printf_s("Podaj nazwe pliku: ");
		scanf("%s", &file);
		value = check_sting(file); //Sprawdza czy plik zostal podany z rozszerzeniem txt TAK - 1 NIE - 0 
		if (value)
		{
			fptr = fopen(file, "r");
			if (fptr == NULL) // Czy uda³o siê otworzyæ plik
			{
				printf("Blad otwarcia pliku.\n");
				system("PAUSE");
				fclose(fptr);
				break;
			}
			while (fscanf(fptr, "%d", &value) != EOF)
			{
				list_add_end(head, value);
			}
			printf("Udalo sie odczytac dane z pliku.\n");
			fclose(fptr);
			system("PAUSE");
			break;
		}
		printf("Podales zly format pliku.\n");
		system("PAUSE");
	} while (!value); // Pêtla nie zakonczy sie do momentu podania pliku z rozszerzeniem txt
}

int list_find(list **p, int value)
{
	int flag = 0;
	int index = 0;
	list **marker = p;
	do
	{
		index++;
		if ((*marker)->data == value)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	} while (*marker != *p);
	if (flag)
	{
		printf("Element exist. Index: %d\n", index);
		return 1;
	}
	printf("Element not exist\n");
	return 0;
}

void list_find_delete(list **p, int find)
{
	int index = 0;
	list **marker = p;
	if ((*marker)->data == find)
	{
		list_delete_first(p);
		return;
	}
	while ((*marker)->next != *p)
	{
		index++;
		if ((*marker)->next->data == find)
			break;
		marker = &(*marker)->next;
	}
	if ((*marker)->next != *p)
	{
		list *tmp = (*marker)->next;
		(*marker)->next = (*marker)->next->next;
		free(tmp);
	}
	else
		if (list_find(p, find))
			list_delete_last(p);
}

void list_delete_all_found_not_rek(list **p, int value)
{
	while (list_find(p, value))
	{
		list_find_delete(p, value);
	}
}

void list_delete_from_first_second(list** first, list** second)
{
	list *head = *second;
	if (*first != NULL)
		if (*second != NULL)
		{
			do
			{
				list_delete_all_found_not_rek(first, (*second)->data);
				(*second) = (*second)->next;
			} while (*second != head);
		}
		else
			printf("Lista druga jest pusta\n");
	else
		printf("Lista pierwsza jest pusta\n");
}