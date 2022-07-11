#include "Domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Medicine* createMedicine(char* name, double con, int quant, double price)
{
	Medicine* p = malloc(sizeof(Medicine));

	if (p == NULL)
		return NULL;

	p->name = malloc(sizeof(char) * (strlen(name) + 1));
	if (p->name != NULL)
		strcpy(p->name, name);
	p->concentration = con;
	p->quantity = quant;
	p->price = price;

	return p;
}

void destroyMedicine(Medicine* p)
{
	if (p == NULL)
		return ;
	free(p->name);
	free(p);
}

char* getName(Medicine* p)
{
	if (p == NULL)
		return NULL;
	return p->name;
}

int setQuantity(Medicine* p,int quantity)
{
	if (p == NULL)
		return NULL;
 p->quantity=quantity;
}

int setPrice(Medicine* p, double price)
{
	if (p == NULL)
		return NULL;
	p->price = price;
}


double getConcentration(Medicine* p)
{
	if (p == NULL)
		return -1;
	return p->concentration;
}

int getPrice(Medicine* p)
{
	if (p == NULL)
		return -1;
	return p->price;
}
double getQuantitye(Medicine* p)
{
	if (p == NULL)
		return -1;
	return p->quantity;
}
void ToString(Medicine* p , char str[])
{
	if (p == NULL)
		return;
	sprintf(str,"Medicine: %s, with the concentration: %.2f %, quantity: %i and prince: %.2f", p->name, p->concentration, p->quantity, p->price);
}
Medicine* CopyofMedicine(Medicine* p)
{
	if (p == NULL)
		return NULL;
	return createMedicine(p->name, p->concentration, p->quantity, p->price);
}