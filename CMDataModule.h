//---------------------------------------------------------------------------
#ifndef CMDataModuleH
#define CMDataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TCMData : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection;
	TADOQuery *ADOQuery;
	TDataSource *DataSource;
private:	// User declarations
public:		// User declarations
	__fastcall TCMData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCMData *CMData;
//---------------------------------------------------------------------------
#endif
