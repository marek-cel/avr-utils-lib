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
#ifndef BOARD_STANDARD_H
#define BOARD_STANDARD_H

////////////////////////////////////////////////////////////////////////////////

#include <avr/interrupt.h>
#include <avr/io.h>

#include <common/types.h>

////////////////////////////////////////////////////////////////////////////////

#define BUILT_IN_LED_PIN_NO 13

////////////////////////////////////////////////////////////////////////////////

#define _DDR_D0     DDRD    /* 0  - PD0 */
#define _DDR_D1     DDRD    /* 1  - PD1 */
#define _DDR_D2     DDRD    /* 2  - PD2 */
#define _DDR_D3     DDRD    /* 3  - PD3 */
#define _DDR_D4     DDRD    /* 4  - PD4 */
#define _DDR_D5     DDRD    /* 5  - PD5 */
#define _DDR_D6     DDRD    /* 6  - PD6 */
#define _DDR_D7     DDRD    /* 7  - PD7 */
#define _DDR_D8     DDRB    /* 8  - PB0 */
#define _DDR_D9     DDRB    /* 9  - PB1 */
#define _DDR_D10    DDRB    /* 10 - PB2 */
#define _DDR_D11    DDRB    /* 11 - PB3 */
#define _DDR_D12    DDRB    /* 12 - PB4 */
#define _DDR_D13    DDRB    /* 13 - PB5 */
#define _DDR_D14    DDRC    /* 14 - PC0 - A0 */
#define _DDR_D15    DDRC    /* 15 - PC1 - A1 */
#define _DDR_D16    DDRC    /* 16 - PC2 - A2 */
#define _DDR_D17    DDRC    /* 17 - PC3 - A3 */
#define _DDR_D18    DDRC    /* 18 - PC4 - A4 */
#define _DDR_D19    DDRC    /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

#define _PCIE_D0    PCIE2   /* 0  - PD0 */
#define _PCIE_D1    PCIE2   /* 1  - PD1 */
#define _PCIE_D2    PCIE2   /* 2  - PD2 */
#define _PCIE_D3    PCIE2   /* 3  - PD3 */
#define _PCIE_D4    PCIE2   /* 4  - PD4 */
#define _PCIE_D5    PCIE2   /* 5  - PD5 */
#define _PCIE_D6    PCIE2   /* 6  - PD6 */
#define _PCIE_D7    PCIE2   /* 7  - PD7 */
#define _PCIE_D8    PCIE0   /* 8  - PB0 */
#define _PCIE_D9    PCIE0   /* 9  - PB1 */
#define _PCIE_D10   PCIE0   /* 10 - PB2 */
#define _PCIE_D11   PCIE0   /* 11 - PB3 */
#define _PCIE_D12   PCIE0   /* 12 - PB4 */
#define _PCIE_D13   PCIE0   /* 13 - PB5 */
#define _PCIE_D14   PCIE1   /* 14 - PC0 - A0 */
#define _PCIE_D15   PCIE1   /* 15 - PC1 - A1 */
#define _PCIE_D16   PCIE1   /* 16 - PC2 - A2 */
#define _PCIE_D17   PCIE1   /* 17 - PC3 - A3 */
#define _PCIE_D18   PCIE1   /* 18 - PC4 - A4 */
#define _PCIE_D19   PCIE1   /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

#define _PCINT_D0   PCINT16 /* 0  - PD0 */
#define _PCINT_D1   PCINT17 /* 1  - PD1 */
#define _PCINT_D2   PCINT18 /* 2  - PD2 */
#define _PCINT_D3   PCINT19 /* 3  - PD3 */
#define _PCINT_D4   PCINT20 /* 4  - PD4 */
#define _PCINT_D5   PCINT21 /* 5  - PD5 */
#define _PCINT_D6   PCINT22 /* 6  - PD6 */
#define _PCINT_D7   PCINT23 /* 7  - PD7 */
#define _PCINT_D8   PCINT0  /* 8  - PB0 */
#define _PCINT_D9   PCINT1  /* 9  - PB1 */
#define _PCINT_D10  PCINT2  /* 10 - PB2 */
#define _PCINT_D11  PCINT3  /* 11 - PB3 */
#define _PCINT_D12  PCINT4  /* 12 - PB4 */
#define _PCINT_D13  PCINT5  /* 13 - PB5 */
#define _PCINT_D14  PCINT8  /* 14 - PC0 - A0 */
#define _PCINT_D15  PCINT9  /* 15 - PC1 - A1 */
#define _PCINT_D16  PCINT10 /* 16 - PC2 - A2 */
#define _PCINT_D17  PCINT11 /* 17 - PC3 - A3 */
#define _PCINT_D18  PCINT12 /* 18 - PC4 - A4 */
#define _PCINT_D19  PCINT13 /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

#define _PCMSK_D0   PCMSK2  /* 0  - PD0 */
#define _PCMSK_D1   PCMSK2  /* 1  - PD1 */
#define _PCMSK_D2   PCMSK2  /* 2  - PD2 */
#define _PCMSK_D3   PCMSK2  /* 3  - PD3 */
#define _PCMSK_D4   PCMSK2  /* 4  - PD4 */
#define _PCMSK_D5   PCMSK2  /* 5  - PD5 */
#define _PCMSK_D6   PCMSK2  /* 6  - PD6 */
#define _PCMSK_D7   PCMSK2  /* 7  - PD7 */
#define _PCMSK_D8   PCMSK0  /* 8  - PB0 */
#define _PCMSK_D9   PCMSK0  /* 9  - PB1 */
#define _PCMSK_D10  PCMSK0  /* 10 - PB2 */
#define _PCMSK_D11  PCMSK0  /* 11 - PB3 */
#define _PCMSK_D12  PCMSK0  /* 12 - PB4 */
#define _PCMSK_D13  PCMSK0  /* 13 - PB5 */
#define _PCMSK_D14  PCMSK1  /* 14 - PC0 - A0 */
#define _PCMSK_D15  PCMSK1  /* 15 - PC1 - A1 */
#define _PCMSK_D16  PCMSK1  /* 16 - PC2 - A2 */
#define _PCMSK_D17  PCMSK1  /* 17 - PC3 - A3 */
#define _PCMSK_D18  PCMSK1  /* 18 - PC4 - A4 */
#define _PCMSK_D19  PCMSK1  /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

#define _PIN_D0     PIND    /* 0  - PD0 */
#define _PIN_D1     PIND    /* 1  - PD1 */
#define _PIN_D2     PIND    /* 2  - PD2 */
#define _PIN_D3     PIND    /* 3  - PD3 */
#define _PIN_D4     PIND    /* 4  - PD4 */
#define _PIN_D5     PIND    /* 5  - PD5 */
#define _PIN_D6     PIND    /* 6  - PD6 */
#define _PIN_D7     PIND    /* 7  - PD7 */
#define _PIN_D8     PINB    /* 8  - PB0 */
#define _PIN_D9     PINB    /* 9  - PB1 */
#define _PIN_D10    PINB    /* 10 - PB2 */
#define _PIN_D11    PINB    /* 11 - PB3 */
#define _PIN_D12    PINB    /* 12 - PB4 */
#define _PIN_D13    PINB    /* 13 - PB5 */
#define _PIN_D14    PINC    /* 14 - PC0 - A0 */
#define _PIN_D15    PINC    /* 15 - PC1 - A1 */
#define _PIN_D16    PINC    /* 16 - PC2 - A2 */
#define _PIN_D17    PINC    /* 17 - PC3 - A3 */
#define _PIN_D18    PINC    /* 18 - PC4 - A4 */
#define _PIN_D19    PINC    /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

#define _PORT_D0    PORTD   /* 0  - PD0 */
#define _PORT_D1    PORTD   /* 1  - PD1 */
#define _PORT_D2    PORTD   /* 2  - PD2 */
#define _PORT_D3    PORTD   /* 3  - PD3 */
#define _PORT_D4    PORTD   /* 4  - PD4 */
#define _PORT_D5    PORTD   /* 5  - PD5 */
#define _PORT_D6    PORTD   /* 6  - PD6 */
#define _PORT_D7    PORTD   /* 7  - PD7 */
#define _PORT_D8    PORTB   /* 8  - PB0 */
#define _PORT_D9    PORTB   /* 9  - PB1 */
#define _PORT_D10   PORTB   /* 10 - PB2 */
#define _PORT_D11   PORTB   /* 11 - PB3 */
#define _PORT_D12   PORTB   /* 12 - PB4 */
#define _PORT_D13   PORTB   /* 13 - PB5 */
#define _PORT_D14   PORTC   /* 14 - PC0 - A0 */
#define _PORT_D15   PORTC   /* 15 - PC1 - A1 */
#define _PORT_D16   PORTC   /* 16 - PC2 - A2 */
#define _PORT_D17   PORTC   /* 17 - PC3 - A3 */
#define _PORT_D18   PORTC   /* 18 - PC4 - A4 */
#define _PORT_D19   PORTC   /* 19 - PC5 - A5 */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Returns digital pin number of a given analog pin number.
 * @param analog_pin analog pin number
 * @return digital pin number
 */
PinNo getPinNoFromAnalog( PinNo analog_pin );

////////////////////////////////////////////////////////////////////////////////

#endif // BOARD_STANDARD_H
