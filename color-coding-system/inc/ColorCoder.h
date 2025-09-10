#pragma once
#include "ColorPair.h"
#include "ColorDefinitions.h"

namespace TelCoColorCoder
{
    class ColorCoder
    {
    public:
        static ColorPair getColorFromPairNumber(int pairNumber);
        static int getPairNumberFromColor(MajorColor major, MinorColor minor);
        static bool isValidPairNumber(int pairNumber);
    };
}
