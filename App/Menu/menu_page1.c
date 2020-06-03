#include "stdio.h"
#include "menu_core.h"
#include "menu_Page1.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 4

Menu_Page_t Page1;

static Page_Screen_t Page1_Screen_List[SCREENS_IN_PAGE];

static void Show_Page1_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">Clock", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Weld", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page1_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clock", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Weld", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page1_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clock", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Weld", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Page1_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Weld", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Loop_Page1_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*TIME*", Font_7x10, White);
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

static uint8_t Loop_Page1_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**VOLT**", Font_7x10, White);
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

static uint8_t Loop_Page1_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**WELD**", Font_7x10, White);
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

static uint8_t Loop_Page1_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(0, 4);
    return 0;
}

void Menu_Page1_Init()
{
    printf("Menu_Page1_Init\n");
    Page1_Screen_List[0].Show_Page_Screen = Show_Page1_Screen0;
    Page1_Screen_List[0].Enter_Page_Screen = Loop_Page1_Screen0;

    Page1_Screen_List[1].Show_Page_Screen = Show_Page1_Screen1;
    Page1_Screen_List[1].Enter_Page_Screen = Loop_Page1_Screen1;

    Page1_Screen_List[2].Show_Page_Screen = Show_Page1_Screen2;
    Page1_Screen_List[2].Enter_Page_Screen = Loop_Page1_Screen2;

    Page1_Screen_List[3].Show_Page_Screen = Show_Page1_Screen3;
    Page1_Screen_List[3].Enter_Page_Screen = Loop_Page1_Screen3;

    Page1.Page_Screen_List = Page1_Screen_List;
    Page1.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Page1);
}
