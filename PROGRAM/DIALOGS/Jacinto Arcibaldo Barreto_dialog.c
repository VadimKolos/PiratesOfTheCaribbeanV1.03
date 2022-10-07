
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
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

			if (npchar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[0] + npchar.name + " " + npchar.middlename + " " + npchar.lastname + DLG_TEXT[1] + address_form.spa + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				Link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}

			if (pchar.quest.portuguese_line == "started")
			{
				dialog.text = "Так значит это вы капитан Хаук? Вы догадываетесь по какой причине я хотел чтобы вы навестили меня?";
				link.l1 = "Не думаю, сеньор.";
				link.l1.go = "portugLine1";
			}

			else
			{
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "quests";
				link.l2 = DLG_TEXT[7];
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests": /*ветка "Да, у меня есть одно дело для вас, капитан - и в чем же оно заключается?" добавлен кейс с помощью link.l2 (l2) */
			dialog.text = DLG_TEXT[13] + address_form.spa + DLG_TEXT[14];
			if (CheckQuestAttribute("portuguese_line", "wait"))
			{
				link.l2 = "Я по поводу расследования исчезновения ростовщика.";
				link.l2.go = "portugLine5.3";
			}
			if (CheckQuestAttribute("portuguese_line", "DeadFerraraInfo"))
			{
				link.l2 = "Я по поводу расследования исчезновения ростовщика.";
				link.l2.go = "portugLine7";
			}
			if (!CheckAttribute(pchar, "quest.generate_kill_quest") && GetNationRelation2MainCharacter(PORTUGAL) != RELATION_ENEMY)
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "kill_pirate";
			}			
			if (CheckQuestAttribute("generate_kill_quest", "completed"))
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "kill_pirate_completed";
			}
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win") || CheckQuestAttribute("nigel_con_parri_checker", "win"))
			{
				link.l2 = DLG_TEXT[15];
				link.l2.go = "garri";
			}		
			link.l99 = DLG_TEXT[20];
			link.l99.go = "exit";
		break;
		
		case "kill_pirate":
			GeneratePirateQuest();
			dialog.text = DLG_TEXT[21] + characters[GetCharacterIndex(DLG_TEXT[22])].ship.name + DLG_TEXT[23] + LanguageConvertString(g_LocLngFileID, pchar.quest.killdestination) + DLG_TEXT[24] + pchar.quest.killmoney + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "kill_pirate_agree";
			link.l2 = DLG_TEXT[27];
			link.l2.go = "kill_pirate_refused";
		break;
		
		case "kill_pirate_agree":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kill_pirate_agree");
		break;
		
		case "kill_pirate_refused":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kill_pirate_refused");
		break;
		
		case "kill_pirate_completed":
			AddPartyExp(pchar, 1500);
			AddMoneyToCharacter(pchar, makeint(pchar.quest.killmoney));
			AddDialogExitQuest("kill_pirate_refused_2");
			ChangeCharacterReputation(pchar, 1);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.generate_kill_quest = "wait_timer";
		break;
		
		case "garri":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "garri_2";
		break;
		
		case "garri_2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win"))
			{
				link.l1.go = "garri_3";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestrecord("nigel", "15");
			DeleteAttribute(PChar, "quest.nigel_con_parri_checker");
			PChar.quest.con_parri_expired.over = "yes";
			AddMoneyToCharacter(pchar, 3000);
			ChangeCharacterReputation(pchar, 1);
			AddDialogExitQuest("nigel_third_encounter");
		break;
		
		case "garri_3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "garri_4";
		break;
		
		case "garri_4":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 6000);
			ChangeCharacterReputation(pchar, 1);
		break;
						
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "j_day":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[36]; 
			link.l1 = DLG_TEXT[37];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[38]; 
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "portugLine1":
			dialog.snd = "Voice\GRSO\GRSO005";
			dialog.text = "Я хотел бы задать вам пару вопросов по поводу женщины которую видели на борту вашего судна. Кажется её имя Аманда Медейруш.";
			link.l1 = "Из-за пассажирки которую я перевозил, меня задержали в порту и отправили к вам? Могу ли я узнать причину такого интереса к её персоне?";
			link.l1.go = "portugLine2";
			break;

		case "portugLine2":
			dialog.text = "Дело в том, что у нас в городе происходит нечто загадочное, Руи Феррара - местный ростовщик,"
				+ " бесследно исчез. Женщина, которую вы перевозили, близко общалась с покойным."
				" Однако, спустя пару дней после того как Феррара пропал, она спешно покинула остров вместе с вами.";
			link.l1 = "Не думаю, что чем-то могу помочь вам в этом деле. Эту девушку первый раз я встретил в тот же день когда"
				+ " она наняла мое судно. И последний раз я её видел уже когда доставил в пункт назначения. К исчезновению ростовщика я не имею никакого отношения.";
			link.l1.go = "portugLine3";
			break;

		case "portugLine3":
			dialog.text = "У меня нет причин в чем-то подозревать вас, капитан. Однако, дело в том, что вы последний кто видел эту женщину. Единственное, что я"
				+ " хотел бы узнать это куда вы доставили сеньору?";
			link.l1 = "В порт Дувезена, там я последний раз её и видел. Боюсь это все что я знаю о ней сеньор Баррето.";
			link.l1.go = "portugLine4";
			break;

		case "portugLine4":
			dialog.text = "Какая досада! Случилось то, чего я опасался. Эта женщина, покинула остров и бьюсь об заклад, в порту Дувезена она пересела на другой корабль чтобы затруднить поиски. А ведь она могла прояснить некоторые вещи в этой ситуации!";
			link.l1 = "Ничего не могу сказать по поводу её дальнейший действий, сеньор губернатор.";
			link.l1.go = "portugLine5.1";
			break;

		case "portugLine5.1":
			dialog.text = "Я верю вам, капитан Хаук. И я думаю, что вы могли бы помочь мне в этом деле. Слушайте внимательно, Феррара был важным человеком в экономической жизни острова."
				+ " Как глава колонии, я должен знать что происходит. Однако, за пределами острова мне гораздо сложнее действовать, к тому же у меня много дел здесь на Консейсао.";
			link.l1.go = "portugLine5.2";
			break;
		case "portugLine5.2":
			dialog.text = " Но вы капитан, как раз могли бы взяться за это дело. Я бы достойно платил вам за вашу работу. И если вы начнете сейчас, то получите 1000 пиастров авансом. Что скажите?";
			link.l1 = "Думаю я могу вам помочь восстановить правосудие. Я согласен, сеньор губернатор.";
			link.l1.go = "portugLine6";
			link.l2 = "К сожалению, я сейчас не в состоянии помочь вам.";
			link.l2.go = "portugLineExitWait";
			break;

		case "portugLine5.3":
			dialog.text = " Да капитан, вы можете взяться за это дело?";
			link.l1 = "Думаю я могу вам помочь восстановить правосудие. Я согласен, сеньор губернатор.";
			link.l1.go = "portugLine6";
			link.l2 = "К сожалению, я сейчас не в состоянии помочь вам.";
			link.l2.go = "portugLineExitWait";
			break;

		case "portugLine6":
			dialog.text = "Замечательно, тогда первым делом посетите сеньора Фелициано Помбала, он сейчас ведет дела Феррары, поговорите с ним"
				+ " об этом инциденте, возможно вы получите дополнительную информацию, а затем отправляйтесь на Дувезен и там начните поиски Аманды Медейруш.";
			link.l1 = "Всего хорошего, сеньор губернатор.";
			link.l1.go = "exit";
			AddQuestRecord("PortuguezeLine", “2”);
			AddDialogExitQuest("StartPortugalLine");
			break;

		case "portugLineExitWait":
			AddDialogExitQuest("StartPortugalLineWait");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "portugLine7":
			dialog.text = "Да, капитан, вам удалось что-либо выяснить?";
			link.l1 = "Сеньор Руи Феррара был жестоко убит в доме своего компаньона, Кермита Праудфута - ростовщика в Гринфорде, его зарезали. Мне удалось выяснить что сам Праудфут " +
				"отсутствовал в своем доме во время убийства. Хотя я не могу сказать что-либо определенное по поводу его причастности к этому делу.";
			link.l1.go = "portugLine8";
			break;

		case "portugLine8":
			dialog.text = "Да, мне уже известно об этом ужасном злодеянии, судно с телом покойного сеньора Феррары недавно прибыло в порт консейсао. И тем не менее я благодарю вас за ваши усилия."
				AddMoneyToCharacter(PChar, 400);
			link.l1.go = "portugLine9";
			break;

		case "portugLine9":
			dialog.text = "А сейчас я хотел бы чтобы вы, сеньор Хаук, выяснили кто именно убил покойного сеньора Феррару. Вы говорили о каком-то моряке который последним видел ростовщика.";
			link.l1 = "Да, сеньор, но это мог быть только исполнитель, не факт что сам Праудфут, в доме которого произошло убийство, не причастен к этому делу.";
			link.l1.go = "portugLine10";
			break;

		case "portugLine10":
			dialog.text = "Вряд ли он на такое бы пошел, во-первых, если бы он планировал убить своего партнера, то вряд ли стал бы это делать у себя дома," +
				" во-вторых, судя по моей информации, ему не было бы никакой выгоды со смерти Феррары. Так что причастность английского ростовщика к убийству на данный момент рассматривать не будем.";
			link.l1 = "А что насчет помощника сеньора Феррары, Фелициано Помбала? После смерти Феррары он стал вести его дела.";
			link.l1.go = "portugLine11";
			break;

		case "portugLine11":
			dialog.text = "Да он действительно теперь ведет дела Феррары, но ему, также как и компаньону покойного, нет выгоды от этого убийства," +
				" так как по завещанию капиталом и всеми ценными бумагами теперь владеет семья Феррары, и Помбал об этом давно знал.";
			link.l1 = "С кем плавал сеньор Феррара? На сколько мне известно он плавал на португальском корабле.";
			link.l1.go = "portugLine12";
			break;

		case "portugLine12":
			dialog.text = "Он плавал с капитаном Тринканом, на шхуне Estrela.";
			link.l1 = " Я думаю у капитана можно узнать дополнительную информацию, по поводу каких-либо событий предшествующих убийству.";
			link.l1.go = "portugLine13";
			break;

		case "portugLine13":
			dialog.text = "Я этим займусь, шхуна приписана к порту Консейсао, поэтому я смогу пересечся с капитаном Тринканом, а вы, сеньор, продолжайте искать женщину сбежавшую с " +
				"Консейсао, и узнайте побольше о человеке которого видели последним в доме английского ростовщика.";
			link.l1 = "Да, сеньор, я продолжу поиски.";
			link.l1.go = "exit";
			AddQuestRecord("PortuguezeLine", “6”);
			AddDialogExitQuest("TalkWithBarreto2");
			break;
	}
}
