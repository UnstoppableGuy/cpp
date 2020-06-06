object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100' '#1095#1080#1089#1083#1086' '#1074' '#1076#1077#1088#1077#1074#1077' '#1091#1079#1083#1086#1074' '#1091' '#1082#1086#1090#1086#1088#1099#1093' '#1077#1089#1090#1100' 2 '#1076#1086#1095#1077#1088#1085#1080#1077
  ClientHeight = 434
  ClientWidth = 908
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 24
    Top = 16
    Width = 281
    Height = 377
    Indent = 19
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 576
    Top = 16
    Width = 329
    Height = 377
    ColCount = 2
    DefaultColWidth = 150
    FixedCols = 0
    RowCount = 15
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing, goAlwaysShowEditor, goThumbTracking]
    TabOrder = 0
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Memo1: TMemo
    Left = 311
    Top = 16
    Width = 259
    Height = 377
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 121
    Top = 399
    Width = 74
    Height = 21
    TabOrder = 3
    TextHint = #1047#1072#1076#1072#1085#1080#1077
  end
  object Button9: TButton
    Left = 24
    Top = 399
    Width = 75
    Height = 25
    Caption = 'Menu'
    TabOrder = 4
    OnClick = Button9Click
  end
end
