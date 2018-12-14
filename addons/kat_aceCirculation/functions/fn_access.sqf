/*
 * Author: Katalam
 * Add a access point to a given selection of a given patient.
 *
 * Arguments:
 * 0: Patient <OBJECT>
 * 1: Selectionname <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorTarget, "hand_l"] call kat_aceCirculation_fnc_access;
 *
 * Public: No
 */

params ["_target", "_selectionName"];

private _access = _target getVariable ['kat_aceCirculation_access', [0,0,0,0,0,0]];
_access set [[_selectionName] call ace_medical_fnc_selectionNameToNumber, 1];
_target setVariable ['kat_aceCirculation_access', _access, true];
