#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 4

Menu_Page_t ADC_Page;

static Page_Screen_t ADC_Screen_List[SCREENS_IN_PAGE];

static void Show_ADC_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">ADC1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" ADC2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" ADC3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_ADC_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" ADC1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">ADC2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" ADC3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_ADC_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" ADC1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" ADC2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">ADC3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_ADC_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" ADC2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" ADC3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_ADC_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*ADC1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("512", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_ADC_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*ADC2*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("728", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_ADC_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*ADC3*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("1023", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_ADC_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(0, 6);
    return 0;
}

void Menu_Add_ADC_Page()
{
    ADC_Screen_List[0].Show_Page_Screen = Show_ADC_Screen0;
    ADC_Screen_List[0].Enter_Page_Screen = Run_ADC_Screen0;

    ADC_Screen_List[1].Show_Page_Screen = Show_ADC_Screen1;
    ADC_Screen_List[1].Enter_Page_Screen = Run_ADC_Screen1;

    ADC_Screen_List[2].Show_Page_Screen = Show_ADC_Screen2;
    ADC_Screen_List[2].Enter_Page_Screen = Run_ADC_Screen2;

    ADC_Screen_List[3].Show_Page_Screen = Show_ADC_Screen3;
    ADC_Screen_List[3].Enter_Page_Screen = Run_ADC_Screen3;

    ADC_Page.Page_Screen_List = ADC_Screen_List;
    ADC_Page.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&ADC_Page);
}
