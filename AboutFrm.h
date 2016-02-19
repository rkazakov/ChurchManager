//---------------------------------------------------------------------------
#ifndef AboutFrmH
#define AboutFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvPanel.hpp"
#include <ExtCtrls.hpp>
#include "AdvGlowButton.hpp"
#include <ActnList.hpp>
#include "AdvGroupBox.hpp"
#include "AdvPicture.hpp"
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
	TAdvPanel *MainPanel;
	TAdvGlowButton *OKButton;
	TAdvPanelGroup *MainPanelGroup;
	TActionList *ActionList;
	TAction *ExitAction;
	TAdvGroupBox *AdvGroupBox1;
	TLabel *AboutLabel;
	TAdvPicture *AdvPicture1;
	TLabel *Label3;
	TLabel *Label5;
	TLabel *Label1;
	TLabel *Label2;
	TAction *EnterAction;
	TLabel *Label6;
	void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
