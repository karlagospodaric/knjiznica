object FRegistracija: TFRegistracija
  Left = 0
  Top = 0
  Caption = 'Registracija'
  ClientHeight = 212
  ClientWidth = 509
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 473
    Height = 209
    Caption = 'Podatci:'
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 32
      Width = 32
      Height = 15
      Caption = 'Email:'
    end
    object Label2: TLabel
      Left = 32
      Top = 61
      Width = 81
      Height = 15
      Caption = 'Korisni'#269'ko ime:'
    end
    object Label3: TLabel
      Left = 32
      Top = 90
      Width = 43
      Height = 15
      Caption = 'Lozinka:'
    end
    object Eemail: TEdit
      Left = 176
      Top = 29
      Width = 241
      Height = 23
      TabOrder = 0
      Text = 'example@example.com'
    end
    object Ekime: TEdit
      Left = 176
      Top = 58
      Width = 241
      Height = 23
      TabOrder = 1
    end
    object Elozinka: TEdit
      Left = 176
      Top = 87
      Width = 241
      Height = 23
      PasswordChar = '*'
      TabOrder = 2
    end
    object BRegistracija: TButton
      Left = 80
      Top = 144
      Width = 105
      Height = 25
      Caption = 'Registracija'
      TabOrder = 3
      OnClick = BRegistracijaClick
    end
    object BOdustani: TButton
      Left = 280
      Top = 144
      Width = 107
      Height = 25
      Caption = 'Odustani'
      TabOrder = 4
      OnClick = BOdustaniClick
    end
  end
end
