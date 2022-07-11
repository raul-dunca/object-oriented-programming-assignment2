#pragma once
#include "Domain.h"
#include "DynamicArray.h"


typedef struct
{
	DynamicArray* medicines;
} MedicineRepo;

/// <summary>
/// creates the repo
/// </summary>
/// <returns></returns>
MedicineRepo* createRepo();

/// <summary>
/// destroyes the repo
/// </summary>
/// <param name="v"></param>
void destroyRepo(MedicineRepo* v);
/// <summary>
/// tryes to find the medicine with the name and concentration from the parameters
/// </summary>
/// <param name="v"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <returns>the position if the medicine is found, -1 otherwise</returns>
int find(MedicineRepo* v, char* name, double concentration);
/// <summary>
/// adds the medicine p in the repo medicines list
/// </summary>
/// <param name="v"></param>
/// <param name="p"></param>
/// <returns>1 if succesful, 0 if the medicine is already added</returns>
int add(MedicineRepo* v, Medicine* p);
/// <summary>
/// returnes the length od the medicines repo list
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
int getLength(MedicineRepo* v);
/// <summary>
/// returned the medicine in the pozition pos
/// </summary>
/// <param name="v"></param>
/// <param name="pos"></param>
/// <returns></returns>
Medicine* getMedicinetOnPos(MedicineRepo* v, int pos);

/// <summary>
/// deletes the madicine with the same name and concentration form parameters
/// </summary>
/// <param name="v"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <returns>1 if succesfull, 0 otherwise</returns>
int delete(MedicineRepo* v, char* name, double concentration);
/// <summary>
/// updates the medicine with the name an concentration from parameters, and updatets its quantity and price with ones in the parameters
/// </summary>
/// <param name="v"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <param name="newquantity"></param>
/// <param name="newprice"></param>
/// <returns>1 if succesfull, 0 therwise</returns>
int update(MedicineRepo* v, char* name, double concentration, int newquantity, int newprice);

/// <summary>
/// it retruns a medicine with the same name as the one from parameter
/// </summary>
/// <param name="repo"></param>
/// <param name="name"></param>
/// <returns>the mdicine if it was found null otherwise</returns>
Medicine* findByName(MedicineRepo* repo, char* name);

