#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *assoc;
    SRunner *run_assoc;

    assoc = check_assoc();
    run_assoc = srunner_create(assoc);

    srunner_run_all(run_assoc, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_assoc);
    srunner_free(run_assoc);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}