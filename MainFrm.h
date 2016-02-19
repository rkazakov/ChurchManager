//---------------------------------------------------------------------------
#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvToolBar.hpp"
#include "AdvToolBarStylers.hpp"
#include "AdvOfficeStatusBar.hpp"
#include "AdvOfficeStatusBarStylers.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include "AdvPanel.hpp"
#include <ExtCtrls.hpp>
#include "AdvMenus.hpp"
#include <Menus.hpp>
#include "AdvMenuStylers.hpp"
#include "AdvGlowButton.hpp"
#include "datelbl.hpp"
#include "AdvEdit.hpp"
#include <Mask.hpp>
#include "AdvGlassButton.hpp"
#include "AdvShapeButton.hpp"
#include "AdvOfficeButtons.hpp"
#include "AdvOfficeHint.hpp"
#include "AdvOfficeComboBox.hpp"
#include <ImgList.hpp>
#include <DBGrids.hpp>
#include <XPMan.hpp>
#include <Dialogs.hpp>
#include "DataFile.hpp"
#include "frxClass.hpp"
#include "frxExportRTF.hpp"
#include "frxADOComponents.hpp"
#include "frxDBSet.hpp"
#include "frxExportPDF.hpp"
#include "frxExportHTML.hpp"
#include "frxExportXLS.hpp"
#include "frxExportText.hpp"
#include "frxDCtrl.hpp"
#include <ExtDlgs.hpp>
#include <DBCtrls.hpp>
#include "AdvCombo.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TAdvToolBarOfficeStyler *AdvToolBarOfficeStyler;
	TAdvOfficeStatusBarOfficeStyler *AdvOfficeStatusBarOfficeStyler;
	TAdvPanelStyler *AdvPanelStyler;
	TXPManifest *XPManifest1;
	TAdvToolBarPager *ToolBarPager;
	TAdvPage *AdvPage1;
	TAdvToolBar *FIOToolBar;
	TAdvToolBar *AdvToolBar1;
	TAdvToolBar *AdvToolBar5;
	TAdvToolBar *AdvToolBar6;
	TAdvPage *AdvPage3;
	TAdvGlowButton *SurButton;
	TAdvGlowButton *NameButton;
	TAdvGlowButton *PatButton;
	TAdvGlowButton *BDateButton;
	TAdvGlowButton *CDateButton;
	TAdvGlowButton *AddButton;
	TAdvGlowButton *FamButton;
	TAdvGlowButton *TelButton;
	TAdvGlowButton *NatButton;
	TAdvGlowButton *ProButton;
	TAdvToolBar *AdvToolBar2;
	TAdvGlowButton *AddMemButton;
	TAdvGlowButton *DeleteMemButton;
	TAdvPage *AdvPage4;
	TAdvPopupMenu *StyleMenu;
	TAdvMenuOfficeStyler *AdvMenuOfficeStyler;
	TMenuItem *LunaMenuItem;
	TMenuItem *SilverMenuItem;
	TMenuItem *BlueMenuItem;
	TMenuItem *OliveMenuItem;
	TMenuItem *Silver2MenuItem;
	TAdvGlowButton *EditMemButton;
	TAdvShapeButton *ShapeButton;
	TAdvPage *AdvPage2;
	TAdvToolBar *AdvToolBar10;
	TAdvGlowButton *ReportButton;
	TAdvToolBar *AdvToolBar3;
	TAdvGlowButton *WordButton;
	TAdvGlowButton *ExcelButton;
	TSaveDialog *SaveDialog;
	TfrxReport *frxReport;
	TfrxDBDataset *frxDBDataset;
	TfrxPDFExport *frxPDFExport;
	TfrxRTFExport *frxRTFExport;
	TAdvGlowButton *PDFButton;
	TAdvGlowButton *HTMLButton;
	TAdvGlowButton *TextButton;
	TfrxHTMLExport *frxHTMLExport;
	TfrxXLSExport *frxXLSExport;
	TfrxSimpleTextExport *frxSimpleTextExport;
	TAdvPanel *CenterPanel;
	TAdvPanel *TopPanel;
	TAdvPanelGroup *SearchPanelGroup;
	TLabel *SearchLabel;
	TAdvMaskEdit *SearchEdit;
	TAdvGlowButton *SearchButton;
	TAdvGlowButton *ShowAllButton;
	TAdvOfficeStatusBar *AdvOfficeStatusBar1;
	TDBGrid *DBGrid;
	TfrxDialogControls *frxDialogControls1;
	TAdvToolBar *AdvToolBar4;
	TAdvOfficeCheckBox *DateCheckBox;
	TAdvOfficeCheckBox *TitleCheckBox;
	TAdvEdit *TitleEdit;
	TOpenDialog *OpenDialog;
	TAdvToolBar *AdvToolBar8;
	TAdvGlowButton *AboutButton;
	TAdvToolBar *AdvToolBar9;
	TAdvGlowButton *GlowButton;
	TAdvToolBar *AdvToolBar7;
	TAdvGlowButton *AddMemPhotoButton;
	TAdvGlowButton *DeleteMemPhotoButton;
	TOpenPictureDialog *OpenPictureDialog;
	TAdvGlowButton *ViewMemPhotoButton;
	TAdvComboBox *DayComboBox;
	TAdvComboBox *MonComboBox;
	TAdvComboBox *YearComboBox;
	TAdvPanelGroup *ParamPanelGroup;
	TAdvOfficeCheckBox *DayCheckBox;
	TLabel *Label1;
	TAdvOfficeCheckBox *MonCheckBox;
	TAdvOfficeCheckBox *YearCheckBox;
	void __fastcall SurButtonClick(TObject *Sender);
	void __fastcall NameButtonClick(TObject *Sender);
	void __fastcall PatButtonClick(TObject *Sender);
	void __fastcall BDateButtonClick(TObject *Sender);
	void __fastcall CDateButtonClick(TObject *Sender);
	void __fastcall NatButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall TelButtonClick(TObject *Sender);
	void __fastcall FamButtonClick(TObject *Sender);
	void __fastcall ProButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ShowAllButtonClick(TObject *Sender);
	void __fastcall AddMemButtonClick(TObject *Sender);
	void __fastcall DeleteMemButtonClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall SearchEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall LunaMenuItemClick(TObject *Sender);
	void __fastcall SilverMenuItemClick(TObject *Sender);
	void __fastcall BlueMenuItemClick(TObject *Sender);
	void __fastcall OliveMenuItemClick(TObject *Sender);
	void __fastcall Silver2MenuItemClick(TObject *Sender);
	void __fastcall AboutButtonClick(TObject *Sender);
	void __fastcall EditMemButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ReportButtonClick(TObject *Sender);
	void __fastcall WordButtonClick(TObject *Sender);
	void __fastcall ExcelButtonClick(TObject *Sender);
	void __fastcall PDFButtonClick(TObject *Sender);
	void __fastcall HTMLButtonClick(TObject *Sender);
	void __fastcall TextButtonClick(TObject *Sender);
	void __fastcall TitleCheckBoxClick(TObject *Sender);
	void __fastcall AddMemPhotoButtonClick(TObject *Sender);
	void __fastcall ViewMemPhotoButtonClick(TObject *Sender);
	void __fastcall DeleteMemPhotoButtonClick(TObject *Sender);
	void __fastcall DBGridCellClick(TColumn *Column);
	void __fastcall DBGridKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
    AnsiString PATH;
	short curID, styleIndex;
	unsigned int msgRestore;
	TDataFile *SettingsFile;
    void __fastcall ConnectToDB();
	void __fastcall PrepareReport();
	void __fastcall PerformQuery(short qID);
	void __fastcall ChangeSearchPanel(AnsiString Caption, AnsiString Mask, short ButtonID);
	AnsiString __fastcall GetMD5Hash(AnsiString text);
	void __fastcall AddPhoto(AnsiString existingFileName);
public:		// User declarations
	bool EditMode;
	__fastcall TMainForm(TComponent* Owner);
	bool __fastcall MessageHandler(TMessage &Message);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
