object FAutori: TFAutori
  Left = 0
  Top = 0
  Caption = 'Popis autora'
  ClientHeight = 261
  ClientWidth = 619
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object DBAutori: TDBGrid
    Left = 8
    Top = 8
    Width = 612
    Height = 185
    DataSource = data.DAutori
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'imeAutora'
        Width = 154
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'prezimeAutora'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'datumRodjenja'
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 199
    Width = 610
    Height = 25
    DataSource = data.DAutori
    TabOrder = 1
  end
  object BReport: TButton
    Left = 8
    Top = 230
    Width = 129
    Height = 25
    Caption = 'Izvje'#353'taj'
    TabOrder = 2
    OnClick = BReportClick
  end
  object izvjestaj: TfrxReport
    Version = '2022.2.7'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 45159.403090648100000000
    ReportOptions.LastChange = 45159.403090648100000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 272
    Top = 104
    Datasets = <
      item
        DataSet = frxAutori
        DataSetName = 'frxAutori'
      end
      item
        DataSet = frxKnjige
        DataSetName = 'frxKnjige'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 215.900000000000000000
      PaperHeight = 279.400000000000000000
      PaperSize = 1
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 18.897650000000000000
        Width = 740.409927000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 8.000000000000000000
          Top = 0.102350000000000000
          Width = 722.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Knjige odabranog autora')
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 102.047310000000000000
        Width = 740.409927000000000000
        DataSet = frxAutori
        DataSetName = 'frxAutori'
        RowCount = 0
        object frxAutoriimeAutora: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 13.369820000000000000
          Top = 0.952690000000000000
          Width = 83.630180000000000000
          Height = 18.897650000000000000
          DataField = 'imeAutora'
          DataSet = frxAutori
          DataSetName = 'frxAutori'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxAutori."imeAutora"]')
        end
        object frxAutoriprezimeAutora: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 101.000000000000000000
          Top = -2.047310000000000000
          Width = 161.630180000000000000
          Height = 18.897650000000000000
          DataField = 'prezimeAutora'
          DataSet = frxAutori
          DataSetName = 'frxAutori'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxAutori."prezimeAutora"]')
        end
        object frxAutoridatumRodjenja: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 593.000000000000000000
          Top = 0.952690000000000000
          Width = 143.622140000000000000
          Height = 18.897650000000000000
          DataField = 'datumRodjenja'
          DataSet = frxAutori
          DataSetName = 'frxAutori'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxAutori."datumRodjenja"]')
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Left = -48.000000000000000000
          Top = -0.047310000000000000
          Width = 745.000000000000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 27.495980000000000000
        Top = 147.401670000000000000
        Width = 740.409927000000000000
        DataSet = frxKnjige
        DataSetName = 'frxKnjige'
        RowCount = 0
        object frxKnjigenaslov: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 45.000000000000000000
          Top = 0.598330000000000000
          Width = 188.630180000000000000
          Height = 18.897650000000000000
          DataField = 'naslov'
          DataSet = frxKnjige
          DataSetName = 'frxKnjige'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxKnjige."naslov"]')
        end
        object frxKnjigeizdavac: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 240.000000000000000000
          Top = 0.598330000000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          DataField = 'izdavac'
          DataSet = frxKnjige
          DataSetName = 'frxKnjige'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxKnjige."izdavac"]')
        end
        object frxKnjigegodinaIzdanja: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 410.000000000000000000
          Top = 2.598330000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataField = 'godinaIzdanja'
          DataSet = frxKnjige
          DataSetName = 'frxKnjige'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxKnjige."godinaIzdanja"]')
        end
      end
    end
  end
  object frxAutori: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'frxAutori'
    CloseDataSource = False
    DataSet = data.TAutori
    BCDToCurrency = False
    DataSetOptions = []
    Left = 368
    Top = 104
  end
  object frxKnjige: TfrxDBDataset
    UserName = 'frxKnjige'
    CloseDataSource = False
    DataSet = data.TKnjige
    BCDToCurrency = False
    DataSetOptions = []
    Left = 470
    Top = 106
  end
  object frxPDF: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 48
    Top = 104
  end
  object frxRTF: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    OpenAfterExport = False
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 168
    Top = 104
  end
end
