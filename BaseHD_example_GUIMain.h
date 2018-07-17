/***************************************************************
 * Name:      BaseHD_example_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-07-16
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef BASEHD_EXAMPLE_GUIMAIN_H
#define BASEHD_EXAMPLE_GUIMAIN_H

//(*Headers(BaseHD_example_GUIFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class BaseHD_example_GUIFrame: public wxFrame
{
    public:

        BaseHD_example_GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BaseHD_example_GUIFrame();

    private:

        //(*Handlers(BaseHD_example_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbAddDeviceClick(wxCommandEvent& event);
        void OnbConnectClick(wxCommandEvent& event);
        void OnbDisconnectClick(wxCommandEvent& event);
        void OnbSetLightClick(wxCommandEvent& event);
        void OnbGetTimeClick(wxCommandEvent& event);
        void OnbSetTimeClick(wxCommandEvent& event);
        void OnbChangePassClick(wxCommandEvent& event);
        void OnbEraseAllClick(wxCommandEvent& event);
        void OnbEraseClick(wxCommandEvent& event);
        void OnbWhitelist_AddClick(wxCommandEvent& event);
        void OnbWhitelist_ReadClick(wxCommandEvent& event);
        void OnbBlacklist_AddClick(wxCommandEvent& event);
        void OnbBlacklist_ReadClick(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnbGetTimeFromPCClick(wxCommandEvent& event);
        void OnbGet_RTEClick(wxCommandEvent& event);
        void OnbStop_RTEClick(wxCommandEvent& event);
        void OnbGetLastNfcClick(wxCommandEvent& event);
        void OnbGet_LogsClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(BaseHD_example_GUIFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_CHOICE1;
        static const long ID_BUTTON3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE3;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT4;
        static const long ID_CHOICE5;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON17;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL4;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT25;
        static const long ID_TEXTCTRL22;
        static const long ID_BUTTON6;
        static const long ID_STATICTEXT9;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON7;
        static const long ID_STATICTEXT11;
        static const long ID_BUTTON8;
        static const long ID_CHOICE6;
        static const long ID_BUTTON9;
        static const long ID_TEXTCTRL8;
        static const long ID_PANEL1;
        static const long ID_GRID1;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT14;
        static const long ID_SPINCTRL1;
        static const long ID_SPINCTRL2;
        static const long ID_SPINCTRL3;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_STATICTEXT15;
        static const long ID_SPINCTRL4;
        static const long ID_SPINCTRL5;
        static const long ID_SPINCTRL6;
        static const long ID_DATEPICKERCTRL2;
        static const long ID_STATICTEXT16;
        static const long ID_TEXTCTRL13;
        static const long ID_GAUGE1;
        static const long ID_BUTTON10;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT17;
        static const long ID_GRID2;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL14;
        static const long ID_STATICTEXT20;
        static const long ID_TEXTCTRL15;
        static const long ID_BUTTON13;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL17;
        static const long ID_BUTTON14;
        static const long ID_STATICTEXT22;
        static const long ID_TEXTCTRL18;
        static const long ID_STATICTEXT23;
        static const long ID_TEXTCTRL19;
        static const long ID_BUTTON15;
        static const long ID_STATICTEXT24;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL21;
        static const long ID_BUTTON16;
        static const long ID_PANEL4;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(BaseHD_example_GUIFrame)
        wxButton* bAddDevice;
        wxButton* bBlacklist_Add;
        wxButton* bBlacklist_Read;
        wxButton* bChangePass;
        wxButton* bConnect;
        wxButton* bDisconnect;
        wxButton* bErase;
        wxButton* bEraseAll;
        wxButton* bGetTime;
        wxButton* bGetTimeFromPC;
        wxButton* bGet_Logs;
        wxButton* bGet_RTE;
        wxButton* bSetLight;
        wxButton* bSetTime;
        wxButton* bStop_RTE;
        wxButton* bWhitelist_Add;
        wxButton* bWhitelist_Read;
        wxChoice* DeviceID_Choice;
        wxChoice* EraseDeviceForCheck_CH;
        wxChoice* GreenMaster_CH;
        wxChoice* GreenSlave_CH;
        wxChoice* RedMaster_CH;
        wxChoice* RedSlave_CH;
        wxDatePickerCtrl* DatePickerFrom;
        wxDatePickerCtrl* DatePickerTo;
        wxGauge* Progress;
        wxGrid* RTE_GRID;
        wxGrid* gLogGrid;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxPanel* Panel4;
        wxRadioButton* Dontuse_DST;
        wxRadioButton* Use_DST;
        wxSpinCtrl* sHoursFrom;
        wxSpinCtrl* sHoursTo;
        wxSpinCtrl* sMinutesFrom;
        wxSpinCtrl* sMinutesTo;
        wxSpinCtrl* sSecondsFrom;
        wxSpinCtrl* sSecondsTo;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText19;
        wxStaticText* StaticText1;
        wxStaticText* StaticText20;
        wxStaticText* StaticText21;
        wxStaticText* StaticText22;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxStaticText* StaticText25;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStatusBar* StatusBar1;
        wxTextCtrl* About_Label;
        wxTextCtrl* BLR_Label;
        wxTextCtrl* BLR_PasswordLabel;
        wxTextCtrl* BL_Label;
        wxTextCtrl* BL_PasswordLabel;
        wxTextCtrl* CurrentTime_Label;
        wxTextCtrl* NewPassword_Label;
        wxTextCtrl* Offset_Label;
        wxTextCtrl* OldPassword_Label;
        wxTextCtrl* Password_Label;
        wxTextCtrl* StatusLabel;
        wxTextCtrl* TimeToSet_Label;
        wxTextCtrl* Timezone_Label;
        wxTextCtrl* WLPassword_Label;
        wxTextCtrl* WLR_PasswordLabel;
        wxTextCtrl* WLRead_Label;
        wxTextCtrl* Whitelisted_Label;
        wxTextCtrl* tEndIndex;
        wxTextCtrl* tPassword;
        wxTextCtrl* tStartIndex;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BASEHD_EXAMPLE_GUIMAIN_H
