#ifndef P_C_SAVE_PANEL_H
#define P_C_SAVE_PANEL_H

#include "PluginManager.h"

#include <app/Application.h>
#include <interface/Menu.h>
#include <interface/MenuItem.h>
#include <interface/MenuField.h>
#include <FilePanel.h>
#include <interface/Button.h>
#include <TranslatorRoster.h>

#ifdef B_ZETA_VERSION_1_0_0
	#include <locale/Locale.h>
	#include <locale/LanguageNotifier.h>
#else
	#define _T(a) a
#endif 

class PCSavePanel : public BFilePanel
{
public:
					PCSavePanel(BMessage *msg,  BMessenger* target = NULL) ;
		BMenu		*BuildFormatsMenu(void);
	//virtual void SelectionChanged();
virtual	void		SendMessage(const BMessenger*, BMessage*);
protected:
	BMenuField		*formatMenu;
	entry_ref 		entryRef;
	BButton			*settings;
};

#endif
