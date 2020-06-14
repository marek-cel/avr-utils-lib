/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#ifndef ENCODER_H
#define ENCODER_H

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////

/**
 * Rotary incremental encoder interface class.
 */
class Encoder
{
public:

    /**
     * Constructor.
     */
    Encoder( uint8_t pinA, uint8_t pinB );

    /** Initializes encoder. */
    void init();

    /**
     * Reads encoder change every detent.
     * @return -1 on decrement, 1 on increment or 0 when no change
     */
    int8_t read_1();

    /**
     * Reads encoder change every 2 detents.
     * @return -1 on decrement, 1 on increment or 0 when no change
     */
    int8_t read_2();

    /**
     * Reads encoder change every 4 detents.
     * @return -1 on decrement, 1 on increment or 0 when no change
     */
    int8_t read_4();

private:

    const uint8_t _pinA;    ///< number of A pin
    const uint8_t _pinB;    ///< number of B pin

    int8_t _delta;          ///< state difference
    int8_t _state_prev;     ///< previous state

    uint8_t getPins();
};

////////////////////////////////////////////////////////////////////////////////

#endif // ENCODER_H
