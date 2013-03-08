#ifndef PAGED_VIEW_H
#define PAGED_VIEW_H
/*
 * @author Paradoxon powered by Jesus Christ
 */
#include <app/Message.h>
#include <interface/Bitmap.h>
#include <interface/View.h>
#include <interface/Rect.h>
#include <vector.h>

enum page_layout{
	ONE_COL	= 1,
	TWO_COL	= 2,
	COL_AS_NEEDED = -1
};

class PagedRect
{
	public:
							PagedRect(void){
								pageRect	= BRect();
								printRect	= BRect();
								sourceRect	= BRect();
							};
							PagedRect(BRect _pageRect,BRect _printRect,BRect _sourceRect){
								pageRect	=_pageRect;
								printRect	=_printRect;
								sourceRect	= _sourceRect;
							};
			float			LeftBorder(void){return printRect.left-pageRect.left;};
			float			TopBorder(void){return printRect.top-pageRect.top;};
			float			RightBorder(void){return pageRect.right-printRect.right;};
			float			BottomBorder(void){return pageRect.bottom-printRect.bottom;};
			BRect			PageRect(void){return pageRect;};
			BRect			PrintRect(void){return printRect;};
			BRect			SourceRect(void){return sourceRect;};
			void			SetPageRect(BRect _pageRect){pageRect=_pageRect;};
			void			SetPrintRect(BRect _printRect){printRect=_printRect;};
			void			SetSourceRect(BRect _sourceRect){sourceRect=_sourceRect;};
			BPoint			DiffOffset(void){return BPoint(sourceRect.left-printRect.left,sourceRect.top-printRect.top);};


	private:
			BRect			pageRect;
			BRect			printRect;
			BRect			sourceRect;

};

class PagedView :  public BView
{

public:
							PagedView(BRect _rect,char *_name,uint32 resizingMode,uint32 flags,page_layout _pageLayout = ONE_COL);

	//++++++++++++++++BView
	virtual void			AttachedToWindow(void);
	
	virtual	void			Draw(BRect updateRect);

	virtual	void			MouseDown(BPoint where);
	virtual	void			MouseMoved(	BPoint where, uint32 code, const BMessage *a_message);
	virtual	void			MouseUp(BPoint where);

	virtual	void			MessageReceived(BMessage *msg);

	virtual void			FrameResized(float width, float height);
	//----------------BView
	/**
	 * Pass the Rect wich defines the new Size of the Page
	 * This Rect must enclose the whole printRect
	 *@see SetPrintRect(BRect _printRect);
	 */
			void			SetPageRect(BRect _pageRect);
	/**
	 * Pass the Rect wich defines the new Size of the Printable Rect
	 * This Rect must be smaller than the PageRect
	 *@see SetPageRect(BRect _printRect);
	 */
			void			SetPrintRect(BRect _printRect);

protected:
			void			Init(void);
			void			DrawPages(BRect);
			void			CalculatePages(void);
			BBitmap			*renderBitmap;
			BView			*drawView;


private:
			bool				paged;
			BRect				pageRect;
			BRect				printRect;
			int32				rows, colums;
			page_layout			pageLayout;
			float				margin;
			vector<PagedRect>	childList;

};
#endif
