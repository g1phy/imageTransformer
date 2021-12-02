object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1042#1077#1083#1080#1082#1086#1077' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077' '#1084#1072#1075#1080#1095#1077#1089#1082#1080#1093' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081
  ClientHeight = 585
  ClientWidth = 851
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 8
    Top = 200
    Width = 385
    Height = 377
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1077' '#1082#1072#1088#1090#1080#1085#1082#1091
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 348
      Width = 65
      Height = 16
    end
    object Image1: TImage
      Left = 16
      Top = 16
      Width = 353
      Height = 313
    end
  end
  object Settings: TPanel
    Left = 8
    Top = 8
    Width = 385
    Height = 129
    TabOrder = 1
    Visible = False
    object Reflection: TRadioGroup
      Left = 0
      Top = 8
      Width = 185
      Height = 105
      Caption = #1054#1090#1088#1072#1078#1077#1085#1080#1077
      ItemIndex = 0
      Items.Strings = (
        #1041#1077#1079' '#1086#1090#1088#1072#1078#1077#1085#1080#1103
        #1057#1083#1077#1074#1072' - '#1085#1072#1087#1088#1072#1074#1086
        #1057#1074#1077#1088#1093#1091' - '#1074#1085#1080#1079
        #1057#1083#1077#1074#1072' - '#1085#1072#1087#1088#1072#1074#1086', '#1089#1074#1077#1088#1093#1091' - '#1074#1085#1080#1079)
      TabOrder = 0
      OnClick = ReflectionClick
    end
    object ScalesCoeff: TLabeledEdit
      Left = 216
      Top = 88
      Width = 106
      Height = 24
      EditLabel.Width = 155
      EditLabel.Height = 16
      EditLabel.Caption = #1050#1086#1101#1092#1092'. '#1084#1072#1089#1096#1090#1072#1073#1080#1088#1086#1074#1072#1085#1080#1103
      TabOrder = 1
      Text = '1'
    end
    object FilterColor: TComboBox
      Left = 216
      Top = 16
      Width = 154
      Height = 24
      TabOrder = 2
      Text = #1062#1074#1077#1090' '#1092#1080#1083#1100#1090#1088#1072
      OnChange = FilterColorChange
      Items.Strings = (
        #1054#1090#1089#1091#1090#1089#1090#1074#1091#1077#1090
        #1047#1077#1083#1105#1085#1099#1081
        #1043#1086#1083#1091#1073#1086#1081
        #1052#1072#1083#1080#1085#1086#1074#1099#1081
        #1048#1085#1074#1077#1088#1089#1080#1103)
    end
    object setCoeff: TButton
      Left = 328
      Top = 88
      Width = 42
      Height = 25
      Caption = 'SET'
      TabOrder = 3
      OnClick = setCoeffClick
    end
  end
  object Button1: TButton
    Left = 8
    Top = 169
    Width = 169
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1082#1072#1088#1090#1080#1085#1082#1091
    TabOrder = 2
    OnClick = Button1Click
  end
  object ScrollBox1: TScrollBox
    Left = 440
    Top = 8
    Width = 393
    Height = 569
    TabOrder = 3
    object Image2: TImage
      Left = 3
      Top = 3
      Width = 353
      Height = 319
      AutoSize = True
    end
  end
  object Button2: TButton
    Left = 224
    Top = 169
    Width = 169
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1088#1090#1080#1085#1082#1091
    TabOrder = 4
    Visible = False
    OnClick = Button2Click
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 712
    Top = 8
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 776
    Top = 8
  end
end
