#include "Repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

MedicineRepo* createRepo()
{
	MedicineRepo* v = (MedicineRepo*)malloc(sizeof(MedicineRepo));
	if (v == NULL)
		return NULL;
	v->medicines = createDynamicArray_v(CAPACITY, &destroyMedicine);
	add_v(v->medicines, createMedicine("Perplex", 10, 100, 5));
	add_v(v->medicines, createMedicine("Teraflu", 20, 70, 10.5));
	add_v(v->medicines, createMedicine("Parasinus", 5, 50, 15));
	add_v(v->medicines, createMedicine("Fervex", 3, 250, 2.5));
	add_v(v->medicines, createMedicine("Colebil", 65.60, 45, 19.50));
	add_v(v->medicines, createMedicine("Margareta", 0.5, 80, 20.50));
	add_v(v->medicines, createMedicine("Memo+", 20, 220, 14.5));
	add_v(v->medicines, createMedicine("Octet", 8.88 ,88, 88.88));
	add_v(v->medicines, createMedicine("Vervelita", 12.54, 42, 18.56));
	add_v(v->medicines, createMedicine("Musetea", 90.50, 30, 45.10));
	return v;

}
void destroyRepo(MedicineRepo* v)
{
	if (v == NULL)
		return;
	destroy_v(v->medicines);
	free(v);

}
int find(MedicineRepo* v, char* name,double concentration)
{
	for (int i = 0; i < getLength(v); i++)
	{
		
		Medicine* p = getMedicinetOnPos(v, i);
		if (strcmp(getName(p), name) == 0 && getConcentration(p) == concentration)
			return i;
	}
	return -1;
}

int add(MedicineRepo* v, Medicine* p)
{
	int k = find(v, getName(p), getConcentration(p));
	if (k != -1)
	{
		return 0;
	}
	else
	{
		add_v(v->medicines, p);
		return 1;
	}
	
}
int delete(MedicineRepo* v, char* name, double concentration)
{
	if (v == NULL || name == NULL) {
		return -1;
	}
	int nr = find(v, name, concentration);
	
	Medicine* m = getMedicinetOnPos(v, nr);

	for (int i = 0; i < getLength_v(v->medicines); i++)
	{
		if (get_v(v->medicines, i) == m)
		{
			delete_v(v->medicines, i);
			return 1;
		}
	}
	return 0;
		 
}

Medicine* findByName(MedicineRepo* v, char* name) {
	if (v == NULL || name == NULL) {
		return NULL;
	}

	for (int i = 0; i < getLength_v(v->medicines); i++) {
		Medicine* p = get_v(v->medicines, i);
		if (strcmp(getName(p), name) == 0) {
			return p;
		}
	}

	return NULL;
}

int update(MedicineRepo* v, char* name, double concentration,int newquantity,int newprice)
{
	int k = find(v, name, concentration);
	if (k == -1)
		return 0;
	else
	{
		setQuantity(get_v(v->medicines,k),newquantity);
		setPrice(get_v(v->medicines,k), newprice);
		
	}
			return 1;

}
int getLength(MedicineRepo* v)
{
	if (v == NULL)
		return -1;
	return getLength_v(v->medicines);
}
Medicine* getMedicinetOnPos(MedicineRepo* v, int pos)
{
	get_v(v->medicines, pos);
}


//Tests


void testRepo()
{
	MedicineRepo* v = createRepo();
	
	assert(getLength(v) == 10);

	Medicine* p = createMedicine("Fervex", 4.2, 50, 10);
	assert(add(v, p) == 1);
	assert(getLength(v) == 11);
	assert(find(v, "Fervex", 4.2) == 10);
	assert(find(v, "Fervex", 4.1) == -1);
	assert(find(v, "Ferve", 4.2) == -1);
	assert(delete(v, "Fervex", 4.2) == 1);
	assert(find(v, "Fervex", 4.2) == -1);
	assert(getLength(v) == 10);
	assert(update(v, "Parasinus", 5, 10,10) == 1);
	assert(getQuantitye(get_v(v->medicines,2))==10);
	assert(getPrice(get_v(v->medicines, 2)) == 10);
	
	
	destroyRepo(v);
}

void testsMedicineRepo()
{
	testRepo();
}

