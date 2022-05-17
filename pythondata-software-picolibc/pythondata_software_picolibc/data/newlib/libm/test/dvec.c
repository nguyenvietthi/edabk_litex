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

ddouble_type ddoubles[] = {
{__LINE__, 7.411456790099005e+08,"7411",4,9,0,"7411456790099",4,9,0,"7.411e+08",4,NULL},
{__LINE__, 6.779433073319225e-23,"6779433",7,-22,0,"",7,-7,0,"6.779433e-23",7,NULL},
{__LINE__, 5.888272965262503e-03,"5888273",7,-2,0,"58883",7,-2,0,"0.005888273",7,NULL},
{__LINE__, 1.705972712393192e-26,"17059727",8,-25,0,"",8,-8,0,"1.7059727e-26",8,NULL},
{__LINE__, 5.790100803298969e-15,"6",1,-14,0,"",1,-1,0,"6e-15",1,NULL},
{__LINE__, 7.563575126808102e-08,"7564",4,-7,0,"",4,-4,0,"7.564e-08",4,NULL},
{__LINE__, 2.065340498087056e+25,"206534",6,26,0,"20653404980870558131421184000000",6,26,0,"2.06534e+25",6,NULL},
{__LINE__, 1.047038124260123e+02,"1",1,3,0,"1047",1,3,0,"1e+02",1,NULL},
{__LINE__, 4.970783404568945e+28,"497",3,29,0,"49707834045689450828908199936000",3,29,0,"4.97e+28",3,NULL},
{__LINE__, 6.188542454563260e+02,"6",1,3,0,"6189",1,3,0,"6e+02",1,NULL},
{__LINE__, 1.913780290320816e+17,"191",3,18,0,"191378029032081600000",3,18,0,"1.91e+17",3,NULL},
{__LINE__, 6.911970810510094e-03,"691197",6,-2,0,"6912",6,-2,0,"0.00691197",6,NULL},
{__LINE__, 6.530901390373796e-19,"7",1,-18,0,"",1,-1,0,"7e-19",1,NULL},
{__LINE__, 1.688357491215602e+02,"168836",6,3,0,"168835749",6,3,0,"168.836",6,NULL},
{__LINE__, 1.347202777558724e-28,"13472028",8,-27,0,"",8,-8,0,"1.3472028e-28",8,NULL},
{__LINE__, 4.198600486581023e+23,"42",2,24,0,"41986004865810231931699200",2,24,0,"4.2e+23",2,NULL},
{__LINE__, 6.626748168931517e-22,"66",2,-21,0,"",2,-2,0,"6.6e-22",2,NULL},
{__LINE__, 8.271145287633235e+21,"82711",5,22,0,"827114528763323455897600000",5,22,0,"8.2711e+21",5,NULL},
{__LINE__, 2.569163640433771e+25,"3",1,26,0,"256916364043377109872148480",1,26,0,"3e+25",1,NULL},
{__LINE__, 7.764533336462913e-13,"776",3,-12,0,"",3,-3,0,"7.76e-13",3,NULL},
{__LINE__, 4.619473758301567e-22,"46195",5,-21,0,"",5,-5,0,"4.6195e-22",5,NULL},
{__LINE__, 2.067935943396911e-13,"20679359",8,-12,0,"",8,-8,0,"2.0679359e-13",8,NULL},
{__LINE__, 1.011355042357299e+02,"1011355",7,3,0,"1011355042",7,3,0,"101.1355",7,NULL},
{__LINE__, 4.814049311025340e+28,"5",1,29,0,"481404931102534015620732682240",1,29,0,"5e+28",1,NULL},
{__LINE__, 1.337365076329700e-30,"1337365",7,-29,0,"",7,-7,0,"1.337365e-30",7,NULL},
{__LINE__, 9.501916506313628e-25,"950",3,-24,0,"",3,-3,0,"9.5e-25",3,NULL},
{__LINE__, 1.529207539606606e-03,"15292",5,-2,0,"153",5,-2,0,"0.0015292",5,NULL},
{__LINE__, 4.077501222009158e+26,"408",3,27,0,"407750122200915774260903936000",3,27,0,"4.08e+26",3,NULL},
{__LINE__, 8.713312243134940e+00,"87133",5,1,0,"871331",5,1,0,"8.7133",5,NULL},
{__LINE__, 9.958770493219248e+29,"99587705",8,30,0,"99587704932192483778701662617600000000",8,30,0,"9.9587705e+29",8,NULL},
{__LINE__, 3.906559442060730e+27,"391",3,28,0,"3906559442060729932870320128000",3,28,0,"3.91e+27",3,NULL},
{__LINE__, 4.596864377904587e+09,"45968644",8,10,0,"459686437790458679",8,10,0,"4.5968644e+09",8,NULL},
{__LINE__, 1.011374744602721e+09,"10113747",8,10,0,"101137474460272098",8,10,0,"1.0113747e+09",8,NULL},
{__LINE__, 7.368531155948668e-29,"736853",6,-28,0,"",6,-6,0,"7.36853e-29",6,NULL},
{__LINE__, 9.501263936830290e-30,"9501264",7,-29,0,"",7,-7,0,"9.501264e-30",7,NULL},
{__LINE__, 1.022516585955060e-21,"10",2,-20,0,"",2,-2,0,"1e-21",2,NULL},
{__LINE__, 1.749461134391626e+03,"1749461",7,4,0,"17494611344",7,4,0,"1749.461",7,NULL},
{__LINE__, 1.597416186584641e+25,"159742",6,26,0,"15974161865846409266200576000000",6,26,0,"1.59742e+25",6,NULL},
{__LINE__, 1.191930545842576e-02,"1",1,-1,0,"",1,-1,0,"0.01",1,NULL},
{__LINE__, 4.401707995092183e-10,"440",3,-9,0,"",3,-3,0,"4.4e-10",3,NULL},
{__LINE__, 5.842911524915388e-20,"5842912",7,-19,0,"",7,-7,0,"5.842912e-20",7,NULL},
{__LINE__, 4.763038868476586e-17,"5",1,-16,0,"",1,-1,0,"5e-17",1,NULL},
{__LINE__, 2.711250050689824e+04,"27112501",8,5,0,"2711250050690",8,5,0,"27112.501",8,NULL},
{__LINE__, 1.586825853752952e-28,"2",1,-27,0,"",1,-1,0,"2e-28",1,NULL},
{__LINE__, 2.692606047104273e+11,"269261",6,12,0,"269260604710427307",6,12,0,"2.69261e+11",6,NULL},
{__LINE__, 3.179150601523438e+07,"3",1,8,0,"317915060",1,8,0,"3e+07",1,NULL},
{__LINE__, 2.504660553392644e+28,"2504661",7,29,0,"250466055339264382574002176000000000",7,29,0,"2.504661e+28",7,NULL},
{__LINE__, 2.337051102431064e+03,"2",1,4,0,"23371",1,4,0,"2e+03",1,NULL},
{__LINE__, 1.178118953346745e-26,"117812",6,-25,0,"",6,-6,0,"1.17812e-26",6,NULL},
{__LINE__, 3.686404114505492e-28,"36864041",8,-27,0,"",8,-8,0,"3.6864041e-28",8,NULL},
{__LINE__, 5.762313620432176e+15,"5762314",7,16,0,"57623136204321760000000",7,16,0,"5.762314e+15",7,NULL},
{__LINE__, 4.452493864611241e-14,"44525",5,-13,0,"",5,-5,0,"4.4525e-14",5,NULL},
{__LINE__, 3.389385718740431e-19,"33893857",8,-18,0,"",8,-8,0,"3.3893857e-19",8,NULL},
{__LINE__, 2.391576379695071e-10,"239",3,-9,0,"",3,-3,0,"2.39e-10",3,NULL},
{__LINE__, 4.775469136289389e+28,"477547",6,29,0,"47754691362893887330853060608000000",6,29,0,"4.77547e+28",6,NULL},
{__LINE__, 1.880103319851404e-22,"18801033",8,-21,0,"",8,-8,0,"1.8801033e-22",8,NULL},
{__LINE__, 3.623855580649127e-15,"36239",5,-14,0,"",5,-5,0,"3.6239e-15",5,NULL},
{__LINE__, 1.632057742810541e-14,"2",1,-13,0,"",1,-1,0,"2e-14",1,NULL},
{__LINE__, 6.692624092583789e-22,"7",1,-21,0,"",1,-1,0,"7e-22",1,NULL},
{__LINE__, 1.252002726173413e-16,"1252",4,-15,0,"",4,-4,0,"1.252e-16",4,NULL},
{__LINE__, 1.462408181475922e+10,"1462",4,11,0,"146240818147592",4,11,0,"1.462e+10",4,NULL},
{__LINE__, 4.005562902861667e+12,"4006",4,13,0,"40055629028616670",4,13,0,"4.006e+12",4,NULL},
{__LINE__, 1.131067062565773e-17,"1",1,-16,0,"",1,-1,0,"1e-17",1,NULL},
{__LINE__, 2.397292973376075e+16,"2397293",7,17,0,"239729297337607520000000",7,17,0,"2.397293e+16",7,NULL},
{__LINE__, 1.247021255449452e+05,"124702",6,6,0,"124702125545",6,6,0,"124702",6,NULL},
{__LINE__, 3.222697929297968e-16,"32226979",8,-15,0,"",8,-8,0,"3.2226979e-16",8,NULL},
{__LINE__, 5.930401483195766e-22,"59304015",8,-21,0,"",8,-8,0,"5.9304015e-22",8,NULL},
{__LINE__, 1.741790451299310e-05,"2",1,-4,0,"",1,-1,0,"2e-05",1,NULL},
{__LINE__, 5.560486576144617e-04,"56",2,-3,0,"",2,-2,0,"0.00056",2,NULL},
{__LINE__, 3.721569132002345e+12,"4",1,13,0,"37215691320023",1,13,0,"4e+12",1,NULL},
{__LINE__, 5.602270485868007e+10,"56",2,11,0,"5602270485868",2,11,0,"5.6e+10",2,NULL},
{__LINE__, 1.872554953737922e-13,"187",3,-12,0,"",3,-3,0,"1.87e-13",3,NULL},
{__LINE__, 3.078997528596941e+07,"308",3,8,0,"30789975286",3,8,0,"3.08e+07",3,NULL},
{__LINE__, 1.637490643914118e-06,"2",1,-5,0,"",1,-1,0,"2e-06",1,NULL},
{__LINE__, 8.179181640418333e+24,"818",3,25,0,"8179181640418333105848320000",3,25,0,"8.18e+24",3,NULL},
{__LINE__, 6.171369234524714e-28,"6171",4,-27,0,"",4,-4,0,"6.171e-28",4,NULL},
{__LINE__, 1.791138795467072e+14,"18",2,15,0,"17911387954670719",2,15,0,"1.8e+14",2,NULL},
{__LINE__, 9.907740945357109e+25,"9907741",7,26,0,"990774094535710879241994240000000",7,26,0,"9.907741e+25",7,NULL},
{__LINE__, 2.530848135710619e-14,"253085",6,-13,0,"",6,-6,0,"2.53085e-14",6,NULL},
{__LINE__, 1.619815697846305e-25,"16198157",8,-24,0,"",8,-8,0,"1.6198157e-25",8,NULL},
{__LINE__, 1.658806111939662e+06,"17",2,7,0,"165880611",2,7,0,"1.7e+06",2,NULL},
{__LINE__, 1.520841097485083e+25,"2",1,26,0,"152084109748508294916341760",1,26,0,"2e+25",1,NULL},
{__LINE__, 1.305213586757638e-18,"1305",4,-17,0,"",4,-4,0,"1.305e-18",4,NULL},
{__LINE__, 7.052058348992362e-12,"70520583",8,-11,0,"",8,-8,0,"7.0520583e-12",8,NULL},
{__LINE__, 7.819308213692752e+20,"781931",6,21,0,"781930821369275219968000000",6,21,0,"7.81931e+20",6,NULL},
{__LINE__, 3.457215738335750e-13,"345722",6,-12,0,"",6,-6,0,"3.45722e-13",6,NULL},
{__LINE__, 5.673283287913788e+07,"56732833",8,8,0,"5673283287913788",8,8,0,"56732833",8,"5.673283e+07"},
{__LINE__, 1.471857261085004e+23,"1472",4,24,0,"1471857261085004021104640000",4,24,0,"1.472e+23",4,NULL},
{__LINE__, 1.793947117071970e+22,"17939471",8,23,0,"1793947117071970074624000000000",8,23,0,"1.7939471e+22",8,NULL},
{__LINE__, 5.121254629351260e-11,"51213",5,-10,0,"",5,-5,0,"5.1213e-11",5,NULL},
{__LINE__, 4.390732882355057e+16,"439073",6,17,0,"43907328823550568000000",6,17,0,"4.39073e+16",6,NULL},
{__LINE__, 2.427335872475672e+27,"24273359",8,28,0,"242733587247567186349051084800000000",8,28,0,"2.4273359e+27",8,NULL},
{__LINE__, 6.328085758887609e+19,"6328086",7,20,0,"632808575888760913920000000",7,20,0,"6.328086e+19",7,NULL},
{__LINE__, 7.399809184791178e+15,"7400",4,16,0,"73998091847911780000",4,16,0,"7.4e+15",4,NULL},
{__LINE__, 1.431701330887928e-11,"143",3,-10,0,"",3,-3,0,"1.43e-11",3,NULL},
{__LINE__, 2.059594182326570e+24,"206",3,25,0,"2059594182326570052485120000",3,25,0,"2.06e+24",3,NULL},
{__LINE__, 1.754194250078728e-25,"175",3,-24,0,"",3,-3,0,"1.75e-25",3,NULL},
{__LINE__, 4.941256641422608e-27,"494",3,-26,0,"",3,-3,0,"4.94e-27",3,NULL},
{__LINE__, 2.206058544089213e-20,"22060585",8,-19,0,"",8,-8,0,"2.2060585e-20",8,NULL},
{__LINE__, 6.994849795137308e+10,"699485",6,11,0,"69948497951373077",6,11,0,"6.99485e+10",6,NULL},
{__LINE__, 3.152798180026982e+28,"3153",4,29,0,"315279818002698188145903534080000",4,29,0,"3.153e+28",4,NULL},
{__LINE__, 1.348325903318616e-24,"1348326",7,-23,0,"",7,-7,0,"1.348326e-24",7,NULL},
{__LINE__, 2.113465893194608e-15,"21134659",8,-14,0,"",8,-8,0,"2.1134659e-15",8,NULL},
{__LINE__, 4.073170124707854e+02,"407",3,3,0,"407317",3,3,0,"407",3,NULL},
{__LINE__, 2.181347299147143e-17,"218135",6,-16,0,"",6,-6,0,"2.18135e-17",6,NULL},
{__LINE__, 2.103271966376922e+03,"21",2,4,0,"210327",2,4,0,"2.1e+03",2,NULL},
{__LINE__, 2.286252208932191e-30,"229",3,-29,0,"",3,-3,0,"2.29e-30",3,NULL},
{__LINE__, 5.624350974502655e+25,"6",1,26,0,"562435097450265477067571200",1,26,0,"6e+25",1,NULL},
{__LINE__, 4.453486178405307e+05,"4453",4,6,0,"4453486178",4,6,0,"4.453e+05",4,NULL},
{__LINE__, 1.555010610051608e+13,"156",3,14,0,"15550106100516080",3,14,0,"1.56e+13",3,NULL},
{__LINE__, 7.719959471762408e-11,"8",1,-10,0,"",1,-1,0,"8e-11",1,NULL},
{__LINE__, 6.649313805526527e+04,"6649314",7,5,0,"664931380553",7,5,0,"66493.14",7,NULL},
{__LINE__, 2.736862165988477e-29,"2737",4,-28,0,"",4,-4,0,"2.737e-29",4,NULL},
{__LINE__, 8.961141449916591e+05,"8961141",7,6,0,"8961141449917",7,6,0,"896114.1",7,NULL},
{__LINE__, 3.743832253349299e+03,"37438323",8,4,0,"374383225335",8,4,0,"3743.8323",8,NULL},
{__LINE__, 4.616542199119112e-19,"5",1,-18,0,"",1,-1,0,"5e-19",1,NULL},
{__LINE__, 2.141990110663772e-10,"214",3,-9,0,"",3,-3,0,"2.14e-10",3,NULL},
{__LINE__, 4.087808591469674e-14,"40878086",8,-13,0,"",8,-8,0,"4.0878086e-14",8,NULL},
{__LINE__, 1.406420622355064e+19,"140642",6,20,0,"14064206223550640128000000",6,20,0,"1.40642e+19",6,NULL},
{__LINE__, 3.962213921914215e-30,"39622",5,-29,0,"",5,-5,0,"3.9622e-30",5,NULL},
{__LINE__, 1.851236839271498e-12,"19",2,-11,0,"",2,-2,0,"1.9e-12",2,NULL},
{__LINE__, 1.752891467132837e-16,"1753",4,-15,0,"",4,-4,0,"1.753e-16",4,NULL},
{__LINE__, 1.313285975240631e+10,"1313286",7,11,0,"131328597524063091",7,11,0,"1.313286e+10",7,NULL},
{__LINE__, 4.797451776197904e-24,"480",3,-23,0,"",3,-3,0,"4.8e-24",3,NULL},
{__LINE__, 5.632348260968011e+03,"6",1,4,0,"56323",1,4,0,"6e+03",1,NULL},
{__LINE__, 1.282189526481336e+17,"1282",4,18,0,"1282189526481336000000",4,18,0,"1.282e+17",4,NULL},
{__LINE__, 9.821689835700839e-26,"98217",5,-25,0,"",5,-5,0,"9.8217e-26",5,NULL},
{__LINE__, 3.380291727425090e-10,"3380",4,-9,0,"",4,-4,0,"3.38e-10",4,NULL},
{__LINE__, 4.869764742219911e-01,"4870",4,0,0,"4870",4,0,0,"0.487",4,NULL},
{__LINE__, 2.099154543729566e+23,"20992",5,24,0,"20991545437295658768793600000",5,24,0,"2.0992e+23",5,NULL},
{__LINE__, 1.768676806117752e+04,"17686768",8,5,0,"1768676806118",8,5,0,"17686.768",8,NULL},
{__LINE__, 4.303784934223482e-13,"4",1,-12,0,"",1,-1,0,"4e-13",1,NULL},
{__LINE__, 6.523728950282939e+15,"65237290",8,16,0,"652372895028293900000000",8,16,0,"6.523729e+15",8,NULL},
{__LINE__, 7.532898256664122e+08,"8",1,9,0,"7532898257",1,9,0,"8e+08",1,NULL},
{__LINE__, 1.442346036443942e+29,"1",1,30,0,"1442346036443942051716960092160",1,30,0,"1e+29",1,NULL},
{__LINE__, 2.594386109572275e+04,"259",3,5,0,"25943861",3,5,0,"2.59e+04",3,NULL},
{__LINE__, 6.254936126036594e+01,"6",1,2,0,"625",1,2,0,"6e+01",1,NULL},
{__LINE__, 1.009888981861756e+09,"100989",6,10,0,"1009888981861756",6,10,0,"1.00989e+09",6,NULL},
{__LINE__, 2.163578851988448e-16,"21635789",8,-15,0,"",8,-8,0,"2.1635789e-16",8,NULL},
{__LINE__, 2.241242805107749e+14,"224124",6,15,0,"224124280510774906250",6,15,0,"2.24124e+14",6,NULL},
{__LINE__, 3.686520132725987e+17,"368652",6,18,0,"368652013272598720000000",6,18,0,"3.68652e+17",6,NULL},
{__LINE__, 1.249196467299682e-10,"1249",4,-9,0,"",4,-4,0,"1.249e-10",4,NULL},
{__LINE__, 2.235966135657711e-16,"224",3,-15,0,"",3,-3,0,"2.24e-16",3,NULL},
{__LINE__, 7.281023867864680e+03,"7281",4,4,0,"72810239",4,4,0,"7281",4,NULL},
{__LINE__, 9.495208466038457e-04,"9495208",7,-3,0,"9495",7,-3,0,"0.0009495208",7,NULL},
{__LINE__, 1.909521167837320e+18,"190952",6,19,0,"1909521167837319936000000",6,19,0,"1.90952e+18",6,NULL},
{__LINE__, 1.595163045878173e-28,"16",2,-27,0,"",2,-2,0,"1.6e-28",2,NULL},
{__LINE__, 8.333021482130567e+12,"83330215",8,13,0,"833302148213056738281",8,13,0,"8.3330215e+12",8,NULL},
{__LINE__, 2.661576028772926e-12,"266",3,-11,0,"",3,-3,0,"2.66e-12",3,NULL},
{__LINE__, 3.333613056158649e-24,"333",3,-23,0,"",3,-3,0,"3.33e-24",3,NULL},
{__LINE__, 6.968307583705560e+11,"696831",6,12,0,"696830758370556030",6,12,0,"6.96831e+11",6,NULL},
{__LINE__, 7.112095848565475e-19,"711",3,-18,0,"",3,-3,0,"7.11e-19",3,NULL},
{__LINE__, 5.115369447807078e+21,"5115",4,22,0,"51153694478070783672320000",4,22,0,"5.115e+21",4,NULL},
{__LINE__, 1.127652589560061e+16,"112765",6,17,0,"11276525895600610000000",6,17,0,"1.12765e+16",6,NULL},
{__LINE__, 6.777084460845612e-18,"6777",4,-17,0,"",4,-4,0,"6.777e-18",4,NULL},
{__LINE__, 7.969183405862033e-02,"7969183",7,-1,0,"796918",7,-1,0,"0.07969183",7,NULL},
{__LINE__, 4.497389494902805e-27,"449739",6,-26,0,"",6,-6,0,"4.49739e-27",6,NULL},
{__LINE__, 1.174283761330826e+27,"1174284",7,28,0,"11742837613308259632645406720000000",7,28,0,"1.174284e+27",7,NULL},
{__LINE__, 1.180289038670172e+06,"11803",5,7,0,"118028903867",5,7,0,"1.1803e+06",5,NULL},
{__LINE__, 1.373844082711513e+16,"137",3,17,0,"13738440827115130000",3,17,0,"1.37e+16",3,NULL},
{__LINE__, 1.080822334120836e+12,"1080822",7,13,0,"10808223341208360596",7,13,0,"1.080822e+12",7,NULL},
{__LINE__, 3.758397902350635e+20,"37584",5,21,0,"37583979023506348441600000",5,21,0,"3.7584e+20",5,NULL},
{__LINE__, 4.412285493952947e-11,"44",2,-10,0,"",2,-2,0,"4.4e-11",2,NULL},
{__LINE__, 6.565101733527507e+17,"657",3,18,0,"656510173352750720000",3,18,0,"6.57e+17",3,NULL},
{__LINE__, 5.723516940272932e+08,"57",2,9,0,"57235169403",2,9,0,"5.7e+08",2,NULL},
{__LINE__, 5.330525090324728e-11,"53",2,-10,0,"",2,-2,0,"5.3e-11",2,NULL},
{__LINE__, 6.915504868363692e+29,"691550",6,30,0,"691550486836369168444751347712000000",6,30,0,"6.9155e+29",6,NULL},
{__LINE__, 3.172898814737255e-01,"317290",6,0,0,"317290",6,0,0,"0.31729",6,NULL},
{__LINE__, 2.967012281733283e+11,"297",3,12,0,"296701228173328",3,12,0,"2.97e+11",3,NULL},
{__LINE__, 8.589210867009845e-29,"8589",4,-28,0,"",4,-4,0,"8.589e-29",4,NULL},
{__LINE__, 3.624557765318715e-26,"362",3,-25,0,"",3,-3,0,"3.62e-26",3,NULL},
{__LINE__, 1.867754272422402e+27,"2",1,28,0,"18677542724224019215679488000",1,28,0,"2e+27",1,NULL},
{__LINE__, 5.150243379639871e-22,"5",1,-21,0,"",1,-1,0,"5e-22",1,NULL},
{__LINE__, 1.190174047262241e+06,"119017",6,7,0,"1190174047262",6,7,0,"1.19017e+06",6,NULL},
{__LINE__, 5.502639082882342e-29,"550264",6,-28,0,"",6,-6,0,"5.50264e-29",6,NULL},
{__LINE__, 7.609168279063695e-08,"76091683",8,-7,0,"8",8,-7,0,"7.6091683e-08",8,NULL},
{__LINE__, 5.487757715406920e-12,"548776",6,-11,0,"",6,-6,0,"5.48776e-12",6,NULL},
{__LINE__, 8.221233434744608e+15,"822123",6,16,0,"8221233434744608000000",6,16,0,"8.22123e+15",6,NULL},
{__LINE__, 1.679041208804822e+22,"17",2,23,0,"1679041208804821906227200",2,23,0,"1.7e+22",2,NULL},
{__LINE__, 3.674074760085828e+11,"3674075",7,12,0,"3674074760085828247",7,12,0,"3.674075e+11",7,NULL},
{__LINE__, 9.707698305552811e+26,"9707698",7,27,0,"9707698305552811411573309440000000",7,27,0,"9.707698e+26",7,NULL},
{__LINE__, 3.290460821927777e+07,"329046",6,8,0,"32904608219278",6,8,0,"3.29046e+07",6,NULL},
{__LINE__, 1.921280148435649e-17,"1921280",7,-16,0,"",7,-7,0,"1.92128e-17",7,NULL},
{__LINE__, 7.262738303068721e+09,"726274",6,10,0,"7262738303068721",6,10,0,"7.26274e+09",6,NULL},
{__LINE__, 4.917897575589579e-25,"4917898",7,-24,0,"",7,-7,0,"4.917898e-25",7,NULL},
{__LINE__, 1.848626498191354e+08,"1849",4,9,0,"1848626498191",4,9,0,"1.849e+08",4,NULL},
{__LINE__, 2.820784720947056e+26,"2820785",7,27,0,"2820784720947056016548167680000000",7,27,0,"2.820785e+26",7,NULL},
{__LINE__, 2.127470079770766e+28,"21274701",8,29,0,"2127470079770766141083667660800000000",8,29,0,"2.1274701e+28",8,NULL},
{__LINE__, 6.873538587870355e+25,"6874",4,26,0,"687353858787035465205678080000",4,26,0,"6.874e+25",4,NULL},
{__LINE__, 6.454410097043550e-24,"64544101",8,-23,0,"",8,-8,0,"6.4544101e-24",8,NULL},
{__LINE__, 2.213118618919111e-26,"22131",5,-25,0,"",5,-5,0,"2.2131e-26",5,NULL},
{__LINE__, 8.742226151396711e+18,"9",1,19,0,"87422261513967114240",1,19,0,"9e+18",1,NULL},
{__LINE__, 3.558503745388271e+20,"356",3,21,0,"355850374538827071488000",3,21,0,"3.56e+20",3,NULL},
{__LINE__, 1.553371837875792e-25,"15533718",8,-24,0,"",8,-8,0,"1.5533718e-25",8,NULL},
{__LINE__, 2.939271130182748e+07,"3",1,8,0,"293927113",1,8,0,"3e+07",1,NULL},
{__LINE__, 6.541662345466598e+16,"6542",4,17,0,"654166234546659840000",4,17,0,"6.542e+16",4,NULL},
{__LINE__, 2.248170096684619e-07,"225",3,-6,0,"",3,-3,0,"2.25e-07",3,NULL},
{__LINE__, 2.756161281996178e+00,"28",2,1,0,"276",2,1,0,"2.8",2,NULL},
{__LINE__, 5.239468978174450e+03,"5",1,4,0,"52395",1,4,0,"5e+03",1,NULL},
{__LINE__, 4.338762938029571e-17,"433876",6,-16,0,"",6,-6,0,"4.33876e-17",6,NULL},
{__LINE__, 3.017196887951920e+06,"3",1,7,0,"30171969",1,7,0,"3e+06",1,NULL},
{__LINE__, 3.150206780920639e-18,"32",2,-17,0,"",2,-2,0,"3.2e-18",2,NULL},
{__LINE__, 7.446444859285636e+20,"74464449",8,21,0,"74464448592856363827200000000",8,21,0,"7.4464449e+20",8,NULL},
{__LINE__, 5.738871302601839e+07,"5738871",7,8,0,"573887130260184",7,8,0,"5.738871e+07",7,NULL},
{__LINE__, 1.237491441221398e-03,"12374914",8,-2,0,"123749",8,-2,0,"0.0012374914",8,NULL},
{__LINE__, 7.324627764516713e+09,"73246",5,10,0,"732462776451671",5,10,0,"7.3246e+09",5,NULL},
{__LINE__, 3.259418579308160e+15,"3",1,16,0,"32594185793081600",1,16,0,"3e+15",1,NULL},
{__LINE__, 1.405194834603686e-15,"1",1,-14,0,"",1,-1,0,"1e-15",1,NULL},
{__LINE__, 3.011742184583622e-17,"301",3,-16,0,"",3,-3,0,"3.01e-17",3,NULL},
{__LINE__, 1.106215706057235e-29,"1106216",7,-28,0,"",7,-7,0,"1.106216e-29",7,NULL},
{__LINE__, 4.358471388308310e+16,"43585",5,17,0,"4358471388308310400000",5,17,0,"4.3585e+16",5,NULL},
{__LINE__, 2.072305531071263e-29,"2072",4,-28,0,"",4,-4,0,"2.072e-29",4,NULL},
{__LINE__, 1.986866126874383e-19,"19868661",8,-18,0,"",8,-8,0,"1.9868661e-19",8,NULL},
{__LINE__, 1.428864728880793e-23,"14288647",8,-22,0,"",8,-8,0,"1.4288647e-23",8,NULL},
{__LINE__, 5.262679202231463e+16,"5263",4,17,0,"526267920223146320000",4,17,0,"5.263e+16",4,NULL},
{__LINE__, 2.717198955673183e-15,"271720",6,-14,0,"",6,-6,0,"2.7172e-15",6,NULL},
{__LINE__, 5.150668549567997e-09,"515067",6,-8,0,"",6,-6,0,"5.15067e-09",6,NULL},
{__LINE__, 5.671830707040847e-22,"56718",5,-21,0,"",5,-5,0,"5.6718e-22",5,NULL},
{__LINE__, 1.032009065233582e-28,"1032",4,-27,0,"",4,-4,0,"1.032e-28",4,NULL},
{__LINE__, 3.256531418180773e+17,"32565",5,18,0,"32565314181807731200000",5,18,0,"3.2565e+17",5,NULL},
{__LINE__, 6.855618055697167e+13,"68556181",8,14,0,"6855618055697167187500",8,14,0,"6.8556181e+13",8,NULL},
{__LINE__, 1.838515126542337e-04,"183852",6,-3,0,"184",6,-3,0,"0.000183852",6,NULL},
{__LINE__, 3.269357648926951e+01,"326936",6,2,0,"32693576",6,2,0,"32.6936",6,NULL},
{__LINE__, 3.155127022134804e+00,"316",3,1,0,"3155",3,1,0,"3.16",3,NULL},
{__LINE__, 9.842427380306443e-11,"9842427",7,-10,0,"",7,-7,0,"9.842427e-11",7,NULL},
{__LINE__, 1.170329127498228e-27,"117033",6,-26,0,"",6,-6,0,"1.17033e-27",6,NULL},
{__LINE__, 7.954489717411354e+25,"795449",6,26,0,"79544897174113544854044672000000",6,26,0,"7.95449e+25",6,NULL},
{__LINE__, 1.330137938788394e-21,"133014",6,-20,0,"",6,-6,0,"1.33014e-21",6,NULL},
{__LINE__, 1.263788120181220e+06,"13",2,7,0,"126378812",2,7,0,"1.3e+06",2,NULL},
{__LINE__, 1.017118108979511e+06,"10171181",8,7,0,"101711810897951",8,7,0,"1017118.1",8,NULL},
{__LINE__, 1.128387852183361e-22,"1128",4,-21,0,"",4,-4,0,"1.128e-22",4,NULL},
{__LINE__, 2.047687698869088e-07,"20477",5,-6,0,"",5,-5,0,"2.0477e-07",5,NULL},
{__LINE__, 9.216460471355292e+05,"92165",5,6,0,"92164604714",5,6,0,"9.2165e+05",5,NULL},
{__LINE__, 5.540246538793573e+07,"5540247",7,8,0,"554024653879357",7,8,0,"5.540247e+07",7,NULL},
{__LINE__, 6.986505945589122e-22,"6986506",7,-21,0,"",7,-7,0,"6.986506e-22",7,NULL},
{__LINE__, 1.779386879779575e-18,"18",2,-17,0,"",2,-2,0,"1.8e-18",2,NULL},
{__LINE__, 9.439044013853281e+08,"9439",4,9,0,"9439044013853",4,9,0,"9.439e+08",4,NULL},
{__LINE__, 1.981265125583486e+05,"2",1,6,0,"1981265",1,6,0,"2e+05",1,NULL},
{__LINE__, 5.674986230255942e+22,"6",1,23,0,"567498623025594163527680",1,23,0,"6e+22",1,NULL},
{__LINE__, 2.298864411716790e+15,"22989",5,16,0,"229886441171679000000",5,16,0,"2.2989e+15",5,NULL},
{__LINE__, 4.754726458107860e-26,"475473",6,-25,0,"",6,-6,0,"4.75473e-26",6,NULL},
{__LINE__, 7.998336968052068e-02,"80",2,-1,0,"8",2,-1,0,"0.08",2,NULL},
{__LINE__, 2.186697365330358e+25,"218670",6,26,0,"21866973653303581917315072000000",6,26,0,"2.1867e+25",6,NULL},
{__LINE__, 6.934807529104567e-22,"6935",4,-21,0,"",4,-4,0,"6.935e-22",4,NULL},
{__LINE__, 1.120569139248787e+18,"1120569",7,19,0,"11205691392487869440000000",7,19,0,"1.120569e+18",7,NULL},
{__LINE__, 1.579448259562240e+11,"1579448",7,12,0,"1579448259562239990",7,12,0,"1.579448e+11",7,NULL},
{__LINE__, 2.272794041158999e-21,"2272794",7,-20,0,"",7,-7,0,"2.272794e-21",7,NULL},
{__LINE__, 1.627330067952862e-06,"1627330",7,-5,0,"16",7,-5,0,"1.62733e-06",7,NULL},
{__LINE__, 3.410001865714449e-30,"3410002",7,-29,0,"",7,-7,0,"3.410002e-30",7,NULL},
{__LINE__, 5.061135631527160e+26,"506114",6,27,0,"506113563152715977668427776000000",6,27,0,"5.06114e+26",6,NULL},
{__LINE__, 1.500941743164653e+27,"1501",4,28,0,"15009417431646531311045181440000",4,28,0,"1.501e+27",4,NULL},
{__LINE__, 6.166170245590984e+24,"61661702",8,25,0,"616617024559098434368307200000000",8,25,0,"6.1661702e+24",8,NULL},
{__LINE__, 3.136978730888098e-24,"31",2,-23,0,"",2,-2,0,"3.1e-24",2,NULL},
{__LINE__, 2.970061334090170e+21,"3",1,22,0,"29700613340901702369280",1,22,0,"3e+21",1,NULL},
{__LINE__, 3.291355984766073e-13,"32913560",8,-12,0,"",8,-8,0,"3.291356e-13",8,NULL},
{__LINE__, 9.303595796139161e+03,"93036",5,4,0,"930359580",5,4,0,"9303.6",5,NULL},
{__LINE__, 7.649624512400109e+09,"8",1,10,0,"76496245124",1,10,0,"8e+09",1,NULL},
{__LINE__, 1.390807673774886e-22,"13908",5,-21,0,"",5,-5,0,"1.3908e-22",5,NULL},
{__LINE__, 8.901090936921922e-21,"890",3,-20,0,"",3,-3,0,"8.9e-21",3,NULL},
{__LINE__, 3.420609082386055e-04,"34206",5,-3,0,"34",5,-3,0,"0.00034206",5,NULL},
{__LINE__, 8.719476778541001e+18,"87",2,19,0,"871947677854100070400",2,19,0,"8.7e+18",2,NULL},
{__LINE__, 2.975167062429047e+07,"29751671",8,8,0,"2975167062429047",8,8,0,"29751671",8,"2.975167e+07"},
{__LINE__, 1.386895871501743e-02,"13868959",8,-1,0,"1386896",8,-1,0,"0.013868959",8,NULL},
{__LINE__, 1.249824679294188e-16,"12",2,-15,0,"",2,-2,0,"1.2e-16",2,NULL},
{__LINE__, 8.835235425529023e-01,"88352354",8,0,0,"88352354",8,0,0,"0.88352354",8,NULL},
{__LINE__, 2.719226257905232e-01,"2719",4,0,0,"2719",4,0,0,"0.2719",4,NULL},
{__LINE__, 9.756572868832603e+17,"97565729",8,18,0,"97565728688326028800000000",8,18,0,"9.7565729e+17",8,NULL},
{__LINE__, 6.264826770146615e-01,"626",3,0,0,"626",3,0,0,"0.626",3,NULL},
{__LINE__, 2.972698423704301e-21,"3",1,-20,0,"",1,-1,0,"3e-21",1,NULL},
{__LINE__, 2.176563709034982e-02,"22",2,-1,0,"2",2,-1,0,"0.022",2,NULL},
{__LINE__, 1.181023160092374e+11,"12",2,12,0,"11810231600924",2,12,0,"1.2e+11",2,NULL},
{__LINE__, 7.469767449800807e-04,"74697674",8,-3,0,"74698",8,-3,0,"0.00074697674",8,NULL},
{__LINE__, 1.457185871184082e+29,"1457186",7,30,0,"1457185871184082085455708815360000000",7,30,0,"1.457186e+29",7,NULL},
{__LINE__, 1.426297306275258e-19,"14263",5,-18,0,"",5,-5,0,"1.4263e-19",5,NULL},
{__LINE__, 2.457411275450009e+25,"24574",5,26,0,"2457411275450008963173580800000",5,26,0,"2.4574e+25",5,NULL},
{__LINE__, 8.249246277298404e-20,"82492",5,-19,0,"",5,-5,0,"8.2492e-20",5,NULL},
{__LINE__, 2.921055529607521e-08,"2921056",7,-7,0,"",7,-7,0,"2.921056e-08",7,NULL},
{__LINE__, 4.976498203142557e-25,"50",2,-24,0,"",2,-2,0,"5e-25",2,NULL},
{__LINE__, 2.483141865351692e-21,"25",2,-20,0,"",2,-2,0,"2.5e-21",2,NULL},
{__LINE__, 1.027771450975839e+24,"10278",5,25,0,"102777145097583893413888000000",5,25,0,"1.0278e+24",5,NULL},
{__LINE__, 1.515030972674741e+01,"1515",4,2,0,"151503",4,2,0,"15.15",4,NULL},
{__LINE__, 5.248693720662853e+22,"5",1,23,0,"524869372066285297336320",1,23,0,"5e+22",1,NULL},
{__LINE__, 3.185373401105931e-01,"32",2,0,0,"32",2,0,0,"0.32",2,NULL},
{__LINE__, 1.024581294142808e-06,"10246",5,-5,0,"",5,-5,0,"1.0246e-06",5,NULL},
{__LINE__, 1.734965037632195e-07,"173",3,-6,0,"",3,-3,0,"1.73e-07",3,NULL},
{__LINE__, 1.368662469019739e+03,"13686625",8,4,0,"136866246902",8,4,0,"1368.6625",8,NULL},
{__LINE__, 4.744768215108924e-02,"474477",6,-1,0,"47448",6,-1,0,"0.0474477",6,NULL},
{__LINE__, 3.523947347400251e+10,"35",2,11,0,"3523947347400",2,11,0,"3.5e+10",2,NULL},
{__LINE__, 4.703989947348573e+08,"4704",4,9,0,"4703989947349",4,9,0,"4.704e+08",4,NULL},
{__LINE__, 3.334096615018971e+22,"333410",6,23,0,"33340966150189709524992000000",6,23,0,"3.3341e+22",6,NULL},
{__LINE__, 2.224344163719534e+19,"2224",4,20,0,"222434416371953418240000",4,20,0,"2.224e+19",4,NULL},
{__LINE__, 2.841077022740213e-09,"2841",4,-8,0,"",4,-4,0,"2.841e-09",4,NULL},
{__LINE__, 4.567747128685568e+04,"456775",6,5,0,"45677471287",6,5,0,"45677.5",6,NULL},
{__LINE__, 4.463721781600269e-03,"4",1,-2,0,"",1,-1,0,"0.004",1,NULL},
{__LINE__, 1.581538540826530e+16,"15815385",8,17,0,"1581538540826530000000000",8,17,0,"1.5815385e+16",8,NULL},
{__LINE__, 2.407978509096453e+21,"2",1,22,0,"24079785090964531445760",1,22,0,"2e+21",1,NULL},
{0},
	};
