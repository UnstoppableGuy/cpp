object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Painter'
  ClientHeight = 456
  ClientWidth = 697
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 14
  object Label1: TLabel
    Left = 529
    Top = 188
    Width = 138
    Height = 14
    Caption = 'Enter the angle, degrees'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 540
    Top = 285
    Width = 70
    Height = 13
    Caption = 'Area, Pixel^2:'
  end
  object Label3: TLabel
    Left = 540
    Top = 349
    Width = 79
    Height = 13
    Caption = 'Perimeter, Pixel:'
  end
  object Button1: TButton
    Left = 565
    Top = 238
    Width = 75
    Height = 25
    Caption = 'Rotate'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 565
    Top = 208
    Width = 75
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 540
    Top = 24
    Width = 127
    Height = 137
    Caption = 'Choose the shape:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object RadioButton1: TRadioButton
      Left = 16
      Top = 22
      Width = 113
      Height = 17
      Caption = 'Rectangle'
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 45
      Width = 113
      Height = 17
      Caption = 'Ellipse'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 68
      Width = 113
      Height = 17
      Caption = 'Circle'
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 16
      Top = 91
      Width = 113
      Height = 17
      Caption = 'Triangle'
      TabOrder = 3
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 16
      Top = 114
      Width = 113
      Height = 17
      Caption = 'Hexagon'
      TabOrder = 4
      OnClick = RadioButton5Click
    end
  end
  object Panel1: TPanel
    Left = 537
    Top = 304
    Width = 130
    Height = 33
    TabOrder = 3
  end
  object Panel2: TPanel
    Left = 539
    Top = 368
    Width = 130
    Height = 25
    TabOrder = 4
  end
  object Button2: TButton
    Left = 556
    Top = 399
    Width = 93
    Height = 42
    Caption = 'Calculate'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 16
    OnTimer = Timer1Timer
    Left = 504
    Top = 16
  end
end
