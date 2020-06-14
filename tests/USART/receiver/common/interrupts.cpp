/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/

#include <common/interrupts.h>

#include <avr/interrupt.h>

#include <common/pins.h>

////////////////////////////////////////////////////////////////////////////////

void enablePCINT( PinNo pin )
{
    PtrPCMSK ptrPCMSK = getPinPCMSK( pin );

    if ( ptrPCMSK )
    {
        PCICR |= getPinPCIE( pin );
        (*ptrPCMSK) |= getPinPCINT( pin );
    }
}

