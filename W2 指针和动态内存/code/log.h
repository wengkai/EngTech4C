#ifndef _LOG_H_
#define _LOG_H_

#define LOG_DEBUG	0
#define LOG_INFO 	1
#define LOG_PANIC	2

void logSetLevel(int level);
int logGetLevel(void);

void log(int level, const char* fmt, ...);

#endif
