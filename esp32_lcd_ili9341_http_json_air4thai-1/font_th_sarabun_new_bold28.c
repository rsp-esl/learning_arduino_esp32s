/**
* The MIT License (MIT)
*
* Copyright (c) 2015 Deaware System (http://www.deaware.com)
* Author: Surawut Aonjaiaow
*         Burin Sapsiri
*
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
*/

#include "dw_font.h"
#if defined(__AVR__)
    #include <avr/pgmspace.h>
    #define CONST_PREFIX           const PROGMEM
#elif defined(__XTENSA__)
    #include <pgmspace.h>
    #define CONST_PREFIX           const PROGMEM
#else
    #define CONST_PREFIX           const
#endif

static CONST_PREFIX dw_font_bitmap_t symbol_20 = {
    .width = 0,
    .height = 0,
    .data = {
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_21 = {
    .width = 2,
    .height = 13,
    .data = {
        0xff,
        0xff,
        0xc3,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_22 = {
    .width = 6,
    .height = 5,
    .data = {
        0xcf,
        0x3c,
        0xf3,
        0xcc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_23 = {
    .width = 11,
    .height = 14,
    .data = {
        0x10,
        0xc2,
        0x18,
        0x42,
        0x18,
        0x4f,
        0xfe,
        0x63,
        0x0c,
        0x61,
        0x8c,
        0x31,
        0x9f,
        0xfc,
        0x84,
        0x30,
        0x86,
        0x10,
        0xc6,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_24 = {
    .width = 8,
    .height = 16,
    .data = {
        0x08,
        0x08,
        0x1c,
        0x3f,
        0x62,
        0x60,
        0x70,
        0x38,
        0x1e,
        0x07,
        0x03,
        0x03,
        0x47,
        0xfe,
        0x18,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_25 = {
    .width = 17,
    .height = 14,
    .data = {
        0x78,
        0x04,
        0x3e,
        0x06,
        0x31,
        0x86,
        0x18,
        0xc6,
        0x0c,
        0x62,
        0x06,
        0x33,
        0x01,
        0xf3,
        0x78,
        0xfb,
        0x7e,
        0x01,
        0x31,
        0x81,
        0x98,
        0xc1,
        0x8c,
        0x61,
        0x86,
        0x31,
        0x81,
        0xf1,
        0xc0,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_26 = {
    .width = 13,
    .height = 14,
    .data = {
        0x1e,
        0x01,
        0xf8,
        0x18,
        0xc0,
        0xc6,
        0x06,
        0x30,
        0x1f,
        0x01,
        0xe0,
        0xcd,
        0x86,
        0xc6,
        0x36,
        0x1b,
        0x30,
        0x79,
        0xc3,
        0x87,
        0xff,
        0x1f,
        0x1c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_27 = {
    .width = 2,
    .height = 6,
    .data = {
        0xf5,
        0x50,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_28 = {
    .width = 6,
    .height = 17,
    .data = {
        0x1c,
        0xc3,
        0x18,
        0x63,
        0x0c,
        0x30,
        0xc3,
        0x0c,
        0x30,
        0x61,
        0x83,
        0x0c,
        0x1c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_29 = {
    .width = 6,
    .height = 17,
    .data = {
        0xe0,
        0xc3,
        0x06,
        0x18,
        0x30,
        0xc3,
        0x0c,
        0x30,
        0xc3,
        0x18,
        0x63,
        0x0c,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2a = {
    .width = 7,
    .height = 7,
    .data = {
        0x28,
        0xd8,
        0xe7,
        0xf3,
        0x85,
        0x1b,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2b = {
    .width = 10,
    .height = 10,
    .data = {
        0x0c,
        0x03,
        0x00,
        0xc0,
        0x30,
        0xff,
        0xc3,
        0x00,
        0xc0,
        0x30,
        0x0c,
        0x03,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2c = {
    .width = 3,
    .height = 6,
    .data = {
        0xff,
        0xbd,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2d = {
    .width = 6,
    .height = 2,
    .data = {
        0xff,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2e = {
    .width = 3,
    .height = 3,
    .data = {
        0xff,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2f = {
    .width = 10,
    .height = 15,
    .data = {
        0x00,
        0xc0,
        0x60,
        0x18,
        0x0c,
        0x07,
        0x01,
        0x80,
        0xc0,
        0x30,
        0x18,
        0x06,
        0x03,
        0x00,
        0xc0,
        0x60,
        0x38,
        0x0c,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_30 = {
    .width = 10,
    .height = 13,
    .data = {
        0x1e,
        0x0f,
        0xc6,
        0x1b,
        0x86,
        0xc0,
        0xf0,
        0x3c,
        0x0f,
        0x03,
        0xc0,
        0xf8,
        0x76,
        0x18,
        0xfc,
        0x1e,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_31 = {
    .width = 7,
    .height = 13,
    .data = {
        0x18,
        0x71,
        0xe6,
        0xc1,
        0x83,
        0x06,
        0x0c,
        0x18,
        0x30,
        0x63,
        0xf7,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_32 = {
    .width = 9,
    .height = 13,
    .data = {
        0x3e,
        0x3f,
        0xb8,
        0xe8,
        0x30,
        0x18,
        0x1c,
        0x1c,
        0x1c,
        0x1c,
        0x1c,
        0x1c,
        0x1f,
        0xff,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_33 = {
    .width = 9,
    .height = 13,
    .data = {
        0x3e,
        0x3f,
        0xb8,
        0xd0,
        0x60,
        0x60,
        0xf8,
        0xfe,
        0x03,
        0x01,
        0x80,
        0xe1,
        0xdf,
        0xe7,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_34 = {
    .width = 11,
    .height = 13,
    .data = {
        0x01,
        0x80,
        0xf0,
        0x3e,
        0x0e,
        0xc3,
        0x98,
        0x63,
        0x18,
        0x63,
        0x0c,
        0x61,
        0x9f,
        0xff,
        0xff,
        0x80,
        0xc0,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_35 = {
    .width = 8,
    .height = 13,
    .data = {
        0x7f,
        0x7f,
        0x60,
        0x60,
        0x60,
        0x7c,
        0x7e,
        0x03,
        0x03,
        0x03,
        0x87,
        0xfe,
        0x78,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_36 = {
    .width = 9,
    .height = 14,
    .data = {
        0x03,
        0x07,
        0x87,
        0x07,
        0x07,
        0x03,
        0x03,
        0xf9,
        0xfe,
        0xe3,
        0xe0,
        0xf0,
        0x7c,
        0x77,
        0xf1,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_37 = {
    .width = 10,
    .height = 13,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x70,
        0x18,
        0x0e,
        0x03,
        0x00,
        0xc0,
        0x30,
        0x18,
        0x06,
        0x01,
        0x80,
        0x60,
        0x18,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_38 = {
    .width = 8,
    .height = 13,
    .data = {
        0x3c,
        0x7e,
        0xc7,
        0xc3,
        0xe7,
        0x7e,
        0x7e,
        0xe7,
        0xc3,
        0xc3,
        0xe7,
        0x7e,
        0x3c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_39 = {
    .width = 9,
    .height = 13,
    .data = {
        0x3c,
        0x3f,
        0xb8,
        0xf8,
        0x3c,
        0x1f,
        0x1d,
        0xfe,
        0x7b,
        0x03,
        0x03,
        0x07,
        0x0f,
        0x06,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3a = {
    .width = 3,
    .height = 9,
    .data = {
        0xff,
        0x80,
        0x3f,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3b = {
    .width = 3,
    .height = 12,
    .data = {
        0xff,
        0x80,
        0x3f,
        0xef,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3c = {
    .width = 10,
    .height = 11,
    .data = {
        0x00,
        0x40,
        0x70,
        0x78,
        0x78,
        0x70,
        0x30,
        0x07,
        0x00,
        0x78,
        0x07,
        0x80,
        0x70,
        0x04,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3d = {
    .width = 9,
    .height = 6,
    .data = {
        0xff,
        0xff,
        0xc0,
        0x00,
        0x0f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3e = {
    .width = 10,
    .height = 11,
    .data = {
        0x80,
        0x38,
        0x07,
        0x80,
        0x78,
        0x07,
        0x80,
        0x70,
        0x78,
        0x78,
        0x78,
        0x38,
        0x08,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3f = {
    .width = 6,
    .height = 14,
    .data = {
        0x7b,
        0xf8,
        0xc3,
        0x0c,
        0x71,
        0x8e,
        0x30,
        0xc0,
        0x0c,
        0x30,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_40 = {
    .width = 14,
    .height = 14,
    .data = {
        0x07,
        0xc0,
        0x60,
        0xc2,
        0x79,
        0x92,
        0x32,
        0x40,
        0x46,
        0x0f,
        0x18,
        0xc4,
        0x64,
        0x11,
        0x90,
        0x4e,
        0x43,
        0x24,
        0xf7,
        0x18,
        0x00,
        0x30,
        0x40,
        0x3e,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_41 = {
    .width = 13,
    .height = 14,
    .data = {
        0x07,
        0x00,
        0x38,
        0x03,
        0xe0,
        0x1b,
        0x00,
        0xd8,
        0x0c,
        0x60,
        0x63,
        0x06,
        0x0c,
        0x3f,
        0xe1,
        0xff,
        0x1c,
        0x1c,
        0xe0,
        0xe6,
        0x03,
        0x70,
        0x1c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_42 = {
    .width = 8,
    .height = 14,
    .data = {
        0xfc,
        0xfe,
        0xc7,
        0xc3,
        0xc7,
        0xfe,
        0xfe,
        0xc7,
        0xc3,
        0xc3,
        0xc3,
        0xc7,
        0xfe,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_43 = {
    .width = 10,
    .height = 14,
    .data = {
        0x0f,
        0x8f,
        0xf7,
        0x05,
        0x80,
        0xc0,
        0x30,
        0x0c,
        0x03,
        0x00,
        0xc0,
        0x30,
        0x06,
        0x01,
        0xc1,
        0x3f,
        0xc7,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_44 = {
    .width = 11,
    .height = 14,
    .data = {
        0xfe,
        0x1f,
        0xf3,
        0x07,
        0x60,
        0x6c,
        0x07,
        0x80,
        0xf0,
        0x1e,
        0x03,
        0xc0,
        0x78,
        0x1f,
        0x03,
        0x60,
        0xef,
        0xf9,
        0xfc,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_45 = {
    .width = 8,
    .height = 14,
    .data = {
        0xff,
        0xff,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xff,
        0xff,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xff,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_46 = {
    .width = 8,
    .height = 14,
    .data = {
        0xff,
        0xff,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xff,
        0xff,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_47 = {
    .width = 11,
    .height = 14,
    .data = {
        0x1f,
        0x87,
        0xfd,
        0xc1,
        0x70,
        0x0c,
        0x01,
        0x80,
        0x30,
        0xfe,
        0x1f,
        0xc0,
        0x78,
        0x0d,
        0x81,
        0xb8,
        0x33,
        0xfe,
        0x3f,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_48 = {
    .width = 11,
    .height = 14,
    .data = {
        0xc0,
        0x78,
        0x0f,
        0x01,
        0xe0,
        0x3c,
        0x07,
        0x80,
        0xff,
        0xff,
        0xff,
        0xc0,
        0x78,
        0x0f,
        0x01,
        0xe0,
        0x3c,
        0x07,
        0x80,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_49 = {
    .width = 2,
    .height = 14,
    .data = {
        0xff,
        0xff,
        0xff,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4a = {
    .width = 7,
    .height = 14,
    .data = {
        0x06,
        0x0c,
        0x18,
        0x30,
        0x60,
        0xc1,
        0x83,
        0x06,
        0x0c,
        0x18,
        0x7f,
        0xcf,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4b = {
    .width = 10,
    .height = 14,
    .data = {
        0xc0,
        0xb0,
        0x7c,
        0x3b,
        0x1c,
        0xce,
        0x37,
        0x0f,
        0x83,
        0xe0,
        0xdc,
        0x33,
        0x8c,
        0x73,
        0x0e,
        0xc1,
        0xf0,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4c = {
    .width = 8,
    .height = 14,
    .data = {
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xff,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4d = {
    .width = 14,
    .height = 14,
    .data = {
        0x60,
        0x19,
        0x80,
        0xe7,
        0x03,
        0x9c,
        0x0e,
        0x70,
        0x3b,
        0x61,
        0xad,
        0x86,
        0xf6,
        0x1b,
        0xcc,
        0xcf,
        0x33,
        0x3c,
        0x48,
        0xf1,
        0xe3,
        0xc7,
        0x8f,
        0x0c,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4e = {
    .width = 11,
    .height = 14,
    .data = {
        0xe0,
        0x7e,
        0x0f,
        0xc1,
        0xec,
        0x3d,
        0x87,
        0x98,
        0xf3,
        0x9e,
        0x33,
        0xc7,
        0x78,
        0x6f,
        0x07,
        0xe0,
        0xfc,
        0x0f,
        0x81,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4f = {
    .width = 13,
    .height = 14,
    .data = {
        0x0f,
        0x81,
        0xff,
        0x1c,
        0x1c,
        0xc0,
        0x6e,
        0x03,
        0xe0,
        0x0f,
        0x00,
        0x78,
        0x03,
        0xc0,
        0x1f,
        0x01,
        0xd8,
        0x0c,
        0xe0,
        0xe3,
        0xfe,
        0x07,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_50 = {
    .width = 9,
    .height = 14,
    .data = {
        0xfe,
        0x7f,
        0xb0,
        0xf8,
        0x3c,
        0x1e,
        0x0f,
        0x0f,
        0xfe,
        0xfe,
        0x60,
        0x30,
        0x18,
        0x0c,
        0x06,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_51 = {
    .width = 13,
    .height = 16,
    .data = {
        0x0f,
        0x81,
        0xff,
        0x1c,
        0x1c,
        0xc0,
        0x6e,
        0x03,
        0xe0,
        0x0f,
        0x00,
        0x78,
        0x03,
        0xc0,
        0x1f,
        0x01,
        0xd8,
        0x0c,
        0xe0,
        0xc3,
        0xfc,
        0x07,
        0xe0,
        0x03,
        0xe0,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_52 = {
    .width = 10,
    .height = 14,
    .data = {
        0xfc,
        0x3f,
        0xcc,
        0x3b,
        0x06,
        0xc1,
        0xb0,
        0x6c,
        0x3b,
        0xfc,
        0xfe,
        0x31,
        0xcc,
        0x3b,
        0x06,
        0xc1,
        0xf0,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_53 = {
    .width = 8,
    .height = 14,
    .data = {
        0x3e,
        0x7f,
        0xe2,
        0xc0,
        0xc0,
        0xe0,
        0x7c,
        0x1e,
        0x07,
        0x03,
        0x03,
        0xc7,
        0xfe,
        0x3c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_54 = {
    .width = 12,
    .height = 14,
    .data = {
        0xff,
        0xff,
        0xff,
        0x06,
        0x00,
        0x60,
        0x06,
        0x00,
        0x60,
        0x06,
        0x00,
        0x60,
        0x06,
        0x00,
        0x60,
        0x06,
        0x00,
        0x60,
        0x06,
        0x00,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_55 = {
    .width = 12,
    .height = 14,
    .data = {
        0xc0,
        0x3c,
        0x03,
        0xc0,
        0x3c,
        0x03,
        0xc0,
        0x3c,
        0x03,
        0xc0,
        0x3c,
        0x03,
        0xc0,
        0x3c,
        0x03,
        0xe0,
        0x77,
        0x0e,
        0x3f,
        0xc1,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_56 = {
    .width = 12,
    .height = 14,
    .data = {
        0xe0,
        0x76,
        0x06,
        0x60,
        0x67,
        0x0e,
        0x30,
        0xc3,
        0x0c,
        0x30,
        0xc1,
        0x98,
        0x19,
        0x81,
        0x98,
        0x0f,
        0x00,
        0xf0,
        0x0f,
        0x00,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_57 = {
    .width = 17,
    .height = 14,
    .data = {
        0xe0,
        0x83,
        0xf0,
        0xe1,
        0xd8,
        0x70,
        0xcc,
        0x28,
        0x66,
        0x36,
        0x33,
        0x1b,
        0x19,
        0x88,
        0x8c,
        0x6c,
        0x6c,
        0x36,
        0x36,
        0x1a,
        0x0b,
        0x0f,
        0x07,
        0x87,
        0x83,
        0xc1,
        0x80,
        0xc0,
        0xc0,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_58 = {
    .width = 12,
    .height = 14,
    .data = {
        0xc0,
        0x36,
        0x06,
        0x30,
        0xc3,
        0x9c,
        0x19,
        0x80,
        0xf0,
        0x0f,
        0x00,
        0xf0,
        0x0f,
        0x01,
        0x98,
        0x39,
        0xc3,
        0x0c,
        0x60,
        0x6c,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_59 = {
    .width = 11,
    .height = 14,
    .data = {
        0xe0,
        0xee,
        0x18,
        0xc3,
        0x1c,
        0xc1,
        0x98,
        0x3e,
        0x03,
        0xc0,
        0x30,
        0x06,
        0x00,
        0xc0,
        0x18,
        0x03,
        0x00,
        0x60,
        0x0c,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5a = {
    .width = 11,
    .height = 14,
    .data = {
        0xff,
        0xff,
        0xfc,
        0x03,
        0x80,
        0xe0,
        0x38,
        0x0e,
        0x03,
        0xc0,
        0x70,
        0x1c,
        0x07,
        0x01,
        0xc0,
        0x70,
        0x0f,
        0xff,
        0xff,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5b = {
    .width = 4,
    .height = 17,
    .data = {
        0xfc,
        0xcc,
        0xcc,
        0xcc,
        0xcc,
        0xcc,
        0xcc,
        0xcc,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5c = {
    .width = 10,
    .height = 15,
    .data = {
        0xe0,
        0x1c,
        0x07,
        0x00,
        0xe0,
        0x38,
        0x07,
        0x01,
        0xc0,
        0x38,
        0x06,
        0x01,
        0xc0,
        0x30,
        0x0e,
        0x01,
        0x80,
        0x70,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5d = {
    .width = 4,
    .height = 17,
    .data = {
        0xf3,
        0x33,
        0x33,
        0x33,
        0x33,
        0x33,
        0x33,
        0x33,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5e = {
    .width = 10,
    .height = 9,
    .data = {
        0x0c,
        0x03,
        0x01,
        0xe0,
        0x48,
        0x33,
        0x08,
        0x46,
        0x19,
        0x02,
        0xc0,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5f = {
    .width = 11,
    .height = 2,
    .data = {
        0xff,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_60 = {
    .width = 5,
    .height = 3,
    .data = {
        0xe3,
        0x8e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_61 = {
    .width = 8,
    .height = 10,
    .data = {
        0x7c,
        0xfe,
        0x87,
        0x03,
        0x3f,
        0xff,
        0xe3,
        0xc3,
        0xff,
        0x7b,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_62 = {
    .width = 9,
    .height = 14,
    .data = {
        0xc0,
        0x60,
        0x30,
        0x18,
        0x0d,
        0xe7,
        0xfb,
        0x8f,
        0x83,
        0xc1,
        0xe0,
        0xf0,
        0x7c,
        0x6f,
        0xf6,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_63 = {
    .width = 8,
    .height = 10,
    .data = {
        0x1e,
        0x7f,
        0x60,
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0x60,
        0x7f,
        0x3e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_64 = {
    .width = 9,
    .height = 14,
    .data = {
        0x01,
        0x80,
        0xc0,
        0x60,
        0x33,
        0xdb,
        0xff,
        0x8f,
        0x83,
        0xc1,
        0xe0,
        0xf0,
        0x6c,
        0x77,
        0xf9,
        0xec,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_65 = {
    .width = 9,
    .height = 10,
    .data = {
        0x3e,
        0x3f,
        0xb8,
        0xd8,
        0x3f,
        0xff,
        0xff,
        0x01,
        0xc2,
        0x7f,
        0x9f,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_66 = {
    .width = 8,
    .height = 14,
    .data = {
        0x0e,
        0x1f,
        0x30,
        0x30,
        0xfe,
        0xfe,
        0x30,
        0x30,
        0x30,
        0x30,
        0x30,
        0x30,
        0x30,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_67 = {
    .width = 8,
    .height = 14,
    .data = {
        0x7f,
        0xff,
        0xc6,
        0xc6,
        0xc6,
        0xfe,
        0x7c,
        0x60,
        0x78,
        0x3e,
        0x0e,
        0x86,
        0xfe,
        0x78,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_68 = {
    .width = 10,
    .height = 14,
    .data = {
        0xc0,
        0x30,
        0x0c,
        0x03,
        0x00,
        0xdf,
        0x3f,
        0xee,
        0x1f,
        0x03,
        0xc0,
        0xf0,
        0x3c,
        0x0f,
        0x03,
        0xc0,
        0xf0,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_69 = {
    .width = 2,
    .height = 14,
    .data = {
        0xfc,
        0xff,
        0xff,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6a = {
    .width = 5,
    .height = 18,
    .data = {
        0x18,
        0xc6,
        0x01,
        0x8c,
        0x63,
        0x18,
        0xc6,
        0x31,
        0x8c,
        0x67,
        0xf7,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6b = {
    .width = 8,
    .height = 14,
    .data = {
        0xc0,
        0xc0,
        0xc0,
        0xc0,
        0xc6,
        0xcc,
        0xd8,
        0xf0,
        0xf0,
        0xf0,
        0xd8,
        0xcc,
        0xc6,
        0xc3,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6c = {
    .width = 5,
    .height = 14,
    .data = {
        0xc6,
        0x31,
        0x8c,
        0x63,
        0x18,
        0xc6,
        0x31,
        0xc7,
        0x9c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6d = {
    .width = 14,
    .height = 10,
    .data = {
        0xdc,
        0x73,
        0xff,
        0xee,
        0x79,
        0xf0,
        0xc3,
        0xc3,
        0x0f,
        0x0c,
        0x3c,
        0x30,
        0xf0,
        0xc3,
        0xc3,
        0x0f,
        0x0c,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6e = {
    .width = 9,
    .height = 10,
    .data = {
        0xde,
        0x7f,
        0xb8,
        0xf8,
        0x3c,
        0x1e,
        0x0f,
        0x07,
        0x83,
        0xc1,
        0xe0,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6f = {
    .width = 10,
    .height = 10,
    .data = {
        0x1e,
        0x1f,
        0xe6,
        0x1b,
        0x03,
        0xc0,
        0xf0,
        0x3c,
        0x0d,
        0x86,
        0x7f,
        0x87,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_70 = {
    .width = 10,
    .height = 14,
    .data = {
        0xde,
        0x3f,
        0xee,
        0x1b,
        0x03,
        0xc0,
        0xf0,
        0x3c,
        0x0f,
        0x86,
        0xff,
        0xb7,
        0x8c,
        0x03,
        0x00,
        0xc0,
        0x30,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_71 = {
    .width = 10,
    .height = 14,
    .data = {
        0x1e,
        0xdf,
        0xf6,
        0x1f,
        0x03,
        0xc0,
        0xf0,
        0x3c,
        0x0d,
        0x87,
        0x7f,
        0xc7,
        0xb0,
        0x0c,
        0x03,
        0x00,
        0xc0,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_72 = {
    .width = 5,
    .height = 10,
    .data = {
        0xdf,
        0xf9,
        0x8c,
        0x63,
        0x18,
        0xc6,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_73 = {
    .width = 6,
    .height = 10,
    .data = {
        0x7f,
        0xfc,
        0x3c,
        0xf9,
        0xf1,
        0xc3,
        0xff,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_74 = {
    .width = 7,
    .height = 13,
    .data = {
        0x10,
        0x60,
        0xc7,
        0xff,
        0xe6,
        0x0c,
        0x18,
        0x30,
        0x60,
        0xc1,
        0xf1,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_75 = {
    .width = 11,
    .height = 10,
    .data = {
        0xc0,
        0xd8,
        0x1b,
        0x03,
        0x60,
        0x6c,
        0x0d,
        0x81,
        0xb0,
        0x37,
        0x1e,
        0x7f,
        0xc7,
        0x9c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_76 = {
    .width = 10,
    .height = 10,
    .data = {
        0xe1,
        0xd8,
        0x66,
        0x19,
        0xce,
        0x33,
        0x0c,
        0xc1,
        0xe0,
        0x78,
        0x1e,
        0x03,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_77 = {
    .width = 13,
    .height = 10,
    .data = {
        0xc2,
        0x1e,
        0x38,
        0xf1,
        0xc7,
        0x8e,
        0x36,
        0xdb,
        0x36,
        0xd9,
        0xb6,
        0xcf,
        0x1e,
        0x78,
        0xf1,
        0x83,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_78 = {
    .width = 10,
    .height = 10,
    .data = {
        0xe1,
        0xdc,
        0xe3,
        0x30,
        0x7c,
        0x1e,
        0x07,
        0x83,
        0xf0,
        0xcc,
        0x73,
        0xb8,
        0x70,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_79 = {
    .width = 10,
    .height = 14,
    .data = {
        0xe1,
        0xd8,
        0x67,
        0x38,
        0xce,
        0x33,
        0x0f,
        0xc1,
        0xe0,
        0x78,
        0x0e,
        0x03,
        0x01,
        0xc0,
        0xe0,
        0xf0,
        0x38,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7a = {
    .width = 8,
    .height = 10,
    .data = {
        0xff,
        0xff,
        0x07,
        0x0e,
        0x1c,
        0x38,
        0x70,
        0xe0,
        0xff,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7b = {
    .width = 5,
    .height = 16,
    .data = {
        0x3a,
        0x10,
        0x86,
        0x10,
        0x84,
        0xc1,
        0x08,
        0x44,
        0x21,
        0x07,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7c = {
    .width = 1,
    .height = 20,
    .data = {
        0xff,
        0xff,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7d = {
    .width = 5,
    .height = 16,
    .data = {
        0xe0,
        0x84,
        0x23,
        0x10,
        0x84,
        0x19,
        0x08,
        0x41,
        0x08,
        0x5c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7e = {
    .width = 10,
    .height = 2,
    .data = {
        0x78,
        0x61,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7f = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b880 = {
    .width = 0,
    .height = 0,
    .data = {
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b881 = {
    .width = 9,
    .height = 11,
    .data = {
        0x3e,
        0x7f,
        0xb0,
        0xfc,
        0x36,
        0x1e,
        0x0f,
        0x07,
        0x83,
        0xc1,
        0xe0,
        0xf0,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b882 = {
    .width = 10,
    .height = 11,
    .data = {
        0x7c,
        0xf9,
        0xb9,
        0x6e,
        0x5b,
        0x6c,
        0xc6,
        0x31,
        0x8c,
        0x63,
        0x18,
        0xc7,
        0xf0,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b883 = {
    .width = 9,
    .height = 11,
    .data = {
        0x6c,
        0xab,
        0x79,
        0xb2,
        0xd9,
        0xcb,
        0x64,
        0x22,
        0x11,
        0x08,
        0x84,
        0x41,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b884 = {
    .width = 10,
    .height = 11,
    .data = {
        0x3f,
        0x1f,
        0xee,
        0x1f,
        0x33,
        0xda,
        0xf7,
        0x3f,
        0x0d,
        0xc3,
        0x60,
        0xd8,
        0x36,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b885 = {
    .width = 8,
    .height = 11,
    .data = {
        0x26,
        0x59,
        0x81,
        0x99,
        0xb5,
        0xb5,
        0x7d,
        0x61,
        0x61,
        0x41,
        0x41,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b886 = {
    .width = 11,
    .height = 11,
    .data = {
        0x6c,
        0x6f,
        0xce,
        0x99,
        0xf3,
        0x3a,
        0xc6,
        0xb8,
        0xc6,
        0x1b,
        0xe3,
        0x4f,
        0x69,
        0x3c,
        0xc3,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b887 = {
    .width = 7,
    .height = 11,
    .data = {
        0x1c,
        0x4c,
        0x98,
        0xf8,
        0x78,
        0xd9,
        0x9b,
        0x1e,
        0x1c,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b888 = {
    .width = 10,
    .height = 11,
    .data = {
        0x3f,
        0x1f,
        0xec,
        0x1c,
        0xe3,
        0x4c,
        0xd3,
        0x33,
        0xcc,
        0x33,
        0x0c,
        0xc3,
        0xf0,
        0x78,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b889 = {
    .width = 10,
    .height = 11,
    .data = {
        0x3f,
        0x1f,
        0xe6,
        0x1c,
        0x03,
        0x60,
        0xe4,
        0x39,
        0x1d,
        0x8e,
        0x6e,
        0x5f,
        0x96,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88a = {
    .width = 10,
    .height = 11,
    .data = {
        0x7c,
        0xf9,
        0xb9,
        0x7a,
        0x5b,
        0x6c,
        0xc6,
        0x31,
        0x8c,
        0x63,
        0x18,
        0xc7,
        0xf0,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88b = {
    .width = 10,
    .height = 12,
    .data = {
        0x00,
        0xcb,
        0x35,
        0x7f,
        0x9e,
        0x96,
        0xe7,
        0xb6,
        0xcc,
        0x63,
        0x18,
        0xc6,
        0x31,
        0xfc,
        0x3e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88c = {
    .width = 14,
    .height = 11,
    .data = {
        0x3e,
        0x0d,
        0xfc,
        0x3c,
        0x70,
        0xd8,
        0xc3,
        0xe3,
        0x0f,
        0x0c,
        0x3c,
        0x38,
        0xf8,
        0xfb,
        0x94,
        0xfe,
        0x52,
        0xf6,
        0x30,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88d = {
    .width = 14,
    .height = 16,
    .data = {
        0x3e,
        0x0d,
        0xfc,
        0x3c,
        0x38,
        0xcc,
        0x63,
        0x71,
        0x8d,
        0x86,
        0x36,
        0x18,
        0xdc,
        0x63,
        0x49,
        0x8d,
        0x27,
        0xf3,
        0x0f,
        0x80,
        0x00,
        0x01,
        0x84,
        0x09,
        0x10,
        0x24,
        0x80,
        0x7c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88e = {
    .width = 11,
    .height = 17,
    .data = {
        0x1f,
        0x87,
        0xf9,
        0xc3,
        0xbe,
        0x31,
        0x86,
        0x30,
        0xc6,
        0x1b,
        0xc3,
        0x98,
        0x73,
        0x0d,
        0xc1,
        0x83,
        0x30,
        0x46,
        0x38,
        0xc9,
        0xd9,
        0x27,
        0x18,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88f = {
    .width = 11,
    .height = 18,
    .data = {
        0x1f,
        0x07,
        0xf9,
        0xc3,
        0xbe,
        0x31,
        0x86,
        0x30,
        0xc6,
        0x1b,
        0xc3,
        0x98,
        0x73,
        0x0d,
        0xc1,
        0x80,
        0x30,
        0x86,
        0x18,
        0xde,
        0x5c,
        0xf7,
        0xbe,
        0xee,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b890 = {
    .width = 10,
    .height = 17,
    .data = {
        0x3e,
        0xd8,
        0x4f,
        0xc0,
        0x3e,
        0x31,
        0x92,
        0x64,
        0x98,
        0xe6,
        0x19,
        0x86,
        0x60,
        0xf0,
        0x00,
        0x13,
        0x09,
        0x6e,
        0x7a,
        0xc6,
        0xef,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b891 = {
    .width = 12,
    .height = 11,
    .data = {
        0x6c,
        0xed,
        0x6f,
        0xe7,
        0xb9,
        0x73,
        0x9d,
        0x36,
        0xf3,
        0x1a,
        0x31,
        0xa3,
        0x1c,
        0x31,
        0xc3,
        0x18,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b892 = {
    .width = 14,
    .height = 11,
    .data = {
        0x33,
        0x0d,
        0xfe,
        0x3c,
        0xcc,
        0xf3,
        0x33,
        0xd2,
        0xcf,
        0x4b,
        0x3c,
        0xec,
        0xf7,
        0x7b,
        0x7a,
        0x7d,
        0xc9,
        0x76,
        0x18,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b893 = {
    .width = 15,
    .height = 11,
    .data = {
        0x3e,
        0x0c,
        0xfe,
        0x1b,
        0x8e,
        0x31,
        0x8c,
        0x67,
        0x18,
        0xcc,
        0x31,
        0x98,
        0x66,
        0x38,
        0xde,
        0x49,
        0xf2,
        0x93,
        0xa4,
        0xc6,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b894 = {
    .width = 10,
    .height = 11,
    .data = {
        0x3e,
        0x1f,
        0xee,
        0x1f,
        0x33,
        0xd2,
        0xf4,
        0xbe,
        0xcd,
        0xe3,
        0x70,
        0xdc,
        0x36,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b895 = {
    .width = 10,
    .height = 11,
    .data = {
        0x33,
        0x1f,
        0xec,
        0xcf,
        0x33,
        0xd2,
        0xf4,
        0xbe,
        0xcd,
        0xe3,
        0x70,
        0xdc,
        0x36,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b896 = {
    .width = 9,
    .height = 11,
    .data = {
        0x3e,
        0x3f,
        0xb0,
        0xfe,
        0x33,
        0x1b,
        0x0d,
        0x86,
        0xe3,
        0x49,
        0xa4,
        0xcc,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b897 = {
    .width = 11,
    .height = 11,
    .data = {
        0x71,
        0xd3,
        0x2e,
        0x6d,
        0xbd,
        0x31,
        0xa6,
        0x3c,
        0xc7,
        0x18,
        0xe3,
        0x1c,
        0x63,
        0x0c,
        0x61,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b898 = {
    .width = 10,
    .height = 11,
    .data = {
        0x7c,
        0xff,
        0xfc,
        0x3b,
        0xf0,
        0x3f,
        0x98,
        0xe6,
        0x19,
        0x86,
        0x61,
        0x9f,
        0xe3,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b899 = {
    .width = 11,
    .height = 11,
    .data = {
        0x70,
        0x73,
        0x0e,
        0x61,
        0xbc,
        0x31,
        0x86,
        0x30,
        0xc6,
        0x18,
        0xc6,
        0x1b,
        0x23,
        0xe4,
        0x63,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89a = {
    .width = 12,
    .height = 11,
    .data = {
        0x70,
        0x39,
        0x83,
        0x98,
        0x37,
        0x83,
        0x18,
        0x31,
        0x83,
        0x18,
        0x31,
        0x83,
        0x18,
        0x31,
        0xff,
        0x07,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89b = {
    .width = 12,
    .height = 16,
    .data = {
        0x00,
        0x30,
        0x03,
        0x00,
        0x30,
        0x03,
        0x00,
        0x37,
        0x03,
        0x98,
        0x39,
        0x83,
        0x78,
        0x31,
        0x83,
        0x18,
        0x31,
        0x83,
        0x18,
        0x31,
        0x87,
        0x1f,
        0xf0,
        0x7c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89c = {
    .width = 10,
    .height = 11,
    .data = {
        0x70,
        0xf2,
        0x3c,
        0x8f,
        0xc3,
        0xc0,
        0xf3,
        0x3d,
        0xef,
        0x6b,
        0xf3,
        0xfc,
        0x7e,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89d = {
    .width = 10,
    .height = 16,
    .data = {
        0x00,
        0xc0,
        0x30,
        0x0c,
        0x03,
        0x00,
        0xdc,
        0x3c,
        0x8f,
        0x23,
        0xf0,
        0xf0,
        0x3c,
        0xcf,
        0x73,
        0xd2,
        0xfc,
        0xfe,
        0x1f,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89e = {
    .width = 13,
    .height = 11,
    .data = {
        0x71,
        0x9c,
        0xcc,
        0xe6,
        0x66,
        0xf7,
        0xb1,
        0xa5,
        0x8d,
        0x2c,
        0x79,
        0xe3,
        0x87,
        0x1c,
        0x38,
        0xe1,
        0xc6,
        0x06,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89f = {
    .width = 13,
    .height = 16,
    .data = {
        0x00,
        0x18,
        0x00,
        0xc0,
        0x06,
        0x00,
        0x30,
        0x01,
        0xb8,
        0xce,
        0x66,
        0x73,
        0x33,
        0x7a,
        0xd8,
        0xd2,
        0xc6,
        0x96,
        0x3c,
        0xf1,
        0xc3,
        0x8e,
        0x1c,
        0x70,
        0xe3,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a0 = {
    .width = 11,
    .height = 11,
    .data = {
        0x1f,
        0x87,
        0xf9,
        0xc3,
        0xbe,
        0x31,
        0x86,
        0x30,
        0xc6,
        0x1b,
        0xc3,
        0x98,
        0x73,
        0x0d,
        0xc1,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a1 = {
    .width = 10,
    .height = 11,
    .data = {
        0x70,
        0xe6,
        0x39,
        0x8d,
        0xe3,
        0x18,
        0xc6,
        0x31,
        0x8d,
        0xf3,
        0x9e,
        0xe6,
        0xf7,
        0x1c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a2 = {
    .width = 9,
    .height = 11,
    .data = {
        0x71,
        0xe4,
        0xf2,
        0x7e,
        0x3c,
        0x1b,
        0xcf,
        0x07,
        0x83,
        0xc1,
        0xff,
        0xdf,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a3 = {
    .width = 9,
    .height = 11,
    .data = {
        0x79,
        0xe3,
        0xbe,
        0x1f,
        0xc0,
        0x70,
        0x18,
        0x0c,
        0x1e,
        0x13,
        0x09,
        0x83,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a4 = {
    .width = 9,
    .height = 15,
    .data = {
        0x3e,
        0x3f,
        0xb0,
        0xfe,
        0x33,
        0x1b,
        0x0d,
        0x86,
        0xe3,
        0x49,
        0xa4,
        0xcc,
        0x60,
        0x30,
        0x18,
        0x0c,
        0x06,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a5 = {
    .width = 9,
    .height = 11,
    .data = {
        0x3e,
        0x3f,
        0xb0,
        0xe3,
        0xb7,
        0xfb,
        0x1d,
        0x86,
        0xf3,
        0x65,
        0xb2,
        0xce,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a6 = {
    .width = 11,
    .height = 15,
    .data = {
        0x1f,
        0x87,
        0xf9,
        0x83,
        0xbe,
        0x31,
        0xc6,
        0x30,
        0xc6,
        0x1b,
        0xc3,
        0x98,
        0x73,
        0x0d,
        0xc1,
        0x80,
        0x30,
        0x06,
        0x00,
        0xc0,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a7 = {
    .width = 9,
    .height = 11,
    .data = {
        0x3e,
        0x3f,
        0xb8,
        0xf8,
        0x30,
        0x18,
        0x0c,
        0x06,
        0x0f,
        0x09,
        0x84,
        0xc1,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a8 = {
    .width = 10,
    .height = 12,
    .data = {
        0x00,
        0xcf,
        0xf7,
        0xfb,
        0x87,
        0xcc,
        0xf6,
        0xbd,
        0xcf,
        0xc3,
        0x70,
        0xd8,
        0x36,
        0x0d,
        0x83,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a9 = {
    .width = 14,
    .height = 11,
    .data = {
        0x70,
        0x32,
        0x60,
        0xc9,
        0x83,
        0x1e,
        0xcc,
        0x1c,
        0xbc,
        0x72,
        0xe1,
        0xbf,
        0x06,
        0x0c,
        0x18,
        0x30,
        0x7f,
        0xc0,
        0x7c,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8aa = {
    .width = 9,
    .height = 12,
    .data = {
        0x01,
        0x9f,
        0xdf,
        0xd8,
        0x71,
        0xdb,
        0xfd,
        0x8e,
        0xc3,
        0x79,
        0xb2,
        0xd9,
        0x67,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ab = {
    .width = 11,
    .height = 11,
    .data = {
        0x70,
        0xd3,
        0x26,
        0x64,
        0xbc,
        0x61,
        0x9e,
        0x36,
        0xc6,
        0xd8,
        0xf3,
        0x1e,
        0x63,
        0x8c,
        0x61,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ac = {
    .width = 13,
    .height = 12,
    .data = {
        0x00,
        0x1b,
        0x87,
        0xa6,
        0x4d,
        0x32,
        0x67,
        0x8f,
        0x0c,
        0x18,
        0x6c,
        0xc3,
        0x56,
        0x1e,
        0xb0,
        0xe3,
        0x87,
        0x1c,
        0x30,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ad = {
    .width = 9,
    .height = 11,
    .data = {
        0x7e,
        0x7f,
        0xb0,
        0xe6,
        0x34,
        0x9a,
        0x4d,
        0xc6,
        0xc3,
        0x61,
        0xbf,
        0xc7,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ae = {
    .width = 9,
    .height = 11,
    .data = {
        0x7d,
        0xc3,
        0xdf,
        0xc0,
        0x66,
        0x34,
        0x9a,
        0x4d,
        0xc6,
        0xc3,
        0x7f,
        0x9f,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8af = {
    .width = 9,
    .height = 11,
    .data = {
        0x67,
        0x4b,
        0xe7,
        0x6f,
        0x30,
        0x18,
        0x0c,
        0x06,
        0x03,
        0x01,
        0x80,
        0xc0,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b0 = {
    .width = 8,
    .height = 11,
    .data = {
        0x63,
        0x93,
        0x96,
        0x7c,
        0x00,
        0x00,
        0x63,
        0x93,
        0x93,
        0xf6,
        0x7c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b1 = {
    .width = 9,
    .height = 4,
    .data = {
        0x61,
        0xc9,
        0xe5,
        0xcf,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b2 = {
    .width = 8,
    .height = 11,
    .data = {
        0x3e,
        0x7f,
        0xe3,
        0xc3,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b3 = {
    .width = 12,
    .height = 17,
    .data = {
        0x60,
        0x09,
        0x00,
        0x90,
        0x06,
        0x00,
        0x00,
        0x00,
        0x00,
        0x03,
        0xc0,
        0x7f,
        0x0e,
        0x30,
        0xc3,
        0x00,
        0x30,
        0x03,
        0x00,
        0x30,
        0x03,
        0x00,
        0x30,
        0x03,
        0x00,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b4 = {
    .width = 9,
    .height = 5,
    .data = {
        0x3c,
        0x33,
        0xb0,
        0xdf,
        0xf0,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b5 = {
    .width = 9,
    .height = 5,
    .data = {
        0x3d,
        0xbb,
        0xf0,
        0xff,
        0xf0,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b6 = {
    .width = 9,
    .height = 6,
    .data = {
        0x01,
        0x1f,
        0x59,
        0xd8,
        0x6f,
        0xf0,
        0x0c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b7 = {
    .width = 8,
    .height = 6,
    .data = {
        0x1b,
        0x7f,
        0xc7,
        0xc3,
        0xff,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b8 = {
    .width = 4,
    .height = 6,
    .data = {
        0x6b,
        0x73,
        0x33,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b9 = {
    .width = 8,
    .height = 7,
    .data = {
        0x63,
        0xb3,
        0x73,
        0x33,
        0x33,
        0x3f,
        0x1e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ba = {
    .width = 1,
    .height = 1,
    .data = {
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bb = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bc = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bd = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8be = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bf = {
    .width = 7,
    .height = 16,
    .data = {
        0x10,
        0x23,
        0xf4,
        0x38,
        0x30,
        0xff,
        0x43,
        0x83,
        0x06,
        0x0c,
        0x3f,
        0xde,
        0x04,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b980 = {
    .width = 5,
    .height = 11,
    .data = {
        0xc6,
        0x31,
        0x8c,
        0x63,
        0x1e,
        0xce,
        0x5c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b981 = {
    .width = 11,
    .height = 11,
    .data = {
        0xc3,
        0x18,
        0x63,
        0x0c,
        0x61,
        0x8c,
        0x31,
        0x86,
        0x30,
        0xc7,
        0x9e,
        0xcb,
        0x39,
        0x65,
        0xc7,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b982 = {
    .width = 8,
    .height = 18,
    .data = {
        0x79,
        0xff,
        0xc6,
        0xf0,
        0x38,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x18,
        0x1e,
        0x19,
        0x19,
        0x0e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b983 = {
    .width = 8,
    .height = 18,
    .data = {
        0x7c,
        0xfe,
        0x96,
        0x96,
        0x66,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0c,
        0x0e,
        0x09,
        0x09,
        0x06,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b984 = {
    .width = 9,
    .height = 19,
    .data = {
        0xc8,
        0x6e,
        0x37,
        0x1f,
        0x86,
        0xc3,
        0x60,
        0x30,
        0x18,
        0x0c,
        0x06,
        0x03,
        0x01,
        0x80,
        0xc0,
        0x60,
        0x30,
        0x1e,
        0x0c,
        0x86,
        0x41,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b985 = {
    .width = 8,
    .height = 15,
    .data = {
        0x7e,
        0xff,
        0xe3,
        0xc3,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b986 = {
    .width = 9,
    .height = 16,
    .data = {
        0x36,
        0x3f,
        0xba,
        0xfc,
        0x39,
        0x1c,
        0x8d,
        0x86,
        0x03,
        0x01,
        0x80,
        0xc0,
        0x60,
        0x30,
        0x18,
        0x0c,
        0x06,
        0x03,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b987 = {
    .width = 7,
    .height = 7,
    .data = {
        0x06,
        0x0d,
        0xf6,
        0x0d,
        0x5f,
        0x53,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b988 = {
    .width = 2,
    .height = 3,
    .data = {
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b989 = {
    .width = 7,
    .height = 5,
    .data = {
        0x47,
        0x4d,
        0xb2,
        0xef,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98a = {
    .width = 9,
    .height = 5,
    .data = {
        0x69,
        0xee,
        0xf1,
        0x54,
        0xe4,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98b = {
    .width = 4,
    .height = 3,
    .data = {
        0x6f,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98c = {
    .width = 4,
    .height = 5,
    .data = {
        0x16,
        0xea,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98d = {
    .width = 4,
    .height = 4,
    .data = {
        0x69,
        0x96,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98e = {
    .width = 5,
    .height = 6,
    .data = {
        0x3a,
        0x11,
        0xc8,
        0x70,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98f = {
    .width = 9,
    .height = 9,
    .data = {
        0x3c,
        0x31,
        0xb7,
        0x54,
        0x5a,
        0x2d,
        0x17,
        0x76,
        0xc6,
        0x3e,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b990 = {
    .width = 11,
    .height = 8,
    .data = {
        0x1f,
        0x0f,
        0xfb,
        0x83,
        0xe0,
        0x3c,
        0x07,
        0xc1,
        0xdf,
        0xf0,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b991 = {
    .width = 11,
    .height = 9,
    .data = {
        0x1f,
        0x0f,
        0xf3,
        0x87,
        0x66,
        0x7d,
        0x27,
        0xa4,
        0xdb,
        0x99,
        0xe6,
        0x01,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b992 = {
    .width = 11,
    .height = 12,
    .data = {
        0xc0,
        0x18,
        0x03,
        0x00,
        0x60,
        0x0d,
        0xcd,
        0xe6,
        0xfe,
        0xdf,
        0x23,
        0xe4,
        0x7b,
        0x0f,
        0xff,
        0xff,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b993 = {
    .width = 12,
    .height = 8,
    .data = {
        0x3c,
        0xe7,
        0xff,
        0xe3,
        0x3c,
        0x33,
        0xf3,
        0x3c,
        0xb3,
        0xcb,
        0x37,
        0x33,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b994 = {
    .width = 13,
    .height = 12,
    .data = {
        0x00,
        0x18,
        0x01,
        0xc0,
        0x0c,
        0x00,
        0xe1,
        0xfe,
        0x3f,
        0xe3,
        0xb0,
        0x1a,
        0x40,
        0xd2,
        0x07,
        0x60,
        0x3f,
        0xf8,
        0xff,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b995 = {
    .width = 13,
    .height = 12,
    .data = {
        0x00,
        0x18,
        0x31,
        0xc2,
        0x4c,
        0x12,
        0xe3,
        0xfe,
        0x3f,
        0xe3,
        0xb0,
        0x1a,
        0x40,
        0xd2,
        0x07,
        0x60,
        0x3f,
        0xf8,
        0xff,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b996 = {
    .width = 12,
    .height = 12,
    .data = {
        0xe0,
        0x06,
        0x00,
        0x20,
        0x03,
        0x00,
        0x3f,
        0xc3,
        0xfe,
        0x30,
        0x71,
        0x83,
        0x24,
        0x32,
        0x47,
        0x3f,
        0xe0,
        0xf8,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b997 = {
    .width = 14,
    .height = 12,
    .data = {
        0x00,
        0x1c,
        0x00,
        0x60,
        0x01,
        0x80,
        0x06,
        0x73,
        0x9b,
        0xff,
        0x6c,
        0xcd,
        0xb3,
        0x36,
        0xf0,
        0xdb,
        0x23,
        0xec,
        0x8f,
        0x1c,
        0x70,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b998 = {
    .width = 12,
    .height = 11,
    .data = {
        0x00,
        0x30,
        0x03,
        0x00,
        0x73,
        0xfe,
        0x7f,
        0xce,
        0x00,
        0xc0,
        0x0c,
        0x9c,
        0xff,
        0x27,
        0x72,
        0x21,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b999 = {
    .width = 12,
    .height = 12,
    .data = {
        0x00,
        0x30,
        0x03,
        0x00,
        0x30,
        0x03,
        0x3d,
        0xb7,
        0xff,
        0xe7,
        0x2c,
        0x30,
        0xd9,
        0x8e,
        0x5c,
        0x64,
        0xe3,
        0x87,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99a = {
    .width = 12,
    .height = 11,
    .data = {
        0x67,
        0x79,
        0x77,
        0x9b,
        0xb7,
        0x33,
        0x03,
        0x30,
        0x33,
        0x03,
        0x30,
        0x33,
        0x03,
        0x30,
        0x33,
        0x03,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99b = {
    .width = 16,
    .height = 9,
    .data = {
        0x78,
        0x00,
        0x6c,
        0x00,
        0x86,
        0x80,
        0x9d,
        0x78,
        0xb5,
        0xee,
        0xb5,
        0x59,
        0x9b,
        0x50,
        0x46,
        0x00,
        0x3c,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99c = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99d = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99e = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99f = {
    .width = 18,
    .height = 23,
    .data = {
        0xff,
        0xff,
        0xe0,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x18,
        0x00,
        0x06,
        0x00,
        0x01,
        0x80,
        0x00,
        0x60,
        0x00,
        0x1f,
        0xff,
        0xfc,
    }
};

const dw_font_info_t font_th_sarabun_new_bold28 = {
    .count = 192,
    .font_size = 28,
    .height = 31,
    .symbols = {
        {.utf8=0x20, .offset_x=0, .offset_y=0, .cur_dist=6, .bitmap=&symbol_20},
        {.utf8=0x21, .offset_x=1, .offset_y=-13, .cur_dist=4, .bitmap=&symbol_21},
        {.utf8=0x22, .offset_x=1, .offset_y=-15, .cur_dist=8, .bitmap=&symbol_22},
        {.utf8=0x23, .offset_x=0, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_23},
        {.utf8=0x24, .offset_x=1, .offset_y=-15, .cur_dist=10, .bitmap=&symbol_24},
        {.utf8=0x25, .offset_x=1, .offset_y=-14, .cur_dist=19, .bitmap=&symbol_25},
        {.utf8=0x26, .offset_x=1, .offset_y=-14, .cur_dist=14, .bitmap=&symbol_26},
        {.utf8=0x27, .offset_x=1, .offset_y=-15, .cur_dist=5, .bitmap=&symbol_27},
        {.utf8=0x28, .offset_x=2, .offset_y=-15, .cur_dist=7, .bitmap=&symbol_28},
        {.utf8=0x29, .offset_x=-1, .offset_y=-15, .cur_dist=7, .bitmap=&symbol_29},
        {.utf8=0x2a, .offset_x=0, .offset_y=-14, .cur_dist=10, .bitmap=&symbol_2a},
        {.utf8=0x2b, .offset_x=0, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_2b},
        {.utf8=0x2c, .offset_x=0, .offset_y=-3, .cur_dist=5, .bitmap=&symbol_2c},
        {.utf8=0x2d, .offset_x=0, .offset_y=-7, .cur_dist=6, .bitmap=&symbol_2d},
        {.utf8=0x2e, .offset_x=1, .offset_y=-3, .cur_dist=5, .bitmap=&symbol_2e},
        {.utf8=0x2f, .offset_x=-2, .offset_y=-14, .cur_dist=8, .bitmap=&symbol_2f},
        {.utf8=0x30, .offset_x=1, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_30},
        {.utf8=0x31, .offset_x=2, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_31},
        {.utf8=0x32, .offset_x=0, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_32},
        {.utf8=0x33, .offset_x=0, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_33},
        {.utf8=0x34, .offset_x=0, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_34},
        {.utf8=0x35, .offset_x=0, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_35},
        {.utf8=0x36, .offset_x=1, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_36},
        {.utf8=0x37, .offset_x=1, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_37},
        {.utf8=0x38, .offset_x=1, .offset_y=-13, .cur_dist=10, .bitmap=&symbol_38},
        {.utf8=0x39, .offset_x=1, .offset_y=-13, .cur_dist=11, .bitmap=&symbol_39},
        {.utf8=0x3a, .offset_x=1, .offset_y=-9, .cur_dist=5, .bitmap=&symbol_3a},
        {.utf8=0x3b, .offset_x=0, .offset_y=-9, .cur_dist=5, .bitmap=&symbol_3b},
        {.utf8=0x3c, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_3c},
        {.utf8=0x3d, .offset_x=1, .offset_y=-8, .cur_dist=12, .bitmap=&symbol_3d},
        {.utf8=0x3e, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_3e},
        {.utf8=0x3f, .offset_x=1, .offset_y=-14, .cur_dist=8, .bitmap=&symbol_3f},
        {.utf8=0x40, .offset_x=1, .offset_y=-11, .cur_dist=16, .bitmap=&symbol_40},
        {.utf8=0x41, .offset_x=0, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_41},
        {.utf8=0x42, .offset_x=2, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_42},
        {.utf8=0x43, .offset_x=1, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_43},
        {.utf8=0x44, .offset_x=1, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_44},
        {.utf8=0x45, .offset_x=2, .offset_y=-14, .cur_dist=10, .bitmap=&symbol_45},
        {.utf8=0x46, .offset_x=2, .offset_y=-14, .cur_dist=10, .bitmap=&symbol_46},
        {.utf8=0x47, .offset_x=1, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_47},
        {.utf8=0x48, .offset_x=1, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_48},
        {.utf8=0x49, .offset_x=2, .offset_y=-14, .cur_dist=6, .bitmap=&symbol_49},
        {.utf8=0x4a, .offset_x=0, .offset_y=-14, .cur_dist=8, .bitmap=&symbol_4a},
        {.utf8=0x4b, .offset_x=2, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_4b},
        {.utf8=0x4c, .offset_x=2, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_4c},
        {.utf8=0x4d, .offset_x=0, .offset_y=-14, .cur_dist=16, .bitmap=&symbol_4d},
        {.utf8=0x4e, .offset_x=1, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_4e},
        {.utf8=0x4f, .offset_x=1, .offset_y=-14, .cur_dist=15, .bitmap=&symbol_4f},
        {.utf8=0x50, .offset_x=1, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_50},
        {.utf8=0x51, .offset_x=1, .offset_y=-14, .cur_dist=15, .bitmap=&symbol_51},
        {.utf8=0x52, .offset_x=1, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_52},
        {.utf8=0x53, .offset_x=1, .offset_y=-14, .cur_dist=10, .bitmap=&symbol_53},
        {.utf8=0x54, .offset_x=0, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_54},
        {.utf8=0x55, .offset_x=1, .offset_y=-14, .cur_dist=14, .bitmap=&symbol_55},
        {.utf8=0x56, .offset_x=0, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_56},
        {.utf8=0x57, .offset_x=0, .offset_y=-14, .cur_dist=17, .bitmap=&symbol_57},
        {.utf8=0x58, .offset_x=0, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_58},
        {.utf8=0x59, .offset_x=0, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_59},
        {.utf8=0x5a, .offset_x=1, .offset_y=-14, .cur_dist=13, .bitmap=&symbol_5a},
        {.utf8=0x5b, .offset_x=2, .offset_y=-15, .cur_dist=7, .bitmap=&symbol_5b},
        {.utf8=0x5c, .offset_x=-1, .offset_y=-14, .cur_dist=8, .bitmap=&symbol_5c},
        {.utf8=0x5d, .offset_x=1, .offset_y=-15, .cur_dist=7, .bitmap=&symbol_5d},
        {.utf8=0x5e, .offset_x=0, .offset_y=-13, .cur_dist=12, .bitmap=&symbol_5e},
        {.utf8=0x5f, .offset_x=0, .offset_y=3, .cur_dist=11, .bitmap=&symbol_5f},
        {.utf8=0x60, .offset_x=1, .offset_y=-14, .cur_dist=6, .bitmap=&symbol_60},
        {.utf8=0x61, .offset_x=1, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_61},
        {.utf8=0x62, .offset_x=2, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_62},
        {.utf8=0x63, .offset_x=1, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_63},
        {.utf8=0x64, .offset_x=1, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_64},
        {.utf8=0x65, .offset_x=1, .offset_y=-10, .cur_dist=11, .bitmap=&symbol_65},
        {.utf8=0x66, .offset_x=0, .offset_y=-14, .cur_dist=7, .bitmap=&symbol_66},
        {.utf8=0x67, .offset_x=0, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_67},
        {.utf8=0x68, .offset_x=1, .offset_y=-14, .cur_dist=12, .bitmap=&symbol_68},
        {.utf8=0x69, .offset_x=1, .offset_y=-14, .cur_dist=4, .bitmap=&symbol_69},
        {.utf8=0x6a, .offset_x=-2, .offset_y=-14, .cur_dist=4, .bitmap=&symbol_6a},
        {.utf8=0x6b, .offset_x=2, .offset_y=-14, .cur_dist=10, .bitmap=&symbol_6b},
        {.utf8=0x6c, .offset_x=2, .offset_y=-14, .cur_dist=6, .bitmap=&symbol_6c},
        {.utf8=0x6d, .offset_x=1, .offset_y=-10, .cur_dist=18, .bitmap=&symbol_6d},
        {.utf8=0x6e, .offset_x=0, .offset_y=-10, .cur_dist=11, .bitmap=&symbol_6e},
        {.utf8=0x6f, .offset_x=1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_6f},
        {.utf8=0x70, .offset_x=1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_70},
        {.utf8=0x71, .offset_x=1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_71},
        {.utf8=0x72, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_72},
        {.utf8=0x73, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_73},
        {.utf8=0x74, .offset_x=1, .offset_y=-13, .cur_dist=8, .bitmap=&symbol_74},
        {.utf8=0x75, .offset_x=1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_75},
        {.utf8=0x76, .offset_x=0, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_76},
        {.utf8=0x77, .offset_x=-1, .offset_y=-10, .cur_dist=13, .bitmap=&symbol_77},
        {.utf8=0x78, .offset_x=0, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_78},
        {.utf8=0x79, .offset_x=0, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_79},
        {.utf8=0x7a, .offset_x=1, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_7a},
        {.utf8=0x7b, .offset_x=1, .offset_y=-14, .cur_dist=7, .bitmap=&symbol_7b},
        {.utf8=0x7c, .offset_x=2, .offset_y=-15, .cur_dist=5, .bitmap=&symbol_7c},
        {.utf8=0x7d, .offset_x=1, .offset_y=-14, .cur_dist=7, .bitmap=&symbol_7d},
        {.utf8=0x7e, .offset_x=1, .offset_y=-6, .cur_dist=12, .bitmap=&symbol_7e},
        {.utf8=0x7f, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_7f},
        {.utf8=0xe0b880, .offset_x=0, .offset_y=0, .cur_dist=0, .bitmap=&symbol_e0b880},
        {.utf8=0xe0b881, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b881},
        {.utf8=0xe0b882, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b882},
        {.utf8=0xe0b883, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b883},
        {.utf8=0xe0b884, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b884},
        {.utf8=0xe0b885, .offset_x=1, .offset_y=-11, .cur_dist=11, .bitmap=&symbol_e0b885},
        {.utf8=0xe0b886, .offset_x=1, .offset_y=-11, .cur_dist=14, .bitmap=&symbol_e0b886},
        {.utf8=0xe0b887, .offset_x=0, .offset_y=-11, .cur_dist=10, .bitmap=&symbol_e0b887},
        {.utf8=0xe0b888, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b888},
        {.utf8=0xe0b889, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b889},
        {.utf8=0xe0b88a, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b88a},
        {.utf8=0xe0b88b, .offset_x=1, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b88b},
        {.utf8=0xe0b88c, .offset_x=1, .offset_y=-11, .cur_dist=17, .bitmap=&symbol_e0b88c},
        {.utf8=0xe0b88d, .offset_x=0, .offset_y=-11, .cur_dist=17, .bitmap=&symbol_e0b88d},
        {.utf8=0xe0b88e, .offset_x=1, .offset_y=-11, .cur_dist=14, .bitmap=&symbol_e0b88e},
        {.utf8=0xe0b88f, .offset_x=1, .offset_y=-11, .cur_dist=14, .bitmap=&symbol_e0b88f},
        {.utf8=0xe0b890, .offset_x=0, .offset_y=-11, .cur_dist=11, .bitmap=&symbol_e0b890},
        {.utf8=0xe0b891, .offset_x=1, .offset_y=-11, .cur_dist=15, .bitmap=&symbol_e0b891},
        {.utf8=0xe0b892, .offset_x=1, .offset_y=-11, .cur_dist=17, .bitmap=&symbol_e0b892},
        {.utf8=0xe0b893, .offset_x=1, .offset_y=-11, .cur_dist=17, .bitmap=&symbol_e0b893},
        {.utf8=0xe0b894, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b894},
        {.utf8=0xe0b895, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b895},
        {.utf8=0xe0b896, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b896},
        {.utf8=0xe0b897, .offset_x=0, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b897},
        {.utf8=0xe0b898, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b898},
        {.utf8=0xe0b899, .offset_x=0, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b899},
        {.utf8=0xe0b89a, .offset_x=1, .offset_y=-11, .cur_dist=15, .bitmap=&symbol_e0b89a},
        {.utf8=0xe0b89b, .offset_x=1, .offset_y=-16, .cur_dist=15, .bitmap=&symbol_e0b89b},
        {.utf8=0xe0b89c, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b89c},
        {.utf8=0xe0b89d, .offset_x=1, .offset_y=-16, .cur_dist=13, .bitmap=&symbol_e0b89d},
        {.utf8=0xe0b89e, .offset_x=1, .offset_y=-11, .cur_dist=16, .bitmap=&symbol_e0b89e},
        {.utf8=0xe0b89f, .offset_x=1, .offset_y=-16, .cur_dist=16, .bitmap=&symbol_e0b89f},
        {.utf8=0xe0b8a0, .offset_x=0, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b8a0},
        {.utf8=0xe0b8a1, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b8a1},
        {.utf8=0xe0b8a2, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8a2},
        {.utf8=0xe0b8a3, .offset_x=0, .offset_y=-11, .cur_dist=10, .bitmap=&symbol_e0b8a3},
        {.utf8=0xe0b8a4, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8a4},
        {.utf8=0xe0b8a5, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8a5},
        {.utf8=0xe0b8a6, .offset_x=0, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b8a6},
        {.utf8=0xe0b8a7, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8a7},
        {.utf8=0xe0b8a8, .offset_x=1, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b8a8},
        {.utf8=0xe0b8a9, .offset_x=1, .offset_y=-11, .cur_dist=15, .bitmap=&symbol_e0b8a9},
        {.utf8=0xe0b8aa, .offset_x=1, .offset_y=-12, .cur_dist=12, .bitmap=&symbol_e0b8aa},
        {.utf8=0xe0b8ab, .offset_x=1, .offset_y=-11, .cur_dist=14, .bitmap=&symbol_e0b8ab},
        {.utf8=0xe0b8ac, .offset_x=1, .offset_y=-12, .cur_dist=15, .bitmap=&symbol_e0b8ac},
        {.utf8=0xe0b8ad, .offset_x=0, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8ad},
        {.utf8=0xe0b8ae, .offset_x=1, .offset_y=-11, .cur_dist=11, .bitmap=&symbol_e0b8ae},
        {.utf8=0xe0b8af, .offset_x=1, .offset_y=-11, .cur_dist=12, .bitmap=&symbol_e0b8af},
        {.utf8=0xe0b8b0, .offset_x=1, .offset_y=-11, .cur_dist=11, .bitmap=&symbol_e0b8b0},
        {.utf8=0xe0b8b1, .offset_x=-7, .offset_y=-18, .cur_dist=0, .bitmap=&symbol_e0b8b1},
        {.utf8=0xe0b8b2, .offset_x=0, .offset_y=-11, .cur_dist=10, .bitmap=&symbol_e0b8b2},
        {.utf8=0xe0b8b3, .offset_x=-4, .offset_y=-17, .cur_dist=10, .bitmap=&symbol_e0b8b3},
        {.utf8=0xe0b8b4, .offset_x=-10, .offset_y=-18, .cur_dist=0, .bitmap=&symbol_e0b8b4},
        {.utf8=0xe0b8b5, .offset_x=-10, .offset_y=-19, .cur_dist=0, .bitmap=&symbol_e0b8b5},
        {.utf8=0xe0b8b6, .offset_x=-10, .offset_y=-19, .cur_dist=0, .bitmap=&symbol_e0b8b6},
        {.utf8=0xe0b8b7, .offset_x=-10, .offset_y=-19, .cur_dist=0, .bitmap=&symbol_e0b8b7},
        {.utf8=0xe0b8b8, .offset_x=-5, .offset_y=1, .cur_dist=0, .bitmap=&symbol_e0b8b8},
        {.utf8=0xe0b8b9, .offset_x=-9, .offset_y=1, .cur_dist=0, .bitmap=&symbol_e0b8b9},
        {.utf8=0xe0b8ba, .offset_x=-3, .offset_y=2, .cur_dist=0, .bitmap=&symbol_e0b8ba},
        {.utf8=0xe0b8bb, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b8bb},
        {.utf8=0xe0b8bc, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b8bc},
        {.utf8=0xe0b8bd, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b8bd},
        {.utf8=0xe0b8be, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b8be},
        {.utf8=0xe0b8bf, .offset_x=2, .offset_y=-14, .cur_dist=11, .bitmap=&symbol_e0b8bf},
        {.utf8=0xe0b980, .offset_x=1, .offset_y=-11, .cur_dist=6, .bitmap=&symbol_e0b980},
        {.utf8=0xe0b981, .offset_x=1, .offset_y=-11, .cur_dist=13, .bitmap=&symbol_e0b981},
        {.utf8=0xe0b982, .offset_x=-2, .offset_y=-18, .cur_dist=7, .bitmap=&symbol_e0b982},
        {.utf8=0xe0b983, .offset_x=-1, .offset_y=-18, .cur_dist=8, .bitmap=&symbol_e0b983},
        {.utf8=0xe0b984, .offset_x=-2, .offset_y=-19, .cur_dist=8, .bitmap=&symbol_e0b984},
        {.utf8=0xe0b985, .offset_x=-3, .offset_y=-11, .cur_dist=6, .bitmap=&symbol_e0b985},
        {.utf8=0xe0b986, .offset_x=2, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b986},
        {.utf8=0xe0b987, .offset_x=-9, .offset_y=-20, .cur_dist=0, .bitmap=&symbol_e0b987},
        {.utf8=0xe0b988, .offset_x=-3, .offset_y=-22, .cur_dist=0, .bitmap=&symbol_e0b988},
        {.utf8=0xe0b989, .offset_x=-6, .offset_y=-24, .cur_dist=0, .bitmap=&symbol_e0b989},
        {.utf8=0xe0b98a, .offset_x=-7, .offset_y=-24, .cur_dist=0, .bitmap=&symbol_e0b98a},
        {.utf8=0xe0b98b, .offset_x=-4, .offset_y=-23, .cur_dist=0, .bitmap=&symbol_e0b98b},
        {.utf8=0xe0b98c, .offset_x=-5, .offset_y=-23, .cur_dist=0, .bitmap=&symbol_e0b98c},
        {.utf8=0xe0b98d, .offset_x=-5, .offset_y=-17, .cur_dist=0, .bitmap=&symbol_e0b98d},
        {.utf8=0xe0b98e, .offset_x=-6, .offset_y=-19, .cur_dist=0, .bitmap=&symbol_e0b98e},
        {.utf8=0xe0b98f, .offset_x=2, .offset_y=-9, .cur_dist=13, .bitmap=&symbol_e0b98f},
        {.utf8=0xe0b990, .offset_x=1, .offset_y=-8, .cur_dist=13, .bitmap=&symbol_e0b990},
        {.utf8=0xe0b991, .offset_x=1, .offset_y=-8, .cur_dist=13, .bitmap=&symbol_e0b991},
        {.utf8=0xe0b992, .offset_x=1, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b992},
        {.utf8=0xe0b993, .offset_x=0, .offset_y=-9, .cur_dist=13, .bitmap=&symbol_e0b993},
        {.utf8=0xe0b994, .offset_x=1, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b994},
        {.utf8=0xe0b995, .offset_x=1, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b995},
        {.utf8=0xe0b996, .offset_x=0, .offset_y=-12, .cur_dist=13, .bitmap=&symbol_e0b996},
        {.utf8=0xe0b997, .offset_x=0, .offset_y=-12, .cur_dist=14, .bitmap=&symbol_e0b997},
        {.utf8=0xe0b998, .offset_x=1, .offset_y=-11, .cur_dist=14, .bitmap=&symbol_e0b998},
        {.utf8=0xe0b999, .offset_x=1, .offset_y=-12, .cur_dist=14, .bitmap=&symbol_e0b999},
        {.utf8=0xe0b99a, .offset_x=1, .offset_y=-11, .cur_dist=15, .bitmap=&symbol_e0b99a},
        {.utf8=0xe0b99b, .offset_x=2, .offset_y=-10, .cur_dist=20, .bitmap=&symbol_e0b99b},
        {.utf8=0xe0b99c, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b99c},
        {.utf8=0xe0b99d, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b99d},
        {.utf8=0xe0b99e, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b99e},
        {.utf8=0xe0b99f, .offset_x=1, .offset_y=-23, .cur_dist=20, .bitmap=&symbol_e0b99f},
    }
};

