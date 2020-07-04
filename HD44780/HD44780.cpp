/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 *
 * Creative Commons Legal Code
 *
 * CC0 1.0 Universal
 *
 *     CREATIVE COMMONS CORPORATION IS NOT A LAW FIRM AND DOES NOT PROVIDE
 *     LEGAL SERVICES. DISTRIBUTION OF THIS DOCUMENT DOES NOT CREATE AN
 *     ATTORNEY-CLIENT RELATIONSHIP. CREATIVE COMMONS PROVIDES THIS
 *     INFORMATION ON AN "AS-IS" BASIS. CREATIVE COMMONS MAKES NO WARRANTIES
 *     REGARDING THE USE OF THIS DOCUMENT OR THE INFORMATION OR WORKS
 *     PROVIDED HEREUNDER, AND DISCLAIMS LIABILITY FOR DAMAGES RESULTING FROM
 *     THE USE OF THIS DOCUMENT OR THE INFORMATION OR WORKS PROVIDED
 *     HEREUNDER.
 *
 * Statement of Purpose
 *
 * The laws of most jurisdictions throughout the world automatically confer
 * exclusive Copyright and Related Rights (defined below) upon the creator
 * and subsequent owner(s) (each and all, an "owner") of an original work of
 * authorship and/or a database (each, a "Work").
 *
 * Certain owners wish to permanently relinquish those rights to a Work for
 * the purpose of contributing to a commons of creative, cultural and
 * scientific works ("Commons") that the public can reliably and without fear
 * of later claims of infringement build upon, modify, incorporate in other
 * works, reuse and redistribute as freely as possible in any form whatsoever
 * and for any purposes, including without limitation commercial purposes.
 * These owners may contribute to the Commons to promote the ideal of a free
 * culture and the further production of creative, cultural and scientific
 * works, or to gain reputation or greater distribution for their Work in
 * part through the use and efforts of others.
 *
 * For these and/or other purposes and motivations, and without any
 * expectation of additional consideration or compensation, the person
 * associating CC0 with a Work (the "Affirmer"), to the extent that he or she
 * is an owner of Copyright and Related Rights in the Work, voluntarily
 * elects to apply CC0 to the Work and publicly distribute the Work under its
 * terms, with knowledge of his or her Copyright and Related Rights in the
 * Work and the meaning and intended legal effect of CC0 on those rights.
 *
 * 1. Copyright and Related Rights. A Work made available under CC0 may be
 * protected by copyright and related or neighboring rights ("Copyright and
 * Related Rights"). Copyright and Related Rights include, but are not
 * limited to, the following:
 *
 *   i. the right to reproduce, adapt, distribute, perform, display,
 *      communicate, and translate a Work;
 *  ii. moral rights retained by the original author(s) and/or performer(s);
 * iii. publicity and privacy rights pertaining to a person's image or
 *      likeness depicted in a Work;
 *  iv. rights protecting against unfair competition in regards to a Work,
 *      subject to the limitations in paragraph 4(a), below;
 *   v. rights protecting the extraction, dissemination, use and reuse of data
 *      in a Work;
 *  vi. database rights (such as those arising under Directive 96/9/EC of the
 *      European Parliament and of the Council of 11 March 1996 on the legal
 *      protection of databases, and under any national implementation
 *      thereof, including any amended or successor version of such
 *      directive); and
 * vii. other similar, equivalent or corresponding rights throughout the
 *      world based on applicable law or treaty, and any national
 *      implementations thereof.
 *
 * 2. Waiver. To the greatest extent permitted by, but not in contravention
 * of, applicable law, Affirmer hereby overtly, fully, permanently,
 * irrevocably and unconditionally waives, abandons, and surrenders all of
 * Affirmer's Copyright and Related Rights and associated claims and causes
 * of action, whether now known or unknown (including existing as well as
 * future claims and causes of action), in the Work (i) in all territories
 * worldwide, (ii) for the maximum duration provided by applicable law or
 * treaty (including future time extensions), (iii) in any current or future
 * medium and for any number of copies, and (iv) for any purpose whatsoever,
 * including without limitation commercial, advertising or promotional
 * purposes (the "Waiver"). Affirmer makes the Waiver for the benefit of each
 * member of the public at large and to the detriment of Affirmer's heirs and
 * successors, fully intending that such Waiver shall not be subject to
 * revocation, rescission, cancellation, termination, or any other legal or
 * equitable action to disrupt the quiet enjoyment of the Work by the public
 * as contemplated by Affirmer's express Statement of Purpose.
 *
 * 3. Public License Fallback. Should any part of the Waiver for any reason
 * be judged legally invalid or ineffective under applicable law, then the
 * Waiver shall be preserved to the maximum extent permitted taking into
 * account Affirmer's express Statement of Purpose. In addition, to the
 * extent the Waiver is so judged Affirmer hereby grants to each affected
 * person a royalty-free, non transferable, non sublicensable, non exclusive,
 * irrevocable and unconditional license to exercise Affirmer's Copyright and
 * Related Rights in the Work (i) in all territories worldwide, (ii) for the
 * maximum duration provided by applicable law or treaty (including future
 * time extensions), (iii) in any current or future medium and for any number
 * of copies, and (iv) for any purpose whatsoever, including without
 * limitation commercial, advertising or promotional purposes (the
 * "License"). The License shall be deemed effective as of the date CC0 was
 * applied by Affirmer to the Work. Should any part of the License for any
 * reason be judged legally invalid or ineffective under applicable law, such
 * partial invalidity or ineffectiveness shall not invalidate the remainder
 * of the License, and in such case Affirmer hereby affirms that he or she
 * will not (i) exercise any of his or her remaining Copyright and Related
 * Rights in the Work or (ii) assert any associated claims and causes of
 * action with respect to the Work, in either case contrary to Affirmer's
 * express Statement of Purpose.
 *
 * 4. Limitations and Disclaimers.
 *
 *  a. No trademark or patent rights held by Affirmer are waived, abandoned,
 *     surrendered, licensed or otherwise affected by this document.
 *  b. Affirmer offers the Work as-is and makes no representations or
 *     warranties of any kind concerning the Work, express, implied,
 *     statutory or otherwise, including without limitation warranties of
 *     title, merchantability, fitness for a particular purpose, non
 *     infringement, or the absence of latent or other defects, accuracy, or
 *     the present or absence of errors, whether or not discoverable, all to
 *     the greatest extent permissible under applicable law.
 *  c. Affirmer disclaims responsibility for clearing rights of other persons
 *     that may apply to the Work or any use thereof, including without
 *     limitation any person's Copyright and Related Rights in the Work.
 *     Further, Affirmer disclaims responsibility for obtaining any necessary
 *     consents, permissions or other rights required for any use of the
 *     Work.
 *  d. Affirmer understands and acknowledges that Creative Commons is not a
 *     party to this document and has no duty or obligation with respect to
 *     this CC0 or use of the Work.
 ******************************************************************************/
#include <HD44780/HD44780.h>

#include <util/delay.h>

#include <common/pins.h>

////////////////////////////////////////////////////////////////////////////////

#define HD44780_DELAY_MS 1

////////////////////////////////////////////////////////////////////////////////

HD44780::HD44780( uint8_t pinRS, uint8_t pinEN,
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

void HD44780::init()
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
    _delay_ms( HD44780_DELAY_MS );

    // ustaw sekwencje 0011
    send4( 0b0011 );
    _delay_ms( HD44780_DELAY_MS );

    // ustawienie interfejsu 4-bitowego
    send4( 0b0010 );
    _delay_ms( HD44780_DELAY_MS );

    // ustaw parametry wyswietlacza
    // bit 4 = 0 (slowo danych ma 4 bity)
    // bit 3 = 1 (2 wiersze znakow)
    // bit 2 = 0 (matryca 5x8 pikseli)
    send8( 0b00101000 );
    _delay_ms( HD44780_DELAY_MS );

    // ustaw tryb pracy wyswietlacza
    // bit 2 = 1 (inkrementowanie adresu zapisu danych)
    // bit 1 = 1 (wylaczenie przesuwania w prawo)
    send8( 0b00000110 );
    _delay_ms( HD44780_DELAY_MS );

    setPinState( _pinRS, STATE_HIGH );

    enableDisplay();
    disableBlink();
    hideCursor();

    clear();
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::update()
{
    send8( _text[ _char ] );

    _char++;

    if ( _char == 16 )
    {
        setPinState( _pinRS, STATE_LOW );
        _delay_ms( HD44780_DELAY_MS );
        // ustaw adres DDRAM na 0x40 (poczatek 2. linii)
        send8( 0b11000000 );
        setPinState( _pinRS, STATE_HIGH );
    }
    else if ( _char >= 32 )
    {
        _char = 0;

        setPinState( _pinRS, STATE_LOW );
        _delay_ms( HD44780_DELAY_MS );
        // ustaw adres DDRAM na 0x00 (poczatek 1. linii)
        send8( 0b10000000 );
        setPinState( _pinRS, STATE_HIGH );
    }
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::clear()
{
    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( 0b1 );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::enableDisplay()
{
    _cmd |= 0b1 << 2;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::disableDisplay()
{
    _cmd &= ~( 0b1 << 2 );

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::enableBlink()
{
    _cmd |= 0b1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::disableBlink()
{
    _cmd &= ~0b1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::showCursor()
{
    _cmd |= 0b1 << 1;

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::hideCursor()
{
    _cmd &= ~( 0b1 << 1 );

    setPinState( _pinRS, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
    send8( _cmd );
    setPinState( _pinRS, STATE_HIGH );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::setLine1( const char *text )
{
    setText( text );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::setLine2( const char *text )
{
    setText( text, 16 );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::send4( const uint8_t &data )
{
    setPinState( _pinEN, STATE_HIGH );
    _delay_ms( HD44780_DELAY_MS );
    setData( data );
    setPinState( _pinEN, STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::send8( const uint8_t &data )
{
    send4( data >> 4 );
    send4( data );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::setData( const uint8_t &data )
{
    setPinState( _pinD4, ( data & 0b0001 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD5, ( data & 0b0010 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD6, ( data & 0b0100 ) ? STATE_HIGH : STATE_LOW );
    setPinState( _pinD7, ( data & 0b1000 ) ? STATE_HIGH : STATE_LOW );
    _delay_ms( HD44780_DELAY_MS );
}

////////////////////////////////////////////////////////////////////////////////

void HD44780::setText( const char *text , uint8_t offset )
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
