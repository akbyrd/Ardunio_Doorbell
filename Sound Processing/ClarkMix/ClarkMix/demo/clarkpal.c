// 15-bit BGR palette made from file 
// Pics/clarky.pnm.pal 

#include "clarkpal.h"

const u32 clarkpal_nbcol=19;
const u16 clarkpal_data[]={/* 0 0 0 */ 0x0, /* 0 0 255 */ 0x1F, /* 0 255 255 */ 0x3FF, /* 64 0 255 */ 0x201F, /* 64 64 64 */ 0x2108, /* 64 64 255 */ 0x211F, /* 64 128 128 */ 0x2210, /* 64 255 255 */ 0x23FF, /* 128 64 255 */ 0x411F, /* 128 128 128 0x4210*/ 0x0, /* 128 128 255 */ 0x421F, /* 128 191 191 */ 0x42F7, /* 128 255 255 */ 0x43FF, /* 191 128 255 */ 0x5E1F, /* 191 191 191 */ 0x5EF7, /* 191 191 255 */ 0x5EFF, /* 191 255 255 */ 0x5FFF, /* 255 191 255 */ 0x7EFF, /* 255 255 255 */ 0x7FFF} ;
