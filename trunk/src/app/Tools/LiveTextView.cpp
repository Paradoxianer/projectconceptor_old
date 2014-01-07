#include "LiveTextView.h"
#include <Messenger.h>

LiveTextView::LiveTextView(const char* name, BMessage *message, uint32 flags):BTextView(name,flags)
{
	BInvoker(message, BMessenger(this));
}

void LiveTextView::AttachedToWindow()
{
	BInvoker::SetTarget(NULL,(BLooper *)Window());
}

void LiveTextView::InsertText(const char* text, int32 length,int32 offset, const text_run_array* runs)
{
	BInvoker::Invoke(new BMessage('test'));
	BTextView::InsertText(text,length,offset,runs);
}
