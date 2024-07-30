#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *filt, *shift;
    SRunner *run_filt, *run_shift;

    filt = filt_arr();
    run_filt = srunner_create(filt);

    shift = shift_arr();
    run_shift = srunner_create(shift);

    srunner_run_all(run_filt, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_filt);
    srunner_free(run_filt);

    srunner_run_all(run_shift, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_shift);
    srunner_free(run_shift);

    return (no_failed == 0) ? EXIT_SUCSESS : EXIT_FAILURE;
}
