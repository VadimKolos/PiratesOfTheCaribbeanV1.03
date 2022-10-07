#include "DIALOGS\PortugalQuestSoldier.h"
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
			dialog.text = "��������, c�����, ��� ���� ����� ����� �� �����?";
			link.l1 = "��, ���. �����-�� �������?";

			link.l1.go = "next";
		break;

	case "next":

		dialog.text = "��, ������, �������� ���������� ����� ������ ��� ��������� ��������, �� ������ ���������� ������� �� ������� ������ � ���������, �������� ������ �� ����, �������.";
		link.l1 = "����� ��������, ��������, �� � ���� ���� ������ �����, � �� ��������� �������� ������� ����-���� ���� � ����.";
		link.l1.go = "next2";
		
		
		break;

	case "next2":
		dialog.text = "��� ��� ����� ������, ������, �� ������, � �� �� ����� ����� ����������� ���� �����������, � ��������, ��� ���� ����� ��������� ��� ��� ��� ������� �����, � ������ �� ����� ��� � ��� ���� �����.";
		link.l1 = "��� � ���� ��������� �����������, �������� ��� � ������� �������� �������� ��������� �����������. ����.";		
		link.l1.go = "Exit";		
		AddQuestRecord("PortuguezeLine", �1�);
		break;	


	case "Exit":
		LAi_SetCitizenType(characterFromID("PortugalQuestSoldier"));
		AddDialogExitQuest("GoToPurtuguezeTownhall");		
		DialogExit();
		break;

	}
}