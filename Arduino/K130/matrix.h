#ifndef __MATRIX_H__
#define __MATRIX_H__

#define J3_1   12
#define J3_2   11
#define J3_3   10
#define J3_4    9
#define J3_5    8
#define J3_6    7
#define J3_7    6
#define J3_8    5
#define J3_9    4
#define J3_10   3
#define J3_11   2

#define J4_1   25
#define J4_2   24
#define J4_3   14
#define J4_4   15
#define J4_5   16
#define J4_6   17
#define J4_7   18
#define J4_8   19
#define J4_9   20
#define J4_10  21
#define J4_11  22
#define J4_12  23

#define MTX_STATE_SIZE     20
#define MTX_PROP_DELAY    100
#define MTX_BUFFER_SIZE    64
#define MTX_DEBOUNCE_TIME  20

#define MTX_PRESSED    0x1000
#define MTX_RELEASED   0x2000

void pinModeJ3(unsigned char mode);
void pinModeJ4(unsigned char mode);
unsigned int digitalReadJ3();
unsigned int digitalReadJ4();
void digitalWriteJ3(unsigned int i);
void digitalWriteJ4(unsigned int i);

void matrix_init();
void matrix_read(unsigned char * state);
unsigned int matrix_read_packet();

#endif
