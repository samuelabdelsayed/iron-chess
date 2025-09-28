using UnrealBuildTool;

public class IronChess : ModuleRules
{
    public IronChess(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay",
            "UMG",
            "Slate",
            "SlateCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Niagara",
            "NiagaraCore",
            "LevelSequence",
            "MovieScene",
            "MovieSceneTracks",
            "CinematicCamera",
            "AIModule",
            "GameplayTasks",
            "NavigationSystem",
            "AudioMixer",
            "AudioPlatformConfiguration"
        });

        // For Stockfish integration - platform-specific libraries would be added here
        // PublicAdditionalLibraries.Add("$(EngineDir)/Binaries/ThirdParty/Stockfish/Win64/stockfish.lib");
        
        PublicIncludePaths.AddRange(new string[] {
            "IronChess/Core",
            "IronChess/AI",
            "IronChess/Animation",
            "IronChess/Cinematic"
        });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}