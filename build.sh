#!/bin/bash

echo "� Building Iron Chess..."

# Set up environment
export PATH="$HOME/.dotnet:$PATH"
cd /Users/samuelabdelsayed/Documents/Repositories/iron-chess

echo "📦 Using UnrealBuildTool to compile..."
"/Users/Shared/Epic Games/UE_5.6/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool" -Mode=Build IronChess Development Mac -Project="$(pwd)/IronChess.uproject" -Verbose

BUILD_RESULT=$?

if [ $BUILD_RESULT -eq 0 ]; then
    echo "🎉 Iron Chess built successfully!"
    echo "🎮 Ready to launch: open IronChess.uproject"
else
    echo "❌ Build failed with exit code: $BUILD_RESULT"
    echo "💡 Check the build log above for details"
fi

exit $BUILD_RESULT