/***************************************************************
 * Name:      BaseHD_example_GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2018-07-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "BaseHD_example_GUIMain.h"
#include <wx/msgdlg.h>
#include "lib/include/ais_readers.h"
#include "lib/include/ais_readers_list.h"
#include "lib/include/dl_status.h"
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <time.h>
//(*InternalHeaders(BaseHD_example_GUIFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

using namespace std;

int RTE_STOP = 0;
HND_AIS handle[11];
int device_count;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(BaseHD_example_GUIFrame)
const long BaseHD_example_GUIFrame::ID_BUTTON1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE5 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT5 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON5 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT6 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON17 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT7 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_RADIOBUTTON1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_RADIOBUTTON2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT8 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL5 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT25 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL22 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON6 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT9 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL6 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT10 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL7 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON7 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT11 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON8 = wxNewId();
const long BaseHD_example_GUIFrame::ID_CHOICE6 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON9 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL8 = wxNewId();
const long BaseHD_example_GUIFrame::ID_PANEL1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_GRID1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT12 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL9 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT13 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL10 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT14 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_DATEPICKERCTRL1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT15 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL5 = wxNewId();
const long BaseHD_example_GUIFrame::ID_SPINCTRL6 = wxNewId();
const long BaseHD_example_GUIFrame::ID_DATEPICKERCTRL2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT16 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL13 = wxNewId();
const long BaseHD_example_GUIFrame::ID_GAUGE1 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON10 = wxNewId();
const long BaseHD_example_GUIFrame::ID_PANEL2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT17 = wxNewId();
const long BaseHD_example_GUIFrame::ID_GRID2 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON11 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON12 = wxNewId();
const long BaseHD_example_GUIFrame::ID_PANEL3 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT19 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL14 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT20 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL15 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON13 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT21 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL16 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL17 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON14 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT22 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL18 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT23 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL19 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON15 = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATICTEXT24 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL20 = wxNewId();
const long BaseHD_example_GUIFrame::ID_TEXTCTRL21 = wxNewId();
const long BaseHD_example_GUIFrame::ID_BUTTON16 = wxNewId();
const long BaseHD_example_GUIFrame::ID_PANEL4 = wxNewId();
const long BaseHD_example_GUIFrame::ID_NOTEBOOK1 = wxNewId();
const long BaseHD_example_GUIFrame::idMenuQuit = wxNewId();
const long BaseHD_example_GUIFrame::idMenuAbout = wxNewId();
const long BaseHD_example_GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BaseHD_example_GUIFrame,wxFrame)
    //(*EventTable(BaseHD_example_GUIFrame)
    //*)
END_EVENT_TABLE()

BaseHD_example_GUIFrame::BaseHD_example_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(BaseHD_example_GUIFrame)
    wxBoxSizer* BoxSizer1;
    wxGridSizer* GridSizer10;
    wxGridSizer* GridSizer11;
    wxGridSizer* GridSizer12;
    wxGridSizer* GridSizer13;
    wxGridSizer* GridSizer14;
    wxGridSizer* GridSizer15;
    wxGridSizer* GridSizer16;
    wxGridSizer* GridSizer17;
    wxGridSizer* GridSizer18;
    wxGridSizer* GridSizer19;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer20;
    wxGridSizer* GridSizer21;
    wxGridSizer* GridSizer22;
    wxGridSizer* GridSizer23;
    wxGridSizer* GridSizer24;
    wxGridSizer* GridSizer25;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxGridSizer* GridSizer4;
    wxGridSizer* GridSizer5;
    wxGridSizer* GridSizer6;
    wxGridSizer* GridSizer7;
    wxGridSizer* GridSizer8;
    wxGridSizer* GridSizer9;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxStaticBoxSizer* StaticBoxSizer12;
    wxStaticBoxSizer* StaticBoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer15;
    wxStaticBoxSizer* StaticBoxSizer16;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer9;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1 = new wxGridSizer(2, 1, -500, 0);
    GridSizer2 = new wxGridSizer(1, 3, 0, -25);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    bConnect = new wxButton(this, ID_BUTTON1, _("Connect to reader"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(bConnect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bDisconnect = new wxButton(this, ID_BUTTON2, _("Disconnect"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(bDisconnect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    DeviceID_Choice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    DeviceID_Choice->Append(_("0"));
    DeviceID_Choice->Append(_("1"));
    DeviceID_Choice->Append(_("2"));
    DeviceID_Choice->Append(_("3"));
    DeviceID_Choice->Append(_("4"));
    DeviceID_Choice->Append(_("5"));
    DeviceID_Choice->Append(_("6"));
    DeviceID_Choice->Append(_("7"));
    DeviceID_Choice->Append(_("8"));
    DeviceID_Choice->Append(_("9"));
    DeviceID_Choice->Append(_("10"));
    StaticBoxSizer2->Add(DeviceID_Choice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bAddDevice = new wxButton(this, ID_BUTTON3, _("Add device"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer2->Add(bAddDevice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    StatusLabel = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(117,21), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer3->Add(StatusLabel, 1, wxALL|wxEXPAND, 5);
    GridSizer2->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    GridSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridSizer3 = new wxGridSizer(3, 2, 250, -450);
    GridSizer4 = new wxGridSizer(1, 1, 0, 0);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Lights"));
    GridSizer5 = new wxGridSizer(5, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Green master"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer5->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GreenMaster_CH = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(50,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    GreenMaster_CH->Append(_("OFF"));
    GreenMaster_CH->Append(_("ON"));
    GridSizer5->Add(GreenMaster_CH, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Red master"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer5->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    RedMaster_CH = new wxChoice(Panel1, ID_CHOICE3, wxDefaultPosition, wxSize(50,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    RedMaster_CH->Append(_("OFF"));
    RedMaster_CH->Append(_("ON"));
    GridSizer5->Add(RedMaster_CH, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Green slave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridSizer5->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GreenSlave_CH = new wxChoice(Panel1, ID_CHOICE4, wxDefaultPosition, wxSize(50,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    GreenSlave_CH->Append(_("OFF"));
    GreenSlave_CH->Append(_("ON"));
    GridSizer5->Add(GreenSlave_CH, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Red slave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridSizer5->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    RedSlave_CH = new wxChoice(Panel1, ID_CHOICE5, wxDefaultPosition, wxSize(50,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    RedSlave_CH->Append(_("OFF"));
    RedSlave_CH->Append(_("ON"));
    GridSizer5->Add(RedSlave_CH, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bSetLight = new wxButton(Panel1, ID_BUTTON4, _("SET"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GridSizer5->Add(bSetLight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(GridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer4->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer3->Add(GridSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer6 = new wxGridSizer(1, 1, 0, 0);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Time"));
    GridSizer7 = new wxGridSizer(7, 3, 0, -40);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Current time :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridSizer7->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CurrentTime_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(170,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridSizer7->Add(CurrentTime_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bGetTime = new wxButton(Panel1, ID_BUTTON5, _("GET"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GridSizer7->Add(bGetTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Time to set :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer7->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TimeToSet_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(170,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    GridSizer7->Add(TimeToSet_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    bGetTimeFromPC = new wxButton(Panel1, ID_BUTTON17, _("Get from PC"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    GridSizer7->Add(bGetTimeFromPC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Timezone : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer7->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Timezone_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(170,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    GridSizer7->Add(Timezone_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Use_DST = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Use Daylight Saving Time"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    GridSizer7->Add(Use_DST, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Dontuse_DST = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Don\'t use Daylight Saving Time"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    GridSizer7->Add(Dontuse_DST, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Offset : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridSizer7->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Offset_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(170,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    GridSizer7->Add(Offset_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(Panel1, ID_STATICTEXT25, _("Password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    GridSizer7->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Password_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL22, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    GridSizer7->Add(Password_Label, 1, wxALL|wxEXPAND, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bSetTime = new wxButton(Panel1, ID_BUTTON6, _("SET"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GridSizer7->Add(bSetTime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(GridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer6->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer3->Add(GridSizer6, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer8 = new wxGridSizer(1, 2, 0, 0);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Password"));
    GridSizer9 = new wxGridSizer(3, 2, 0, -100);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Old password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridSizer9->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    OldPassword_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    GridSizer9->Add(OldPassword_Label, 1, wxALL|wxEXPAND, 5);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("New password :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    GridSizer9->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    NewPassword_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    GridSizer9->Add(NewPassword_Label, 1, wxALL|wxEXPAND, 5);
    bChangePass = new wxButton(Panel1, ID_BUTTON7, _("Change password"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    GridSizer9->Add(bChangePass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(GridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer8->Add(StaticBoxSizer6, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Erase device for check"));
    GridSizer10 = new wxGridSizer(2, 2, 0, 0);
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Erase all devices for check : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    GridSizer10->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bEraseAll = new wxButton(Panel1, ID_BUTTON8, _("ERASE ALL"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    GridSizer10->Add(bEraseAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    EraseDeviceForCheck_CH = new wxChoice(Panel1, ID_CHOICE6, wxDefaultPosition, wxSize(50,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    EraseDeviceForCheck_CH->Append(_("0"));
    EraseDeviceForCheck_CH->Append(_("1"));
    EraseDeviceForCheck_CH->Append(_("2"));
    EraseDeviceForCheck_CH->Append(_("3"));
    EraseDeviceForCheck_CH->Append(_("4"));
    EraseDeviceForCheck_CH->Append(_("5"));
    EraseDeviceForCheck_CH->Append(_("6"));
    EraseDeviceForCheck_CH->Append(_("7"));
    EraseDeviceForCheck_CH->Append(_("8"));
    EraseDeviceForCheck_CH->Append(_("9"));
    EraseDeviceForCheck_CH->Append(_("10"));
    GridSizer10->Add(EraseDeviceForCheck_CH, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bErase = new wxButton(Panel1, ID_BUTTON9, _("ERASE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    GridSizer10->Add(bErase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7->Add(GridSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer8->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    GridSizer3->Add(GridSizer8, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer3->Add(-1,-1,1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    About_Label = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(800,75), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    GridSizer3->Add(About_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    GridSizer3->Add(-1,-1,1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    Panel1->SetSizer(GridSizer3);
    GridSizer3->Fit(Panel1);
    GridSizer3->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    GridSizer11 = new wxGridSizer(2, 1, -250, 0);
    gLogGrid = new wxGrid(Panel2, ID_GRID1, wxDefaultPosition, wxSize(1300,300), 0, _T("ID_GRID1"));
    gLogGrid->CreateGrid(5000,8);
    gLogGrid->EnableEditing(true);
    gLogGrid->EnableGridLines(true);
    gLogGrid->SetDefaultColSize(149, true);
    gLogGrid->SetColLabelValue(0, _("Log index"));
    gLogGrid->SetColLabelValue(1, _("Log action"));
    gLogGrid->SetColLabelValue(2, _("Reader ID"));
    gLogGrid->SetColLabelValue(3, _("Card ID"));
    gLogGrid->SetColLabelValue(4, _("System ID"));
    gLogGrid->SetColLabelValue(5, _("NFC UID"));
    gLogGrid->SetColLabelValue(6, _("UID length"));
    gLogGrid->SetColLabelValue(7, _("Timestamp"));
    gLogGrid->SetDefaultCellFont( gLogGrid->GetFont() );
    gLogGrid->SetDefaultCellTextColour( gLogGrid->GetForegroundColour() );
    GridSizer11->Add(gLogGrid, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer12 = new wxGridSizer(2, 3, 0, -150);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Get log by index"));
    GridSizer13 = new wxGridSizer(1, 4, 0, 0);
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Start index : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    GridSizer13->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tStartIndex = new wxTextCtrl(Panel2, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(50,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    GridSizer13->Add(tStartIndex, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel2, ID_STATICTEXT13, _("End index : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    GridSizer13->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    tEndIndex = new wxTextCtrl(Panel2, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(50,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    GridSizer13->Add(tEndIndex, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer8->Add(GridSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer12->Add(StaticBoxSizer8, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Get log by time"));
    GridSizer14 = new wxGridSizer(2, 5, 0, 0);
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT14, _("Time from :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    GridSizer14->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    sHoursFrom = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 23, 0, _T("ID_SPINCTRL1"));
    sHoursFrom->SetValue(_T("0"));
    GridSizer14->Add(sHoursFrom, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    sMinutesFrom = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 59, 0, _T("ID_SPINCTRL2"));
    sMinutesFrom->SetValue(_T("0"));
    GridSizer14->Add(sMinutesFrom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sSecondsFrom = new wxSpinCtrl(Panel2, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 59, 0, _T("ID_SPINCTRL3"));
    sSecondsFrom->SetValue(_T("0"));
    GridSizer14->Add(sSecondsFrom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerFrom = new wxDatePickerCtrl(Panel2, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    GridSizer14->Add(DatePickerFrom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel2, ID_STATICTEXT15, _("Time to : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    GridSizer14->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    sHoursTo = new wxSpinCtrl(Panel2, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 23, 0, _T("ID_SPINCTRL4"));
    sHoursTo->SetValue(_T("0"));
    GridSizer14->Add(sHoursTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sMinutesTo = new wxSpinCtrl(Panel2, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 59, 0, _T("ID_SPINCTRL5"));
    sMinutesTo->SetValue(_T("0"));
    GridSizer14->Add(sMinutesTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sSecondsTo = new wxSpinCtrl(Panel2, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 59, 0, _T("ID_SPINCTRL6"));
    sSecondsTo->SetValue(_T("0"));
    GridSizer14->Add(sSecondsTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerTo = new wxDatePickerCtrl(Panel2, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    GridSizer14->Add(DatePickerTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer9->Add(GridSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer12->Add(StaticBoxSizer9, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Input password : "));
    GridSizer15 = new wxGridSizer(1, 2, 0, 0);
    StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT16, _("Password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    GridSizer15->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    tPassword = new wxTextCtrl(Panel2, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    GridSizer15->Add(tPassword, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer10->Add(GridSizer15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer12->Add(StaticBoxSizer10, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    Progress = new wxGauge(Panel2, ID_GAUGE1, 100, wxDefaultPosition, wxSize(292,28), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    GridSizer12->Add(Progress, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bGet_Logs = new wxButton(Panel2, ID_BUTTON10, _("GET LOGS"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    GridSizer12->Add(bGet_Logs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer12->Add(-1,-1,1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    GridSizer11->Add(GridSizer12, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    Panel2->SetSizer(GridSizer11);
    GridSizer11->Fit(Panel2);
    GridSizer11->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    GridSizer16 = new wxGridSizer(6, 1, -100, 0);
    StaticText17 = new wxStaticText(Panel3, ID_STATICTEXT17, _("REAL TIME EVENT INFORMATION :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    GridSizer16->Add(StaticText17, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    RTE_GRID = new wxGrid(Panel3, ID_GRID2, wxDefaultPosition, wxSize(1150,70), 0, _T("ID_GRID2"));
    RTE_GRID->CreateGrid(1,8);
    RTE_GRID->EnableEditing(true);
    RTE_GRID->EnableGridLines(true);
    RTE_GRID->SetDefaultRowSize(35, true);
    RTE_GRID->SetDefaultColSize(130, true);
    RTE_GRID->SetColLabelValue(0, _("Log index"));
    RTE_GRID->SetColLabelValue(1, _("Log action"));
    RTE_GRID->SetColLabelValue(2, _("Reader ID"));
    RTE_GRID->SetColLabelValue(3, _("Card ID"));
    RTE_GRID->SetColLabelValue(4, _("System ID"));
    RTE_GRID->SetColLabelValue(5, _("NFC UID"));
    RTE_GRID->SetColLabelValue(6, _("UID length"));
    RTE_GRID->SetColLabelValue(7, _("Timestamp"));
    RTE_GRID->SetDefaultCellFont( RTE_GRID->GetFont() );
    RTE_GRID->SetDefaultCellTextColour( RTE_GRID->GetForegroundColour() );
    GridSizer16->Add(RTE_GRID, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    bGet_RTE = new wxButton(Panel3, ID_BUTTON11, _("GET RTE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    BoxSizer1->Add(bGet_RTE, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bStop_RTE = new wxButton(Panel3, ID_BUTTON12, _("STOP RTE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    BoxSizer1->Add(bStop_RTE, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer16->Add(BoxSizer1, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Panel3->SetSizer(GridSizer16);
    GridSizer16->Fit(Panel3);
    GridSizer16->SetSizeHints(Panel3);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    GridSizer17 = new wxGridSizer(1, 2, 0, 0);
    StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Whitelist"));
    GridSizer18 = new wxGridSizer(2, 1, -90, 0);
    StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Add to whitelist"));
    GridSizer19 = new wxGridSizer(3, 2, 0, -420);
    StaticText19 = new wxStaticText(Panel4, ID_STATICTEXT19, _("Cards : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    GridSizer19->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Whitelisted_Label = new wxTextCtrl(Panel4, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxSize(470,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    GridSizer19->Add(Whitelisted_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel4, ID_STATICTEXT20, _("Password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    GridSizer19->Add(StaticText20, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    WLPassword_Label = new wxTextCtrl(Panel4, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxSize(133,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    GridSizer19->Add(WLPassword_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bWhitelist_Add = new wxButton(Panel4, ID_BUTTON13, _("Add card to whiltelist"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    GridSizer19->Add(bWhitelist_Add, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer12->Add(GridSizer19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer18->Add(StaticBoxSizer12, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Read whitelist"));
    GridSizer20 = new wxGridSizer(3, 1, -70, 0);
    GridSizer21 = new wxGridSizer(1, 2, 0, -100);
    StaticText21 = new wxStaticText(Panel4, ID_STATICTEXT21, _("Password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    GridSizer21->Add(StaticText21, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    WLR_PasswordLabel = new wxTextCtrl(Panel4, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    GridSizer21->Add(WLR_PasswordLabel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer20->Add(GridSizer21, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    WLRead_Label = new wxTextCtrl(Panel4, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxSize(530,100), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    GridSizer20->Add(WLRead_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    bWhitelist_Read = new wxButton(Panel4, ID_BUTTON14, _("Read whitelisted cards"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
    GridSizer20->Add(bWhitelist_Read, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer13->Add(GridSizer20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer18->Add(StaticBoxSizer13, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer11->Add(GridSizer18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer17->Add(StaticBoxSizer11, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer14 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Blacklist"));
    GridSizer22 = new wxGridSizer(2, 1, -90, 0);
    StaticBoxSizer15 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Add to blacklist"));
    GridSizer23 = new wxGridSizer(3, 2, 0, -420);
    StaticText22 = new wxStaticText(Panel4, ID_STATICTEXT22, _("Cards : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    GridSizer23->Add(StaticText22, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BL_Label = new wxTextCtrl(Panel4, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxSize(470,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    GridSizer23->Add(BL_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(Panel4, ID_STATICTEXT23, _("Password :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    GridSizer23->Add(StaticText23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BL_PasswordLabel = new wxTextCtrl(Panel4, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxSize(136,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    GridSizer23->Add(BL_PasswordLabel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    bBlacklist_Add = new wxButton(Panel4, ID_BUTTON15, _("Add card to blacklist"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    GridSizer23->Add(bBlacklist_Add, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer15->Add(GridSizer23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer22->Add(StaticBoxSizer15, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer16 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Read blacklist"));
    GridSizer24 = new wxGridSizer(3, 1, -70, 0);
    GridSizer25 = new wxGridSizer(1, 2, 0, -100);
    StaticText24 = new wxStaticText(Panel4, ID_STATICTEXT24, _("Password : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    GridSizer25->Add(StaticText24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BLR_PasswordLabel = new wxTextCtrl(Panel4, ID_TEXTCTRL20, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    GridSizer25->Add(BLR_PasswordLabel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer24->Add(GridSizer25, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BLR_Label = new wxTextCtrl(Panel4, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxSize(530,100), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    GridSizer24->Add(BLR_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    bBlacklist_Read = new wxButton(Panel4, ID_BUTTON16, _("Read blacklisted cards"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    GridSizer24->Add(bBlacklist_Read, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer16->Add(GridSizer24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer22->Add(StaticBoxSizer16, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticBoxSizer14->Add(GridSizer22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer17->Add(StaticBoxSizer14, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Panel4->SetSizer(GridSizer17);
    GridSizer17->Fit(Panel4);
    GridSizer17->SetSizeHints(Panel4);
    Notebook1->AddPage(Panel1, _("Settings"), false);
    Notebook1->AddPage(Panel2, _("LOGS"), false);
    Notebook1->AddPage(Panel3, _("Real Time Event"), false);
    Notebook1->AddPage(Panel4, _("Whitelisted / Blacklisted cards"), false);
    GridSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
    SetSizer(GridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridSizer1->Fit(this);
    GridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbConnectClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbDisconnectClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbAddDeviceClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbSetLightClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbGetTimeClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbGetTimeFromPCClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbSetTimeClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbChangePassClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbEraseAllClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbEraseClick);
    Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnGrid1CellLeftClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbGet_LogsClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbGet_RTEClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbStop_RTEClick);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbWhitelist_AddClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbWhitelist_ReadClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbBlacklist_AddClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnbBlacklist_ReadClick);
//    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnNotebook1PageChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BaseHD_example_GUIFrame::OnAbout);
    //*)

    GreenMaster_CH->SetSelection(0);
    RedMaster_CH->SetSelection(0);
    GreenSlave_CH->SetSelection(0);
    RedSlave_CH->SetSelection(0);
    DeviceID_Choice->SetSelection(0);
    EraseDeviceForCheck_CH->SetSelection(0);
    Progress->Hide();



}

BaseHD_example_GUIFrame::~BaseHD_example_GUIFrame()
{
    //(*Destroy(BaseHD_example_GUIFrame)
    //*)
}

void BaseHD_example_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void BaseHD_example_GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void BaseHD_example_GUIFrame::OnbAddDeviceClick(wxCommandEvent& event)
{
    int device_id;
    device_id = DeviceID_Choice -> GetSelection();

    DL_STATUS status;

    status = AIS_List_AddDeviceForCheck(static_cast<E_KNOWN_DEVICE_TYPES>(11), device_id);

    StatusLabel -> SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbConnectClick(wxCommandEvent& event)
{
    AIS_List_UpdateAndGetCount(&device_count);
    DL_STATUS status;
    c_string pDevice_Serial;
    int pDevice_Type;
    int pDevice_ID;
    int pDevice_FW_VER;
    int pDevice_CommSpeed;
    c_string pDevice_FTDI_Serial;
    int pDevice_isOpened;
    int pDevice_Status;
    int pSystem_Status;

    for(int i = 0; i < device_count; i++){

         AIS_List_GetInformation(&handle[i], &pDevice_Serial, &pDevice_Type, &pDevice_ID,
                                 &pDevice_FW_VER, &pDevice_CommSpeed, &pDevice_FTDI_Serial, &pDevice_isOpened,
                                 &pDevice_Status, &pSystem_Status);

        status = AIS_Open(handle[i]);
    }

    StatusLabel -> SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbDisconnectClick(wxCommandEvent& event)
{
    DL_STATUS status;
    for(int i = 0; i < device_count; i++){

            status = AIS_Close(handle[i]);
    }

    StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbSetLightClick(wxCommandEvent& event)
{
    int green_master = 0;
    int red_master = 0;
    int green_slave = 0;
    int red_slave = 0;
    DL_STATUS status;

    green_master = GreenMaster_CH->GetSelection();
    red_master= RedMaster_CH->GetSelection();
    green_slave= GreenSlave_CH->GetSelection();
    red_slave= RedSlave_CH->GetSelection();

    for(int i = 0; i < device_count; i++){

        status = AIS_LightControl(handle[i], green_master, red_master, green_slave, red_slave);
    }

    StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbGetTimeClick(wxCommandEvent& event)
{
    uint64_t current_time = 0;
    wxString cur_time = "";
    int timezone;
    int DST;
    int offset;
    void *additional;
    DL_STATUS status;

    for(int i = 0; i < device_count; i++){

    status = AIS_GetTime(handle[i],&current_time, &timezone, &DST, &offset, &additional);

    }

    StatusLabel->SetValue(dl_status2str(status));

    cur_time << current_time;

    CurrentTime_Label -> SetValue(cur_time);


    cur_time = "";
}

void BaseHD_example_GUIFrame::OnbSetTimeClick(wxCommandEvent& event)
{
    wxString CurrentTime = "";
    wxString Timezone = "";
    wxString Offset = "";
    wxString Password = "";

    c_string password = "";
    uint64_t current_time;
    int timezone;
    int offset;
    int DST = 0;
    int additional = 0x36;
    DL_STATUS status;

    Password = Password_Label->GetValue();
    CurrentTime = CurrentTime_Label->GetValue();
    Timezone = Timezone_Label->GetValue();
    Offset = Offset_Label->GetValue();

    current_time = wxAtoi(CurrentTime);
    timezone = wxAtoi(Timezone);
    offset = wxAtoi(Offset);
    password = Password.c_str();

    if(Use_DST -> GetValue()){

        DST = 1;

    }else if(Dontuse_DST -> GetValue()){

        DST = 0;

    }

    for(int i = 0; i < device_count; i++){

         status = AIS_SetTime(handle[i], password, current_time, timezone, DST, offset, (int *)additional);

    }

    StatusLabel->SetValue(dl_status2str(status));

}

void BaseHD_example_GUIFrame::OnbChangePassClick(wxCommandEvent& event)
{
    DL_STATUS status;
    wxString wxold_password = "";
    wxString wxnew_password = "";

    c_string old_pass = "";
    c_string new_pass = "";

    wxold_password = OldPassword_Label->GetValue();
    wxnew_password = NewPassword_Label->GetValue();

    old_pass = wxold_password.c_str();
    new_pass = wxnew_password.c_str();

    for(int i = 0; i < device_count; i++){

        status = AIS_ChangePassword(handle[i], old_pass, new_pass);
    }

    StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbEraseAllClick(wxCommandEvent& event)
{
    //DL_STATUS status;

    AIS_List_EraseAllDevicesForCheck();

    //StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbEraseClick(wxCommandEvent& event)
{
    int device_id;
    DL_STATUS status;

    device_id = EraseDeviceForCheck_CH->GetSelection();

    status = AIS_List_EraseDeviceForCheck(static_cast<E_KNOWN_DEVICE_TYPES>(11), device_id);

    StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbWhitelist_AddClick(wxCommandEvent& event)
{
    DL_STATUS status;
    wxString pass = "";
    wxString wl_str = "";

    c_string password = "";
    c_string str_whitelist = "";

    pass = WLPassword_Label -> GetValue();
    wl_str = Whitelisted_Label -> GetValue();

    password = pass.char_str();
    str_whitelist = wl_str.char_str();

    for(int i = 0; i < device_count; i++){

    status = AIS_Whitelist_Write(handle[i], password, str_whitelist);

    }

    StatusLabel -> SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbWhitelist_ReadClick(wxCommandEvent& event)
{
    DL_STATUS status;
    wxString pass = "";
    c_string password = "";
    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;
    pass = WLR_PasswordLabel->GetValue();

    password = pass.c_str();
    c_string str_whitelist = "";

    for(int i = 0; i < device_count; i++){

        do{

    AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);
    status = AIS_Whitelist_Read(handle[i], password, &str_whitelist);

        }while(status == TIMEOUT_ERROR);
    }

    WLRead_Label->SetValue(str_whitelist);

    StatusLabel -> SetValue(dl_status2str(status));

}



void BaseHD_example_GUIFrame::OnbBlacklist_AddClick(wxCommandEvent& event)
{
    DL_STATUS status;
    wxString pass = "";
    wxString bl_str = "";

    c_string password = "";
    c_string str_blacklist = "";

    pass = BL_PasswordLabel -> GetValue();
    bl_str = BL_Label -> GetValue();

    password = pass.char_str();
    str_blacklist = bl_str.char_str();

    for(int i = 0; i < device_count; i++){


    status = AIS_Blacklist_Write(handle[i], password, str_blacklist);

    }

    StatusLabel->SetValue(dl_status2str(status));
}

void BaseHD_example_GUIFrame::OnbBlacklist_ReadClick(wxCommandEvent& event)
{
    DL_STATUS status;
    wxString pass = "";
    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;
    c_string password = "";
    c_string str_blacklist = "";

    pass = BLR_PasswordLabel->GetValue();
    password = pass.c_str();

    for(int i = 0; i < device_count; i++){

    do{

    AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);
    status = AIS_Blacklist_Read(handle[i], password, &str_blacklist);

    }while(status == TIMEOUT_ERROR);

    }

    StatusLabel->SetValue(dl_status2str(status));
    BLR_Label->SetValue(str_blacklist);
}

void BaseHD_example_GUIFrame::OnGrid1CellLeftClick(wxGridEvent& event)
{
}

void BaseHD_example_GUIFrame::OnbGetTimeFromPCClick(wxCommandEvent& event)
{
    time_t current_time;
    wxString cur_time = "";

    time(&current_time);

    cur_time << current_time;

    TimeToSet_Label -> SetValue(cur_time);

    cur_time = "";
}

void BaseHD_example_GUIFrame::OnbGet_RTEClick(wxCommandEvent& event)
{

    int rte_count = 0;
    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;
    int log_index,log_action,log_reader_id,log_card_id,log_system_id, nfc_uid_len;
    uint8_t nfc_uid[10];
    uint64_t timestamp;
    char uid_Str[4] = "";

    wxString wxlog_index = "";
    wxString wxlog_action = "";
    wxString wxlog_reader_id = "";
    wxString wxlog_system_id = "";
    wxString wxnfc_uid = "";
    wxString wxnfc_uid_len = "";
    wxString wxtimestamp = "";
    wxString wxlog_card = "";


        do{

    wxYield();

     for(int i = 0; i < device_count; i++){

     AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);

     rte_count = AIS_ReadRTE_Count(handle[i]);

     if(rte_count > 0){

        AIS_ReadRTE(handle[i], &log_index, &log_action, &log_reader_id, &log_card_id, &log_system_id,
                    nfc_uid, &nfc_uid_len, &timestamp);

        wxlog_index << log_index;
        wxlog_action << log_action;
        wxlog_reader_id << log_reader_id;
        wxlog_card << log_card_id;
        wxlog_system_id << log_system_id;
        wxnfc_uid_len << nfc_uid_len;
        wxtimestamp << dbg_GMT2str(timestamp);

        for(int j = 0; j < nfc_uid_len; j++){

            strcpy(uid_Str, "");
            sprintf(uid_Str, "%02X", nfc_uid[j]);
            wxnfc_uid << uid_Str;

        }

        RTE_GRID -> SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

        RTE_GRID -> SetCellValue(0, 0, wxlog_index);
        RTE_GRID -> SetCellValue(0, 1, wxlog_action);
        RTE_GRID -> SetCellValue(0, 2, wxlog_reader_id);
        RTE_GRID -> SetCellValue(0, 3, wxlog_card);
        RTE_GRID -> SetCellValue(0, 4, wxlog_system_id);
        RTE_GRID -> SetCellValue(0, 5, wxnfc_uid);
        RTE_GRID -> SetCellValue(0, 6, wxnfc_uid_len);
        RTE_GRID -> SetCellValue(0, 7, wxtimestamp);

     }
     wxlog_index = "";
     wxlog_action = "";
     wxlog_reader_id = "";
     wxlog_system_id = "";
     wxnfc_uid = "";
     wxnfc_uid_len = "";
     wxtimestamp = "";
     wxlog_card = "";

        }

    }while(RTE_STOP == 0);


}

void BaseHD_example_GUIFrame::OnbStop_RTEClick(wxCommandEvent& event)
{
    RTE_STOP = 1;
}

void BaseHD_example_GUIFrame::OnbGet_LogsClick(wxCommandEvent& event)
{
    Progress->Show();
    DL_STATUS status;
    wxString wxDebug = "";
    wxString cmdDebug ="";
    wxString wxLogsDetails = "";
    wxString StartIndex = "";
    wxString EndIndex = "";
    wxString TimeTo = "";
    wxString TimeFrom = "";
    wxString wxPassword = "";
    wxString DateTo;
    wxString DateFrom;
    int to_set_col = 0;

        wxDateTime get_date_from;
        wxDateTime get_date_to;
        wxLongLong seconds_from_date_picker;
        wxLongLong seconds_to_date_picker;

    char uid_chars[4] = "";


    get_date_from = DatePickerFrom->GetValue();

    get_date_to = DatePickerTo->GetValue();


    int hours_to, minutes_to,seconds_to;
    int hours_from, minutes_from, seconds_from;


        hours_to = sHoursTo->GetValue();
        minutes_to = sMinutesTo->GetValue();
        seconds_to = sSecondsTo->GetValue();

        hours_from = sHoursFrom->GetValue();
        minutes_from = sMinutesFrom->GetValue();
        seconds_from = sSecondsFrom->GetValue();



///******************************************************************************************
        wxDateTime date_from = DatePickerFrom->GetValue();

        wxDateTime dt1970;
        dt1970.Set(1, wxDateTime::Jan, 1970, 0, 0, 0, 0);


        wxDateTime dt;

        dt.Set(date_from.GetDay(), date_from.GetMonth(), date_from.GetYear(), hours_from+1, minutes_from, seconds_from, 0);

        wxTimeSpan ts = dt.Subtract(dt1970);

    wxLongLong long_time_from = ts.GetSeconds();



    wxString time_from_in_seconds = "";

    time_from_in_seconds << long_time_from;

    uint64_t from = long_time_from.ToLong();

///****************************************************************************************
 wxDateTime date_to = DatePickerTo->GetValue();

        wxDateTime dt_to;

        dt_to.Set(date_to.GetDay(), date_to.GetMonth(), date_to.GetYear(), hours_to+1, minutes_to, seconds_to, 0);

        wxTimeSpan ts_to = dt_to.Subtract(dt1970);



wxLongLong long_time_to = ts_to.GetSeconds();

   wxString time_to_in_seconds = "";

    time_to_in_seconds << "\n TO: " << long_time_from;

        uint64_t to = long_time_to.ToLong();

        wxPassword = tPassword->GetValue();

        c_string password = wxPassword.c_str();

        int start_index;

        int end_index;

    StartIndex = tStartIndex->GetValue();

    EndIndex = tEndIndex->GetValue();


    start_index = wxAtoi(StartIndex);

    end_index = wxAtoi(EndIndex);

        if ( ((StartIndex == "") && (EndIndex == "")) && ((hours_from == 0) && (minutes_from == 0) && (seconds_from == 0))) {

        gLogGrid -> ClearGrid();

        for (int i = 0; i < device_count; i++){

    int log_index,log_action,log_reader_id,log_card_id,log_system_id, nfc_uid_len;

    uint64_t timestamp;

    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;

    uint8_t nfc_uid[10];


            AIS_ClearLog(handle[i]);


            status = AIS_GetLog(handle[i], password);

            do {

    wxString wxLogIndex = "";
    wxString wxLogAction = "";
    wxString wxCardID = "";
    wxString wxReaderID = "";
    wxString wxUID = "";
    wxString wxUIDLength = "";
    wxString wxTimestamp = "";
    wxString wxSystemID ="";


                wxYield();

            status = AIS_ReadLog(handle[i],&log_index, &log_action, &log_reader_id, &log_card_id, &log_system_id, nfc_uid,&nfc_uid_len, &timestamp);

            status = AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);


                if (LogUnread == 0){

                Progress->SetValue(cmdPercent);

            } else {


        for (unsigned int k = 0; k < unsigned(nfc_uid_len); k++)
        {

            strcpy(uid_chars, "");
            sprintf(uid_chars, "%02X", nfc_uid[k]);;
            wxUID << uid_chars;

        }


        wxLogIndex << log_index;

        wxLogAction << log_action;

        wxReaderID << log_reader_id;

        wxCardID << log_card_id;

        wxSystemID << log_system_id;

        wxUIDLength << nfc_uid_len;

        wxTimestamp << dbg_GMT2str(timestamp);


      gLogGrid -> SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

            gLogGrid->SetCellValue(to_set_col,0,wxLogIndex);
            gLogGrid->SetCellValue(to_set_col,1,wxLogAction);
            gLogGrid->SetCellValue(to_set_col,2,wxReaderID);
            gLogGrid->SetCellValue(to_set_col,3,wxCardID);
            gLogGrid->SetCellValue(to_set_col,4,wxSystemID);
            gLogGrid->SetCellValue(to_set_col,5,wxUID);
            gLogGrid->SetCellValue(to_set_col,6,wxUIDLength);
            gLogGrid->SetCellValue(to_set_col,7,wxTimestamp);

            to_set_col = to_set_col + 1;
            if (log_index == LogUnread-1){

                    to_set_col = 0;
                    break;
                }
            }
        } while (status == DL_OK);


    }


        }

            else if (((StartIndex != "") && (EndIndex != "")) && ((TimeFrom == "") && (TimeTo == ""))) {
                    gLogGrid -> ClearGrid();

        for (int i = 0; i < device_count; i++){


                int log_index,log_action,log_reader_id,log_card_id,log_system_id, nfc_uid_len;

    uint64_t timestamp;

    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;

    uint8_t nfc_uid[10];

            AIS_ClearLog(handle[i]);

           status = AIS_GetLogByIndex(handle[i], password,start_index,end_index);

            do {

    wxString wxLogIndex = "";
    wxString wxLogAction = "";
    wxString wxCardID = "";
    wxString wxReaderID = "";
    wxString wxUID = "";
    wxString wxUIDLength = "";
    wxString wxTimestamp = "";
    wxString wxSystemID ="";

                wxYield();

            status = AIS_ReadLog(handle[i],&log_index, &log_action, &log_reader_id, &log_card_id, &log_system_id, nfc_uid,&nfc_uid_len, &timestamp);

            status = AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);


                if (LogUnread == 0){

                        Progress->SetValue(cmdPercent);


            } else {


        for (unsigned int k = 0; k < unsigned(nfc_uid_len); k++)
        {

             strcpy(uid_chars, "");
            sprintf(uid_chars, "%02X", nfc_uid[k]);;
            wxUID << uid_chars;


        }


        wxLogIndex << log_index;

        wxLogAction << log_action;

        wxReaderID << log_reader_id;

        wxCardID << log_card_id;

        wxSystemID << log_system_id;

        wxUIDLength << nfc_uid_len;

        wxTimestamp << dbg_GMT2str(timestamp);

      gLogGrid -> SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

            gLogGrid->SetCellValue(to_set_col,0,wxLogIndex);
            gLogGrid->SetCellValue(to_set_col,1,wxLogAction);
            gLogGrid->SetCellValue(to_set_col,2,wxReaderID);
            gLogGrid->SetCellValue(to_set_col,3,wxCardID);
            gLogGrid->SetCellValue(to_set_col,4,wxSystemID);
            gLogGrid->SetCellValue(to_set_col,5,wxUID);
            gLogGrid->SetCellValue(to_set_col,6,wxUIDLength);
            gLogGrid->SetCellValue(to_set_col,7,wxTimestamp);

            to_set_col = to_set_col + 1;

            if (log_index == end_index){

                    to_set_col = 0;
                    break;
                }
            }
        } while (status == DL_OK);


    }

        }  else if (((StartIndex == "") && (EndIndex == "")) && ((hours_from != 0) && (hours_to != 0))) {

            gLogGrid -> ClearGrid();

        for (int i = 0; i < device_count; i++){


                int log_index,log_action,log_reader_id,log_card_id,log_system_id, nfc_uid_len;

    uint64_t timestamp;

    int RealTimeEvents,LogAvailable,LogUnread,cmdResponses,cmdPercent,DeviceStatus,TimeoutOccurred,int_status;

    uint8_t nfc_uid[10];


            AIS_ClearLog(handle[i]);

           status = AIS_GetLogByTime(handle[i], password,from,to);
            int racunaj=0;
            do {

    wxString wxLogIndex = "";
    wxString wxLogAction = "";
    wxString wxCardID = "";
    wxString wxReaderID = "";
    wxString wxUID = "";
    wxString wxUIDLength = "";
    wxString wxTimestamp = "";
    wxString wxSystemID ="";

             racunaj = log_index;

                wxYield();

            status = AIS_ReadLog(handle[i],&log_index, &log_action, &log_reader_id, &log_card_id, &log_system_id, nfc_uid,&nfc_uid_len, &timestamp);

            status = AIS_MainLoop(handle[i],&RealTimeEvents,&LogAvailable,&LogUnread,&cmdResponses,&cmdPercent,&DeviceStatus,&TimeoutOccurred,&int_status);


                if (LogUnread == 0){

                Progress->SetValue(cmdPercent);

            } else {

        for (unsigned int k = 0; k < unsigned(nfc_uid_len); k++)
        {

         strcpy(uid_chars, "");
            sprintf(uid_chars, "%02X", nfc_uid[k]);;
            wxUID << uid_chars;


        }


        wxLogIndex << log_index;

        wxLogAction << log_action;

        wxReaderID << log_reader_id;

        wxCardID << log_card_id;

        wxSystemID << log_system_id;

        wxUIDLength << nfc_uid_len;

        wxTimestamp << dbg_GMT2str(timestamp);


 if(racunaj == log_index){
                         break;
                     }
      gLogGrid -> SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

            gLogGrid->SetCellValue(to_set_col,0,wxLogIndex);
            gLogGrid->SetCellValue(to_set_col,1,wxLogAction);
            gLogGrid->SetCellValue(to_set_col,2,wxReaderID);
            gLogGrid->SetCellValue(to_set_col,3,wxCardID);
            gLogGrid->SetCellValue(to_set_col,4,wxSystemID);
            gLogGrid->SetCellValue(to_set_col,5,wxUID);
            gLogGrid->SetCellValue(to_set_col,6,wxUIDLength);
            gLogGrid->SetCellValue(to_set_col,7,wxTimestamp);

            to_set_col = to_set_col + 1;

            }

        } while (status == DL_OK);


    }
            }

            start_index = 0;
            end_index = 0;

            hours_from = 0; minutes_from = 0; seconds_from = 0;
            hours_to = 0; minutes_to = 0; seconds_to = 0;

            gLogGrid->AutoSizeColumn(7);
            gLogGrid->AutoSizeColumn(6);
            Progress->Hide();
}
