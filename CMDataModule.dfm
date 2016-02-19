object CMData: TCMData
  OldCreateOrder = False
  Height = 75
  Width = 287
  object ADOConnection: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Password=manager;Persist Security Info=True;U' +
      'ser ID=admin;Extended Properties="DBQ=C:\ChurchManager\cmdatabas' +
      'e.mdb;DefaultDir=C:\ChurchManager;Driver={Driver do Microsoft Ac' +
      'cess (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=C:\ChurchManager' +
      '\cmdatabase.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout' +
      '=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;"'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'MSDASQL.1'
    Left = 40
    Top = 8
  end
  object ADOQuery: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select mSur, mName, mPat, mBD, mCD, mNat, mAdd, mTel, mFam, '
      'mPro, mLife, mSug, mEtc, mPhoto, ID from tblMembers'
      'order by mSur, mName, mPat')
    Left = 136
    Top = 8
  end
  object DataSource: TDataSource
    DataSet = ADOQuery
    Left = 218
    Top = 8
  end
end
