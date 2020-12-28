object Form1: TForm1
  Left = -158
  Top = 249
  Width = 632
  Height = 487
  Caption = #1043#1088#1072#1092#1080#1095#1077#1089#1082#1080#1077' '#1087#1088#1080#1084#1080#1090#1080#1074#1099
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pbx: TPaintBox
    Left = 40
    Top = 8
    Width = 425
    Height = 425
    Color = clWhite
    ParentColor = False
  end
  object Label1: TLabel
    Left = 552
    Top = 64
    Width = 39
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072
  end
  object Label2: TLabel
    Left = 552
    Top = 104
    Width = 38
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072
  end
  object Button1: TButton
    Left = 480
    Top = 136
    Width = 75
    Height = 25
    Caption = #1057#1090#1072#1088#1090
    TabOrder = 0
    OnClick = Button1Click
  end
  object DayNight: TButton
    Left = 480
    Top = 168
    Width = 75
    Height = 25
    Caption = 'DayNight'
    TabOrder = 1
    OnClick = DayNightClick
  end
  object XX: TEdit
    Left = 480
    Top = 64
    Width = 65
    Height = 21
    TabOrder = 2
    Text = '0'
  end
  object YY: TEdit
    Left = 480
    Top = 104
    Width = 65
    Height = 21
    TabOrder = 3
    Text = '0'
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 480
    Top = 24
  end
end
