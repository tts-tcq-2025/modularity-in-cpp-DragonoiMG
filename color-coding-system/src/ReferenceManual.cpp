#include "../inc/ReferenceManual.h"
#include "../inc/ColorCoder.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace TelCoColorCoder
{
    std::string ReferenceManual::generateColorCodingReference() 
    {
        std::stringstream manual;
        manual << "=== Telecommunication Color Coding Reference Manual ===\n";
        manual << "25-Pair Color Code for Wire Identification\n";
        manual << "========================================================\n\n";
        manual << std::left << std::setw(6) << "Pair#" 
               << std::setw(12) << "Major Color" 
               << std::setw(12) << "Minor Color" << "\n";
        manual << "------  -----------  -----------\n";
        
        for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber) 
        {
            try 
            {
                ColorPair colorPair = ColorCoder::getColorFromPairNumber(pairNumber);
                std::string majorColorName = MajorColorNames[colorPair.getMajor()];
                std::string minorColorName = MinorColorNames[colorPair.getMinor()];
                
                manual << formatColorPairEntry(pairNumber, majorColorName, minorColorName);
            }
            catch (const std::exception& e) 
            {
                manual << "Error processing pair " << pairNumber << ": " << e.what() << "\n";
            }
        }
        
        manual << "\n========================================================\n";
        manual << "Total pairs: " << numberOfMajorColors * numberOfMinorColors << "\n";
        
        return manual.str();
    }
    
    std::string ReferenceManual::formatColorPairEntry(int pairNumber, 
                                                     const std::string& majorColor, 
                                                     const std::string& minorColor) 
    {
        std::stringstream entry;
        entry << std::left << std::setw(6) << pairNumber 
              << std::setw(12) << majorColor 
              << std::setw(12) << minorColor << "\n";
        return entry.str();
    }
    
    void ReferenceManual::printColorCodingReference() 
    {
        std::cout << generateColorCodingReference() << std::endl;
    }
}
