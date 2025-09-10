#include "ColorCoder.h"
#include "ReferenceManual.h"
#include <iostream>

using namespace TelCoColorCoder;

int main() 
{
    std::cout << "=== Telecommunication Color Coder Demo ===" << std::endl;
    
    try 
    {
        // Test basic functionality
        std::cout << "\n--- Basic Color Coding Tests ---" << std::endl;
        
        // Test number to color conversion
        ColorPair pair4 = ColorCoder::getColorFromPairNumber(4);
        std::cout << "Pair 4: " << pair4.toString() << std::endl;
        
        ColorPair pair5 = ColorCoder::getColorFromPairNumber(5);
        std::cout << "Pair 5: " << pair5.toString() << std::endl;
        
        // Test color to number conversion
        int pairNum12 = ColorCoder::getPairNumberFromColor(BLACK, ORANGE);
        std::cout << "Black Orange = Pair " << pairNum12 << std::endl;
        
        int pairNum25 = ColorCoder::getPairNumberFromColor(VIOLET, SLATE);
        std::cout << "Violet Slate = Pair " << pairNum25 << std::endl;
        
        // NEW FEATURE: Print reference manual
        std::cout << "\n--- Reference Manual ---" << std::endl;
        ReferenceManual::printColorCodingReference();
        
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
