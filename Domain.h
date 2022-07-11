#pragma once

typedef struct
{
	char* name;
	double concentration;
	int quantity;
	double price;
} Medicine;

/// <summary>
/// creates a medicine
/// </summary>
/// <param name="name" name of the medicine></param>
/// <param name="con">concentration of the medicine</param>
/// <param name="quant">quantitye of the medicine</param>
/// <param name="price">price of the medicine</param>
/// <returns> the medicine created</returns>
Medicine* createMedicine(char* name, double con, int quant, double price);

/// <summary>
/// just destroyes the medicine 
/// </summary>
/// <param name="p">the medicine willing to be destroyed</param>
void destroyMedicine(Medicine* p);

/// <summary>
/// just returned the name of the medicine
/// </summary>
/// <param name="p">the medicine which name will be returned</param>
/// <returns></returns>
char* getName(Medicine* p);
/// <summary>
/// just returned the name of the medicine
/// </summary>
/// <param name="p">the medicine which concentration will be returned</param>
/// <returns></returns>
double getConcentration(Medicine* p);
/// <summary>
/// just returned the concentration of the medicine
/// </summary>
/// <param name="p">the medicine which quantitye will be returned</param>
/// <returns></returns>
double getQuantitye(Medicine* p);
/// <summary>
/// just returned the quantitye of the medicine
/// </summary>
/// <param name="p">the medicine which price will be returned</param>
/// <returns></returns>
int getPrice(Medicine* p);
/// <summary>
/// just creates a nicely string of the medicine which will be printed out
/// </summary>
/// <param name="p"></param>
/// <param name="str"></param>
void ToString(Medicine* p, char str[]);
/// <summary>
/// just sets the price of the medicine
/// </summary>
/// <param name="p">the medicine which price will be modified</param>
/// <param name="price"> the new price</param>
int setPrice(Medicine* p, double price);

/// <summary>
/// just sets the quantity of the medicine
/// </summary>
/// <param name="p">the medicine which quantity will be modified</param>
/// <param name="price"> the new price</param>
int setQuantity(Medicine* p, int quantity);
/// <summary>
/// creates a copy of the medicine passed by parameter
/// </summary>
/// <param name="p" the medicine which copy will be created></param>
/// <returns>the copy of the medicine</returns>
Medicine* CopyofMedicine(Medicine* p);
