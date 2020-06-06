#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 4

Menu_Page_t UART_page;

static Page_Item_t UART_Screen_List[ITEMS_IN_PAGE];

static void Show_UART_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">UART1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" UART2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" UART3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_UART_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" UART1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">UART2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" UART3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_UART_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" UART1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" UART2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">UART3", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_UART_Screen3()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" UART2", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" UART3", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_UART_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*UART1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("Baud:", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("9600", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_UART_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*UART2*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("Baud:", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("38400", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_UART_Screen2(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*UART3*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("Baud:", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("115200", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_UART_Screen3(Menu_Event_t *event)
{
    Menu_Change_Page(0, 7);
    return 0;
}

void Menu_Add_UART_Page()
{
    UART_Screen_List[0].Show_Page_Item = Show_UART_Screen0;
    UART_Screen_List[0].Page_Item_Callback = Run_UART_Screen0;

    UART_Screen_List[1].Show_Page_Item = Show_UART_Screen1;
    UART_Screen_List[1].Page_Item_Callback = Run_UART_Screen1;

    UART_Screen_List[2].Show_Page_Item = Show_UART_Screen2;
    UART_Screen_List[2].Page_Item_Callback = Run_UART_Screen2;

    UART_Screen_List[3].Show_Page_Item = Show_UART_Screen3;
    UART_Screen_List[3].Page_Item_Callback = Run_UART_Screen3;

    UART_page.Page_Item_List = UART_Screen_List;
    UART_page.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&UART_page);
}
