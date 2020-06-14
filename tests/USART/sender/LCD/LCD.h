/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#ifndef LCD_H
#define LCD_H

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////

/**
 * HD44780 liquid display driver interface class.
 */
class LCD
{
public:

    /**
     * Constructor.
     */
    LCD( uint8_t pinRS, uint8_t pinEN,
         uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7 );

    /** Initializes LCD. */
    void init();

    /** Updates LCD. */
    void update();

    void clear();
    void enableDisplay();
    void disableDisplay();
    void enableBlink();
    void disableBlink();
    void showCursor();
    void hideCursor();

    void setLine1( const char *text );
    void setLine2( const char *text );

private:

    const uint8_t _pinRS;   ///< number of RS pin
    const uint8_t _pinEN;   ///< number of EN pin
    const uint8_t _pinD4;   ///< number of D4 pin
    const uint8_t _pinD5;   ///< number of D5 pin
    const uint8_t _pinD6;   ///< number of D6 pin
    const uint8_t _pinD7;   ///< number of D7 pin

    uint8_t _cmd;           ///< command word

    uint8_t _char;          ///< current char
    char _text[ 32 ];       ///< text to display 2x16

    void send4( const uint8_t &data );
    void send8( const uint8_t &data );

    void setData( const uint8_t &data );

    void setText( const char *text, uint8_t offset = 0 );
};

////////////////////////////////////////////////////////////////////////////////

#endif // LCD_H
