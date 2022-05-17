/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include "fdlibm.h"

#ifdef __STDC__
	float truncf(float x)
#else
	float truncf(x)
	float x;
#endif
{
    int32_t ix = _asint32 (x);
    int32_t mask;
    int exp;

    exp = _exponent32(ix) - 127;

    if (unlikely(exp == 128))
        return x + x;

    /* compute portion of value with useful bits */
    if (exp < 0)
        /* less than one, save sign bit */
        mask = 0x80000000;
    else
        /* otherwise, save sign, exponent and any useful bits */
        mask = ~(0x007fffff >> exp);

    return _asfloat(ix & mask);
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
	double trunc(double x)
#else
	double trunc(x)
	double x;
#endif
{
    return (double) truncf((float) x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
