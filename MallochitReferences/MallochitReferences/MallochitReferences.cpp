/// random_gref
/*#include <iostream>
#include "random_gref.h"

using namespace std;

random_gref<int> foo() {
	rgrowned<int> rgo = make_rgrowned<int>(10);
	random_gref<int> rgr = rgo.ref();
	return rgr;
}

int main()

{
	rgrowned<int> rg = make_rgrowned<int>(5);
	random_gref<int> a = rg.ref();

	a = foo();

	cout << *a.open() << endl;
	cout << *a.open() << endl;
}*/

/// constr_ref
/*#include "constr_ref.h"
#include <iostream>

using namespace std;

constr_ref<int> foo() {
	crowned<int> cro = make_crowned<int>(10);
	constr_ref<int> crr = cro.ref();
	return crr;
}

int main()

{
	crowned<int> cr = make_crowned<int>(5);
	constr_ref<int> a = cr.ref();

	a = foo();
}*/

/// arc_ref
#include <iostream>
#include <thread>
#include <atomic>
#include <type_traits>

using namespace std;


int main()
{
}
