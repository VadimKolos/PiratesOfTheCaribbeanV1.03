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
		// -----------------------------------ƒиалог первый - перва€ встреча
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
			dialog.text = "ѕостойте, cеньор, это ваше судно стоит на рейде?";
			link.l1 = "ƒа, мое.  акие-то вопросы?";

			link.l1.go = "next";
		break;

	case "next":

		dialog.text = "ƒа, сеньор, господин губернатор хочет задать вам несколько вопросов, по поводу пассажирки которую вы недавно увезли с  онсейсао, извольте пройти со мной, капитан.";
		link.l1 = "ѕрошу прощени€, любезный, но у мен€ были другие планы, € не испытываю большого желани€ куда-либо идти с вами.";
		link.l1.go = "next2";
		
		
		break;

	case "next2":
		dialog.text = " ак вам будет угодно, сеньор, но учтите, € бы на вашем месте повиновалс€ воле губернатора, а учитыва€, что ваше судно находитс€ как раз под пушками форта, € вообще не думаю что у вас есть выбор.";
		link.l1 = "„то ж ваши аргументы убедительны, возможно мне и вправду придетс€ посетить господина губернатора. »дем.";		
		link.l1.go = "Exit";		
		AddQuestRecord("PortuguezeLine", У1Ф);
		break;	


	case "Exit":
		LAi_SetCitizenType(characterFromID("PortugalQuestSoldier"));
		AddDialogExitQuest("GoToPurtuguezeTownhall");		
		DialogExit();
		break;

	}
}