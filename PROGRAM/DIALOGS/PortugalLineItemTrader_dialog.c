#include "DIALOGS\Item Trader_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Items":
			if(CheckAttribute(Pchar, "quest.tutorial.Spyglass"))
			{
				TakeNItems(Npchar,"blade1", Rand(4)+1);
				TakeNItems(Npchar,"blade2", Rand(4)+1);
				TakeNItems(Npchar,"blade3", Rand(4)+1);
				TakeNItems(Npchar,"blade4", Rand(4)+1);
				TakeNItems(Npchar,"blade5", Rand(4)+1);

				TakeNItems(Npchar,"spyglass2", 1);
				TakeNItems(Npchar,"potion1", Rand(10)+1);
				TakeNItems(Npchar,"potion2", Rand(3)+1);
				
				TakeNItems(Npchar,"jewelry1", Rand(4)+1);
				TakeNItems(Npchar,"jewelry2", Rand(4)+1);
				TakeNItems(Npchar,"jewelry4", Rand(4)+1);
				TakeNItems(Npchar,"indian4", Rand(4)+1);
				TakeNItems(Npchar,"indian13", Rand(4)+1);
				
			//	DeleteAttribute(Pchar, "quest.tutorial.Spyglass");
			}
			else
			{
				if (npchar.quest.Meeting != lastspeak_date)
				{
					GiveItemToTrader(npchar);
					npchar.quest.Meeting = lastspeak_date;
				}
			}
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Items";						
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "exit";	
			if (CheckQuestAttribute("portuguese_line", "DeadFerrara"))
			{
				link.l4 = "У меня есть к вам несколько вопросов.";
				link.l4.go = "portugalLineStart2";
			}
		break;

		case "portugalLineStart2":
			d.Text = "Что вы хотели, капитан?";
			Link.l1 = "Скажите, вы были на этом месте в день, когда произошло убийство в доме ростовщика?";
			Link.l1.go = "portugalLineStart3";
			break;

		case "portugalLineStart3":
			d.Text = "Да, сэр. Такой ужас, средь бела людей режут, и куда только смотрят наши стражники? Как-будто для вида стоят. Даром их только держат на наши налоги.";
			Link.l1 = "Я занимаюсь расследованием этого убийства. Скажите пожалуйста как обнаружили тело убитого?";
			Link.l1.go = "portugalLineStart4";
			break;

		case "portugalLineStart4":
			d.Text = "Так ростовщик-то наш и обнаружил. Как вернулся сразу крик такой поднял, да как ошпаренный на улицу выскачил, стал стражу звать.";
			Link.l1 = "Значит во время убийства сэра Праудфута не было в доме?";
			Link.l1.go = "portugalLineStart5";
			break;

		case "portugalLineStart5":
			d.Text = "Нет не было. Он с утра вышел и его потом полдня не было.";
			Link.l1 = "А после того как сэр Праудфут покинул свой дом, туда заходил кто-нибудь?";
			Link.l1.go = "portugalLineStart6";
			break;

		case "portugalLineStart6":
			d.Text = "В том-то и дело что заходил, был там какой-то подозрительный тип - моряк, одежда у него была морская, точнее как капитан он был одет, мне он сразу показался подозрительным, правда я ничего не слышала.";
			Link.l1 = "Он был последний кто туда заходил?";
			Link.l1.go = "portugalLineStart7";
			break;
		case "portugalLineStart7":
			d.Text = "Да, капитан, после него, вроде никто не заходил. Ну разве что сам мистер Праудфут.";
			Link.l1 = "Что ж, понятно.";
			Link.l1.go = "portugalLineStart8";
			break;
		case "portugalLineStart8":
			AddDialogExitQuest("FerraraWasKilledInfo");
			AddQuestRecord("PortuguezeLine", “5”);
			DialogExit();
			break;
	}
}