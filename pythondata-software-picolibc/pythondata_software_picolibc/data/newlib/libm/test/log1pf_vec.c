/*
 * Copyright (c) 1994 Cygnus Support.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * and/or other materials related to such
 * distribution and use acknowledge that the software was developed
 * at Cygnus Support, Inc.  Cygnus Support, Inc. may not be used to
 * endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include "test.h"
 one_line_type log1pf_vec[] = {
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff33333, 0x33333333},	/* -nan=f(-1.2)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff30a3d, 0x70a3d70a},	/* -nan=f(-1.19)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff2e147, 0xae147ae1},	/* -nan=f(-1.18)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff2b851, 0xeb851eb8},	/* -nan=f(-1.17)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff28f5c, 0x28f5c28f},	/* -nan=f(-1.16)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff26666, 0x66666666},	/* -nan=f(-1.15)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff23d70, 0xa3d70a3d},	/* -nan=f(-1.14)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff2147a, 0xe147ae14},	/* -nan=f(-1.13)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff1eb85, 0x1eb851eb},	/* -nan=f(-1.12)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff1c28f, 0x5c28f5c2},	/* -nan=f(-1.11)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff19999, 0x99999999},	/* -nan=f(-1.1)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff170a3, 0xd70a3d70},	/* -nan=f(-1.09)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff147ae, 0x147ae147},	/* -nan=f(-1.08)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff11eb8, 0x51eb851e},	/* -nan=f(-1.07)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff0f5c2, 0x8f5c28f5},	/* -nan=f(-1.06)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff0cccc, 0xcccccccc},	/* -nan=f(-1.05)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff0a3d7, 0x0a3d70a3},	/* -nan=f(-1.04)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff07ae1, 0x47ae147a},	/* -nan=f(-1.03)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff051eb, 0x851eb851},	/* -nan=f(-1.02)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff028f5, 0xc28f5c28},	/* -nan=f(-1.01)*/
{ 0, 0, 34,__LINE__, 0xfff00000, 0x00000000, 0xbfefffff, 0xfffffffe},	/* -inf=f(-1)*/
{10, 0,123,__LINE__, 0xc0126bb1, 0xfbb55716, 0xbfefae14, 0x7ae147ac},	/* -4.60517=f(-0.99)*/
{11, 0,123,__LINE__, 0xc00f4bd3, 0x37ac1faf, 0xbfef5c28, 0xf5c28f5a},	/* -3.91202=f(-0.98)*/
{11, 0,123,__LINE__, 0xc00c0d6e, 0xba142ca6, 0xbfef0a3d, 0x70a3d708},	/* -3.50656=f(-0.97)*/
{11, 0,123,__LINE__, 0xc009c041, 0xafed8e77, 0xbfeeb851, 0xeb851eb6},	/* -3.21888=f(-0.96)*/
{11, 0,123,__LINE__, 0xc007f742, 0x5b73e3d1, 0xbfee6666, 0x66666664},	/* -2.99573=f(-0.95)*/
{11, 0,123,__LINE__, 0xc00681dd, 0x750044d6, 0xbfee147a, 0xe147ae12},	/* -2.81341=f(-0.94)*/
{11, 0,123,__LINE__, 0xc005462a, 0x2e085879, 0xbfedc28f, 0x5c28f5c0},	/* -2.65926=f(-0.93)*/
{11, 0,123,__LINE__, 0xc00434b1, 0x542efee9, 0xbfed70a3, 0xd70a3d6e},	/* -2.52573=f(-0.92)*/
{11, 0,123,__LINE__, 0xc0034379, 0x23da1947, 0xbfed1eb8, 0x51eb851c},	/* -2.40795=f(-0.91)*/
{11, 0,123,__LINE__, 0xc0026bb1, 0x9bb55556, 0xbfeccccc, 0xccccccca},	/* -2.30258=f(-0.9)*/
{11, 0,123,__LINE__, 0xc001a87f, 0xae7715db, 0xbfec7ae1, 0x47ae1478},	/* -2.20727=f(-0.89)*/
{11, 0,123,__LINE__, 0xc000f64c, 0xb541b65b, 0xbfec28f5, 0xc28f5c26},	/* -2.12026=f(-0.88)*/
{11, 0,123,__LINE__, 0xc000525f, 0x51256ca0, 0xbfebd70a, 0x3d70a3d4},	/* -2.04022=f(-0.87)*/
{11, 0,123,__LINE__, 0xbfff7532, 0xdc9393fa, 0xbfeb851e, 0xb851eb82},	/* -1.96611=f(-0.86)*/
{11, 0,123,__LINE__, 0xbffe5a9a, 0xa6e56efc, 0xbfeb3333, 0x33333330},	/* -1.89712=f(-0.85)*/
{11, 0,123,__LINE__, 0xbffd5240, 0xc4e0e0b4, 0xbfeae147, 0xae147ade},	/* -1.83258=f(-0.84)*/
{11, 0,123,__LINE__, 0xbffc59ef, 0x5085fb1e, 0xbfea8f5c, 0x28f5c28c},	/* -1.77196=f(-0.83)*/
{11, 0,123,__LINE__, 0xbffb6fd0, 0x6f5386a2, 0xbfea3d70, 0xa3d70a3a},	/* -1.7148=f(-0.82)*/
{11, 0,123,__LINE__, 0xbffa925a, 0xe62a3ed5, 0xbfe9eb85, 0x1eb851e8},	/* -1.66073=f(-0.81)*/
{11, 0,123,__LINE__, 0xbff9c042, 0x07ed8d3b, 0xbfe99999, 0x99999996},	/* -1.60944=f(-0.8)*/
{12, 0,123,__LINE__, 0xbff8f869, 0xe163ade7, 0xbfe947ae, 0x147ae144},	/* -1.56065=f(-0.79)*/
{12, 0,123,__LINE__, 0xbff839dd, 0xdd710ebf, 0xbfe8f5c2, 0x8f5c28f2},	/* -1.51413=f(-0.78)*/
{12, 0,123,__LINE__, 0xbff783ca, 0xdcef242c, 0xbfe8a3d7, 0x0a3d70a0},	/* -1.46968=f(-0.77)*/
{12, 0,123,__LINE__, 0xbff6d577, 0xeb064fbe, 0xbfe851eb, 0x851eb84e},	/* -1.42712=f(-0.76)*/
{12, 0,123,__LINE__, 0xbff62e42, 0xfefa39ef, 0xbfe7ffff, 0xfffffffc},	/* -1.38629=f(-0.75)*/
{12, 0,123,__LINE__, 0xbff58d9d, 0x22cdbc49, 0xbfe7ae14, 0x7ae147aa},	/* -1.34707=f(-0.74)*/
{12, 0,123,__LINE__, 0xbff4f307, 0x91c4cfff, 0xbfe75c28, 0xf5c28f58},	/* -1.30933=f(-0.73)*/
{12, 0,123,__LINE__, 0xbff45e11, 0x5d167702, 0xbfe70a3d, 0x70a3d706},	/* -1.27297=f(-0.72)*/
{12, 0,123,__LINE__, 0xbff3ce55, 0x435ca798, 0xbfe6b851, 0xeb851eb4},	/* -1.23787=f(-0.71)*/
{12, 0,123,__LINE__, 0xbff34378, 0xf212fc79, 0xbfe66666, 0x66666662},	/* -1.20397=f(-0.7)*/
{12, 0,123,__LINE__, 0xbff2bd2a, 0x5ba27981, 0xbfe6147a, 0xe147ae10},	/* -1.17118=f(-0.69)*/
{12, 0,123,__LINE__, 0xbff23b1f, 0x7763c381, 0xbfe5c28f, 0x5c28f5be},	/* -1.13943=f(-0.68)*/
{12, 0,123,__LINE__, 0xbff1bd15, 0x12bd4793, 0xbfe570a3, 0xd70a3d6c},	/* -1.10866=f(-0.67)*/
{12, 0,123,__LINE__, 0xbff142ce, 0x0017ed2d, 0xbfe51eb8, 0x51eb851a},	/* -1.07881=f(-0.66)*/
{12, 0,123,__LINE__, 0xbff0cc12, 0x366c4843, 0xbfe4cccc, 0xccccccc8},	/* -1.04982=f(-0.65)*/
{12, 0,123,__LINE__, 0xbff058ae, 0xefd669ab, 0xbfe47ae1, 0x47ae1476},	/* -1.02165=f(-0.64)*/
{12, 0,123,__LINE__, 0xbfefd0ea, 0x1dd44b73, 0xbfe428f5, 0xc28f5c24},	/* -0.994252=f(-0.63)*/
{12, 0,123,__LINE__, 0xbfeef672, 0xcd5a43bb, 0xbfe3d70a, 0x3d70a3d2},	/* -0.967584=f(-0.62)*/
{12, 0,123,__LINE__, 0xbfee21a8, 0x4f3bac6d, 0xbfe3851e, 0xb851eb80},	/* -0.941609=f(-0.61)*/
{12, 0,123,__LINE__, 0xbfed5241, 0x10e0e088, 0xbfe33333, 0x3333332e},	/* -0.916291=f(-0.6)*/
{12, 0,123,__LINE__, 0xbfec87f8, 0xa5188d62, 0xbfe2e147, 0xae147adc},	/* -0.891598=f(-0.59)*/
{12, 0,123,__LINE__, 0xbfebc290, 0x779c5eab, 0xbfe28f5c, 0x28f5c28a},	/* -0.867501=f(-0.58)*/
{12, 0,123,__LINE__, 0xbfeb01cd, 0x7c68d4b0, 0xbfe23d70, 0xa3d70a38},	/* -0.84397=f(-0.57)*/
{12, 0,123,__LINE__, 0xbfea4579, 0x04a211cd, 0xbfe1eb85, 0x1eb851e6},	/* -0.820981=f(-0.56)*/
{13, 0,123,__LINE__, 0xbfe98d60, 0x115465ac, 0xbfe19999, 0x99999994},	/* -0.798508=f(-0.55)*/
{13, 0,123,__LINE__, 0xbfe8d953, 0x0074c06b, 0xbfe147ae, 0x147ae142},	/* -0.776529=f(-0.54)*/
{13, 0,123,__LINE__, 0xbfe82924, 0xfeb899a2, 0xbfe0f5c2, 0x8f5c28f0},	/* -0.755023=f(-0.53)*/
{13, 0,123,__LINE__, 0xbfe77cac, 0xd712658c, 0xbfe0a3d7, 0x0a3d709e},	/* -0.733969=f(-0.52)*/
{13, 0,123,__LINE__, 0xbfe6d3c3, 0x1a6e4efd, 0xbfe051eb, 0x851eb84c},	/* -0.71335=f(-0.51)*/
{13, 0,123,__LINE__, 0xbfe62e42, 0xfefa39ef, 0xbfdfffff, 0xfffffff4},	/* -0.693147=f(-0.5)*/
{13, 0,123,__LINE__, 0xbfe58c09, 0xea70aebb, 0xbfdf5c28, 0xf5c28f50},	/* -0.673345=f(-0.49)*/
{13, 0,123,__LINE__, 0xbfe4ecf7, 0x27dc5251, 0xbfdeb851, 0xeb851eac},	/* -0.653926=f(-0.48)*/
{13, 0,123,__LINE__, 0xbfe450ec, 0x3bec9432, 0xbfde147a, 0xe147ae08},	/* -0.634878=f(-0.47)*/
{13, 0,123,__LINE__, 0xbfe3b7cc, 0x06ee3691, 0xbfdd70a3, 0xd70a3d64},	/* -0.616186=f(-0.46)*/
{13, 0,123,__LINE__, 0xbfe3217b, 0x042fc85e, 0xbfdccccc, 0xccccccc0},	/* -0.597837=f(-0.45)*/
{13, 0,123,__LINE__, 0xbfe28ddf, 0x820e219e, 0xbfdc28f5, 0xc28f5c1c},	/* -0.579818=f(-0.44)*/
{13, 0,123,__LINE__, 0xbfe1fce0, 0xd6fa7795, 0xbfdb851e, 0xb851eb78},	/* -0.562119=f(-0.43)*/
{13, 0,123,__LINE__, 0xbfe16e67, 0xa35526d1, 0xbfdae147, 0xae147ad4},	/* -0.544727=f(-0.42)*/
{13, 0,123,__LINE__, 0xbfe0e25e, 0x0c304735, 0xbfda3d70, 0xa3d70a30},	/* -0.527633=f(-0.41)*/
{13, 0,123,__LINE__, 0xbfe058ae, 0xffd669a7, 0xbfd99999, 0x9999998c},	/* -0.510826=f(-0.4)*/
{13, 0,123,__LINE__, 0xbfdfa28c, 0xf1006697, 0xbfd8f5c2, 0x8f5c28e8},	/* -0.494296=f(-0.39)*/
{13, 0,123,__LINE__, 0xbfde9823, 0x70957227, 0xbfd851eb, 0x851eb844},	/* -0.478036=f(-0.38)*/
{13, 0,123,__LINE__, 0xbfdd91fd, 0x354451af, 0xbfd7ae14, 0x7ae147a0},	/* -0.462035=f(-0.37)*/
{13, 0,123,__LINE__, 0xbfdc8ff7, 0xdf9a9a26, 0xbfd70a3d, 0x70a3d6fc},	/* -0.446287=f(-0.36)*/
{13, 0,123,__LINE__, 0xbfdb91f2, 0x783a1c79, 0xbfd66666, 0x66666658},	/* -0.430783=f(-0.35)*/
{13, 0,123,__LINE__, 0xbfda97ce, 0x1c848b4f, 0xbfd5c28f, 0x5c28f5b4},	/* -0.415515=f(-0.34)*/
{13, 0,123,__LINE__, 0xbfd9a16c, 0xbdd810ac, 0xbfd51eb8, 0x51eb8510},	/* -0.400478=f(-0.33)*/
{13, 0,123,__LINE__, 0xbfd8aeb1, 0xa44d2283, 0xbfd47ae1, 0x47ae146c},	/* -0.385662=f(-0.32)*/
{14, 0,123,__LINE__, 0xbfd7bf81, 0xe5c971bc, 0xbfd3d70a, 0x3d70a3c8},	/* -0.371064=f(-0.31)*/
{14, 0,123,__LINE__, 0xbfd6d3c3, 0x372a63e4, 0xbfd33333, 0x33333324},	/* -0.356675=f(-0.3)*/
{14, 0,123,__LINE__, 0xbfd5eb5c, 0x6c693eee, 0xbfd28f5c, 0x28f5c280},	/* -0.34249=f(-0.29)*/
{14, 0,123,__LINE__, 0xbfd50635, 0xedd6f9da, 0xbfd1eb85, 0x1eb851dc},	/* -0.328504=f(-0.28)*/
{14, 0,123,__LINE__, 0xbfd42438, 0x98fa36e9, 0xbfd147ae, 0x147ae138},	/* -0.314711=f(-0.27)*/
{14, 0,123,__LINE__, 0xbfd3454e, 0x3db42307, 0xbfd0a3d7, 0x0a3d7094},	/* -0.301105=f(-0.26)*/
{14, 0,123,__LINE__, 0xbfd26962, 0x1134db92, 0xbfcfffff, 0xffffffe0},	/* -0.287682=f(-0.25)*/
{14, 0,123,__LINE__, 0xbfd1905f, 0x87b29a53, 0xbfceb851, 0xeb851e98},	/* -0.274437=f(-0.24)*/
{14, 0,123,__LINE__, 0xbfd0ba33, 0x4c63a1fa, 0xbfcd70a3, 0xd70a3d50},	/* -0.261365=f(-0.23)*/
{14, 0,123,__LINE__, 0xbfcfcd94, 0xeef8a90c, 0xbfcc28f5, 0xc28f5c08},	/* -0.248461=f(-0.22)*/
{14, 0,123,__LINE__, 0xbfce2c26, 0x2ee1d24b, 0xbfcae147, 0xae147ac0},	/* -0.235722=f(-0.21)*/
{14, 0,123,__LINE__, 0xbfcc8ff7, 0xcf9a9a22, 0xbfc99999, 0x99999978},	/* -0.223144=f(-0.2)*/
{14, 0,123,__LINE__, 0xbfcaf8e8, 0x1ab8151e, 0xbfc851eb, 0x851eb830},	/* -0.210721=f(-0.19)*/
{14, 0,123,__LINE__, 0xbfc966d7, 0x34924746, 0xbfc70a3d, 0x70a3d6e8},	/* -0.198451=f(-0.18)*/
{14, 0,123,__LINE__, 0xbfc7d9a5, 0xceee7530, 0xbfc5c28f, 0x5c28f5a0},	/* -0.18633=f(-0.17)*/
{15, 0,123,__LINE__, 0xbfc65136, 0x2eb955df, 0xbfc47ae1, 0x47ae1458},	/* -0.174353=f(-0.16)*/
{15, 0,123,__LINE__, 0xbfc4cd6b, 0xa6a55088, 0xbfc33333, 0x33333310},	/* -0.162519=f(-0.15)*/
{15, 0,123,__LINE__, 0xbfc34e2a, 0x1aefffd6, 0xbfc1eb85, 0x1eb851c8},	/* -0.150823=f(-0.14)*/
{15, 0,123,__LINE__, 0xbfc1d356, 0xd89d8230, 0xbfc0a3d7, 0x0a3d7080},	/* -0.139262=f(-0.13)*/
{15, 0,123,__LINE__, 0xbfc05cd8, 0x0470d3d6, 0xbfbeb851, 0xeb851e71},	/* -0.127833=f(-0.12)*/
{15, 0,123,__LINE__, 0xbfbdd528, 0xfed22bc7, 0xbfbc28f5, 0xc28f5be2},	/* -0.116534=f(-0.11)*/
{15, 0,123,__LINE__, 0xbfbaf8e8, 0x2826b325, 0xbfb99999, 0x99999953},	/* -0.105361=f(-0.1)*/
{15, 0,123,__LINE__, 0xbfb824be, 0xb4df23dd, 0xbfb70a3d, 0x70a3d6c4},	/* -0.0943107=f(-0.09)*/
{16, 0,123,__LINE__, 0xbfb5587f, 0x3b221d4b, 0xbfb47ae1, 0x47ae1435},	/* -0.0833816=f(-0.08)*/
{16, 0,123,__LINE__, 0xbfb293fe, 0x31c0018f, 0xbfb1eb85, 0x1eb851a6},	/* -0.0725707=f(-0.07)*/
{16, 0,123,__LINE__, 0xbfafae21, 0xfa89619f, 0xbfaeb851, 0xeb851e2d},	/* -0.0618754=f(-0.06)*/
{16, 0,123,__LINE__, 0xbfaa431d, 0x6288bae7, 0xbfa99999, 0x9999990e},	/* -0.0512933=f(-0.05)*/
{17, 0,123,__LINE__, 0xbfa4e69e, 0xced80eae, 0xbfa47ae1, 0x47ae13ef},	/* -0.040822=f(-0.04)*/
{17, 0,123,__LINE__, 0xbf9f30b2, 0xc428c90e, 0xbf9eb851, 0xeb851da0},	/* -0.0304592=f(-0.03)*/
{18, 0,123,__LINE__, 0xbf94b004, 0xb50a77b3, 0xbf947ae1, 0x47ae1362},	/* -0.0202027=f(-0.02)*/
{19, 0,123,__LINE__, 0xbf849545, 0x36ade43a, 0xbf847ae1, 0x47ae1249},	/* -0.0100503=f(-0.01)*/
{62, 0,123,__LINE__, 0x3cd18fff, 0xfffffffe, 0x3cd19000, 0x00000000},	/* 9.74915e-16=f(9.74915e-16)*/
{37, 0,123,__LINE__, 0x3f8460d6, 0xc52f9951, 0x3f847ae1, 0x47ae16ad},	/* 0.00995033=f(0.01)*/
{36, 0,123,__LINE__, 0x3f944723, 0xcaeb206a, 0x3f947ae1, 0x47ae1594},	/* 0.0198026=f(0.02)*/
{37, 0,123,__LINE__, 0x3f9e44a9, 0x988f9d39, 0x3f9eb851, 0xeb851fd2},	/* 0.0295588=f(0.03)*/
{37, 0,123,__LINE__, 0x3fa414bc, 0xb940f031, 0x3fa47ae1, 0x47ae1508},	/* 0.0392207=f(0.04)*/
{37, 0,123,__LINE__, 0x3fa8fb06, 0x450b296f, 0x3fa99999, 0x99999a27},	/* 0.0487902=f(0.05)*/
{36, 0,123,__LINE__, 0x3fadd56c, 0x12aa0e92, 0x3faeb851, 0xeb851f46},	/* 0.0582689=f(0.06)*/
{38, 0,123,__LINE__, 0x3fb15213, 0xc3aecfb0, 0x3fb1eb85, 0x1eb85232},	/* 0.0676586=f(0.07)*/
{37, 0,123,__LINE__, 0x3fb3b3b7, 0xfba279c8, 0x3fb47ae1, 0x47ae14c1},	/* 0.076961=f(0.08)*/
{39, 0,123,__LINE__, 0x3fb60fbd, 0xe11778ab, 0x3fb70a3d, 0x70a3d750},	/* 0.0861777=f(0.09)*/
{40, 0,123,__LINE__, 0x3fb8663f, 0x7f0dbb24, 0x3fb99999, 0x999999df},	/* 0.0953102=f(0.1)*/
{38, 0,123,__LINE__, 0x3fbab756, 0x828578d9, 0x3fbc28f5, 0xc28f5c6e},	/* 0.10436=f(0.11)*/
{36, 0,123,__LINE__, 0x3fbd031b, 0xcace7969, 0x3fbeb851, 0xeb851efd},	/* 0.113329=f(0.12)*/
{36, 0,123,__LINE__, 0x3fbf49a7, 0x8d6bda0c, 0x3fc0a3d7, 0x0a3d70c6},	/* 0.122218=f(0.13)*/
{38, 0,123,__LINE__, 0x3fc0c588, 0xbc110070, 0x3fc1eb85, 0x1eb8520e},	/* 0.131028=f(0.14)*/
{36, 0,123,__LINE__, 0x3fc1e3b8, 0x30fe6a18, 0x3fc33333, 0x33333356},	/* 0.139762=f(0.15)*/
{36, 0,123,__LINE__, 0x3fc2ff6d, 0x37682931, 0x3fc47ae1, 0x47ae149e},	/* 0.14842=f(0.16)*/
{36, 0,123,__LINE__, 0x3fc418b2, 0xea86878c, 0x3fc5c28f, 0x5c28f5e6},	/* 0.157004=f(0.17)*/
{36, 0,123,__LINE__, 0x3fc52f93, 0xcb27caea, 0x3fc70a3d, 0x70a3d72e},	/* 0.165514=f(0.18)*/
{36, 0,123,__LINE__, 0x3fc6441a, 0x1642b5a3, 0x3fc851eb, 0x851eb876},	/* 0.173953=f(0.19)*/
{36, 0,123,__LINE__, 0x3fc75650, 0x1739ebcb, 0x3fc99999, 0x999999be},	/* 0.182322=f(0.2)*/
{36, 0,123,__LINE__, 0x3fc8663f, 0x6d995e0c, 0x3fcae147, 0xae147b06},	/* 0.19062=f(0.21)*/
{37, 0,123,__LINE__, 0x3fc973f1, 0xe572987f, 0x3fcc28f5, 0xc28f5c4e},	/* 0.198851=f(0.22)*/
{39, 0,123,__LINE__, 0x3fca7f70, 0xbef112f3, 0x3fcd70a3, 0xd70a3d96},	/* 0.207014=f(0.23)*/
{40, 0,123,__LINE__, 0x3fcb88c5, 0x00ef8fd3, 0x3fceb851, 0xeb851ede},	/* 0.215111=f(0.24)*/
{37, 0,123,__LINE__, 0x3fcc8ff7, 0xc79a9a22, 0x3fd00000, 0x00000013},	/* 0.223144=f(0.25)*/
{35, 0,123,__LINE__, 0x3fcd9511, 0x9160445f, 0x3fd0a3d7, 0x0a3d70b7},	/* 0.231112=f(0.26)*/
{37, 0,123,__LINE__, 0x3fce981b, 0x277f6e22, 0x3fd147ae, 0x147ae15b},	/* 0.239017=f(0.27)*/
{36, 0,123,__LINE__, 0x3fcf991c, 0x6eb3b379, 0x3fd1eb85, 0x1eb851ff},	/* 0.24686=f(0.28)*/
{37, 0,123,__LINE__, 0x3fd04c0e, 0xd913ff92, 0x3fd28f5c, 0x28f5c2a3},	/* 0.254642=f(0.29)*/
{37, 0,123,__LINE__, 0x3fd0ca93, 0x85ba5765, 0x3fd33333, 0x33333347},	/* 0.262364=f(0.3)*/
{36, 0,123,__LINE__, 0x3fd1481f, 0xe8cb7b28, 0x3fd3d70a, 0x3d70a3eb},	/* 0.270027=f(0.31)*/
{39, 0,123,__LINE__, 0x3fd1c4b7, 0xe16fe88f, 0x3fd47ae1, 0x47ae148f},	/* 0.277632=f(0.32)*/
{37, 0,123,__LINE__, 0x3fd2405f, 0x382fd40d, 0x3fd51eb8, 0x51eb8533},	/* 0.285179=f(0.33)*/
{36, 0,123,__LINE__, 0x3fd2bb19, 0x57fdd204, 0x3fd5c28f, 0x5c28f5d7},	/* 0.29267=f(0.34)*/
{41, 0,123,__LINE__, 0x3fd334e9, 0xdfbf66c5, 0x3fd66666, 0x6666667b},	/* 0.300105=f(0.35)*/
{37, 0,123,__LINE__, 0x3fd3add4, 0x59a7515c, 0x3fd70a3d, 0x70a3d71f},	/* 0.307485=f(0.36)*/
{36, 0,123,__LINE__, 0x3fd425db, 0xf5bf7351, 0x3fd7ae14, 0x7ae147c3},	/* 0.314811=f(0.37)*/
{37, 0,123,__LINE__, 0x3fd49d04, 0x182b0222, 0x3fd851eb, 0x851eb867},	/* 0.322083=f(0.38)*/
{37, 0,123,__LINE__, 0x3fd5134f, 0xfb0e7b6c, 0x3fd8f5c2, 0x8f5c290b},	/* 0.329304=f(0.39)*/
{38, 0,123,__LINE__, 0x3fd588c2, 0xdda57db4, 0x3fd99999, 0x999999af},	/* 0.336472=f(0.4)*/
{36, 0,123,__LINE__, 0x3fd5fd5f, 0xa92d0f7f, 0x3fda3d70, 0xa3d70a53},	/* 0.34359=f(0.41)*/
{38, 0,123,__LINE__, 0x3fd67129, 0x7b023156, 0x3fdae147, 0xae147af7},	/* 0.350657=f(0.42)*/
{39, 0,123,__LINE__, 0x3fd6e423, 0x5f8fad1e, 0x3fdb851e, 0xb851eb9b},	/* 0.357674=f(0.43)*/
{36, 0,123,__LINE__, 0x3fd75650, 0x101d7a04, 0x3fdc28f5, 0xc28f5c3f},	/* 0.364643=f(0.44)*/
{38, 0,123,__LINE__, 0x3fd7c7b2, 0x79fcf7ba, 0x3fdccccc, 0xcccccce3},	/* 0.371564=f(0.45)*/
{38, 0,123,__LINE__, 0x3fd8384d, 0x7ae53272, 0x3fdd70a3, 0xd70a3d87},	/* 0.378436=f(0.46)*/
{38, 0,123,__LINE__, 0x3fd8a823, 0xa012a431, 0x3fde147a, 0xe147ae2b},	/* 0.385262=f(0.47)*/
{36, 0,123,__LINE__, 0x3fd91737, 0xaaa12e40, 0x3fdeb851, 0xeb851ecf},	/* 0.392042=f(0.48)*/
{35, 0,123,__LINE__, 0x3fd9858c, 0x4d487c86, 0x3fdf5c28, 0xf5c28f73},	/* 0.398776=f(0.49)*/
{36, 0,123,__LINE__, 0x3fd9f323, 0xecbf984c, 0x3fe00000, 0x0000000b},	/* 0.405465=f(0.5)*/
{38, 0,123,__LINE__, 0x3fda6001, 0x2162a648, 0x3fe051eb, 0x851eb85d},	/* 0.41211=f(0.51)*/
{38, 0,123,__LINE__, 0x3fdacc26, 0x61346047, 0x3fe0a3d7, 0x0a3d70af},	/* 0.41871=f(0.52)*/
{37, 0,123,__LINE__, 0x3fdb3796, 0x15d2aeb4, 0x3fe0f5c2, 0x8f5c2901},	/* 0.425268=f(0.53)*/
{36, 0,123,__LINE__, 0x3fdba252, 0xc6584ce6, 0x3fe147ae, 0x147ae153},	/* 0.431782=f(0.54)*/
{36, 0,123,__LINE__, 0x3fdc0c5e, 0x712c4ec9, 0x3fe19999, 0x999999a5},	/* 0.438255=f(0.55)*/
{37, 0,123,__LINE__, 0x3fdc75bb, 0x86781f59, 0x3fe1eb85, 0x1eb851f7},	/* 0.444686=f(0.56)*/
{38, 0,123,__LINE__, 0x3fdcde6c, 0x4166ecaf, 0x3fe23d70, 0xa3d70a49},	/* 0.451076=f(0.57)*/
{37, 0,123,__LINE__, 0x3fdd4672, 0xd242bb54, 0x3fe28f5c, 0x28f5c29b},	/* 0.457425=f(0.58)*/
{40, 0,123,__LINE__, 0x3fddadd1, 0x5ebab03f, 0x3fe2e147, 0xae147aed},	/* 0.463734=f(0.59)*/
{38, 0,123,__LINE__, 0x3fde148a, 0x2a2726cc, 0x3fe33333, 0x3333333f},	/* 0.470004=f(0.6)*/
{36, 0,123,__LINE__, 0x3fde7a9e, 0xf58c0d62, 0x3fe3851e, 0xb851eb91},	/* 0.476234=f(0.61)*/
{38, 0,123,__LINE__, 0x3fdee011, 0xf098694f, 0x3fe3d70a, 0x3d70a3e3},	/* 0.482426=f(0.62)*/
{37, 0,123,__LINE__, 0x3fdf44e5, 0x1923e6ef, 0x3fe428f5, 0xc28f5c35},	/* 0.48858=f(0.63)*/
{37, 0,123,__LINE__, 0x3fdfa91a, 0x63ab503b, 0x3fe47ae1, 0x47ae1487},	/* 0.494696=f(0.64)*/
{39, 0,123,__LINE__, 0x3fe00659, 0xddc56482, 0x3fe4cccc, 0xccccccd9},	/* 0.500775=f(0.65)*/
{39, 0,123,__LINE__, 0x3fe037d9, 0x94e214ec, 0x3fe51eb8, 0x51eb852b},	/* 0.506818=f(0.66)*/
{39, 0,123,__LINE__, 0x3fe0690d, 0x1d619495, 0x3fe570a3, 0xd70a3d7d},	/* 0.512824=f(0.67)*/
{38, 0,123,__LINE__, 0x3fe099f5, 0x734be478, 0x3fe5c28f, 0x5c28f5cf},	/* 0.518794=f(0.68)*/
{38, 0,123,__LINE__, 0x3fe0ca93, 0x7b1fd520, 0x3fe6147a, 0xe147ae21},	/* 0.524729=f(0.69)*/
{39, 0,123,__LINE__, 0x3fe0fae8, 0x1550e5cd, 0x3fe66666, 0x66666673},	/* 0.530628=f(0.7)*/
{40, 0,123,__LINE__, 0x3fe12af4, 0x1e5f8e80, 0x3fe6b851, 0xeb851ec5},	/* 0.536493=f(0.71)*/
{38, 0,123,__LINE__, 0x3fe15ab8, 0x818b9f2e, 0x3fe70a3d, 0x70a3d717},	/* 0.542324=f(0.72)*/
{41, 0,123,__LINE__, 0x3fe18a35, 0xee64740a, 0x3fe75c28, 0xf5c28f69},	/* 0.548121=f(0.73)*/
{39, 0,123,__LINE__, 0x3fe1b96d, 0x48d2d963, 0x3fe7ae14, 0x7ae147bb},	/* 0.553885=f(0.74)*/
{41, 0,123,__LINE__, 0x3fe1e85f, 0x5e7040d0, 0x3fe80000, 0x0000000d},	/* 0.559616=f(0.75)*/
{38, 0,123,__LINE__, 0x3fe2170c, 0xf9526211, 0x3fe851eb, 0x851eb85f},	/* 0.565314=f(0.76)*/
{39, 0,123,__LINE__, 0x3fe24576, 0xe01f9f0e, 0x3fe8a3d7, 0x0a3d70b1},	/* 0.57098=f(0.77)*/
{40, 0,123,__LINE__, 0x3fe2739d, 0xd622d4d1, 0x3fe8f5c2, 0x8f5c2903},	/* 0.576613=f(0.78)*/
{39, 0,123,__LINE__, 0x3fe2a182, 0xad3f27aa, 0x3fe947ae, 0x147ae155},	/* 0.582216=f(0.79)*/
{41, 0,123,__LINE__, 0x3fe2cf25, 0xfe672aa7, 0x3fe99999, 0x999999a7},	/* 0.587787=f(0.8)*/
{39, 0,123,__LINE__, 0x3fe2fc88, 0x953eda8f, 0x3fe9eb85, 0x1eb851f9},	/* 0.593327=f(0.81)*/
{39, 0,123,__LINE__, 0x3fe329ab, 0x285e5574, 0x3fea3d70, 0xa3d70a4b},	/* 0.598836=f(0.82)*/
{41, 0,123,__LINE__, 0x3fe3568e, 0x6b5d5219, 0x3fea8f5c, 0x28f5c29d},	/* 0.604316=f(0.83)*/
{46, 0,123,__LINE__, 0x3fe38333, 0x0ee3e002, 0x3feae147, 0xae147aef},	/* 0.609766=f(0.84)*/
{40, 0,123,__LINE__, 0x3fe3af99, 0xd206cef4, 0x3feb3333, 0x33333341},	/* 0.615186=f(0.85)*/
{39, 0,123,__LINE__, 0x3fe3dbc3, 0x3d0f4d02, 0x3feb851e, 0xb851eb93},	/* 0.620576=f(0.86)*/
{39, 0,123,__LINE__, 0x3fe407b0, 0x099aa826, 0x3febd70a, 0x3d70a3e5},	/* 0.625938=f(0.87)*/
{41, 0,123,__LINE__, 0x3fe43360, 0xdd30f589, 0x3fec28f5, 0xc28f5c37},	/* 0.631272=f(0.88)*/
{42, 0,123,__LINE__, 0x3fe45ed6, 0x5ab7dd3e, 0x3fec7ae1, 0x47ae1489},	/* 0.636577=f(0.89)*/
{41, 0,123,__LINE__, 0x3fe48a11, 0x2280d6ac, 0x3feccccc, 0xccccccdb},	/* 0.641854=f(0.9)*/
{42, 0,123,__LINE__, 0x3fe4b511, 0xe31806b0, 0x3fed1eb8, 0x51eb852d},	/* 0.647103=f(0.91)*/
{40, 0,123,__LINE__, 0x3fe4dfd9, 0x163763af, 0x3fed70a3, 0xd70a3d7f},	/* 0.652325=f(0.92)*/
{40, 0,123,__LINE__, 0x3fe50a67, 0x659d2342, 0x3fedc28f, 0x5c28f5d1},	/* 0.65752=f(0.93)*/
{44, 0,123,__LINE__, 0x3fe534bd, 0x67d108c4, 0x3fee147a, 0xe147ae23},	/* 0.662688=f(0.94)*/
{42, 0,123,__LINE__, 0x3fe55edb, 0xb1087490, 0x3fee6666, 0x66666675},	/* 0.667829=f(0.95)*/
{41, 0,123,__LINE__, 0x3fe588c2, 0xd3328d60, 0x3feeb851, 0xeb851ec7},	/* 0.672944=f(0.96)*/
{43, 0,123,__LINE__, 0x3fe5b273, 0x6e427a8e, 0x3fef0a3d, 0x70a3d719},	/* 0.678034=f(0.97)*/
{42, 0,123,__LINE__, 0x3fe5dbed, 0xef2c7044, 0x3fef5c28, 0xf5c28f6b},	/* 0.683097=f(0.98)*/
{45, 0,123,__LINE__, 0x3fe60532, 0xf1a66ac1, 0x3fefae14, 0x7ae147bd},	/* 0.688135=f(0.99)*/
{64, 0,123,__LINE__, 0x3fe62e42, 0xfefa39ef, 0x3ff00000, 0x00000007},	/* 0.693147=f(1)*/
{46, 0,123,__LINE__, 0x3fe6571e, 0x9e63cd5b, 0x3ff028f5, 0xc28f5c30},	/* 0.698135=f(1.01)*/
{42, 0,123,__LINE__, 0x3fe67fc6, 0x551ba4af, 0x3ff051eb, 0x851eb859},	/* 0.703098=f(1.02)*/
{48, 0,123,__LINE__, 0x3fe6a83a, 0xa660fe2e, 0x3ff07ae1, 0x47ae1482},	/* 0.708036=f(1.03)*/
{41, 0,123,__LINE__, 0x3fe6d07c, 0x1383c523, 0x3ff0a3d7, 0x0a3d70ab},	/* 0.71295=f(1.04)*/
{44, 0,123,__LINE__, 0x3fe6f88b, 0x1bee4227, 0x3ff0cccc, 0xccccccd4},	/* 0.71784=f(1.05)*/
{41, 0,123,__LINE__, 0x3fe72068, 0x3d2e8f11, 0x3ff0f5c2, 0x8f5c28fd},	/* 0.722706=f(1.06)*/
{40, 0,123,__LINE__, 0x3fe74814, 0x11eaca1d, 0x3ff11eb8, 0x51eb8526},	/* 0.727549=f(1.07)*/
{40, 0,123,__LINE__, 0x3fe76f8e, 0xd618218e, 0x3ff147ae, 0x147ae14f},	/* 0.732368=f(1.08)*/
{43, 0,123,__LINE__, 0x3fe796d9, 0x20f7fd87, 0x3ff170a3, 0xd70a3d78},	/* 0.737164=f(1.09)*/
{42, 0,123,__LINE__, 0x3fe7bdf3, 0x6901c7f3, 0x3ff19999, 0x999999a1},	/* 0.741937=f(1.1)*/
{43, 0,123,__LINE__, 0x3fe7e4de, 0x22fcb1c8, 0x3ff1c28f, 0x5c28f5ca},	/* 0.746688=f(1.11)*/
{40, 0,123,__LINE__, 0x3fe80b99, 0xc207dfad, 0x3ff1eb85, 0x1eb851f3},	/* 0.751416=f(1.12)*/
{40, 0,123,__LINE__, 0x3fe83226, 0xb7a2656b, 0x3ff2147a, 0xe147ae1c},	/* 0.756122=f(1.13)*/
{40, 0,123,__LINE__, 0x3fe85885, 0x73b31181, 0x3ff23d70, 0xa3d70a45},	/* 0.760806=f(1.14)*/
{39, 0,123,__LINE__, 0x3fe87eb6, 0x64900a2e, 0x3ff26666, 0x6666666e},	/* 0.765468=f(1.15)*/
{42, 0,123,__LINE__, 0x3fe8a4b9, 0xf7063d4d, 0x3ff28f5c, 0x28f5c297},	/* 0.770108=f(1.16)*/
{41, 0,123,__LINE__, 0x3fe8ca90, 0x9660a42c, 0x3ff2b851, 0xeb851ec0},	/* 0.774727=f(1.17)*/
{39, 0,123,__LINE__, 0x3fe8f03a, 0xac6f5cad, 0x3ff2e147, 0xae147ae9},	/* 0.779325=f(1.18)*/
{43, 0,123,__LINE__, 0x3fe915b8, 0xbec7e019, 0x3ff30a3d, 0x70a3d712},	/* 0.783902=f(1.19)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc01921fb, 0x54442d18},	/* -nan=f(-6.28319)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc012d97c, 0x7f3321d2},	/* -nan=f(-4.71239)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc00921fb, 0x54442d18},	/* -nan=f(-3.14159)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff921fb, 0x54442d18},	/* -nan=f(-1.5708)*/
{64, 0,123,__LINE__, 0x00000000, 0x00000000, 0x00000000, 0x00000000},	/* 0=f(0)*/
{37, 0,123,__LINE__, 0x3fee3703, 0xe42b92e4, 0x3ff921fb, 0x54442d18},	/* 0.944216=f(1.5708)*/
{41, 0,123,__LINE__, 0x3ff6bcbe, 0xd6499138, 0x400921fb, 0x54442d18},	/* 1.42108=f(3.14159)*/
{39, 0,123,__LINE__, 0x3ffbe1d7, 0xac9b500a, 0x4012d97c, 0x7f3321d2},	/* 1.74264=f(4.71239)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc03e0000, 0x00000000},	/* -nan=f(-30)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc03c4ccc, 0xcccccccd},	/* -nan=f(-28.3)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc03a9999, 0x9999999a},	/* -nan=f(-26.6)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc038e666, 0x66666667},	/* -nan=f(-24.9)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0373333, 0x33333334},	/* -nan=f(-23.2)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0358000, 0x00000001},	/* -nan=f(-21.5)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc033cccc, 0xccccccce},	/* -nan=f(-19.8)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0321999, 0x9999999b},	/* -nan=f(-18.1)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0306666, 0x66666668},	/* -nan=f(-16.4)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc02d6666, 0x6666666a},	/* -nan=f(-14.7)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc02a0000, 0x00000004},	/* -nan=f(-13)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0269999, 0x9999999e},	/* -nan=f(-11.3)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0233333, 0x33333338},	/* -nan=f(-9.6)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc01f9999, 0x999999a3},	/* -nan=f(-7.9)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc018cccc, 0xccccccd6},	/* -nan=f(-6.2)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0120000, 0x00000009},	/* -nan=f(-4.5)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc0066666, 0x66666678},	/* -nan=f(-2.8)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff19999, 0x999999bd},	/* -nan=f(-1.1)*/
{38, 0,123,__LINE__, 0x3fde148a, 0x2a2726cc, 0x3fe33333, 0x333332ec},	/* 0.470004=f(0.6)*/
{40, 0,123,__LINE__, 0x3ff31a4e, 0x6e5fcf38, 0x40026666, 0x66666654},	/* 1.19392=f(2.3)*/
{39, 0,123,__LINE__, 0x3ff9c041, 0xf7ed8d33, 0x400fffff, 0xffffffee},	/* 1.60944=f(4)*/
{40, 0,123,__LINE__, 0x3ffe6f08, 0x45914e1e, 0x4016cccc, 0xccccccc4},	/* 1.90211=f(5.7)*/
{43, 0,123,__LINE__, 0x4001069e, 0x59bd8ef4, 0x401d9999, 0x99999991},	/* 2.12823=f(7.4)*/
{41, 0,123,__LINE__, 0x40028012, 0x9793dd64, 0x40223333, 0x3333332f},	/* 2.31254=f(9.1)*/
{39, 0,123,__LINE__, 0x4003beaa, 0xf9c2f023, 0x40259999, 0x99999995},	/* 2.4681=f(10.8)*/
{40, 0,123,__LINE__, 0x4004d24e, 0xf844f614, 0x4028ffff, 0xfffffffb},	/* 2.60269=f(12.5)*/
{45, 0,123,__LINE__, 0x4005c536, 0x87dbe11e, 0x402c6666, 0x66666661},	/* 2.7213=f(14.2)*/
{42, 0,123,__LINE__, 0x40069e56, 0x97a6309d, 0x402fcccc, 0xccccccc7},	/* 2.82731=f(15.9)*/
{42, 0,123,__LINE__, 0x400762a2, 0x8cb19671, 0x40319999, 0x99999997},	/* 2.92316=f(17.6)*/
{40, 0,123,__LINE__, 0x400815c0, 0x62267caa, 0x40334ccc, 0xccccccca},	/* 3.01062=f(19.3)*/
{41, 0,123,__LINE__, 0x4008ba74, 0x773dc5c8, 0x4034ffff, 0xfffffffd},	/* 3.09104=f(21)*/
{39, 0,123,__LINE__, 0x400952e4, 0x9952a718, 0x4036b333, 0x33333330},	/* 3.16548=f(22.7)*/
{42, 0,123,__LINE__, 0x4009e0c4, 0x2ac58dda, 0x40386666, 0x66666663},	/* 3.23475=f(24.4)*/
{41, 0,123,__LINE__, 0x400a6571, 0xf24e340e, 0x403a1999, 0x99999996},	/* 3.29953=f(26.1)*/
{41, 0,123,__LINE__, 0x400ae20c, 0x7a223d7c, 0x403bcccc, 0xccccccc9},	/* 3.36038=f(27.8)*/
{42, 0,123,__LINE__, 0x400b5781, 0x1666499e, 0x403d7fff, 0xfffffffc},	/* 3.41773=f(29.5)*/
{0},};
void test_log1pf(int m)   {run_vector_1(m,log1pf_vec,(char *)(log1pf),"log1pf","ff");   }	
