object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Lab4'
  ClientHeight = 411
  ClientWidth = 729
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 144
    Top = 24
    Width = 47
    Height = 16
    Caption = 'Formula'
  end
  object Label2: TLabel
    Left = 152
    Top = 97
    Width = 39
    Height = 16
    Caption = 'input a'
  end
  object Label3: TLabel
    Left = 152
    Top = 135
    Width = 39
    Height = 16
    Caption = 'input b'
  end
  object Label4: TLabel
    Left = 152
    Top = 181
    Width = 38
    Height = 16
    Caption = 'input c'
  end
  object Label5: TLabel
    Left = 152
    Top = 227
    Width = 39
    Height = 16
    Caption = 'input d'
  end
  object Label6: TLabel
    Left = 152
    Top = 267
    Width = 39
    Height = 16
    Caption = 'input e'
  end
  object Label7: TLabel
    Left = 397
    Top = 24
    Width = 47
    Height = 16
    Caption = 'Formula'
  end
  object Label8: TLabel
    Left = 456
    Top = 208
    Width = 35
    Height = 16
    Caption = 'Result'
  end
  object Edit1: TEdit
    Left = 232
    Top = 24
    Width = 121
    Height = 24
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 232
    Top = 94
    Width = 121
    Height = 24
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 232
    Top = 132
    Width = 121
    Height = 24
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 232
    Top = 178
    Width = 121
    Height = 24
    TabOrder = 3
  end
  object Edit5: TEdit
    Left = 232
    Top = 224
    Width = 121
    Height = 24
    TabOrder = 4
  end
  object Edit6: TEdit
    Left = 232
    Top = 264
    Width = 121
    Height = 24
    TabOrder = 5
  end
  object Button1: TButton
    Left = 488
    Top = 280
    Width = 75
    Height = 25
    Caption = 'GO'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 450
    Top = 8
    Width = 185
    Height = 41
    Caption = 'result'
    Color = clAqua
    ParentBackground = False
    TabOrder = 7
  end
  object Panel2: TPanel
    Left = 512
    Top = 196
    Width = 185
    Height = 41
    Caption = 'result'
    Color = clAqua
    ParentBackground = False
    TabOrder = 8
  end
end