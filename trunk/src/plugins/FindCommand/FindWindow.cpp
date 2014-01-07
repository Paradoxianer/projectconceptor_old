#include <interface/Button.h>
#include <interface/Box.h>
#include <interface/GroupLayoutBuilder.h>
#include <interface/GroupLayout.h>
#include <interface/SplitLayoutBuilder.h>
#include <interface/SplitView.h>
#include <interface/StringView.h>
#include <interface/SpaceLayoutItem.h>



#include "FindWindow.h"
#include "ColumnTypes.h"

FindWindow::FindWindow(PDocument *tmpDoc):BWindow(BRect(50,50,600,400),_T("Find"),B_FLOATING_WINDOW_LOOK,B_MODAL_APP_WINDOW_FEEL,B_AUTO_UPDATE_SIZE_LIMITS)
{
	TRACE();
	doc=tmpDoc;
	CreateViews();
    Init();

}

void FindWindow::Init()
{
	BList		*nodeList	= doc->GetAllNodes();
	int32		i			= 0;
	nodeListView->AddColumn(new BStringColumn("Node",150.0,30.0,300.0,5),0);
	for (i=0; i< nodeList->CountItems();i++)
	{
		nodeListView->AddRow(CreateRow((BMessage *)nodeList->ItemAt(i)));
	}
}

void FindWindow::CreateViews()
{
	TRACE();
    searchText				= new LiveTextView("searchText", new BMessage('find'));
    nodeListView			= new BColumnListView("nodeListView",0);
	SetLayout(new BGroupLayout(B_HORIZONTAL));	
	AddChild(
		BGroupLayoutBuilder(B_VERTICAL)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL)
			.SetInsets(10,10,10,10);
			.Add(new BStringView("findLabel","Find"))
			.Add(searchText)
			
		)
		.Add(BSplitLayoutBuilder(B_VERTICAL)
			.Add(new BBox("Advanced Search"))
			.Add(nodeListView)	
		)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL)
			.Add(new BButton("okButton",_T("OK"), new BMessage('ok')))
			.Add(new BButton("channelButton",_T("Cancel"), new BMessage('cl')))
		)
	);

}

BRow *FindWindow::CreateRow(BMessage *tmpNode)
{
	char		*tmpName	= NULL;
	BMessage	*tmpMessage	= new BMessage();
	tmpNode->FindMessage("Node::Data",tmpMessage);
	tmpMessage->FindString("Name",(const char **)&tmpName);
	BRow		*row		= new BRow();
	row->SetField(new BStringField(tmpName),0);
	return row;
}

void FindWindow::ChangeLanguage()
{
	TRACE();

}

void FindWindow::MessageReceived(BMessage *message)
{
	TRACE();
	message->PrintToStream();
	switch(message->what)
	{
		case 'ok':
		
		break;
		case 'cl':
		{
			BWindow::Quit();
		}
		break;
		case 'find':
		{
			FindNodes(searchText->Text());
		}
		break; 
	}
}

void FindWindow::FindNodes(BMessage *node,BString *string)
{
	char		*attribName		= NULL;
	BMessage	*attribMessage	= new BMessage();
	uint32		type			= B_ANY_TYPE;
	int32		count			= 0;
	bool		found			= false;
	for (int32 i = 0; node->GetInfo(B_MESSAGE_TYPE, i,(char **) &attribName, &type, &count) == B_OK; i++)
	{
		if (node->FindMessage(attribName,count-1,attribMessage) == B_OK)
			found = found | FindInMessage(attribMessage, string);
	}
}

bool FindWindow::FindInMessage(BMessage *node,BString *string)
{
	
}


void FindWindow::Quit()
{
	TRACE();
	BWindow::Quit();
}
