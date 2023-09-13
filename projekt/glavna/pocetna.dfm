object FPocetna: TFPocetna
  Left = 0
  Top = 0
  Caption = 'Po'#269'etna'
  ClientHeight = 152
  ClientWidth = 498
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 177
    Height = 149
    Caption = 'Korisni'#269'ki ra'#269'un'
    TabOrder = 0
    object Uredi: TButton
      Left = 16
      Top = 64
      Width = 133
      Height = 25
      Caption = 'Uredi profil'
      TabOrder = 0
      OnClick = UrediClick
    end
    object Obrisi: TButton
      Left = 16
      Top = 95
      Width = 133
      Height = 25
      Caption = 'Obri'#353'i profil'
      TabOrder = 1
      OnClick = ObrisiClick
    end
    object Odjava: TButton
      Left = 16
      Top = 33
      Width = 133
      Height = 25
      Caption = 'Odjava'
      ModalResult = 2
      TabOrder = 2
      OnClick = OdjavaClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 208
    Top = 8
    Width = 289
    Height = 149
    Caption = 'Knji'#382'nica'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 33
      Width = 69
      Height = 15
      Caption = 'Popis autora:'
    end
    object Label2: TLabel
      Left = 16
      Top = 68
      Width = 83
      Height = 15
      Caption = 'Sve o knjigama:'
    end
    object Label3: TLabel
      Left = 16
      Top = 99
      Width = 92
      Height = 15
      Caption = 'Dodajte izdava'#269'a:'
    end
    object Button1: TButton
      Left = 124
      Top = 29
      Width = 133
      Height = 25
      Caption = 'Autori'
      TabOrder = 0
      OnClick = AutoriClick
    end
    object Button2: TButton
      Left = 124
      Top = 64
      Width = 133
      Height = 25
      Caption = 'Knjige'
      TabOrder = 1
      OnClick = KnjigeClick
    end
    object Button3: TButton
      Left = 124
      Top = 95
      Width = 133
      Height = 25
      Caption = 'Izdava'#269'i'
      TabOrder = 2
      OnClick = IzdavacClick
    end
  end
end
