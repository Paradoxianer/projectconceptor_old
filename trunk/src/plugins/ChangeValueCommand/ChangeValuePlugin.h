#ifndef CHANGE_VALUE_PLUGIN_H
#define CHANGE_VALUE_PLUGIN_H
/*
 * @author Paradoxon powered by Jesus Christ
 */
#include "BasePlugin.h"
#include "ChangeValue.h"

class ChangeValuePlugin : public BasePlugin
{
public:

						ChangeValuePlugin(image_id id);
	
	//++++++++++++++++BasePlugin
	virtual uint32			GetType(){return P_C_COMMANDO_PLUGIN_TYPE;};
	virtual	char*			GetVersionsString(void){return "0.01preAlpha";};
	virtual char*			GetAutor(void){return "Paradoxon";};
	virtual char*			GetName(void){return "ChangeValue";};
	virtual char*			GetDescription(void){return "This is a simple ChangeValue Command for ProjectConceptor with basic funktionality";};
	virtual void*			GetNewObject(void *value){return new ChangeValue();};
};
#endif
