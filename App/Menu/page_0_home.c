#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 10

Menu_Page_t Home;

static Page_Item_t Home_Item_List[ITEMS_IN_PAGE];

static void Show_Home_Item0()
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

static void Show_Home_Item1()
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

static void Show_Home_Item2()
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

static void Show_Home_Item3()
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

static void Show_Home_Item4()
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

static void Show_Home_Item5()
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

static void Show_Home_Item6()
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

static void Show_Home_Item7()
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

static void Show_Home_Item8()
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

static void Show_Home_Item9()
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

static uint8_t Run_Home_Item0(Menu_Event_t *event)
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

    if (event->Enter_Button_Clicks == 1)
    {
        xreturn = 0;
    }
    /* if clicked twice, directly jump to page_9_encoder */
    else if (event->Enter_Button_Clicks == 2)
    {
        Menu_Change_Page(9, 0);
        xreturn = 1;
    }

    return xreturn;
}

static uint8_t Run_Home_Item1(Menu_Event_t *event)
{
    Menu_Change_Page(1, 0);
    return 0;
}

static uint8_t Run_Home_Item2(Menu_Event_t *event)
{
    Menu_Change_Page(2, 0);
    return 0;
}

static uint8_t Run_Home_Item3(Menu_Event_t *event)
{
    Menu_Change_Page(3, 0);
    return 0;
}

static uint8_t Run_Home_Item4(Menu_Event_t *event)
{
    Menu_Change_Page(4, 0);
    return 0;
}

static uint8_t Run_Home_Item5(Menu_Event_t *event)
{
    Menu_Change_Page(5, 0);
    return 0;
}

static uint8_t Run_Home_Item6(Menu_Event_t *event)
{
    Menu_Change_Page(6, 0);
    return 0;
}

static uint8_t Run_Home_Item7(Menu_Event_t *event)
{
    Menu_Change_Page(7, 0);
    return 0;
}

static uint8_t Run_Home_Item8(Menu_Event_t *event)
{
    Menu_Change_Page(8, 0);
    return 0;
}

static uint8_t Run_Home_Item9(Menu_Event_t *event)
{
    Menu_Change_Page(9, 0);
    return 0;
}

/* root menu */
void Menu_Add_Home_Page()
{
    printf("Menu_Home_Init\n");

    Home_Item_List[0].Show_Page_Item = Show_Home_Item0;
    Home_Item_List[0].Page_Item_Callback = Run_Home_Item0;

    Home_Item_List[1].Show_Page_Item = Show_Home_Item1;
    Home_Item_List[1].Page_Item_Callback = Run_Home_Item1;

    Home_Item_List[2].Show_Page_Item = Show_Home_Item2;
    Home_Item_List[2].Page_Item_Callback = Run_Home_Item2;

    Home_Item_List[3].Show_Page_Item = Show_Home_Item3;
    Home_Item_List[3].Page_Item_Callback = Run_Home_Item3;

    Home_Item_List[4].Show_Page_Item = Show_Home_Item4;
    Home_Item_List[4].Page_Item_Callback = Run_Home_Item4;

    Home_Item_List[5].Show_Page_Item = Show_Home_Item5;
    Home_Item_List[5].Page_Item_Callback = Run_Home_Item5;

    Home_Item_List[6].Show_Page_Item = Show_Home_Item6;
    Home_Item_List[6].Page_Item_Callback = Run_Home_Item6;

    Home_Item_List[7].Show_Page_Item = Show_Home_Item7;
    Home_Item_List[7].Page_Item_Callback = Run_Home_Item7;

    Home_Item_List[8].Show_Page_Item = Show_Home_Item8;
    Home_Item_List[8].Page_Item_Callback = Run_Home_Item8;

    Home_Item_List[9].Show_Page_Item = Show_Home_Item9;
    Home_Item_List[9].Page_Item_Callback = Run_Home_Item9;

    Home.Page_Item_List = Home_Item_List;
    Home.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&Home);
}
