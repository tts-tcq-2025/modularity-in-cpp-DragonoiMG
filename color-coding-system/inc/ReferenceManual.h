#pragma once
#include <string>
#include "ColorDefinitions.h"

namespace TelCoColorCoder
{
    class ReferenceManual
    {
    public:
        static std::string generateColorCodingReference();
        static std::string formatColorPairEntry(int pairNumber, 
                                               const std::string& majorColor, 
                                               const std::string& minorColor);
        static void printColorCodingReference();
    };
}
