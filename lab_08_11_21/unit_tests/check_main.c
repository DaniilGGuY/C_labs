#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *sum, *comp, *slau;
    SRunner *run_sum, *run_comp, *run_slau;

    sum = check_sum();
    run_sum = srunner_create(sum);

    srunner_run_all(run_sum, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_sum);
    srunner_free(run_sum);

    comp = check_comp();
    run_comp = srunner_create(comp);

    srunner_run_all(run_comp, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_comp);
    srunner_free(run_comp);

    slau = check_slau();
    run_slau = srunner_create(slau);

    srunner_run_all(run_slau, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_slau);
    srunner_free(run_slau);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
