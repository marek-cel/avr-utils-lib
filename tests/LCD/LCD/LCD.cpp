/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#include <LCD/LCD.h>

#include <util/delay.h>

#include <common/pins.h>

////////////////////////////////////////////////////////////////////////////////

#define LCD_DELAY_MS 1

////////////////////////////////////////////////////////////////////////////////

LCD::LCD( uint8_t pinRS, uint8_t pinEN,
          uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7 ) :
    _pinRS ( pinRS ),
    _pinEN ( pinEN ),
    _pinD4 ( pinD4 ),
    _pinD5 ( pinD5 ),
    _pinD6 ( pinD6 ),
    _pinD7 ( pinD7 ),

    _cmd ( 0b1100 ),

    _char ( 0 )
{
    for ( uint8_t i = 0; i < 32; i++ )
    {
        _text[ i ] = '\0';
    }
}

////////////////////////////////////////////////////////////////////////////////

void LCD::init()
{
    setPinMode( _pinRS, MODE_OUTPUT );
    setPinMode( _pinEN, MODE_OUTPUT );
    setPinMode( _pinD4, MODE_OUTPUT );
    setPinMode( _pinD5, MODE_OUTPUT );
    setPinMode( _pinD6, MODE_OUTPUT );
    setPinMode( _pinD7, MODE_OUTPUT );

    setPinState( _pinRS, STATE_LOW );
    setPinState( _pinEN, STATE_LOW );
    setPinState( _pinD4, STATE_LOW );
    setPinState( _pinD5, STATE_LOW );
    setPinState( _pinD6, STATE_LOW );
    setPinState( _pinD7, STATE_LOW );

    // zaczekaj co najmniej 45ms na ustabilizowanie sie napiecia
    _delay_ms( 45 );

    // ustaw sekwencje 0011
    send4( 0b0011 );
    _delay_ms( 5 );

    // ustaw sekwencje 0011
    send4( 0b0011 );
    _delay_ms( LCD_DELAY_MS );

    // ustaw sekwencje 0011
    send4( 0b0011 );
    _delay_ms( LCD_DELAY_MS );

    // ustawienie interfejsu 4-bitowego
    send4( 0b0010 );
    _delay_ms( LCD_DELAY_MS );

    // ustaw parametry wyswietlacza
    // bit 4 = 0 (slowo danych ma 4 bity)
    // bit 3 = 1 (2 wiersze znakow)
    // bit 2 = 0 (matryca 5x8 pikseli)
    send8( 0b00101000 );
    _delay_ms( LCD_DELAY_MS );

    // ustaw tryb pracy wyswietlacza
    // bit 2 = 1 (inkrementowanie adresu zapisu danych)
    // bit 1 = 1 (wylaczenie przesuwania w prawo)
    send8( 0b00000110 );
    _delay_ms( LCD_DELAY_MS );

    setPinState( _pinRS, STATE_HIGH );

    enableDisplay();
    disableBlink();
    hideCursor();

    clear();
}

////////////////////////////////////////////////////////////////////////////////

void LCD::update()
{
    send8( _text[ _char ] );

    _char++;

    if ( _char == 16 )
    {
        setPinState( _pinRS, STATE_LOW );
        _delay_ms( LCD_DELAY_MS );
        // ustaw adres DDRAM na 0x40 (poczatek 2. linii)
        send8( 0b11000000 );
        setPinState( _pinRS, STATE_HIGH );
    }
    else if ( _char >= 32 )
    {
        _char = 0;

        setPinState( _pinRS, STATE_LOW );
        _delay_ms( LCD_DELAY_MS );
        // ustaw adres DDRAM na 0x00 (poczatek 1. linii)
        send8( 0b10000000 );
        setPinState( _pinRS, STATE_HIGH );
    }
}

////////////////////////////////////////////////////////////////////////////////

void LCD::clear()
{
    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( 0b1 );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::enableDisplay()
{
    _cmd |= 0b1 << 2;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::disableDisplay()
{
    _cmd &= ~( 0b1 << 2 );

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::enableBlink()
{
    _cmd |= 0b1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::disableBlink()
{
    _cmd &= ~0b1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::showCursor()
{
    _cmd |= 0b1 << 1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::hideCursor()
{
    _cmd &= ~( 0b1 << 1 );

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::setLine1( const char *text )
{
    setText( text );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::setLine2( const char *text )
{
    setText( text, 16 );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::send4( const uint8_t &data )
{
    setPinState( _pinEN, STATE_HIGH );
    _delay_ms( LCD_DELAY_MS );
    setData( data );
    setPinState( _pinEN, STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::send8( const uint8_t &data )
{
    send4( data >> 4 );
    send4( data );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::setData( const uint8_t &data )
{
    setPinState( _pinD4, ( data & 0b0001 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD5, ( data & 0b0010 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD6, ( data & 0b0100 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD7, ( data & 0b1000 ) ? STATE_HIGH : STATE_LOW );
    _delay_ms( LCD_DELAY_MS );
}

////////////////////////////////////////////////////////////////////////////////

void LCD::setText( const char *text , uint8_t offset )
{
    bool terminated = false;

    for ( uint8_t i = 0; i < 16; i++ )
    {
        if ( !terminated && text[ i ] != '\0' )
        {
            _text[ i + offset ] = text[ i ];
        }
        else
        {
            terminated = true;
            _text[ i + offset ] = ' ';
        }
    }
}
