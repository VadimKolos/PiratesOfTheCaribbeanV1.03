#include "DIALOGS\Gonsalo Saras_dialog.h" //v 1.03
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
		Dialog.snd = "dialogs\0\009";
		if (CheckQuestAttribute("amanda_status", "searchFraCorsair"))
		{
			dialog.text = "���� ����, ������?";
			link.l1 = "� ��� �������� ����� '����������', ��� ��������, ��� �� ��� ������ ������.";
			link.l1.go = "next";
		}
		else
		{
			dialog.snd = "Voice\BUCH\BUCH001";
			dialog.text = "����� ������ ��������.";
			link.l1 = "...";
			link.l1.go = "Exit1";
		}
		break;

	case "next":
		dialog.text = "� ������������� ���� �������� ��������, �� � ���� �� ����, ��� � ���� ���� �������� � ��� �������?";
		link.l1 = "� �������� �� ��������� ����������� ������������� �������, ������� �������, ��� ��� ���������� �������� �����, ��� � ���� ����� ��������?";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "�������� ����, �����, ��� ������� �� ����� ��������� �� ����������! ������ ������ � �������� ������, ���� ���, ��� � � ��� ������� ���� ����� ������.";
		link.l1 = "� �� ���� ������ ���� �� ����� ��� ������ ��������� ���� ��������.";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "���� � ������! ���� ��� ������������ ����� ���� �� ����! ��, ������, � ���� ������� ������� ����� �����, ����������� � ���!";
		link.l1.go = "next4";
		break;


	case "diag3":
		dialog.text = "������� ���� ����! �� �������� �� �����!";
		link.l1 = "������ �� ������ �����������, �������?";
		link.l1.go = "next5";
		break;

	case "Exit1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		//NextDiag.TempNode = "diag3"
		break;

	case "next4":
		AddDialogExitQuest("disgruntledRaven");
		NextDiag.TempNode = "diag3"
			NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

	case "next5":
		dialog.text = "�� �� �����! �� �� ������� ���� ��� ����� �����, �� � ��������� ����, ��� �� ���� ������� �����.";
		link.l1 = "� ���� ��� ������� �����, ������ ����������. ������ ��� ��������� ������ ��������, ��� �� ������ �� ����������� � ��������, ����� �� ������ ��������!";
		link.l1.go = "next6";
		break;

	case "next6":
		dialog.text = "��, � ���, ����� ���������� ���������� �� ���� ����������, ��� �� �� ����-��-����, ������ ���� �����!";
		link.l1 = "� ���, �� ����� ������� ���� ��� ������ ���? �� ������������� �� ����, ������, �������� ��� ������� ���-�-���, � ������ �������� �������� �����-������ ����� �� ����, ����� �� ����������� ������� ����.";
		link.l1.go = "next7";
		break;

	case "next7":
		dialog.text = "���-�-�����! ��� ������ ����� ��� �� �������!";
		link.l1 = "��� ����� ���� �����, ���� �� �� ����� ��� ��� ������.";
		link.l1.go = "next8";
		NextDiag.TempNode = "diag4";
		NextDiag.CurrentNode = NextDiag.TempNode;

		break;

	case "next8":
		AddQuestRecord("PortuguezeLine", �10�); //�������� � ������ ������
		AddDialogExitQuest("goToFaussurier");
		DialogExit();
		break;

	case "diag4":
		if (CheckQuestAttribute("foussur3", "searchFaussurierInTavernFF234"))
		{
			dialog.text = "���, �����, ������ ���� � �������, ��� � ������� ������� � ��������.";
			link.l1 = "����.";
			link.l1.go = "next9";
			NextDiag.TempNode = "diag5";
			NextDiag.CurrentNode = NextDiag.TempNode;
		}

		else
		{
			dialog.text = "����� ��� ������� �������� � ���� �����.";
			link.l1.go = "Exit1";
		}
		break;

	case "diag5":
		if (CheckQuestAttribute("foussur3", "searchFaussurierInTavernFF235"))
		{
			NextDiag.TempNode = "next11";
			NextDiag.CurrentNode = NextDiag.TempNode;
			dialog.text = "� ������� �������� ��������, ������ �� ����������.";
			link.l1 = "�������������, ������.";
			link.l1.go = "next10";
		}
		else
		{
			dialog.text = "���, �����, ������ ���� � �������, ��� � ������� ������� � ��������.";
			link.l1 = "����.";
			link.l1.go = "Exit1";
		}
		break;

	case "next9":
		AddDialogExitQuest("goToFaussurierInFFTavern");
		DialogExit();
		break;

	case "next10":
		LAi_SetCitizenType(characterFromID("black_raven"));
		AddDialogExitQuest("meetFaussurier");
		DialogExit();
		break;

	case "next11":
		dialog.text = "� ���� ���� ������, ������� �������� ����� ���� ����� �����, � �����, ����� �����, ������� ��� ���.";
		link.l1 = "���, ������, �� �� ������ �� ���� ���� � �� ����� �������.";
		link.l1.go = "next12";
		AddQuestRecord("PortuguezeLine", �11�);
		break;

	case "next12":
		NextDiag.TempNode = "diag4";
		NextDiag.CurrentNode = NextDiag.TempNode;
		dialog.text = "�������, �� ������ ���������!";
		link.l1.go = "next13";
		break;

	case "next13":
		AddDialogExitQuest("meetFaussurier3");
		DialogExit();
		break;
	}
}