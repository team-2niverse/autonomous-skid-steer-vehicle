/*
 * Stdio.c
 *
 *  Created on: 2025. 7. 25.
 *      Author: USER
 */


#include "Stdio.h"
#include "IfxCpu.h"
#include "asclin.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE     128
#define KB_BS '\x7F'
#define KB_CR '\r'

void remove_null(char *s);

void my_puts(const char *str) {
    const char *p = str;
    while (*p != 0)
        Asclin0_outUart(*p++);
    Asclin0_outUart('\r');
    Asclin0_outUart('\n');
}

void my_printf(const char *fmt, ...) {
    char buf[BUFSIZE];
    int len = 0;
    va_list args;

    va_start(args, fmt);
    len = vsnprintf(buf, BUFSIZE, fmt, args);
    va_end(args);

    for (int i = 0; i < len; i++)
        Asclin0_outUart(buf[i]);
}

// from NGV_project
void my_scanf(const char *fmt, ...)
{
    uint8 c = 0;
    char buf[BUFSIZE];
    int idx = 0, i;
    char *pstr, *pidx;

    memset(buf, 0, BUFSIZE);
    while (c != '\r')
    {
        c = Asclin0_inUart();
        if (c == KB_BS || c == 0x8)
        {
            if (idx > 0) {
                buf[idx - 1] = 0;
                idx--;
                Asclin0_outUart(8);
                Asclin0_outUart(' ');
                Asclin0_outUart(8);
            }
            continue;
        }
        else
        {
            if (c == KB_CR) {
                idx += 1;
                buf[idx] = '\0';
            } else {
                buf[idx] = c;
                idx += 1;
            }
        }
        Asclin0_outUart(c);
    }
    Asclin0_outUart('\r');
    Asclin0_outUart('\n');

    va_list ap;
    va_start(ap, fmt);
    while ((c = *fmt++) != 0)
    {
        if (c == '%')
        {
            uint8 c1;
            c = *fmt++;
            switch (c)
            {
                case 'c':
                    *va_arg(ap, char *) = buf[0];
                    buf[0] = '\0';
                    break;
                case 'd':
                    *va_arg(ap, int *) = atoi(buf);
                    pidx = strchr(buf, ' ');
                    if (pidx != NULL) { *pidx = '\0'; }
                    for (i = 0; ; i++)
                    {
                        if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                        buf[i] = '\0';
                    }
                    break;
                case 's':
                    pstr = va_arg(ap, char *);
                    for (i = 0; buf[i] != '\0'; i++)
                    {
                        *pstr++ = buf[i];
                        buf[i] = '\0';
                    }
                    *pstr = '\0';
                    break;
                case 'l':
                    c1 = *fmt++;
                    if (c1 == 'd') {
                        *va_arg(ap, long long *) = atoll(buf);
                        pidx = strchr(buf, ' ');
                        if (pidx != NULL) { *pidx = '\0'; }
                        for (i = 0; ; i++)
                        {
                            if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                            buf[i] = '\0';
                        }
                    } else if (c1 == 'f') {
                        *va_arg(ap, double *) = atof(buf);
                        pidx = strchr(buf, ' ');
                        if (pidx != NULL) { *pidx = '\0'; }
                        for (int i = 0; ; i++)
                        {
                            if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                            buf[i] = '\0';
                        }
                    }
                    break;
                case 'f':
                    *va_arg(ap, float *) = (float)(atof(buf));
                    pidx = strchr(buf, ' ');
                    if (pidx != NULL) { *pidx = '\0'; }
                    for (i = 0; ; i++)
                    {
                        if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                        buf[i] = '\0';
                    }
                    break;
                default:
                    break;
            }
            remove_null(buf);
        }
    }
    va_end(ap);
}

void remove_null(char *s)
{
    int i, start_idx;
    char buf[128];

    start_idx = 0;
    while (*(s + start_idx++) == '\0');
    memset(buf, 0, 128);
    strcpy(buf, (s + (start_idx - 1)));

    memset(s, 0, 128);
    i = 0;
    while (buf[i] != '\0')
    {
        *(s + i) = buf[i];
        ++i;
    }
    *(s + i) = '\0';
}
