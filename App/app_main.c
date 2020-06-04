#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "rotary_encoder.h"
#include "button.h"
#include "menu_core.h"
#include "ssd1306.h"
#include "fonts.h"

Encoder_Struct_t Encoder_X;
Button_Struct_t Button_X;

/* redirect printf to uart */
int __io_putchar(int ch)
{
    huart2.Instance->DR = (ch);
    while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TC) == 0)
        ;
    return ch;
}

/** Encoder Functions Start ***/
uint32_t Encoder_Get_Tick()
{
    return HAL_GetTick();
}

void Encoder_X_Init()
{
    // enable clock, configure as gpio as input
    // configured in cube @see gpio.c
}

uint8_t Encoder_X_Read_Pin_A()
{
    return HAL_GPIO_ReadPin(ENC_X_A_GPIO_Port, ENC_X_A_Pin);
}

uint8_t Encoder_X_Read_Pin_B()
{
    return HAL_GPIO_ReadPin(ENC_X_B_GPIO_Port, ENC_X_B_Pin);
}
/** Encoder Functions End ***/

/** Button Functions  Start ***/
uint32_t Button_Get_Tick()
{
    return HAL_GetTick();
}

void Button_X_Init()
{
    // enable clock, configure as gpio as input
    // configured in cube @see gpio.c
}

uint8_t Button_X_Read()
{
    return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) ? 0 : 1;
}
/** Button Functions End ***/

/** Menu Functions Start ***/
uint32_t Menu_Get_Tick()
{
    return HAL_GetTick();
}

void Menu_Get_Event(Menu_Event_t *event)
{
    event->Encoder_Count = Encoder_Get_Count(&Encoder_X);
    event->Enter_Button_Clicks = Button_Get_Clicked_Count(&Button_X);
    event->Back_Button_Clicks = 0;
    event->Down_Button_Clicks = 0;
    event->Up_Button_Clicks = 0;
    event->Right_Button_Clicks = 0;
    event->Left_Button_Clicks = 0;
}
/** Menu Functions End ***/

void Sytick_Callback()
{
    Encoder_Loop();
    Button_Loop();
}

void App_Main()
{
    /* io buffer off*/
    /* redirect printf to uart */
    setvbuf(stdout, NULL, _IONBF, 0);

    Encoder_X.Encoder_Init = Encoder_X_Init;
    Encoder_X.Encoder_Read_Pin_A = Encoder_X_Read_Pin_A;
    Encoder_X.Encoder_Read_Pin_B = Encoder_X_Read_Pin_B;
    Encoder_Add(&Encoder_X);

    /* button call is not used, set to NULL */
    Button_X.Button_Init = Button_X_Init;
    Button_X.Button_Read = Button_X_Read;
    Button_X.Callback = NULL;
    Button_Add(&Button_X);

    ssd1306_Init();

    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("SSD1306 Menu", Font_7x10, White);
    ssd1306_UpdateScreen();

    extern void Menu_Add_Home_Page();
    extern void Menu_Add_Settings_Page();
    extern void Menu_Add_MCU_Page();
    extern void Menu_Add_Clocks_Page();
    extern void Menu_Add_Battery_Page();
    extern void Menu_Add_Timer_Page();
    extern void Menu_Add_ADC_Page();
    extern void Menu_Add_UART_Page();
    extern void Menu_Add_I2C_Page();
    extern void Menu_Add_Encoder_Page();

    Menu_Add_Home_Page();
    Menu_Add_Settings_Page();
    Menu_Add_MCU_Page();
    Menu_Add_Clocks_Page();
    Menu_Add_Battery_Page();
    Menu_Add_Timer_Page();
    Menu_Add_ADC_Page();
    Menu_Add_UART_Page();
    Menu_Add_I2C_Page();
    Menu_Add_Encoder_Page();
    Menu_Change_Page(0, 0); // by default show page0 screen0.

    while (1)
    {
        Menu_Loop();
    }
}
