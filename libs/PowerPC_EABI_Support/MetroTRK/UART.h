#ifndef _METROTRK_UART_H
#define _METROTRK_UART_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int UARTError;

typedef enum {
	UART_NoError            = 0,
	UART_UnknownBaudRate    = 1,
	UART_ConfigurationError = 2,
	UART_BufferOverflow     = 3,
	UART_NoData             = 4,
} UARTErrorOptions;

typedef enum {
	kBaudHWSet  = -1,
	kBaud300    = 300,
	kBaud600    = 600,
	kBaud1200   = 1200,
	kBaud1800   = 1800,
	kBaud2000   = 2000,
	kBaud2400   = 2400,
	kBaud3600   = 3600,
	kBaud4800   = 4800,
	kBaud7200   = 7200,
	kBaud9600   = 9600,
	kBaud19200  = 19200,
	kBaud38400  = 38400,
	kBaud57600  = 57600,
	kBaud115200 = 115200,
	kBaud230400 = 230400
} UARTBaudRate;

UARTError InitializeUART(UARTBaudRate baudRate);
UARTError ReadUARTN(void* bytes, unsigned long length);
UARTError WriteUARTN(const void* bytes, unsigned long length);

#ifdef __cplusplus
};
#endif

#endif
