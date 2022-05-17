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
 one_line_type log1p_vec[] = {
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
{ 9, 0,123,__LINE__, 0xc0420596, 0x6f2b4f12, 0xbfefffff, 0xfffffffe},	/* -36.0437=f(-1)*/
{10, 0,123,__LINE__, 0xc0126bb1, 0xbbb554fc, 0xbfefae14, 0x7ae147ac},	/* -4.60517=f(-0.99)*/
{11, 0,123,__LINE__, 0xc00f4bd2, 0xb7ac1b94, 0xbfef5c28, 0xf5c28f5a},	/* -3.91202=f(-0.98)*/
{11, 0,123,__LINE__, 0xc00c0d6e, 0x3a142893, 0xbfef0a3d, 0x70a3d708},	/* -3.50656=f(-0.97)*/
{11, 0,123,__LINE__, 0xc009c041, 0xf7ed8d25, 0xbfeeb851, 0xeb851eb6},	/* -3.21888=f(-0.96)*/
{11, 0,123,__LINE__, 0xc007f742, 0x7b73e385, 0xbfee6666, 0x66666664},	/* -2.99573=f(-0.95)*/
{11, 0,123,__LINE__, 0xc00681dd, 0x7a559a20, 0xbfee147a, 0xe147ae12},	/* -2.81341=f(-0.94)*/
{11, 0,123,__LINE__, 0xc005462a, 0x20517cf6, 0xbfedc28f, 0x5c28f5c0},	/* -2.65926=f(-0.93)*/
{11, 0,123,__LINE__, 0xc00434b1, 0x382efeaf, 0xbfed70a3, 0xd70a3d6e},	/* -2.52573=f(-0.92)*/
{11, 0,123,__LINE__, 0xc0034378, 0xfcbda719, 0xbfed1eb8, 0x51eb851c},	/* -2.40795=f(-0.91)*/
{11, 0,123,__LINE__, 0xc0026bb1, 0xbbb5550f, 0xbfeccccc, 0xccccccca},	/* -2.30259=f(-0.9)*/
{11, 0,123,__LINE__, 0xc001a87f, 0xbfeb72d9, 0xbfec7ae1, 0x47ae1478},	/* -2.20727=f(-0.89)*/
{11, 0,123,__LINE__, 0xc000f64c, 0xba970ba8, 0xbfec28f5, 0xc28f5c26},	/* -2.12026=f(-0.88)*/
{11, 0,123,__LINE__, 0xc000525f, 0x4c391dd4, 0xbfebd70a, 0x3d70a3d4},	/* -2.04022=f(-0.87)*/
{11, 0,123,__LINE__, 0xbfff7532, 0xc125dcfc, 0xbfeb851e, 0xb851eb82},	/* -1.96611=f(-0.86)*/
{11, 0,123,__LINE__, 0xbffe5a9a, 0x7c3ac40d, 0xbfeb3333, 0x33333330},	/* -1.89712=f(-0.85)*/
{11, 0,123,__LINE__, 0xbffd5240, 0xf0e0e06d, 0xbfeae147, 0xae147ade},	/* -1.83258=f(-0.84)*/
{11, 0,123,__LINE__, 0xbffc59ef, 0x6ae05559, 0xbfea8f5c, 0x28f5c28c},	/* -1.77196=f(-0.83)*/
{11, 0,123,__LINE__, 0xbffb6fd0, 0x79fe3140, 0xbfea3d70, 0xa3d70a3a},	/* -1.7148=f(-0.82)*/
{11, 0,123,__LINE__, 0xbffa925a, 0xe2cbedf4, 0xbfe9eb85, 0x1eb851e8},	/* -1.66073=f(-0.81)*/
{11, 0,123,__LINE__, 0xbff9c041, 0xf7ed8d2a, 0xbfe99999, 0x99999996},	/* -1.60944=f(-0.8)*/
{12, 0,123,__LINE__, 0xbff8f869, 0xc5f5f6eb, 0xbfe947ae, 0x147ae144},	/* -1.56065=f(-0.79)*/
{12, 0,123,__LINE__, 0xbff839de, 0x0059c8be, 0xbfe8f5c2, 0x8f5c28f2},	/* -1.51413=f(-0.78)*/
{12, 0,123,__LINE__, 0xbff783ca, 0xf331ec6e, 0xbfe8a3d7, 0x0a3d70a0},	/* -1.46968=f(-0.77)*/
{12, 0,123,__LINE__, 0xbff6d577, 0xf5b0fa5c, 0xbfe851eb, 0x851eb84e},	/* -1.42712=f(-0.76)*/
{12, 0,123,__LINE__, 0xbff62e42, 0xfefa39e7, 0xbfe7ffff, 0xfffffffc},	/* -1.38629=f(-0.75)*/
{12, 0,123,__LINE__, 0xbff58d9d, 0x18f51eb5, 0xbfe7ae14, 0x7ae147aa},	/* -1.34707=f(-0.74)*/
{12, 0,123,__LINE__, 0xbff4f307, 0x7ece4b2f, 0xbfe75c28, 0xf5c28f58},	/* -1.30933=f(-0.73)*/
{12, 0,123,__LINE__, 0xbff45e11, 0x41a8c008, 0xbfe70a3d, 0x70a3d706},	/* -1.27297=f(-0.72)*/
{12, 0,123,__LINE__, 0xbff3ce55, 0x57395811, 0xbfe6b851, 0xeb851eb4},	/* -1.23787=f(-0.71)*/
{12, 0,123,__LINE__, 0xbff34378, 0xfcbda719, 0xbfe66666, 0x66666662},	/* -1.20397=f(-0.7)*/
{12, 0,123,__LINE__, 0xbff2bd2a, 0x5db2fd9b, 0xbfe6147a, 0xe147ae10},	/* -1.17118=f(-0.69)*/
{12, 0,123,__LINE__, 0xbff23b1f, 0x7163c379, 0xbfe5c28f, 0x5c28f5be},	/* -1.13943=f(-0.68)*/
{12, 0,123,__LINE__, 0xbff1bd15, 0x0529e2ad, 0xbfe570a3, 0xd70a3d6c},	/* -1.10866=f(-0.67)*/
{12, 0,123,__LINE__, 0xbff142cd, 0xeb633864, 0xbfe51eb8, 0x51eb851a},	/* -1.07881=f(-0.66)*/
{12, 0,123,__LINE__, 0xbff0cc12, 0x48b56cc4, 0xbfe4cccc, 0xccccccc8},	/* -1.04982=f(-0.65)*/
{12, 0,123,__LINE__, 0xbff058ae, 0xfa81144b, 0xbfe47ae1, 0x47ae1476},	/* -1.02165=f(-0.64)*/
{12, 0,123,__LINE__, 0xbfefd0ea, 0x24bf89aa, 0xbfe428f5, 0xc28f5c24},	/* -0.994252=f(-0.63)*/
{12, 0,123,__LINE__, 0xbfeef672, 0xc69da1fe, 0xbfe3d70a, 0x3d70a3d2},	/* -0.967584=f(-0.62)*/
{12, 0,123,__LINE__, 0xbfee21a8, 0x3b8a7146, 0xbfe3851e, 0xb851eb80},	/* -0.941609=f(-0.61)*/
{12, 0,123,__LINE__, 0xbfed5240, 0xf0e0e06b, 0xbfe33333, 0x3333332e},	/* -0.916291=f(-0.6)*/
{12, 0,123,__LINE__, 0xbfec87f8, 0xc76ff769, 0xbfe2e147, 0xae147adc},	/* -0.891598=f(-0.59)*/
{12, 0,123,__LINE__, 0xbfebc290, 0x8cf1b3ec, 0xbfe28f5c, 0x28f5c28a},	/* -0.867501=f(-0.58)*/
{12, 0,123,__LINE__, 0xbfeb01cd, 0x8556f85b, 0xbfe23d70, 0xa3d70a38},	/* -0.84397=f(-0.57)*/
{12, 0,123,__LINE__, 0xbfea4579, 0x01b95792, 0xbfe1eb85, 0x1eb851e6},	/* -0.820981=f(-0.56)*/
{13, 0,123,__LINE__, 0xbfe98d60, 0x031b820e, 0xbfe19999, 0x99999994},	/* -0.798508=f(-0.55)*/
{13, 0,123,__LINE__, 0xbfe8d952, 0xe7699ef0, 0xbfe147ae, 0x147ae142},	/* -0.776529=f(-0.54)*/
{13, 0,123,__LINE__, 0xbfe82925, 0x1f66e5c6, 0xbfe0f5c2, 0x8f5c28f0},	/* -0.755023=f(-0.53)*/
{13, 0,123,__LINE__, 0xbfe77cac, 0xec67bace, 0xbfe0a3d7, 0x0a3d709e},	/* -0.733969=f(-0.52)*/
{13, 0,123,__LINE__, 0xbfe6d3c3, 0x24e13f43, 0xbfe051eb, 0x851eb84c},	/* -0.71335=f(-0.51)*/
{13, 0,123,__LINE__, 0xbfe62e42, 0xfefa39e3, 0xbfdfffff, 0xfffffff4},	/* -0.693147=f(-0.5)*/
{13, 0,123,__LINE__, 0xbfe58c09, 0xe066a4a4, 0xbfdf5c28, 0xf5c28f50},	/* -0.673345=f(-0.49)*/
{13, 0,123,__LINE__, 0xbfe4ecf7, 0x32f0037e, 0xbfdeb851, 0xeb851eac},	/* -0.653926=f(-0.48)*/
{13, 0,123,__LINE__, 0xbfe450ec, 0x3d21b5f5, 0xbfde147a, 0xe147ae08},	/* -0.634878=f(-0.47)*/
{13, 0,123,__LINE__, 0xbfe3b7cb, 0xfea25c72, 0xbfdd70a3, 0xd70a3d64},	/* -0.616186=f(-0.46)*/
{13, 0,123,__LINE__, 0xbfe3217b, 0x0fd2b10b, 0xbfdccccc, 0xccccccc0},	/* -0.597837=f(-0.45)*/
{13, 0,123,__LINE__, 0xbfe28ddf, 0x84574624, 0xbfdc28f5, 0xc28f5c1c},	/* -0.579818=f(-0.44)*/
{13, 0,123,__LINE__, 0xbfe1fce0, 0xd03dd5da, 0xbfdb851e, 0xb851eb78},	/* -0.562119=f(-0.43)*/
{13, 0,123,__LINE__, 0xbfe16e67, 0xaf787636, 0xbfdae147, 0xae147ad4},	/* -0.544727=f(-0.42)*/
{13, 0,123,__LINE__, 0xbfe0e25e, 0x0f715cdb, 0xbfda3d70, 0xa3d70a30},	/* -0.527633=f(-0.41)*/
{13, 0,123,__LINE__, 0xbfe058ae, 0xfa811446, 0xbfd99999, 0x9999998c},	/* -0.510826=f(-0.4)*/
{13, 0,123,__LINE__, 0xbfdfa28d, 0x0a2e9074, 0xbfd8f5c2, 0x8f5c28e8},	/* -0.494296=f(-0.39)*/
{13, 0,123,__LINE__, 0xbfde9823, 0x78d78294, 0xbfd851eb, 0x851eb844},	/* -0.478036=f(-0.38)*/
{13, 0,123,__LINE__, 0xbfdd91fd, 0x2d23cf90, 0xbfd7ae14, 0x7ae147a0},	/* -0.462035=f(-0.37)*/
{13, 0,123,__LINE__, 0xbfdc8ff7, 0xc79a9a0b, 0xbfd70a3d, 0x70a3d6fc},	/* -0.446287=f(-0.36)*/
{13, 0,123,__LINE__, 0xbfdb91f2, 0x8212b9ec, 0xbfd66666, 0x66666658},	/* -0.430783=f(-0.35)*/
{13, 0,123,__LINE__, 0xbfda97ce, 0x16b316dc, 0xbfd5c28f, 0x5c28f5b4},	/* -0.415515=f(-0.34)*/
{13, 0,123,__LINE__, 0xbfd9a16c, 0xa8d43e6c, 0xbfd51eb8, 0x51eb8510},	/* -0.400478=f(-0.33)*/
{13, 0,123,__LINE__, 0xbfd8aeb1, 0xaf986db7, 0xbfd47ae1, 0x47ae146c},	/* -0.385662=f(-0.32)*/
{14, 0,123,__LINE__, 0xbfd7bf81, 0xe213a598, 0xbfd3d70a, 0x3d70a3c8},	/* -0.371064=f(-0.31)*/
{14, 0,123,__LINE__, 0xbfd6d3c3, 0x24e13f39, 0xbfd33333, 0x33333324},	/* -0.356675=f(-0.3)*/
{14, 0,123,__LINE__, 0xbfd5eb5c, 0x7907e4b3, 0xbfd28f5c, 0x28f5c280},	/* -0.34249=f(-0.29)*/
{14, 0,123,__LINE__, 0xbfd50635, 0xec0fdd53, 0xbfd1eb85, 0x1eb851dc},	/* -0.328504=f(-0.28)*/
{14, 0,123,__LINE__, 0xbfd42438, 0x893252df, 0xbfd147ae, 0x147ae138},	/* -0.314711=f(-0.27)*/
{14, 0,123,__LINE__, 0xbfd3454e, 0x4b8a9f7b, 0xbfd0a3d7, 0x0a3d7094},	/* -0.301105=f(-0.26)*/
{14, 0,123,__LINE__, 0xbfd26962, 0x1134db7d, 0xbfcfffff, 0xffffffe0},	/* -0.287682=f(-0.25)*/
{14, 0,123,__LINE__, 0xbfd1905f, 0x8f46d023, 0xbfceb851, 0xeb851e98},	/* -0.274437=f(-0.24)*/
{14, 0,123,__LINE__, 0xbfd0ba33, 0x46922d88, 0xbfcd70a3, 0xd70a3d50},	/* -0.261365=f(-0.23)*/
{14, 0,123,__LINE__, 0xbfcfcd94, 0xf240dd65, 0xbfcc28f5, 0xc28f5c08},	/* -0.248461=f(-0.22)*/
{14, 0,123,__LINE__, 0xbfce2c26, 0x40b47426, 0xbfcae147, 0xae147ac0},	/* -0.235722=f(-0.21)*/
{14, 0,123,__LINE__, 0xbfcc8ff7, 0xc79a99f8, 0xbfc99999, 0x99999978},	/* -0.223144=f(-0.2)*/
{14, 0,123,__LINE__, 0xbfcaf8e8, 0x210a4134, 0xbfc851eb, 0x851eb830},	/* -0.210721=f(-0.19)*/
{14, 0,123,__LINE__, 0xbfc966d7, 0x21d6f5ef, 0xbfc70a3d, 0x70a3d6e8},	/* -0.198451=f(-0.18)*/
{14, 0,123,__LINE__, 0xbfc7d9a5, 0xca4e1253, 0xbfc5c28f, 0x5c28f5a0},	/* -0.18633=f(-0.17)*/
{15, 0,123,__LINE__, 0xbfc65136, 0x37dde7fe, 0xbfc47ae1, 0x47ae1458},	/* -0.174353=f(-0.16)*/
{15, 0,123,__LINE__, 0xbfc4cd6b, 0x9796414f, 0xbfc33333, 0x33333310},	/* -0.162519=f(-0.15)*/
{15, 0,123,__LINE__, 0xbfc34e2a, 0x1972f9b9, 0xbfc1eb85, 0x1eb851c8},	/* -0.150823=f(-0.14)*/
{15, 0,123,__LINE__, 0xbfc1d356, 0xe462a847, 0xbfc0a3d7, 0x0a3d7080},	/* -0.139262=f(-0.13)*/
{15, 0,123,__LINE__, 0xbfc05cd8, 0x0afc7696, 0xbfbeb851, 0xeb851e71},	/* -0.127833=f(-0.12)*/
{15, 0,123,__LINE__, 0xbfbdd529, 0x01b28783, 0xbfbc28f5, 0xc28f5be2},	/* -0.116534=f(-0.11)*/
{15, 0,123,__LINE__, 0xbfbaf8e8, 0x210a410f, 0xbfb99999, 0x99999953},	/* -0.105361=f(-0.1)*/
{15, 0,123,__LINE__, 0xbfb824be, 0xa3fe157e, 0xbfb70a3d, 0x70a3d6c4},	/* -0.0943107=f(-0.09)*/
{16, 0,123,__LINE__, 0xbfb5587f, 0x437b2820, 0xbfb47ae1, 0x47ae1435},	/* -0.0833816=f(-0.08)*/
{16, 0,123,__LINE__, 0xbfb293fe, 0x305fa92e, 0xbfb1eb85, 0x1eb851a6},	/* -0.0725707=f(-0.07)*/
{16, 0,123,__LINE__, 0xbfafae22, 0x06cabda3, 0xbfaeb851, 0xeb851e2d},	/* -0.0618754=f(-0.06)*/
{16, 0,123,__LINE__, 0xbfaa431d, 0x5bcc18a5, 0xbfa99999, 0x9999990e},	/* -0.0512933=f(-0.05)*/
{17, 0,123,__LINE__, 0xbfa4e69e, 0xd6d80e1c, 0xbfa47ae1, 0x47ae13ef},	/* -0.040822=f(-0.04)*/
{17, 0,123,__LINE__, 0xbf9f30b2, 0xd0091c61, 0xbf9eb851, 0xeb851da0},	/* -0.0304592=f(-0.03)*/
{18, 0,123,__LINE__, 0xbf94b004, 0xbce0aad3, 0xbf947ae1, 0x47ae1362},	/* -0.0202027=f(-0.02)*/
{19, 0,123,__LINE__, 0xbf849545, 0x3e6fd27f, 0xbf847ae1, 0x47ae1249},	/* -0.0100503=f(-0.01)*/
{64, 0,123,__LINE__, 0x3cd18fff, 0xfffffffe, 0x3cd19000, 0x00000000},	/* 9.74915e-16=f(9.74915e-16)*/
{64, 0,123,__LINE__, 0x3f8460d6, 0xccca38a3, 0x3f847ae1, 0x47ae16ad},	/* 0.00995033=f(0.01)*/
{64, 0,123,__LINE__, 0x3f944723, 0xd272a905, 0x3f947ae1, 0x47ae1594},	/* 0.0198026=f(0.02)*/
{64, 0,123,__LINE__, 0x3f9e44a9, 0xa3bed775, 0x3f9eb851, 0xeb851fd2},	/* 0.0295588=f(0.03)*/
{64, 0,123,__LINE__, 0x3fa414bc, 0xc0a366e0, 0x3fa47ae1, 0x47ae1508},	/* 0.0392207=f(0.04)*/
{64, 0,123,__LINE__, 0x3fa8fb06, 0x3ef2c870, 0x3fa99999, 0x99999a27},	/* 0.0487902=f(0.05)*/
{64, 0,123,__LINE__, 0x3fadd56c, 0x1d883f65, 0x3faeb851, 0xeb851f46},	/* 0.0582689=f(0.06)*/
{64, 0,123,__LINE__, 0x3fb15213, 0xc27c91be, 0x3fb1eb85, 0x1eb85232},	/* 0.0676586=f(0.07)*/
{64, 0,123,__LINE__, 0x3fb3b3b8, 0x02beebd0, 0x3fb47ae1, 0x47ae14c1},	/* 0.076961=f(0.08)*/
{64, 0,123,__LINE__, 0x3fb60fbd, 0xd2fffc71, 0x3fb70a3d, 0x70a3d750},	/* 0.0861777=f(0.09)*/
{64, 0,123,__LINE__, 0x3fb8663f, 0x793c4706, 0x3fb99999, 0x999999df},	/* 0.0953102=f(0.1)*/
{64, 0,123,__LINE__, 0x3fbab756, 0x84d3e32e, 0x3fbc28f5, 0xc28f5c6e},	/* 0.10436=f(0.11)*/
{64, 0,123,__LINE__, 0x3fbd031b, 0xd5179e39, 0x3fbeb851, 0xeb851efd},	/* 0.113329=f(0.12)*/
{64, 0,123,__LINE__, 0x3fbf49a7, 0x9f8b91ca, 0x3fc0a3d7, 0x0a3d70c6},	/* 0.122218=f(0.13)*/
{64, 0,123,__LINE__, 0x3fc0c588, 0xbaf19047, 0x3fc1eb85, 0x1eb8520e},	/* 0.131028=f(0.14)*/
{64, 0,123,__LINE__, 0x3fc1e3b8, 0x25dd060a, 0x3fc33333, 0x33333356},	/* 0.139762=f(0.15)*/
{64, 0,123,__LINE__, 0x3fc2ff6d, 0x3e070ed3, 0x3fc47ae1, 0x47ae149e},	/* 0.14842=f(0.16)*/
{64, 0,123,__LINE__, 0x3fc418b2, 0xe73e5327, 0x3fc5c28f, 0x5c28f5e6},	/* 0.157004=f(0.17)*/
{64, 0,123,__LINE__, 0x3fc52f93, 0xbe237442, 0x3fc70a3d, 0x70a3d72e},	/* 0.165514=f(0.18)*/
{64, 0,123,__LINE__, 0x3fc6441a, 0x1a9027c6, 0x3fc851eb, 0x851eb876},	/* 0.173953=f(0.19)*/
{64, 0,123,__LINE__, 0x3fc75650, 0x11e49695, 0x3fc99999, 0x999999be},	/* 0.182322=f(0.2)*/
{64, 0,123,__LINE__, 0x3fc8663f, 0x793c46e5, 0x3fcae147, 0xae147b06},	/* 0.19062=f(0.21)*/
{64, 0,123,__LINE__, 0x3fc973f1, 0xe78bc6c7, 0x3fcc28f5, 0xc28f5c4e},	/* 0.198851=f(0.22)*/
{63, 0,123,__LINE__, 0x3fca7f70, 0xb7a83a9d, 0x3fcd70a3, 0xd70a3d96},	/* 0.207014=f(0.23)*/
{64, 0,123,__LINE__, 0x3fcb88c5, 0x0a39e287, 0x3fceb851, 0xeb851ede},	/* 0.215111=f(0.24)*/
{64, 0,123,__LINE__, 0x3fcc8ff7, 0xc79a9a40, 0x3fd00000, 0x00000013},	/* 0.223144=f(0.25)*/
{64, 0,123,__LINE__, 0x3fcd9511, 0xa1a1488f, 0x3fd0a3d7, 0x0a3d70b7},	/* 0.231112=f(0.26)*/
{64, 0,123,__LINE__, 0x3fce981b, 0x155b25b1, 0x3fd147ae, 0x147ae15b},	/* 0.239017=f(0.27)*/
{64, 0,123,__LINE__, 0x3fcf991c, 0x6cb3b398, 0x3fd1eb85, 0x1eb851ff},	/* 0.24686=f(0.28)*/
{64, 0,123,__LINE__, 0x3fd04c0e, 0xe0061b6a, 0x3fd28f5c, 0x28f5c2a3},	/* 0.254642=f(0.29)*/
{64, 0,123,__LINE__, 0x3fd0ca93, 0x7be1b9eb, 0x3fd33333, 0x33333347},	/* 0.262364=f(0.3)*/
{64, 0,123,__LINE__, 0x3fd1481f, 0xe6d734de, 0x3fd3d70a, 0x3d70a3eb},	/* 0.270027=f(0.31)*/
{64, 0,123,__LINE__, 0x3fd1c4b7, 0xe7415cfc, 0x3fd47ae1, 0x47ae148f},	/* 0.277632=f(0.32)*/
{64, 0,123,__LINE__, 0x3fd2405f, 0x2d99b178, 0x3fd51eb8, 0x51eb8533},	/* 0.285179=f(0.33)*/
{64, 0,123,__LINE__, 0x3fd2bb19, 0x5520356c, 0x3fd5c28f, 0x5c28f5d7},	/* 0.29267=f(0.34)*/
{64, 0,123,__LINE__, 0x3fd334e9, 0xe47d0804, 0x3fd66666, 0x6666667b},	/* 0.300105=f(0.35)*/
{64, 0,123,__LINE__, 0x3fd3add4, 0x4e5c0621, 0x3fd70a3d, 0x70a3d71f},	/* 0.307485=f(0.36)*/
{64, 0,123,__LINE__, 0x3fd425db, 0xf202b884, 0x3fd7ae14, 0x7ae147c3},	/* 0.314811=f(0.37)*/
{64, 0,123,__LINE__, 0x3fd49d04, 0x1be0ce40, 0x3fd851eb, 0x851eb867},	/* 0.322083=f(0.38)*/
{64, 0,123,__LINE__, 0x3fd51350, 0x061b5fdc, 0x3fd8f5c2, 0x8f5c290b},	/* 0.329304=f(0.39)*/
{64, 0,123,__LINE__, 0x3fd588c2, 0xd913349f, 0x3fd99999, 0x999999af},	/* 0.336472=f(0.4)*/
{64, 0,123,__LINE__, 0x3fd5fd5f, 0xabe64094, 0x3fda3d70, 0xa3d70a53},	/* 0.34359=f(0.41)*/
{64, 0,123,__LINE__, 0x3fd67129, 0x84ec8f25, 0x3fdae147, 0xae147af7},	/* 0.350657=f(0.42)*/
{64, 0,123,__LINE__, 0x3fd6e423, 0x5a30cb9d, 0x3fdb851e, 0xb851eb9b},	/* 0.357674=f(0.43)*/
{64, 0,123,__LINE__, 0x3fd75650, 0x11e49686, 0x3fdc28f5, 0xc28f5c3f},	/* 0.364643=f(0.44)*/
{64, 0,123,__LINE__, 0x3fd7c7b2, 0x82d0d47b, 0x3fdccccc, 0xcccccce3},	/* 0.371564=f(0.45)*/
{64, 0,123,__LINE__, 0x3fd8384d, 0x74c220f9, 0x3fdd70a3, 0xd70a3d87},	/* 0.378436=f(0.46)*/
{64, 0,123,__LINE__, 0x3fd8a823, 0xa0f18d9c, 0x3fde147a, 0xe147ae2b},	/* 0.385262=f(0.47)*/
{64, 0,123,__LINE__, 0x3fd91737, 0xb269d45e, 0x3fdeb851, 0xeb851ecf},	/* 0.392042=f(0.48)*/
{64, 0,123,__LINE__, 0x3fd9858c, 0x46692186, 0x3fdf5c28, 0xf5c28f73},	/* 0.398776=f(0.49)*/
{64, 0,123,__LINE__, 0x3fd9f323, 0xecbf985b, 0x3fe00000, 0x0000000b},	/* 0.405465=f(0.5)*/
{64, 0,123,__LINE__, 0x3fda6001, 0x282ab3e7, 0x3fe051eb, 0x851eb85d},	/* 0.41211=f(0.51)*/
{64, 0,123,__LINE__, 0x3fdacc26, 0x6eada3b5, 0x3fe0a3d7, 0x0a3d70af},	/* 0.41871=f(0.52)*/
{64, 0,123,__LINE__, 0x3fdb3796, 0x29e6c2da, 0x3fe0f5c2, 0x8f5c2901},	/* 0.425268=f(0.53)*/
{64, 0,123,__LINE__, 0x3fdba252, 0xb7624650, 0x3fe147ae, 0x147ae153},	/* 0.431782=f(0.54)*/
{64, 0,123,__LINE__, 0x3fdc0c5e, 0x68ea3e54, 0x3fe19999, 0x999999a5},	/* 0.438255=f(0.55)*/
{64, 0,123,__LINE__, 0x3fdc75bb, 0x84d40526, 0x3fe1eb85, 0x1eb851f7},	/* 0.444686=f(0.56)*/
{64, 0,123,__LINE__, 0x3fdcde6c, 0x464b347d, 0x3fe23d70, 0xa3d70a49},	/* 0.451076=f(0.57)*/
{64, 0,123,__LINE__, 0x3fdd4672, 0xdd9a39c5, 0x3fe28f5c, 0x28f5c29b},	/* 0.457425=f(0.58)*/
{63, 0,123,__LINE__, 0x3fddadd1, 0x7070a037, 0x3fe2e147, 0xae147aed},	/* 0.463734=f(0.59)*/
{64, 0,123,__LINE__, 0x3fde148a, 0x1a2726dc, 0x3fe33333, 0x3333333f},	/* 0.470004=f(0.6)*/
{64, 0,123,__LINE__, 0x3fde7a9e, 0xec01b794, 0x3fe3851e, 0xb851eb91},	/* 0.476234=f(0.61)*/
{64, 0,123,__LINE__, 0x3fdee011, 0xed6f533e, 0x3fe3d70a, 0x3d70a3e3},	/* 0.482426=f(0.62)*/
{63, 0,123,__LINE__, 0x3fdf44e5, 0x1c480667, 0x3fe428f5, 0xc28f5c35},	/* 0.48858=f(0.63)*/
{64, 0,123,__LINE__, 0x3fdfa91a, 0x6d08f8e1, 0x3fe47ae1, 0x47ae1487},	/* 0.494696=f(0.64)*/
{64, 0,123,__LINE__, 0x3fe00659, 0xe5875506, 0x3fe4cccc, 0xccccccd9},	/* 0.500775=f(0.65)*/
{63, 0,123,__LINE__, 0x3fe037d9, 0x8c66b557, 0x3fe51eb8, 0x51eb852b},	/* 0.506818=f(0.66)*/
{64, 0,123,__LINE__, 0x3fe0690d, 0x18041250, 0x3fe570a3, 0xd70a3d7d},	/* 0.512824=f(0.67)*/
{64, 0,123,__LINE__, 0x3fe099f5, 0x7102bfed, 0x3fe5c28f, 0x5c28f5cf},	/* 0.518794=f(0.68)*/
{64, 0,123,__LINE__, 0x3fe0ca93, 0x7be1b9e3, 0x3fe6147a, 0xe147ae21},	/* 0.524729=f(0.69)*/
{63, 0,123,__LINE__, 0x3fe0fae8, 0x1914a999, 0x3fe66666, 0x66666673},	/* 0.530628=f(0.7)*/
{63, 0,123,__LINE__, 0x3fe12af4, 0x251c3037, 0x3fe6b851, 0xeb851ec5},	/* 0.536493=f(0.71)*/
{64, 0,123,__LINE__, 0x3fe15ab8, 0x789d7b7e, 0x3fe70a3d, 0x70a3d717},	/* 0.542324=f(0.72)*/
{64, 0,123,__LINE__, 0x3fe18a35, 0xe8792b90, 0x3fe75c28, 0xf5c28f69},	/* 0.548121=f(0.73)*/
{64, 0,123,__LINE__, 0x3fe1b96d, 0x45e18fdb, 0x3fe7ae14, 0x7ae147bb},	/* 0.553885=f(0.74)*/
{64, 0,123,__LINE__, 0x3fe1e85f, 0x5e7040d8, 0x3fe80000, 0x0000000d},	/* 0.559616=f(0.75)*/
{64, 0,123,__LINE__, 0x3fe2170c, 0xfc3b1c47, 0x3fe851eb, 0x851eb85f},	/* 0.565314=f(0.76)*/
{64, 0,123,__LINE__, 0x3fe24576, 0xe5e8a936, 0x3fe8a3d7, 0x0a3d70b1},	/* 0.57098=f(0.77)*/
{64, 0,123,__LINE__, 0x3fe2739d, 0xdec3e8fc, 0x3fe8f5c2, 0x8f5c2903},	/* 0.576613=f(0.78)*/
{64, 0,123,__LINE__, 0x3fe2a182, 0xa6cf9a1c, 0x3fe947ae, 0x147ae155},	/* 0.582216=f(0.79)*/
{64, 0,123,__LINE__, 0x3fe2cf25, 0xfad8f1cb, 0x3fe99999, 0x999999a7},	/* 0.587787=f(0.8)*/
{64, 0,123,__LINE__, 0x3fe2fc88, 0x9489d0b0, 0x3fe9eb85, 0x1eb851f9},	/* 0.593327=f(0.81)*/
{64, 0,123,__LINE__, 0x3fe329ab, 0x2a7a773d, 0x3fea3d70, 0xa3d70a4b},	/* 0.598837=f(0.82)*/
{64, 0,123,__LINE__, 0x3fe3568e, 0x7042bdd8, 0x3fea8f5c, 0x28f5c29d},	/* 0.604316=f(0.83)*/
{64, 0,123,__LINE__, 0x3fe38333, 0x168ad4e9, 0x3feae147, 0xae147aef},	/* 0.609766=f(0.84)*/
{64, 0,123,__LINE__, 0x3fe3af99, 0xcb1b90b7, 0x3feb3333, 0x33333341},	/* 0.615186=f(0.85)*/
{64, 0,123,__LINE__, 0x3fe3dbc3, 0x38ee44c8, 0x3feb851e, 0xb851eb93},	/* 0.620576=f(0.86)*/
{63, 0,123,__LINE__, 0x3fe407b0, 0x083c3271, 0x3febd70a, 0x3d70a3e5},	/* 0.625938=f(0.87)*/
{64, 0,123,__LINE__, 0x3fe43360, 0xde8d8e13, 0x3fec28f5, 0xc28f5c37},	/* 0.631272=f(0.88)*/
{64, 0,123,__LINE__, 0x3fe45ed6, 0x5ec81e4a, 0x3fec7ae1, 0x47ae1489},	/* 0.636577=f(0.89)*/
{64, 0,123,__LINE__, 0x3fe48a11, 0x293d7863, 0x3feccccc, 0xccccccdb},	/* 0.641854=f(0.9)*/
{64, 0,123,__LINE__, 0x3fe4b511, 0xdbb8dd2b, 0x3fed1eb8, 0x51eb852d},	/* 0.647103=f(0.91)*/
{64, 0,123,__LINE__, 0x3fe4dfd9, 0x118cb90c, 0x3fed70a3, 0xd70a3d7f},	/* 0.652325=f(0.92)*/
{64, 0,123,__LINE__, 0x3fe50a67, 0x639fca6b, 0x3fedc28f, 0x5c28f5d1},	/* 0.65752=f(0.93)*/
{64, 0,123,__LINE__, 0x3fe534bd, 0x6879f10b, 0x3fee147a, 0xe147ae23},	/* 0.662688=f(0.94)*/
{64, 0,123,__LINE__, 0x3fe55edb, 0xb450a91b, 0x3fee6666, 0x66666675},	/* 0.667829=f(0.95)*/
{64, 0,123,__LINE__, 0x3fe588c2, 0xd9133497, 0x3feeb851, 0xeb851ec7},	/* 0.672944=f(0.96)*/
{64, 0,123,__LINE__, 0x3fe5b273, 0x66767564, 0x3fef0a3d, 0x70a3d719},	/* 0.678034=f(0.97)*/
{64, 0,123,__LINE__, 0x3fe5dbed, 0xea007aa4, 0x3fef5c28, 0xf5c28f6b},	/* 0.683097=f(0.98)*/
{64, 0,123,__LINE__, 0x3fe60532, 0xef13c38d, 0x3fefae14, 0x7ae147bd},	/* 0.688135=f(0.99)*/
{64, 0,123,__LINE__, 0x3fe62e42, 0xfefa39f6, 0x3ff00000, 0x00000007},	/* 0.693147=f(1)*/
{64, 0,123,__LINE__, 0x3fe6571e, 0xa0efe6db, 0x3ff028f5, 0xc28f5c30},	/* 0.698135=f(1.01)*/
{64, 0,123,__LINE__, 0x3fe67fc6, 0x5a2d62d0, 0x3ff051eb, 0x851eb859},	/* 0.703098=f(1.02)*/
{64, 0,123,__LINE__, 0x3fe6a83a, 0xadf20485, 0x3ff07ae1, 0x47ae1482},	/* 0.708036=f(1.03)*/
{64, 0,123,__LINE__, 0x3fe6d07c, 0x1d8dcf36, 0x3ff0a3d7, 0x0a3d70ab},	/* 0.71295=f(1.04)*/
{64, 0,123,__LINE__, 0x3fe6f88b, 0x286b22f8, 0x3ff0cccc, 0xccccccd4},	/* 0.71784=f(1.05)*/
{64, 0,123,__LINE__, 0x3fe72068, 0x4c1830a9, 0x3ff0f5c2, 0x8f5c28fd},	/* 0.722706=f(1.06)*/
{64, 0,123,__LINE__, 0x3fe74814, 0x04503345, 0x3ff11eb8, 0x51eb8526},	/* 0.727549=f(1.07)*/
{64, 0,123,__LINE__, 0x3fe76f8e, 0xcb04705c, 0x3ff147ae, 0x147ae14f},	/* 0.732368=f(1.08)*/
{64, 0,123,__LINE__, 0x3fe796d9, 0x1865013c, 0x3ff170a3, 0xd70a3d78},	/* 0.737164=f(1.09)*/
{64, 0,123,__LINE__, 0x3fe7bdf3, 0x62e96675, 0x3ff19999, 0x999999a1},	/* 0.741937=f(1.1)*/
{64, 0,123,__LINE__, 0x3fe7e4de, 0x1f58e732, 0x3ff1c28f, 0x5c28f5ca},	/* 0.746688=f(1.11)*/
{64, 0,123,__LINE__, 0x3fe80b99, 0xc0d2bde4, 0x3ff1eb85, 0x1eb851f3},	/* 0.751416=f(1.12)*/
{64, 0,123,__LINE__, 0x3fe83226, 0xb8d613b8, 0x3ff2147a, 0xe147ae1c},	/* 0.756122=f(1.13)*/
{64, 0,123,__LINE__, 0x3fe85885, 0x7749cc26, 0x3ff23d70, 0xa3d70a45},	/* 0.760806=f(1.14)*/
{64, 0,123,__LINE__, 0x3fe87eb6, 0x6a842206, 0x3ff26666, 0x6666666e},	/* 0.765468=f(1.15)*/
{64, 0,123,__LINE__, 0x3fe8a4b9, 0xff521768, 0x3ff28f5c, 0x28f5c297},	/* 0.770108=f(1.16)*/
{64, 0,123,__LINE__, 0x3fe8ca90, 0xa0feb971, 0x3ff2b851, 0xeb851ec0},	/* 0.774727=f(1.17)*/
{64, 0,123,__LINE__, 0x3fe8f03a, 0xb95a397c, 0x3ff2e147, 0xae147ae9},	/* 0.779325=f(1.18)*/
{64, 0,123,__LINE__, 0x3fe915b8, 0xb0c0dca2, 0x3ff30a3d, 0x70a3d712},	/* 0.783902=f(1.19)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc01921fb, 0x54442d18},	/* -nan=f(-6.28319)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc012d97c, 0x7f3321d2},	/* -nan=f(-4.71239)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xc00921fb, 0x54442d18},	/* -nan=f(-3.14159)*/
{ 0, 0, 33,__LINE__, 0xfff80000, 0x00000000, 0xbff921fb, 0x54442d18},	/* -nan=f(-1.5708)*/
{64, 0,123,__LINE__, 0x00000000, 0x00000000, 0x00000000, 0x00000000},	/* 0=f(0)*/
{64, 0,123,__LINE__, 0x3fee3703, 0xdb0ab11a, 0x3ff921fb, 0x54442d18},	/* 0.944216=f(1.5708)*/
{64, 0,123,__LINE__, 0x3ff6bcbe, 0xd09f00af, 0x400921fb, 0x54442d18},	/* 1.42108=f(3.14159)*/
{64, 0,123,__LINE__, 0x3ffbe1d7, 0xac0bdb86, 0x4012d97c, 0x7f3321d2},	/* 1.74264=f(4.71239)*/
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
{63, 0,123,__LINE__, 0x3fde148a, 0x1a272675, 0x3fe33333, 0x333332ec},	/* 0.470004=f(0.6)*/
{64, 0,123,__LINE__, 0x3ff31a4e, 0x7240c76c, 0x40026666, 0x66666654},	/* 1.19392=f(2.3)*/
{64, 0,123,__LINE__, 0x3ff9c041, 0xf7ed8d2c, 0x400fffff, 0xffffffee},	/* 1.60944=f(4)*/
{64, 0,123,__LINE__, 0x3ffe6f08, 0x4d359a85, 0x4016cccc, 0xccccccc4},	/* 1.90211=f(5.7)*/
{64, 0,123,__LINE__, 0x4001069e, 0x58377691, 0x401d9999, 0x99999991},	/* 2.12823=f(7.4)*/
{64, 0,123,__LINE__, 0x40028012, 0x92821f4a, 0x40223333, 0x3333332f},	/* 2.31254=f(9.1)*/
{64, 0,123,__LINE__, 0x4003beaa, 0xf7978c56, 0x40259999, 0x99999995},	/* 2.4681=f(10.8)*/
{64, 0,123,__LINE__, 0x4004d24e, 0xf844f613, 0x4028ffff, 0xfffffffb},	/* 2.60269=f(12.5)*/
{64, 0,123,__LINE__, 0x4005c536, 0x898b0989, 0x402c6666, 0x66666661},	/* 2.7213=f(14.2)*/
{64, 0,123,__LINE__, 0x40069e56, 0x9aadc38b, 0x402fcccc, 0xccccccc7},	/* 2.82731=f(15.9)*/
{64, 0,123,__LINE__, 0x400762a2, 0x89f0e644, 0x40319999, 0x99999997},	/* 2.92316=f(17.6)*/
{64, 0,123,__LINE__, 0x400815c0, 0x6731d634, 0x40334ccc, 0xccccccca},	/* 3.01062=f(19.3)*/
{64, 0,123,__LINE__, 0x4008ba74, 0x773dc5c6, 0x4034ffff, 0xfffffffd},	/* 3.09104=f(21)*/
{64, 0,123,__LINE__, 0x400952e4, 0x95008f55, 0x4036b333, 0x33333330},	/* 3.16548=f(22.7)*/
{64, 0,123,__LINE__, 0x4009e0c4, 0x2cc995e9, 0x40386666, 0x66666663},	/* 3.23475=f(24.4)*/
{64, 0,123,__LINE__, 0x400a6571, 0xf06a8af5, 0x403a1999, 0x99999996},	/* 3.29953=f(26.1)*/
{64, 0,123,__LINE__, 0x400ae20c, 0x7db0765f, 0x403bcccc, 0xccccccc9},	/* 3.36038=f(27.8)*/
{64, 0,123,__LINE__, 0x400b5781, 0x1666499d, 0x403d7fff, 0xfffffffc},	/* 3.41773=f(29.5)*/
{0},};
void test_log1p(int m)   {run_vector_1(m,log1p_vec,(char *)(log1p),"log1p","dd");   }	
