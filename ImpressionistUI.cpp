//
// impressionistUI.h
//
// The user interface part for the program.
//


#include <FL/fl_ask.h>

#include <math.h>
#include<iostream>
#include "impressionistUI.h"
#include "impressionistDoc.h"

using namespace std;
/*
//------------------------------ Widget Examples -------------------------------------------------
Here is some example code for all of the widgets that you may need to add to the 
project.  You can copy and paste these into your code and then change them to 
make them look how you want.  Descriptions for all of the widgets here can be found 
in links on the fltk help session page.

//---------Window/Dialog and Menubar-----------------------------------
	
	//----To install a window--------------------------
	Fl_Window* myWindow = new Fl_Window(600, 300, "MyWindow");
		myWindow->user_data((void*)(this));	// record self to be used by static callback functions
		
		// install menu bar
		myMenubar = new Fl_Menu_Bar(0, 0, 600, 25);
		Fl_Menu_Item ImpressionistUI::myMenuItems[] = {
			{ "&File",		0, 0, 0, FL_SUBMENU },
				{ "&Load...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load },
				{ "&Save...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save }.
				{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
				{ 0 },
			{ "&Edit",		0, 0, 0, FL_SUBMENU },
				{ "&Copy",FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_copy, (void *)COPY },
				{ "&Cut",	FL_ALT + 'x', (Fl_Callback *)ImpressionistUI::cb_cut, (void *)CUT },
				{ "&Paste",	FL_ALT + 'v', (Fl_Callback *)ImpressionistUI::cb_paste, (void *)PASTE },
				{ 0 },
			{ "&Help",		0, 0, 0, FL_SUBMENU },
				{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
				{ 0 },
			{ 0 }
		};
		myMenubar->menu(myMenuItems);
    m_mainWindow->end();

	//----The window callback--------------------------
	// One of the callbacks
	void ImpressionistUI::cb_load(Fl_Menu_* o, void* v) 
	{	
		ImpressionistDoc *pDoc=whoami(o)->getDocument();

		char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
		if (newfile != NULL) {
			pDoc->loadImage(newfile);
		}
	}


//------------Slider---------------------------------------

	//----To install a slider--------------------------
	Fl_Value_Slider * mySlider = new Fl_Value_Slider(10, 80, 300, 20, "My Value");
	mySlider->user_data((void*)(this));	// record self to be used by static callback functions
	mySlider->type(FL_HOR_NICE_SLIDER);
    mySlider->labelfont(FL_COURIER);
    mySlider->labelsize(12);
	mySlider->minimum(1);
	mySlider->maximum(40);
	mySlider->step(1);
	mySlider->value(m_nMyValue);
	mySlider->align(FL_ALIGN_RIGHT);
	mySlider->callback(cb_MyValueSlides);

	//----The slider callback--------------------------
	void ImpressionistUI::cb_MyValueSlides(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyValue=int( ((Fl_Slider *)o)->value() ) ;
	}
	

//------------Choice---------------------------------------
	
	//----To install a choice--------------------------
	Fl_Choice * myChoice = new Fl_Choice(50,10,150,25,"&myChoiceLabel");
	myChoice->user_data((void*)(this));	 // record self to be used by static callback functions
	Fl_Menu_Item ImpressionistUI::myChoiceMenu[3+1] = {
	  {"one",FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)ONE},
	  {"two",FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)TWO},
	  {"three",FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)THREE},
	  {0}
	};
	myChoice->menu(myChoiceMenu);
	myChoice->callback(cb_myChoice);
	
	//-----The choice callback-------------------------
	void ImpressionistUI::cb_myChoice(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
		ImpressionistDoc* pDoc=pUI->getDocument();

		int type=(int)v;

		pDoc->setMyType(type);
	}


//------------Button---------------------------------------

	//---To install a button---------------------------
	Fl_Button* myButton = new Fl_Button(330,220,50,20,"&myButtonLabel");
	myButton->user_data((void*)(this));   // record self to be used by static callback functions
	myButton->callback(cb_myButton);

	//---The button callback---------------------------
	void ImpressionistUI::cb_myButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI*)(o->user_data()));
		ImpressionistDoc* pDoc = pUI->getDocument();
		pDoc->startPainting();
	}


//---------Light Button------------------------------------
	
	//---To install a light button---------------------
	Fl_Light_Button* myLightButton = new Fl_Light_Button(240,10,150,25,"&myLightButtonLabel");
	myLightButton->user_data((void*)(this));   // record self to be used by static callback functions
	myLightButton->callback(cb_myLightButton);

	//---The light button callback---------------------
	void ImpressionistUI::cb_myLightButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

		if (pUI->myBool==TRUE) pUI->myBool=FALSE;
		else pUI->myBool=TRUE;
	}

//----------Int Input--------------------------------------

    //---To install an int input-----------------------
	Fl_Int_Input* myInput = new Fl_Int_Input(200, 50, 5, 5, "&My Input");
	myInput->user_data((void*)(this));   // record self to be used by static callback functions
	myInput->callback(cb_myInput);

	//---The int input callback------------------------
	void ImpressionistUI::cb_myInput(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyInputValue=int( ((Fl_Int_Input *)o)->value() );
	}

//------------------------------------------------------------------------------------------------
*/

//------------------------------------- Help Functions --------------------------------------------

//------------------------------------------------------------
// This returns the UI, given the menu item.  It provides a
// link from the menu items to the UI
//------------------------------------------------------------
ImpressionistUI* ImpressionistUI::whoami(Fl_Menu_* o)	
{
	return ( (ImpressionistUI*)(o->parent()->user_data()) );
}


//--------------------------------- Callback Functions --------------------------------------------

//------------------------------------------------------------------
// Brings up a file chooser and then loads the chosen image
// This is called by the UI when the load image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_load_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}


//------------------------------------------------------------------
// Brings up a file chooser and then saves the painted image
// This is called by the UI when the save image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_save_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Save File?", "*.bmp", "save.bmp" );
	if (newfile != NULL) {
		pDoc->saveImage(newfile);
	}
}

//-------------------------------------------------------------
// Brings up the paint dialog
// This is called by the UI when the brushes menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_brushes(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_brushDialog->show();
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();

	pDoc->clearCanvas();
}

//------------------------------------------------------------
// Causes the Impressionist program to exit
// Called by the UI when the quit menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_exit(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_mainWindow->hide();
	whoami(o)->m_brushDialog->hide();

}



//-----------------------------------------------------------
// Brings up an about dialog box
// Called by the UI when the about menu item is chosen
//-----------------------------------------------------------
void ImpressionistUI::cb_about(Fl_Menu_* o, void* v) 
{
	fl_message("Impressionist FLTK version for CS341, Spring 2002");
}

//------- UI should keep track of the current for all the controls for answering the query from Doc ---------
//-------------------------------------------------------------
// Sets the type of brush to use to the one chosen in the brush 
// choice.  
// Called by the UI when a brush is chosen in the brush choice
//-------------------------------------------------------------
void ImpressionistUI::cb_brushChoice(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc=pUI->getDocument();

	int type=(int)v;
	cout<<"sfdfgdsfgsefgsdfgsdfgsfgsdfgaf"<<type;
	pUI->curAlg = pUI->algorithmSet[type];
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas button is pushed
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->clearCanvas();
}


//-----------------------------------------------------------
// Updates the brush size to use from the value of the size
// slider
// Called by the UI when the size slider is moved
//-----------------------------------------------------------
void ImpressionistUI::cb_sizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nSize=int( ((Fl_Slider *)o)->value() ) ;
}

//---------------------------------- per instance functions --------------------------------------

//------------------------------------------------
// Return the ImpressionistDoc used
//------------------------------------------------
ImpressionistDoc* ImpressionistUI::getDocument()
{
	return m_pDoc;
}

//------------------------------------------------
// Draw the main window
//------------------------------------------------
void ImpressionistUI::show() {
	m_mainWindow->show();
	//m_paintView->show();
	//m_origView->show();
}

//------------------------------------------------
// Change the paint and original window sizes to 
// w by h
//------------------------------------------------
void ImpressionistUI::resize_windows(int w, int h) {
	m_paintView->size(w,h);
	m_origView->size(w,h);
}

//------------------------------------------------ 
// Set the ImpressionistDoc used by the UI to 
// communicate with the brushes 
//------------------------------------------------
void ImpressionistUI::setDocument(ImpressionistDoc* doc)
{
	m_pDoc = doc;

	//m_origView->m_pDoc = doc;
	//m_paintView->m_pDoc = doc;
}

//------------------------------------------------
// Return the brush size
//------------------------------------------------
int ImpressionistUI::getSize()
{
	return m_nSize;
}

//-------------------------------------------------
// Set the brush size
//-------------------------------------------------
void ImpressionistUI::setSize( int size )
{
	m_nSize=size;

	if (size<=40) 
		m_BrushSizeSlider->value(m_nSize);
}

// Main menu definition
Fl_Menu_Item ImpressionistUI::menuitems[] = {
	{ "&File",		0, 0, 0, FL_SUBMENU },
	//{ "&Load Image...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load_image },
		//{ "&Save Image...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save_image },
		{ "&Parameters...",	FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushes }, 
		//{ "&Clear Canvas", FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_clear_canvas, 0, FL_MENU_DIVIDER },
		
		{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
		{ 0 },

	{ "&Help",		0, 0, 0, FL_SUBMENU },
		{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ 0 }
};

// Brush choice menu definition
Fl_Menu_Item ImpressionistUI::brushTypeMenu[NUM_BRUSH_TYPE+1] = {
  {"DB-LSH",			FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_POINTS},
  {"FB-LSH",				FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_LINES},
  {"LCCS-LSH",				FL_ALT + 'l', (Fl_Callback*)ImpressionistUI::cb_brushChoice, (void*)BRUSH_LINES},
  {"PM-LSH",				FL_ALT + 'l', (Fl_Callback*)ImpressionistUI::cb_brushChoice, (void*)BRUSH_LINES},
  {"R2-LSH",				FL_ALT + 'l', (Fl_Callback*)ImpressionistUI::cb_brushChoice, (void*)BRUSH_LINES},
  {"VHP",				FL_ALT + 'l', (Fl_Callback*)ImpressionistUI::cb_brushChoice, (void*)BRUSH_LINES},
 /* {"Circles",			FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_CIRCLES},
  {"Scattered Points",	FL_ALT+'q', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_POINTS},
  {"Scattered Lines",	FL_ALT+'m', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_LINES},
  {"Scattered Circles",	FL_ALT+'d', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_CIRCLES},*/
  {0}
};



//----------------------------------------------------
// Constructor.  Creates all of the widgets.
// Add new widgets here
//----------------------------------------------------
ImpressionistUI::ImpressionistUI() {
	// Create the main window
	m_mainWindow = new Fl_Window(600, 300, "UROP demo");
		m_mainWindow->user_data((void*)(this));	// record self to be used by static callback functions
		// install menu bar
		m_menubar = new Fl_Menu_Bar(0, 0, 600, 25);
		m_menubar->menu(menuitems);

		// Create a group that will hold two sub windows inside the main
		// window
		Fl_Group* group = new Fl_Group(0, 25, 600, 275);

			//// install paint view window
			//m_paintView = new PaintView(300, 25, 300, 275, "This is the paint view");//0jon
			//m_paintView->box(FL_DOWN_FRAME);

			//// install original view window
			//m_origView = new OriginalView(0, 25, 300, 275, "This is the orig view");//300jon
			//m_origView->box(FL_DOWN_FRAME);
			//m_origView->deactivate();
			pText = new Fl_Text_Editor(50, 50, 500, 240);
			pBuff = new Fl_Text_Buffer();
			pText->buffer(pBuff);
			pBuff->text("DEMO");
		group->end();
		Fl_Group::current()->resizable(group);
    m_mainWindow->end();

	// init values

	m_nSize = 10;

	// brush dialog definition
	m_brushDialog = new Fl_Window(400, 325, "Algorithm Dialog");
		// Add a brush type choice to the dialog
		m_BrushTypeChoice = new Fl_Choice(65,10,150,25,"&Algorithm");
		m_BrushTypeChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushTypeChoice->menu(brushTypeMenu);
		m_BrushTypeChoice->callback(cb_brushChoice);

		m_ClearCanvasButton = new Fl_Button(240,10,150,25,"&Search");
		m_ClearCanvasButton->user_data((void*)(this));
		m_ClearCanvasButton->callback(cb_printOut);


		// Add brush size slider to the dialog 
		cSlider = new Fl_Value_Slider(10, 80, 300, 20, "c");
		cSlider->user_data((void*)(this));	// record self to be used by static callback functions
		cSlider->type(FL_HOR_NICE_SLIDER);
		cSlider->labelfont(FL_COURIER);
		cSlider->labelsize(12);
		cSlider->minimum(0);
		cSlider->maximum(2);
		cSlider->step(0.1);
		cSlider->value(1.5);
		cSlider->align(FL_ALIGN_RIGHT);
		cSlider->callback(cb_cSlides);


		kSlider = new Fl_Value_Slider(10, 110, 300, 20, "k");
		kSlider->user_data((void*)(this));	// record self to be used by static callback functions
		kSlider->type(FL_HOR_NICE_SLIDER);
		kSlider->labelfont(FL_COURIER);
		kSlider->labelsize(12);
		kSlider->minimum(1);
		kSlider->maximum(100);
		kSlider->step(1);
		kSlider->value(50);
		kSlider->align(FL_ALIGN_RIGHT);
		kSlider->callback(cb_kSlides);

		LSlider = new Fl_Value_Slider(10, 140, 300, 20, "L");
		LSlider->user_data((void*)(this));	// record self to be used by static callback functions
		LSlider->type(FL_HOR_NICE_SLIDER);
		LSlider->labelfont(FL_COURIER);
		LSlider->labelsize(12);
		LSlider->minimum(1);
		LSlider->maximum(20);
		LSlider->step(1);
		LSlider->value(5);
		LSlider->align(FL_ALIGN_RIGHT);
		LSlider->callback(cb_LSlides);

		// Add AlphaValue slider to the dialog
		KSlider = new Fl_Value_Slider(10, 170, 300, 20, "K");
		KSlider->user_data((void*)(this));	// record self to be used by static callback functions
		KSlider->type(FL_HOR_NICE_SLIDER);
		KSlider->labelfont(FL_COURIER);
		KSlider->labelsize(12);
		KSlider->minimum(1);
		KSlider->maximum(20);
		KSlider->step(1);
		KSlider->value(10);
		KSlider->align(FL_ALIGN_RIGHT);
		KSlider->callback(cb_KSlides);

		// Add Auto Paint Space slider to the dialog
		betaSlider = new Fl_Value_Slider(10, 200, 300, 20, "beta");
		betaSlider->user_data((void*)(this));	// record self to be used by static callback functions
		betaSlider->type(FL_HOR_NICE_SLIDER);
		betaSlider->labelfont(FL_COURIER);
		betaSlider->labelsize(12);
		betaSlider->minimum(0.1);
		betaSlider->maximum(2);
		betaSlider->step(0.1);
		betaSlider->value(0.1);
		betaSlider->align(FL_ALIGN_RIGHT);
		betaSlider->callback(cb_betaSlides);

		RminSlider = new Fl_Value_Slider(10, 230, 300, 20, "Rmin");
		RminSlider->user_data((void*)(this));	// record self to be used by static callback functions
		RminSlider->type(FL_HOR_NICE_SLIDER);
		RminSlider->labelfont(FL_COURIER);
		RminSlider->labelsize(12);
		RminSlider->minimum(0.1);
		RminSlider->maximum(2);
		RminSlider->step(0.1);
		RminSlider->value(1.0f);
		RminSlider->align(FL_ALIGN_RIGHT);
		RminSlider->callback(cb_betaSlides);

		//cInput = new Fl_Input(10, 250, 300, 20, "c");
		//cInput->user_data((void*)(this));	// record self to be used by static callback functions
		//cInput->labelfont(FL_COURIER);
		//cInput->labelsize(12);
		//cSlider->value(m_nSize);
		//cSlider->align(FL_ALIGN_RIGHT);
		//cSlider->callback(cb_cSlides);
	


    m_brushDialog->end();	

}

void ImpressionistUI::cb_cSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->c = int(((Fl_Slider*)o)->value());
}
void ImpressionistUI::cb_kSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->k = int(((Fl_Slider*)o)->value());
}

void ImpressionistUI::cb_LSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->L = int(((Fl_Slider*)o)->value());
}

void ImpressionistUI::cb_KSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->K = int(((Fl_Slider*)o)->value());
}

void ImpressionistUI::cb_betaSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->beta = int(((Fl_Slider*)o)->value());
}

void ImpressionistUI::cb_RminSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->Rmin = int(((Fl_Slider*)o)->value());
}

void ImpressionistUI::cb_printOut(Fl_Widget* o, void* v) {
	querry(((ImpressionistUI*)(o->user_data())));
	((ImpressionistUI*)(o->user_data()))->pBuff->text(((ImpressionistUI*)(o->user_data()))->printInfo.c_str());
}

//void ImpressionistUI::cb_cInput(Fl_Widget* o, void* v)
//{
//	((ImpressionistUI*)(o->user_data()))->c = int(atoi(((Fl_Input*)o)->value()));
//	//int i = atoi(str.c_str());
//}