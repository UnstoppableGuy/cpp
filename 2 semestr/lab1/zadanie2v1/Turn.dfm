object TurnForm: TTurnForm
  Left = 0
  Top = 0
  Caption = 'Turn'
  ClientHeight = 201
  ClientWidth = 200
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 40
    Top = 16
    Width = 121
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowFrame
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'x'
  end
  object Edit2: TEdit
    Left = 40
    Top = 51
    Width = 121
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowFrame
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = 'y'
  end
  object Edit3: TEdit
    Left = 40
    Top = 88
    Width = 121
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowFrame
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = 'angle'
  end
  object Edit4: TEdit
    Left = 40
    Top = 131
    Width = 121
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowFrame
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = 'time'
  end
  object Button1: TButton
    Left = 40
    Top = 159
    Width = 121
    Height = 25
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 0
    OnTimer = Timer2Timer
    Top = 48
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 0
    OnTimer = Timer3Timer
    Top = 96
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer4Timer
    Top = 144
  end
end
