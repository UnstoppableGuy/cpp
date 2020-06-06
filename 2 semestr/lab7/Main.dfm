object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1101#1083#1077#1084#1077#1085#1090#1086#1074'  '#1074' '#1082#1072#1078#1078#1086#1084' '#1089#1090#1077#1082#1077
  ClientHeight = 322
  ClientWidth = 966
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 327
    Top = 6
    Width = 631
    Height = 313
    TabOrder = 0
  end
  object Button2: TButton
    Left = 24
    Top = 16
    Width = 97
    Height = 25
    Caption = 'Amount'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 140
    Width = 97
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    TextHint = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
  end
  object Button3: TButton
    Left = 24
    Top = 47
    Width = 97
    Height = 25
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 24
    Top = 167
    Width = 97
    Height = 21
    NumbersOnly = True
    TabOrder = 4
    TextHint = #1054#1073#1083#1072#1089#1090#1100
  end
  object Button4: TButton
    Left = 24
    Top = 78
    Width = 97
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Memo2: TMemo
    Left = 136
    Top = 6
    Width = 185
    Height = 313
    Lines.Strings = (
      '')
    TabOrder = 6
  end
end
