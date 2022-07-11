#include "Ui.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

UI* createUI(Service* s)
{
	UI* u = malloc(sizeof(UI));
	if (u == NULL)
		return NULL;

	u->serv = s;
	return u;
}
void destroyUI(UI* ui)
{
	if (ui == NULL)
		return;
	destroyService(ui->serv);
	free(ui);
}


void listMedicinesSpecial(UI* ui)
{
	if (ui == NULL)
		return;
	MedicineRepo* repo = getRepo(ui->serv);
	if (repo == NULL)
		return;
	char str[50];
	printf("See all available medicines containing a given string (null for all): ");
	int scanf_result = scanf("%49s", str);
	if (strcmp(str,"null")==0) {
		int nr = getLength(repo);
		
		for (int i = 0; i < nr; i++)
		{
			Medicine* medicine = getMedicinetOnPos(repo, i);
			char medicineString[200];
			ToString(medicine, medicineString);
			printf("%s\n", medicineString);
		}
	}
	else
	{
		int nr = getLength(repo);
		int rl = 0;
		for (int i = 0; i < nr; i++)
		{
			//while(ind<)
			//if (ui->serv->repo->medicines[i])
			if (filterBySymb(get_v(ui->serv->repo->medicines,i), str) == 1)
			{
				rl++;
				Medicine* medicine = getMedicinetOnPos(repo, i);
				char medicineString[200];
				ToString(medicine, medicineString);
				printf("%s\n", medicineString);
			}
		}
		if (rl == 0)
			printf("No medicine was found!");
	}
}


int addMedicineUI(UI* ui)
{
	// read the planet's data
	char name[50];
	int quantity = 0;
	double price = 0, concentration = 0;
	
	printf("Please input the name: ");
	int scanf_result = scanf("%49s", name);
	printf("Please input the concentration: ");
	if (scanf(" %lf", &concentration) == 0)		
		return 0;
	
	printf("Please input the quantity: ");
	if (scanf("%d", &quantity) == 0)
		return 0;
	
	printf("Please input the price: ");
	if (scanf("%lf", &price) == 0)
		return 0;
	return addMedicine(ui->serv, name, concentration, quantity, price);


}int short_supllyUI(UI* ui)
{
	int nr = getLength(ui->serv->repo);
	int x = 0;
	printf("Please input the X: ");
	if (scanf("%d", &x) == 0)
		return 0;
	
	int k = 0;
	for (int i = 0; i < nr; i++)
	{
		Medicine* medicine = getMedicinetOnPos(ui->serv->repo, i);
		if (medicine->quantity < x)
		{
			k++;
			char medicineString[200];
			ToString(medicine, medicineString);
			printf("%s\n", medicineString);
		}
	}
	if (k == 0)
	{
		printf("There is no medicine with less than %d quantity!!!", x);
	}
	return 1;
}


int deleteMedicineUI(UI* ui)
{
	
	char name[50];
	double  concentration = 0;

	printf("We need the name of tht medicine you want to delete: ");
	int scanf_result = scanf("%49s", name);
	printf("And also the concentration: ");
	if (scanf("%lf", &concentration) == 0)
		return 0;
	
	return deleteMedicine(ui->serv, name, concentration);
}

int updateMedicineUI(UI* ui)
{
	
	char name[50];
	int quantity = 0;
	double price = 0, concentration = 0;

	printf("Please input the name of the medicine you want to update: ");
	int scanf_result = scanf("%49s", name);
	printf("And also input the concentration: ");
	if (scanf("%lf", &concentration) == 0)
		return 0;
	printf("Please input the NEW quantity: ");
	if (scanf("%d", &quantity) == 0)
		return 0;
	printf("Please input the NEW price: ");
	if (scanf("%lf", &price) == 0)
		return 0;
	return updateMedicine(ui->serv, name, concentration, quantity, price);
}
void printMenu()
{
	printf("\n**********************************************************\n");
	printf("1 - add a medicine.\n");
	printf("2 - delete a medicine.\n");
	printf("3 - update a medicine.\n");
	printf("4 - list all medicines\n");
	printf("5 - see those medicines that are in short supply (quantity less than X items)\n");
	printf("6 - undo\n");
	printf("7 - redo\n");
	printf("0 - to exit.\n");
	printf("**********************************************************\n");
}

int validCommand(int command)
{

	if (command >= 0 && command <= 7 )
		return 1;

	return 0;

}
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		
		
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			 command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;

		switch (command)
		{
		case 1:
		{
			int res = addMedicineUI(ui);
			if (res == 1)
				printf("Medicine successfully added.\n");
			else
				printf("Error! Medicine could not be added !\n");
			break;
		}
		case 2:
		{
			int r=deleteMedicineUI(ui);
			if (r == 1)
				printf("Medicine successfully deleted.\n");
			else
				printf("Error! Medicine could not be deleted \n");
			break;
		}
		case 3:
		{
			int r = updateMedicineUI(ui);
			if (r == 1)
				printf("Medicine successfully updated.\n");
			else
				printf("Error! Medicine could not be updated \n");
			break;
		}
		case 4:
		{

			listMedicinesSpecial(ui);
			break;
		}
		case 5:
		{
			
			int l=short_supllyUI(ui);
			if (l == 0)
				printf("No bueno!");
			break;
		}
		case 6:
		{
			int res = undo_s(ui);
			// check res and print message accordingly
			if (res == 1)
				printf("Undo successful");
			else if (res == -1)
				printf("No more undos!");
			break;
		}
		case 7:
		{
			int res = redo_s(ui);
			// check res and print message accordingly
			if (res == 1)
				printf("Redo successful");
			else if (res == -1)
				printf("No more redos!");
			break;
		}
		}
		
		
	}
}

int undo_s(UI* ui)
{
	if (ui == NULL)
		return 0;
	return undo(ui->serv);
}
int redo_s(UI* ui)
{
	if (ui == NULL)
		return 0;
	return redo(ui->serv);
}