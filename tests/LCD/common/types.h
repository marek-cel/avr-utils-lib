/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#ifndef TYPES_H
#define TYPES_H

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////

typedef uint8_t PinNo;

typedef volatile uint8_t* PtrPIN;
typedef volatile uint8_t* PtrPORT;
typedef volatile uint8_t* PtrDDR;
typedef volatile uint8_t* PtrPCMSK;

typedef uint8_t  BitMask;

typedef void (*PtrFun)();

////////////////////////////////////////////////////////////////////////////////

#endif // TYPES_H
