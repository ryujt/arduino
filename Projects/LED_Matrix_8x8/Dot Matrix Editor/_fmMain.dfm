object fmMain: TfmMain
  Left = 0
  Top = 0
  Caption = 'Dot Matrix Generator'
  ClientHeight = 562
  ClientWidth = 784
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 784
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      784
      41)
    object btAdd: TButton
      Left = 352
      Top = 11
      Width = 75
      Height = 25
      Caption = 'Add'
      TabOrder = 0
      OnClick = btAddClick
    end
    object btOn: TButton
      Left = 88
      Top = 10
      Width = 75
      Height = 25
      Caption = 'On'
      TabOrder = 1
      OnClick = btOnClick
    end
    object btOff: TButton
      Left = 169
      Top = 10
      Width = 75
      Height = 25
      Caption = 'Off'
      TabOrder = 2
      OnClick = btOffClick
    end
    object btTurnRight: TButton
      Left = 250
      Top = 10
      Width = 75
      Height = 25
      Caption = 'Turn Right'
      TabOrder = 3
      OnClick = btTurnRightClick
    end
    object btPlay: TButton
      Left = 703
      Top = 10
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Play'
      TabOrder = 4
      OnClick = btPlayClick
    end
    object btUpdate: TButton
      Left = 514
      Top = 11
      Width = 75
      Height = 25
      Caption = 'Update'
      TabOrder = 5
      OnClick = btUpdateClick
    end
    object btInsert: TButton
      Left = 433
      Top = 11
      Width = 75
      Height = 25
      Caption = 'Insert'
      TabOrder = 6
      OnClick = btInsertClick
    end
    object btClear: TButton
      Left = 7
      Top = 10
      Width = 75
      Height = 25
      Caption = 'Clear'
      TabOrder = 7
      OnClick = btClearClick
    end
  end
  object plLeft: TPanel
    Left = 0
    Top = 41
    Width = 377
    Height = 521
    Align = alLeft
    BevelOuter = bvNone
    Color = clBlack
    ParentBackground = False
    TabOrder = 1
    object plMatrix: TPanel
      Left = 0
      Top = 0
      Width = 377
      Height = 201
      Align = alTop
      BevelOuter = bvNone
      Color = clGray
      ParentBackground = False
      TabOrder = 0
      object Shape1: TShape
        Left = 14
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape10: TShape
        Left = 36
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape11: TShape
        Left = 58
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape12: TShape
        Left = 80
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape13: TShape
        Left = 102
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape14: TShape
        Left = 124
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape15: TShape
        Left = 146
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape16: TShape
        Left = 168
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape17: TShape
        Left = 14
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape18: TShape
        Left = 36
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape19: TShape
        Left = 58
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape2: TShape
        Left = 36
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape20: TShape
        Left = 80
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape21: TShape
        Left = 102
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape22: TShape
        Left = 124
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape23: TShape
        Left = 146
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape24: TShape
        Left = 168
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape25: TShape
        Left = 36
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape26: TShape
        Left = 58
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape27: TShape
        Left = 80
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape28: TShape
        Left = 102
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape29: TShape
        Left = 124
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape3: TShape
        Left = 58
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape30: TShape
        Left = 146
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape31: TShape
        Left = 168
        Top = 60
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape32: TShape
        Left = 14
        Top = 82
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape33: TShape
        Left = 14
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape34: TShape
        Left = 36
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape35: TShape
        Left = 58
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape36: TShape
        Left = 80
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape37: TShape
        Left = 102
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape38: TShape
        Left = 124
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape39: TShape
        Left = 146
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape4: TShape
        Left = 80
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape40: TShape
        Left = 168
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape41: TShape
        Left = 14
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape42: TShape
        Left = 36
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape43: TShape
        Left = 58
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape44: TShape
        Left = 36
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape45: TShape
        Left = 80
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape46: TShape
        Left = 102
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape47: TShape
        Left = 124
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape48: TShape
        Left = 146
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape49: TShape
        Left = 168
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape5: TShape
        Left = 102
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape50: TShape
        Left = 36
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape51: TShape
        Left = 58
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape52: TShape
        Left = 80
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape53: TShape
        Left = 102
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape54: TShape
        Left = 124
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape55: TShape
        Left = 58
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape56: TShape
        Left = 146
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape57: TShape
        Left = 168
        Top = 148
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape58: TShape
        Left = 14
        Top = 170
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape59: TShape
        Left = 80
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape6: TShape
        Left = 124
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape60: TShape
        Left = 102
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape61: TShape
        Left = 124
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape62: TShape
        Left = 146
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape63: TShape
        Left = 168
        Top = 104
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape64: TShape
        Left = 14
        Top = 126
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape7: TShape
        Left = 146
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape8: TShape
        Left = 168
        Top = 16
        Width = 16
        Height = 16
        Shape = stCircle
      end
      object Shape9: TShape
        Left = 14
        Top = 38
        Width = 16
        Height = 16
        Shape = stCircle
      end
    end
    object ListBox: TListBox
      Left = 0
      Top = 201
      Width = 377
      Height = 320
      Align = alClient
      ImeName = 'Microsoft IME 2010'
      ItemHeight = 13
      PopupMenu = PopupMenu
      TabOrder = 1
      OnDblClick = ListBoxDblClick
    end
  end
  object moLines: TMemo
    Left = 377
    Top = 41
    Width = 407
    Height = 521
    Align = alClient
    ImeName = 'Microsoft IME 2010'
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object MainMenu: TMainMenu
    AutoHotkeys = maManual
    Left = 180
    Top = 304
    object File1: TMenuItem
      Caption = 'File'
      object miOpen: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
        OnClick = miOpenClick
      end
      object miSave: TMenuItem
        Caption = 'Save'
        ShortCut = 16467
        OnClick = miSaveClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object miExit: TMenuItem
        Caption = 'Exit'
        OnClick = miExitClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = 'Text File(s)|*.txt|All File(s)|*.*'
    Left = 496
    Top = 216
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text File(s)|*.txt|All File(s)|*.*'
    Left = 568
    Top = 216
  end
  object PopupMenu: TPopupMenu
    AutoHotkeys = maManual
    Left = 100
    Top = 304
    object miDelete: TMenuItem
      Caption = 'Delete'
      OnClick = miDeleteClick
    end
    object miInsert: TMenuItem
      Caption = 'Insert'
      OnClick = miInsertClick
    end
    object miUpdate: TMenuItem
      Caption = 'Update'
      OnClick = miUpdateClick
    end
  end
  object Timer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = TimerTimer
    Left = 388
    Top = 296
  end
end
