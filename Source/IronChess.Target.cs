using UnrealBuildTool;
using System.Collections.Generic;

public class IronChessTarget : TargetRules
{
    public IronChessTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        
        ExtraModuleNames.AddRange(new string[] { "IronChess" });
    }
}