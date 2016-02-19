//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "CMDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCMData *CMData;
//---------------------------------------------------------------------------
__fastcall TCMData::TCMData(TComponent* Owner) : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
