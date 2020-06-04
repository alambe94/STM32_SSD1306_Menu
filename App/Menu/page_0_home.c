#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define SCREENS_IN_PAGE 10

Menu_Page_t Home;

static Page_Screen_t Home_Screen_List[SCREENS_IN_PAGE];

static void Show_Home_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">Home", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Settings", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" MCU", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Home", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">Settings", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" MCU", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Home", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Settings", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">MCU", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Settings", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" MCU", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Clocks", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen4()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" MCU", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Clocks", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Battery", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen5()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Clocks", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Timer", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen6()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Battery", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Timer", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">ADC", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen7()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" Timer", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" ADC", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">UART", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen8()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" ADC", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" UART", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">I2C", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Home_Screen9()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" UART", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" I2C", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">ENC", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Home_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static uint8_t count = 0;
    char buff[20] = "";

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*HOME*", Font_11x18, White);
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

static uint8_t Run_Home_Screen1(Menu_Event_t *event)
{
    Menu_Change_Page(1, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen2(Menu_Event_t *event)
{
    Menu_Change_Page(2, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(3, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen4(Menu_Event_t *event)
{
    Menu_Change_Page(4, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen5(Menu_Event_t *event)
{
    Menu_Change_Page(5, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen6(Menu_Event_t *event)
{
    Menu_Change_Page(6, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen7(Menu_Event_t *event)
{
    Menu_Change_Page(7, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen8(Menu_Event_t *event)
{
    Menu_Change_Page(8, 0);
    /* if changing return 0 */
    return 0;
}

static uint8_t Run_Home_Screen9(Menu_Event_t *event)
{
    Menu_Change_Page(9, 0);
    /* if changing return 0 */
    return 0;
}

/* root menu */
void Menu_Add_Home_Page()
{
    printf("Menu_Home_Init\n");

    Home_Screen_List[0].Show_Page_Screen = Show_Home_Screen0;
    Home_Screen_List[0].Enter_Page_Screen = Run_Home_Screen0;

    Home_Screen_List[1].Show_Page_Screen = Show_Home_Screen1;
    Home_Screen_List[1].Enter_Page_Screen = Run_Home_Screen1;

    Home_Screen_List[2].Show_Page_Screen = Show_Home_Screen2;
    Home_Screen_List[2].Enter_Page_Screen = Run_Home_Screen2;

    Home_Screen_List[3].Show_Page_Screen = Show_Home_Screen3;
    Home_Screen_List[3].Enter_Page_Screen = Run_Home_Screen3;

    Home_Screen_List[4].Show_Page_Screen = Show_Home_Screen4;
    Home_Screen_List[4].Enter_Page_Screen = Run_Home_Screen4;

    Home_Screen_List[5].Show_Page_Screen = Show_Home_Screen5;
    Home_Screen_List[5].Enter_Page_Screen = Run_Home_Screen5;

    Home_Screen_List[6].Show_Page_Screen = Show_Home_Screen6;
    Home_Screen_List[6].Enter_Page_Screen = Run_Home_Screen6;

    Home_Screen_List[7].Show_Page_Screen = Show_Home_Screen7;
    Home_Screen_List[7].Enter_Page_Screen = Run_Home_Screen7;

    Home_Screen_List[8].Show_Page_Screen = Show_Home_Screen8;
    Home_Screen_List[8].Enter_Page_Screen = Run_Home_Screen8;

    Home_Screen_List[9].Show_Page_Screen = Show_Home_Screen9;
    Home_Screen_List[9].Enter_Page_Screen = Run_Home_Screen9;


    Home.Page_Screen_List = Home_Screen_List;
    Home.Screens_In_Page = SCREENS_IN_PAGE;
    Menu_Add_Page(&Home);
}
