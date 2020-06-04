#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 5

Menu_Page_t Settings;

static Page_Screen_t Settings_Screen_List[SCREENS_IN_PAGE];

static void Show_Settings_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">SET1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" SET2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" SET3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Settings_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" SET1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">SET2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" SET3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Settings_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" SET1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" SET2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">SET3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Settings_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" SET2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" SET3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">SET4", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Settings_Screen4()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" SET3", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" SET4", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Settings_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*SET1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*SET1*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*SET1*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Settings_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*SET2*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*SET2*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*SET2*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Settings_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*SET3*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*SET3*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*SET3*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Settings_Screen3(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*SET4*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*SET4*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*SET4*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Settings_Screen4(Menu_Event_t *event)
{
    Menu_Change_Page(0, 1);
    return 0;
}

void Menu_Add_Settings_Page()
{
    Settings_Screen_List[0].Show_Page_Screen = Show_Settings_Screen0;
    Settings_Screen_List[0].Enter_Page_Screen = Run_Settings_Screen0;

    Settings_Screen_List[1].Show_Page_Screen = Show_Settings_Screen1;
    Settings_Screen_List[1].Enter_Page_Screen = Run_Settings_Screen1;

    Settings_Screen_List[2].Show_Page_Screen = Show_Settings_Screen2;
    Settings_Screen_List[2].Enter_Page_Screen = Run_Settings_Screen2;

    Settings_Screen_List[3].Show_Page_Screen = Show_Settings_Screen3;
    Settings_Screen_List[3].Enter_Page_Screen = Run_Settings_Screen3;

    Settings_Screen_List[4].Show_Page_Screen = Show_Settings_Screen4;
    Settings_Screen_List[4].Enter_Page_Screen = Run_Settings_Screen4;

    Settings.Page_Screen_List = Settings_Screen_List;
    Settings.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Settings);
}
