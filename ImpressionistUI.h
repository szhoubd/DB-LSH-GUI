//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Text_Editor.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "main.h"
using namespace std;
class ImpressionistUI {
public:
	
	ImpressionistUI();
	string algorithmSet[3] = {"DB-LSH","XXX","XXX"};

	int		m_nSize;
	float c = 1.5;
	float k = 50;
	float  L = 5;
	float K = 10;
	float beta = 0.1;
	float Rmin = 1.0f;
	string curAlg = algorithmSet[0];
	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
	Fl_Text_Editor*  pText;
	Fl_Text_Buffer* pBuff;
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
	Fl_Slider* m_BrushSizeSlider;
	Fl_Slider*			cSlider;
	Fl_Slider*			kSlider;
	Fl_Slider*			LSlider;
	Fl_Slider*		KSlider;
	Fl_Slider*		betaSlider;
	Fl_Slider*		RminSlider;
	Fl_Button*          m_ClearCanvasButton;
	Fl_Input* cInput;
	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);
	
	string printInfo;
private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	
	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void	cb_cSlides(Fl_Widget* o, void* v);
	static void	cb_kSlides(Fl_Widget* o, void* v);
	static void	cb_LSlides(Fl_Widget* o, void* v);
	static void	cb_KSlides(Fl_Widget* o, void* v);
	static void	cb_betaSlides(Fl_Widget* o, void* v);
	static void	cb_RminSlides(Fl_Widget* o, void* v);
	static void cb_printOut(Fl_Widget* o, void* v);


	//static void	cb_cInput(Fl_Widget* o, void* v);
	/*static void	cb_kInput(Fl_Widget* o, void* v);
	static void	cb_LInput(Fl_Widget* o, void* v);
	static void	cb_KInput(Fl_Widget* o, void* v);
	static void	cb_betaInput(Fl_Widget* o, void* v);
	static void	cb_RminInput(Fl_Widget* o, void* v);*/

};

#endif
