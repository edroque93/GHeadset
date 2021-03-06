#pragma once

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <array>
#include <unordered_map>

namespace GHeadset::Color
{
    struct RGB
    {
        uint8_t red;
        uint8_t green;
        uint8_t blue;

        constexpr RGB(uint8_t r, uint8_t g, uint8_t b) 
            : red(r), green(g), blue(b) {};
        constexpr RGB(uint32_t rgb)
            : red((rgb >> 16) & 0xff), green((rgb >> 8) & 0xff), blue(rgb & 0xff) {};
    };

    // I just like the selection from dot net :)
    namespace Palette
    {
        constexpr RGB AliceBlue = RGB(240, 248, 255);
        constexpr RGB AntiqueWhite = RGB(250, 235, 215);
        constexpr RGB Aqua = RGB(0, 255, 255);
        constexpr RGB Aquamarine = RGB(127, 255, 212);
        constexpr RGB Azure = RGB(240, 255, 255);
        constexpr RGB Beige = RGB(245, 245, 220);
        constexpr RGB Bisque = RGB(255, 228, 196);
        constexpr RGB Black = RGB(0, 0, 0);
        constexpr RGB BlanchedAlmond = RGB(255, 255, 205);
        constexpr RGB Blue = RGB(0, 0, 255);
        constexpr RGB BlueViolet = RGB(138, 43, 226);
        constexpr RGB Brown = RGB(165, 42, 42);
        constexpr RGB BurlyWood = RGB(222, 184, 135);
        constexpr RGB CadetBlue = RGB(95, 158, 160);
        constexpr RGB Chartreuse = RGB(127, 255, 0);
        constexpr RGB Chocolate = RGB(210, 105, 30);
        constexpr RGB Coral = RGB(255, 127, 80);
        constexpr RGB CornflowerBlue = RGB(100, 149, 237);
        constexpr RGB Cornsilk = RGB(255, 248, 220);
        constexpr RGB Crimson = RGB(220, 20, 60);
        constexpr RGB Cyan = RGB(0, 255, 255);
        constexpr RGB DarkBlue = RGB(0, 0, 139);
        constexpr RGB DarkCyan = RGB(0, 139, 139);
        constexpr RGB DarkGoldenrod = RGB(184, 134, 11);
        constexpr RGB DarkGray = RGB(169, 169, 169);
        constexpr RGB DarkGreen = RGB(0, 100, 0);
        constexpr RGB DarkKhaki = RGB(189, 183, 107);
        constexpr RGB DarkMagena = RGB(139, 0, 139);
        constexpr RGB DarkOliveGreen = RGB(85, 107, 47);
        constexpr RGB DarkOrange = RGB(255, 140, 0);
        constexpr RGB DarkOrchid = RGB(153, 50, 204);
        constexpr RGB DarkRed = RGB(139, 0, 0);
        constexpr RGB DarkSalmon = RGB(233, 150, 122);
        constexpr RGB DarkSeaGreen = RGB(143, 188, 143);
        constexpr RGB DarkSlateBlue = RGB(72, 61, 139);
        constexpr RGB DarkSlateGray = RGB(40, 79, 79);
        constexpr RGB DarkTurquoise = RGB(0, 206, 209);
        constexpr RGB DarkViolet = RGB(148, 0, 211);
        constexpr RGB DeepPink = RGB(255, 20, 147);
        constexpr RGB DeepSkyBlue = RGB(0, 191, 255);
        constexpr RGB DimGray = RGB(105, 105, 105);
        constexpr RGB DodgerBlue = RGB(30, 144, 255);
        constexpr RGB Firebrick = RGB(178, 34, 34);
        constexpr RGB FloralWhite = RGB(255, 250, 240);
        constexpr RGB ForestGreen = RGB(34, 139, 34);
        constexpr RGB Fuschia = RGB(255, 0, 255);
        constexpr RGB Gainsboro = RGB(220, 220, 220);
        constexpr RGB GhostWhite = RGB(248, 248, 255);
        constexpr RGB Gold = RGB(255, 215, 0);
        constexpr RGB Goldenrod = RGB(218, 165, 32);
        constexpr RGB Gray = RGB(128, 128, 128);
        constexpr RGB Green = RGB(0, 128, 0);
        constexpr RGB GreenYellow = RGB(173, 255, 47);
        constexpr RGB Honeydew = RGB(240, 255, 240);
        constexpr RGB HotPink = RGB(255, 105, 180);
        constexpr RGB IndianRed = RGB(205, 92, 92);
        constexpr RGB Indigo = RGB(75, 0, 130);
        constexpr RGB Ivory = RGB(255, 240, 240);
        constexpr RGB Khaki = RGB(240, 230, 140);
        constexpr RGB Lavender = RGB(230, 230, 250);
        constexpr RGB LavenderBlush = RGB(255, 240, 245);
        constexpr RGB LawnGreen = RGB(124, 252, 0);
        constexpr RGB LemonChiffon = RGB(255, 250, 205);
        constexpr RGB LightBlue = RGB(173, 216, 230);
        constexpr RGB LightCoral = RGB(240, 128, 128);
        constexpr RGB LightCyan = RGB(224, 255, 255);
        constexpr RGB LightGoldenrodYellow = RGB(250, 250, 210);
        constexpr RGB LightGray = RGB(211, 211, 211);
        constexpr RGB LightGreen = RGB(144, 238, 144);
        constexpr RGB LightPink = RGB(255, 182, 193);
        constexpr RGB LightSalmon = RGB(255, 160, 122);
        constexpr RGB LightSeaGreen = RGB(32, 178, 170);
        constexpr RGB LightSkyBlue = RGB(135, 206, 250);
        constexpr RGB LightSlateGray = RGB(119, 136, 153);
        constexpr RGB LightSteelBlue = RGB(176, 196, 222);
        constexpr RGB LightYellow = RGB(255, 255, 224);
        constexpr RGB Lime = RGB(0, 255, 0);
        constexpr RGB LimeGreen = RGB(50, 205, 50);
        constexpr RGB Linen = RGB(250, 240, 230);
        constexpr RGB Magenta = RGB(255, 0, 255);
        constexpr RGB Maroon = RGB(128, 0, 0);
        constexpr RGB MediumAquamarine = RGB(102, 205, 170);
        constexpr RGB MediumBlue = RGB(0, 0, 205);
        constexpr RGB MediumOrchid = RGB(186, 85, 211);
        constexpr RGB MediumPurple = RGB(147, 112, 219);
        constexpr RGB MediumSeaGreen = RGB(60, 179, 113);
        constexpr RGB MediumSlateBlue = RGB(123, 104, 238);
        constexpr RGB MediumSpringGreen = RGB(0, 250, 154);
        constexpr RGB MediumTurquoise = RGB(72, 209, 204);
        constexpr RGB MediumVioletRed = RGB(199, 21, 112);
        constexpr RGB MidnightBlue = RGB(25, 25, 112);
        constexpr RGB MintCream = RGB(245, 255, 250);
        constexpr RGB MistyRose = RGB(255, 228, 225);
        constexpr RGB Moccasin = RGB(255, 228, 181);
        constexpr RGB NavajoWhite = RGB(255, 222, 173);
        constexpr RGB Navy = RGB(0, 0, 128);
        constexpr RGB OldLace = RGB(253, 245, 230);
        constexpr RGB Olive = RGB(128, 128, 0);
        constexpr RGB OliveDrab = RGB(107, 142, 45);
        constexpr RGB Orange = RGB(255, 165, 0);
        constexpr RGB OrangeRed = RGB(255, 69, 0);
        constexpr RGB Orchid = RGB(218, 112, 214);
        constexpr RGB PaleGoldenrod = RGB(238, 232, 170);
        constexpr RGB PaleGreen = RGB(152, 251, 152);
        constexpr RGB PaleTurquoise = RGB(175, 238, 238);
        constexpr RGB PaleVioletRed = RGB(219, 112, 147);
        constexpr RGB PapayaWhip = RGB(255, 239, 213);
        constexpr RGB PeachPuff = RGB(255, 218, 155);
        constexpr RGB Peru = RGB(205, 133, 63);
        constexpr RGB Pink = RGB(255, 192, 203);
        constexpr RGB Plum = RGB(221, 160, 221);
        constexpr RGB PowderBlue = RGB(176, 224, 230);
        constexpr RGB Purple = RGB(128, 0, 128);
        constexpr RGB Red = RGB(255, 0, 0);
        constexpr RGB RosyBrown = RGB(188, 143, 143);
        constexpr RGB RoyalBlue = RGB(65, 105, 225);
        constexpr RGB SaddleBrown = RGB(139, 69, 19);
        constexpr RGB Salmon = RGB(250, 128, 114);
        constexpr RGB SandyBrown = RGB(244, 164, 96);
        constexpr RGB SeaGreen = RGB(46, 139, 87);
        constexpr RGB Seashell = RGB(255, 245, 238);
        constexpr RGB Sienna = RGB(160, 82, 45);
        constexpr RGB Silver = RGB(192, 192, 192);
        constexpr RGB SkyBlue = RGB(135, 206, 235);
        constexpr RGB SlateBlue = RGB(106, 90, 205);
        constexpr RGB SlateGray = RGB(112, 128, 144);
        constexpr RGB Snow = RGB(255, 250, 250);
        constexpr RGB SpringGreen = RGB(0, 255, 127);
        constexpr RGB SteelBlue = RGB(70, 130, 180);
        constexpr RGB Tan = RGB(210, 180, 140);
        constexpr RGB Teal = RGB(0, 128, 128);
        constexpr RGB Thistle = RGB(216, 191, 216);
        constexpr RGB Tomato = RGB(253, 99, 71);
        constexpr RGB Turquoise = RGB(64, 224, 208);
        constexpr RGB Violet = RGB(238, 130, 238);
        constexpr RGB Wheat = RGB(245, 222, 179);
        constexpr RGB White = RGB(255, 255, 255);
        constexpr RGB WhiteSmoke = RGB(245, 245, 245);
        constexpr RGB Yellow = RGB(255, 255, 0);
        constexpr RGB YellowGreen = RGB(154, 205, 50);
    }

    // Led utils

    static void __attribute__((unused)) calcGammaCorrection()
    {
        std::cout << "constexpr std::array<uint8_t, 256> gammaCorrection = {";
        for (int i = 0; i < 0x100; i++)
        {
            if (!(i%16)) std::cout << "\n\t";
            int value = std::pow(i/255.0, 2.5) * 255;
            std::cout << std::setw(3) << value << ", ";
        }
        std::cout << "\n};" << std::endl;
    }

    constexpr std::array<uint8_t, 256> gammaCorrection = {
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

    constexpr inline RGB gammaCorrected(RGB color)
    {
        return RGB(gammaCorrection[color.red], gammaCorrection[color.green], gammaCorrection[color.blue]);
    }
}