#include <iostream>

namespace TelCoColorCoder 
{
    void runColorPairTests();
    void runReferenceManualTests();
}

int main() 
{
    std::cout << "=== Running Telecommunication Color Coder Tests ===" << std::endl;
    
    try 
    {
        TelCoColorCoder::runColorPairTests();
        std::cout << std::endl;
        TelCoColorCoder::runReferenceManualTests();
        
        std::cout << std::endl << "=== All tests completed successfully! ===" << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
