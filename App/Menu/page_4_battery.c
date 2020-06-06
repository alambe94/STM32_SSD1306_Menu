#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 3

Menu_Page_t Battery;

static Page_Item_t Battery_Screen_List[ITEMS_IN_PAGE];

static void Show_Battery_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">Volt", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" mAh", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Battery_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Volt", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">mAh", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Battery_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Volt", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" mAh", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Battery_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*VOLT*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("4.1V", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Battery_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*mAh*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("2600", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Battery_Screen2(Menu_Event_t *event)
{
    Menu_Change_Page(0, 4);
    return 0;
}

void Menu_Add_Battery_Page()
{
    printf("Menu_Battery_Init\n");
    Battery_Screen_List[0].Show_Page_Item = Show_Battery_Screen0;
    Battery_Screen_List[0].Page_Item_Callback = Run_Battery_Screen0;

    Battery_Screen_List[1].Show_Page_Item = Show_Battery_Screen1;
    Battery_Screen_List[1].Page_Item_Callback = Run_Battery_Screen1;

    Battery_Screen_List[2].Show_Page_Item = Show_Battery_Screen2;
    Battery_Screen_List[2].Page_Item_Callback = Run_Battery_Screen2;


    Battery.Page_Item_List = Battery_Screen_List;
    Battery.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&Battery);
}
