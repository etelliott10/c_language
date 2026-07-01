#include <stdint.h>

// Common aliases for standard types used in Windows BMP headers
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// Information about the type, size, and layout of a file
typedef struct {
    WORD   bfType;
    DWORD  bfSize;
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;
} __attribute__((__packed__)) BITMAPFILEHEADER;

// Information about the dimensions and color format of a file
typedef struct {
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} __attribute__((__packed__)) BITMAPINFOHEADER;

// Relative intensities of red, green, and blue for a pixel
typedef struct {
  BYTE  rgbtRed;   // stb_image reads Red first
  BYTE  rgbtGreen; // Then Green
  BYTE  rgbtBlue;  // Then Blue
} __attribute__((__packed__)) RGBTRIPLE;
