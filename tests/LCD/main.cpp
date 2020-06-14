/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/

#include <common/all.h>
#include <LCD/LCD.h>

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

////////////////////////////////////////////////////////////////////////////////

#define LCD_PIN_RS 2
#define LCD_PIN_EN 3
#define LCD_PIN_D4 8
#define LCD_PIN_D5 9
#define LCD_PIN_D6 10
#define LCD_PIN_D7 11

////////////////////////////////////////////////////////////////////////////////

LCD _lcd( LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7 );

////////////////////////////////////////////////////////////////////////////////

int main()
{
    _lcd.init();

    while ( 1 )
    {
        _lcd.setLine1( "Hello LCD!" );
        _lcd.setLine2( "" );
        _lcd.update();
    }
}
