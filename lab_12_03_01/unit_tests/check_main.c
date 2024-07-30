#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *filt, *sort;
    SRunner *run_filt, *run_sort;

    filt = filt_arr();
    run_filt = srunner_create(filt);

    sort = sort_arr();
    run_sort = srunner_create(sort);

    srunner_run_all(run_filt, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_filt);
    srunner_free(run_filt);

    srunner_run_all(run_sort, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_sort);
    srunner_free(run_sort);

    return (no_failed == 0) ? EXIT_SUCSESS : EXIT_FAILURE;
}
