#!/bin/bash#!/bin/bash



# Iron Chess Build Scriptecho "� Building Iron Chess..."

echo "🏰 Building Iron Chess..."

# Set up environment

# Create build directoryexport PATH="$HOME/.dotnet:$PATH"

mkdir -p buildcd /Users/samuelabdelsayed/Documents/Repositories/iron-chess

cd build

echo "📦 Using UnrealBuildTool to compile..."

# Configure with CMake"/Users/Shared/Epic Games/UE_5.6/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool" -Mode=Build IronChess Development Mac -Project="$(pwd)/IronChess.uproject" -Verbose

echo "📦 Configuring build system..."

cmake ..BUILD_RESULT=$?



# Build the projectif [ $BUILD_RESULT -eq 0 ]; then

echo "🔨 Compiling..."    echo "🎉 Iron Chess built successfully!"

make -j$(sysctl -n hw.ncpu)    echo "🎮 Ready to launch: open IronChess.uproject"

else

if [ $? -eq 0 ]; then    echo "❌ Build failed with exit code: $BUILD_RESULT"

    echo "✅ Iron Chess built successfully!"    echo "💡 Check the build log above for details"

    echo "🎮 Run with: ./build/bin/IronChess"fi

else

    echo "❌ Build failed!"exit $BUILD_RESULT
    exit 1
fi