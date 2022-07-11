#include "Repo.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	
	 testsMedicineRepo();
	 testVector();
	 testsMedicineServ();
	MedicineRepo* repo = createRepo();
	Service* serv = createService(repo);

	/*addMedicine(serv, "Perplex", 10,100,5);
	addMedicine(serv, "Teraflu", 20, 70, 10.5);
	addMedicine(serv, "Parasinus", 5, 50, 15);
	addMedicine(serv, "Fervex", 3, 250, 2.5);
	addMedicine(serv, "Colebil", 65.60, 45, 19.50);
	updateMedicine(serv, "Fervex", 3, 111111, 111111111);*/

	UI* ui = createUI(serv);

	startUI(ui);

	destroyUI(ui);

	int return_value = _CrtDumpMemoryLeaks();
	printf("%d", return_value);

	return 0;
}