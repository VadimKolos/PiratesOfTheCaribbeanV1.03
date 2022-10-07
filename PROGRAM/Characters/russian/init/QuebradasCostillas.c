int CreateQuebradasCostillasCharacters(int n)
{
	ref ch;

// QC_port:

	makeref(ch,Characters[n]);		// Terry  Snider -- Black_Corsair
	ch.name 	= "�����";
	ch.lastname = "�������";
	ch.id		= "Terry  Snider";
	ch.model	= "Black_Corsair";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "character3";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;


	makeref(ch,Characters[n]);		// Gilles Roche -- Corsair2
	ch.name 	= "����";
	ch.lastname = "����";
	ch.id		= "Gilles Roche";
	ch.model	= "Corsair2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "character1";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;

	makeref(ch,Characters[n]);		// Alvaro Dimas -- korsar
	ch.name 	= "�������";
	ch.lastname = "�����";
	ch.id		= "Alvaro Dimas";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;


// QC_town:

	makeref(ch,Characters[n]);		// Natan Bueno -- Corsair1
	ch.name 	= "�����";
	ch.lastname = "�����";
	ch.id		= "Natan Bueno";
	ch.model	= "Corsair1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;

	makeref(ch,Characters[n]);		// Romao  Edhino -- fatman
	ch.name 	= "�����";
	ch.lastname = "������";
	ch.id		= "Romao  Edhino";
	ch.model	= "fatman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;

	makeref(ch,Characters[n]);		// Valerio Tintorero -- Corsair3
	ch.name 	= "�������";
	ch.lastname = "���������";
	ch.id		= "Valerio Tintorero";
	ch.model	= "Corsair3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto19";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;

	makeref(ch,Characters[n]);		// Elias  Hafte -- man1
	ch.name 	= "�����";
	ch.lastname = "����";
	ch.id		= "Elias Hafte";
	ch.model	= "man1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;

	makeref(ch,Characters[n]);		// Hamund Verret -- shkiper
	ch.name 	= "�����";
	ch.lastname = "�����";
	ch.id		= "Hamund Verret";
	ch.model	= "man1_2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	n = n + 1;


// QC_Store:

	makeref(ch,Characters[n]);		// Peter Blowhorn -- Fatman2
	ch.name 	= "�����";
	ch.lastname = "��������";
	ch.id		= "Peter Blowhorn";
	ch.model	= "Fatman2";
	ch.sex = "man";
	ch.location	= "QC_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Peter Blowhorn_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Peter Blowhorn";
	n = n + 1;

// QC_Tavern:

	makeref(ch,Characters[n]);		// Ines Diaz -- towngirl3
	ch.name 	= "����";
	ch.lastname = "����";
	ch.id		= "Ines Diaz";
	ch.model	= "Oldwoman";
	ch.sex = "woman";
	ch.location	= "QC_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Ines Diaz_dialog.c";
	ch.greeting = "Gr_Ines Diaz";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	ch.quest.about = "0";
	ch.quest.rheims = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);		// William Blaker -- cameleon
	ch.name 	= "������";
	ch.lastname = "�������";
	ch.id		= "William Blaker";
	ch.model	= "chameleon";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "William Blaker_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);		// Marc Fremont -- man5
	ch.name 	= "����";
	ch.lastname = "������";
	ch.id		= "Marc Fremont";
	ch.model	= "man5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);		// Conceicao_officiant
	ch.name 	= "������";
	ch.lastname = "�����";
	ch.id		= "QC_officiant";
	ch.model	= "towngirl2";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "QC_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;
	
	makeref(ch,Characters[n]);		// (Robyn Baldhead -- Old_man1 (shipyard owner)
	ch.name 	= "������";
	ch.lastname = "�����";
	ch.id		= "Robyn Baldhead";
	ch.model	= "Old_man1";
	ch.sex = "man";
	ch.location	= "QC_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Lambrecht Fobes_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	ch.greeting = "Gr_Lambrecht Fobes";
	n = n + 1;

// QC_residence:

	makeref(ch,Characters[n]);		// Isenbrandt Jurcksen -- capitan
	ch.name 	= "����������";
	ch.lastname = "������";
	ch.id		= "Isenbrandt Jurcksen";
	ch.model	= "capitan";
	ch.sex = "man";
	ch.location	= "QC_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Isenbrandt Jurcksen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "pistol4");
	ch.equip.gun = "pistol4";
	GiveItem2Character(ch, "blade25");
	ch.equip.blade = "blade25";
	ch.rank 	= 22;
	ch.reputation = "25";
	ch.experience = CalculateExperienceFromRank(22)+ (CalculateExperienceFromRank(22)/10 + rand(22000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "10000";
	ch.Ship.Name = "�������������";
	ch.ship.type = SHIP_PROPHECY;
	ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_warrior_SetStay(ch, true);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 160.0, 160.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Isenbrandt Jurcksen";
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenseProfessional = true;
	ch.perks.list.CriticalShoot = true;
	ch.perks.list.LongRangeShoot = true;
	ch.perks.list.BasicDefense = true;
	ch.perks.list.AdvancedDefense = true;
	ch.perks.list.ShipSpeedUp = true;
	n = n + 1;

	makeref(ch, Characters[n]);		// -- shkiper
	ch.name = "������ �����";
	ch.lastname = "";
	ch.id = "black_raven";
	ch.model = "shkiper";
	ch.sex = "man";
	ch.act.sound_type = "pirate";
	//ch.sound_type = "seaman";
	ch.location = "QC_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "";
	ch.Dialog.Filename = "black_raven_dialog.c";
	ch.greeting = "Gr_Isenbrandt Jurcksen";
	ch.nation = PIRATE;
	ch.rank = 6;
	ch.reputation = "None";
	ch.experience = "1200";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "3";
	ch.money = "850";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;

	makeref(ch, Characters[n]);
	ch.name = "�����";
	ch.lastname = "";
	ch.id = "blackRavens_pirate";
	ch.model = "Fatman2";
	ch.sex = "man";
	ch.act.sound_type = "pirate";
	ch.location = "QC_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "";
	ch.Dialog.Filename = "blackRavens_pirate_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank = 4;
	ch.reputation = "None";
	ch.experience = "900";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;

	makeref(ch, Characters[n]);
	ch.name = "�����";
	ch.lastname = "";
	ch.id = "blackRavens_pirate2";
	ch.model = "korsar";
	ch.sex = "man";
	ch.location = "QC_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "";
	ch.Dialog.Filename = "blackRavens_pirate_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	ch.rank = 5;
	ch.reputation = "None";
	ch.experience = "900";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	n = n + 1;


	return n;
}