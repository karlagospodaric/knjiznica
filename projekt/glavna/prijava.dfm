object FPrijava: TFPrijava
  Left = 0
  Top = 0
  Caption = 'Prijava'
  ClientHeight = 332
  ClientWidth = 426
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 20
  object Label3: TLabel
    Left = 113
    Top = 224
    Width = 165
    Height = 20
    Caption = 'Nemate korisni'#269'ki ra'#269'un?'
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 385
    Height = 193
    Caption = 'Prijava'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 100
      Height = 20
      Caption = 'Korisni'#269'ko ime:'
    end
    object Label2: TLabel
      Left = 16
      Top = 64
      Width = 53
      Height = 20
      Caption = 'Lozinka:'
    end
    object EKime: TEdit
      Left = 173
      Top = 29
      Width = 185
      Height = 28
      TabOrder = 0
    end
    object ELozinka: TEdit
      Left = 173
      Top = 61
      Width = 185
      Height = 28
      PasswordChar = '*'
      TabOrder = 1
    end
    object Prijava: TButton
      Left = 56
      Top = 113
      Width = 97
      Height = 25
      Caption = 'Prijava'
      TabOrder = 2
      OnClick = PrijavaClick
    end
    object Odustani: TButton
      Left = 200
      Top = 113
      Width = 97
      Height = 25
      Caption = 'Odustani'
      TabOrder = 3
      OnClick = OdustaniClick
    end
    object FastLogin: TCheckBox
      Left = 16
      Top = 90
      Width = 342
      Height = 17
      Caption = 'Zapamti me!'
      TabOrder = 4
    end
  end
  object Registracija: TButton
    Left = 129
    Top = 250
    Width = 133
    Height = 25
    Caption = 'Registracija'
    TabOrder = 1
    OnClick = RegistracijaClick
  end
  object MainMenu1: TMainMenu
    Left = 43
    Top = 170
    object Postavke: TMenuItem
      Caption = 'Postavke'
      object Svjetla: TMenuItem
        Caption = 'Svjetla tema'
        OnClick = SvjetlaClick
      end
      object Tamna: TMenuItem
        Caption = 'Tamna tema'
        OnClick = TamnaClick
      end
      object Default: TMenuItem
        Caption = 'Postavke sustava'
        OnClick = DefaultClick
      end
    end
    object Jezik: TMenuItem
      Caption = 'Jezik'
      object EN: TMenuItem
        Caption = 'EN'
        OnClick = ENClick
      end
      object HR: TMenuItem
        Caption = 'HR'
        OnClick = HRClick
      end
    end
  end
end
