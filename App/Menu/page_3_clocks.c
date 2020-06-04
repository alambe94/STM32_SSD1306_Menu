#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 4

Menu_Page_t Clocks;

static Page_Screen_t Clocks_Screen_List[SCREENS_IN_PAGE];

static void Show_Clocks_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">Clock1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Clock2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Clock3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Clocks_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clock1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">Clock2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Clock3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Clocks_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clock1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Clock2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Clock3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Clocks_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clock2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Clock3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Clocks_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*TIME*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "Count = %d", count);
    count++;
    ssd1306_WriteString(buff, Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Clocks_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*CLOCK2*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*CLOCK2*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*CLOCK2*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Clocks_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*CLOCK3*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*CLOCK3*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*CLOCK3*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Clocks_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(0, 4);
    return 0;
}

void Menu_Add_Clocks_Page()
{
    Clocks_Screen_List[0].Show_Page_Screen = Show_Clocks_Screen0;
    Clocks_Screen_List[0].Enter_Page_Screen = Run_Clocks_Screen0;

    Clocks_Screen_List[1].Show_Page_Screen = Show_Clocks_Screen1;
    Clocks_Screen_List[1].Enter_Page_Screen = Run_Clocks_Screen1;

    Clocks_Screen_List[2].Show_Page_Screen = Show_Clocks_Screen2;
    Clocks_Screen_List[2].Enter_Page_Screen = Run_Clocks_Screen2;

    Clocks_Screen_List[3].Show_Page_Screen = Show_Clocks_Screen3;
    Clocks_Screen_List[3].Enter_Page_Screen = Run_Clocks_Screen3;

    Clocks.Page_Screen_List = Clocks_Screen_List;
    Clocks.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Clocks);
}
