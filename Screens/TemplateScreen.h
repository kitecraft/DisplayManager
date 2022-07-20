#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>


class TemplateScreen
{
private:
	TFT_eSPI* _tft;

public:
	TemplateScreen(TFT_eSPI* tft);
	~TemplateScreen();

	void UpdateScreen(int inKey, char* value);
	void UpdateScreenOnInterval();

	void HandleTouch(int x, int y);

};


static TemplateScreen* templateScreen = nullptr;
static void Create_TemplateScreen(TFT_eSPI* TFT) 
{
	templateScreen = new OTAScreen(TFT);
}

static void Destroy_TemplateScreen()
{
	if (templateScreen != nullptr)
	{
		delete(templateScreen);
		templateScreen = nullptr;
	}
}

static void Update_TemplateScreen(int inKey, char* value)
{
	templateScreen->UpdateScreen(inKey, value);
}

static void Update_OTAScreen_OnInterval()
{
	otaScreen->UpdateScreenOnInterval();
}
*
static void Handle_OTAScreen_Touch(int x, int y)
{
	otaScreen->HandleTouch(x, y);
}


