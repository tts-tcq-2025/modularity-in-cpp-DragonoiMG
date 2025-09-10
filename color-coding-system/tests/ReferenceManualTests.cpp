#include "../inc/ReferenceManual.h"
#include <iostream>
#include <cassert>

namespace TelCoColorCoder 
{
    void testReferenceManualGeneration() 
    {
        std::string manual = ReferenceManual::generateColorCodingReference();
        
        // Check that manual contains expected content
        assert(manual.find("Telecommunication Color Coding Reference Manual") != std::string::npos);
        assert(manual.find("Pair#") != std::string::npos);
        assert(manual.find("Major Color") != std::string::npos);
        assert(manual.find("Minor Color") != std::string::npos);
        assert(manual.find("Total pairs: 25") != std::string::npos);
        
        std::cout << "✓ Reference manual generation test passed" << std::endl;
    }
    
    void testFormatColorPairEntry() 
    {
        std::string entry = ReferenceManual::formatColorPairEntry(1, "White", "Blue");
        assert(entry.find("1") != std::string::npos);
        assert(entry.find("White") != std::string::npos);
        assert(entry.find("Blue") != std::string::npos);
        
        std::cout << "✓ Format color pair entry test passed" << std::endl;
    }
    
    void testPrintReferenceManual() 
    {
        std::cout << "Testing reference manual printing:" << std::endl;
        ReferenceManual::printColorCodingReference();
        std::cout << "Reference manual printing test completed" << std::endl;
    }
    
    void runReferenceManualTests() 
    {
        std::cout << "Running ReferenceManual tests..." << std::endl;
        testReferenceManualGeneration();
        testFormatColorPairEntry();
        testPrintReferenceManual();
        std::cout << "All ReferenceManual tests passed!" << std::endl;
    }
}
