object data: Tdata
  Height = 750
  Width = 1000
  PixelsPerInch = 120
  object Veza: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLNCLI11.1;Integrated Security=SSPI;Persist Security I' +
      'nfo=False;User ID="";Initial Catalog=knjiznicaDB;Data Source=loc' +
      'alhost\SQLExpress;Use Procedure for Prepare=1;Auto Translate=Tru' +
      'e;Packet Size=4096;Workstation ID=DESKTOP-BSSIIQ5;Initial File N' +
      'ame="";Use Encryption for Data=False;Tag with column collation w' +
      'hen possible=False;MARS Connection=False;DataTypeCompatibility=0' +
      ';Trust Server Certificate=False;Application Intent=READWRITE'
    LoginPrompt = False
    Provider = 'SQLNCLI11.1'
    Left = 96
    Top = 160
  end
  object DAutori: TDataSource
    DataSet = TAutori
    Left = 216
    Top = 88
  end
  object DKnjige: TDataSource
    DataSet = TKnjige
    Left = 344
    Top = 88
  end
  object DKorisnici: TDataSource
    DataSet = TKorisnici
    Left = 464
    Top = 88
  end
  object TAutori: TADOTable
    Active = True
    Connection = Veza
    CursorType = ctStatic
    TableName = 'autori'
    Left = 192
    Top = 208
    object TAutoriIDAutora: TAutoIncField
      FieldName = 'IDAutora'
      ReadOnly = True
    end
    object TAutoriimeAutora: TWideStringField
      FieldName = 'imeAutora'
      Size = 50
    end
    object TAutoriprezimeAutora: TWideStringField
      FieldName = 'prezimeAutora'
      Size = 50
    end
    object TAutoridatumRodjenja: TDateTimeField
      FieldName = 'datumRodjenja'
    end
  end
  object TKnjige: TADOTable
    Active = True
    Connection = Veza
    CursorType = ctStatic
    OnCalcFields = TKnjigeCalcFields
    IndexFieldNames = 'autorID'
    MasterFields = 'IDAutora'
    MasterSource = DAutori
    TableName = 'knjige'
    Left = 336
    Top = 200
    object TKnjigeIDKnjiga: TAutoIncField
      FieldName = 'IDKnjiga'
      ReadOnly = True
    end
    object TKnjigenaslov: TStringField
      FieldName = 'naslov'
      Size = 50
    end
    object TKnjigeautorID: TIntegerField
      FieldName = 'autorID'
    end
    object TKnjigedostupnost: TBooleanField
      FieldName = 'dostupnost'
    end
    object TKnjigegodinaIzdanja: TIntegerField
      FieldName = 'godinaIzdanja'
    end
    object TKnjigeizdavac: TStringField
      FieldName = 'izdavac'
      Size = 50
    end
    object TKnjigelogo: TBlobField
      FieldName = 'logo'
    end
    object TKnjigeprezimeAutora: TStringField
      FieldKind = fkLookup
      FieldName = 'prezimeAutora'
      LookupDataSet = TAutori
      LookupKeyFields = 'IDAutora'
      LookupResultField = 'prezimeAutora'
      KeyFields = 'autorID'
      Lookup = True
    end
    object TKnjigestarostKnjige: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'starostKnjige'
      Calculated = True
    end
  end
  object TKorisnici: TADOTable
    Active = True
    Connection = Veza
    CursorType = ctStatic
    TableName = 'korisnici'
    Left = 464
    Top = 200
  end
end
