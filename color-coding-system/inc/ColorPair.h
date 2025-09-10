#pragma once
#include <string>
#include "ColorDefinitions.h"

namespace TelCoColorCoder
{
    class ColorPair 
    {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
        
    public:
        ColorPair(MajorColor major, MinorColor minor);
        
        MajorColor getMajor() const;
        MinorColor getMinor() const;
        std::string toString() const;
    };
}
