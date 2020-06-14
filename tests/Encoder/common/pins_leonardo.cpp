/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#include <common/pins.h>

#if BOARD_ID == ARDUINO_LEONARDO

////////////////////////////////////////////////////////////////////////////////

#include <avr/interrupt.h>
#include <avr/io.h>

////////////////////////////////////////////////////////////////////////////////

PinNo getDigitalPinNo( PinNo analog_pin )
{
    switch ( analog_pin )
    {
        case 0: return 18;  // PF7 - A0
        case 1: return 19;  // PF6 - A1
        case 2: return 20;  // PF5 - A2
        case 3: return 21;  // PF4 - A3
        case 4: return 22;  // PF1 - A4
        case 5: return 23;  // PF0 - A5
    }

    return NOT_A_PIN;
}

////////////////////////////////////////////////////////////////////////////////

PtrPIN getPinPIN( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD2
    case 1:     // PD3
    case 2:     // PD1
    case 3:     // PD0
    case 4:     // PD4
    case 6:     // PD7
    case 12:    // PD6
        return &PIND;

    case 5:     // PC6
    case 13:    // PC7
        return &PINC;

    case 7:     // PE6
        return &PINE;

    case 8:     // PB4
    case 9:     // PB5
    case 10:    // PB6
    case 11:    // PB7
    case 14:    // PB3 - MISO
    case 15:    // PB1 - SCK
    case 16:    // PB2 - MOSI
    case 17:    // PB0 - SS
        return &PINB;

    case 18:    // PF7 - A0
    case 19:    // PF6 - A1
    case 20:    // PF5 - A2
    case 21:    // PF4 - A3
    case 22:    // PF1 - A4
    case 23:    // PF0 - A5
        return &PINF;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPORT getPinPORT( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD2
    case 1:     // PD3
    case 2:     // PD1
    case 3:     // PD0
    case 4:     // PD4
    case 6:     // PD7
    case 12:    // PD6
        return &PORTD;

    case 5:     // PC6
    case 13:    // PC7
        return &PORTC;

    case 7:     // PE6
        return &PORTE;

    case 8:     // PB4
    case 9:     // PB5
    case 10:    // PB6
    case 11:    // PB7
    case 14:    // PB3 - MISO
    case 15:    // PB1 - SCK
    case 16:    // PB2 - MOSI
    case 17:    // PB0 - SS
        return &PORTB;

    case 18:    // PF7 - A0
    case 19:    // PF6 - A1
    case 20:    // PF5 - A2
    case 21:    // PF4 - A3
    case 22:    // PF1 - A4
    case 23:    // PF0 - A5
        return &PORTF;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrDDR getPinDDR( PinNo pin )
{
    switch( pin )
    {
    case 0:     // PD2
    case 1:     // PD3
    case 2:     // PD1
    case 3:     // PD0
    case 4:     // PD4
    case 6:     // PD7
    case 12:    // PD6
        return &DDRD;

    case 5:     // PC6
    case 13:    // PC7
        return &DDRC;

    case 7:     // PE6
        return &DDRE;

    case 8:     // PB4
    case 9:     // PB5
    case 10:    // PB6
    case 11:    // PB7
    case 14:    // PB3 - MISO
    case 15:    // PB1 - SCK
    case 16:    // PB2 - MOSI
    case 17:    // PB0 - SS
        return &DDRB;

    case 18:    // PF7 - A0
    case 19:    // PF6 - A1
    case 20:    // PF5 - A2
    case 21:    // PF4 - A3
    case 22:    // PF1 - A4
    case 23:    // PF0 - A5
        return &DDRF;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

BitMask getPinMask( PinNo pin )
{
    switch( pin )
    {
        case 0:  return _BV( PD2 );     // PD2
        case 1:  return _BV( PD3 );     // PD3
        case 2:  return _BV( PD1 );     // PD1
        case 3:  return _BV( PD0 );     // PD0
        case 4:  return _BV( PD4 );     // PD4
        case 5:  return _BV( PC6 );     // PC6
        case 6:  return _BV( PD7 );     // PD7
        case 7:  return _BV( PE6 );     // PE6
        case 8:  return _BV( PB4 );     // PB4
        case 9:  return _BV( PB5 );     // PB5
        case 10: return _BV( PB6 );     // PB6
        case 11: return _BV( PB7 );     // PB7
        case 12: return _BV( PD6 );     // PD6
        case 13: return _BV( PC7 );     // PC7
        case 14: return _BV( PB3 );     // PB3 - MISO
        case 15: return _BV( PB1 );     // PB1 - SCK
        case 16: return _BV( PB2 );     // PB2 - MOSI
        case 17: return _BV( PB0 );     // PB0 - SS
        case 18: return _BV( PF7 );     // PF7 - A0
        case 19: return _BV( PF6 );     // PF6 - A1
        case 20: return _BV( PF5 );     // PF5 - A2
        case 21: return _BV( PF4 );     // PF4 - A3
        case 22: return _BV( PF1 );     // PF1 - A4
        case 23: return _BV( PF0 );     // PF0 - A5
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPinPCINT( PinNo pin )
{
    switch( pin )
    {
        case 8:  return _BV( PCINT4 );  // PB4
        case 9:  return _BV( PCINT5 );  // PB5
        case 10: return _BV( PCINT6 );  // PB6
        case 11: return _BV( PCINT7 );  // PB7
        case 14: return _BV( PCINT3 );  // PB3 - MISO
        case 15: return _BV( PCINT1 );  // PB1 - SCK
        case 16: return _BV( PCINT2 );  // PB2 - MOSI
        case 17: return _BV( PCINT0 );  // PB0 - SS
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPinPCIE( PinNo pin )
{
    switch( pin )
    {
    case 8:     // PB4
    case 9:     // PB5
    case 10:    // PB6
    case 11:    // PB7
    case 14:    // PB3 - MISO
    case 15:    // PB1 - SCK
    case 16:    // PB2 - MOSI
    case 17:    // PB0 - SS
        return _BV( PCIE0 );
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPCMSK getPinPCMSK( PinNo pin )
{
    switch( pin )
    {
    case 8:     // PB4
    case 9:     // PB5
    case 10:    // PB6
    case 11:    // PB7
    case 14:    // PB3 - MISO
    case 15:    // PB1 - SCK
    case 16:    // PB2 - MOSI
    case 17:    // PB0 - SS
        return &PCMSK0;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

#endif
