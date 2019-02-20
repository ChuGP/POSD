#ifndef TREE_FRAME_H
#define TREE_FRAME_H

#include <wx/treectrl.h>
#include "node_builder.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "node_iterator.h"
#include "editNode.h"
#include <fstream>
#include <sstream>

#include "observer.h"

using namespace std;
enum{
    BUTTON_Save = wxID_HIGHEST + 1
  };
  
class TreeFrame : public wxFrame
{
public:
  TreeFrame(const wxChar *title, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
  {
    _tree = new wxTreeCtrl(this, wxID_ANY, wxPoint(0,0), wxSize(300,1000), wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );

    createTextArea();
    createSaveButton();
    wxString gp =wxGetApp().argv[1] ; // 要建立的檔案
    
    char * path = new char[sizeof(gp.mb_str())];
    strcpy(path,gp.mb_str());
    NodeBuilder nb;
    nb.build(path);
    Node * root = nb.getRoot();
    string allname = root->name() + ", " + to_string(root->size()) ;
    wxTreeItemId rootId = _tree->AddRoot(allname,-1,-1,new EditNode(root));
    treebuilder(root,rootId);
    _tree->ExpandAllChildren(rootId);
    

    
    
    Layout();
    Centre();
  }
  //===========================================================attach detach
  void attach(Observer * ob) {
      _observers.push_back(ob);
  }

  void detach(Observer * ob) {
    for(int i  = 0; i < _observers.size(); i++){
      if (_observers[i] == ob) {
        _observers.erase(_observers.begin() + i);
      }
    }
  }

  void notify(Node * temp)
  {
      std::vector<Observer *>::iterator it;
      for(it=_observers.begin();it != _observers.end() ; ++it){
        (*it)->update(temp);
      }
  }


  //  ======================================================EVENT
  void createTextArea()
  {
    m_pTextCtrl = new wxTextCtrl(this, -1, _T("Welcome To POSD_EDITOR"),
		wxPoint(300,0), wxSize(724,500), wxTE_MULTILINE);
  } // createTextArea()

  void createSaveButton()
  {
    wxBoxSizer * vbox = new wxBoxSizer(wxHORIZONTAL) ;
    m_save = new wxButton(this, BUTTON_Save, _T("Save"), wxPoint(300,500), wxSize(724,200), 0);
    vbox->Add( m_save );
  }

  void treebuilder(Node * root, wxTreeItemId rootId)
  {
    //建立tree頁面
    NodeIterator * it = root->createIterator();
      for (it->first(); it->isDone() == false ; it->next() )
      {
        string allname = it->currentItem()->name() + ", " + to_string(it->currentItem()->size()) ;
        wxTreeItemId childId = _tree->AppendItem(rootId, allname,-1,-1,new EditNode(it->currentItem()) );
        treebuilder( it->currentItem(), childId);
      } // for
  }

  void OnEdit(wxTreeEvent& event)
  {
    wxString label = event.GetLabel(); //改過後
    string show = "label edited:"+ string(label.c_str()) + "-- old name was " + string(oldlabel.c_str()) ;
    wxMessageDialog * dialog = new wxMessageDialog( this, show, "Confirm", wxYES_NO|wxCANCEL);
    if ( dialog->ShowModal() != wxID_YES )
      event.Veto(); // 不編輯
      
    
    wxTreeItemId  id = event.GetItem();
    EditNode * gp = dynamic_cast<EditNode*>(_tree->GetItemData(id));
    char * oldName;
    char * newName ;
    if ( gp->GetNode()->getParent() != nullptr ) {
      
      oldName = new char[sizeof(gp->GetNode()->path())] ;
      strcpy(oldName,gp->GetNode()->path().c_str());

      newName = new char[(gp->GetNode()->getParent()->path()+"/"+label.mb_str()).length()];
      strcpy(newName,(gp->GetNode()->getParent()->path().c_str() ));
      strcat(newName,"/");
      strcat(newName,label.mb_str());
    }

    if (rename(oldName, newName) == 0)
    {
      gp->GetNode()->setPath(newName) ;
      notify(gp->GetNode());  // 呼叫observer 去update
    }
    else
      return ;
    
  }

  void OnBeginEdit(wxTreeEvent& event)
  {
    wxTreeItemId  id = event.GetItem();
    oldlabel = _tree -> GetItemText(id) ;
  }

  void ClickSave(wxCommandEvent& event)
  {
    wxMessageDialog * dialog = new wxMessageDialog( this, "You want save?", "Confirm", wxYES_NO|wxCANCEL);
    if ( dialog->ShowModal() == wxID_YES )
    {
      // m_pTextCtrl->SaveFile(nowhover->path());
      notify(nowhover);
    }
  }

  wxTextCtrl * GetCtrl()
  {
    return m_pTextCtrl;
  }

  void ShowFile(wxTreeEvent& event)
  {
    wxTreeItemId  id = event.GetItem();
    EditNode * gp = dynamic_cast<EditNode*>(_tree->GetItemData(id));
    nowhover = gp->GetNode();
    struct stat st;
    if (lstat( (gp->GetNode()->path()).c_str(), &st) == 0) {
      if (S_ISREG(st.st_mode))
      {
        int c = 0;
        fstream test(gp->GetNode()->path(),ios::in) ; //測試text binary用
        while((c = test.get()) != EOF && c <= 127);
        if(c == EOF) {
          m_pTextCtrl->LoadFile(gp->GetNode()->path()) ;
          return ;
            /* file is all ASCII */
        }
        
      } // if
      m_pTextCtrl->SetValue("The file is not displayed in the editor because it uses an unsupported text encoding.");
    
    } // if
  }

  wxTreeCtrl *_tree;

private:
  DECLARE_EVENT_TABLE()
  wxTextCtrl *m_pTextCtrl;
  wxButton *m_save;
  wxString oldlabel;
  Node * nowhover;
  std::vector<Observer *> _observers;
};

 
BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
  EVT_TREE_BEGIN_LABEL_EDIT (wxID_ANY, TreeFrame::OnBeginEdit)
  EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnEdit)
  EVT_BUTTON(BUTTON_Save,TreeFrame::ClickSave)
  EVT_TREE_SEL_CHANGED(wxID_ANY, TreeFrame::ShowFile)
END_EVENT_TABLE()
#endif
