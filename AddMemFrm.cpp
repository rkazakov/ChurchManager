//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MainFrm.h"
#include "AddMemFrm.h"
#include "CMDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma link "AdvGroupBox"
#pragma link "advlued"
#pragma link "dbadvle"
#pragma link "AdvPanel"
#pragma resource "*.dfm"
TAddMemForm *AddMemForm;
//---------------------------------------------------------------------------
__fastcall TAddMemForm::TAddMemForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddMemForm::CloseButtonClick(TObject *Sender)
{
	CMData->ADOQuery->Cancel();
	CMData->ADOQuery->First();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddMemForm::AddButtonClick(TObject *Sender)
{
	CMData->ADOQuery->Append();
	//TExecuteOptions Options;
	//CMData->ADOQuery->Requery(Options);
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddMemForm::FormShow(TObject *Sender)
{
	if (MainForm->EditMode) AddButton->Caption = "Изменить";
}
//---------------------------------------------------------------------------
