#pragma once
#include "Repo.h"
typedef struct
{
	MedicineRepo* repo;
	DynamicArray* undostack;
	DynamicArray* redostack;
} Service;

/// <summary>
/// creates the service
/// </summary>
/// <param name="r"></param>
/// <returns>the service created</returns>
Service* createService(MedicineRepo* r);

/// <summary>
/// destroys the service 
/// </summary>
/// <param name="s"></param>
void destroyService(Service* s);
/// <summary>
/// first this function create the medicine with the respective characteristics and then add it 
/// alos it create the operetion which will be put on the undo stack
/// </summary>
/// <param name="s"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <param name="quantity"></param>
/// <param name="price"></param>
/// <returns>return 1 if succesufll, 0 otherwise</returns>
int addMedicine(Service* s, char* name, double concentration, int quantity, double price);

/// <summary>
/// it just return the repo
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
MedicineRepo* getRepo(Service* s);

/// <summary>
/// firs will search for the medicine with the respective characteristics and delete it
/// it also att the proper operation to the undo stack
/// </summary>
/// <param name="s"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <returns>return 1 if succesfull and 0 therwise</returns>
int deleteMedicine(Service* s, char* name, double concentration);
/// <summary>
/// as well it will search for the medicine with the respective charachterestics and then it will update it
/// it also add the preoper operation ot the undo stack
/// </summary>
/// <param name="s"></param>
/// <param name="name"></param>
/// <param name="concentration"></param>
/// <param name="newquantity"></param>
/// <param name="newprice"></param>
/// <returns>returns 1 if succesfull 0 otherwise</returns>
int updateMedicine(Service* s, char* name, double concentration, int newquantity, double newprice);
/// <summary>
/// it undos the last performed operation
/// it takes from the "stack" the operation put there and then do the acording stuff (for add-> deletes..etc)
/// also after undoing something we will put in on the redo stack
/// </summary>
/// <param name="s"></param>
/// <returns>returns 1 if succestul ,-1 if there are no more undos on the stack and 0 therwise</returns>
int undo(Service* s);

/// <summary>
/// it redos the last performed operation
/// it takes from the "stack" the operation put there and then do the acording stuff (for add-> adds..etc)
/// similary we will put what we "pop" to the undo stack
/// </summary>
/// <param name="s"></param>
/// <returns>returns 1 if succestul ,-1 if there are no more undos on the stack and 0 therwise</returns>
int redo(Service* s);