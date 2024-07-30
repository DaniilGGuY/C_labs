#include "check_head.h"

int main(void)
{
    int no_failed = 0;
    Suite *find, *insert, *fb_split, *sort, *rm_dups;
    SRunner *run_find, *run_insert, *run_fb_split, *run_sort, *run_rm_dups;

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

    fb_split = check_fb_split();
    run_fb_split = srunner_create(fb_split);

    srunner_run_all(run_fb_split, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_fb_split);
    srunner_free(run_fb_split);

    sort = check_sort();
    run_sort = srunner_create(sort);

    srunner_run_all(run_sort, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_sort);
    srunner_free(run_sort);

    rm_dups = check_rm_dups();
    run_rm_dups = srunner_create(rm_dups);

    srunner_run_all(run_rm_dups, CK_VERBOSE);
    no_failed += srunner_ntests_failed(run_rm_dups);
    srunner_free(run_rm_dups);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}