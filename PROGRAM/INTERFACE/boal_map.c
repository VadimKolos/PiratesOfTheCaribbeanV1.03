string totalInfo;
void InitInterface(string iniName)
{
	EngineLayersOffOn(true);
	SetTimeScale(0.0);
    	GameInterface.title = "titleBoal_map";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
    

	CalculateInfoData();

	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	SetFormatedText("INFO_TEXT",totalInfo);//"Капитан, кто-то явно плывет.");
	//LanguageCloseFile(tmpLangFileID);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0); // Выход на море
	SetEventHandler("exitCancel","ProcessCancelExit",0); // Выход на море по крестику или Esc
	SetEventHandler("ievnt_command","ProcCommand",0); // выход на карту только тут (по НЕТ)
	SetEventHandler("evntDoPostExit","DoPostExit",0); // выход из интерфейса
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
	wdmReloadToSea();
	SetTimeScale(1.0);
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
	wdmReloadToSea();
	SetTimeScale(1.0);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
	SetTimeScale(1.0);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "B_OK":
		if(comName=="activate" || comName=="click")
		{
			// напасть
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
			wdmReloadToSea();
		}
	break;

	case "B_CANCEL":
		if(comName=="activate" || comName=="click")
		{
			//пропустить
			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SALARY_EXIT);
			SetTimeScale(1.0);
		}
		if(comName=="upstep")
		{
			if(GetSelectable("B_OK"))	{SetCurrentNode("B_OK");}
		}
	break;
	}
}
void wdmRecalcReloadToSea()
{

	worldMap.encounter.type = "";
	totalInfo = "";
	//Encounters
	int numEncounters = wdmGetNumberShipEncounters();
	int isShipEncounterType = 0;
	ref rEncounter;
	for(int i = 0; i < numEncounters; i++)
	{
		if(wdmSetCurrentShipData(i))
		{
		    if(MakeInt(worldMap.encounter.select) == 0) continue;			
			isShipEncounterType++;
			if (isShipEncounterType>1)
			{
			    totalInfo = totalInfo + " А так же ";
			}
			rEncounter = &MapEncounters[sti(worldMap.encounter.type)];
			
			switch(sti(rEncounter.RealEncounterType))
			{
				  case 0:		
				     totalInfo = totalInfo + "торговцы ";
				  break;
				  case 1:		
				     totalInfo = totalInfo + "торговцы с сопровождением ";
				  break;
				  case 2:		
				     totalInfo = totalInfo + "военный конвой важного груза ";
				  break;
				  case 3:		
				     totalInfo = totalInfo + "военный патруль ";
				  break;
				  case 4:		
				     totalInfo = totalInfo + "военная армада ";
				  break;
				  case 5:		
				     totalInfo = totalInfo + "один или несколько военных кораблей ";
				  break;
				  case 6:		
				     totalInfo = totalInfo + "корсары ";
				  break;
				  case 7:		
				     totalInfo = totalInfo + "карательная экспедиция ";
				  break;
			}
	        //totalInfo = totalInfo + ", флаг ";
	        switch(sti(rEncounter.Nation))
	        {
		        case 0:		
			        totalInfo = totalInfo + "под английским флагом.";
		        break;
		        case 1:		
			        totalInfo = totalInfo + "под французким флагом.";
		        break;
		        case 2:		
			        totalInfo = totalInfo + "под испанским флагом.";
		        break;
		        case 3:		
			        totalInfo = totalInfo + "под пиратским флагом.";
		        break;
		        case 4:		
			        totalInfo = totalInfo + "под голландским флагом.";
		        break;
		        case 5:		
			        totalInfo = totalInfo + "под португальским флагом.";
		        break;
		    }
		}
	}
	if (isShipEncounterType>1)
	{
	   totalInfo = "Капитан, сражение по курсу. Похоже, что это " + totalInfo;
	}
	else
	{
	   totalInfo = "Капитан, кто-то плывет. Похоже, что это " + totalInfo;
	}
}




void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	
    wdmRecalcReloadToSea();
    ref mainCh = GetMainCharacter();
    
	if(!CheckAttribute(mainCh, "perks.list.SailingProfessional"))
	{
		SetSelectable("B_CANCEL",false);
		SetCurrentNode("B_OK");
	}
	else
	{
		SetSelectable("B_CANCEL",true);
		SetCurrentNode("B_OK");
	}
}
