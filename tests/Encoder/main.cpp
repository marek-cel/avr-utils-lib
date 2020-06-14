/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/

#include <common/all.h>
#include <Encoder/Encoder.h>
#include <LCD/LCD.h>

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

////////////////////////////////////////////////////////////////////////////////

#define ENCODER_1_PIN_A 5
#define ENCODER_1_PIN_B 4

#define LCD_PIN_RS 14
#define LCD_PIN_EN 15
#define LCD_PIN_D4 16
#define LCD_PIN_D5 17
#define LCD_PIN_D6 18
#define LCD_PIN_D7 19

////////////////////////////////////////////////////////////////////////////////

uint8_t _pins2_new = 0b0;
uint8_t _pins2_old = 0b0;

int8_t _test_val = 0;

char _temp[ 16 ] = "";

Encoder _encoder_1( ENCODER_1_PIN_A, ENCODER_1_PIN_B );
LCD _lcd( LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7 );

////////////////////////////////////////////////////////////////////////////////

ISR( PCINT2_vect )
{
    _pins2_new = *getRegPIN( ENCODER_1_PIN_A );

    uint8_t diff = _pins2_new ^ _pins2_old;

    if ( ( diff & getPinBitMask( ENCODER_1_PIN_A ) )
      || ( diff & getPinBitMask( ENCODER_1_PIN_B ) ) )
    {
        switch( _encoder_1.read_4() )
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
    _encoder_1.init();

    enablePCINT( ENCODER_1_PIN_A );
    enablePCINT( ENCODER_1_PIN_B );

    _lcd.init();

    _pins2_new = *getRegPIN( ENCODER_1_PIN_A );

    sei();

    while ( 1 )
    {
        sprintf( _temp, "Test Val= %d", _test_val );

        _lcd.setLine1( _temp );
        _lcd.setLine2( "" );
        _lcd.update();
    }
}
