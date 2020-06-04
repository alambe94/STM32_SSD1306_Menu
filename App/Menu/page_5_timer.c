#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 4

Menu_Page_t Timer;

static Page_Screen_t Timer_Screen_List[SCREENS_IN_PAGE];

static void Show_Timer_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">TIM1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" TIM2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" TIM3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Timer_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" TIM1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">TIM2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" TIM3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Timer_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" TIM1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" TIM2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">TIM3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Timer_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" TIM2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" TIM3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Timer_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*TIM1*", Font_11x18, White);
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

static uint8_t Run_Timer_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**TIM12**", Font_11x18, White);
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

static uint8_t Run_Timer_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("**TIM3**", Font_11x18, White);
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

static uint8_t Run_Timer_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(0, 5);
    return 0;
}

void Menu_Add_Timer_Page()
{
    printf("Menu_Timer_Init\n");
    Timer_Screen_List[0].Show_Page_Screen = Show_Timer_Screen0;
    Timer_Screen_List[0].Enter_Page_Screen = Run_Timer_Screen0;

    Timer_Screen_List[1].Show_Page_Screen = Show_Timer_Screen1;
    Timer_Screen_List[1].Enter_Page_Screen = Run_Timer_Screen1;

    Timer_Screen_List[2].Show_Page_Screen = Show_Timer_Screen2;
    Timer_Screen_List[2].Enter_Page_Screen = Run_Timer_Screen2;

    Timer_Screen_List[3].Show_Page_Screen = Show_Timer_Screen3;
    Timer_Screen_List[3].Enter_Page_Screen = Run_Timer_Screen3;

    Timer.Page_Screen_List = Timer_Screen_List;
    Timer.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Timer);
}
