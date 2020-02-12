#pragma once //The pragma once will ensure that the includes are only 'written'(?) or 'defined' once. (Visual C++)
//Else we can use other preprocessor directives called Include Guards
#ifndef VENDINGMACHINE_H 
#define VENDINGMACHINE_H

//Also I'm using a custom namespace (cac):
namespace cac {
	void VendingMachine(); //Function prototype... Tell the linker that this function exist somewhere.
}
#endif
