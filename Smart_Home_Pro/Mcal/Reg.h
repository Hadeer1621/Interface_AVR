/*
 * Reg.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef REG_H_
#define REG_H_

#include "Std.h"
/******************************************************_DIO_REGISTERS_****************************/
#define PINA_REG   *(volatile u8*)0x39
#define DDRA_REG   *(volatile u8*)0x3A
#define PORTA_REG  *(volatile u8*)0x3B
#define PINB_REG   *(volatile u8*)0x36
#define DDRB_REG   *(volatile u8*)0x37
#define PORTB_REG  *(volatile u8*)0x38
#define PINC_REG   *(volatile u8*)0x33
#define DDRC_REG   *(volatile u8*)0x34
#define PORTC_REG  *(volatile u8*)0x35
#define PIND_REG   *(volatile u8*)0x30
#define DDRD_REG   *(volatile u8*)0x31
#define PORTD_REG  *(volatile u8*)0x32
/******************************************************_EXT_INT_REGISTERS_****************************/
#define GICR_REG     *((volatile u8 *)0x5B)
#define GIFR_REG     *((volatile u8 *)0x5A)
#define MCUCR_REG    *((volatile u8 *)0x55)
#define MCUCSR_REG   *((volatile u8 *)0x54)
#define SREG_REG     *((volatile u8*)0x5F)
/***********************************_ADC_REGISTERS_***************************************/
#define ADMUX_REG    *((volatile u8*)0x27)
#define ADCSRA_REG    *((volatile u8*)0x26)
#define ADCL_REG   *(volatile u8*)0x24
#define ADCH_REG   *(volatile u8*)0x25
#define ADC_REG    *(volatile u16*)0x24
/***************************************_Timer0_REG_**********************************/
#define TIMER0_TCCR0  *((volatile u8*)0x53)
#define TIMER0_TCNT0  *((volatile u8*)0x52)
#define TIMER0_OCR0   *((volatile u8*)0x5C)

#define TIMER_TIMSK   *((volatile u8*)0x59)
#define TIMER_TIFR    *((volatile u8*)0x58)

//TIMER0_TCCR0  bits
#define TIMER0_CS00  0
#define TIMER0_CS01  1
#define TIMER0_CS02  2
#define TIMER0_WGM01 3
#define TIMER0_COM00 4
#define TIMER0_COM01 5
#define TIMER0_WGM00 6
#define TIMER0_FOC0  7

//TIMER_TIMSK bits
#define TIMER_TOIE0  0    /*OVF Interrupt Enable*/
#define TIMER_OCIE0  1    /*Output Compare Interrupt Enable*/
#define TIMER_TICIE1 5
//TIMER_TIFR bits
#define TIMER_TOV0   0
#define TIMER_OCF0   1


//////////////////////////////////////////////////// TIMER 1
#define TIMER1_TCCR1A				*((volatile u8 *)0x4F)

#define TIMER1_TCCR1B				*((volatile u8 *)0x4E) // TIMER1_TCCR1B

#define TIMER1_CS10                 0
#define TIMER1_CS11                 1
#define TIMER1_CS12                 2
#define TIMER1_ICES1                6

#define TIMER1_TCNT1H				*((volatile u8 *)0x4B)
#define TIMER1_TCNT1L				*((volatile u8 *)0x4C)
#define TIMER1_OCR1AH				*((volatile u8 *)0x4B)
#define TIMER1_OCR1AL				*((volatile u8 *)0x4A)
#define TIMER1_OCR1BH				*((volatile u8 *)0x49)
#define TIMER1_OCR1BL				*((volatile u8 *)0x48)
#define TIMER1_ICR1H				*((volatile u8 *)0x47)
#define TIMER1_ICR1L				*((volatile u8 *)0x46)

#define TIMER1_ICR1				*((volatile u16 *)0x46) // TIMER1_ICR1L + TIMER1_ICR1H


/***************************************_UART_REG_**********************************/
#define UART_UDR         *((volatile u8*)  0x2C)
#define UART_UCSRA       *((volatile u8*)  0x2B)
#define UART_UCSRB       *((volatile u8*)  0x2A)
#define UART_UCSRC       *((volatile u8*)  0x40)
#define UART_UBRRH       *((volatile u8*)  0x40)
#define UART_UBRRL       *((volatile u8*)  0x29)

//UCSRA
#define UART_RXC         7
#define UART_TXC         6
#define UART_UDRE        5

//UCSRB
#define UART_RXEN        4
#define UART_TXEN        3

//UCSRC
#define UART_URSEL        7
#define UART_UMSEL        6  // mode select
#define UART_UPM1         5
#define UART_UPM0         4
#define UART_USBS         3
#define UART_UCSZ1        2
#define UART_UCSZ0        1
#define UART_UCSZ2        0
/***************************************_UART_REG_**********************************/
#define SPI_SPCR         *((volatile u8*)  0x2D)
#define SPI_SPSR         *((volatile u8*)  0x2E)
#define SPI_SPDR         *((volatile u8*)  0x2F)

/***************************************_UART_REG_**********************************/
#define TWI_TWBR         *((volatile u8*)  0x)
#define TWI_TWCR         *((volatile u8*)  0x)
#define TWI_TWSR         *((volatile u8*)  0x)
#define TWI_TWDR         *((volatile u8*)  0x)
#define TWI_TWAR         *((volatile u8*)  0x)

#define TWINT   7  // interrupt flag
#define TWEA    6  // enable ACK
#define TWSTA   5  // send start
#define TWSTO   4  // send stop
#define TWWC    3  // collision flag
#define TWEN    2  // enable TWI
#define TWIE    0  // interrupt enable

#define TWPS1   // PRESCALER 1
#define TWPS1   // PRESCALER 0

#define TWGCE   0 // enable recognition of brodcast

#endif /* REG_H_ */
