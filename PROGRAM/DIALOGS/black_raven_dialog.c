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
		Dialog.snd = "dialogs\0\009";
		if (CheckQuestAttribute("amanda_status", "searchFraCorsair"))
		{
			dialog.text = "Чего тебе, парень?";
			link.l1 = "Я ищу капитана шхуны 'Прозерпина', мне известно, что ты мне можешь помочь.";
			link.l1.go = "next";
		}
		else
		{
			dialog.snd = "Voice\BUCH\BUCH001";
			dialog.text = "Топай дальше приятель.";
			link.l1 = "...";
			link.l1.go = "Exit1";
		}
		break;

	case "next":
		dialog.text = "Я действительно знаю капитана Фоссурье, но с чего ты взял, что я буду тебе помогать в его поисках?";
		link.l1 = "Я действую по поручению губернатора португальской колонии, сеньора Баррето, так что рекомендую ответить прямо, где я могу найти француза?";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "Послушай сюда, щенок, мне плевать по чьему поручению ты действуешь! Катись отсюда к чертовой матери, пока цел, или я в миг нарисую тебе новую улыбку.";
		link.l1 = "Я не уйду отсюда пока не узнаю где сейчас находится твой приятель.";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "Гром и молния! Этот пес окончательно вывел меня из себя! Эй, ребята, я хочу увидеть потраха этого щенка, разберитесь с ним!";
		link.l1.go = "next4";
		break;


	case "diag3":
		dialog.text = "Разрази меня гром! Ты прирезал их обоих!";
		link.l1 = "Теперь ты будешь сговорчивее, каналья?";
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
		dialog.text = "Ах ты щенок! Ты бы окончил свои дни прямо здесь, но я настолько пьян, что не могу достать саблю.";
		link.l1 = "У тебя нет никакой сабли, старый маразматик. Говори где находится корсар Фоссурье, или ты сейчас же отправишься к праотцам, вслед за своими дружками!";
		link.l1.go = "next6";
		break;

	case "next6":
		dialog.text = "Ну, а где, может находиться лягушатник на этом архипелаге, как ни на Фале-Де-Флер, пустая твоя башка!";
		link.l1 = "Я что, по всему острову буду там искать его? Ты отправляешься со мной, старик, устроишь нам встречу тет-а-тет, и только попробуй выкинуть какую-нибудь шутку по пути, сразу же отправишься кормить акул.";
		link.l1.go = "next7";
		break;

	case "next7":
		dialog.text = "Кар-р-рамба! Мне только этого еще не хватало!";
		link.l1 = "Все могло быть иначе, если бы ты сразу мне все сказал.";
		link.l1.go = "next8";
		NextDiag.TempNode = "diag4";
		NextDiag.CurrentNode = NextDiag.TempNode;

		break;

	case "next8":
		AddQuestRecord("PortuguezeLine", “10”); //Добавить в журнал запись
		AddDialogExitQuest("goToFaussurier");
		DialogExit();
		break;

	case "diag4":
		if (CheckQuestAttribute("foussur3", "searchFaussurierInTavernFF234"))
		{
			dialog.text = "Так, ладно, теперь идем в таверну, там я назначу встречу с Ферланом.";
			link.l1 = "Идем.";
			link.l1.go = "next9";
			NextDiag.TempNode = "diag5";
			NextDiag.CurrentNode = NextDiag.TempNode;
		}

		else
		{
			dialog.text = "Давай уже быстрее покончим с этим делом.";
			link.l1.go = "Exit1";
		}
		break;

	case "diag5":
		if (CheckQuestAttribute("foussur3", "searchFaussurierInTavernFF235"))
		{
			NextDiag.TempNode = "next11";
			NextDiag.CurrentNode = NextDiag.TempNode;
			dialog.text = "Я передам весточку Фоссурье, смотри не вмешивайся.";
			link.l1 = "Пошевеливайся, старик.";
			link.l1.go = "next10";
		}
		else
		{
			dialog.text = "Так, ладно, теперь идем в таверну, там я назначу встречу с Ферланом.";
			link.l1 = "Идем.";
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
		dialog.text = "Я свое дело сделал, капитан Фоссурье будет тебя ждать ночью, в порту, около доков, найдешь его сам.";
		link.l1 = "Нет, старик, ты не уйдешь от меня пока я не увижу корсара.";
		link.l1.go = "next12";
		AddQuestRecord("PortuguezeLine", “11”);
		break;

	case "next12":
		NextDiag.TempNode = "diag4";
		NextDiag.CurrentNode = NextDiag.TempNode;
		dialog.text = "Карамба, ты просто невыносим!";
		link.l1.go = "next13";
		break;

	case "next13":
		AddDialogExitQuest("meetFaussurier3");
		DialogExit();
		break;
	}
}