#include <Encoder/Encoder.h>

#include <common/pins.h>

////////////////////////////////////////////////////////////////////////////////

Encoder::Encoder( uint8_t pinA, uint8_t pinB ):
    _pinA ( pinA ),
    _pinB ( pinB ),

    _delta      ( 0b0 ),
    _state_prev ( 0b0 )
{}

////////////////////////////////////////////////////////////////////////////////

void Encoder::init()
{
    setPinMode( _pinA, MODE_PULLUP );
    setPinMode( _pinB, MODE_PULLUP );
}

////////////////////////////////////////////////////////////////////////////////

int8_t Encoder::read_1()
{
    uint8_t pins = getPins();
    int8_t state = 0b0;

    if ( ( pins & 0b01 ) == 0 ) state  = 3;
    if ( ( pins & 0b10 ) == 0 ) state ^= 1;

    int8_t diff = _state_prev - state;

    if ( diff & 1 )
    {
        _state_prev = state;
        _delta += ( diff & 2 ) - 1;
    }

    int8_t result = _delta;
    _delta = 0b0;

    return result;
}

////////////////////////////////////////////////////////////////////////////////

int8_t Encoder::read_2()
{
    uint8_t pins = getPins();
    int8_t state = 0b0;

    if ( ( pins & 0b01 ) == 0 ) state  = 3;
    if ( ( pins & 0b10 ) == 0 ) state ^= 1;

    int8_t diff = _state_prev - state;

    if ( diff & 1 )
    {
        _state_prev = state;
        _delta += ( diff & 2 ) - 1;
    }

    int8_t result = _delta;
    _delta = result & 1;

    return result >> 1;
}

////////////////////////////////////////////////////////////////////////////////

int8_t Encoder::read_4()
{
    uint8_t pins = getPins();
    int8_t state = 0b0;

    if ( ( pins & 0b01 ) == 0 ) state  = 3;
    if ( ( pins & 0b10 ) == 0 ) state ^= 1;

    int8_t diff = _state_prev - state;

    if ( diff & 1 )
    {
        _state_prev = state;
        _delta += ( diff & 2 ) - 1;
    }

    int8_t result = _delta;
    _delta = result & 3;

    return result >> 2;
}


////////////////////////////////////////////////////////////////////////////////

uint8_t Encoder::getPins()
{
    uint8_t pins = 0b0;

    if ( !getPinState( _pinA ) ) pins |= 0b01;
    if ( !getPinState( _pinB ) ) pins |= 0b10;

    return pins;
}

