//---------------------------------------------------------------------------
#include <vcl.h>
#include <Clipbrd.hpp>
#pragma hdrstop
#include "MainFrm.h"
#include "AboutFrm.h"
#include "AddMemFrm.h"
#include "CMDataModule.h"
#include "md5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "gdiplus.lib"
#pragma link "AdvToolBar"
#pragma link "AdvToolBarStylers"
#pragma link "AdvOfficeStatusBar"
#pragma link "AdvOfficeStatusBarStylers"
#pragma link "BaseGrid"
#pragma link "AdvPanel"
#pragma link "AdvMenus"
#pragma link "AdvMenuStylers"
#pragma link "AdvGlowButton"
#pragma link "datelbl"
#pragma link "AdvEdit"
#pragma link "AdvGlassButton"
#pragma link "AdvShapeButton"
#pragma link "AdvOfficeButtons"
#pragma link "AdvOfficeHint"
#pragma link "AdvOfficeComboBox"
#pragma link "frxClass"
#pragma link "frxExportRTF"
#pragma link "frxADOComponents"
#pragma link "frxDBSet"
#pragma link "frxExportPDF"
#pragma link "frxExportHTML"
#pragma link "frxExportXLS"
#pragma link "frxExportText"
#pragma link "frxDCtrl"
#pragma link "AdvCombo"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner)
{
	curID = 1;
	styleIndex = 1;
	msgRestore = RegisterWindowMessage("WM_ChurchManager_Instance");
	Application->HookMainWindow(MessageHandler);
	
	SettingsFile = new TDataFile("ChurchManager.dat");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SurButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по фамилии:","",1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NameButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по имени:","",2);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PatButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по отчеству:","",3);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BDateButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по дате рождения:","",4);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CDateButtonClick(TObject *Sender)
{
    ChangeSearchPanel("Поиск по дате крещения:","",5);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NatButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по национальности:","",6);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по адресу:","",7);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TelButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по номеру телефона:","",8);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FamButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по семейному положению:","",9);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ProButtonClick(TObject *Sender)
{
	ChangeSearchPanel("Поиск по профессии:","",10);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ChangeSearchPanel(AnsiString Caption, AnsiString Mask,
	short ButtonID)
{
    curID = ButtonID;
	SearchLabel->Caption = Caption;
	SearchEdit->EditMask = Mask;
	SurButton->Down = False;
	NameButton->Down = False;
	PatButton->Down = False;
	BDateButton->Down = False;
	CDateButton->Down = False;
	NatButton->Down = False;
	AddButton->Down = False;
	TelButton->Down = False;
	FamButton->Down = False;
	ProButton->Down = False;
	ParamPanelGroup->Visible = False;
	DayComboBox->Visible = False;
	MonComboBox->Visible = False;
	YearComboBox->Visible = False;
	SearchEdit->Visible = True;
	switch (ButtonID) {
		case 1: SurButton->Down = True;	break;
		case 2: NameButton->Down = True; break;
		case 3: PatButton->Down = True; break;
		case 4:
			BDateButton->Down = True;
			ParamPanelGroup->Visible = True;
			DayComboBox->Visible = True;
			MonComboBox->Visible = True;
			YearComboBox->Visible = True;
			SearchEdit->Visible = False;
		break;
		case 5:
			CDateButton->Down = True;
			ParamPanelGroup->Visible = True;
			DayComboBox->Visible = True;
			MonComboBox->Visible = True;
			YearComboBox->Visible = True;
			SearchEdit->Visible = False;
		break;
		case 6: NatButton->Down = True; break;
		case 7: AddButton->Down = True; break;
		case 8: TelButton->Down = True; break;
		case 9: FamButton->Down = True; break;
		case 10: ProButton->Down = True; break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	PATH = SettingsFile->ReadString("MainForm","PATH",GetCurrentDir()+"\\cmdata.mdb");

	if (!FileExists(PATH)) {
		 OpenDialog->FileName = PATH;
		 if (OpenDialog->Execute()) {
			PATH = OpenDialog->FileName;
			ConnectToDB();
		 } else {
			MessageDlg("Файл '" + PATH + "' не найден!", mtError, TMsgDlgButtons() << mbOK, 0);
            Application->Terminate();
		 }
	} else {
		ConnectToDB();
	}
	ToolBarPager->Caption->Caption = "ChurchManager 4.0 [" + PATH + "]";

	if (SettingsFile->ReadBoolean("MainForm", "WindowStateMaximized", 0))
		WindowState = wsMaximized;
	else {
		Left = SettingsFile->ReadInteger("MainForm", "Left", Screen->WorkAreaWidth - Width);
		Top = SettingsFile->ReadInteger("MainForm", "Top", Screen->WorkAreaHeight - Height);
	}
	styleIndex = SettingsFile->ReadInteger("MainForm", "StyleIndex", 1);
	if (styleIndex == 1) {
		LunaMenuItemClick(this);
		LunaMenuItem->Checked = true;
	}
	else if (styleIndex == 2) {
		SilverMenuItemClick(this);
		SilverMenuItem->Checked = true;
	}
	else if (styleIndex == 3) {
		BlueMenuItemClick(this);
		BlueMenuItem->Checked = true;
	}
	else if (styleIndex == 4) {
		OliveMenuItemClick(this);
		OliveMenuItem->Checked = true;
	}
	else {
		Silver2MenuItemClick(this);
		Silver2MenuItem->Checked = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConnectToDB()
{
		AnsiString cs = "";
		cs += "Provider=MSDASQL.1;Password=manager;";
		cs += "Persist Security Info=False;User ID=admin;";
		cs += "Extended Properties=\"DBQ=" + PATH + ";";
		cs += "Driver={Driver do Microsoft Access (*.mdb)};";
		cs += "DriverId=25;";
		cs += "FIL=MS Access;";
		cs += "MaxBufferSize=2048;";
		cs += "MaxScanRows=8;";
		cs += "PageTimeout=5;";
		cs += "SafeTransactions=0;";
		cs += "Threads=3;";
		cs += "UID=admin;";
		cs += "UserCommitSync=Yes;\"";
		CMData->ADOConnection->ConnectionString = cs;
		CMData->ADOConnection->Connected = True;
		CMData->ADOQuery->Active = True;
		AdvOfficeStatusBar1->Panels->Items[1]->Text =
			String("Всего записей (членов церкви) в базе данных: ") + CMData->ADOQuery->RecordCount;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowAllButtonClick(TObject *Sender)
{
	PerformQuery(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddMemButtonClick(TObject *Sender)
{
    EditMode = false;
	CMData->ADOQuery->Last();
	CMData->ADOQuery->Append();
	AddMemForm = new TAddMemForm(this);
	AddMemForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteMemButtonClick(TObject *Sender)
{
	if (MessageDlg("Вы уверены, что хотите удалить выбранную запись?",
			mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == 6)
		CMData->ADOQuery->Delete();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PerformQuery(short qID)
{
    AnsiString date = "";
	AnsiString query = "";
	query = "select mSur, mName, mPat, mBD, mCD, mNat, mAdd, mTel, " +
		String("mFam, mPro, mLife, mSug, mEtc, mPhoto, ID ");
	switch (qID) {
		case 0: // ShowAll
			query = "select mSur, mName, mPat, mBD, mCD, mNat, mAdd, mTel, mFam, mPro, " +
			String("mLife, mSug, mEtc, mPhoto, ID from tblMembers");
		break;
		case 1: // Surname
			query += "from tblMembers where mSur like '" + SearchEdit->Text + "%'";
		break;
		case 2: // Name
			query += "from tblMembers where mName like '" + SearchEdit->Text + "%'";
		break;
		case 3: // Patronymic
			query += "from tblMembers where mPat like '" + SearchEdit->Text + "%'";
		break;
		case 4: // BirthDate
			date += (DayCheckBox->Checked ? DayComboBox->Text : String("%")) + ".";
			if (MonCheckBox->Checked) {
				if (String(MonComboBox->ItemIndex+1).Length() == 1)
					date += "0" + AnsiString(MonComboBox->ItemIndex+1);
				else if (String(MonComboBox->ItemIndex+1).Length() == 2 && MonComboBox->ItemIndex+1 < 13)
					date += AnsiString(MonComboBox->ItemIndex+1);
				else if (MonComboBox->ItemIndex+1 == 13) date += "Зима";
				else if (MonComboBox->ItemIndex+1 == 14) date += "Весна";
				else if (MonComboBox->ItemIndex+1 == 15) date += "Лето";
				else if (MonComboBox->ItemIndex+1 == 16) date += "Осень";            
			} else {
				date += AnsiString("%");
			}
            date += ".";
			date += (YearCheckBox->Checked ? YearComboBox->Text : String("%"));
			query += "from tblMembers where mBD like '" + date + "'";
        	query += " order by mBD";
		break;
		case 5: // Christen Date
			date += (DayCheckBox->Checked ? DayComboBox->Text : String("%")) + ".";
			if (MonCheckBox->Checked) {
				if (String(MonComboBox->ItemIndex+1).Length() == 1)
					date += "0" + AnsiString(MonComboBox->ItemIndex+1);
				else if (String(MonComboBox->ItemIndex+1).Length() == 2 && MonComboBox->ItemIndex+1 < 13)
					date += AnsiString(MonComboBox->ItemIndex+1);
				else if (MonComboBox->ItemIndex+1 == 13) date += "Зима";
				else if (MonComboBox->ItemIndex+1 == 14) date += "Весна";
				else if (MonComboBox->ItemIndex+1 == 15) date += "Лето";
				else if (MonComboBox->ItemIndex+1 == 16) date += "Осень";            
			} else {
				date += AnsiString("%");
			}
            date += ".";
			date += (YearCheckBox->Checked ? YearComboBox->Text : String("%"));
			query += "from tblMembers where mCD like '" + date + "'";
			query += " order by mCD";
		break;
		case 6: // Nationality
			query += "from tblMembers where mNat like '" + SearchEdit->Text + "%'";
		break;
		case 7: // Address
			query += "from tblMembers where mAdd like '%" + SearchEdit->Text + "%'";
		break;
		case 8: // Telephone
			query += "from tblMembers where mTel like '%" + SearchEdit->Text + "%'";
		break;
		case 9: // Family
			query += "from tblMembers where mFam like '" + SearchEdit->Text + "%'";
		break;
		case 10: // Profession
			query += "from tblMembers where mPro like '%" + SearchEdit->Text + "%'";
		break;
	}
	if (qID != 4 && qID != 5) {
		query += " order by mSur, mName, mPat";
	}

	CMData->ADOQuery->SQL->Clear();
	CMData->ADOQuery->SQL->Add(query);
	CMData->ADOQuery->Open();

	AdvOfficeStatusBar1->Panels->Items[0]->Text =
		String("Найдено записей (членов церкви): ") + CMData->ADOQuery->RecordCount;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchButtonClick(TObject *Sender)
{
	PerformQuery(curID);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchEditKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key == 9) {
		PerformQuery(curID);
		SearchEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LunaMenuItemClick(TObject *Sender)
{
	SearchButton->Appearance->Color = StringToColor("0x00EEDBC8");
	SearchButton->Appearance->ColorMirror = StringToColor("0x00EEDBC8");
	SearchButton->Appearance->ColorTo = StringToColor("0x00F6DDC9");
	SearchButton->Appearance->ColorMirrorTo = StringToColor("0x00F6DDC9");
	SearchButton->Appearance->BorderColor = StringToColor("0x00E0B99B");
	ShowAllButton->Appearance->Color = StringToColor("0x00EEDBC8");
	ShowAllButton->Appearance->ColorMirror = StringToColor("0x00EEDBC8");
	ShowAllButton->Appearance->ColorTo = StringToColor("0x00F6DDC9");
	ShowAllButton->Appearance->ColorMirrorTo = StringToColor("0x00F6DDC9");
	ShowAllButton->Appearance->BorderColor = StringToColor("0x00E0B99B");
	DBGrid->FixedColor = StringToColor("clSkyBlue");
	AdvMenuOfficeStyler->Style = osOffice2007Luna;
	AdvToolBarOfficeStyler->Style = bsOffice2007Luna;
	AdvPanelStyler->Style = Advpanel::psOffice2007Luna;
	AdvOfficeStatusBarOfficeStyler->Style = Advofficestatusbarstylers::psOffice2007Luna;

	SilverMenuItem->Checked = false;
	BlueMenuItem->Checked = false;
	OliveMenuItem->Checked = false;
	Silver2MenuItem->Checked = false;
	styleIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SilverMenuItemClick(TObject *Sender)
{
	SearchButton->Appearance->Color = StringToColor("0x00E9E9E9");
	SearchButton->Appearance->ColorMirror = StringToColor("0x00E9E9E9");
	SearchButton->Appearance->ColorTo = StringToColor("0x00E9E9E9");
	SearchButton->Appearance->ColorMirrorTo = StringToColor("0x00E9E9E9");
	SearchButton->Appearance->BorderColor = StringToColor("0x00DDD4D0");
	ShowAllButton->Appearance->Color = StringToColor("0x00E9E9E9");
	ShowAllButton->Appearance->ColorTo = StringToColor("0x00E9E9E9");
	ShowAllButton->Appearance->ColorMirrorTo = StringToColor("0x00E9E9E9");
	ShowAllButton->Appearance->BorderColor = StringToColor("0x00DDD4D0");
	DBGrid->FixedColor = StringToColor("0x00DDD4D0");
	//DBAdvGrid->ControlLook->FixedGradientFrom = StringToColor("0x00E9E9E9");
	//DBAdvGrid->ControlLook->FixedGradientTo = StringToColor("0x00DDD4D0");
	AdvMenuOfficeStyler->Style = osOffice2007Silver;
	AdvToolBarOfficeStyler->Style = bsOffice2007Silver;
	AdvPanelStyler->Style = Advpanel::psOffice2007Silver;
	AdvOfficeStatusBarOfficeStyler->Style = Advofficestatusbarstylers::psOffice2007Silver;

	LunaMenuItem->Checked = false;
	BlueMenuItem->Checked = false;
	OliveMenuItem->Checked = false;
	Silver2MenuItem->Checked = false;
	styleIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BlueMenuItemClick(TObject *Sender)
{
	SearchButton->Appearance->Color = StringToColor("0x00EEDBC8");
	SearchButton->Appearance->ColorMirror = StringToColor("0x00EEDBC8");
	SearchButton->Appearance->ColorTo = StringToColor("0x00F6DDC9");
	SearchButton->Appearance->ColorMirrorTo = StringToColor("0x00F6DDC9");
	SearchButton->Appearance->BorderColor = StringToColor("0x00E0B99B");
	ShowAllButton->Appearance->Color = StringToColor("0x00EEDBC8");
	ShowAllButton->Appearance->ColorTo = StringToColor("0x00F6DDC9");
	ShowAllButton->Appearance->ColorMirrorTo = StringToColor("0x00F6DDC9");
	ShowAllButton->Appearance->BorderColor = StringToColor("0x00E0B99B");
	DBGrid->FixedColor = StringToColor("0x00E0A57D");
	//DBAdvGrid->ControlLook->FixedGradientFrom = StringToColor("0x00FCE1CB");
	//DBAdvGrid->ControlLook->FixedGradientTo = StringToColor("0x00E0A57D");
	AdvMenuOfficeStyler->Style = osOffice2003Blue;
	AdvToolBarOfficeStyler->Style = bsOffice2003Blue;
	AdvPanelStyler->Style = Advpanel::psOffice2003Blue;
	AdvOfficeStatusBarOfficeStyler->Style = Advofficestatusbarstylers::psOffice2003Blue;

	LunaMenuItem->Checked = false;
	SilverMenuItem->Checked = false;
	OliveMenuItem->Checked = false;
	Silver2MenuItem->Checked = false;
	styleIndex = 3;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OliveMenuItemClick(TObject *Sender)
{
	SearchButton->Appearance->Color = StringToColor("0x00CFF0EA");
	SearchButton->Appearance->ColorMirror = StringToColor("0x00CFF0EA");
	SearchButton->Appearance->ColorTo = StringToColor("0x00CFF0EA");
	SearchButton->Appearance->ColorMirrorTo = StringToColor("0x00CFF0EA");
	SearchButton->Appearance->BorderColor = StringToColor("0x008CC0B1");
	ShowAllButton->Appearance->Color = StringToColor("0x00CFF0EA");
	ShowAllButton->Appearance->ColorMirror = StringToColor("0x00CFF0EA");
	ShowAllButton->Appearance->ColorTo = StringToColor("0x00CFF0EA");
	ShowAllButton->Appearance->ColorMirrorTo = StringToColor("0x00CFF0EA");
	ShowAllButton->Appearance->BorderColor = StringToColor("0x008CC0B1");
	DBGrid->FixedColor = StringToColor("0x008CC0B1");
	//DBAdvGrid->ControlLook->FixedGradientFrom = StringToColor("0x00CFF0EA");
	//DBAdvGrid->ControlLook->FixedGradientTo = StringToColor("0x008CC0B1");
	AdvMenuOfficeStyler->Style = osOffice2003Olive;
	AdvToolBarOfficeStyler->Style = bsOffice2003Olive;
	AdvPanelStyler->Style = Advpanel::psOffice2003Olive;
	AdvOfficeStatusBarOfficeStyler->Style = Advofficestatusbarstylers::psOffice2003Olive;

	LunaMenuItem->Checked = false;
	SilverMenuItem->Checked = false;
	BlueMenuItem->Checked = false;
	Silver2MenuItem->Checked = false;
	styleIndex = 4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Silver2MenuItemClick(TObject *Sender)
{
	SearchButton->Appearance->Color = StringToColor("0x00ECE2E1");
	SearchButton->Appearance->ColorMirror = StringToColor("0x00ECE2E1");
	SearchButton->Appearance->ColorTo = StringToColor("0x00ECE2E1");
	SearchButton->Appearance->ColorMirrorTo = StringToColor("0x00ECE2E1");
	SearchButton->Appearance->BorderColor = StringToColor("0x00ECE2E1");
	ShowAllButton->Appearance->Color = StringToColor("0x00ECE2E1");
	ShowAllButton->Appearance->ColorMirror = StringToColor("0x00ECE2E1");
	ShowAllButton->Appearance->ColorTo = StringToColor("0x00ECE2E1");
	ShowAllButton->Appearance->ColorMirrorTo = StringToColor("0x00ECE2E1");
	ShowAllButton->Appearance->BorderColor = StringToColor("0x00ECE2E1");
	DBGrid->FixedColor = StringToColor("0x00B39698");
	//DBAdvGrid->ControlLook->FixedGradientFrom = StringToColor("0x00ECE2E1");
	//DBAdvGrid->ControlLook->FixedGradientTo = StringToColor("0x00B39698");
	AdvMenuOfficeStyler->Style = osOffice2003Silver;
	AdvToolBarOfficeStyler->Style = bsOffice2003Silver;
	AdvPanelStyler->Style = Advpanel::psOffice2003Silver;
	AdvOfficeStatusBarOfficeStyler->Style = Advofficestatusbarstylers::psOffice2003Silver;

	LunaMenuItem->Checked = false;
	SilverMenuItem->Checked = false;
	BlueMenuItem->Checked = false;
	OliveMenuItem->Checked = false;
	styleIndex = 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AboutButtonClick(TObject *Sender)
{
	AboutForm = new TAboutForm(this);
	AboutForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EditMemButtonClick(TObject *Sender)
{
    EditMode = true;
	AddMemForm = new TAddMemForm(this);
	AddMemForm->ShowModal();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::MessageHandler(TMessage &Message)
{
	if (Message.Msg == msgRestore) {
		Application->Restore();
		Application->BringToFront();
		return true;
	}
	else
		return false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
	if (WindowState == wsMaximized)
		SettingsFile->WriteBoolean("MainForm", "WindowStateMaximized", true);
	else {
		SettingsFile->WriteBoolean("MainForm", "WindowStateMaximized", false);
		SettingsFile->WriteInteger("MainForm", "Left", Left);
		SettingsFile->WriteInteger("MainForm", "Top", Top);
		SettingsFile->WriteInteger("MainForm", "StyleIndex", styleIndex);
	}
    SettingsFile->WriteString("MainForm","PATH",PATH);

	// unhook
	Application->UnhookMainWindow(MessageHandler);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReportButtonClick(TObject *Sender)
{
    PrepareReport();
	frxReport->ShowReport(true);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WordButtonClick(TObject *Sender)
{
    PrepareReport();
	if (frxReport->PrepareReport(true))
		frxReport->Export(frxRTFExport);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelButtonClick(TObject *Sender)
{
	PrepareReport();
	if (frxReport->PrepareReport(true))
		frxReport->Export(frxXLSExport);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PDFButtonClick(TObject *Sender)
{
	PrepareReport();
	if (frxReport->PrepareReport(true))
		frxReport->Export(frxPDFExport);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HTMLButtonClick(TObject *Sender)
{
	PrepareReport();
	if (frxReport->PrepareReport(true))
		frxReport->Export(frxHTMLExport);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TextButtonClick(TObject *Sender)
{
	PrepareReport();
	if (frxReport->PrepareReport(true));
		frxReport->Export(frxSimpleTextExport);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TitleCheckBoxClick(TObject *Sender)
{
	if (TitleCheckBox->Checked) TitleEdit->Enabled = true;
	else TitleEdit->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrepareReport()
{
	TfrxMemoView *TitleMemo = new TfrxMemoView(this);
	TitleMemo = (TfrxMemoView *) frxReport->FindObject("Memo18");
	TfrxMemoView *DateMemo = new TfrxMemoView(this);
	TitleMemo = (TfrxMemoView *) frxReport->FindObject("Memo16");
	TfrxReportTitle *ReportTitle = new TfrxReportTitle(this);
	ReportTitle = (TfrxReportTitle *) frxReport->FindObject("ReportTitle1");

	if (TitleCheckBox->Checked) {
		TitleMemo->Text = TitleEdit->Text;
		TitleMemo->Visible = true;
	} else {
		TitleMemo->Visible = false;
	}

	if (DateCheckBox->Checked) DateMemo->Visible = true;
	else DateMemo->Visible = false;

	if (!DateCheckBox->Checked && !TitleCheckBox->Checked) {
    	ReportTitle->Visible = false;
	}
	if (DateCheckBox->Checked || TitleCheckBox->Checked) {
		ReportTitle->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddMemPhotoButtonClick(TObject *Sender)
{
	if (DBGrid->Fields[13]->AsString.IsEmpty()) {
		AddPhoto("");
	} else {
		if (MessageDlg("Данная запись уже содержит фото! Заменить?", mtWarning,
				TMsgDlgButtons() << mbYes << mbNo, 0) == 6) {
			AddPhoto(DBGrid->Fields[13]->AsString);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddPhoto(AnsiString existingFileName)
{
	AnsiString photoFile = "";
    AnsiString hash = "";
	if (existingFileName.IsEmpty()) {
		Randomize();
		hash = GetMD5Hash(AnsiString(Random(99999999999999999999999999999999)));
		photoFile = GetAppPath()+"Photo\\"+hash+".jpg";
	} else {
		hash = existingFileName;
	}
    photoFile = GetAppPath()+"Photo\\"+hash+".jpg";

	if (OpenPictureDialog->Execute()) {
		if (!OpenPictureDialog->FileName.IsEmpty()) {
			if (FileExists(OpenPictureDialog->FileName)) {
				int ID = DBGrid->Fields[14]->AsInteger;
				AnsiString query = "UPDATE tblMembers SET mPhoto = '" + hash + "' WHERE ID = " + AnsiString(ID);
				CMData->ADOQuery->SQL->Clear();
				CMData->ADOQuery->SQL->Add(query);
				CMData->ADOQuery->ExecSQL();
				query = AnsiString("select mSur, mName, mPat, mBD, mCD, mNat, mAdd, mTel, mFam, mPro, ") +
					AnsiString ("mLife, mSug, mEtc, mPhoto, ID from tblMembers order by mSur, mName, mPat");
				CMData->ADOQuery->SQL->Clear();
				CMData->ADOQuery->SQL->Add(query);
				CMData->ADOQuery->Open();
				CopyFile(OpenPictureDialog->FileName.c_str(), photoFile.c_str(), false);
			} else {
				MessageDlg("Файл '" + OpenPictureDialog->FileName + "' не найден!", mtError, TMsgDlgButtons() << mbOK, 0);
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ViewMemPhotoButtonClick(TObject *Sender)
{
	if (!DBGrid->Fields[13]->AsString.IsEmpty()) {
		HWND h;
		AnsiString photoFile = GetAppPath()+"Photo\\"+DBGrid->Fields[13]->AsString+".jpg";

		if (FileExists(photoFile))
			ShellExecute(h, "open", photoFile.c_str(), NULL, NULL, SW_SHOW);
		else
			MessageDlg("Файл '" + photoFile + "' не найден!", mtError, TMsgDlgButtons() << mbOK, 0);
	} else {
		MessageDlg("Для этой записи еще нет фото!", mtWarning, TMsgDlgButtons() << mbOK, 0);    	
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteMemPhotoButtonClick(TObject *Sender)
{
    if (!DBGrid->Fields[13]->AsString.IsEmpty()) {
		if (MessageDlg("Вы уверены, что хотите удалить фото в этой записи?",
			mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == 6) {

			AnsiString photoFile = GetAppPath()+"Photo\\"+DBGrid->Fields[13]->AsString+".jpg";
			int ID = DBGrid->Fields[14]->AsInteger;
			AnsiString query = "UPDATE tblMembers SET mPhoto = '' WHERE ID = " + AnsiString(ID);
			CMData->ADOQuery->SQL->Clear();
			CMData->ADOQuery->SQL->Add(query);
			CMData->ADOQuery->ExecSQL();
			query = AnsiString("select mSur, mName, mPat, mBD, mCD, mNat, mAdd, mTel, mFam, mPro, ") +
				AnsiString ("mLife, mSug, mEtc, mPhoto, ID from tblMembers order by mSur, mName, mPat");
			CMData->ADOQuery->SQL->Clear();
			CMData->ADOQuery->SQL->Add(query);
			CMData->ADOQuery->Open();

			if (FileExists(photoFile)) {
				DeleteFileA(photoFile);
			} else {
				MessageDlg("Файл '" + photoFile + "' не найден!", mtError, TMsgDlgButtons() << mbOK, 0);
			}
		}
	} else
		MessageDlg("Данная запись не содержит фото!", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetMD5Hash(AnsiString text)
{
	char out_char[32];
	int len = text.Length();
	GetMD5(text.c_str(), len++, out_char);
	return AnsiString(out_char);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridCellClick(TColumn *Column)
{
	if (!DBGrid->Fields[13]->AsString.IsEmpty()) {
		ViewMemPhotoButton->Enabled = True;
		DeleteMemPhotoButton->Enabled = True;
	}
	else {
		ViewMemPhotoButton->Enabled = False;
		DeleteMemPhotoButton->Enabled = False;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (!DBGrid->Fields[13]->AsString.IsEmpty()) {
		ViewMemPhotoButton->Enabled = True;
		DeleteMemPhotoButton->Enabled = True;
	}
	else {
		ViewMemPhotoButton->Enabled = False;
		DeleteMemPhotoButton->Enabled = False;
	}
}
//---------------------------------------------------------------------------

