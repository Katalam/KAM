#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class kat_aceCirculation
    {
        units[] = {
			"KAT_PainkillersItem",
      "KAT_X_AEDItem"
		};
        weapons[] = {
      "KAT_Painkillers",
      "KAT_bloodIV_O",
      "KAT_bloodIV_A",
      "KAT_bloodIV_B",
      "KAT_bloodIV_AB",
      "KAT_bloodIV_O_500",
      "KAT_bloodIV_A_500",
      "KAT_bloodIV_B_500",
      "KAT_bloodIV_AB_500",
      "KAT_bloodIV_O_250",
      "KAT_bloodIV_A_250",
      "KAT_bloodIV_B_250",
      "KAT_bloodIV_AB_250",
      "KAT_X_AED"
		};
        requiredVersion = 1.80;
        requiredAddons[] = {
			"ace_medical",
      "ace_dogtags",
      "adv_aceCPR",
      "cba_settings"
		};
		version = "0.7";
		versionStr = "0.7";
		author = "[SeL] Katalam";
		authorUrl = "http://spezialeinheit-luchs.de/";
    };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
};

#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}

class CfgFunctions {
	class kat_aceCirculation {
    file = "kat_aceCirculation\functions";
		class functions {
        class bloodType{};
        class compatible{};
        class events{};
        class groupID{};
        class handleInit{};
        class handleTreatment{};
        class init{};
        class registerSettings{};
        class removeAccess{};
        class removeEffect_IV{};
        class removeItemfromMag{};
        class treatmentAdvanced_Access{};
        class treatmentAdvanced_IV{};
        class treatmentAdvanced_X{};
		};
	};
  class kat_aceDogtag {
    tag = "ace_dogtags";
    class ace_dogtags {
      class getDogtagData {
        file = "kat_aceCirculation\functions\fn_getDogtagData.sqf";
      };
      class canCheckDogtag {
        file = "kat_aceCirculation\functions\fn_canCheckDogtag.sqf";
      };
    };
  };
};

class Extended_PreInit_EventHandlers {
	class kat_aceCirculation_preInit {
		init = "call kat_aceCirculation_fnc_registerSettings";
	};
};
class Extended_Init_EventHandlers {
    class CAManBase {
        class kat_aceCirculation_init {
            init = "_this call kat_aceCirculation_fnc_handleInit";
        };
    };
};
class Extended_PostInit_EventHandlers {
  class kat_aceCirculation_postInit {
    init = "call kat_aceCirculation_fnc_events";
  };
};

class CfgSounds {
  sounds[] = {};
  class KAT_HeartRate {
      name = "KAT_HeartRate";
      sound[] = {"kat_aceCirculation\sounds\heartrate.wav", db + 2, 1, 15};
      titles[]	= {};
  };
  class KAT_NoHeartRate {
      name = "KAT_NoHeartRate";
      sound[] = {"kat_aceCirculation\sounds\noheartrate.wav", db + 2, 1, 15};
      titles[]	= {};
  };
  class KAT_NoShock {
      name = "KAT_NoShock";
      sound[] = {"kat_aceCirculation\sounds\noshock.wav", db + 2, 1, 15};
      titles[]	= {};
  };
};

class cfgWeapons {
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
  class ACE_bloodIV;
  class adv_aceCPR_AED;
  class KAT_bloodIV_O: ACE_bloodIV {
    displayName = $STR_KAT_aceCirculation_BloodIV_O;
  };
  class KAT_bloodIV_A: ACE_bloodIV {
    displayName = $STR_KAT_aceCirculation_BloodIV_A;
  };
  class KAT_bloodIV_B: ACE_bloodIV {
    displayName = $STR_KAT_aceCirculation_BloodIV_B;
  };
  class KAT_bloodIV_AB: ACE_bloodIV {
    displayName = $STR_KAT_aceCirculation_BloodIV_AB;
  };
  class ACE_bloodIV_500;
  class KAT_bloodIV_O_500: ACE_bloodIV_500 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_O_500";
  };
  class KAT_bloodIV_A_500: ACE_bloodIV_500 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_A_500";
  };
  class KAT_bloodIV_B_500: ACE_bloodIV_500 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_B_500";
  };
  class KAT_bloodIV_AB_500: ACE_bloodIV_500 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_AB_500";
  };
  class ACE_bloodIV_250;
  class KAT_bloodIV_O_250: ACE_bloodIV_250 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_O_250";
  };
  class KAT_bloodIV_A_250: ACE_bloodIV_250 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_A_250";
  };
  class KAT_bloodIV_B_250: ACE_bloodIV_250 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_B_250";
  };
  class KAT_bloodIV_AB_250: ACE_bloodIV_250 {
    displayName = "$STR_KAT_aceCirculation_BloodIV_AB_250";
  };
  class KAT_Painkillers: ACE_ItemCore {
    scope = 1; // no mistake, just a placeholder, cause ACE can't handle magazines. DO NOT USE!
    author = "Katalam";
    displayName = "$STR_KAT_aceCirculation_Painkillers_Box_Display";
    class ItemInfo: CBA_MiscItem_ItemInfo {
        mass = 0;
    };
  };
  class KAT_X_AED: adv_aceCPR_AED {
    scope = 2;
    author = "Katalam";
    displayName = $STR_KAT_aceCirculation_X_Display;
    picture = "\kat_acecirculation\images\x-series.paa";
    model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
    descriptionShort = $STR_KAT_aceCirculation_X_Desc;
    descriptionUse = $STR_KAT_aceCirculation_X_Desc;
    class ItemInfo: CBA_MiscItem_ItemInfo {
      mass = 40;
    };
  };
  class KAT_coolBattery: ACE_ItemCore {
    scope = 2;
    author = "Katalam";
    displayName = "$STR_KAT_aceCirculation_coolBattery";
    picture = "\kat_acecirculation\images\coolBattery.paa";
    model = "\A3\Structures_F_EPA\Items\Medical\WaterPurificationTablets_F.p3d";
    descriptionShort = $STR_KAT_aceCirculation_coolBattery_desc;
    descriptionUse = $STR_KAT_aceCirculation_coolBattery_desc;
    class ItemInfo: CBA_MiscItem_ItemInfo {
      mass = 2;
    };
  };
};

class cfgMagazines {
  class CA_Magazine;
  class KAT_Painkillers: CA_Magazine {
    author = "Katalam";
    scope = 2;

    displayName = "$STR_KAT_aceCirculation_Painkillers_Box_Display";
    descriptionShort = "$STR_KAT_aceCirculation_Painkillers_DescShort";
    model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
    picture = "\kat_acecirculation\images\icon_painkillers.paa";

    ammo = "";
    count = 10;
    initSpeed = 0;
    tracersEvery = 0;
    lastRoundsTracer = 0;
    mass = 1;
  };
};

class cfgVehicles {
  class WeaponHolder_Single_limited_item_F;
  class KAT_PainkillersItem: WeaponHolder_Single_limited_item_F {
      scope = 2;
      scopeCurator = 2;
      displayName= "$STR_KAT_aceCirculation_Painkillers_Box_Display";
      author = "Katalam";
      vehicleClass = "Magazines";
      class TransportItems {
          MACRO_ADDITEM(KAT_Painkillers,1);
      };
  };
  class adv_aceCPR_AEDItem;
  class KAT_X_AEDItem: adv_aceCPR_AEDItem {
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_KAT_aceCirculation_X_Display";
    author = "[SeL] Katalam";
    class TransportItems {
        MACRO_ADDITEM(KAT_X_AED,1);
    };
	};

  class NATO_Box_Base;
	class ACE_medicalSupplyCrate: NATO_Box_Base {
		class TransportItems;
    class TransportMagazines;
	};
	class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
		class TransportItems: TransportItems {
      MACRO_ADDITEM(KAT_X_AED,1);
		};
    class TransportMagazines: TransportMagazines {
      MACRO_ADDMAGAZINE(KAT_Painkillers,10);
    };
	};
  class KAT_medicalSupplyCrate: ACE_medicalSupplyCrate {
    displayName = $STR_KAT_aceCirculation_bloodbank;
    class TransportItems: TransportItems {
      MACRO_ADDITEM(KAT_coolBattery,5);
      MACRO_ADDITEM(KAT_bloodIV_O,5);
      MACRO_ADDITEM(KAT_bloodIV_A,10);
      MACRO_ADDITEM(KAT_bloodIV_B,10);
      MACRO_ADDITEM(KAT_bloodIV_AB,10);
      MACRO_ADDITEM(KAT_bloodIV_O_500,5);
      MACRO_ADDITEM(KAT_bloodIV_A_500,10);
      MACRO_ADDITEM(KAT_bloodIV_B_500,10);
      MACRO_ADDITEM(KAT_bloodIV_AB_500,10);
      MACRO_ADDITEM(KAT_bloodIV_O_250,5);
      MACRO_ADDITEM(KAT_bloodIV_A_250,10);
      MACRO_ADDITEM(KAT_bloodIV_B_250,10);
      MACRO_ADDITEM(KAT_bloodIV_AB_250,10);
    };
  };

class Man;
	class CAManBase: Man {
		class ACE_Actions {
      class ACE_Dogtag {
        condition = "[_player, _target] call ace_dogtags_fnc_canCheckDogtag";
      };
      class ACE_Head {
        class CheckBloodPressure {}; // Remove the ability to check blood pressure at the head
        class Painkillers {
          displayName = "$STR_KAT_aceCirculation_Inject_Box_Painkillers";
          condition = "('KAT_Painkillers' in (magazines _player) || 'KAT_Painkillers' in (magazines _target))";
          statement = "[_player, _target, 'head', 'Painkillers'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
      };
      class ACE_Torso {
  			class CPR;
  			class KAT_X_AED: CPR {
  				displayName = $STR_KAT_aceCirculation_X_Action_Use;
  				condition = "[_player, _target, 'body', 'X_Defibrillator'] call ace_medical_fnc_canTreatCached";
  				statement = "[_player, _target, 'body', 'X_Defibrillator'] call ace_medical_fnc_treatment";
  				exceptions[] = {""};
  				icon = "kat_aceCirculation\images\X_Series-Device_W.paa";
  			};
        class KAT_R_X_AED: CPR {
          displayName = $STR_KAT_aceCirculation_X_Action_Remove;
          condition = "[_player, _target, 'body', 'Remove_X_Defibrillator'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'body', 'Remove_X_Defibrillator'] call ace_medical_fnc_treatment";
          exceptions[] = {""};
          icon = "kat_aceCirculation\images\X_Series-Device_W.paa"; // this is ugly xD should be changed
        };
      };
      class ACE_ArmLeft {
        #include "Blood_ArmL.hpp"
        class Access {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'hand_l', 'Access'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'hand_l', 'Access'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
        class RemoveAccess {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'hand_l', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'hand_l', 'RemoveAccess'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
      };
      class ACE_ArmRight {
        #include "Blood_ArmR.hpp"
        class Access {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'hand_r', 'Access'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'hand_r', 'Access'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
        class RemoveAccess {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'hand_r', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'hand_r', 'RemoveAccess'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
      };
      class ACE_LegLeft {
        #include "Blood_LegL.hpp"
        class Access {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'leg_l', 'Access'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'leg_l', 'Access'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
        class RemoveAccess {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'leg_l', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'leg_l', 'RemoveAccess'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
      };
      class ACE_LegRight {
        #include "Blood_LegR.hpp"
        class Access {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'leg_r', 'Access'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'leg_r', 'Access'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
        class RemoveAccess {
          displayName = $STR_KAT_aceCirculation_access_display;
          condition = "[_player, _target, 'leg_r', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
          statement = "[_player, _target, 'leg_r', 'RemoveAccess'] call ace_medical_fnc_treatment";
          showDisabled = 0;
          exceptions[] = {"isNotSitting"};
          //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
        };
      };
      class ACE_MainActions {
        class Medical {
          class ACE_Head {
            class CheckBloodPressure {}; // Remove the ability to check blood pressure at the head
            class Painkillers {
              displayName = "$STR_KAT_aceCirculation_Inject_Box_Painkillers";
              condition = "('KAT_Painkillers' in (magazines _player) || 'KAT_Painkillers' in (magazines _target))";
              statement = "[_player, _target, 'head', 'Painkillers'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
          };
          class ACE_Torso {
      			class CPR;
            class KAT_X_AED: CPR {
      				displayName = $STR_KAT_aceCirculation_X_Action_Use;
      				condition = "[_player, _target, 'body', 'X_Defibrillator'] call ace_medical_fnc_canTreatCached";
      				statement = "[_player, _target, 'body', 'X_Defibrillator'] call ace_medical_fnc_treatment";
      				exceptions[] = {""};
      				icon = "kat_aceCirculation\images\X_Series-Device_W.paa";
      			};
            class KAT_R_X_AED: CPR {
              displayName = $STR_KAT_aceCirculation_X_Action_Remove;
              condition = "[_player, _target, 'body', 'Remove_X_Defibrillator'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'body', 'Remove_X_Defibrillator'] call ace_medical_fnc_treatment";
              exceptions[] = {""};
              icon = "kat_aceCirculation\images\X_Series-Device_W.paa";
            };
          };
          class ACE_ArmLeft {
            #include "Blood_ArmL.hpp"
            class Access {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'hand_l', 'Access'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'hand_l', 'Access'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
            class RemoveAccess {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'hand_l', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'hand_l', 'RemoveAccess'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
          };
          class ACE_ArmRight {
            #include "Blood_ArmR.hpp"
            class Access {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'hand_r', 'Access'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'hand_r', 'Access'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
            class RemoveAccess {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'hand_r', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'hand_r', 'RemoveAccess'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
          };
          class ACE_LegLeft {
            #include "Blood_LegL.hpp"
            class Access {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'leg_l', 'Access'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'leg_l', 'Access'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
            class RemoveAccess {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'leg_l', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'leg_l', 'RemoveAccess'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
          };
          class ACE_LegRight {
            #include "Blood_LegR.hpp"
            class Access {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'leg_r', 'Access'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'leg_r', 'Access'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
            class RemoveAccess {
              displayName = $STR_KAT_aceCirculation_access_display;
              condition = "[_player, _target, 'leg_r', 'RemoveAccess'] call ace_medical_fnc_canTreatCached";
              statement = "[_player, _target, 'leg_r', 'RemoveAccess'] call ace_medical_fnc_treatment";
              showDisabled = 0;
              exceptions[] = {"isNotSitting"};
              //icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
            };
          };
        };
      };
    };
    class ACE_SelfActions {
      class Medical {
        class ACE_Head {
          class CheckBloodPressure {};
          class Painkillers {
            displayName = "$STR_KAT_aceCirculation_Inject_Box_Painkillers";
            condition = "'KAT_Painkillers' in (magazines _player)";
            statement = "[_player, _target, 'head', 'Painkillers'] call ace_medical_fnc_treatment";
            showDisabled = 0;
            exceptions[] = {"isNotInside", "isNotSitting"};
            icon = "kat_aceCirculation\images\icon_painkillers_action.paa";
          };
        };
      };
      class ACE_Equipment {
        class removeSound {
          displayName = "$STR_KAT_aceCirculation_X_Action_removeSound";
          condition = "'KAT_X_AED' in (items _player) && !((_player getVariable 'kat_aceCirculation_X_sound1') isEqualTo '')";
          statement = "_player setVariable ['kat_aceCirculation_X_sound1', '', true]; _player setVariable ['kat_aceCirculation_X_sound2', '', true];";
          showDisabled = 0;
          exceptions[] = {"isNotInside", "isNotSitting"};
          icon = "";
        };
        class addSound {
          displayName = "$STR_KAT_aceCirculation_X_Action_addSound";
          condition = "'KAT_X_AED' in (items _player) && ((_player getVariable 'kat_aceCirculation_X_sound1') isEqualTo '')";
          statement = "_player setVariable ['kat_aceCirculation_X_sound1', 'kat_aceCirculation\sounds\noheartrate.wav', true]; _player setVariable ['kat_aceCirculation_X_sound2', 'kat_aceCirculation\sounds\heartrate.wav', true];";
          showDisabled = 0;
          exceptions[] = {"isNotInside", "isNotSitting"};
          icon = "";
        };
      };
    };
  };
};

class ACE_Medical_Actions {
	class Advanced {
    class FieldDressing;
    class Morphine;
    class Painkillers: Morphine {
      displayName = $STR_KAT_aceCirculation_Inject_Box_Painkillers;
      displayNameProgress = $STR_KAT_aceCirculation_Using;
      allowedSelections[] = {"head"};
      items[] = {};
      callbackSuccess = "['KAT_Painkillers', _player, _target, _selectionName, 'Painkillers'] call kat_aceCirculation_fnc_removeItemfromMag";
      condition = "('KAT_Painkillers' in (magazines _player) || 'KAT_Painkillers' in (magazines _target))";
    };
    class CheckPulse;
    class CheckDogtags: checkPulse {
      displayName = $STR_KAT_aceCirculation_DogTag;
      displayNameProgress = $STR_KAT_aceCirculation_DogTag_Action;
      treatmentTime = 2;
      allowedSelections[] = {"head"};
      allowSelfTreatment = 1;
      callbackSuccess = "[_player, _target] call ace_dogtags_fnc_checkDogtag";
      condition = "true";
    };
    class CheckBloodPressure: CheckPulse { // Remove the ability to check blood pressure at the head
      allowedSelections[] = {"hand_l", "hand_r", "leg_l", "leg_r"};
    };
    #include "Blood_Medical.hpp"
    class CPR;
    class Defibrillator: CPR {
      items[] = {{"adv_aceCPR_AED", "KAT_X_AED"}};
    };
    class X_Defibrillator: CPR {
      displayName = $STR_KAT_aceCirculation_X_Action_Use;
      displayNameProgress = $STR_KAT_aceCirculation_X_Action_Progress;
      items[] = {"KAT_X_AED"};
      condition = "!(_player getVariable ['kat_aceCirculation_use',false])";
      treatmentTime = 2;
      requiredMedic = 1;
      callbackProgress = "";
      callbackSuccess = "[_player, _target] call kat_aceCirculation_fnc_treatmentAdvanced_X";
      animationCaller = "AinvPknlMstpSnonWnonDnon_medic3";
    };
    class Remove_X_Defibrillator: X_Defibrillator {
      displayName = $STR_KAT_aceCirculation_X_Action_Remove;
      items[] = {};
      condition = "_target getVariable ['kat_aceCirculation_X', true]";
      treatmentTime = 2;
      callbackProgress = "";
      callbackSuccess = "_target setVariable ['kat_aceCirculation_X', false, true]; _player setVariable ['kat_aceCirculation_use', false, true]";
    };
    class Access: FieldDressing {
      displayName = $STR_KAT_aceCirculation_access_display;
      displayNameProgress = $STR_KAT_aceCirculation_access_doing;
      items[] = {"ACE_surgicalKit"};
      category = "advanced";
      condition = "(missionNamespace getVariable ['kat_aceCirculation_access', true]) && (_target getVariable ['kat_aceCirculation_access', [0,0,0,0,0,0]] select ([_selectionName] call ace_medical_fnc_selectionNameToNumber)) == 0";
      itemConsumed = 0;
      requiredMedic = 1;
      treatmentTime = 5;
      allowedSelections[] = {"hand_l", "hand_r", "leg_l", "leg_r"};
      callbackProgress = "";
      callbackSuccess = "[_player, _target, _selectionName] call kat_aceCirculation_fnc_treatmentAdvanced_Access";
    };
    class RemoveAccess: FieldDressing {
      displayName = $STR_KAT_aceCirculation_removeAccess_display;
      displayNameProgress = $STR_KAT_aceCirculation_removeAccess_doing;
      items[] = {"ACE_surgicalKit"};
      category = "advanced";
      condition = "(missionNamespace getVariable ['kat_aceCirculation_access', true]) && (_target getVariable ['kat_aceCirculation_access', [0,0,0,0,0,0]] select ([_selectionName] call ace_medical_fnc_selectionNameToNumber)) == 1";
      itemConsumed = 0;
      requiredMedic = 1;
      treatmentTime = 5;
      allowedSelections[] = {"hand_l", "hand_r", "leg_l", "leg_r"};
      callbackProgress = "";
      callbackSuccess = "[_player, _target, _selectionName] call kat_aceCirculation_fnc_removeAccess";
    };
	};
};
class ACE_Medical_Advanced {
  class Treatment {
    class IV {
      class BloodIV;
      class BloodIV_O: BloodIV {
        bloodType = "O";
        compatibility[] = {"O", "A", "B", "AB"};
      };
      class BloodIV_A: BloodIV {
        bloodType = "A";
        compatibility[] = {"A", "AB"};
      };
      class BloodIV_B: BloodIV {
        bloodType = "B";
        compatibility[] = {"B", "AB"};
      };
      class BloodIV_AB: BloodIV {
        bloodType = "AB";
        compatibility[] = {"AB"};
      };

      class BloodIV_500;
      class BloodIV_O_500: BloodIV_500 {
        bloodType = "O";
        compatibility[] = {"O", "A", "B", "AB"};
      };
      class BloodIV_A_500: BloodIV_500 {
        bloodType = "A";
        compatibility[] = {"A", "AB"};
      };
      class BloodIV_B_500: BloodIV_500 {
        bloodType = "B";
        compatibility[] = {"B", "AB"};
      };
      class BloodIV_AB_500: BloodIV_500 {
        bloodType = "AB";
        compatibility[] = {"AB"};
      };

      class BloodIV_250;
      class BloodIV_O_250: BloodIV_250 {
        bloodType = "O";
        compatibility[] = {"O", "A", "B", "AB"};
      };
      class BloodIV_A_250: BloodIV_250 {
        bloodType = "A";
        compatibility[] = {"A", "AB"};
      };
      class BloodIV_B_250: BloodIV_250 {
        bloodType = "B";
        compatibility[] = {"B", "AB"};
      };
      class BloodIV_AB_250: BloodIV_250 {
        bloodType = "AB";
        compatibility[] = {"AB"};
      };
    };
    class Medication {
      class Atropine {
        //change for effect from Atropine. Anomalie here, if you give more it will push your heart rate
        hrIncreaseLow[] = {2, 5, 15};
        hrIncreaseNormal[] = {10, 15, 20};
        hrIncreaseHigh[] = {5, 20, 10};
      };
      class Painkillers {
        // copied from ACE. Just a reminder
        painReduce = 0.7;
        timeInSystem = 120;
        maxDose = 10;
        inCompatableMedication[] = {};
        // will push your blood pressure and leave your heart rate
        // The viscosity of a fluid is a measure of its resistance to gradual deformation by shear stress or tensile stress. For liquids, it corresponds to the informal concept of "thickness". This value will increase/decrease the viscoty of the blood with the percentage given. Where 100 = max. Using the minus will decrease viscosity
        viscosityChange = 5;
      };
    };
  };
};
