
//////////////
// INCLUDES //
//////////////
#include "systemclass.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	SystemClass* System;
	bool result;


	// Create the system object. // Создание объекта системы.
	System = new SystemClass;
	if (!System)
	{
		return 0;
	}

	// Initialize and run the system object. // Инициализация и запуск системного объекта.
	result = System->Initialize();
	if (result)
	{
		System->Run();
	}

	// Shutdown and release the system object. // Завершение работы и освободить системный объект.
	System->Shutdown();
	delete System;
	System = 0;

	return 0;
}