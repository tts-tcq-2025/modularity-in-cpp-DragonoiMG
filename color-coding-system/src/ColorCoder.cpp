#include "../inc/ColorCoder.h"
#include <stdexcept>

namespace TelCoColorCoder
{
    ColorPair ColorCoder::getColorFromPairNumber(int pairNumber) 
    {
        if (!isValidPairNumber(pairNumber)) 
        {
            throw std::invalid_argument("Invalid pair number: " + std::to_string(pairNumber));
        }
        
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    
    int ColorCoder::getPairNumberFromColor(MajorColor major, MinorColor minor) 
    {
        return major * numberOfMinorColors + minor + 1;
    }
    
    bool ColorCoder::isValidPairNumber(int pairNumber) 
    {
        return pairNumber >= 1 && pairNumber <= (numberOfMajorColors * numberOfMinorColors);
    }
}
