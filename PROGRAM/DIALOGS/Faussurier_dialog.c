//#include "DIALOGS\Faussurier_dialog.h"
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
		dialog.text = "Это ты хотел со мной встретиться?";
		link.l1 = "Возможно, если ты капитан Фоссурье.";
		link.l1.go = "next";
		break;

	case "next":
		dialog.text = "Ха-ха, да это действительно я. А это видимо ты, тот малый, что приструнил старика Черного Ворона, неплохо-неплохо.";
		link.l1 = "Я просто попросил старика о небольшом одолжении.";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "Хах, об одолжении? Ну-ну, Ворон просто кипит от злости. Итак, чем обязан?";
		link.l1 = "Мне известно, что несколько дней назад ты взял на абордаж судно - галиот под голландским флагом.";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "Возможно и я, а возможно и нет, ты что, охотишься за головами?";
		link.l1 = "Нет, это меня не интересует, а вот где сейчас португальская пассажирка, которую ты взял в плен с того корабля, я бы хотел узнать.";
		link.l1.go = "next4";
		break;

	case "next4":
		dialog.text = "Так это из-за этой девки ты меня искал? Ха, ей нечем было откупиться, а деньги мне нужны, поэтому я продал её одному своему знакомому, который торгует невольниками. Так что у меня её ты не найдешь, наверное она будет в каком-нибудь борделе.";
		link.l1 = "Тогда скажи мне где искать этого твоего знакомого? У губернатора Консейсао есть вопросы к этой женщине.";
		link.l1.go = "next5";
		break;

	case "next5":
		dialog.text = "Боюсь, просто так сказать, где он находится я тебе не смогу. Он работает через посредников.";
		link.l1 = "Ты же понимаешь, что я буду искать ответа любым способом.";
		link.l1.go = "next6";
		break;

	case "next6":
		dialog.text = "Хмм, возможно да, я думал об этом, я могу сделать для тебя исключение, но только если ты поможешь мне в одном деле.";
		link.l1 = "Что за дело?";
		link.l1.go = "next7";
		break;

	case "next7":
		dialog.text = "А дело такое, есть один человек, обеспечением безопасности которого я занимаюсь, однако он, видимо, не ценит мои услуги и, соответственно, задолжал мне определенную сумму - 1500 пиастров";
		link.l1.go = "next8";
		break;

	case "next8":
		dialog.text = "После штурма Оксбэя нашими, мне на английские колонии путь заказан, а деньги, как ты понимаешь нужны, вот мне и пригодится твоя помощь.";
		link.l1 = "А что это за человек, и на какой калонии мне его искать?";
		link.l1.go = "next9";
		break;

	case "next9":
		dialog.text = "Это Бен Валлиец - судовладелец, живет в Рэдмонде, думаю он вряд ли захочет расставаться с деньгами, и его на самом деле, можно понять - деньги сейчас нужны всем, но тем не менее он должен понять как важна безопасность.";
		link.l1.go = "next10";
		break;

	case "next10":
		dialog.text = "Там в акватории Рэдмонда, будет его яхта 'Кадваллон', ты наглядно покажешь, как в наше время необходима защита, то что будет на корабле и само судно, если возьмешь на абордаж, можешь оставить себе, потом вернешься к Бену, думаю он будет посговорчивее.";
		link.l1 = "А если я заплачу те же деньги тебе сразу?";
		link.l1.go = "next11";
		break;

	case "next11":
		dialog.text = "Дело не в деньгах, Валлиец должен понять, что я нужен ему. Я ещё дальше планирую с ним работать, поэтому важно, чтобы он остался в живых.";
		link.l1 = "Как скажешь.";
		link.l1.go = "Exit";
		break;

	case "diag3":

	dialog.text = "В этих водах ты должен быть готов ко всему.";
	link.l1 = "...";
		link.l1.go = "Exit1";
		break;

	case "Exit1":
	    DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		NextDiag.TempNode = "diag3";
		break;

    case "Exit":
		AddQuestRecord("PortuguezeLine", “12”); //Добавить в журнал запись
		AddDialogExitQuest("LessonForBen");
		NextDiag.TempNode = "diag3";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
	}
}