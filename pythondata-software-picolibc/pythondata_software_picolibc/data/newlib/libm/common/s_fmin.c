/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */
/*
FUNCTION
<<fmin>>, <<fminf>>---minimum
INDEX
	fmin
INDEX
	fminf

SYNOPSIS
	#include <math.h>
	double fmin(double <[x]>, double <[y]>);
	float fminf(float <[x]>, float <[y]>);

DESCRIPTION
The <<fmin>> functions determine the minimum numeric value of their arguments.
NaN arguments are treated as missing data:  if one argument is a NaN and the
other numeric, then the <<fmin>> functions choose the numeric value.

RETURNS
The <<fmin>> functions return the minimum numeric value of their arguments.

PORTABILITY
ANSI C, POSIX.

*/

#include "fdlibm.h"

#ifndef _DOUBLE_IS_32BITS

double fmin(double x, double y)
{
    if (issignaling(x) || issignaling(y))
        return x + y;

    if (isnan(x))
        return y;

    if (isnan(y))
        return x;

    return x < y ? x : y;
}

#endif /* _DOUBLE_IS_32BITS */
