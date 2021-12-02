//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	OpenPictureDialog1 -> InitialDir = ExtractFilePath(ParamStr(0));
	SavePictureDialog1 -> InitialDir = OpenPictureDialog1 -> InitialDir;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(OpenPictureDialog1->Execute()) {
		Label1->Caption = "Успешно загружено";
		Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
		Settings->Visible = true;
        Button2->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FilterColorChange(TObject *Sender)
{
	currentFilterColor = static_cast <filterColor> (FilterColor->ItemIndex);
    setAllChanges();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setCoeffClick(TObject *Sender)
{
	coeff = StrToFloat(ScalesCoeff->Text);
	setAllChanges();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReflectionClick(TObject *Sender)
{
	currentReflection = static_cast <Reflections> (Reflection->ItemIndex);
	setAllChanges();
}

void TForm1::setAllChanges() {
	Graphics::TBitmap* bmp = new Graphics::TBitmap();
	bmp->LoadFromFile(OpenPictureDialog1->FileName);
	// Отражение
	if(currentReflection == Reflections::left_right || currentReflection == Reflections::both) {
		for(int i = 0; i < bmp->Width / 2; ++ i)
			for(int j = 0; j < bmp->Height; ++ j) {
				TColor temp = bmp->Canvas->Pixels[i][j];
				bmp->Canvas->Pixels[i][j] = bmp->Canvas->Pixels[bmp->Width - 1 - i][j];
				bmp->Canvas->Pixels[bmp->Width - 1 - i][j] = temp;
			}
	}
	if(currentReflection == Reflections::top_bottom || currentReflection == Reflections::both) {
		for(int i = 0; i < bmp->Width; ++ i)
			for(int j = 0; j < bmp->Height / 2; ++ j) {
				TColor temp = bmp->Canvas->Pixels[i][j];
				bmp->Canvas->Pixels[i][j] = bmp->Canvas->Pixels[i][bmp->Height - 1 - j];
				bmp->Canvas->Pixels[i][bmp->Height - 1 - j] = temp;
			}
	}

	//Фильтр
	if(currentFilterColor == filterColor::green || currentFilterColor == filterColor::lightblue
		|| currentFilterColor == filterColor::raspberry) {
			Graphics::TBitmap *Ris3 = new Graphics::TBitmap();
			Ris3 -> Width = bmp->Width;
			Ris3 -> Height = bmp->Height;

			if(currentFilterColor == filterColor::green)
				Ris3 -> Canvas -> Brush -> Color =  TColor(RGB(0, 255, 0));
			else if(currentFilterColor == filterColor::lightblue)
				Ris3 -> Canvas -> Brush -> Color =  TColor(RGB(0, 255, 255));
			else Ris3 -> Canvas -> Brush -> Color =  TColor(RGB(255, 0, 255));
			Ris3 -> Canvas -> Rectangle(Bounds(0, 0, bmp->Width, bmp->Height));
			bmp -> Canvas -> CopyMode = cmSrcAnd;
			bmp -> Canvas -> Draw(0, 0, Ris3);
			bmp -> Canvas -> CopyMode = cmSrcCopy;
			delete Ris3;
	} else if(currentFilterColor == filterColor::inverse) {
			Graphics::TBitmap *Ris3 = new Graphics::TBitmap();
			Ris3 -> Width = bmp->Width;
			Ris3 -> Height = bmp->Height;
			bmp -> Canvas -> CopyMode = cmSrcInvert;
			bmp -> Canvas -> Draw(0, 0, Ris3);
			bmp -> Canvas -> CopyMode = cmSrcCopy;
			delete Ris3;
	}

	TRect Pr2;
	int neww, newh;
	neww = round(bmp->Width * coeff);
	newh = round(bmp->Height * coeff);
	Pr2 = Bounds(0, 0, neww, newh);
	Graphics::TBitmap *Ris2  = new Graphics::TBitmap();
	Ris2 -> Width = neww;
	Ris2 -> Height = newh;
	Ris2 -> Canvas -> StretchDraw(Pr2, bmp);
	Image2 -> Picture -> Assign(Ris2);

	Image2->Picture->Assign(Ris2);
	delete bmp;
	delete Ris2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 if(SavePictureDialog1->Execute()) {
         Image2->Picture->SaveToFile(SavePictureDialog1->FileName);
     }
}
//---------------------------------------------------------------------------

