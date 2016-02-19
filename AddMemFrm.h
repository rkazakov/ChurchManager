//---------------------------------------------------------------------------
#ifndef AddMemFrmH
#define AddMemFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvGlowButton.hpp"
#include <ComCtrls.hpp>
#include "AdvGroupBox.hpp"
#include "advlued.hpp"
#include "dbadvle.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "AdvPanel.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TAddMemForm : public TForm
{
__published:	// IDE-managed Components
	TAdvPanel *MainPanel;
	TAdvGlowButton *AddButton;
	TAdvGlowButton *CloseButton;
	TAdvPanelGroup *MainPanelGroup;
	TAdvGroupBox *FIOGroupBox;
	TLabel *SurLabel;
	TLabel *NameLabel;
	TLabel *PatLabel;
	TDBEdit *SurDBEdit;
	TDBEdit *NameDBEdit;
	TDBEdit *PatDBEdit;
	TAdvGroupBox *DateGroupBox;
	TLabel *CDLabel;
	TLabel *BDLabel;
	TDBEdit *BDDBEdit;
	TDBEdit *CDDBEdit;
	TAdvGroupBox *AddGroupBox;
	TLabel *AddLabel;
	TLabel *TelLabel;
	TDBEdit *AddDBEdit;
	TDBEdit *TelDBEdit;
	TAdvGroupBox *EtcGroupBox;
	TLabel *NatLabel;
	TLabel *FamLabel;
	TLabel *ProLabel;
	TLabel *LifeLabel;
	TLabel *SugLabel;
	TLabel *EtcLabel;
	TDBEdit *NatDBEdit;
	TDBEdit *ProDBEdit;
	TDBEdit *FamDBEdit;
	TDBEdit *LifeDBEdit;
	TDBEdit *SugDBEdit;
	TDBEdit *EtcDBEdit;
	TActionList *ActionList;
	TAction *ExitAction;
	TLabel *Label1;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddMemForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddMemForm *AddMemForm;
//---------------------------------------------------------------------------
#endif
