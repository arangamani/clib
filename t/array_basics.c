#include "clib_internal.h"
#include "testsuite.h"

#include <stdio.h>

int
main(void)
{
	int ntest = 0, exitval = 0;
	struct c_array *a;

	/* Create array. */
	testresult("create array",
		a = c_array_new(c_resize_minimal));

	/* Insert data. */
	testresult("push array 1",
		c_array_push(a, strdup("charly")));
	testresult("push array 2",
		c_array_push(a, strdup("charlene")));

	/* Fetch data. */
	test_expect_str("get array 1", c_array_get(a, 0), "charly");
	test_expect_str("get array 2", c_array_get(a, 1), "charlene");

	/* Replace it. */
	testresult("replace array existing",
		c_array_replace(a, 0, strdup("fries")));

	/* Fetch it again. */
	test_expect_str("get array 3", c_array_get(a, 0), "fries");
	test_expect_str("get array 4", c_array_get(a, 1), "charlene");

	/* Insert new data with replace. */
	testresult("replace array new",
		c_array_replace(a, 2, strdup("peanuts")));

	/* Fetch that too. */
	test_expect_str("get array 5", c_array_get(a, 2), "peanuts");

	/* Remove it all. */
	/* FIXME: not implemented
	testresult("clear array", c_array_clear(a), 1);
	*/

	/* Destroy array. */
	c_array_destroy(a);
	testresult("destroy array", 1);

	exit(exitval ? EXIT_FAILURE : EXIT_SUCCESS);
}