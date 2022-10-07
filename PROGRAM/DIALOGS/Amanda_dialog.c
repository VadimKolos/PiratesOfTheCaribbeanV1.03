#include "DIALOGS\Amanda_dialog.h"
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
			dialog.text = "����� ��������, c�����, ��� �� ���� ����� ����� �� �����?";
			link.l1 = "������. � ��� �� ��� �����-�� ����, �������..?";
			link.l1.go = "next";
		break;

	case "next":

		dialog.text = "������ ��������.";
		link.l1 = "����� �������, ������, � - ������� ��������� ����. � ��� ��� ���� ������?";
		link.l1.go = "next2";
		break;

	case "next2":

		dialog.text = "� �� ������ ��������� �� ��������, ��� ����� ������. �� ��������, �� �������� 2000 ��������. �������� ���������?";
		link.l1 = "�����, � �������� �������. ����� ���������� �� ����.";		
		link.l1.go = "next3";
		link.l12 = "����� � ���� �� ����� ����� ��� ����������. ��� ����� ����.";
		link.l12.go = "Exit";		
		NextDiag.TempNode = "diag3"
		break;	

	case "next3":
		
		dialog.text = "���������, �������. �� ����� �������.";
		link.l1 = "�� �����, �������.";
		link.l1.go = "Exit1";
		NextDiag.TempNode = "diag3"
	break;

	case "diag3":

		dialog.text = "�����-�� �������, ������?";
		link.l1 = "��, �������, �� ������� ������ ����-�� ���������?";
		link.l1.go = "next2";

		break;

	case "next4":

		dialog.text = "��������� ���, ���������. ������, � ����, � ���������, �������� �������� � �������. � ���� ��� ���� ������ ������ �������� � ���� �������.";
		link.l1 = "��, �� ��� �� ��������������.";
		link.l1.go = "next5";
		
		break;

	case "next5":
		dialog.text = "�������, �������. �� ���� ��� ����� � ������ �� ����������. ��� ����� � ���� ������ ������ ���.";
		link.l1 = "�����, �� ���� ����������� �� �������";
		link.l1.go = "next6";
		break;

	case "next6":
		AddQuestRecord("AmandaQuest", �2�); //�������� � ������ ������
		AddDialogExitQuest("AmandaLeaveDou");		
		AddDialogExitQuest("LessonForBen");//�������!!!!!!
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("MainPortugalLineQuest1");
		break;

	case "Exit1":
		AddQuestRecord("AmandaQuest", �1�); //�������� � ������ ������
		AddDialogExitQuest("AmandaSit");
		AddDialogExitQuest("AmandaInDou");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "Exit":
		LAi_SetCitizenType(characterFromID("Amanda"));
		DialogExit();		
		NextDiag.TempNode = "diag3"
	    NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}