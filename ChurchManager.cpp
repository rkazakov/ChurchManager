//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("AboutFrm.cpp", AboutForm);
USEFORM("AddMemFrm.cpp", AddMemForm);
USEFORM("CMDataModule.cpp", CMData); /* TDataModule: File Type */
USEFORM("MainFrm.cpp", MainForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		HANDLE Mutex = OpenMutex(MUTEX_ALL_ACCESS, false, "ChurchManagerApplication");
		if (Mutex == NULL) {
			Mutex = CreateMutex(NULL, true, "ChurchManagerApplication");
			Application->Initialize();
			Application->Title = "ChurchManager 4.0";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TCMData), &CMData);
		Application->Run();
		} else {
			SendMessage(HWND_BROADCAST, RegisterWindowMessage("WM_ChurchManager_Instance"), 0, 0);
			return 0;
		}
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
