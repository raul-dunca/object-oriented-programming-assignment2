#include "Service.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Operation.h"
Service* createService(MedicineRepo* r)
{
	Service* s = malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->repo = r;
	s->undostack = createDynamicArray_v(10, &destroyOperation);
	s->redostack = createDynamicArray_v(10, &destroyOperation);
	return s;

}
void destroyService(Service* s)
{
	if (s == NULL)
		return;
	destroyRepo(s->repo);

	destroy_v(s->undostack);

	destroy_v(s->redostack);

	free(s);

}

int addMedicine(Service* s, char* name, double concentration, int quantity, double price)
{
	/*if (concentration < 0 || quantity < 0 || price < 0)
		return 0;*/
	Medicine* m = createMedicine(name, concentration, quantity, price);
	int res = add(s->repo, m);

	if (res == 1)
	{
		Operation* op = createOperation(ADD, m);
		if (op == NULL)
			return -1;
		add_v(s->undostack, op);
		//destroyMedicine(m);
	}
	else
	{
		destroyMedicine(m);
	}
	return res;

	
}
//int short_suplly(Service* s, int x)
//{
//	Medicine** res = filtru(s->repo, x);
//
//	return res;
//}
int deleteMedicine(Service* s, char* name, double concentration)
{
	int k = find(s->repo, name, concentration);
	if (k == -1)
		return 0;
	
	Medicine* p = getMedicinetOnPos(s->repo, k);
	Operation* op = createOperation(DELETE, p);
	if (op == NULL)
		return -1;
	
	add_v(s->undostack,op );

	return delete(s->repo, name,concentration);


}
int updateMedicine(Service* s, char* name, double concentration, int newquantity, double newprice)
{
	int k = find(s->repo, name, concentration);
	Medicine* p = getMedicinetOnPos(s->repo, k);
	Operation* op = createOperation(UPDATE, p);
	
	if (op == NULL)
		return -1;


	
	int res = update(s->repo,name, concentration, newquantity, newprice);

	Operation* op2 = createOperation(UPDATE, p);
	if (op2 == NULL)
		return -1;
	add_v(s->undostack, op2);


	add_v(s->undostack, op);



	/*if (res == 0)
		destroyMedicine(m);*/

	return res;


}

MedicineRepo* getRepo(Service* s)
{

	return s->repo;
}

int filterBySymb(Medicine* s,char  symbols[50])
{
	//returnam repou cu filtrele bune 

	//MedicineRepo* m = malloc(sizeof(MedicineRepo));
	
	char* name= getName(s);
	
	int val = 0;
	//m->length = 0;

	
	
		for (int i = 0; i < strlen(symbols); i++)
		{
			for (int k = 0; k < strlen(name); k++)
			{

				if (name[k] == symbols[i])
				{		
					val++;
					break;
				}
			}
		}

		//free(name);
	//destroyMedicine(medicine);
	if (val == strlen(symbols))
		return 1;
	else
		return 0;
}
int undo(Service* s)
{

	if (s == NULL)
		return 0;
	int undo_stack_size = getLength_v(s->undostack);
	if (undo_stack_size == 0)
		return -1;
	Operation* op = get_v(s->undostack, undo_stack_size - 1);
	if (op == NULL)
		return 0;
	Medicine* p = getOpObject(op);
	if (p == NULL)
		return -1;

	if (getOpType(op) == ADD)
		delete(s->repo, getName(p), getConcentration(p));
	else if (getOpType(op) == DELETE)
		add(s->repo, CopyofMedicine(p)); // must have a copy, because p
										   // will be destroyed when deleting
										   // the operation from the stack
	else if (getOpType(op) == UPDATE)
	{
		
		update(s->repo, getName(p), getConcentration(p), getQuantitye(p), getPrice(p));
		add_v(s->redostack, op);
		//Operation* op2 = createOperation(UPDATE, CopyofMedicine(p));
		 op = get_v(s->undostack, undo_stack_size - 2);
		 p = getOpObject(op);

		add_v(s->redostack, op);
		
		//add_v(s->redostack, op2);
		delete_2(s->undostack, undo_stack_size - 1);
		delete_2(s->undostack, undo_stack_size - 2);
		return 1;

	}
	// remove the operation from "the stack"
	// should be added to the redo stack
	add_v(s->redostack,op);
	delete_2(s->undostack, undo_stack_size -1);
	return 1;
}
int redo(Service* s)
{

	if (s == NULL)
		return 0;
	int redo_stack_size = getLength_v(s->redostack);
	if (redo_stack_size == 0)
		return -1;
	Operation* op = get_v(s->redostack, redo_stack_size - 1);
	if (op == NULL)
		return 0;
	Medicine* p = getOpObject(op);
	if (p == NULL)
		return -1;


	if (getOpType(op) == ADD)
		add(s->repo, CopyofMedicine(p));
	else if (getOpType(op) == DELETE)
		delete(s->repo, getName(p), getConcentration(p));
		 // must have a copy, because p
										   // will be destroyed when deleting
										   // the operation from the stack
	else if (getOpType(op) == UPDATE)
	{
		update(s->repo, getName(p), getConcentration(p), getQuantitye(p), getPrice(p));
		add_v(s->undostack, op);
		 op = get_v(s->redostack, redo_stack_size - 2);
		 p = getOpObject(op);
		
		 add_v(s->undostack, op);
		
		
		//add_v(s->undostack, op2);
		delete_2(s->redostack, redo_stack_size - 1);
		delete_2(s->redostack, redo_stack_size - 2);
		return 1;
	}
	
	add_v(s->undostack, op);
	delete_2(s->redostack, redo_stack_size - 1);
	return 1;

}


void testServ()
{
	MedicineRepo* v = createRepo();
	Service* s = createService(v);

	assert(getLength(s->repo) == 10);


	assert(addMedicine(s, "med",10,10,10) == 1);
	
	assert(getLength(s->repo) == 11);
	assert(undo(s));
	assert(getLength(s->repo) == 10);
	assert(redo(s));
	assert(getLength(s->repo) == 11);

	assert(deleteMedicine(s, "med", 10));
	assert(getLength(s->repo) == 10);
	assert(undo(s));
	assert(getLength(s->repo) == 11);
	assert(redo(s));
	assert(getLength(s->repo) == 10);



	
	assert(updateMedicine(s, "Fervex", 3, 1, 1) == 1);
	assert(getQuantitye(get_v(s->repo->medicines, 3)) == 1);
	assert(getPrice(get_v(s->repo->medicines, 3)) == 1);


	destroyService(s);
}

void testsMedicineServ()
{
	testServ();
}
