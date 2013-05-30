; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dijshow.h"
LastPage=0

ClassCount=7
Class1=CDijshowApp
Class2=CDijshowDoc
Class3=CDijshowView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CSetNumDlg
Resource3=IDD_SETNUMDLG
Class7=CSetWeightDlg
Resource4=IDD_SETWEIGHTDLG

[CLS:CDijshowApp]
Type=0
HeaderFile=dijshow.h
ImplementationFile=dijshow.cpp
Filter=N

[CLS:CDijshowDoc]
Type=0
HeaderFile=dijshowDoc.h
ImplementationFile=dijshowDoc.cpp
Filter=N
LastObject=CDijshowDoc

[CLS:CDijshowView]
Type=0
HeaderFile=dijshowView.h
ImplementationFile=dijshowView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDijshowView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=dijshow.cpp
ImplementationFile=dijshow.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_BEGIN
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_BEGIN
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_NODETOOL
Command10=ID_PATHTOOL
Command11=ID_MOVENODE
Command12=ID_BEGINSEARCH
Command13=ID_EXSTEP
Command14=ID_BUTTON32777
CommandCount=14

[DLG:IDD_SETNUMDLG]
Type=1
Class=CSetNumDlg
ControlCount=5
Control1=IDC_ENTERNUM,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287

[CLS:CSetNumDlg]
Type=0
HeaderFile=SetNumDlg.h
ImplementationFile=SetNumDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetNumDlg
VirtualFilter=dWC

[DLG:IDD_SETWEIGHTDLG]
Type=1
Class=CSetWeightDlg
ControlCount=5
Control1=IDC_SETWEIGHT,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287

[CLS:CSetWeightDlg]
Type=0
HeaderFile=SetWeightDlg.h
ImplementationFile=SetWeightDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_BEGIN
VirtualFilter=dWC

