#include <USART/USART.h>

#include <avr/io.h>
#include <avr/interrupt.h>

////////////////////////////////////////////////////////////////////////////////

USART::USART()
{
    // TODO
}

////////////////////////////////////////////////////////////////////////////////

void USART::init( unsigned int ubrr )
{
    // set baud rate
    UBRR0H = (unsigned char)( ubrr >> 8 );
    UBRR0L = (unsigned char)( ubrr );

    // enable receiver and transmitter
    UCSR0B = ( 1 << RXEN0 ) | ( 1 << TXEN0 );

    // set frame: 8data, 1 stp
    UCSR0C = ( 1 << UCSZ01 ) | ( 1 << UCSZ00 );
}

////////////////////////////////////////////////////////////////////////////////

void USART::send( const uint8_t &data )
{
    // wait for empty transmit buffer
    while ( !( UCSR0A & ( 1 << UDRE0 ) ) );

    // Put data into buffer, sends the data
    UDR0 << data;
}

////////////////////////////////////////////////////////////////////////////////

uint8_t USART::recv()
{
    // wait for data to be received
    while ( !( UCSR0A & ( 1 << RXC0 ) ) );

    // get and return received data from buffer
    return UDR0;
}
