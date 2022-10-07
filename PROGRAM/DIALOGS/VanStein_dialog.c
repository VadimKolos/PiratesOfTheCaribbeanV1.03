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
		dialog.text = "Чем обязан, парень?";
		link.l1 = "Вы каптан Ван Стейн?";
		link.l1.go = "next";

		break;

	case "next":
		dialog.text = "Да, а ты кто такой?";
		link.l1 = "Мое имя Натаниэль Хаук. Я пришел к вам по поводу женщины по имени Аманда Медейруш, она должна была плыть с вами как пассажир.";
		link.l1.go = "next2";
		break;

	case "next2":
		dialog.text = "Да, ей необходимо было попасть на Рэдмонд, а я как раз должен был доставить груз паприки туда...";
		link.l1 = "Но что-то пошло не так?";
		link.l1.go = "next3";
		break;

	case "next3":
		dialog.text = "Гром и молния! Да это плавание обернулось самым настоящим кошмаром! Вот уж правда говорят: 'Женщина на корабле - быть беде'. По началу все шло прекрасно, нам дул попутный ветер, погода была ясная, козалось что ничто не предвещает беды.";		
		link.l99.go = "next4";
		break;

	case "next4":
		dialog.text = "Пока, на следующий день плавания, на горизонте не показалась шхуна, которая быстро стала сближаться с нами. Я сразу заподозрил неладное, но они шли под голландским флагом, и к тому же нам нужно было пополнить запас пресной воды, я подумал, что стоит поторговать с ними.";
		link.l1.go = "next5";
		break;

	case "next5":
		dialog.text = "Но как бы ни так. Едва они поравнялись с нами борт о борт, так сразу же дали бортовой залп книппелями, такой выстрел просто разорвал наше парусное вооружение и такелаж. Мой галиот был конечно побыстрее пиратской шхуны, но с полным трюмом специй и без парусов особо не разгонишься.";
		link.l1.go = "next6";
		break;

	case "next6":
		dialog.text = "Тогда я решил дать бой пиратам. Я сразу скомандовал свистать всех наверх мы дали один залп, но шхуна прошла мимо нас, сделала поворот оверштаг и дала залп картечью, после следующего такого залпа, когда они выкосили большую часть нашей команды, я понял, что наше дело труба и приказал вывесить белый флаг.";
		link.l1.go = "next7";
		break;

	case "next7":
		dialog.text = "Пираты забрали весь груз, что был на корабле и обшарили все сундуки - ничего не оставили, кроме наших жизней. Мне пришлось вернуться на Дувезен. И сейчас, я даже не знаю на что мне ремонтировать судно.";
		link.l1 = "А что стало с вашей пассажиркой?";
		link.l1.go = "next8";
		break;

	case "next8":
		dialog.text = "Пираты нашли её в трюме и забрали, мне даже страшно подумать о её дальнейшей судьбе.";
		link.l1 = "Как звали капитана пиратского корабля?";
		link.l1.go = "next9";
		break;

	case "next9":
		dialog.text = "Этого я не знаю, я не понял кто из их шайки капитан.";
		link.l1 = "Как называлось пиратское судно?";
		link.l1.go = "next10";
		break;

	case "next10":
		dialog.text = "Шхуна плыла под названием 'Прозерпина'.";
		link.l1 = "Это уже что-то, попробую найти эту шхуну.";
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
		NextDiag.TempNode = "diag3"
			break;

	case "Exit":
		AddQuestRecord("PortuguezeLine", “9”); //Добавить в журнал запись
		AddDialogExitQuest("StolenAmanda");		
		NextDiag.TempNode = "diag3"
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
	}
}