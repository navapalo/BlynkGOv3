#include "../Arduino_DataBus.h"

#if defined(ESP32) && (CONFIG_IDF_TARGET_ESP32S3)

#ifndef _ARDUINO_RGB_DISPLAY_H_
#define _ARDUINO_RGB_DISPLAY_H_

#include "../Arduino_GFX.h"
#include "../databus/Arduino_ESP32RGBPanel.h"

static const uint8_t gc9503v_type1_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xF0,
    WRITE_BYTES, 5, 0x55, 0xAA, 0x52, 0x08, 0x00,

    WRITE_C8_D16, 0xF6, 0x5A, 0x87,

    WRITE_C8_D8, 0xC1, 0x3F,
    WRITE_C8_D8, 0xC2, 0x0E,
    WRITE_C8_D8, 0xC6, 0xF8,
    WRITE_C8_D8, 0xC9, 0x10,
    WRITE_C8_D8, 0xCD, 0x25,
    WRITE_C8_D8, 0xF8, 0x8A,
    WRITE_C8_D8, 0xAC, 0x45,
    WRITE_C8_D8, 0xA0, 0xDD,
    WRITE_C8_D8, 0xA7, 0x47,

    WRITE_COMMAND_8, 0xFA,
    WRITE_BYTES, 4, 0x00, 0x00, 0x00, 0x04,

    WRITE_C8_D8, 0xA3, 0xEE,

    WRITE_COMMAND_8, 0xFD,
    WRITE_BYTES, 3, 0x28, 0x28, 0x00,

    WRITE_C8_D8, 0x71, 0x48,
    WRITE_C8_D8, 0x72, 0x48,
    WRITE_C8_D16, 0x73, 0x00, 0x44,
    WRITE_C8_D8, 0x97, 0xEE,
    WRITE_C8_D8, 0x83, 0x93,
    WRITE_C8_D8, 0x9A, 0x72,
    WRITE_C8_D8, 0x9B, 0x5a,
    WRITE_C8_D16, 0x82, 0x2c, 0x2c,
    WRITE_C8_D8, 0xB1, 0x10,

    WRITE_COMMAND_8, 0x6D,
    WRITE_BYTES, 32,
    0x00, 0x1F, 0x19, 0x1A,
    0x10, 0x0e, 0x0c, 0x0a,
    0x02, 0x07, 0x1E, 0x1E,
    0x1E, 0x1E, 0x1E, 0x1E,
    0x1E, 0x1E, 0x1E, 0x1E,
    0x1E, 0x1E, 0x08, 0x01,
    0x09, 0x0b, 0x0D, 0x0F,
    0x1a, 0x19, 0x1f, 0x00,

    WRITE_COMMAND_8, 0x64,
    WRITE_BYTES, 16,
    0x38, 0x05, 0x01, 0xdb,
    0x03, 0x03, 0x38, 0x04,
    0x01, 0xdc, 0x03, 0x03,
    0x7A, 0x7A, 0x7A, 0x7A,

    WRITE_COMMAND_8, 0x65,
    WRITE_BYTES, 16,
    0x38, 0x03, 0x01, 0xdd,
    0x03, 0x03, 0x38, 0x02,
    0x01, 0xde, 0x03, 0x03,
    0x7A, 0x7A, 0x7A, 0x7A,

    WRITE_COMMAND_8, 0x66,
    WRITE_BYTES, 16,
    0x38, 0x01, 0x01, 0xdf,
    0x03, 0x03, 0x38, 0x00,
    0x01, 0xe0, 0x03, 0x03,
    0x7A, 0x7A, 0x7A, 0x7A,

    WRITE_COMMAND_8, 0x67,
    WRITE_BYTES, 16,
    0x30, 0x01, 0x01, 0xe1,
    0x03, 0x03, 0x30, 0x02,
    0x01, 0xe2, 0x03, 0x03,
    0x7A, 0x7A, 0x7A, 0x7A,

    WRITE_COMMAND_8, 0x68,
    WRITE_BYTES, 13,
    0x00, 0x08, 0x15, 0x08,
    0x15, 0x7A, 0x7A, 0x08,
    0x15, 0x08, 0x15, 0x7A,
    0x7A,

    WRITE_COMMAND_8, 0x60,
    WRITE_BYTES, 8,
    0x38, 0x08, 0x7A, 0x7A,
    0x38, 0x09, 0x7A, 0x7A,

    WRITE_COMMAND_8, 0x63,
    WRITE_BYTES, 8,
    0x31, 0xe4, 0x7A, 0x7A,
    0x31, 0xe5, 0x7A, 0x7A,

    WRITE_C8_D8, 0x6B, 0x07,

    WRITE_C8_D16, 0x7A, 0x08, 0x13,

    WRITE_C8_D16, 0x7B, 0x08, 0x13,

    WRITE_COMMAND_8, 0xD1,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_COMMAND_8, 0xD2,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_COMMAND_8, 0xD3,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_COMMAND_8, 0xD4,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_COMMAND_8, 0xD5,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_COMMAND_8, 0xD6,
    WRITE_BYTES, 52,
    0x00, 0x00, 0x00, 0x04,
    0x00, 0x12, 0x00, 0x18,
    0x00, 0x21, 0x00, 0x2a,
    0x00, 0x35, 0x00, 0x47,
    0x00, 0x56, 0x00, 0x90,
    0x00, 0xe5, 0x01, 0x68,
    0x01, 0xd5, 0x01, 0xd7,
    0x02, 0x36, 0x02, 0xa6,
    0x02, 0xee, 0x03, 0x48,
    0x03, 0xa0, 0x03, 0xba,
    0x03, 0xc5, 0x03, 0xd0,
    0x03, 0xE0, 0x03, 0xea,
    0x03, 0xFa, 0x03, 0xFF,

    WRITE_C8_D8, 0x3a, 0x66,

    WRITE_COMMAND_8, 0x11,
    END_WRITE,

    DELAY, 200,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29,
    END_WRITE};

static const uint8_t st7701_type1_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3B, 0x00,
    WRITE_C8_D16, 0xC1, 0x0D, 0x02,
    WRITE_C8_D16, 0xC2, 0x31, 0x05,
    WRITE_C8_D8, 0xCD, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x18, 0x0E,
    0x11, 0x06, 0x07, 0x08,
    0x07, 0x22, 0x04, 0x12,
    0x0F, 0xAA, 0x31, 0x18,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x19, 0x0E,
    0x12, 0x07, 0x08, 0x08,
    0x08, 0x22, 0x04, 0x11,
    0x11, 0xA9, 0x32, 0x18,

    // PAGE1
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xB0, 0x60, // Vop=4.7375v
    WRITE_C8_D8, 0xB1, 0x32, // VCOM=32
    WRITE_C8_D8, 0xB2, 0x07, // VGH=15v
    WRITE_C8_D8, 0xB3, 0x80,
    WRITE_C8_D8, 0xB5, 0x49, // VGL=-10.17v
    WRITE_C8_D8, 0xB7, 0x85,
    WRITE_C8_D8, 0xB8, 0x21, // AVDD=6.6 & AVCL=-4.6
    WRITE_C8_D8, 0xC1, 0x78,
    WRITE_C8_D8, 0xC2, 0x78,

    WRITE_COMMAND_8, 0xE0,
    WRITE_BYTES, 3, 0x00, 0x1B, 0x02,

    WRITE_COMMAND_8, 0xE1,
    WRITE_BYTES, 11,
    0x08, 0xA0, 0x00, 0x00,
    0x07, 0xA0, 0x00, 0x00,
    0x00, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE2,
    WRITE_BYTES, 12,
    0x11, 0x11, 0x44, 0x44,
    0xED, 0xA0, 0x00, 0x00,
    0xEC, 0xA0, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x11,

    WRITE_C8_D16, 0xE4, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE5,
    WRITE_BYTES, 16,
    0x0A, 0xE9, 0xD8, 0xA0,
    0x0C, 0xEB, 0xD8, 0xA0,
    0x0E, 0xED, 0xD8, 0xA0,
    0x10, 0xEF, 0xD8, 0xA0,

    WRITE_COMMAND_8, 0xE6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x11,

    WRITE_C8_D16, 0xE7, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE8,
    WRITE_BYTES, 16,
    0x09, 0xE8, 0xD8, 0xA0,
    0x0B, 0xEA, 0xD8, 0xA0,
    0x0D, 0xEC, 0xD8, 0xA0,
    0x0F, 0xEE, 0xD8, 0xA0,

    WRITE_COMMAND_8, 0xEB,
    WRITE_BYTES, 7,
    0x02, 0x00, 0xE4, 0xE4,
    0x88, 0x00, 0x40,

    WRITE_C8_D16, 0xEC, 0x3C, 0x00,

    WRITE_COMMAND_8, 0xED,
    WRITE_BYTES, 16,
    0xAB, 0x89, 0x76, 0x54,
    0x02, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x20,
    0x45, 0x67, 0x98, 0xBA,

    //-----------VAP & VAN---------------
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,

    WRITE_C8_D8, 0xE5, 0xE4,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0x21,   // 0x20 normal, 0x21 IPS
    WRITE_C8_D8, 0x3A, 0x60, // 0x70 RGB888, 0x60 RGB666, 0x50 RGB565

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 120,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29, // Display On
    END_WRITE};

static const uint8_t st7701_type2_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0xE9, 0x03,
    WRITE_C8_D16, 0xC1, 0x11, 0x02,
    WRITE_C8_D16, 0xC2, 0x31, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x0D, 0x14, 0x0D,
    0x10, 0x05, 0x02, 0x08,
    0x08, 0x1E, 0x05, 0x13,
    0x11, 0xA3, 0x29, 0x18,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x0C, 0x14, 0x0C,
    0x10, 0x05, 0x03, 0x08,
    0x07, 0x20, 0x05, 0x13,
    0x11, 0xA4, 0x29, 0x18,

    // PAGE1
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xB0, 0x6C,
    WRITE_C8_D8, 0xB1, 0x43,
    WRITE_C8_D8, 0xB2, 0x07,
    WRITE_C8_D8, 0xB3, 0x80,
    WRITE_C8_D8, 0xB5, 0x47,
    WRITE_C8_D8, 0xB7, 0x8A,
    WRITE_C8_D8, 0xB8, 0x20,
    WRITE_C8_D8, 0xC1, 0x78,
    WRITE_C8_D8, 0xC2, 0x78,

    WRITE_C8_D8, 0xD0, 0x88,

    WRITE_COMMAND_8, 0xE0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,

    WRITE_COMMAND_8, 0xE1,
    WRITE_BYTES, 11,
    0x08, 0x00, 0x0A, 0x00,
    0x07, 0x00, 0x09, 0x00,
    0x00, 0x33, 0x33,

    WRITE_COMMAND_8, 0xE2,
    WRITE_BYTES, 12,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x33, 0x33,

    WRITE_C8_D16, 0xE4, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE5,
    WRITE_BYTES, 16,
    0x0E, 0x60, 0xA0, 0xA0,
    0x10, 0x60, 0xA0, 0xA0,
    0x0A, 0x60, 0xA0, 0xA0,
    0x0C, 0x60, 0xA0, 0xA0,

    WRITE_COMMAND_8, 0xE6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x33, 0x33,

    WRITE_C8_D16, 0xE7, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE8,
    WRITE_BYTES, 16,
    0x0D, 0x60, 0xA0, 0xA0,
    0x0F, 0x60, 0xA0, 0xA0,
    0x09, 0x60, 0xA0, 0xA0,
    0x0B, 0x60, 0xA0, 0xA0,

    WRITE_COMMAND_8, 0xEB,
    WRITE_BYTES, 7,
    0x02, 0x01, 0xE4, 0xE4,
    0x44, 0x00, 0x40,

    WRITE_C8_D16, 0xEC, 0x02, 0x01,

    WRITE_COMMAND_8, 0xED,
    WRITE_BYTES, 16,
    0xAB, 0x89, 0x76, 0x54,
    0x01, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x10,
    0x45, 0x67, 0x98, 0xBA,

    //-----------------------------------------End GIP Setting-----------------------------------------//
    //--------------------------- Power Control Registers Initial End------------------------------//
    //-------------------------------------Bank1 Setting------------------------------------------------//
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0x21,   // 0x20 normal, 0x21 IPS
    WRITE_C8_D8, 0x3A, 0x77, // RGB 24bits D[23:0]

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 100,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29, // Display On
    END_WRITE};

static const uint8_t st7701_type3_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3B, 0x00,
    WRITE_C8_D16, 0xC1, 0x0B, 0x02, // VBP
    WRITE_C8_D16, 0xC2, 0x00, 0x02,
    WRITE_C8_D8, 0xCC, 0x10,
    WRITE_C8_D8, 0xCD, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x02, 0x13, 0x1B, 0x0D,
    0x10, 0x05, 0x08, 0x07,
    0x07, 0x24, 0x04, 0x11,
    0x0E, 0x2C, 0x33, 0x1D,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x05, 0x13, 0x1B, 0x0D,
    0x11, 0x05, 0x08, 0x07,
    0x07, 0x24, 0x04, 0x11,
    0x0E, 0x2C, 0x33, 0x1D,

    // PAGE1
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xB0, 0x5d, // 5d
    WRITE_C8_D8, 0xB1, 0x43, // VCOM amplitude setting
    WRITE_C8_D8, 0xB2, 0x81, // VGH Voltage setting, 12V
    WRITE_C8_D8, 0xB3, 0x80,
    WRITE_C8_D8, 0xB5, 0x43, // VGL Voltage setting, -8.3V
    WRITE_C8_D8, 0xB7, 0x85,
    WRITE_C8_D8, 0xB8, 0x20,

    WRITE_C8_D8, 0xC1, 0x78,
    WRITE_C8_D8, 0xC2, 0x78,

    WRITE_C8_D8, 0xD0, 0x88,

    WRITE_COMMAND_8, 0xE0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,

    WRITE_COMMAND_8, 0xE1,
    WRITE_BYTES, 11,
    0x03, 0xA0, 0x00, 0x00,
    0x04, 0xA0, 0x00, 0x00,
    0x00, 0x20, 0x20,

    WRITE_COMMAND_8, 0xE2,
    WRITE_BYTES, 12,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,

    WRITE_C8_D16, 0xE4, 0x22, 0x00,

    WRITE_COMMAND_8, 0xE5,
    WRITE_BYTES, 16,
    0x05, 0xEC, 0xA0, 0xA0,
    0x07, 0xEE, 0xA0, 0xA0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,

    WRITE_C8_D16, 0xE7, 0x22, 0x00,

    WRITE_COMMAND_8, 0xE8,
    WRITE_BYTES, 16,
    0x06, 0xED, 0xA0, 0xA0,
    0x08, 0xEF, 0xA0, 0xA0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xEB,
    WRITE_BYTES, 7,
    0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xED,
    WRITE_BYTES, 16,
    0xFF, 0xFF, 0xFF, 0xBA,
    0x0A, 0xBF, 0x45, 0xFF,
    0xFF, 0x54, 0xFB, 0xA0,
    0xAB, 0xFF, 0xFF, 0xFF,

    WRITE_COMMAND_8, 0xEF,
    WRITE_BYTES, 6,
    0x10, 0x0D, 0x04, 0x08,
    0x3F, 0x1F,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,

    WRITE_C8_D8, 0xEF, 0x08,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 120,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29,   // Display On
    WRITE_COMMAND_8, 0x21,   // 0x20 normal, 0x21 IPS
    WRITE_C8_D8, 0x36, 0x00, // Display data access control
    WRITE_C8_D8, 0x3A, 0x60, // 0x60 18bit   0x50 16bit
    END_WRITE};

static const uint8_t st7701_type4_init_operations[] = {
    BEGIN_WRITE,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3b, 0x00,
    WRITE_C8_D16, 0xC1, 0x0b, 0x02,
    WRITE_C8_D16, 0xC2, 0x07, 0x02,
    WRITE_C8_D8, 0xCC, 0x10,
    WRITE_C8_D8, 0xCD, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x16, 0x0e,
    0x11, 0x06, 0x05, 0x09,
    0x08, 0x21, 0x06, 0x13,
    0x10, 0x29, 0x31, 0x18,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x16, 0x0e,
    0x11, 0x07, 0x05, 0x09,
    0x09, 0x21, 0x05, 0x13,
    0x11, 0x2a, 0x31, 0x18,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xb0, 0x6d,
    WRITE_C8_D8, 0xb1, 0x37,
    WRITE_C8_D8, 0xb2, 0x81,
    WRITE_C8_D8, 0xb3, 0x80,
    WRITE_C8_D8, 0xb5, 0x43,
    WRITE_C8_D8, 0xb7, 0x85,
    WRITE_C8_D8, 0xb8, 0x20,

    WRITE_C8_D8, 0xc1, 0x78,
    WRITE_C8_D8, 0xc2, 0x78,
    WRITE_C8_D8, 0xc3, 0x8c,

    WRITE_C8_D8, 0xd0, 0x88,

    WRITE_COMMAND_8, 0xe0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,
    WRITE_COMMAND_8, 0xe1,
    WRITE_BYTES, 11,
    0x03, 0xa0, 0x00, 0x00,
    0x04, 0xa0, 0x00, 0x00,
    0x00, 0x20, 0x20,
    WRITE_COMMAND_8, 0xe2,
    WRITE_BYTES, 13,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00,
    WRITE_COMMAND_8, 0xe3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,
    WRITE_C8_D16, 0xe4, 0x22, 0x00,
    WRITE_COMMAND_8, 0xe5,
    WRITE_BYTES, 16,
    0x05, 0xec, 0xa0, 0xa0,
    0x07, 0xee, 0xa0, 0xa0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xe6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,
    WRITE_C8_D16, 0xe7, 0x22, 0x00,
    WRITE_COMMAND_8, 0xe8,
    WRITE_BYTES, 16,
    0x06, 0xed, 0xa0, 0xa0,
    0x08, 0xef, 0xa0, 0xa0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xeb,
    WRITE_BYTES, 7,
    0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xed,
    WRITE_BYTES, 16,
    0xff, 0xff, 0xff, 0xba,
    0x0a, 0xbf, 0x45, 0xff,
    0xff, 0x54, 0xfb, 0xa0,
    0xab, 0xff, 0xff, 0xff,
    WRITE_COMMAND_8, 0xef,
    WRITE_BYTES, 6,
    0x10, 0x0d, 0x04, 0x08,
    0x3f, 0x1f,
    WRITE_COMMAND_8, 0xff,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,
    WRITE_C8_D8, 0xef, 0x08,
    WRITE_COMMAND_8, 0xff,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,
    WRITE_C8_D8, 0x36, 0x08,
    WRITE_C8_D8, 0x3a, 0x66,
    WRITE_C8_D8, 0x11, 0x00,
    WRITE_C8_D8, 0x29, 0x00,

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 120,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29,   // Display On
    WRITE_C8_D8, 0x36, 0x08, // Display data access control
    WRITE_C8_D8, 0x3A, 0x60, // 0x60 18bit   0x50 16bit
    END_WRITE};

static const uint8_t st7701_type5_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3B, 0x00,
    WRITE_C8_D16, 0xC1, 0x0B, 0x02, // VBP
    WRITE_C8_D16, 0xC2, 0x00, 0x02,

    WRITE_C8_D8, 0xCC, 0x10,
    WRITE_C8_D8, 0xCD, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x02, 0x13, 0x1B, 0x0D,
    0x10, 0x05, 0x08, 0x07,
    0x07, 0x24, 0x04, 0x11,
    0x0E, 0x2C, 0x33, 0x1D,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x05, 0x13, 0x1B, 0x0D,
    0x11, 0x05, 0x08, 0x07,
    0x07, 0x24, 0x04, 0x11,
    0x0E, 0x2C, 0x33, 0x1D,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xB0, 0x5d, // 5d
    WRITE_C8_D8, 0xB1, 0x43, // VCOM amplitude setting
    WRITE_C8_D8, 0xB2, 0x81, // VGH Voltage setting, 12V
    WRITE_C8_D8, 0xB3, 0x80,

    WRITE_C8_D8, 0xB5, 0x43, // VGL Voltage setting, -8.3V

    WRITE_C8_D8, 0xB7, 0x85,
    WRITE_C8_D8, 0xB8, 0x20,

    WRITE_C8_D8, 0xC1, 0x78,
    WRITE_C8_D8, 0xC2, 0x78,

    WRITE_C8_D8, 0xD0, 0x88,

    WRITE_COMMAND_8, 0xE0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,

    WRITE_COMMAND_8, 0xE1,
    WRITE_BYTES, 11,
    0x03, 0xA0, 0x00, 0x00,
    0x04, 0xA0, 0x00, 0x00,
    0x00, 0x20, 0x20,

    WRITE_COMMAND_8, 0xE2,
    WRITE_BYTES, 13,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00,

    WRITE_COMMAND_8, 0xE3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,

    WRITE_C8_D16, 0xE4, 0x22, 0x00,

    WRITE_COMMAND_8, 0xE5,
    WRITE_BYTES, 16,
    0x05, 0xEC, 0xA0, 0xA0,
    0x07, 0xEE, 0xA0, 0xA0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,

    WRITE_C8_D16, 0xE7, 0x22, 0x00,

    WRITE_COMMAND_8, 0xE8,
    WRITE_BYTES, 16,
    0x06, 0xED, 0xA0, 0xA0,
    0x08, 0xEF, 0xA0, 0xA0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xEB,
    WRITE_BYTES, 7,
    0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xED,
    WRITE_BYTES, 16,
    0xFF, 0xFF, 0xFF, 0xBA,
    0x0A, 0xBF, 0x45, 0xFF,
    0xFF, 0x54, 0xFB, 0xA0,
    0xAB, 0xFF, 0xFF, 0xFF,

    WRITE_COMMAND_8, 0xEF,
    WRITE_BYTES, 6,
    0x10, 0x0D, 0x04, 0x08,
    0x3F, 0x1F,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,

    WRITE_C8_D8, 0xEF, 0x08,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,

    WRITE_C8_D8, 0x36, 0x08,
    WRITE_C8_D8, 0x3A, 0x60, // 0x70 RGB888, 0x60 RGB666, 0x50 RGB565

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 100,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29, // Display On
    END_WRITE,

    DELAY, 50};

static const uint8_t st7701_type6_init_operations[] = {
    BEGIN_WRITE,
    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,
    WRITE_C8_D8, 0xEF, 0x08,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3B, 0x00,

    WRITE_C8_D16, 0xC1, 0x10, 0x0C,

    WRITE_C8_D16, 0xC2, 0x07, 0x0A,

    WRITE_C8_D8, 0xC7, 0x04,

    WRITE_C8_D8, 0xCC, 0x10,

    WRITE_COMMAND_8, 0xB0,
    WRITE_BYTES, 16,
    0x05, 0x12, 0x98, 0x0E,
    0x0F, 0x07, 0x07, 0x09,
    0x09, 0x23, 0x05, 0x52,
    0x0F, 0x67, 0x2C, 0x11,

    WRITE_COMMAND_8, 0xB1,
    WRITE_BYTES, 16,
    0x0B, 0x11, 0x97, 0x0C,
    0x12, 0x06, 0x06, 0x08,
    0x08, 0x22, 0x03, 0x51,
    0x11, 0x66, 0x2B, 0x0F,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xB0, 0x5D,
    WRITE_C8_D8, 0xB1, 0x2D,
    WRITE_C8_D8, 0xB2, 0x81,
    WRITE_C8_D8, 0xB3, 0x80,

    WRITE_C8_D8, 0xB5, 0x4E,

    WRITE_C8_D8, 0xB7, 0x85,
    WRITE_C8_D8, 0xB8, 0x20,

    WRITE_C8_D8, 0xC1, 0x78,
    WRITE_C8_D8, 0xC2, 0x78,

    WRITE_C8_D8, 0xD0, 0x88,

    WRITE_COMMAND_8, 0xE0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,

    WRITE_COMMAND_8, 0xE1,
    WRITE_BYTES, 11,
    0x06, 0x30, 0x08, 0x30,
    0x05, 0x30, 0x07, 0x30,
    0x00, 0x33, 0x33,

    WRITE_COMMAND_8, 0xE2,
    WRITE_BYTES, 12,
    0x11, 0x11, 0x33, 0x33,
    0xF4, 0x00, 0x00, 0x00,
    0xF4, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0xE3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x11,

    WRITE_C8_D16, 0xE4, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE5,
    WRITE_BYTES, 16,
    0x0D, 0xF5, 0x30, 0xF0,
    0x0F, 0xF7, 0x30, 0xF0,
    0x09, 0xF1, 0x30, 0xF0,
    0x0B, 0xF3, 0x30, 0xF0,

    WRITE_COMMAND_8, 0xE6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x11,

    WRITE_C8_D16, 0xE7, 0x44, 0x44,

    WRITE_COMMAND_8, 0xE8,
    WRITE_BYTES, 16,
    0x0C, 0xF4, 0x30, 0xF0,
    0x0E, 0xF6, 0x30, 0xF0,
    0x08, 0xF0, 0x30, 0xF0,
    0x0A, 0xF2, 0x30, 0xF0,

    WRITE_C8_D16, 0xE9, 0x36, 0x01,

    WRITE_COMMAND_8, 0xEB,
    WRITE_BYTES, 7,
    0x00, 0x01, 0xE4, 0xE4,
    0x44, 0x88, 0x40,

    WRITE_COMMAND_8, 0xED,
    WRITE_BYTES, 16,
    0xFF, 0x10, 0xAF, 0x76,
    0x54, 0x2B, 0xCF, 0xFF,
    0xFF, 0xFC, 0xB2, 0x45,
    0x67, 0xFA, 0x01, 0xFF,

    WRITE_COMMAND_8, 0xEF,
    WRITE_BYTES, 6,
    0x08, 0x08, 0x08, 0x45,
    0x3F, 0x54,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,

    WRITE_COMMAND_8, 0x11,
    END_WRITE,

    DELAY, 120, // ms

    BEGIN_WRITE,
    WRITE_C8_D8, 0x3A, 0x66,

    WRITE_C8_D8, 0x36, 0x00,

    WRITE_C8_D8, 0x35, 0x00,

    WRITE_COMMAND_8, 0x29, // Display On
    END_WRITE};

static const uint8_t st7701_type7_init_operations[] = {
    BEGIN_WRITE,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x10,

    WRITE_C8_D16, 0xC0, 0x3b, 0x00,
    WRITE_C8_D16, 0xC1, 0x0b, 0x02,
    WRITE_C8_D16, 0xC2, 0x07, 0x02,
    WRITE_C8_D8, 0xCC, 0x10,
    WRITE_C8_D8, 0xCD, 0x08,

    WRITE_COMMAND_8, 0xB0, // Positive Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x16, 0x0e,
    0x11, 0x06, 0x05, 0x09,
    0x08, 0x21, 0x06, 0x13,
    0x10, 0x29, 0x31, 0x18,

    WRITE_COMMAND_8, 0xB1, // Negative Voltage Gamma Control
    WRITE_BYTES, 16,
    0x00, 0x11, 0x16, 0x0e,
    0x11, 0x07, 0x05, 0x09,
    0x09, 0x21, 0x05, 0x13,
    0x11, 0x2a, 0x31, 0x18,

    WRITE_COMMAND_8, 0xFF,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x11,

    WRITE_C8_D8, 0xb0, 0x6d,
    WRITE_C8_D8, 0xb1, 0x37,
    WRITE_C8_D8, 0xb2, 0x81,
    WRITE_C8_D8, 0xb3, 0x80,
    WRITE_C8_D8, 0xb5, 0x43,
    WRITE_C8_D8, 0xb7, 0x85,
    WRITE_C8_D8, 0xb8, 0x20,

    WRITE_C8_D8, 0xc1, 0x78,
    WRITE_C8_D8, 0xc2, 0x78,

    WRITE_C8_D8, 0xd0, 0x88,

    WRITE_COMMAND_8, 0xe0,
    WRITE_BYTES, 3, 0x00, 0x00, 0x02,
    WRITE_COMMAND_8, 0xe1,
    WRITE_BYTES, 11,
    0x03, 0xa0, 0x00, 0x00,
    0x04, 0xa0, 0x00, 0x00,
    0x00, 0x20, 0x20,
    WRITE_COMMAND_8, 0xe2,
    WRITE_BYTES, 13,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00,
    WRITE_COMMAND_8, 0xe3,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,
    WRITE_C8_D16, 0xe4, 0x22, 0x00,
    WRITE_COMMAND_8, 0xe5,
    WRITE_BYTES, 16,
    0x05, 0xec, 0xa0, 0xa0,
    0x07, 0xee, 0xa0, 0xa0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xe6,
    WRITE_BYTES, 4, 0x00, 0x00, 0x11, 0x00,
    WRITE_C8_D16, 0xe7, 0x22, 0x00,
    WRITE_COMMAND_8, 0xe8,
    WRITE_BYTES, 16,
    0x06, 0xed, 0xa0, 0xa0,
    0x08, 0xef, 0xa0, 0xa0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xeb,
    WRITE_BYTES, 7,
    0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x00,
    WRITE_COMMAND_8, 0xed,
    WRITE_BYTES, 16,
    0xff, 0xff, 0xff, 0xba,
    0x0a, 0xbf, 0x45, 0xff,
    0xff, 0x54, 0xfb, 0xa0,
    0xab, 0xff, 0xff, 0xff,
    WRITE_COMMAND_8, 0xef,
    WRITE_BYTES, 6,
    0x10, 0x0d, 0x04, 0x08,
    0x3f, 0x1f,
    WRITE_COMMAND_8, 0xff,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x13,
    WRITE_C8_D8, 0xef, 0x08,
    WRITE_COMMAND_8, 0xff,
    WRITE_BYTES, 5, 0x77, 0x01, 0x00, 0x00, 0x00,
    WRITE_C8_D8, 0x36, 0x00,
    WRITE_C8_D8, 0x3a, 0x66,
    WRITE_C8_D8, 0x11, 0x00,

    WRITE_COMMAND_8, 0x11, // Sleep Out
    END_WRITE,

    DELAY, 120,

    BEGIN_WRITE,
    WRITE_COMMAND_8, 0x29,   // Display On
    END_WRITE};

class Arduino_RGB_Display : public Arduino_GFX
{
public:
  Arduino_RGB_Display(
      int16_t w, int16_t h, Arduino_ESP32RGBPanel *rgbpanel, uint8_t r = 0, bool auto_flush = true,
      Arduino_DataBus *bus = NULL, int8_t rst = GFX_NOT_DEFINED, const uint8_t *init_operations = NULL, size_t init_operations_len = GFX_NOT_DEFINED);

  bool begin(int32_t speed = GFX_NOT_DEFINED) override;
  void writePixelPreclipped(int16_t x, int16_t y, uint16_t color) override;
  void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
  void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
  void writeFillRectPreclipped(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;
  void drawIndexedBitmap(int16_t x, int16_t y, uint8_t *bitmap, uint16_t *color_index, int16_t w, int16_t h);
  void draw16bitRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) override;
  void draw16bitBeRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) override;
  void flush(void) override;

  uint16_t *getFramebuffer();

protected:
  uint16_t *_framebuffer;
  size_t _framebuffer_size;
  Arduino_ESP32RGBPanel *_rgbpanel;
  bool _auto_flush;
  Arduino_DataBus *_bus;
  int8_t _rst;
  const uint8_t *_init_operations;
  size_t _init_operations_len;

private:
};

#endif // _ARDUINO_RGB_DISPLAY_H_

#endif // #if defined(ESP32) && (CONFIG_IDF_TARGET_ESP32S3)
