#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *form, *mult, *square, *division;
    SRunner *run_form, *run_mult, *run_square, *run_division;

    form = check_form();
    run_form = srunner_create(form);

    srunner_run_all(run_form, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_form);
    srunner_free(run_form);

    mult = check_mult();
    run_mult = srunner_create(mult);

    srunner_run_all(run_mult, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_mult);
    srunner_free(run_mult);

    square = check_square();
    run_square = srunner_create(square);

    srunner_run_all(run_square, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_square);
    srunner_free(run_square);

    division = check_division();
    run_division = srunner_create(division);

    srunner_run_all(run_division, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_division);
    srunner_free(run_division);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
