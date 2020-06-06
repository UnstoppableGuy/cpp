object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 402
  ClientWidth = 562
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 400
    Height = 400
  end
  object Label1: TLabel
    Left = 440
    Top = 280
    Width = 56
    Height = 13
    Caption = 'Information'
  end
  object Label2: TLabel
    Left = 406
    Top = 312
    Width = 19
    Height = 13
    Caption = 'Size'
  end
  object Label3: TLabel
    Left = 406
    Top = 336
    Width = 46
    Height = 13
    Caption = 'Perimeter'
  end
  object Label4: TLabel
    Left = 406
    Top = 360
    Width = 73
    Height = 13
    Caption = 'Center of mass'
  end
  object Label5: TLabel
    Left = 499
    Top = 312
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label6: TLabel
    Left = 499
    Top = 336
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label7: TLabel
    Left = 499
    Top = 360
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Button1: TButton
    Left = 424
    Top = 8
    Width = 121
    Height = 32
    Caption = 'Create A Shape'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 57
    Width = 121
    Height = 32
    Caption = 'Move'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 424
    Top = 105
    Width = 121
    Height = 32
    Caption = 'Turn'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 424
    Top = 153
    Width = 121
    Height = 32
    Caption = 'Scale'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
end
