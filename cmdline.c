/**********************************************************************************
 * Program to test the C implementation of the zxcvbn password strength estimator.
 * Copyright (c) 2015-2017 Tony Evans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 **********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <zxcvbn.h>

/* For pre-compiled headers under windows */
#ifdef _WIN32
#include "stdafx.h"
#endif

int main() {
    int i;
    char Line[1024];
    double e;
    while(fgets(Line, sizeof Line, stdin)) {
        /* Drop the trailing newline character */
        for(i = 0; i < (int)(sizeof Line - 1); ++i) {
            if (Line[i] < ' ') {
                Line[i] = 0;
                break;
            }
        }
        e = ZxcvbnMatch(Line, 0, 0);
        printf("%.17g\t%s\n", e, Line);
    }
    return 0;
}
