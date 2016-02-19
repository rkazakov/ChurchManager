// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Datafile.pas' rev: 10.00

#ifndef DatafileHPP
#define DatafileHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Datafile
{
//-- type declarations -------------------------------------------------------
typedef char DF_IDENTNAME[36];

struct IDataHeader;
typedef IDataHeader *pDataHeader;

#pragma pack(push,1)
struct IDataHeader
{
	
public:
	int Id;
	char Section[36];
	char Ident[36];
	int Size;
} ;
#pragma pack(pop)

class DELPHICLASS TDataFile;
class PASCALIMPLEMENTATION TDataFile : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TFileStream* FFile;
	AnsiString FFileName;
	AnsiString FCodeKey;
	int __fastcall GetSectionCount(void);
	bool __fastcall FindIdent(AnsiString Section, AnsiString Ident, pDataHeader pHdr);
	
public:
	__fastcall TDataFile(const AnsiString FileName);
	__fastcall virtual ~TDataFile(void);
	void __fastcall GetSectionNames(Classes::TStrings* List);
	void __fastcall GetValueNames(AnsiString Section, Classes::TStrings* List);
	bool __fastcall SectionExists(AnsiString Section);
	bool __fastcall ValueExists(AnsiString Section, AnsiString Ident);
	int __fastcall ReadData(AnsiString Section, AnsiString Ident, void * pBuf);
	int __fastcall ReadStream(AnsiString Section, AnsiString Ident, Classes::TStream* Stream);
	AnsiString __fastcall ReadString(AnsiString Section, AnsiString Ident, AnsiString Default);
	int __fastcall ReadInteger(AnsiString Section, AnsiString Ident, int Default);
	double __fastcall ReadDouble(AnsiString Section, AnsiString Ident, double Default);
	Extended __fastcall ReadExtended(AnsiString Section, AnsiString Ident, Extended Default);
	System::TDateTime __fastcall ReadDateTime(AnsiString Section, AnsiString Ident, System::TDateTime Default);
	bool __fastcall ReadBoolean(AnsiString Section, AnsiString Ident, bool Default);
	void __fastcall ReadStrings(AnsiString Section, AnsiString Ident, Classes::TStrings* List);
	void __fastcall ReadFont(AnsiString Section, AnsiString Ident, Graphics::TFont* Font);
	int __fastcall WriteData(AnsiString Section, AnsiString Ident, void * pBuf, int Count);
	int __fastcall WriteStream(AnsiString Section, AnsiString Ident, Classes::TStream* Stream);
	void __fastcall WriteString(AnsiString Section, AnsiString Ident, AnsiString Value);
	void __fastcall WriteInteger(AnsiString Section, AnsiString Ident, int Value);
	void __fastcall WriteDouble(AnsiString Section, AnsiString Ident, double Value);
	void __fastcall WriteExtended(AnsiString Section, AnsiString Ident, Extended Value);
	void __fastcall WriteDateTime(AnsiString Section, AnsiString Ident, System::TDateTime Value);
	void __fastcall WriteBoolean(AnsiString Section, AnsiString Ident, bool Value);
	void __fastcall WriteStrings(AnsiString Section, AnsiString Ident, Classes::TStrings* List);
	void __fastcall WriteFont(AnsiString Section, AnsiString Ident, Graphics::TFont* Font);
	void __fastcall Delete(AnsiString Section, AnsiString Ident);
	void __fastcall DeleteSection(AnsiString Section);
	DYNAMIC void __fastcall EncryptBuf(void * pBuf, int BufLen);
	DYNAMIC void __fastcall DecryptBuf(void * pBuf, int BufLen);
	__property AnsiString CodeKey = {read=FCodeKey, write=FCodeKey};
	__property AnsiString FileName = {read=FFileName};
	__property int SectionCount = {read=GetSectionCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MAX_NAMELEN = 0x24;
static const Byte MAX_PATHLEN = 0xf0;
#define SECTION_TEST "$test"

}	/* namespace Datafile */
using namespace Datafile;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Datafile
