#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t unidad = 0;
uint8_t decena = 0;
uint8_t centena = 0;

void config_USART(void) {
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); 
    UBRR0 = 103; 
}
ISR(USART_RX_vect) {
}  

int main (void){

    DDRD |=0xF0; //display
    DDRB |=0x07; //prender apagar

    config_USART();
    sei();
    while (1) {
        // UNIDAD
        PORTB &= ~0x07;
        PORTB |=0x02;
        PORTD &= ~0xF0;
        PORTD |=(unidad << 4);
        _delay_ms(5);


        // DECENA
        PORTB &= ~0x07;
        PORTB |=0x01;
        PORTD &=~0xF0;
        PORTD |=(decena << 4);
        _delay_ms(5);


        // CENTENA
        PORTB &=~0x07;
        PORTB |=0x04;
        PORTD &= ~0xF0;
        PORTD |= (centena << 4);
        _delay_ms(5);
    }
}
