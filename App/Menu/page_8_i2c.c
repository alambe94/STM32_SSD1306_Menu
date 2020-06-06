#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 3

Menu_Page_t I2C_Page;

static Page_Item_t I2C_Screen_List[ITEMS_IN_PAGE];

static void Show_I2C_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">I2C1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" I2C2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_I2C_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" I2C1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">I2C2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(" Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_I2C_Screen2()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" I2C1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" I2C2", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_I2C_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*I2C1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("CLK:", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("100Khz", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_I2C_Screen1(Menu_Event_t *event)
{
    uint8_t xreturn = 1;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*I2C2*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString("CLK:", Font_11x18, White);
    ssd1306_SetCursor(0, 40);
    ssd1306_WriteString("400Khz", Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_I2C_Screen2(Menu_Event_t *event)
{
    Menu_Change_Page(0, 8);
    return 0;
}

void Menu_Add_I2C_Page()
{
    printf("Menu_I2C_Init\n");
    I2C_Screen_List[0].Show_Page_Item = Show_I2C_Screen0;
    I2C_Screen_List[0].Page_Item_Callback = Run_I2C_Screen0;

    I2C_Screen_List[1].Show_Page_Item = Show_I2C_Screen1;
    I2C_Screen_List[1].Page_Item_Callback = Run_I2C_Screen1;

    I2C_Screen_List[2].Show_Page_Item = Show_I2C_Screen2;
    I2C_Screen_List[2].Page_Item_Callback = Run_I2C_Screen2;

    I2C_Page.Page_Item_List = I2C_Screen_List;
    I2C_Page.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&I2C_Page);
}
