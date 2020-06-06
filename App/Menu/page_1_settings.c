#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 5

Menu_Page_t Settings;

static Page_Item_t Settings_Item_List[ITEMS_IN_PAGE];

static void Show_Settings_Item0()
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

static void Show_Settings_Item1()
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

static void Show_Settings_Item2()
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

static void Show_Settings_Item3()
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

static void Show_Settings_Item4()
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

static uint8_t Run_Settings_Item0(Menu_Event_t *event)
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

static uint8_t Run_Settings_Item1(Menu_Event_t *event)
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

static uint8_t Run_Settings_Item2(Menu_Event_t *event)
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

static uint8_t Run_Settings_Item3(Menu_Event_t *event)
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

static uint8_t Run_Settings_Item4(Menu_Event_t *event)
{
    Menu_Change_Page(0, 1);
    return 0;
}

void Menu_Add_Settings_Page()
{
    Settings_Item_List[0].Show_Page_Item = Show_Settings_Item0;
    Settings_Item_List[0].Page_Item_Callback = Run_Settings_Item0;

    Settings_Item_List[1].Show_Page_Item = Show_Settings_Item1;
    Settings_Item_List[1].Page_Item_Callback = Run_Settings_Item1;

    Settings_Item_List[2].Show_Page_Item = Show_Settings_Item2;
    Settings_Item_List[2].Page_Item_Callback = Run_Settings_Item2;

    Settings_Item_List[3].Show_Page_Item = Show_Settings_Item3;
    Settings_Item_List[3].Page_Item_Callback = Run_Settings_Item3;

    Settings_Item_List[4].Show_Page_Item = Show_Settings_Item4;
    Settings_Item_List[4].Page_Item_Callback = Run_Settings_Item4;

    Settings.Page_Item_List = Settings_Item_List;
    Settings.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&Settings);
}
