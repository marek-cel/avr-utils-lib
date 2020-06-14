/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#include <common/pins.h>

#if BOARD_ID == ARDUINO_UNO || BOARD_ID == ARDUINO_NANO

////////////////////////////////////////////////////////////////////////////////

#include <avr/interrupt.h>
#include <avr/io.h>

////////////////////////////////////////////////////////////////////////////////

PinNo getDigitalPinNo( PinNo analog_pin )
{
    switch ( analog_pin )
    {
        case 0: return 14;
        case 1: return 15;
        case 2: return 16;
        case 3: return 17;
        case 4: return 18;
        case 5: return 19;
    }

    return NOT_A_PIN;
}

////////////////////////////////////////////////////////////////////////////////

PtrPIN getPinPIN( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD0
    case 1:     // PD1
    case 2:     // PD2
    case 3:     // PD3
    case 4:     // PD4
    case 5:     // PD5
    case 6:     // PD6
    case 7:     // PD7
        return &PIND;

    case 8:     // PB0
    case 9:     // PB1
    case 10:    // PB2
    case 11:    // PB3
    case 12:    // PB4
    case 13:    // PB5
        return &PINB;

    case 14:    // PC0 - A0
    case 15:    // PC1 - A1
    case 16:    // PC2 - A2
    case 17:    // PC3 - A3
    case 18:    // PC4 - A4
    case 19:    // PC5 - A5
        return &PINC;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPORT getPinPORT( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD0
    case 1:     // PD1
    case 2:     // PD2
    case 3:     // PD3
    case 4:     // PD4
    case 5:     // PD5
    case 6:     // PD6
    case 7:     // PD7
        return &PORTD;

    case 8:     // PB0
    case 9:     // PB1
    case 10:    // PB2
    case 11:    // PB3
    case 12:    // PB4
    case 13:    // PB5
        return &PORTB;

    case 14:    // PC0
    case 15:    // PC1
    case 16:    // PC2
    case 17:    // PC3
    case 18:    // PC4
    case 19:    // PC5
        return &PORTC;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrDDR getPinDDR( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD0
    case 1:     // PD1
    case 2:     // PD2
    case 3:     // PD3
    case 4:     // PD4
    case 5:     // PD5
    case 6:     // PD6
    case 7:     // PD7
        return &DDRD;

    case 8:     // PB0
    case 9:     // PB1
    case 10:    // PB2
    case 11:    // PB3
    case 12:    // PB4
    case 13:    // PB5
        return &DDRB;

    case 14:    // PC0
    case 15:    // PC1
    case 16:    // PC2
    case 17:    // PC3
    case 18:    // PC4
    case 19:    // PC5
        return &DDRC;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

BitMask getPinMask( PinNo pin )
{
    switch( pin )
    {
        case 0:  return _BV( PD0 );         // PD0
        case 1:  return _BV( PD1 );         // PD1
        case 2:  return _BV( PD2 );         // PD2
        case 3:  return _BV( PD3 );         // PD3
        case 4:  return _BV( PD4 );         // PD4
        case 5:  return _BV( PD5 );         // PD5
        case 6:  return _BV( PD6 );         // PD6
        case 7:  return _BV( PD7 );         // PD7
        case 8:  return _BV( PB0 );         // PB0
        case 9:  return _BV( PB1 );         // PB1
        case 10: return _BV( PB2 );         // PB2
        case 11: return _BV( PB3 );         // PB3
        case 12: return _BV( PB4 );         // PB4
        case 13: return _BV( PB5 );         // PB5
        case 14: return _BV( PC0 );         // PC0
        case 15: return _BV( PC1 );         // PC1
        case 16: return _BV( PC2 );         // PC2
        case 17: return _BV( PC3 );         // PC3
        case 18: return _BV( PC4 );         // PC4
        case 19: return _BV( PC5 );         // PC5
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPinPCINT( PinNo pin )
{
    switch( pin )
    {
        case 0:  return _BV( PCINT16 ); // PD0
        case 1:  return _BV( PCINT17 ); // PD1
        case 2:  return _BV( PCINT18 ); // PD2
        case 3:  return _BV( PCINT19 ); // PD3
        case 4:  return _BV( PCINT20 ); // PD4
        case 5:  return _BV( PCINT21 ); // PD5
        case 6:  return _BV( PCINT22 ); // PD6
        case 7:  return _BV( PCINT23 ); // PD7
        case 8:  return _BV( PCINT0  ); // PB0
        case 9:  return _BV( PCINT1  ); // PB1
        case 10: return _BV( PCINT2  ); // PB2
        case 11: return _BV( PCINT3  ); // PB3
        case 12: return _BV( PCINT4  ); // PB4
        case 13: return _BV( PCINT5  ); // PB5
        case 14: return _BV( PCINT8  ); // PC0
        case 15: return _BV( PCINT9  ); // PC1
        case 16: return _BV( PCINT10 ); // PC2
        case 17: return _BV( PCINT11 ); // PC3
        case 18: return _BV( PCINT12 ); // PC4
        case 19: return _BV( PCINT13 ); // PC5
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPinPCIE( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD0
    case 1:     // PD1
    case 2:     // PD2
    case 3:     // PD3
    case 4:     // PD4
    case 5:     // PD5
    case 6:     // PD6
    case 7:     // PD7
        return _BV( PCIE2 );

    case 8:     // PB0
    case 9:     // PB1
    case 10:    // PB2
    case 11:    // PB3
    case 12:    // PB4
    case 13:    // PB5
        return _BV( PCIE0 );

    case 14:    // PC0
    case 15:    // PC1
    case 16:    // PC2
    case 17:    // PC3
    case 18:    // PC4
    case 19:    // PC5
        return _BV( PCIE1 );
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPCMSK getPinPCMSK( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD0
    case 1:     // PD1
    case 2:     // PD2
    case 3:     // PD3
    case 4:     // PD4
    case 5:     // PD5
    case 6:     // PD6
    case 7:     // PD7
        return &PCMSK2;

    case 8:     // PB0
    case 9:     // PB1
    case 10:    // PB2
    case 11:    // PB3
    case 12:    // PB4
    case 13:    // PB5
        return &PCMSK0;

    case 14:    // PC0
    case 15:    // PC1
    case 16:    // PC2
    case 17:    // PC3
    case 18:    // PC4
    case 19:    // PC5
        return &PCMSK1;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

#endif
