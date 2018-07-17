/***************************************************************
 * Name:      BaseHD_example_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-07-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "BaseHD_example_GUIApp.h"

//(*AppHeaders
#include "BaseHD_example_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(BaseHD_example_GUIApp);

bool BaseHD_example_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	BaseHD_example_GUIFrame* Frame = new BaseHD_example_GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
