#include "stdio.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

#define ITEMS_IN_PAGE 2

Menu_Page_t Encoder;

static Page_Item_t Encoder_Screen_List[ITEMS_IN_PAGE];

static void Show_Encoder_Screen0()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(">ENC1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(" Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static void Show_Encoder_Screen1()
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(" ENC1", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(">Back", Font_11x18, White);
    ssd1306_UpdateScreen();
}

static uint8_t Run_Encoder_Screen0(Menu_Event_t *event)
{
    uint8_t xreturn = 1;
    static int16_t count = 0;
    char buff[20] = "";

    count += event->Encoder_Count;

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("*ENC1*", Font_11x18, White);
    ssd1306_SetCursor(0, 20);
    snprintf(buff, sizeof(buff), "  %d", count);
    ssd1306_WriteString(buff, Font_11x18, White);
    ssd1306_UpdateScreen();

    if (event->Enter_Button_Clicks)
    {
        xreturn = 0;
    }

    return xreturn;
}

static uint8_t Run_Encoder_Screen1(Menu_Event_t *event)
{
    Menu_Change_Page(0, 9);
    return 0;
}

void Menu_Add_Encoder_Page()
{
    printf("Menu_Encoder_Init\n");
    Encoder_Screen_List[0].Show_Page_Item = Show_Encoder_Screen0;
    Encoder_Screen_List[0].Page_Item_Callback = Run_Encoder_Screen0;

    Encoder_Screen_List[1].Show_Page_Item = Show_Encoder_Screen1;
    Encoder_Screen_List[1].Page_Item_Callback = Run_Encoder_Screen1;

    Encoder.Page_Item_List = Encoder_Screen_List;
    Encoder.Items_In_Page = ITEMS_IN_PAGE;
    Menu_Add_Page(&Encoder);
}
