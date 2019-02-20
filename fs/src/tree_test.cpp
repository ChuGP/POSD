#include <wx/wx.h>
#include "tree_test.h"
#include "tree_frame.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "observer.h"
#include "mock_tree_path.h"
#include "mock_tree_size.h"
using namespace std;
IMPLEMENT_APP(TreeTestApp)

bool TreeTestApp::OnInit()
{

  wxFrame *frame = new TreeFrame(wxT("***Tree Test***"), 100,100,1025,700);
  frame->Show(true);
  this->SetTopWindow(frame);
  Observer * mockTreePath = new MockTreePath(dynamic_cast<TreeFrame*>(frame));
  Observer * mockTreeSize = new MockTreeSize(dynamic_cast<TreeFrame*>(frame));
  //設ctrl+s快捷
  wxAcceleratorEntry entries[1];
  entries[0].Set(wxACCEL_CTRL,(int) 'S',BUTTON_Save);
  wxAcceleratorTable accel(1,entries);
  frame->SetAcceleratorTable(accel);
  return true;
}
