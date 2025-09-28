# Iron Chess - Asset Pipeline & Requirements
## Comprehensive 3D Asset Production Guide

### Table of Contents
1. [Asset Categories & Specifications](#asset-categories)
2. [3D Model Requirements](#3d-models)
3. [Texture & Material Pipeline](#textures-materials)
4. [Animation Requirements](#animations)
5. [Audio Asset Specifications](#audio)
6. [Asset Naming Conventions](#naming-conventions)
7. [Import Pipeline](#import-pipeline)
8. [Optimization Guidelines](#optimization)
9. [Quality Assurance](#quality-assurance)

---

## Asset Categories & Specifications

### 1. Chess Pieces (Medieval Theme)

#### Pawn - Medieval Foot Soldier
- **Concept**: Armored infantryman with sword and shield
- **Polygon Budget**: 5,000 triangles (LOD0), 2,500 (LOD1), 1,200 (LOD2)
- **Texture Resolution**: 2048x2048 (Albedo, Normal, Roughness, Metallic)
- **Animation Sockets**: Weapon_R, Shield_L, Head
- **Variations**: 2 per color (Male/Female soldiers)

#### Rook - Mobile Siege Tower
- **Concept**: Medieval siege tower with wheels and battlements
- **Polygon Budget**: 8,000 triangles (LOD0), 4,000 (LOD1), 2,000 (LOD2)
- **Texture Resolution**: 4096x4096 (due to architectural details)
- **Animation Sockets**: Door_Main, Ladder_Side, Flag_Top
- **Special Features**: Destructible elements, particle spawn points
- **Variations**: Castle design differences per color

#### Knight - Armored Cavalry
- **Concept**: Medieval knight on war horse
- **Polygon Budget**: 12,000 triangles total (6,000 rider + 6,000 horse)
- **Texture Resolution**: 4096x4096 (shared atlas for rider and horse)
- **Animation Sockets**: Weapon_R, Shield_L, Reins, Banner_Back
- **Rigging**: Full skeletal rig for both rider and horse
- **Variations**: Different armor styles and horse breeds

#### Bishop - Robed Cleric
- **Concept**: Medieval bishop with ornate robes and staff
- **Polygon Budget**: 7,000 triangles (LOD0), 3,500 (LOD1), 1,800 (LOD2)
- **Texture Resolution**: 2048x2048 with additional 1024x1024 for accessories
- **Animation Sockets**: Staff_R, Book_L, Medallion_Chest
- **Special Features**: Cloth simulation for robes, particle effects for magic
- **Variations**: Different religious order styles

#### Queen - Royal Majesty
- **Concept**: Regal female figure with crown and scepter
- **Polygon Budget**: 10,000 triangles (LOD0), 5,000 (LOD1), 2,500 (LOD2)
- **Texture Resolution**: 4096x4096 (high detail for royal appearance)
- **Animation Sockets**: Scepter_R, Crown, Cape_Back, Jewelry_Multiple
- **Special Features**: Dynamic crown gems, flowing cape, particle aura
- **Variations**: Distinct royal styles for White/Black

#### King - Sovereign Ruler
- **Concept**: Majestic king with ornate armor and royal regalia
- **Polygon Budget**: 15,000 triangles (LOD0), 7,500 (LOD1), 3,750 (LOD2)
- **Texture Resolution**: 4096x4096 + 2048x2048 for accessories
- **Animation Sockets**: Sword_R, Crown, Cape_Back, Armor_Multiple
- **Special Features**: Most detailed model, particle effects, dynamic materials
- **Variations**: Completely unique designs for each color

### 2. Environment Assets

#### Chessboard - Floating Arena
- **Concept**: Ancient stone platform floating in misty void
- **Polygon Budget**: 20,000 triangles with detailed carvings
- **Texture Resolution**: 8192x8192 tiling texture set
- **Special Features**: 
  - Intricate runic carvings around edges
  - Dynamic lighting integration points
  - Particle spawn locations for atmosphere
  - 64 precisely positioned square markers
- **Materials**: Stone base, metal inlays, magical runes

#### Environment - Medieval Castle Courtyard
- **Concept**: Atmospheric backdrop with castle walls, towers, and sky
- **Components**:
  - **Castle Walls**: 15,000 triangles, 4096x4096 textures
  - **Towers**: 8,000 triangles each, 2048x2048 textures
  - **Sky Dome**: 2,000 triangles, 8192x4096 panoramic texture
  - **Atmospheric Elements**: Fog volumes, particle systems

#### Props & Decorative Elements
- **Torches**: 500 triangles, 1024x1024 textures, flame particle systems
- **Banners**: 800 triangles, 1024x2048 textures, cloth simulation
- **Weapon Racks**: 2,000 triangles, 2048x2048 textures
- **Architectural Details**: Various small props, budget per item: 500-1,500 triangles

---

## 3D Model Requirements

### Technical Specifications

#### Polygon Budgets by Category
```
Chess Pieces:
├── Pawn: 5,000 tris (LOD0)
├── Rook: 8,000 tris (LOD0)  
├── Knight: 12,000 tris (LOD0)
├── Bishop: 7,000 tris (LOD0)
├── Queen: 10,000 tris (LOD0)
└── King: 15,000 tris (LOD0)

Environment:
├── Chessboard: 20,000 tris
├── Castle Walls: 15,000 tris
├── Towers: 8,000 tris each
└── Props: 500-2,000 tris each
```

#### Level of Detail (LOD) Requirements
- **LOD0**: Full detail (100% polygons)
- **LOD1**: Medium detail (50% polygons)  
- **LOD2**: Low detail (25% polygons)
- **LOD3**: Impostor (Billboard/Card)

#### UV Mapping Standards
- **Non-overlapping UVs** for unique textures
- **Consistent Texel Density**: 512 pixels per meter minimum
- **UV Seams** placed strategically to minimize visibility
- **UV Islands** optimally packed with 4-pixel padding

#### Pivot Points & Orientation
- **Chess Pieces**: Pivot at base center, facing +X direction
- **Props**: Pivot at logical interaction point
- **Architecture**: Pivot at base center or logical construction point

---

## Textures & Material Pipeline

### Texture Specifications

#### Albedo (Base Color)
- **Format**: BC7 (sRGB) for detailed textures, BC1 for simple textures
- **Bit Depth**: 8-bit per channel
- **Color Space**: sRGB
- **Content**: Diffuse color information only, no lighting or shadows

#### Normal Maps
- **Format**: BC5 (Linear) for best quality
- **Encoding**: OpenGL format (Y+ up)
- **Bit Depth**: 8-bit per channel (RG only)
- **Content**: Surface detail normals, consistent scale across assets

#### Roughness Maps
- **Format**: BC4 (Linear) single channel
- **Bit Depth**: 8-bit
- **Range**: 0.0 (mirror) to 1.0 (completely rough)
- **Content**: Surface roughness variation

#### Metallic Maps
- **Format**: BC4 (Linear) single channel  
- **Bit Depth**: 8-bit
- **Values**: Binary (0.0 = dielectric, 1.0 = metallic)
- **Content**: Material type definition

#### Packed Utility Textures
- **ORM Maps**: Occlusion (R), Roughness (G), Metallic (B)
- **Format**: BC7 (Linear)
- **Purpose**: Optimize memory usage for material properties

### Material Categories

#### Stone Materials
- **Castle Stone**: Weathered limestone with moss growth
- **Chessboard Stone**: Polished marble with runic inlays
- **Cobblestone**: Rough-hewn path stones

#### Metal Materials
- **Armor Steel**: Polished plate armor with wear
- **Weapon Steel**: Sharp blade metal with edge wear
- **Decorative Bronze**: Ornate fittings and decorations
- **Iron Fittings**: Rough iron for utilitarian elements

#### Fabric Materials
- **Royal Silk**: Luxurious cloth for queen/king garments
- **Rough Canvas**: Soldier clothing and basic textiles
- **Leather**: Armor components and accessories
- **Banner Cloth**: Flag and banner materials

#### Special Materials
- **Glowing Runes**: Emissive magical inscriptions
- **Particle Materials**: For VFX and atmospheric effects
- **Glass**: Windows, crystal balls, magical elements
- **Organic**: Wood, rope, organic decorative elements

---

## Animation Requirements

### Chess Piece Animations

#### Standard Movement Animations
- **Idle**: Subtle breathing/swaying (2-4 second loop)
- **Walk**: 8-frame walk cycle for piece movement
- **Attack**: Combat animation for captures (1-2 seconds)
- **Death**: Defeat animation when captured (2-3 seconds)
- **Victory**: Celebration animation for game end (3-5 seconds)

#### Special Animations by Piece Type

##### Pawn Animations
- **March**: Military walking animation
- **Shield Bash**: Attack animation
- **Fallen Soldier**: Death animation
- **Promotion**: Transformation sequence to other pieces

##### Knight Animations  
- **Horse Trot**: Standard movement
- **Cavalry Charge**: Attack animation with lance
- **Rear and Strike**: Dramatic combat sequence
- **Dismount**: Death animation

##### Rook Animations
- **Tower Roll**: Movement on wheels/tracks  
- **Siege Strike**: Ballista/catapult attack
- **Collapse**: Destruction sequence
- **Fortify**: Defensive stance

##### Bishop Animations
- **Glide**: Mystical floating movement
- **Staff Strike**: Magical attack with staff
- **Blessing**: Area effect animation
- **Ascension**: Ethereal death sequence

##### Queen Animations
- **Regal Walk**: Majestic movement
- **Royal Command**: Multi-directional attack
- **Sovereign Power**: Ultimate ability animation
- **Crown Fall**: Dramatic defeat sequence

##### King Animations
- **Royal March**: Dignified movement
- **Royal Decree**: Command gesture
- **Last Stand**: Desperate combat
- **Checkmate**: Final defeat/victory sequences

### Environmental Animations

#### Atmospheric Elements
- **Torch Flames**: 30 FPS flame animation
- **Banner Sway**: Wind-affected cloth animation
- **Fog Movement**: Subtle atmospheric motion
- **Particle Effects**: Various magical and combat effects

#### Dynamic Lighting
- **Flickering Torches**: Light intensity variation
- **Lightning Flashes**: Dramatic sky lighting
- **Magical Glows**: Pulsing runic illumination

---

## Audio Asset Specifications

### Music Categories

#### Orchestral Soundtrack
- **Format**: 44.1kHz, 16-bit stereo WAV files
- **Compression**: OGG Vorbis for runtime (quality 7-8)
- **Length**: 3-8 minutes per track with seamless loops
- **Instrumentation**: Full medieval orchestra emphasis

##### Track List Requirements
1. **Main Theme**: Epic orchestral (5 minutes)
2. **Battle Music**: Intense combat scoring (4 minutes) 
3. **Victory Theme**: Triumphant celebration (3 minutes)
4. **Ambient Castle**: Atmospheric background (6 minutes)
5. **Defeat Theme**: Somber loss music (3 minutes)
6. **Tactical Theme**: Thoughtful strategy music (5 minutes)

#### Adaptive Music System
- **Layers**: Multiple instrument layers for dynamic intensity
- **Stems**: Separate instrument groups for mixing
- **Transitions**: Musical bridges between themes
- **Stingers**: Short musical accents for specific events

### Sound Effects Categories

#### Combat Sounds
- **Sword Clashes**: Metal-on-metal impact sounds
- **Horse Sounds**: Neighing, galloping, snorting
- **Armor Movement**: Chainmail and plate armor sounds  
- **Shield Impacts**: Wood and metal shield strikes
- **Weapon Swooshes**: Blade movement through air

#### Environmental Audio
- **Castle Ambience**: Wind through stones, distant sounds
- **Torch Crackle**: Fire burning sounds
- **Stone Movement**: Heavy chess pieces on stone board
- **Footsteps**: Various surfaces and armor types
- **Banner Flaps**: Cloth movement in wind

#### Magical Effects
- **Rune Activation**: Mystical charging sounds
- **Particle Spawns**: Magical manifestation audio
- **Bishop Magic**: Ethereal spell casting
- **Transformation**: Pawn promotion audio
- **Aura Effects**: Continuous magical presence

#### UI and Feedback
- **Piece Selection**: Clear selection confirmation
- **Move Completion**: Satisfying placement sound
- **Check Alert**: Urgent warning tone
- **Checkmate**: Dramatic final sound
- **Menu Navigation**: Clean interface sounds

### Narration Requirements

#### Voice Actor Specifications
- **Language**: English (British accent preferred for medieval feel)
- **Gender**: Male, deep authoritative voice
- **Age Range**: 40-60 years for gravitas
- **Style**: Classical narrator, documentary-style delivery

#### Recording Specifications
- **Format**: 48kHz, 24-bit mono WAV
- **Processing**: Professional noise reduction and normalization
- **Delivery**: Multiple emotional variations per line
- **Length**: 15-45 seconds per narration segment

#### Script Categories
- **Opening Narrations**: Game introduction (30-45 seconds)
- **Move Descriptions**: Individual move commentary (5-15 seconds)  
- **Battle Descriptions**: Combat scene narration (10-20 seconds)
- **Closing Narrations**: Victory/defeat summaries (30-60 seconds)
- **Tutorial**: Instructional voice-over content

---

## Asset Naming Conventions

### File Naming Structure
```
[Category]_[AssetName]_[Variation]_[LOD]_[Type].[Extension]

Examples:
- CP_Pawn_White_LOD0_Mesh.fbx
- CP_Knight_Black_LOD1_Texture_Albedo.tga  
- ENV_Castle_Wall_01_LOD0_Mesh.fbx
- SFX_Sword_Clash_Heavy_01.wav
- MUS_Battle_Theme_Intense_Loop.wav
```

### Category Prefixes
- **CP**: Chess Pieces
- **ENV**: Environment
- **PROP**: Props and decorative elements  
- **MAT**: Materials
- **TEX**: Textures
- **ANIM**: Animations
- **SFX**: Sound Effects
- **MUS**: Music
- **VFX**: Visual Effects/Particles
- **UI**: User Interface elements

### Variation Suffixes
- **_White** / **_Black**: Color variations
- **_01**, **_02**: Numbered variations
- **_Male** / **_Female**: Gender variations
- **_Damaged**: Destruction states
- **_LOD0**, **_LOD1**, etc.: Level of detail versions

---

## Import Pipeline

### 3D Model Import Settings (Unreal Engine 5)

#### FBX Import Configuration
```json
{
  "Import Mesh": true,
  "Import Materials": false,
  "Import Textures": false,
  "Import Animations": true,
  "Create Materials": false,
  "Combine Meshes": false,
  "Generate Lightmap UVs": true,
  "Transform": {
    "Import Translation": [0, 0, 0],
    "Import Rotation": [0, 0, 0],  
    "Import Scale": [1, 1, 1]
  },
  "Mesh": {
    "Remove Degenerates": true,
    "Build Adjacency Buffer": true,
    "Build Reversed Index Buffer": true,
    "Generate LODs": false,
    "Normal Import Method": "Import Normals and Tangents",
    "Normal Generation Method": "MikkTSpace"
  }
}
```

#### Texture Import Settings
```json
{
  "Albedo": {
    "sRGB": true,
    "Compression": "BC7",
    "Mip Gen Settings": "FromTextureGroup",
    "Texture Group": "WorldNormalMap"
  },
  "Normal": {
    "sRGB": false, 
    "Compression": "BC5",
    "Texture Group": "WorldNormalMap",
    "Flip Green Channel": false
  },
  "Roughness/Metallic": {
    "sRGB": false,
    "Compression": "BC4",  
    "Texture Group": "WorldSpecular"
  }
}
```

### Audio Import Settings
```json
{
  "Music": {
    "Format": "OGG",
    "Quality": 0.75,
    "Sample Rate": 44100,
    "Channel Count": "Stereo",
    "Loading Behavior": "Load On Demand"
  },
  "SFX": {
    "Format": "WAV",
    "Quality": 1.0,
    "Sample Rate": 44100, 
    "Loading Behavior": "Load Into Memory"
  },
  "Narration": {
    "Format": "OGG",
    "Quality": 0.85,
    "Channel Count": "Mono",
    "Loading Behavior": "Load On Demand"  
  }
}
```

---

## Optimization Guidelines

### Performance Targets
- **Target FPS**: 60 FPS (PC), 30 FPS (Console)
- **Memory Budget**: 4GB total assets, 2GB VRAM
- **Loading Time**: < 15 seconds initial, < 3 seconds transitions
- **Batch Count**: < 2000 draw calls per frame

### LOD System Implementation
```cpp
// Example LOD distances (Unreal units)
LOD Distances:
- LOD0: 0 - 1000 units (close-up detail)
- LOD1: 1000 - 2500 units (medium distance)
- LOD2: 2500 - 5000 units (far distance)  
- LOD3: 5000+ units (impostor/billboard)
```

### Texture Streaming
- **Pool Size**: 2GB texture streaming pool
- **Mip Bias**: -1 for chess pieces (higher detail)
- **Priority**: Chess pieces > Environment > Effects

### Culling Optimization
- **Frustum Culling**: Standard view frustum culling
- **Occlusion Culling**: Hardware occlusion queries
- **Distance Culling**: Piece-specific cull distances
- **Importance Scaling**: Key pieces render at higher distances

---

## Quality Assurance

### Asset Validation Checklist

#### 3D Models
- [ ] Polygon count within budget
- [ ] Clean topology (no n-gons, minimal triangulation)
- [ ] Proper UV mapping (no overlaps, good texel density)
- [ ] Correct pivot point and orientation
- [ ] All LOD levels generated and tested
- [ ] Materials properly assigned
- [ ] Lightmap UVs generated (for static meshes)

#### Textures
- [ ] Correct resolution and format
- [ ] Proper compression settings
- [ ] No visual artifacts or seams
- [ ] Consistent style across asset set
- [ ] Mip maps generated correctly
- [ ] Color space correctly set

#### Animations  
- [ ] Smooth interpolation between keyframes
- [ ] Proper loop points for cyclic animations
- [ ] No mesh interpenetration during animation
- [ ] Consistent timing across similar animations
- [ ] Root motion correctly configured
- [ ] Animation compression optimized

#### Audio
- [ ] No clipping or distortion
- [ ] Consistent volume levels across similar sounds
- [ ] Proper fade-ins and fade-outs
- [ ] No unwanted silence or noise
- [ ] Correct format and compression
- [ ] Seamless loops for music

### Performance Testing
- [ ] Frame rate maintained at target levels
- [ ] Memory usage within budgets
- [ ] Loading times acceptable
- [ ] No streaming hitches
- [ ] Proper LOD transitions
- [ ] Culling working correctly

### Visual Quality Standards
- [ ] Consistent art style across all assets
- [ ] Appropriate level of detail for viewing distance
- [ ] Lighting responds correctly to dynamic lights
- [ ] Materials appear correct under various lighting
- [ ] No visual glitches or artifacts
- [ ] Proper alpha sorting for transparent elements

---

This comprehensive asset pipeline ensures that Iron Chess maintains the highest visual and audio fidelity while meeting performance requirements across all target platforms. Each asset category has been carefully planned to contribute to the immersive medieval chess experience while maintaining optimal runtime performance.