#include "IronChess.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * Iron Chess Game Module
 * Main module implementation for the Iron Chess medieval chess game
 */
class FIronChessModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		UE_LOG(LogTemp, Log, TEXT("Iron Chess module started - Ready to conquer the medieval battlefield!"));
	}

	virtual void ShutdownModule() override
	{
		UE_LOG(LogTemp, Log, TEXT("Iron Chess module shutdown"));
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FIronChessModule, IronChess, "IronChess");