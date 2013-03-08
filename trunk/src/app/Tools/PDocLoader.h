#ifndef P_DOC_LOADER_H
#define P_DOC_LOADER_H

#include "Commands/PCommandManager.h"
#include "Document/PEditorManager.h"
#include "Indexer.h"

#include <app/Message.h>

class PDocumen;
class WindowManager;
/**
 * @class PDocLoader
 *
 * @brief  PDocLoader is a class to generate Classes from a ProjectConceptor Dokument datastream
 * @warning it assums that the Nodes and Connections are BMEssages!!
 * but it automatically restores pointers from Connections to the Nodes (BMessage Objects) 
 *
 * @author Paradoxon powered by Jesus Christ
 * @version 0.01
 * @date 2005/10/04
 * @Contact: mail@projectconceptor.de
 *
 *
 */

class PDocLoader
{

public:
								PDocLoader(PDocument *doc,BMessage *loadableMessage);
	virtual						~PDocLoader(void);


	virtual	BList*				GetAllNodes(void){return allNodes;};
	virtual	BList*				GetAllConnections(void){return allConnections;};
	virtual	BList*				GetSelectedNodes(void){return selectedNodes;};
	
	virtual BList*				GetUndoList(void){return undoList;};
	virtual BList*				GetMacroList(void){return macroList;};
	
	virtual uint32				GetUndoIndex(void){return undoIndex;};
	
	virtual	BMessage*			GetPrinterSetting(void){return printerSettings;};
	virtual	BMessage*			GetSettings(void){return settings;};

	virtual	PEditorManager*		GetEditorManager(void);
	virtual	BMessage*			GetCommandManagerMessage(void){return commandManagerMessage;};

protected:
	virtual void				Init(void);
	virtual void				Load(void);
	//spread sorts all BList stuff out of the nodes... ;-)
	virtual BList*				Spread(BMessage *allNodeMessage);
	//ReIndex takes the stored Connections and ReAssing the Connections to real existing pointers 
	virtual BList*				ReIndexConnections(BMessage *allConnectionsMessage);
	virtual BList*				ReIndexSelected(BMessage *allConnectionsMessage);
	virtual BList*				ReIndexUndo(BMessage *reIndexUndo);
	virtual BList*				ReIndexMacro(BMessage *reIndexUndo);
	
		
		BList*					allNodes;
		BList*					selectedNodes;
		BList*					allConnections;
		BList*					undoList;
		BList*					macroList;
		
		uint32					undoIndex;


		BMessage*				settings;
		
		BMessage*				printerSettings;


		BMessage*				commandManagerMessage;

		PEditorManager*			editorManager;
		WindowManager*			windowManager;
		
		BMessage*				loadedStuff;
		Indexer					*indexer;

private:

};
#endif
