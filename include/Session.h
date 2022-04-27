#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"

namespace game {	
	class Session  
	{
	private:
		std::vector<Sprite*> sprits;
		std::vector<Sprite*> tempAdded;
	public:
		void add(Sprite* c);
		void run();
		~Session();

	};
	extern Session ses;
}
#endif