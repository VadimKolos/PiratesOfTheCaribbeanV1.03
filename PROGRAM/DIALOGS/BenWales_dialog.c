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
		dialog.text = "Чего тебе надо в этом доме?";
		link.l1 = "Я ищу Бена Валлийца, он случайно не здесь живет?";
		link.l1.go = "next";

		break;

	case "next":
		dialog.text = "Я и есть Бен Валлиец, чего надо?";
		link.l1 = "Я от капитана Фоссурье, по поводу отплаты его услуг, по обеспечению вашей безопасности.";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "Я уже говорил твоему лягушатнику, что мне не нужны никакие его услуги, я сам справлюсь со своими делами. А уж после вторжения французов в Оксбэй, я вообще не представляю что он собирается делать.";
		link.l1 = "На самом деле, в этих водах, просто кишащих пиратами, лишняя помощь была бы очень кстати, сэр. Так что я бы подумал над предложением месье Фоссурье.";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "Ты не я, чтобы о чем-то думать! Катись отсюда, пока я не кликнул солдат, и передай своему лягушатнику, что бы он проваливал на все четыре стороны со своей помощью, и больше не присылал сюда своих людей!";		
		link.l1 = "Боюсь, капитану Фоссурье очень не понравиться ваш ответ, и мне кажется, нам с вами еще придется увидиться.";
		link.l1.go = "Exit";
		break;	

	case "diag3":		
		if (CheckQuestAttribute("IsBenWalesLostHisShip", "Yes"))
		{
			dialog.text = "Ты отмороженный ублюдок, ты безумный сукин сын, тебе хватило наглости еще явиться в мой дом!?";
			link.l1 = "Я тебя предупреждал, все можно было уладить мирно, но ты сделал свой выбор, и последствия твоиих решений.";
			link.l1.go = "dialog1";
		}
		else
		{
			dialog.text = "Катись отсюда!";
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
		AddQuestRecord("PortuguezeLine", “13”); //Добавить в журнал запись
		AddDialogExitQuest("ShipOfBenWales");		
		NextDiag.TempNode = "diag3"
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

	case "dialog1":
		dialog.text = "Закрой пасть чертово отродье, этому должен быть положен конец!";
		link.l1 = "Лучше не распыляйся, Бен, остынь. Это еще кто?";
		link.l1.go = "dialog2";
		break;

	case "dialog2":
		//ChangeCharacterAddressGroup(characterFromID("BenWalesGuard"), "Redmond_HouseInsideR2", "goto", "goto2");
		AddDialogExitQuest("DisgruntledBenWales");				
		DialogExit();
		break;
	}
}