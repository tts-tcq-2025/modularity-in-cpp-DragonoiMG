# Telecommunication Color Coder

A modular C++ implementation for the 25-pair color coding system used in telecommunications cables.

## Features

- **Color Pair Management**: Convert between pair numbers and color combinations
- **Reference Manual**: Generate printable reference manual for wiring personnel
- **Input Validation**: Robust error handling for invalid inputs
- **Modular Design**: Clean separation of concerns across multiple files

## Project Structure

```
color-coding-system/
├── inc/                    # Header files
│   ├── ColorDefinitions.h  # Color enums and constants
│   ├── ColorPair.h         # ColorPair class
│   ├── ColorCoder.h        # Color conversion utilities
│   └── ReferenceManual.h   # Reference manual generator
├── src/                    # Source files
│   ├── ColorDefinitions.cpp
│   ├── ColorPair.cpp
│   ├── ColorCoder.cpp
│   ├── ReferenceManual.cpp
│   └── main.cpp            # Demo application
├── tests/                  # Test files
│   ├── ColorPairTests.cpp
│   ├── ReferenceManualTests.cpp
│   └── TestRunner.cpp
├── Makefile               # Build configuration
├── CMakeLists.txt         # CMake configuration
└── README.md              # This file
```

## Building

### Using Make (Linux/Mac/MinGW on Windows)
```bash
make all        # Build main application
make test       # Build and run tests
make run        # Build and run main application
make clean      # Clean build artifacts
```

### Using CMake (Cross-platform)
```bash
mkdir build
cd build
cmake ..
make
```

## Usage

### Basic Operations
```cpp
#include "ColorCoder.h"

// Convert pair number to colors
ColorPair pair = ColorCoder::getColorFromPairNumber(4);
std::cout << pair.toString() << std::endl;  // "White Brown"

// Convert colors to pair number
int pairNum = ColorCoder::getPairNumberFromColor(BLACK, ORANGE);
std::cout << pairNum << std::endl;  // 12
```

### Generate Reference Manual
```cpp
#include "ReferenceManual.h"

// Print complete reference manual
ReferenceManual::printColorCodingReference();

// Get manual as string for custom formatting
std::string manual = ReferenceManual::generateColorCodingReference();
```

## Color Coding System

The system supports 25 color pairs using:
- **Major Colors**: White, Red, Black, Yellow, Violet
- **Minor Colors**: Blue, Orange, Green, Brown, Slate

Each combination maps to a unique pair number (1-25).

## Clean Code Principles Applied

1. **Single Responsibility**: Each class has one clear purpose
2. **Separation of Concerns**: Logic separated from presentation
3. **Descriptive Naming**: Clear, intention-revealing names
4. **Error Handling**: Proper exception handling with validation
5. **Modularity**: Easy to extend and maintain
6. **Testing**: Comprehensive test coverage

## Running Tests

Tests verify:
- Color pair creation and conversion
- Number-to-color and color-to-number mappings
- Reference manual generation
- Input validation and error handling

```bash
make test
# or
./bin/test_runner
```
