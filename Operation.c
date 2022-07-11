#include "Operation.h"
#include "Domain.h"
#include <stdlib.h>

Operation* createOperation(opType type, Medicine* p) 
{
	Operation* op = malloc(sizeof(Operation));
	op->type = type;
	Medicine* m = CopyofMedicine(p);
	op->p = m;

	return op;
}

void destroyOperation(Operation* o) 
{
	if (o == NULL)
		return;

	destroyMedicine(o->p);
	free(o);

}

opType getOpType(Operation* o) 
{
	
	if (o == NULL)
		return ;
	return o->type;
}

Medicine* getOpObject(Operation* o)
{
	if (o == NULL)
		return NULL;
	return o->p;
}
