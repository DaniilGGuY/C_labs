#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *find, *insert;
    SRunner *run_find, *run_insert;

    find = check_find();
    run_find = srunner_create(find);

    srunner_run_all(run_find, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_find);
    srunner_free(run_find);

    insert = check_insert();
    run_insert = srunner_create(insert);

    srunner_run_all(run_insert, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_insert);
    srunner_free(run_insert);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
