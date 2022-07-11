#pragma once
#include "Service.h"

typedef struct
{
	Service* serv;
} UI;

/// <summary>
/// creates the ui
/// </summary>
/// <param name="s" the service></param>
/// <returns> the ui </returns>
UI* createUI(Service* s);
/// <summary>
/// destroyes the ui
/// </summary>
/// <param name="ui"></param>
void destroyUI(UI* ui);
/// <summary>
/// start he ui, prints the console
/// </summary>
/// <param name="ui"></param>
void startUI(UI* ui);

