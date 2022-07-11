#pragma once
#include "Domain.h"


typedef enum {
	ADD,
	DELETE,
	UPDATE
} opType;

typedef struct {
	opType type;
	Medicine* p;
} Operation;
/// <summary>
/// creates a operation
/// </summary>
/// <param name="type" is the type of the operation (add,delete,update)></param>
/// <param name="p", the medicine that an operation needs to be done on in order to undo/redo></param>
/// <returns></returns>
Operation* createOperation(opType type, Medicine* p);

/// <summary>
/// just destroys the operation
/// </summary>
/// <param name="o" the operation meant ot be destroyed></param>
void destroyOperation(Operation* o);

/// <summary>
/// returns the type of the operation
/// </summary>
/// <param name="o", the operation which type will be returned></param>
/// <returns></returns>
opType getOpType(Operation* o);

/// <summary>
/// returns the medicine from the operation
/// </summary>
/// <param name="o" the operation, which medicine will be returned></param>
/// <returns></returns>
Medicine* getOpObject(Operation* o);
