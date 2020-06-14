/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 ******************************************************************************/
#ifndef PINS_H
#define PINS_H

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

#include <common/defs.h>
#include <common/types.h>

////////////////////////////////////////////////////////////////////////////////

#if BOARD_ID == ARDUINO_LEONARDO
#   include <common/pins_leonardo.h>
#endif

#if BOARD_ID == ARDUINO_MEGA
#   include <common/pins_mega.h>
#endif

#if BOARD_ID == ARDUINO_UNO || BOARD_ID == ARDUINO_NANO
#   include <common/pins_standard.h>
#endif

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets digital pin mode.
 * @param pin digital pin number
 * @param mode pin mode
 */
void setPinMode( PinNo pin, uint8_t mode );

/**
 * @brief getDigitalPinState
 * @param pin digital pin number
 * @return pin state
 */
uint8_t getPinState( PinNo pin );

/**
 * @brief Sets digital pin state.
 * @param pin digital pin number
 * @param state pin state
 */
void setPinState( PinNo pin, uint8_t state );

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Returns digital pin number of a given analog pin number.
 * @param analog_pin analog pin number
 * @return digital pin number
 */
PinNo getDigitalPinNo( PinNo analog_pin );

/**
 * @brief Returns PIN register pointer of a given digital pin number.
 * @param pin digital pin number
 * @return PIN register pointer
 */
PtrPIN getPinPIN( PinNo pin );

/**
 * @brief Returns PORT register pointer of a given digital pin number.
 * @param pin digital pin number
 * @return PORT register pointer
 */
PtrPORT getPinPORT( PinNo pin );

/**
 * @brief Returns Data Direction Register (DDR) pointer of a given digital pin number.
 * @param pin digital pin number
 * @return DDR register pointer
 */
PtrDDR getPinDDR( PinNo pin );

/**
 * @brief Returns bit mask of a given digital pin number.
 * @param pin digital pin number
 * @return bit mask
 */
BitMask getPinMask( PinNo pin );

/**
 * @brief Returns PCINT bit of a given digital pin number.
 * @param pin digital pin number
 * @return PCINT bit
 */
uint8_t getPinPCINT( PinNo pin );

/**
 * @brief Returns PCIE bit of a given digital pin number.
 * @param pin digital pin number
 * @return PCIE bit
 */
uint8_t getPinPCIE( PinNo pin );

/**
 * @brief Returns PCMSK register pointer of a given digital pin number.
 * @param pin digital pin number
 * @return PCMSK register pointer
 */
PtrPCMSK getPinPCMSK( PinNo pin );

////////////////////////////////////////////////////////////////////////////////

#endif // PINS_H
