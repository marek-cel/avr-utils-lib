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
#include <common/board.h>

#if BOARD_ID == ARDUINO_UNO || BOARD_ID == ARDUINO_NANO

////////////////////////////////////////////////////////////////////////////////

PinNo getDigitalPinFromAnalog( PinNo analog_pin )
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

BitMask getPinBitMask( PinNo pin )
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

uint8_t getPCIE( PinNo pin )
{
    switch( pin )
    {
    case 0:  return _BV( _PCIE_D0  );       // PD0
    case 1:  return _BV( _PCIE_D1  );       // PD1
    case 2:  return _BV( _PCIE_D2  );       // PD2
    case 3:  return _BV( _PCIE_D3  );       // PD3
    case 4:  return _BV( _PCIE_D4  );       // PD4
    case 5:  return _BV( _PCIE_D5  );       // PD5
    case 6:  return _BV( _PCIE_D6  );       // PD6
    case 7:  return _BV( _PCIE_D7  );       // PD7
    case 8:  return _BV( _PCIE_D8  );       // PB0
    case 9:  return _BV( _PCIE_D9  );       // PB1
    case 10: return _BV( _PCIE_D10 );       // PB2
    case 11: return _BV( _PCIE_D11 );       // PB3
    case 12: return _BV( _PCIE_D12 );       // PB4
    case 13: return _BV( _PCIE_D13 );       // PB5
    case 14: return _BV( _PCIE_D14 );       // PC0
    case 15: return _BV( _PCIE_D15 );       // PC1
    case 16: return _BV( _PCIE_D16 );       // PC2
    case 17: return _BV( _PCIE_D17 );       // PC3
    case 18: return _BV( _PCIE_D18 );       // PC4
    case 19: return _BV( _PCIE_D19 );       // PC5
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t getPCINT( PinNo pin )
{
    switch( pin )
    {
        case 0:  return _BV( _PCINT_D0  ); // PD0
        case 1:  return _BV( _PCINT_D1  ); // PD1
        case 2:  return _BV( _PCINT_D2  ); // PD2
        case 3:  return _BV( _PCINT_D3  ); // PD3
        case 4:  return _BV( _PCINT_D4  ); // PD4
        case 5:  return _BV( _PCINT_D5  ); // PD5
        case 6:  return _BV( _PCINT_D6  ); // PD6
        case 7:  return _BV( _PCINT_D7  ); // PD7
        case 8:  return _BV( _PCINT_D8  ); // PB0
        case 9:  return _BV( _PCINT_D9  ); // PB1
        case 10: return _BV( _PCINT_D10 ); // PB2
        case 11: return _BV( _PCINT_D11 ); // PB3
        case 12: return _BV( _PCINT_D12 ); // PB4
        case 13: return _BV( _PCINT_D13 ); // PB5
        case 14: return _BV( _PCINT_D14 ); // PC0
        case 15: return _BV( _PCINT_D15 ); // PC1
        case 16: return _BV( _PCINT_D16 ); // PC2
        case 17: return _BV( _PCINT_D17 ); // PC3
        case 18: return _BV( _PCINT_D18 ); // PC4
        case 19: return _BV( _PCINT_D19 ); // PC5
    }

    return 0b0;
}

////////////////////////////////////////////////////////////////////////////////

PtrDDR getRegDDR( PinNo pin )
{
    switch( pin )
    {
        case 0:  return &_DDR_D0;           // PD0
        case 1:  return &_DDR_D1;           // PD1
        case 2:  return &_DDR_D2;           // PD2
        case 3:  return &_DDR_D3;           // PD3
        case 4:  return &_DDR_D4;           // PD4
        case 5:  return &_DDR_D5;           // PD5
        case 6:  return &_DDR_D6;           // PD6
        case 7:  return &_DDR_D7;           // PD7
        case 8:  return &_DDR_D8;           // PB0
        case 9:  return &_DDR_D9;           // PB1
        case 10: return &_DDR_D10;          // PB2
        case 11: return &_DDR_D11;          // PB3
        case 12: return &_DDR_D12;          // PB4
        case 13: return &_DDR_D13;          // PB5
        case 14: return &_DDR_D14;          // PC0
        case 15: return &_DDR_D15;          // PC1
        case 16: return &_DDR_D16;          // PC2
        case 17: return &_DDR_D17;          // PC3
        case 18: return &_DDR_D18;          // PC4
        case 19: return &_DDR_D19;          // PC5
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPCMSK getRegPCMSK( PinNo pin )
{
    switch( pin )
    {
        case 0:  return &_PCMSK_D0;         // PD0
        case 1:  return &_PCMSK_D1;         // PD1
        case 2:  return &_PCMSK_D2;         // PD2
        case 3:  return &_PCMSK_D3;         // PD3
        case 4:  return &_PCMSK_D4;         // PD4
        case 5:  return &_PCMSK_D5;         // PD5
        case 6:  return &_PCMSK_D6;         // PD6
        case 7:  return &_PCMSK_D7;         // PD7
        case 8:  return &_PCMSK_D8;         // PB0
        case 9:  return &_PCMSK_D9;         // PB1
        case 10: return &_PCMSK_D10;        // PB2
        case 11: return &_PCMSK_D11;        // PB3
        case 12: return &_PCMSK_D12;        // PB4
        case 13: return &_PCMSK_D13;        // PB5
        case 14: return &_PCMSK_D14;        // PC0
        case 15: return &_PCMSK_D15;        // PC1
        case 16: return &_PCMSK_D16;        // PC2
        case 17: return &_PCMSK_D17;        // PC3
        case 18: return &_PCMSK_D18;        // PC4
        case 19: return &_PCMSK_D19;        // PC5
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPIN getRegPIN( PinNo pin )
{
    switch( pin )
    {
        case 0:  return &_PIN_D0;           // PD0
        case 1:  return &_PIN_D1;           // PD1
        case 2:  return &_PIN_D2;           // PD2
        case 3:  return &_PIN_D3;           // PD3
        case 4:  return &_PIN_D4;           // PD4
        case 5:  return &_PIN_D5;           // PD5
        case 6:  return &_PIN_D6;           // PD6
        case 7:  return &_PIN_D7;           // PD7
        case 8:  return &_PIN_D8;           // PB0
        case 9:  return &_PIN_D9;           // PB1
        case 10: return &_PIN_D10;          // PB2
        case 11: return &_PIN_D11;          // PB3
        case 12: return &_PIN_D12;          // PB4
        case 13: return &_PIN_D13;          // PB5
        case 14: return &_PIN_D14;          // PC0
        case 15: return &_PIN_D15;          // PC1
        case 16: return &_PIN_D16;          // PC2
        case 17: return &_PIN_D17;          // PC3
        case 18: return &_PIN_D18;          // PC4
        case 19: return &_PIN_D19;          // PC5
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

PtrPORT getRegPORT( PinNo pin )
{
    switch( pin )
    {
        case 0:  return &_PORT_D0;          // PD0
        case 1:  return &_PORT_D1;          // PD1
        case 2:  return &_PORT_D2;          // PD2
        case 3:  return &_PORT_D3;          // PD3
        case 4:  return &_PORT_D4;          // PD4
        case 5:  return &_PORT_D5;          // PD5
        case 6:  return &_PORT_D6;          // PD6
        case 7:  return &_PORT_D7;          // PD7
        case 8:  return &_PORT_D8;          // PB0
        case 9:  return &_PORT_D9;          // PB1
        case 10: return &_PORT_D10;         // PB2
        case 11: return &_PORT_D11;         // PB3
        case 12: return &_PORT_D12;         // PB4
        case 13: return &_PORT_D13;         // PB5
        case 14: return &_PORT_D14;         // PC0
        case 15: return &_PORT_D15;         // PC1
        case 16: return &_PORT_D16;         // PC2
        case 17: return &_PORT_D17;         // PC3
        case 18: return &_PORT_D18;         // PC4
        case 19: return &_PORT_D19;         // PC5
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

#endif
