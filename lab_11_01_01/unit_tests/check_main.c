#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *func;
    SRunner *run_func;

    func = check_my_snprintf();
    run_func = srunner_create(func);

    srunner_run_all(run_func, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_func);
    srunner_free(run_func);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
