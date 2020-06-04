#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 5

Menu_Page_t MCU;

static Page_Screen_t MCU_Screen_List[SCREENS_IN_PAGE];

static void Show_MCU_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">STM32F0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" STM32F1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" STM32F4", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_MCU_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" STM32F0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">STM32F1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" STM32F4", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_MCU_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" STM32F0", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" STM32F1", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">STM32F4", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_MCU_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" STM32F1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" STM32F4", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">STM32F7", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_MCU_Screen4()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" STM32F4", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" STM32F7", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}


static uint8_t Run_MCU_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*STM32F0*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*STM32F0*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*STM32F0*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_MCU_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*STM32F1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*STM32F1*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*STM32F1*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_MCU_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*STM32F4*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*STM32F4*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*STM32F4*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_MCU_Screen3(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*STM32F7*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("*STM32F7*", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("*STM32F7*", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_MCU_Screen4(Menu_Event_t *event)
{
    Menu_Change_Page(0, 2);
    return 0;
}

void Menu_Add_MCU_Page()
{
    MCU_Screen_List[0].Show_Page_Screen = Show_MCU_Screen0;
    MCU_Screen_List[0].Enter_Page_Screen = Run_MCU_Screen0;

    MCU_Screen_List[1].Show_Page_Screen = Show_MCU_Screen1;
    MCU_Screen_List[1].Enter_Page_Screen = Run_MCU_Screen1;

    MCU_Screen_List[2].Show_Page_Screen = Show_MCU_Screen2;
    MCU_Screen_List[2].Enter_Page_Screen = Run_MCU_Screen2;

    MCU_Screen_List[3].Show_Page_Screen = Show_MCU_Screen3;
    MCU_Screen_List[3].Enter_Page_Screen = Run_MCU_Screen3;

    MCU_Screen_List[4].Show_Page_Screen = Show_MCU_Screen4;
    MCU_Screen_List[4].Enter_Page_Screen = Run_MCU_Screen4;

    MCU.Page_Screen_List = MCU_Screen_List;
    MCU.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&MCU);
}
