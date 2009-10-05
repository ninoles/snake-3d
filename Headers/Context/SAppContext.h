#ifndef SAPPCONTEXT_H_
#define SAPPCONTEXT_H_

#include <irrlicht.h>

//TODO Incluir referência ao frame que tem um SAppContext

namespace Context{
	
	class SAppContext{
		
		private:
			
			irr::IrrlichtDevice* _device;
		public:
			
			SAppContext(irr::IrrlichtDevice *__device);
			SAppContext();
			
			void setDevice(irr::IrrlichtDevice *__device);
			irr::IrrlichtDevice* getDevice();
			
			irr::gui::IGUIEnvironment* getEnvironment();
			irr::video::IVideoDriver* getDriver();
	};
};

#endif /*SAPPCONTEXT_H_*/
