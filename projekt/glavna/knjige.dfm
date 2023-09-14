object FKnjige: TFKnjige
  Left = 0
  Top = 0
  Caption = 'Popis knjiga'
  ClientHeight = 594
  ClientWidth = 605
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label8: TLabel
    Left = 440
    Top = 207
    Width = 78
    Height = 15
    Caption = 'Logo izdava'#269'a:'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 585
    Height = 193
    DataSource = data.DKnjige
    Options = [dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    Columns = <
      item
        Expanded = False
        FieldName = 'naslov'
        Width = 153
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'prezimeAutora'
        Width = 89
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'izdavac'
        Width = 85
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'godinaIzdanja'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'starostKnjige'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'dostupnost'
        Visible = True
      end>
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 207
    Width = 409
    Height = 330
    Caption = 'Podatci o knjizi'
    TabOrder = 1
    object Label4: TLabel
      Left = 16
      Top = 32
      Width = 39
      Height = 15
      Caption = 'Naslov:'
    end
    object Label5: TLabel
      Left = 16
      Top = 61
      Width = 33
      Height = 15
      Caption = 'Autor:'
    end
    object Label1: TLabel
      Left = 16
      Top = 96
      Width = 81
      Height = 15
      Caption = 'Godina izdanja:'
    end
    object Label2: TLabel
      Left = 16
      Top = 124
      Width = 42
      Height = 15
      Caption = 'Izdava'#269':'
    end
    object Image1: TImage
      Left = 16
      Top = 169
      Width = 105
      Height = 105
      OnClick = Image1Click
    end
    object Image2: TImage
      Left = 127
      Top = 169
      Width = 105
      Height = 105
      OnClick = Image2Click
    end
    object Image3: TImage
      Left = 238
      Top = 169
      Width = 105
      Height = 105
      OnClick = Image3Click
    end
    object Label9: TLabel
      Left = 16
      Top = 148
      Width = 130
      Height = 15
      Caption = 'Odaberite logo izdava'#269'a:'
    end
    object ENaslov: TEdit
      Left = 112
      Top = 29
      Width = 231
      Height = 23
      TabOrder = 0
    end
    object BDodaj: TButton
      Left = 16
      Top = 288
      Width = 81
      Height = 25
      Caption = 'Dodaj'
      TabOrder = 1
      OnClick = BDodajClick
    end
    object BOdustani: TButton
      Left = 312
      Top = 288
      Width = 73
      Height = 25
      Caption = 'Odustani'
      ModalResult = 8
      TabOrder = 2
      OnClick = BOdustaniClick
    end
    object EGodina: TEdit
      Left = 112
      Top = 87
      Width = 231
      Height = 23
      NumbersOnly = True
      TabOrder = 3
    end
    object CBIzdavaci: TComboBox
      Left = 112
      Top = 116
      Width = 231
      Height = 23
      Style = csDropDownList
      TabOrder = 4
    end
    object CBAutori: TComboBox
      Left = 112
      Top = 58
      Width = 231
      Height = 23
      Style = csDropDownList
      TabOrder = 5
    end
    object BUredi: TButton
      Left = 120
      Top = 288
      Width = 75
      Height = 25
      Caption = 'Uredi'
      Enabled = False
      TabOrder = 6
      OnClick = BUrediClick
    end
    object BObrisi: TButton
      Left = 216
      Top = 288
      Width = 75
      Height = 25
      Caption = 'Obri'#353'i'
      Enabled = False
      TabOrder = 7
      OnClick = BObrisiClick
    end
  end
  object BPosudi: TButton
    Left = 439
    Top = 343
    Width = 107
    Height = 25
    Caption = 'Posudi knjigu'
    TabOrder = 2
    OnClick = BPosudiClick
  end
  object BFilter: TButton
    Left = 440
    Top = 407
    Width = 107
    Height = 25
    Caption = 'Dostupne knjige'
    TabOrder = 3
    OnClick = BFilterClick
  end
  object BVrati: TButton
    Left = 440
    Top = 376
    Width = 107
    Height = 25
    Caption = 'Vrati knjigu'
    TabOrder = 4
    OnClick = BVratiClick
  end
  object slika: TDBImage
    Left = 440
    Top = 228
    Width = 114
    Height = 105
    DataField = 'logo'
    DataSource = data.DKnjige
    TabOrder = 5
  end
end
