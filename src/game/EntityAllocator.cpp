// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "EntityManager.h"
#include "EntityAllocator.h"

// TODO(header): foreign declarations
// local class shells for new expressions
class Achille {
public:
    Achille();
    char _pad[0x760];
};
class AchilleObject {
public:
    AchilleObject();
    char _pad[0x220];
};
class ActionPling {
public:
    ActionPling();
    char _pad[0x1C0];
};
class AmbientEntity {
public:
    AmbientEntity();
    char _pad[0x200];
};
class Ancestor {
public:
    Ancestor();
    char _pad[0x1D0];
};
class AnimSegmentTrigger {
public:
    AnimSegmentTrigger();
    char _pad[0x230];
};
class AnimTrigger {
public:
    AnimTrigger();
    char _pad[0x210];
};
class AnimTriggerOnDeath {
public:
    AnimTriggerOnDeath();
    char _pad[0x1D0];
};
class ArenaWaveSetup {
public:
    ArenaWaveSetup();
    char _pad[0x1D0];
};
class Bane {
public:
    Bane();
    char _pad[0x23F0];
};
class BaneObject {
public:
    BaneObject();
    char _pad[0x1E0];
};
class Baron {
public:
    Baron();
    char _pad[0x2240];
};
class BattleArena {
public:
    BattleArena();
    char _pad[0x400];
};
class BlowingLeaves {
public:
    BlowingLeaves();
    char _pad[0x200];
};
class BlowingLeavesTrigger {
public:
    BlowingLeavesTrigger();
    char _pad[0x1D0];
};
class BoreBeetle {
public:
    BoreBeetle();
    char _pad[0x250];
};
class BoreBeetleCocoon {
public:
    BoreBeetleCocoon();
    char _pad[0x1D0];
};
class BreakableItem {
public:
    BreakableItem();
    char _pad[0x1D0];
};
class Bridge {
public:
    Bridge();
    char _pad[0x3A0];
};
class Bubbles {
public:
    Bubbles();
    char _pad[0x1F0];
};
class Bucket {
public:
    Bucket();
    char _pad[0x1E0];
};
class CamBox {
public:
    CamBox();
    char _pad[0x2B0];
};
class CamCylinder {
public:
    CamCylinder();
    char _pad[0x1F0];
};
class CamSphere {
public:
    CamSphere();
    char _pad[0x1E0];
};
class CeilingDebris {
public:
    CeilingDebris();
    char _pad[0x1C0];
};
class ClockworkFlyer {
public:
    ClockworkFlyer();
    char _pad[0x2D0];
};
class ClockworkMaximo {
public:
    ClockworkMaximo();
    char _pad[0x2A0];
};
class ClockworkPuncher {
public:
    ClockworkPuncher();
    char _pad[0x2E0];
};
class ClockworkReaper {
public:
    ClockworkReaper();
    char _pad[0x310];
};
class ClockworkReaperGunner {
public:
    ClockworkReaperGunner();
    char _pad[0x1C0];
};
class ClockworkReaperSpear {
public:
    ClockworkReaperSpear();
    char _pad[0x1E0];
};
class ClockworkSoulsucker {
public:
    ClockworkSoulsucker();
    char _pad[0x2D0];
};
class ClockworkStalker {
public:
    ClockworkStalker();
    char _pad[0x300];
};
class ClockworkStinger {
public:
    ClockworkStinger();
    char _pad[0x270];
};
class CornWall {
public:
    CornWall();
    char _pad[0x1C0];
};
class CutCameraSetup {
public:
    CutCameraSetup();
    char _pad[0x260];
};
class CutableItem {
public:
    CutableItem();
    char _pad[0x1C0];
};
class Cyclocks {
public:
    Cyclocks();
    char _pad[0x540];
};
class CyclocksDebris {
public:
    CyclocksDebris();
    char _pad[0x1C0];
};
class CyclocksObject {
public:
    CyclocksObject();
    char _pad[0x2B0];
};
class CyclocksShockwave {
public:
    CyclocksShockwave();
    char _pad[0x3E0];
};
class DoorFlaming {
public:
    DoorFlaming();
    char _pad[0x1E0];
};
class EnemyGenerator {
public:
    EnemyGenerator();
    char _pad[0x210];
};
class EntityTrigger {
public:
    EntityTrigger();
    char _pad[0x200];
};
class ExitLevel {
public:
    ExitLevel();
    char _pad[0x1F0];
};
class FarPlaneTrigger {
public:
    FarPlaneTrigger();
    char _pad[0x1D0];
};
class Fire {
public:
    Fire();
    char _pad[0x1D0];
};
class Fog {
public:
    Fog();
    char _pad[0x220];
};
class FogTrigger {
public:
    FogTrigger();
    char _pad[0x210];
};
class GunTurret {
public:
    GunTurret();
    char _pad[0x270];
};
class HangingNet {
public:
    HangingNet();
    char _pad[0x1C0];
};
class HarmonicCrystal {
public:
    HarmonicCrystal();
    char _pad[0x1E0];
};
class Highwayman {
public:
    Highwayman();
    char _pad[0x290];
};
class HolyGround {
public:
    HolyGround();
    char _pad[0x1D0];
};
class HouseCrasher {
public:
    HouseCrasher();
    char _pad[0x610];
};
class HouseCrasherBullet {
public:
    HouseCrasherBullet();
    char _pad[0x1E0];
};
class HouseCrasherDebris {
public:
    HouseCrasherDebris();
    char _pad[0x1E0];
};
class HouseCrasherTree {
public:
    HouseCrasherTree();
    char _pad[0x1C0];
};
class Innocent {
public:
    Innocent();
    char _pad[0x2B0];
};
class LiftOperator {
public:
    LiftOperator();
    char _pad[0x240];
};
class LockGate {
public:
    LockGate();
    char _pad[0x1C0];
};
class LockOnTarget {
public:
    LockOnTarget();
    char _pad[0x1C0];
};
class MagicEye {
public:
    MagicEye();
    char _pad[0x210];
};
class MagicEyeShockwave {
public:
    MagicEyeShockwave();
    char _pad[0x1F0];
};
class MineableItem {
public:
    MineableItem();
    char _pad[0x1D0];
};
class MovingFog {
public:
    MovingFog();
    char _pad[0x200];
};
class Mushroom {
public:
    Mushroom();
    char _pad[0x1D0];
};
class MusicSwitch {
public:
    MusicSwitch();
    char _pad[0x210];
};
class OakmeadSign {
public:
    OakmeadSign();
    char _pad[0x1C0];
};
class Peddler {
public:
    Peddler();
    char _pad[0x2E0];
};
class Pickup {
public:
    Pickup();
    char _pad[0x240];
};
class Player {
public:
    Player();
    char _pad[0x23E0];
};
class Projectile {
public:
    Projectile();
    char _pad[0x200];
};
class PropellerEngine {
public:
    PropellerEngine();
    char _pad[0x1D0];
};
class PropellerPowerSource {
public:
    PropellerPowerSource();
    char _pad[0x1E0];
};
class PumpkinHead {
public:
    PumpkinHead();
    char _pad[0x240];
};
class PumpkinHeadBomb {
public:
    PumpkinHeadBomb();
    char _pad[0x1D0];
};
class Rabite {
public:
    Rabite();
    char _pad[0x250];
};
class Rain {
public:
    Rain();
    char _pad[0x1C0];
};
class RainTrigger {
public:
    RainTrigger();
    char _pad[0x1D0];
};
class Raven {
public:
    Raven();
    char _pad[0x270];
};
class ReversibleAnimTrigger {
public:
    ReversibleAnimTrigger();
    char _pad[0x1F0];
};
class Roots {
public:
    Roots();
    char _pad[0x1E0];
};
class SavePoint {
public:
    SavePoint();
    char _pad[0x1C0];
};
class SeaSerpent {
public:
    SeaSerpent();
    char _pad[0x400];
};
class SeaSerpentBreakablePlanks {
public:
    SeaSerpentBreakablePlanks();
    char _pad[0x1D0];
};
class SeaSerpentPoisonGasCloud {
public:
    SeaSerpentPoisonGasCloud();
    char _pad[0x1D0];
};
class Shield {
public:
    Shield();
    char _pad[0x1E0];
};
class SoulFire {
public:
    SoulFire();
    char _pad[0x1F0];
};
class SoundRoom {
public:
    SoundRoom();
    char _pad[0x1F0];
};
class SoundTriggerPlainBox {
public:
    SoundTriggerPlainBox();
    char _pad[0x230];
};
class SoundTriggerPlainSphere {
public:
    SoundTriggerPlainSphere();
    char _pad[0x1F0];
};
class Spitter {
public:
    Spitter();
    char _pad[0x220];
};
class SpitterItem {
public:
    SpitterItem();
    char _pad[0x210];
};
class Stalactite {
public:
    Stalactite();
    char _pad[0x1C0];
};
class SulfurMonster {
public:
    SulfurMonster();
    char _pad[0x270];
};
class Tinker {
public:
    Tinker();
    char _pad[0x300];
};
class Triton {
public:
    Triton();
    char _pad[0x290];
};
class WoodenChest {
public:
    WoodenChest();
    char _pad[0x220];
};
class ZinShell {
public:
    ZinShell();
    char _pad[0x240];
};
class ZinShellCrater {
public:
    ZinShellCrater();
    char _pad[0x1C0];
};
class ZinShellExplosion {
public:
    ZinShellExplosion();
    char _pad[0x1C0];
};
class ZinShellShadow {
public:
    ZinShellShadow();
    char _pad[0x1C0];
};
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__10BaneObjectFv(void *);
extern "C" void *__ct__10BoreBeetleFv(void *);
extern "C" void *__ct__10FogTriggerFv(void *);
extern "C" void *__ct__10HangingNetFv(void *);
extern "C" void *__ct__10HighwaymanFv(void *);
extern "C" void *__ct__10HolyGroundFv(void *);
extern "C" void *__ct__10ProjectileFv(void *);
extern "C" void *__ct__10SeaSerpentFv(void *);
extern "C" void *__ct__10StalactiteFv(void *);
extern "C" void *__ct__11ActionPlingFv(void *);
extern "C" void *__ct__11AnimTriggerFv(void *);
extern "C" void *__ct__11BattleArenaFv(void *);
extern "C" void *__ct__11CamCylinderFv(void *);
extern "C" void *__ct__11CutableItemFv(void *);
extern "C" void *__ct__11DoorFlamingFv(void *);
extern "C" void *__ct__11MusicSwitchFv(void *);
extern "C" void *__ct__11OakmeadSignFv(void *);
extern "C" void *__ct__11PumpkinHeadFv(void *);
extern "C" void *__ct__11RainTriggerFv(void *);
extern "C" void *__ct__11SpitterItemFv(void *);
extern "C" void *__ct__11WoodenChestFv(void *);
extern "C" void *__ct__12HouseCrasherFv(void *);
extern "C" void *__ct__12LiftOperatorFv(void *);
extern "C" void *__ct__12LockOnTargetFv(void *);
extern "C" void *__ct__12MineableItemFv(void *);
extern "C" void *__ct__13AchilleObjectFv(void *);
extern "C" void *__ct__13AmbientEntityFv(void *);
extern "C" void *__ct__13BlowingLeavesFv(void *);
extern "C" void *__ct__13BreakableItemFv(void *);
extern "C" void *__ct__13CeilingDebrisFv(void *);
extern "C" void *__ct__13EntityTriggerFv(void *);
extern "C" void *__ct__13SulfurMonsterFv(void *);
extern "C" void *__ct__14ArenaWaveSetupFv(void *);
extern "C" void *__ct__14ClockworkFlyerFv(void *);
extern "C" void *__ct__14CutCameraSetupFv(void *);
extern "C" void *__ct__14CyclocksDebrisFv(void *);
extern "C" void *__ct__14CyclocksObjectFv(void *);
extern "C" void *__ct__14EnemyGeneratorFv(void *);
extern "C" void *__ct__14ZinShellCraterFv(void *);
extern "C" void *__ct__14ZinShellShadowFv(void *);
extern "C" void *__ct__15ClockworkMaximoFv(void *);
extern "C" void *__ct__15ClockworkReaperFv(void *);
extern "C" void *__ct__15FarPlaneTriggerFv(void *);
extern "C" void *__ct__15HarmonicCrystalFv(void *);
extern "C" void *__ct__15PropellerEngineFv(void *);
extern "C" void *__ct__15PumpkinHeadBombFv(void *);
extern "C" void *__ct__16BoreBeetleCocoonFv(void *);
extern "C" void *__ct__16ClockworkPuncherFv(void *);
extern "C" void *__ct__16ClockworkStalkerFv(void *);
extern "C" void *__ct__16ClockworkStingerFv(void *);
extern "C" void *__ct__16HouseCrasherTreeFv(void *);
extern "C" void *__ct__17CyclocksShockwaveFv(void *);
extern "C" void *__ct__17MagicEyeShockwaveFv(void *);
extern "C" void *__ct__17ZinShellExplosionFv(void *);
extern "C" void *__ct__18AnimSegmentTriggerFv(void *);
extern "C" void *__ct__18AnimTriggerOnDeathFv(void *);
extern "C" void *__ct__18HouseCrasherBulletFv(void *);
extern "C" void *__ct__18HouseCrasherDebrisFv(void *);
extern "C" void *__ct__19ClockworkSoulsuckerFv(void *);
extern "C" void *__ct__20BlowingLeavesTriggerFv(void *);
extern "C" void *__ct__20ClockworkReaperSpearFv(void *);
extern "C" void *__ct__20PropellerPowerSourceFv(void *);
extern "C" void *__ct__20SoundTriggerPlainBoxFv(void *);
extern "C" void *__ct__21ClockworkReaperGunnerFv(void *);
extern "C" void *__ct__21ReversibleAnimTriggerFv(void *);
extern "C" void *__ct__23SoundTriggerPlainSphereFv(void *);
extern "C" void *__ct__24SeaSerpentPoisonGasCloudFv(void *);
extern "C" void *__ct__25SeaSerpentBreakablePlanksFv(void *);
extern "C" void *__ct__3FogFv(void *);
extern "C" void *__ct__4BaneFv(void *);
extern "C" void *__ct__4FireFv(void *);
extern "C" void *__ct__4RainFv(void *);
extern "C" void *__ct__5BaronFv(void *);
extern "C" void *__ct__5RavenFv(void *);
extern "C" void *__ct__5RootsFv(void *);
extern "C" void *__ct__6BridgeFv(void *);
extern "C" void *__ct__6BucketFv(void *);
extern "C" void *__ct__6CamBoxFv(void *);
extern "C" void *__ct__6PickupFv(void *);
extern "C" void *__ct__6PlayerFv(void *);
extern "C" void *__ct__6RabiteFv(void *);
extern "C" void *__ct__6ShieldFv(void *);
extern "C" void *__ct__6TinkerFv(void *);
extern "C" void *__ct__6TritonFv(void *);
extern "C" void *__ct__7AchilleFv(void *);
extern "C" void *__ct__7BubblesFv(void *);
extern "C" void *__ct__7PeddlerFv(void *);
extern "C" void *__ct__7SpitterFv(void *);
extern "C" void *__ct__8AncestorFv(void *);
extern "C" void *__ct__8CornWallFv(void *);
extern "C" void *__ct__8CyclocksFv(void *);
extern "C" void *__ct__8InnocentFv(void *);
extern "C" void *__ct__8LockGateFv(void *);
extern "C" void *__ct__8MagicEyeFv(void *);
extern "C" void *__ct__8MushroomFv(void *);
extern "C" void *__ct__8SoulFireFv(void *);
extern "C" void *__ct__8ZinShellFv(void *);
extern "C" void *__ct__9CamSphereFv(void *);
extern "C" void *__ct__9ExitLevelFv(void *);
extern "C" void *__ct__9GunTurretFv(void *);
extern "C" void *__ct__9MovingFogFv(void *);
extern "C" void *__ct__9SavePointFv(void *);
extern "C" void *__ct__9SoundRoomFv(void *);

// FUNCTION: 0x001B0AA0 SpawnEntity__13EntityManagerFUii
void *EntityManager::SpawnEntity(unsigned int arg0, int arg1) {
    void *var_s0;
    void *temp;

    switch (arg0) {
    case 0x3:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Player;
        goto block_621;
    case 0x2D:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Projectile;
        goto block_621;
    case 0x1:
        if ((arg1 != -1) && (arg1 != 0x13)) {
            return (void *)-1;
        }
        var_s0 = new CamBox;
        goto block_621;
    case 0x7:
        if ((arg1 != -1) && (arg1 != 0x15)) {
            return (void *)-1;
        }
        var_s0 = new Innocent;
        goto block_621;
    case 0xC:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new CamSphere;
        goto block_621;
    case 0x8:
        if ((arg1 != -1) && (arg1 != 5)) {
            return (void *)-1;
        }
        var_s0 = new Pickup;
        goto block_621;
    case 0xA:
        if ((arg1 != -1) && (arg1 != 0xC)) {
            return (void *)-1;
        }
        var_s0 = new WoodenChest;
        goto block_621;
    case 0xD:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new CamCylinder;
        goto block_621;
    case 0x5:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Shield;
        goto block_621;
    case 0x6:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new HolyGround;
        goto block_621;
    case 0xF:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new ZinShell;
        goto block_621;
    case 0x11:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ZinShellExplosion;
        goto block_621;
    case 0x12:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ZinShellShadow;
        goto block_621;
    case 0x14:
        if ((arg1 != -1) && (arg1 != 0x14)) {
            return (void *)-1;
        }
        var_s0 = new AnimTrigger;
        goto block_621;
    case 0x16:
        if ((arg1 != -1) && (arg1 != 5)) {
            return (void *)-1;
        }
        var_s0 = new SoundRoom;
        goto block_621;
    case 0x1A:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ActionPling;
        goto block_621;
    case 0x24:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new Raven;
        goto block_621;
    case 0x26:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new Fire;
        goto block_621;
    case 0x28:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new MineableItem;
        goto block_621;
    case 0x25:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new CutableItem;
        goto block_621;
    case 0x2C:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new AmbientEntity;
        goto block_621;
    case 0x17:
        if ((arg1 != -1) && (arg1 != 0xD)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkReaper;
        goto block_621;
    case 0x35:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new ExitLevel;
        goto block_621;
    case 0x39:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new MusicSwitch;
        goto block_621;
    case 0x3F:
        if ((arg1 != -1) && (arg1 != 0xD)) {
            return (void *)-1;
        }
        var_s0 = new BattleArena;
        goto block_621;
    case 0x40:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new ArenaWaveSetup;
        goto block_621;
    case 0x41:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ZinShellCrater;
        goto block_621;
    case 0x4D:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new RainTrigger;
        goto block_621;
    case 0x4C:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new Rain;
        goto block_621;
    case 0x4F:
        if ((arg1 != -1) && (arg1 != 7)) {
            return (void *)-1;
        }
        var_s0 = new FogTrigger;
        goto block_621;
    case 0x4E:
        if ((arg1 != -1) && (arg1 != 9)) {
            return (void *)-1;
        }
        var_s0 = new Fog;
        goto block_621;
    case 0x1F:
        if ((arg1 != -1) && (arg1 != 0x14)) {
            return (void *)-1;
        }
        var_s0 = new Peddler;
        goto block_621;
    case 0xB:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new LockOnTarget;
        goto block_621;
    case 0x5A:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new MovingFog;
        goto block_621;
    case 0x9:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new BreakableItem;
        goto block_621;
    case 0x15:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new SpitterItem;
        goto block_621;
    case 0xE:
        if ((arg1 != -1) && (arg1 != 0xA)) {
            return (void *)-1;
        }
        var_s0 = new Spitter;
        goto block_621;
    case 0x19:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new LockGate;
        goto block_621;
    case 0x61:
        if ((arg1 != -1) && (arg1 != 0x12)) {
            return (void *)-1;
        }
        var_s0 = new CutCameraSetup;
        goto block_621;
    case 0x29:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new Bridge;
        goto block_621;
    case 0x22:
        if ((arg1 != -1) && (arg1 != 0xA)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkPuncher;
        goto block_621;
    case 0x37:
        if ((arg1 != -1) && (arg1 != 0xA)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkStinger;
        goto block_621;
    case 0x36:
        if ((arg1 != -1) && (arg1 != 0xA)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkStalker;
        goto block_621;
    case 0x2B:
        if ((arg1 != -1) && (arg1 != 0xC)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkFlyer;
        goto block_621;
    case 0x57:
        if ((arg1 != -1) && (arg1 != 9)) {
            return (void *)-1;
        }
        var_s0 = new ReversibleAnimTrigger;
        goto block_621;
    case 0x69:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkReaperSpear;
        goto block_621;
    case 0x1E:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new PropellerPowerSource;
        goto block_621;
    case 0x4:
        if ((arg1 != -1) && (arg1 != 0xA)) {
            return (void *)-1;
        }
        var_s0 = new EntityTrigger;
        goto block_621;
    case 0x2A:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new Rabite;
        goto block_621;
    case 0x45:
        if ((arg1 != -1) && (arg1 != 5)) {
            return (void *)-1;
        }
        var_s0 = new BlowingLeaves;
        goto block_621;
    case 0x50:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new FarPlaneTrigger;
        goto block_621;
    case 0x6B:
        if ((arg1 != -1) && (arg1 != 9)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkSoulsucker;
        goto block_621;
    case 0x55:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new BlowingLeavesTrigger;
        goto block_621;
    case 0x48:
        if ((arg1 != -1) && (arg1 != 0x1B)) {
            return (void *)-1;
        }
        var_s0 = new Tinker;
        goto block_621;
    case 0x71:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new SoundTriggerPlainBox;
        goto block_621;
    case 0x70:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new SoundTriggerPlainSphere;
        goto block_621;
    case 0x58:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new EnemyGenerator;
        goto block_621;
    case 0x74:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new SavePoint;
        goto block_621;
    case 0x7B:
        if ((arg1 != -1) && (arg1 != 0xF)) {
            return (void *)-1;
        }
        var_s0 = new AnimSegmentTrigger;
        goto block_621;
    case 0x51:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new CeilingDebris;
        goto block_621;
    case 0x2E:
        if ((arg1 != -1) && (arg1 != 9)) {
            return (void *)-1;
        }
        var_s0 = new LiftOperator;
        goto block_621;
    case 0x72:
        if ((arg1 != -1) && (arg1 != 9)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkMaximo;
        goto block_621;
    case 0x7F:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new AnimTriggerOnDeath;
        goto block_621;
    case 0x6F:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new ClockworkReaperGunner;
        goto block_621;
    case 0x6C:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new GunTurret;
        goto block_621;
    case 0x2:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new SoulFire;
        goto block_621;
    case 0x1C:
        if ((arg1 != -1) && (arg1 != 5)) {
            return (void *)-1;
        }
        var_s0 = new MagicEye;
        goto block_621;
    case 0x7D:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new MagicEyeShockwave;
        goto block_621;
    case 0x49:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new DoorFlaming;
        goto block_621;
    case 0x2F:
        if ((arg1 != -1) && (arg1 != 5)) {
            return (void *)-1;
        }
        var_s0 = new HouseCrasher;
        goto block_621;
    case 0x3C:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new HouseCrasherBullet;
        goto block_621;
    case 0x34:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new HouseCrasherDebris;
        goto block_621;
    case 0x47:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new HouseCrasherTree;
        goto block_621;
    case 0x4B:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new OakmeadSign;
        goto block_621;
    case 0x7A:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new Achille;
        goto block_621;
    case 0x7E:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new AchilleObject;
        goto block_621;
    case 0x75:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new Bane;
        goto block_621;
    case 0x79:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new BaneObject;
        goto block_621;
    case 0x33:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Bucket;
        goto block_621;
    case 0x5C:
        if ((arg1 != -1) && (arg1 != 4)) {
            return (void *)-1;
        }
        var_s0 = new Cyclocks;
        goto block_621;
    case 0x5E:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new CyclocksDebris;
        goto block_621;
    case 0x5F:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new CyclocksObject;
        goto block_621;
    case 0x64:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new CyclocksShockwave;
        goto block_621;
    case 0x53:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new Highwayman;
        goto block_621;
    case 0x1D:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new PropellerEngine;
        goto block_621;
    case 0x54:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new PumpkinHead;
        goto block_621;
    case 0x6A:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new PumpkinHeadBomb;
        goto block_621;
    case 0x44:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new CornWall;
        goto block_621;
    case 0x46:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new Roots;
        goto block_621;
    case 0x3D:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new Mushroom;
        goto block_621;
    case 0x59:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Ancestor;
        goto block_621;
    case 0x1B:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Baron;
        goto block_621;
    case 0x4A:
        if ((arg1 != -1) && (arg1 != 6)) {
            return (void *)-1;
        }
        var_s0 = new BoreBeetle;
        goto block_621;
    case 0x32:
        if ((arg1 != -1) && (arg1 != 2)) {
            return (void *)-1;
        }
        var_s0 = new BoreBeetleCocoon;
        goto block_621;
    case 0x23:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new HangingNet;
        goto block_621;
    case 0x43:
        if ((arg1 != -1) && (arg1 != 7)) {
            return (void *)-1;
        }
        var_s0 = new HarmonicCrystal;
        goto block_621;
    case 0x5B:
        if ((arg1 != -1) && (arg1 != 1)) {
            return (void *)-1;
        }
        var_s0 = new Stalactite;
        goto block_621;
    case 0x38:
        if ((arg1 != -1) && (arg1 != 3)) {
            return (void *)-1;
        }
        var_s0 = new SulfurMonster;
        goto block_621;
    case 0x7C:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new SeaSerpentPoisonGasCloud;
        goto block_621;
    case 0x77:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new SeaSerpent;
        goto block_621;
    case 0x76:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new SeaSerpentBreakablePlanks;
        goto block_621;
    case 0x78:
        if ((arg1 != -1) && (arg1 != 0)) {
            return (void *)-1;
        }
        var_s0 = new Bubbles;
        goto block_621;
    case 0x73:
        if ((arg1 != -1) && (arg1 != 8)) {
            return (void *)-1;
        }
        var_s0 = new Triton;
        goto block_621;
    default:
        CdsAssert("EntityAllocator.cpp", 0x345, "0");
        goto block_621;
    }
block_621:
    return var_s0;
}
