#include "DIALOGS\Gonsalo Saras_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();


	switch (Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
	case "First time":

		Dialog.defAni = "dialog_stay1";
		Dialog.defCam = "1";
		Dialog.defSnd = "dialogs\0\017";
		Dialog.defLinkAni = "dialog_1";
		Dialog.defLinkCam = "1";
		Dialog.defLinkSnd = "dialogs\woman\024";
		Dialog.ani = "dialog_stay2";
		Dialog.cam = "1";

		dialog.snd = "Voice\BUCH\BUCH001";
		dialog.text = "���� ���� ���� � ���� ����?";
		link.l1 = "� ��� ���� ��������, �� �������� �� ����� �����?";
		link.l1.go = "next";

		break;

	case "next":
		dialog.text = "� � ���� ��� �������, ���� ����?";
		link.l1 = "� �� �������� ��������, �� ������ ������� ��� �����, �� ����������� ����� ������������.";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "� ��� ������� ������ �����������, ��� ��� �� ����� ������� ��� ������, � ��� ��������� �� ������ ������. � �� ����� ��������� ��������� � ������, � ������ �� ����������� ��� �� ���������� ������.";
		link.l1 = "�� ����� ����, � ���� �����, ������ ������� ��������, ������ ������ ���� �� ����� ������, ���. ��� ��� � �� ������� ��� ������������ ����� ��������.";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "�� �� �, ����� � ���-�� ������! ������ ������, ���� � �� ������� ������, � ������� ������ �����������, ��� �� �� ���������� �� ��� ������ ������� �� ����� �������, � ������ �� �������� ���� ����� �����!";		
		link.l1 = "�����, �������� �������� ����� �� ����������� ��� �����, � ��� �������, ��� � ���� ��� �������� ���������.";
		link.l1.go = "Exit";
		break;	

	case "diag3":		
		if (CheckQuestAttribute("IsBenWalesLostHisShip", "Yes"))
		{
			dialog.text = "�� ������������ �������, �� �������� ����� ���, ���� ������� �������� ��� ������� � ��� ���!?";
			link.l1 = "� ���� ������������, ��� ����� ���� ������� �����, �� �� ������ ���� �����, � ����������� ������ �������.";
			link.l1.go = "dialog1";
		}
		else
		{
			dialog.text = "������ ������!";
			link.l1 = "....";
			link.l1.go = "Exit1";
		}
		break;

	case "Exit1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;		
		NextDiag.TempNode = "diag3"
		break;

	case "Exit":
		AddQuestRecord("PortuguezeLine", �13�); //�������� � ������ ������
		AddDialogExitQuest("ShipOfBenWales");		
		NextDiag.TempNode = "diag3"
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

	case "dialog1":
		dialog.text = "������ ����� ������� �������, ����� ������ ���� ������� �����!";
		link.l1 = "����� �� ����������, ���, ������. ��� ��� ���?";
		link.l1.go = "dialog2";
		break;

	case "dialog2":
		//ChangeCharacterAddressGroup(characterFromID("BenWalesGuard"), "Redmond_HouseInsideR2", "goto", "goto2");
		AddDialogExitQuest("DisgruntledBenWales");				
		DialogExit();
		break;
	}
}