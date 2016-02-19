//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "AboutFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPanel"
#pragma link "AdvGlowButton"
#pragma link "AdvGroupBox"
#pragma link "AdvPicture"
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::OKButtonClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

