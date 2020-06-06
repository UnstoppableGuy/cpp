object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'lab2'
  ClientHeight = 476
  ClientWidth = 772
  Color = clYellow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Name: TLabel
    Left = 73
    Top = 42
    Width = 68
    Height = 28
    Caption = 'Name'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Surname: TLabel
    Left = 36
    Top = 8
    Width = 105
    Height = 28
    Caption = 'Surname'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Math: TLabel
    Left = 81
    Top = 139
    Width = 60
    Height = 28
    Caption = 'Math'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Physics: TLabel
    Left = 55
    Top = 185
    Width = 86
    Height = 28
    Caption = 'Physics'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Patronymic: TLabel
    Left = 9
    Top = 71
    Width = 132
    Height = 28
    Caption = 'Patronymic'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object RussianLanguage: TLabel
    Left = 55
    Top = 221
    Width = 84
    Height = 28
    Caption = 'English'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Specialty: TLabel
    Left = 57
    Top = 105
    Width = 84
    Height = 28
    Caption = 'Faculty'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Certificate: TLabel
    Left = 19
    Top = 255
    Width = 122
    Height = 28
    Caption = 'Certificate'
    Font.Charset = ANSI_CHARSET
    Font.Color = clDefault
    Font.Height = -23
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Press: TButton
    Left = 460
    Top = 325
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 0
    OnClick = PressClick
  end
  object Mem: TMemo
    Left = 304
    Top = 8
    Width = 445
    Height = 297
    Color = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'Mem')
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    Visible = False
  end
  object Button1: TButton
    Left = 569
    Top = 325
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 2
    Visible = False
    OnClick = Button1Click
  end
  object Sort: TButton
    Left = 674
    Top = 325
    Width = 75
    Height = 25
    Caption = 'Sort'
    TabOrder = 3
    Visible = False
    OnClick = SortClick
  end
  object Edit2: TEdit
    Left = 147
    Top = 17
    Width = 121
    Height = 21
    TabOrder = 4
    Visible = False
  end
  object Edit3: TEdit
    Left = 147
    Top = 44
    Width = 121
    Height = 21
    TabOrder = 5
    Visible = False
  end
  object Edit4: TEdit
    Left = 147
    Top = 71
    Width = 121
    Height = 21
    TabOrder = 6
    Visible = False
  end
  object Edit5: TEdit
    Left = 147
    Top = 147
    Width = 121
    Height = 21
    TabOrder = 7
    Visible = False
  end
  object Edit6: TEdit
    Left = 147
    Top = 187
    Width = 121
    Height = 21
    TabOrder = 8
    Visible = False
  end
  object Edit7: TEdit
    Left = 147
    Top = 228
    Width = 121
    Height = 21
    TabOrder = 9
    Visible = False
  end
  object Edit8: TEdit
    Left = 147
    Top = 107
    Width = 121
    Height = 21
    TabOrder = 10
    Visible = False
  end
  object Edit9: TEdit
    Left = 147
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 11
    Visible = False
  end
  object JustDoIt: TButton
    Left = 72
    Top = 298
    Width = 75
    Height = 25
    Caption = 'Apply'
    TabOrder = 12
    Visible = False
    OnClick = JustDoItClick
  end
  object WhatToDo: TRadioGroup
    Left = 160
    Top = 348
    Width = 125
    Height = 99
    Caption = 'Menu'
    Color = clLime
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Orientation = 1
    Font.Style = [fsItalic]
    Items.Strings = (
      'Search'
      'Add'
      'Delete')
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    TabOrder = 13
    Visible = False
    OnClick = WhatToDoClick
  end
  object ComboBox1: TComboBox
    Left = 321
    Top = 327
    Width = 125
    Height = 29
    Color = clMedGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
    Text = 'Faculties'
    Visible = False
    OnChange = ComboBox1Change
    Items.Strings = (
      'All'
      'FKSiS'
      'FKP'
      'IEF'
      'FITY'
      'FIK')
  end
  object OpenDialog1: TOpenDialog
    Left = 720
    Top = 432
  end
  object SaveDialog1: TSaveDialog
    Left = 680
    Top = 432
  end
end
