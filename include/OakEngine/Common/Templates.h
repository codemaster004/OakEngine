/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_TEMPLATES_H
#define OAKENGINE_TEMPLATES_H

namespace oak::Common {
	template<typename T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}
}

#endif //OAKENGINE_TEMPLATES_H
