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
		// -----------------------------------Диалог первый - первая встреча
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
			dialog.text = "Прошу прощения, cеньор, это не ваше судно стоит на рейде?";
			link.l1 = "Именно. У вас ко мне какое-то дело, сеньора..?";
			link.l1.go = "next";
		break;

	case "next":

		dialog.text = "Аманда Медейруш.";
		link.l1 = "Очень приятно, Аманда, я - капитан Натаниэль Хаук. И так чем могу помочь?";
		link.l1.go = "next2";
		break;

	case "next2":

		dialog.text = "Я бы хотела добраться до Дувезена, как можно скорее. По прибытии, вы получите 2000 пиастров. Возьмете пассажира?";
		link.l1 = "Думаю, я согласен сеньора. Добро пожаловать на борт.";		
		link.l1.go = "next3";
		link.l12 = "Боюсь у меня не будет места для пассажиров. Мне очень жаль.";
		link.l12.go = "Exit";		
		NextDiag.TempNode = "diag3"
		break;	

	case "next3":
		
		dialog.text = "Благодарю, капитан. Вы очень любезны.";
		link.l1 = "Не стоит, сеньора.";
		link.l1.go = "Exit1";
		NextDiag.TempNode = "diag3"
	break;

	case "diag3":

		dialog.text = "Какие-то вопросы, сеньор?";
		link.l1 = "Да, сеньора, вы кажется хотели куда-то добраться?";
		link.l1.go = "next2";

		break;

	case "next4":

		dialog.text = "Благодарю вас, Натаниэль. Однако, у меня, к сожалению, возникли проблемы с оплатой. Я могу вам дать только тысячу пиастров и этот изумруд.";
		link.l1 = "Хм, мы так не договаривались.";
		link.l1.go = "next5";
		
		break;

	case "next5":
		dialog.text = "Бросьте, капитан. Вы ведь все равно в убытке не останитесь. Тем более у меня больше ничего нет.";
		link.l1 = "Ладно, не буду распаляться по мелочам";
		link.l1.go = "next6";
		break;

	case "next6":
		AddQuestRecord("AmandaQuest", “2”); //Добавить в журнал запись
		AddDialogExitQuest("AmandaLeaveDou");		
		AddDialogExitQuest("LessonForBen");//УДОЛИТЬ!!!!!!
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("MainPortugalLineQuest1");
		break;

	case "Exit1":
		AddQuestRecord("AmandaQuest", “1”); //Добавить в журнал запись
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