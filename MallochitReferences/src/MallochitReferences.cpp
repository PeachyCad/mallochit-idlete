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

/// sref
/* #include <iostream>
#include "sref.h"

using namespace std;

int main()
{

	sref<int> sr1 = make_sref<int>(10);
	auto sr2 = sr1;
	auto sr3 = sr1;

	*sr2 = 2;
	*sr3 = 11;

	cout << *sr1 << endl;
}*/
