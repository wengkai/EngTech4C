#include "log.h"
#include "public.h"
#include <stdarg.h>
#include "uart.h"
#include <stdio.h>

static int _logLevel = 0;

void logSetLevel(int level)
{
	_logLevel = level;
}

int logGetLevel(void)
{
	return _logLevel;
}

void log(int level, const char* fmt, ...)
{
	static char buf[200];
	
	if ( level >= _logLevel ) {
		va_list va;
		snprintf(buf,200,"%02d%02d%02d:",HOUR,MIN,SEC);
		va_start(va, fmt);
		vsnprintf(buf+7 ,200-7, fmt, va);
		va_end(va);
		uartPrintln(UART0,buf);
	}
}
