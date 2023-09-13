object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Izdava'#269'i'
  ClientHeight = 226
  ClientWidth = 388
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object GroupBox2: TGroupBox
    Left = 16
    Top = 16
    Width = 353
    Height = 193
    Caption = 'Izdava'#269':'
    TabOrder = 0
    object Label4: TLabel
      Left = 16
      Top = 32
      Width = 26
      Height = 15
      Caption = #352'ifra:'
    end
    object Label5: TLabel
      Left = 16
      Top = 61
      Width = 65
      Height = 15
      Caption = 'Naziv tvrtke:'
    end
    object Label6: TLabel
      Left = 16
      Top = 93
      Width = 38
      Height = 15
      Caption = 'Dr'#382'ava:'
    end
    object ESifra: TEdit
      Left = 112
      Top = 29
      Width = 225
      Height = 23
      TabOrder = 0
    end
    object ENaziv: TEdit
      Left = 112
      Top = 58
      Width = 225
      Height = 23
      TabOrder = 1
    end
    object BDodaj: TButton
      Left = 40
      Top = 136
      Width = 113
      Height = 25
      Caption = 'Dodaj'
      ModalResult = 1
      TabOrder = 2
      OnClick = BDodajClick
    end
    object BOdustani: TButton
      Left = 224
      Top = 136
      Width = 99
      Height = 25
      Caption = 'Odustani'
      ModalResult = 8
      TabOrder = 3
      OnClick = BOdustaniClick
    end
    object CBDrzava: TComboBox
      Left = 112
      Top = 90
      Width = 225
      Height = 23
      Style = csDropDownList
      TabOrder = 4
    end
  end
end
