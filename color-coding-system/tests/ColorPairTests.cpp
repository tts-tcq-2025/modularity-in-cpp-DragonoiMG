#include "../inc/ColorPair.h"
#include "../inc/ColorCoder.h"
#include <iostream>
#include <cassert>

namespace TelCoColorCoder 
{
    void testColorPairCreation() 
    {
        ColorPair colorPair(WHITE, BROWN);
        assert(colorPair.getMajor() == WHITE);
        assert(colorPair.getMinor() == BROWN);
        std::cout << "ColorPair creation test passed" << std::endl;
    }
    
    void testColorPairToString() 
    {
        ColorPair colorPair(RED, BLUE);
        std::string expected = "Red Blue";
        assert(colorPair.toString() == expected);
        std::cout << "ColorPair toString test passed" << std::endl;
    }
    
    void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) 
    {
        ColorPair colorPair = ColorCoder::getColorFromPairNumber(pairNumber);
        std::cout << "Got pair " << colorPair.toString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
        std::cout << "Number to pair test passed for pair " << pairNumber << std::endl;
    }
    
    void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) 
    {
        int pairNumber = ColorCoder::getPairNumberFromColor(major, minor);
        std::cout << "Got pair number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
        std::cout << "Pair to number test passed for colors " 
                  << MajorColorNames[major] << " " << MinorColorNames[minor] << std::endl;
    }
    
    void runColorPairTests() 
    {
        std::cout << "Running ColorPair tests..." << std::endl;
        testColorPairCreation();
        testColorPairToString();
        
        testNumberToPair(4, WHITE, BROWN);
        testNumberToPair(5, WHITE, SLATE);
        
        testPairToNumber(BLACK, ORANGE, 12);
        testPairToNumber(VIOLET, SLATE, 25);
        
        std::cout << "All ColorPair tests passed!" << std::endl;
    }
}
