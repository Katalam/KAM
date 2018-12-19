/*
 * Author: Katalam
 * Remove access point to a given selection of a given patient.
 *
 * Arguments:
 * 0: Patient <OBJECT>
 * 1: Selectionname <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorTarget, "hand_l"] call kat_aceCirculation_fnc_removeAccess;
 *
 * Public: No
 */

params ["", "_target", "_selectionName"]; //0: _player

private _access = _target getVariable ['kat_aceCirculation_access', [0,0,0,0,0,0]];
_access set [[_selectionName] call ace_medical_fnc_selectionNameToNumber, 0];
_target setVariable ['kat_aceCirculation_access', _access, true];

if ({_x > 0} count _access == 0) then {
  _target forceWalk false;
};

/*
private _location = "";
switch (_selectionName) do {
  case ("hand_l"): {
    _location = "STR_ACE_Medical_LeftArm";
  };
	case ("hand_r"): {
		_location = "STR_ACE_Medical_RightArm";
	};
	case ("leg_l"): {
		_location = "STR_ACE_Medical_LeftLeg";
	};
	case ("leg_r"): {
		_location = "STR_ACE_Medical_RightLeg";
	};
};

// medical log
[_target, "activity", "STR_KAT_aceCirculation_access_log", [[_player] call ace_common_fnc_getName, _location]] call ace_medical_fnc_addToLog;
[_target, "activity_view", "STR_KAT_aceCirculation_access_log", [[_player] call ace_common_fnc_getName, _location]] call ace_medical_fnc_addToLog;
*/
