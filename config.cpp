class CfgPatches
{
    class ld3k_jca_mk23_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_Mk23",
            "Weapons_F_JCA_Mk23_Pistols_Mk23"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    /*class B_45ACP_Ball: BulletBase // official BI tool All-in-one Config Arma3 2.19.152743 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        airLock=1;
        hit=5;
        indirectHit=0;
        indirectHitRange=0;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        cartridge="FxCartridge_9mm";
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
        caliber=1.4;
        deflecting=25;
        audibleFire=45;
        cost=100;
        typicalSpeed=280;
        airFriction=-0.0018;
        tracerScale=0.6;
        tracerStartTime=0.0075;
        tracerEndTime=5;
    };
    class B_45ACP_Ball_Green: B_45ACP_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class B_45ACP_Ball_Yellow: B_45ACP_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class B_45ACP_Ball: BulletBase // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L727
    {
        airFriction=-0.00082143;
        tracerScale=0.6;
        ACE_caliber=11.481;
        ACE_bulletLength=17.272;
        ACE_bulletMass=14.904;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619};
        ACE_ballisticCoefficients[]={0.195};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={230,250,285};
        ACE_barrelLengths[]={101.6,127.0,228.6};
    };*/
    class JCA_B_45ACP_Ball_Mk23: BulletBase // Winchester Law Enforcement .45 ACP +P 230gr, 990fps (302m/s) barrel length 5" https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
    {
        ACE_caliber=11.48; // CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf
        ACE_bulletLength=16.99; // 0.669"
        ACE_bulletMass=14.904; // 230gr
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /10. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        // ACE_ballisticCoefficients[]={0.193}; // 990fps (302m/s) 5", ICAO G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ICAO";
        // ACE_ballisticCoefficients[]={0.187}; // 990fps (302m/s) 5", ASM G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ASM";
        ACE_ballisticCoefficients[]={0.209}; // 1020fps (311m/s) 149mm, ICAO G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        ACE_standardAtmosphere="ICAO";
        // ACE_ballisticCoefficients[]={0.203}; // 1020fps (311m/s) 149mm, ASM G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ASM";
        ACE_velocityBoundaries[]={};
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={278,302,344}; // 311m/s barrel length 149mm ICAO conditions (15°C, 1013.25 hPa, 0%)
        ACE_barrelLengths[]={101.6,127,228.6}; // 4", 5", 9"
        airLock=1;
        hit=6.2; // 721 Joules, B_45ACP_Ball 5 584 Joules, JCA 7
        indirectHit=0;
        indirectHitRange=0;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        cartridge="FxCartridge_9mm";
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_45ACP_Ball tracer_red
        caliber=1.4;
        deflecting=25;
        visibleFire=1; // Subsonic, B_127x54_Ball, BulletBase 3
        audibleFire=5; // Subsonic, B_127x54_Ball, B_45ACP_Ball 45
        cost=100;
        typicalSpeed=311; // 721 Joules, B_45ACP_Ball 280 584 Joules
        airFriction=-0.00105488; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        tracerScale=0.6;
        tracerStartTime=0.0075;
        tracerEndTime=5;
        nvgOnly=0; // B_45ACP_Ball w/o nvgOnly
    };
    class JCA_B_45ACP_Ball_Mk23_Tracer_Red: JCA_B_45ACP_Ball_Mk23
    {
        visibleFire=5; // B_45ACP_Ball 3, B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_45ACP_Ball_Mk23_Tracer_Green: JCA_B_45ACP_Ball_Mk23_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_45ACP_Ball_Mk23_Tracer_Yellow: JCA_B_45ACP_Ball_Mk23_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_45ACP_Ball_Mk23_Tracer_IR: JCA_B_45ACP_Ball_Mk23
    {
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_12Rnd_45ACP_Mk23_Mag: CA_Magazine // JCA default config
    {
        // mass=13.6; // Operators Manual Mk23 empty magazine 12rnd 366g + cartridge 21g x12= 618g, 11Rnd_45ACP_Mag 7, JCA 8
        ammo="JCA_B_45ACP_Ball_Mk23";
        initSpeed=311; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 370
    };
    class JCA_12Rnd_45ACP_Mk23_Tracer_Red_Mag: JCA_12Rnd_45ACP_Mk23_Mag
    {
        ammo="JCA_B_45ACP_Ball_Mk23_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_12Rnd_45ACP_Mk23_Tracer_Green_Mag: JCA_12Rnd_45ACP_Mk23_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_Mk23_Tracer_Green";
    };
    class JCA_12Rnd_45ACP_Mk23_Tracer_Yellow_Mag: JCA_12Rnd_45ACP_Mk23_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_Mk23_Tracer_Yellow";
    };
    class JCA_12Rnd_45ACP_Mk23_Tracer_IR_Mag: JCA_12Rnd_45ACP_Mk23_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_Mk23_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    class JCA_Mk23_45ACP // Weapon initSpeed -1 ACE_barrelLength 149mm: 311m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_12Rnd_45ACP_Mk23 magazines initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_12Rnd_45ACP_Mk23_Mag",
            "JCA_12Rnd_45ACP_Mk23_Tracer_Red_Mag",
            "JCA_12Rnd_45ACP_Mk23_Tracer_Green_Mag",
            "JCA_12Rnd_45ACP_Mk23_Tracer_Yellow_Mag",
            "JCA_12Rnd_45ACP_Mk23_Tracer_IR_Mag"
        };
    };
};
class Mode_SemiAuto;
class CfgWeapons
{
    class Pistol;
    class Pistol_Base_F: Pistol
    {
        class WeaponSlotsInfo;
    };
    class JCA_hgun_Mk23_base_F: Pistol_Base_F
    {
        ACE_barrelLength=149; // 5.87" Operators Manual Mark 23
        ACE_barrelTwist=378; // Operators Manual Mark 23 (CIP 406mm https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf)
        initSpeed=-1; // 311m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 300
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=26.7; // Operators Manual Mark 23 1.21kg (empty magazine), JCA 35
        };
        class Single: Mode_SemiAuto // "2.5-inch maximum extreme spread in 5-round shot groups at 25 meters with service ammunition" Operators Manual Mark 23
        {
            dispersion=0.001428; // 8.73 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0037 (12.72 MOA)
        };
    };
};
