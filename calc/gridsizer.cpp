#include "gridsizer.h"
#include <iostream>
#include <sstream>
using namespace std;

GridSizer::GridSizer(const wxString& title)
       : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(270, 220))
{
  sizer = new wxBoxSizer(wxVERTICAL);
 
  display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1),
     wxSize(-1, -1), wxTE_RIGHT);

  sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
  gs = new wxGridSizer(5, 4, 3, 3);

  gs->Add(new wxButton(this, 1050, wxT("Cls")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("Bck")), 0, wxEXPAND);
  gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("Close")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 7, wxT("7")), 0, wxEXPAND); 
  gs->Add(new wxButton(this, 8, wxT("8")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 9, wxT("9")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("/")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 999, wxT("4")), 0, wxEXPAND);
  gs->Add(new wxButton(this,10, wxT("5")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 11, wxT("6")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 21, wxT("*")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 1001, wxT("1")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 1002, wxT("2")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 1000, wxT("3")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("-")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("0")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT(".")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("=")), 0, wxEXPAND);
  gs->Add(new wxButton(this, 1011 , wxT("+")), 0, wxEXPAND);

  sizer->Add(gs, 1, wxEXPAND);
  SetSizer(sizer);
  SetMinSize(wxSize(270, 220));

  Centre();
}

void GridSizer::onCls (wxCommandEvent& WXUNUSED (event)) {
	nClicks += 1;
	cout <<"Hola " << nClicks << endl;
}


void GridSizer::onBt1 (wxCommandEvent& WXUNUSED (event)) {
	nClicks += 1;
	
	if (nClicks==1)
		valor1 = 1;
		cout<<valor2<<endl;
	if (nClicks==2)
		valor2 = 1;
		cout<<valor2<<endl;
}

void GridSizer::onBt2 (wxCommandEvent& WXUNUSED (event)) {
	nClicks += 1;
	if (nClicks==1)
		valor1 = 2;
	if (nClicks==2)
		valor2 = 2;
}
void GridSizer::onBt3(wxCommandEvent& WXUNUSED (event)){
	nClicks++;
	if(nClicks==1)
		valor1=3;
	if(nClicks==2)
		valor2=3;
	

}

void GridSizer::onBt4(wxCommandEvent& WXUNUSED (event)){
	nClicks++;
	if(nClicks==1)
		valor1=4;
	if(nClicks==2)
		valor2=4;
}

void GridSizer::onBt5(wxCommandEvent& WXUNUSED (event)){
	nClicks++;
	if(nClicks==1)
		valor1=5;
	if(nClicks==2)
		valor2=5;

}
void GridSizer::onBt6(wxCommandEvent& WXUNUSED (event)){

	nClicks++;
	if(nClicks==1)
		valor1=6;
	if(nClicks==2)
		valor2=6;
}

void GridSizer::onBt7(wxCommandEvent& WXUNUSED (event)){

	nClicks++;
	if(nClicks==1)
		valor1=7;
	if(nClicks==2)
		valor2=7;
}

void GridSizer::onBt8(wxCommandEvent& WXUNUSED (event)){

	nClicks++;
	if(nClicks==1)
		valor1=8;
	if(nClicks==2)
		valor2=8;
}

void GridSizer::onBt9(wxCommandEvent& WXUNUSED (event)){

	nClicks++;
	if(nClicks==1)
		valor1=9;
	if(nClicks==2)
		valor2=9;
}



void GridSizer::onBtSum (wxCommandEvent& WXUNUSED (event)) {
	int total = valor1 + valor2;
	cout << "Resultado suma " << total << endl;
	valor1=valor2=0;
	nClicks=0;
	string S;
	ostringstream convert;   
	
	convert << total;
	S=convert.str();
	wxString k(S);
	display->SetValue(k);
	
}
void GridSizer::onBtPor (wxCommandEvent& WXUNUSED (event)) {
	int total = valor1 * valor2;
	cout << "Resultado multiplicacion " << total << endl;
	
	valor1=valor2=0;
	nClicks=0;
	string S;
	ostringstream convert;   
	
	convert << total;
	S=convert.str();
	wxString k(S);
	display->SetValue(k);
}




	
	

BEGIN_EVENT_TABLE(GridSizer, wxFrame)
    EVT_BUTTON(1050,  GridSizer::onCls)
    EVT_BUTTON(1001,  GridSizer::onBt1)
    EVT_BUTTON(1002,  GridSizer::onBt2)
    EVT_BUTTON(1000,  GridSizer::onBt3)
    EVT_BUTTON(1011,  GridSizer::onBtSum)
    EVT_BUTTON(999,GridSizer::onBt4)
    EVT_BUTTON(10,GridSizer::onBt5)
    EVT_BUTTON(11,GridSizer::onBt6)
    EVT_BUTTON(7,GridSizer::onBt7)
    EVT_BUTTON(8,GridSizer::onBt8)
    EVT_BUTTON(9,GridSizer::onBt9)
    EVT_BUTTON(21,GridSizer::onBtPor)
END_EVENT_TABLE()
