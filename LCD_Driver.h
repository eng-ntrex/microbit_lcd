/*****************************************************************************
* | File        :   LCD1in8_Driver.h
* | Author      :   Waveshare team
* | Function    :   ILI9486 Drive function
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* | This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

//data
#define UBYTE   unsigned char
#define UWORD   unsigned int

//Define the full screen height length of the display
#define LCD_WIDTH  160  //LCD width
#define LCD_HEIGHT  128 //LCD height

enum LCD_COLOR {
    WHITE = 0xFFFF,
    BLACK = 0x0000,
    BLUE = 0x001F,
    BRED = 0XF81F,
    GRED = 0XFFE0,
    GBLUE = 0X07FF,
    RED = 0xF800,
    MAGENTA = 0xF81F,
    GREEN = 0x07E0,
    CYAN = 0x7FFF,
    YELLOW = 0xFFE0,
    BROWN = 0XBC40,
    BRRED = 0XFC07,
    GRAY = 0X8430,
    LBLUE = 039ddd,
    BBLUE = 037fc7,
    DBLUE = 0b4da3
};

enum DOT_PIXEL{
    DOT_PIXEL_1 = 1,
    DOT_PIXEL_2,
    DOT_PIXEL_3,
    DOT_PIXEL_4
};

enum LINE_STYLE {
    LINE_SOLID = 0,
    LINE_DOTTED,
};

enum DRAW_FILL {
    DRAW_EMPTY = 0,
    DRAW_FULL,
};

class LCD_Driver{
private:
	void LCD_SPI_Init(void);
	void LCD_Reset(void);
	void LCD_InitReg(void);
	
	void LCD_WriteReg(UBYTE Reg);
    void LCD_WriteData_8Bit(UBYTE Data);
    void LCD_WriteData_Buf(UWORD Buf,unsigned long Len);

    void LCD_SetWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend);
    void LCD_SetCursor(UWORD X, UWORD Y);
    void LCD_SetColor(UWORD Color ,UWORD Xnum, UWORD Ynum);
	
	void LCD_SetPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color);
public:
	void LCD_Init(void);
	
	void LCD_SetBL(int Lev);

    void LCD_Clear(UWORD Color);
    void LCD_ClearBuf(void);

    void LCD_Display(void);
    void LCD_DisplayWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend);
    
	void LCD_DrawPoint(int Xpoint, int Ypoint, DOT_PIXEL Dot_Pixel, int Color);
	void LCD_DisChar_1207(int Xchar, int Ychar, int Char_Offset, int Color);
};

static const unsigned char Font12_Table[] = 
{
    // @0 ' ' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @12 '!' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        

    // @24 '"' (7 pixels wide)
    0x00, //        
    0x6C, //  ## ## 
    0x48, //  #  #  
    0x48, //  #  #  
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @36 '#' (7 pixels wide)
    0x00, //        
    0x14, //    # # 
    0x14, //    # # 
    0x28, //   # #  
    0x7C, //  ##### 
    0x28, //   # #  
    0x7C, //  ##### 
    0x28, //   # #  
    0x50, //  # #   
    0x50, //  # #   
    0x00, //        
    0x00, //        

    // @48 '$' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x38, //   ###  
    0x40, //  #     
    0x40, //  #     
    0x38, //   ###  
    0x48, //  #  #  
    0x70, //  ###   
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        

    // @60 '%' (7 pixels wide)
    0x00, //        
    0x20, //   #    
    0x50, //  # #   
    0x20, //   #    
    0x0C, //     ## 
    0x70, //  ###   
    0x08, //     #  
    0x14, //    # # 
    0x08, //     #  
    0x00, //        
    0x00, //        
    0x00, //        

    // @72 '&' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x18, //    ##  
    0x20, //   #    
    0x20, //   #    
    0x54, //  # # # 
    0x48, //  #  #  
    0x34, //   ## # 
    0x00, //        
    0x00, //        
    0x00, //        

    // @84 ''' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @96 '(' (7 pixels wide)
    0x00, //        
    0x08, //     #  
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x08, //     #  
    0x08, //     #  
    0x00, //        

    // @108 ')' (7 pixels wide)
    0x00, //        
    0x20, //   #    
    0x20, //   #    
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x20, //   #    
    0x20, //   #    
    0x00, //        

    // @120 '*' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x7C, //  ##### 
    0x10, //    #   
    0x28, //   # #  
    0x28, //   # #  
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @132 '+' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0xFE, // #######
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        

    // @144 ',' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x18, //    ##  
    0x10, //    #   
    0x30, //   ##   
    0x20, //   #    
    0x00, //        

    // @156 '-' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @168 '.' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x30, //   ##   
    0x30, //   ##   
    0x00, //        
    0x00, //        
    0x00, //        

    // @180 '/' (7 pixels wide)
    0x00, //        
    0x04, //      # 
    0x04, //      # 
    0x08, //     #  
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x20, //   #    
    0x20, //   #    
    0x40, //  #     
    0x00, //        
    0x00, //        

    // @192 '0' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @204 '1' (7 pixels wide)
    0x00, //        
    0x30, //   ##   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @216 '2' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x04, //      # 
    0x08, //     #  
    0x10, //    #   
    0x20, //   #    
    0x44, //  #   # 
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @228 '3' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x04, //      # 
    0x18, //    ##  
    0x04, //      # 
    0x04, //      # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @240 '4' (7 pixels wide)
    0x00, //        
    0x0C, //     ## 
    0x14, //    # # 
    0x14, //    # # 
    0x24, //   #  # 
    0x44, //  #   # 
    0x7E, //  ######
    0x04, //      # 
    0x0E, //     ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @252 '5' (7 pixels wide)
    0x00, //        
    0x3C, //   #### 
    0x20, //   #    
    0x20, //   #    
    0x38, //   ###  
    0x04, //      # 
    0x04, //      # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @264 '6' (7 pixels wide)
    0x00, //        
    0x1C, //    ### 
    0x20, //   #    
    0x40, //  #     
    0x78, //  ####  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @276 '7' (7 pixels wide)
    0x00, //        
    0x7C, //  ##### 
    0x44, //  #   # 
    0x04, //      # 
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        

    // @288 '8' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @300 '9' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x3C, //   #### 
    0x04, //      # 
    0x08, //     #  
    0x70, //  ###   
    0x00, //        
    0x00, //        
    0x00, //        

    // @312 ':' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x30, //   ##   
    0x30, //   ##   
    0x00, //        
    0x00, //        
    0x30, //   ##   
    0x30, //   ##   
    0x00, //        
    0x00, //        
    0x00, //        

    // @324 ';' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x18, //    ##  
    0x18, //    ##  
    0x00, //        
    0x00, //        
    0x18, //    ##  
    0x30, //   ##   
    0x20, //   #    
    0x00, //        
    0x00, //        

    // @336 '<' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x0C, //     ## 
    0x10, //    #   
    0x60, //  ##    
    0x80, // #      
    0x60, //  ##    
    0x10, //    #   
    0x0C, //     ## 
    0x00, //        
    0x00, //        
    0x00, //        

    // @348 '=' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x7C, //  ##### 
    0x00, //        
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @360 '>' (7 pixels wide)
    0x00, //        
    0x00, //        
    0xC0, // ##     
    0x20, //   #    
    0x18, //    ##  
    0x04, //      # 
    0x18, //    ##  
    0x20, //   #    
    0xC0, // ##     
    0x00, //        
    0x00, //        
    0x00, //        

    // @372 '?' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x18, //    ##  
    0x24, //   #  # 
    0x04, //      # 
    0x08, //     #  
    0x10, //    #   
    0x00, //        
    0x30, //   ##   
    0x00, //        
    0x00, //        
    0x00, //        

    // @384 '@' (7 pixels wide)
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x4C, //  #  ## 
    0x54, //  # # # 
    0x54, //  # # # 
    0x4C, //  #  ## 
    0x40, //  #     
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        

    // @396 'A' (7 pixels wide)
    0x00, //        
    0x30, //   ##   
    0x10, //    #   
    0x28, //   # #  
    0x28, //   # #  
    0x28, //   # #  
    0x7C, //  ##### 
    0x44, //  #   # 
    0xEE, // ### ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @408 'B' (7 pixels wide)
    0x00, //        
    0xF8, // #####  
    0x44, //  #   # 
    0x44, //  #   # 
    0x78, //  ####  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xF8, // #####  
    0x00, //        
    0x00, //        
    0x00, //        

    // @420 'C' (7 pixels wide)
    0x00, //        
    0x3C, //   #### 
    0x44, //  #   # 
    0x40, //  #     
    0x40, //  #     
    0x40, //  #     
    0x40, //  #     
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @432 'D' (7 pixels wide)
    0x00, //        
    0xF0, // ####   
    0x48, //  #  #  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x48, //  #  #  
    0xF0, // ####   
    0x00, //        
    0x00, //        
    0x00, //        

    // @444 'E' (7 pixels wide)
    0x00, //        
    0xFC, // ###### 
    0x44, //  #   # 
    0x50, //  # #   
    0x70, //  ###   
    0x50, //  # #   
    0x40, //  #     
    0x44, //  #   # 
    0xFC, // ###### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @456 'F' (7 pixels wide)
    0x00, //        
    0x7E, //  ######
    0x22, //   #   #
    0x28, //   # #  
    0x38, //   ###  
    0x28, //   # #  
    0x20, //   #    
    0x20, //   #    
    0x70, //  ###   
    0x00, //        
    0x00, //        
    0x00, //        

    // @468 'G' (7 pixels wide)
    0x00, //        
    0x3C, //   #### 
    0x44, //  #   # 
    0x40, //  #     
    0x40, //  #     
    0x4E, //  #  ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @480 'H' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x7C, //  ##### 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xEE, // ### ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @492 'I' (7 pixels wide)
    0x00, //        
    0x7C, //  ##### 
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @504 'J' (7 pixels wide)
    0x00, //        
    0x3C, //   #### 
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x48, //  #  #  
    0x48, //  #  #  
    0x48, //  #  #  
    0x30, //   ##   
    0x00, //        
    0x00, //        
    0x00, //        

    // @516 'K' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x48, //  #  #  
    0x50, //  # #   
    0x70, //  ###   
    0x48, //  #  #  
    0x44, //  #   # 
    0xE6, // ###  ##
    0x00, //        
    0x00, //        
    0x00, //        

    // @528 'L' (7 pixels wide)
    0x00, //        
    0x70, //  ###   
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x24, //   #  # 
    0x24, //   #  # 
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @540 'M' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x6C, //  ## ## 
    0x6C, //  ## ## 
    0x54, //  # # # 
    0x54, //  # # # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xEE, // ### ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @552 'N' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x64, //  ##  # 
    0x64, //  ##  # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x4C, //  #  ## 
    0xEC, // ### ## 
    0x00, //        
    0x00, //        
    0x00, //        

    // @564 'O' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @576 'P' (7 pixels wide)
    0x00, //        
    0x78, //  ####  
    0x24, //   #  # 
    0x24, //   #  # 
    0x24, //   #  # 
    0x38, //   ###  
    0x20, //   #    
    0x20, //   #    
    0x70, //  ###   
    0x00, //        
    0x00, //        
    0x00, //        

    // @588 'Q' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x1C, //    ### 
    0x00, //        
    0x00, //        

    // @600 'R' (7 pixels wide)
    0x00, //        
    0xF8, // #####  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x78, //  ####  
    0x48, //  #  #  
    0x44, //  #   # 
    0xE2, // ###   #
    0x00, //        
    0x00, //        
    0x00, //        

    // @612 'S' (7 pixels wide)
    0x00, //        
    0x34, //   ## # 
    0x4C, //  #  ## 
    0x40, //  #     
    0x38, //   ###  
    0x04, //      # 
    0x04, //      # 
    0x64, //  ##  # 
    0x58, //  # ##  
    0x00, //        
    0x00, //        
    0x00, //        

    // @624 'T' (7 pixels wide)
    0x00, //        
    0xFE, // #######
    0x92, // #  #  #
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @636 'U' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @648 'V' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x28, //   # #  
    0x28, //   # #  
    0x28, //   # #  
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        

    // @660 'W' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x28, //   # #  
    0x00, //        
    0x00, //        
    0x00, //        

    // @672 'X' (7 pixels wide)
    0x00, //        
    0xC6, // ##   ##
    0x44, //  #   # 
    0x28, //   # #  
    0x10, //    #   
    0x10, //    #   
    0x28, //   # #  
    0x44, //  #   # 
    0xC6, // ##   ##
    0x00, //        
    0x00, //        
    0x00, //        

    // @684 'Y' (7 pixels wide)
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x28, //   # #  
    0x28, //   # #  
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @696 'Z' (7 pixels wide)
    0x00, //        
    0x7C, //  ##### 
    0x44, //  #   # 
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x20, //   #    
    0x44, //  #   # 
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @708 '[' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x38, //   ###  
    0x00, //        

    // @720 '\' (7 pixels wide)
    0x00, //        
    0x40, //  #     
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x10, //    #   
    0x10, //    #   
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x00, //        
    0x00, //        

    // @732 ']' (7 pixels wide)
    0x00, //        
    0x38, //   ###  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x38, //   ###  
    0x00, //        

    // @744 '^' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x10, //    #   
    0x28, //   # #  
    0x44, //  #   # 
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @756 '_' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0xFE, // #######

    // @768 '`' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x08, //     #  
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        

    // @780 'a' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x3C, //   #### 
    0x44, //  #   # 
    0x44, //  #   # 
    0x3E, //   #####
    0x00, //        
    0x00, //        
    0x00, //        

    // @792 'b' (7 pixels wide)
    0x00, //        
    0xC0, // ##     
    0x40, //  #     
    0x58, //  # ##  
    0x64, //  ##  # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xF8, // #####  
    0x00, //        
    0x00, //        
    0x00, //        

    // @804 'c' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x3C, //   #### 
    0x44, //  #   # 
    0x40, //  #     
    0x40, //  #     
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @816 'd' (7 pixels wide)
    0x00, //        
    0x0C, //     ## 
    0x04, //      # 
    0x34, //   ## # 
    0x4C, //  #  ## 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x3E, //   #####
    0x00, //        
    0x00, //        
    0x00, //        

    // @828 'e' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x7C, //  ##### 
    0x40, //  #     
    0x40, //  #     
    0x3C, //   #### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @840 'f' (7 pixels wide)
    0x00, //        
    0x1C, //    ### 
    0x20, //   #    
    0x7C, //  ##### 
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @852 'g' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x36, //   ## ##
    0x4C, //  #  ## 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x3C, //   #### 
    0x04, //      # 
    0x38, //   ###  
    0x00, //        

    // @864 'h' (7 pixels wide)
    0x00, //        
    0xC0, // ##     
    0x40, //  #     
    0x58, //  # ##  
    0x64, //  ##  # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xEE, // ### ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @876 'i' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x00, //        
    0x70, //  ###   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @888 'j' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x00, //        
    0x78, //  ####  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x08, //     #  
    0x70, //  ###   
    0x00, //        

    // @900 'k' (7 pixels wide)
    0x00, //        
    0xC0, // ##     
    0x40, //  #     
    0x5C, //  # ### 
    0x48, //  #  #  
    0x70, //  ###   
    0x50, //  # #   
    0x48, //  #  #  
    0xDC, // ## ### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @912 'l' (7 pixels wide)
    0x00, //        
    0x30, //   ##   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @924 'm' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xE8, // ### #  
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0xFE, // #######
    0x00, //        
    0x00, //        
    0x00, //        

    // @936 'n' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xD8, // ## ##  
    0x64, //  ##  # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0xEE, // ### ###
    0x00, //        
    0x00, //        
    0x00, //        

    // @948 'o' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x38, //   ###  
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x38, //   ###  
    0x00, //        
    0x00, //        
    0x00, //        

    // @960 'p' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xD8, // ## ##  
    0x64, //  ##  # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x78, //  ####  
    0x40, //  #     
    0xE0, // ###    
    0x00, //        

    // @972 'q' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x36, //   ## ##
    0x4C, //  #  ## 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x3C, //   #### 
    0x04, //      # 
    0x0E, //     ###
    0x00, //        

    // @984 'r' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x6C, //  ## ## 
    0x30, //   ##   
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @996 's' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x3C, //   #### 
    0x44, //  #   # 
    0x38, //   ###  
    0x04, //      # 
    0x44, //  #   # 
    0x78, //  ####  
    0x00, //        
    0x00, //        
    0x00, //        

    // @1008 't' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x20, //   #    
    0x7C, //  ##### 
    0x20, //   #    
    0x20, //   #    
    0x20, //   #    
    0x22, //   #   #
    0x1C, //    ### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @1020 'u' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xCC, // ##  ## 
    0x44, //  #   # 
    0x44, //  #   # 
    0x44, //  #   # 
    0x4C, //  #  ## 
    0x36, //   ## ##
    0x00, //        
    0x00, //        
    0x00, //        

    // @1032 'v' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x44, //  #   # 
    0x28, //   # #  
    0x28, //   # #  
    0x10, //    #   
    0x00, //        
    0x00, //        
    0x00, //        

    // @1044 'w' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x54, //  # # # 
    0x28, //   # #  
    0x00, //        
    0x00, //        
    0x00, //        

    // @1056 'x' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xCC, // ##  ## 
    0x48, //  #  #  
    0x30, //   ##   
    0x30, //   ##   
    0x48, //  #  #  
    0xCC, // ##  ## 
    0x00, //        
    0x00, //        
    0x00, //        

    // @1068 'y' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0xEE, // ### ###
    0x44, //  #   # 
    0x24, //   #  # 
    0x28, //   # #  
    0x18, //    ##  
    0x10, //    #   
    0x10, //    #   
    0x78, //  ####  
    0x00, //        

    // @1080 'z' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x7C, //  ##### 
    0x48, //  #  #  
    0x10, //    #   
    0x20, //   #    
    0x44, //  #   # 
    0x7C, //  ##### 
    0x00, //        
    0x00, //        
    0x00, //        

    // @1092 '{' (7 pixels wide)
    0x00, //        
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x20, //   #    
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x08, //     #  
    0x00, //        

    // @1104 '|' (7 pixels wide)
    0x00, //        
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x00, //        
    0x00, //        

    // @1116 '}' (7 pixels wide)
    0x00, //        
    0x20, //   #    
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x08, //     #  
    0x10, //    #   
    0x10, //    #   
    0x10, //    #   
    0x20, //   #    
    0x00, //        

    // @1128 '~' (7 pixels wide)
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x24, //   #  # 
    0x58, //  # ##  
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
    0x00, //        
};



#endif



