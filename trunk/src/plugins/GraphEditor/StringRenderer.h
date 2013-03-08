#ifndef STRING_RENDERER_H
#define STRING_RENDERER_H
/*
 * @author Paradoxon powered by Jesus Christ
 */
#include <app/Message.h>
#include <app/Messenger.h>
#include <interface/View.h>
#include <interface/Box.h>
#include <interface/PictureButton.h>
#include <interface/TextView.h>
#include <interface/TextControl.h>

#include "GraphEditor.h"
#include "PDocument.h"
#include "PCommand.h"
#include "Renderer.h"
#include "Renderer.h"
#include "TextEditorControl.h"

#ifdef B_ZETA_VERSION
	#include <locale/Locale.h>
	#include <locale/LanguageNotifier.h>
#else
	#define _T(a) a
#endif 

const uint32	B_C_V_NAME_CHANGED	= 'bcNC';

class StringRenderer: public Renderer
{

public:
							StringRenderer(GraphEditor *parentEditor,char *forString,BRect stringRect,BMessage *message=NULL);
			void			ValueChanged(void){};
			void			Draw(BView *drawOn, BRect updateRect);
			void			SetString(char *newString);
			char*			GetString(void){return string;};
			void			MouseDown(BPoint where);
			void			MouseMoved(BPoint pt, uint32 code, const BMessage *msg){};

			void			MouseUp(BPoint where){};
			void			SetFrame(BRect newRect);
			BRect			Frame(void){return frame;};
			void			MoveBy(float dx, float dy){frame.OffsetBy(dx,dy);};
			void			ResizeBy(float dx,float dy){frame.right+=dx;SetFrame(frame);};

			bool			Selected(void){return false;};
			bool			Caught(BPoint where){frame.Contains(where);};

protected:
			void			Init();
		BMessage			*changeMessage;
		GraphEditor 		*editor;
		BRect				frame;
		char				*string;
		BString				*shortString;
		BFont				*editorFont;
		float				fontHeight;
private:
};
#endif
