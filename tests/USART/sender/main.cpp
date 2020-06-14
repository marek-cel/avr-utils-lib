/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/

#include <common/all.h>
#include <Encoder/Encoder.h>
#include <LCD/LCD.h>
#include <USART/USART.h>

#include <stdio.h>

#include <avr/interrupt.h>
#include <avr/io.h>

#include <util/delay.h>

////////////////////////////////////////////////////////////////////////////////

#define ENCODER_PIN_A 6
#define ENCODER_PIN_B 7

#define LCD_PIN_RS 2
#define LCD_PIN_EN 3
#define LCD_PIN_D4 8
#define LCD_PIN_D5 9
#define LCD_PIN_D6 10
#define LCD_PIN_D7 11

////////////////////////////////////////////////////////////////////////////////

uint8_t _pins2_new = 0b0;
uint8_t _pins2_old = 0b0;

int8_t _test_val = 0;

char _temp[ 16 ] = "";

Encoder _encoder( ENCODER_PIN_A, ENCODER_PIN_B );
LCD _lcd( LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7 );

////////////////////////////////////////////////////////////////////////////////

ISR( PCINT2_vect )
{
    _pins2_new = *getPinPIN( ENCODER_PIN_A );

    uint8_t diff = _pins2_new ^ _pins2_old;

    if ( ( diff & getPinMask( ENCODER_PIN_A ) )
      || ( diff & getPinMask( ENCODER_PIN_B ) ) )
    {
        switch( _encoder.read_4() )
        {
            case -1: _test_val--; break;
            case  1: _test_val++; break;
        }

        _pins2_old = _pins2_new;
    }
}

////////////////////////////////////////////////////////////////////////////////

ISR( BADISR_vect ) {}

////////////////////////////////////////////////////////////////////////////////

int main()
{
    _encoder.init();

    enablePCINT( ENCODER_PIN_A );
    enablePCINT( ENCODER_PIN_B );

    _lcd.init();

    _pins2_new = *getPinPIN( ENCODER_PIN_A );

    sei();

    while ( 1 )
    {
        sprintf( _temp, "Test Val= %d", _test_val );

        _lcd.setLine1( _temp );
        _lcd.setLine2( "" );
        _lcd.update();
    }
}
