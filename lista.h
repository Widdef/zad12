#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ell
{
	int data;
	struct ell *next;
}list;
void list_add_end(list**, int);
void list_add_start(list**, int);
void list_show(list*);
void list_show_from_back(list **);
void list_delete_first(list**);
void list_delete_last(list**);
int list_find(list**, int);
void list_from_file(list **);
int list_find(list **, int);
void list_find_delete(list **, int);
int check_sting(char *);
void list_delete_all_found_not_rek(list **, int);
void list_delete_from_first_second(list **, list **);