/* 
 * File:   LDR_Pin_Definitions.h
 * Author: rfisher
 *
 * Created on 9 February 2017, 1:08 PM
 */

#ifndef LDR_PIN_DEFINITIONS_H
#define	LDR_PIN_DEFINITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define IR_LED_Bank1        PORTEbits.RE2
#define IR_LED_Bank1_Port   TRISE
#define IR_LED_Bank1_Bit    (0x01 << 2)

#define IR_LED_Bank2        PORTEbits.RE5
#define IR_LED_Bank2_Port   TRISE
#define IR_LED_Bank2_Bit    (0x01 << 5)

#define IR_LED_Bank3        PORTEbits.RE4    
#define IR_LED_Bank3_Port   TRISE
#define IR_LED_Bank3_Bit    (0x01 << 4)
    
/********************** LED Bank 1 **********************/
#define LDR_L01         PORTDbits.RD11      // 1  - A26 
#define LDR_L01_Port    TRISD
#define LDR_L01_Bit     (0x01 << 11)

#define LDR_L02         PORTHbits.RH12      // 2  - A01 
#define LDR_L02_Port    TRISH
#define LDR_L02_Bit     (0x01 << 12)

#define LDR_L03         PORTHbits.RH13      // 3  - A27 14
#define LDR_L03_Port    TRISH
#define LDR_L03_Bit     (0x01 << 13)

#define LDR_L04         PORTHbits.RH14      // 4  - A02 26
#define LDR_L04_Port    TRISH
#define LDR_L04_Bit     (0x01 << 14)

#define LDR_L05         PORTHbits.RH15      // 5  - A28 15
#define LDR_L05_Port    TRISH
#define LDR_L05_Bit     (0x01 << 15)

#define LDR_L06         PORTDbits.RD0       // 6  - A03
#define LDR_L06_Port    TRISB
#define LDR_L06_Bit     (0x01 << 0)

#define LDR_L07         PORTDbits.RD1       // 7 - A29
#define LDR_L07_Port    TRISD
#define LDR_L07_Bit     (0x01 << 1)

#define LDR_L08         PORTDbits.RD2       // 8  - A04
#define LDR_L08_Port    TRISD
#define LDR_L08_Bit     (0x01 << 2)

#define LDR_L09         PORTDbits.RD3       // 9  - A30
#define LDR_L09_Port    TRISD
#define LDR_L09_Bit     (0x01 << 3)

#define LDR_L10         PORTDbits.RD12      // 10 - A05 
#define LDR_L10_Port    TRISD
#define LDR_L10_Bit     (0x01 << 12)

#define LDR_L11         PORTDbits.RD13      // 11 - A31 
#define LDR_L11_Port    TRISD
#define LDR_L11_Bit     (0x01 << 13)

#define LDR_L12         PORTJbits.RJ0       // 12 - A06 
#define LDR_L12_Port    TRISJ
#define LDR_L12_Bit     (0x01 << 0)

#define LDR_L13         PORTJbits.RJ1       // 13 - A32 
#define LDR_L13_Port    TRISJ
#define LDR_L13_Bit     (0x01 << 1)

#define LDR_L14         PORTJbits.RJ2       // 14 - A07 
#define LDR_L14_Port    TRISJ
#define LDR_L14_Bit     (0x01 << 2)

#define LDR_L15         PORTJbits.RJ3       // 15 - A33 
#define LDR_L15_Port    TRISJ
#define LDR_L15_Bit     (0x01 << 3)

#define LDR_L16         PORTBbits.RB14      // 16 - A08 
#define LDR_L16_Port    TRISB
#define LDR_L16_Bit     (0x01 << 14)

#define LDR_L17         PORTBbits.RB13       // 17 - A34 
#define LDR_L17_Port    TRISB
#define LDR_L17_Bit     (0x01 << 13)

#define LDR_L18         PORTBbits.RB12       // 18 - A09 
#define LDR_L18_Port    TRISB
#define LDR_L18_Bit     (0x01 << 12)

#define LDR_L19         PORTHbits.RH6       // 19 - A35 
#define LDR_L19_Port    TRISH
#define LDR_L19_Bit     (0x01 << 6)

#define LDR_L20         PORTFbits.RF0       // 20 - A10 
#define LDR_L20_Port    TRISF
#define LDR_L20_Bit     (0x01 << 0)

#define LDR_L21         PORTFbits.RF1       // 21 - A36
#define LDR_L21_Port    TRISF
#define LDR_L21_Bit     (0x01 << 1)

#define LDR_L22         PORTGbits.RG1       // 22 - A11
#define LDR_L22_Port    TRISG
#define LDR_L22_Bit     (0x01 << 1)

#define LDR_L23         PORTGbits.RG0       // 23 - A37
#define LDR_L23_Port    TRISG
#define LDR_L23_Bit     (0x01 << 0)

#define LDR_L24         PORTAbits.RA6       // 24 - A12
#define LDR_L24_Port    TRISA
#define LDR_L24_Bit     (0x01 << 6)

#define LDR_L25         PORTAbits.RA7       // 25 - A38
#define LDR_L25_Port    TRISA
#define LDR_L25_Bit     (0x01 << 7)

/********************** LED Bank 2 **********************/
#define LDR_L26         PORTJbits.RJ4       // 26 - A39 8
#define LDR_L26_Port    TRISJ
#define LDR_L26_Bit     (0x01 << 4)

#define LDR_L27         PORTJbits.RJ5       // 27 - A40 9
#define LDR_L27_Port    TRISJ
#define LDR_L27_Bit     (0x01 << 5)

#define LDR_L28         PORTJbits.RJ6       // 28 - A41 20
#define LDR_L28_Port    TRISJ
#define LDR_L28_Bit     (0x01 << 6)

#define LDR_L29         PORTJbits.RJ7       // 29 - A42 10
#define LDR_L29_Port    TRISJ
#define LDR_L29_Bit     (0x01 << 7)

#define LDR_L30         PORTAbits.RA15       // 30 - A43 21
#define LDR_L30_Port    TRISA
#define LDR_L30_Bit     (0x01 << 15)

#define LDR_L31         PORTEbits.RE1       // 31 - A44 24
#define LDR_L31_Port    TRISE
#define LDR_L31_Bit     (0x01 << 1)

#define LDR_L32         PORTGbits.RG14      // 32 - A45 11
#define LDR_L32_Port    TRISG
#define LDR_L32_Bit     (0x01 << 14)

#define LDR_L33         PORTGbits.RG12      // 33 - A46 22
#define LDR_L33_Port    TRISG
#define LDR_L33_Bit     (0x01 << 12)

#define LDR_L34         PORTGbits.RG13      // 34 - A47 12
#define LDR_L34_Port    TRISG
#define LDR_L34_Bit     (0x01 << 13)

#define LDR_L35         PORTEbits.RE3       // 35 - A48 25
#define LDR_L35_Port    TRISE
#define LDR_L35_Bit     (0x01 << 3)

#define LDR_L36         PORTEbits.RE6       // 36 - A49 13
#define LDR_L36_Port    TRISE
#define LDR_L36_Bit     (0x01 << 6)

#define LDR_L37         PORTEbits.RE7       // 37 - A50 23
#define LDR_L37_Port    TRISE
#define LDR_L37_Bit     (0x01 << 7)

#define LDR_L38         PORTJbits.RJ8       // 38 - A21 30
#define LDR_L38_Port    TRISJ
#define LDR_L38_Bit     (0x01 << 8)

#define LDR_L39         PORTJbits.RJ9       // 39 - A22 31
#define LDR_L39_Port    TRISJ
#define LDR_L39_Bit     (0x01 << 9)

#define LDR_L40         PORTJbits.RJ10      // 40 - A23 35
#define LDR_L40_Port    TRISJ
#define LDR_L40_Bit     (0x01 << 10)

#define LDR_L41         PORTJbits.RJ11      // 41 - A24 32
#define LDR_L41_Port    TRISJ
#define LDR_L41_Bit     (0x01 << 11)

#define LDR_L42         PORTCbits.RC1       // 42 - A25 33
#define LDR_L42_Port    TRISC
#define LDR_L42_Bit     (0x01 << 1)

#define LDR_L43         PORTCbits.RC2       // 43 - A20 49
#define LDR_L43_Port    TRISC
#define LDR_L43_Bit     (0x01 << 2)

#define LDR_L44         PORTCbits.RC3       // 44 - A19 50
#define LDR_L44_Port    TRISc
#define LDR_L44_Bit     (0x01 << 3)

#define LDR_L45         PORTCbits.RC4       // 45 - A18 48
#define LDR_L45_Port    TRISC
#define LDR_L45_Bit     (0x01 << 4)

#define LDR_L46         PORTJbits.RJ12      // 46 - A17 47
#define LDR_L46_Port    TRISJ
#define LDR_L46_Bit     (0x01 << 12)

#define LDR_L47         PORTJbits.RJ13      // 47 - A16 46
#define LDR_L47_Port    TRISJ
#define LDR_L47_Bit     (0x01 << 13)

#define LDR_L48         PORTGbits.RG6       // 48 - A15 45
#define LDR_L48_Port    TRISG
#define LDR_L48_Bit     (0x01 << 6)

#define LDR_L49         PORTGbits.RG7       // 49 - A14
#define LDR_L49_Port    TRISG
#define LDR_L49_Bit     (0x01 << 7)

#define LDR_L50         PORTGbits.RG8       // 50 - A13 43
#define LDR_L50_Port    TRISG
#define LDR_L50_Bit     (0x01 << 8)
    
    
/********************** LED Bank 3 **********************/
#define LDR_L51         PORTJbits.RJ14      // 51 - B13 
#define LDR_L51_Port    TRISJ
#define LDR_L51_Bit     (0x01 << 14)

#define LDR_L52         PORTJbits.RJ15      // 52 - B12 
#define LDR_L52_Port    TRISJ
#define LDR_L52_Bit     (0x01 << 15)

#define LDR_L53         PORTAbits.RA0       // 53 - B11 
#define LDR_L53_Port    TRISA
#define LDR_L53_Bit     (0x01 << 0)

#define LDR_L54         PORTEbits.RE8       // 54 - B01 
#define LDR_L54_Port    TRISE
#define LDR_L54_Bit     (0x01 << 8)

#define LDR_L55         PORTEbits.RE9       // 55 - B02 
#define LDR_L55_Port    TRISE
#define LDR_L55_Bit     (0x01 << 9)

#define LDR_L56         PORTKbits.RK0       // 56 - B03 
#define LDR_L56_Port    TRISK
#define LDR_L56_Bit     (0x01 << 0)

#define LDR_L57         PORTKbits.RK1       // 57 - B04 
#define LDR_L57_Port    TRISK
#define LDR_L57_Bit     (0x01 << 1)

#define LDR_L58         PORTBbits.RB5       // 58 - B05 
#define LDR_L58_Port    TRISB
#define LDR_L58_Bit     (0x01 << 5)

#define LDR_L59         PORTBbits.RB4       // 59 - B06 
#define LDR_L59_Port    TRISB
#define LDR_L59_Bit     (0x01 << 4)

#define LDR_L60         PORTBbits.RB3       // 60 - B07 
#define LDR_L60_Port    TRISB
#define LDR_L60_Bit     (0x01 << 3)

#define LDR_L61         PORTBbits.RB2       // 61 - B08 
#define LDR_L61_Port    TRISB
#define LDR_L61_Bit     (0x01 << 2)

#define LDR_L62         PORTBbits.RB1       // 62 - B09 
#define LDR_L62_Port    TRISB
#define LDR_L62_Bit     (0x01 << 1)

#define LDR_L63         PORTBbits.RB0       // 63 - B10 
#define LDR_L63_Port    TRISB
#define LDR_L63_Bit     (0x01 << 0)

#define LDR_L64         PORTBbits.RB6       // 64 - B14 
#define LDR_L64_Port    TRISB
#define LDR_L64_Bit     (0x01 << 6)

#define LDR_L65         PORTBbits.RB7       // 65 - B15 
#define LDR_L65_Port    TRISB
#define LDR_L65_Bit     (0x01 << 7)

#define LDR_L66         PORTAbits.RA9       // 66 - B16 
#define LDR_L66_Port    TRISA
#define LDR_L66_Bit     (0x01 << 9)

#define LDR_L67         PORTKbits.RK15      // 67 - B17 
#define LDR_L67_Port    TRISK
#define LDR_L67_Bit     (0x01 << 15)

#define LDR_L68         PORTHbits.RH0       // 68 - B18 
#define LDR_L68_Port    TRISH
#define LDR_L68_Bit     (0x01 << 0)

#define LDR_L69         PORTHbits.RH1       // 69 - B19 
#define LDR_L69_Port    TRISH
#define LDR_L69_Bit     (0x01 << 1)

#define LDR_L70         PORTHbits.RH2       // 70 - B20 
#define LDR_L70_Port    TRISH
#define LDR_L70_Bit     (0x01 << 2)

#define LDR_L71         PORTHbits.RH3       // 71 - B21 
#define LDR_L71_Port    TRISH
#define LDR_L71_Bit     (0x01 << 3)

#define LDR_L72         PORTBbits.RB8       // 72 - B22 
#define LDR_L72_Port    TRISB
#define LDR_L72_Bit     (0x01 << 8)

#define LDR_L73         PORTBbits.RB9       // 73 - B23 
#define LDR_L73_Port    TRISB
#define LDR_L73_Bit     (0x01 << 9)

#define LDR_L74         PORTBbits.RB10      // 74 - B24 
#define LDR_L74_Port    TRISB
#define LDR_L74_Bit     (0x01 << 10)

#define LDR_L75         PORTBbits.RB11      // 75 - B25 
#define LDR_L75_Port    TRISB
#define LDR_L75_Bit     (0x01 << 11)

#ifdef	__cplusplus
}
#endif

#endif	/* LDR_PIN_DEFINITIONS_H */

