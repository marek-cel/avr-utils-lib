/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/

#include <common/pins.h>

////////////////////////////////////////////////////////////////////////////////

void setPinMode( PinNo pin, uint8_t mode )
{
    PtrDDR  ptrDDR  = getPinDDR  ( pin );
    PtrPORT ptrPORT = getPinPORT ( pin );
    BitMask bitMask = getPinMask ( pin );

    if ( ptrDDR && ptrPORT )
    {
        if ( mode == MODE_INPUT || mode == MODE_PULLUP )
        {
            (*ptrDDR) &= ~bitMask;

            if ( mode == MODE_PULLUP )
            {
                (*ptrPORT) |=  bitMask;
            }
            else
            {
                (*ptrPORT) &= ~bitMask;
            }
        }
        else if ( mode == MODE_OUTPUT )
        {
            (*ptrDDR) |= bitMask;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPinState( PinNo pin )
{
    PtrPIN ptrPIN = getPinPIN( pin );

    if ( ptrPIN )
    {
        BitMask bitMask = getPinMask( pin );

        if ( (*ptrPIN) & bitMask )
        {
             return STATE_HIGH;
        }
    }

    return STATE_LOW;
}

////////////////////////////////////////////////////////////////////////////////

void setPinState( PinNo pin, uint8_t state )
{
    PtrPORT ptrPORT = getPinPORT( pin );

    if ( ptrPORT )
    {
        BitMask bitMask = getPinMask( pin );

        if ( state )
        {
            *ptrPORT |=  bitMask;
        }
        else
        {
            *ptrPORT &= ~bitMask;
        }
    }
}
