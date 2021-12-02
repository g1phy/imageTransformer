//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Mask.hpp>
#include <iostream>

using namespace std;

enum filterColor {
	f_none = 0,
	green,
	lightblue,
	raspberry,
	inverse
};

enum Reflections {
	r_none = 0,
	left_right,
	top_bottom,
	both
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenPictureDialog *OpenPictureDialog1;
	TSavePictureDialog *SavePictureDialog1;
	TImage *Image1;
	TButton *Button1;
	TLabel *Label1;
	TPanel *Panel1;
	TPanel *Settings;
	TImage *Image2;
	TRadioGroup *Reflection;
	TLabeledEdit *ScalesCoeff;
	TComboBox *FilterColor;
	TScrollBox *ScrollBox1;
	TButton *setCoeff;
	TButton *Button2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FilterColorChange(TObject *Sender);
	void __fastcall setCoeffClick(TObject *Sender);
	void __fastcall ReflectionClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);



private:	// User declarations
	filterColor currentFilterColor = filterColor::f_none;
	double coeff = 1.;
	Reflections currentReflection = Reflections::r_none;
	void setAllChanges();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
