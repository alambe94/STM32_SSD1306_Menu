#include "stdio.h"
#include "menu_core.h"
#include "menu_Page0.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 5

Menu_Page_t Page0;

static Page_Screen_t Page0_Screen_List[SCREENS_IN_PAGE];

static void Show_Page0_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">Item0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Item1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Item2", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page0_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Item0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">Item1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Item2", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page0_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Item0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Item1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Item2", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page0_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Item1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Item2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Item3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page0_Screen4()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Item2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Item3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Page2", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Loop_Page0_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**Screen0**", Font_7x10, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "Count = %d", count);
    count++;
    ssd1306_WriteString(buff, Font_7x10, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Loop_Page0_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**Screen1**", Font_7x10, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "Count = %d", count);
    count++;
    ssd1306_WriteString(buff, Font_7x10, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Loop_Page0_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**Screen2**", Font_7x10, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "Count = %d", count);
    count++;
    ssd1306_WriteString(buff, Font_7x10, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Loop_Page0_Screen3(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**Screen3**", Font_7x10, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "Count = %d", count);
    count++;
    ssd1306_WriteString(buff, Font_7x10, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Loop_Page0_Screen4(Menu_Event_t *event)
{
    Menu_Change_Page(1, 0);
    return 0;
}

void Menu_Page0_Init()
{
    printf("Menu_Page0_Init\n");

    Page0_Screen_List[0].Show_Page_Screen = Show_Page0_Screen0;
    Page0_Screen_List[0].Enter_Page_Screen = Loop_Page0_Screen0;

    Page0_Screen_List[1].Show_Page_Screen = Show_Page0_Screen1;
    Page0_Screen_List[1].Enter_Page_Screen = Loop_Page0_Screen1;

    Page0_Screen_List[2].Show_Page_Screen = Show_Page0_Screen2;
    Page0_Screen_List[2].Enter_Page_Screen = Loop_Page0_Screen2;

    Page0_Screen_List[3].Show_Page_Screen = Show_Page0_Screen3;
    Page0_Screen_List[3].Enter_Page_Screen = Loop_Page0_Screen3;

    Page0_Screen_List[4].Show_Page_Screen = Show_Page0_Screen4;
    Page0_Screen_List[4].Enter_Page_Screen = Loop_Page0_Screen4;

    Page0.Page_Screen_List = Page0_Screen_List;
    Page0.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Page0);
}
