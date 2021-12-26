#pragma once

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

namespace GHeadset::Color
{
    struct RGB
    {
        uint8_t red;
        uint8_t green;
        uint8_t blue;

        RGB(uint8_t r, uint8_t g, uint8_t b) 
            : red(r), green(g), blue(b) {};
        RGB(uint32_t rgb)
            : red((rgb >> 16) & 0xff), green((rgb >> 8) & 0xff), blue(rgb & 0xff) {};
    };

    // I just like the selection from dot net :)
    namespace Palette
    {
        static const RGB AliceBlue = RGB(240, 248, 255);
        static const RGB AntiqueWhite = RGB(250, 235, 215);
        static const RGB Aqua = RGB(0, 255, 255);
        static const RGB Aquamarine = RGB(127, 255, 212);
        static const RGB Azure = RGB(240, 255, 255);
        static const RGB Beige = RGB(245, 245, 220);
        static const RGB Bisque = RGB(255, 228, 196);
        static const RGB Black = RGB(0, 0, 0);
        static const RGB BlanchedAlmond = RGB(255, 255, 205);
        static const RGB Blue = RGB(0, 0, 255);
        static const RGB BlueViolet = RGB(138, 43, 226);
        static const RGB Brown = RGB(165, 42, 42);
        static const RGB BurlyWood = RGB(222, 184, 135);
        static const RGB CadetBlue = RGB(95, 158, 160);
        static const RGB Chartreuse = RGB(127, 255, 0);
        static const RGB Chocolate = RGB(210, 105, 30);
        static const RGB Coral = RGB(255, 127, 80);
        static const RGB CornflowerBlue = RGB(100, 149, 237);
        static const RGB Cornsilk = RGB(255, 248, 220);
        static const RGB Crimson = RGB(220, 20, 60);
        static const RGB Cyan = RGB(0, 255, 255);
        static const RGB DarkBlue = RGB(0, 0, 139);
        static const RGB DarkCyan = RGB(0, 139, 139);
        static const RGB DarkGoldenrod = RGB(184, 134, 11);
        static const RGB DarkGray = RGB(169, 169, 169);
        static const RGB DarkGreen = RGB(0, 100, 0);
        static const RGB DarkKhaki = RGB(189, 183, 107);
        static const RGB DarkMagena = RGB(139, 0, 139);
        static const RGB DarkOliveGreen = RGB(85, 107, 47);
        static const RGB DarkOrange = RGB(255, 140, 0);
        static const RGB DarkOrchid = RGB(153, 50, 204);
        static const RGB DarkRed = RGB(139, 0, 0);
        static const RGB DarkSalmon = RGB(233, 150, 122);
        static const RGB DarkSeaGreen = RGB(143, 188, 143);
        static const RGB DarkSlateBlue = RGB(72, 61, 139);
        static const RGB DarkSlateGray = RGB(40, 79, 79);
        static const RGB DarkTurquoise = RGB(0, 206, 209);
        static const RGB DarkViolet = RGB(148, 0, 211);
        static const RGB DeepPink = RGB(255, 20, 147);
        static const RGB DeepSkyBlue = RGB(0, 191, 255);
        static const RGB DimGray = RGB(105, 105, 105);
        static const RGB DodgerBlue = RGB(30, 144, 255);
        static const RGB Firebrick = RGB(178, 34, 34);
        static const RGB FloralWhite = RGB(255, 250, 240);
        static const RGB ForestGreen = RGB(34, 139, 34);
        static const RGB Fuschia = RGB(255, 0, 255);
        static const RGB Gainsboro = RGB(220, 220, 220);
        static const RGB GhostWhite = RGB(248, 248, 255);
        static const RGB Gold = RGB(255, 215, 0);
        static const RGB Goldenrod = RGB(218, 165, 32);
        static const RGB Gray = RGB(128, 128, 128);
        static const RGB Green = RGB(0, 128, 0);
        static const RGB GreenYellow = RGB(173, 255, 47);
        static const RGB Honeydew = RGB(240, 255, 240);
        static const RGB HotPink = RGB(255, 105, 180);
        static const RGB IndianRed = RGB(205, 92, 92);
        static const RGB Indigo = RGB(75, 0, 130);
        static const RGB Ivory = RGB(255, 240, 240);
        static const RGB Khaki = RGB(240, 230, 140);
        static const RGB Lavender = RGB(230, 230, 250);
        static const RGB LavenderBlush = RGB(255, 240, 245);
        static const RGB LawnGreen = RGB(124, 252, 0);
        static const RGB LemonChiffon = RGB(255, 250, 205);
        static const RGB LightBlue = RGB(173, 216, 230);
        static const RGB LightCoral = RGB(240, 128, 128);
        static const RGB LightCyan = RGB(224, 255, 255);
        static const RGB LightGoldenrodYellow = RGB(250, 250, 210);
        static const RGB LightGray = RGB(211, 211, 211);
        static const RGB LightGreen = RGB(144, 238, 144);
        static const RGB LightPink = RGB(255, 182, 193);
        static const RGB LightSalmon = RGB(255, 160, 122);
        static const RGB LightSeaGreen = RGB(32, 178, 170);
        static const RGB LightSkyBlue = RGB(135, 206, 250);
        static const RGB LightSlateGray = RGB(119, 136, 153);
        static const RGB LightSteelBlue = RGB(176, 196, 222);
        static const RGB LightYellow = RGB(255, 255, 224);
        static const RGB Lime = RGB(0, 255, 0);
        static const RGB LimeGreen = RGB(50, 205, 50);
        static const RGB Linen = RGB(250, 240, 230);
        static const RGB Magenta = RGB(255, 0, 255);
        static const RGB Maroon = RGB(128, 0, 0);
        static const RGB MediumAquamarine = RGB(102, 205, 170);
        static const RGB MediumBlue = RGB(0, 0, 205);
        static const RGB MediumOrchid = RGB(186, 85, 211);
        static const RGB MediumPurple = RGB(147, 112, 219);
        static const RGB MediumSeaGreen = RGB(60, 179, 113);
        static const RGB MediumSlateBlue = RGB(123, 104, 238);
        static const RGB MediumSpringGreen = RGB(0, 250, 154);
        static const RGB MediumTurquoise = RGB(72, 209, 204);
        static const RGB MediumVioletRed = RGB(199, 21, 112);
        static const RGB MidnightBlue = RGB(25, 25, 112);
        static const RGB MintCream = RGB(245, 255, 250);
        static const RGB MistyRose = RGB(255, 228, 225);
        static const RGB Moccasin = RGB(255, 228, 181);
        static const RGB NavajoWhite = RGB(255, 222, 173);
        static const RGB Navy = RGB(0, 0, 128);
        static const RGB OldLace = RGB(253, 245, 230);
        static const RGB Olive = RGB(128, 128, 0);
        static const RGB OliveDrab = RGB(107, 142, 45);
        static const RGB Orange = RGB(255, 165, 0);
        static const RGB OrangeRed = RGB(255, 69, 0);
        static const RGB Orchid = RGB(218, 112, 214);
        static const RGB PaleGoldenrod = RGB(238, 232, 170);
        static const RGB PaleGreen = RGB(152, 251, 152);
        static const RGB PaleTurquoise = RGB(175, 238, 238);
        static const RGB PaleVioletRed = RGB(219, 112, 147);
        static const RGB PapayaWhip = RGB(255, 239, 213);
        static const RGB PeachPuff = RGB(255, 218, 155);
        static const RGB Peru = RGB(205, 133, 63);
        static const RGB Pink = RGB(255, 192, 203);
        static const RGB Plum = RGB(221, 160, 221);
        static const RGB PowderBlue = RGB(176, 224, 230);
        static const RGB Purple = RGB(128, 0, 128);
        static const RGB Red = RGB(255, 0, 0);
        static const RGB RosyBrown = RGB(188, 143, 143);
        static const RGB RoyalBlue = RGB(65, 105, 225);
        static const RGB SaddleBrown = RGB(139, 69, 19);
        static const RGB Salmon = RGB(250, 128, 114);
        static const RGB SandyBrown = RGB(244, 164, 96);
        static const RGB SeaGreen = RGB(46, 139, 87);
        static const RGB Seashell = RGB(255, 245, 238);
        static const RGB Sienna = RGB(160, 82, 45);
        static const RGB Silver = RGB(192, 192, 192);
        static const RGB SkyBlue = RGB(135, 206, 235);
        static const RGB SlateBlue = RGB(106, 90, 205);
        static const RGB SlateGray = RGB(112, 128, 144);
        static const RGB Snow = RGB(255, 250, 250);
        static const RGB SpringGreen = RGB(0, 255, 127);
        static const RGB SteelBlue = RGB(70, 130, 180);
        static const RGB Tan = RGB(210, 180, 140);
        static const RGB Teal = RGB(0, 128, 128);
        static const RGB Thistle = RGB(216, 191, 216);
        static const RGB Tomato = RGB(253, 99, 71);
        static const RGB Turquoise = RGB(64, 224, 208);
        static const RGB Violet = RGB(238, 130, 238);
        static const RGB Wheat = RGB(245, 222, 179);
        static const RGB White = RGB(255, 255, 255);
        static const RGB WhiteSmoke = RGB(245, 245, 245);
        static const RGB Yellow = RGB(255, 255, 0);
        static const RGB YellowGreen = RGB(154, 205, 50);
    }

    // Led utils

    static void __attribute__((unused)) calcGammaCorrection()
    {
        std::cout << "static const std::vector<uint8_t> gammaCorrection = {";
        for (int i = 0; i < 0x100; i++)
        {
            if (!(i%16)) std::cout << "\n\t";
            int value = std::pow(i/255.0, 2.5) * 255;
            std::cout << std::setw(3) << value << ", ";
        }
        std::cout << "\n};" << std::endl;
    }

    static const std::vector<uint8_t> gammaCorrection = {
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1, 
        1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3, 
        3,   4,   4,   4,   4,   5,   5,   5,   5,   6,   6,   6,   6,   7,   7,   7, 
        8,   8,   8,   9,   9,   9,  10,  10,  10,  11,  11,  11,  12,  12,  13,  13, 
        14,  14,  14,  15,  15,  16,  16,  17,  17,  18,  18,  19,  19,  20,  21,  21, 
        22,  22,  23,  23,  24,  25,  25,  26,  27,  27,  28,  29,  29,  30,  31,  31, 
        32,  33,  34,  34,  35,  36,  37,  37,  38,  39,  40,  41,  42,  42,  43,  44, 
        45,  46,  47,  48,  49,  50,  51,  52,  52,  53,  54,  55,  56,  57,  59,  60, 
        61,  62,  63,  64,  65,  66,  67,  68,  69,  71,  72,  73,  74,  75,  77,  78, 
        79,  80,  82,  83,  84,  85,  87,  88,  89,  91,  92,  93,  95,  96,  98,  99, 
        100, 102, 103, 105, 106, 108, 109, 111, 112, 114, 115, 117, 119, 120, 122, 123, 
        125, 127, 128, 130, 132, 133, 135, 137, 138, 140, 142, 144, 145, 147, 149, 151, 
        153, 155, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 
        184, 186, 188, 190, 192, 194, 197, 199, 201, 203, 205, 207, 210, 212, 214, 216, 
        219, 221, 223, 226, 228, 230, 233, 235, 237, 240, 242, 245, 247, 250, 252, 255, 
    };

    static inline RGB gammaCorrected(RGB color)
    {
        return RGB(gammaCorrection[color.red], gammaCorrection[color.green], gammaCorrection[color.blue]);
    }
}