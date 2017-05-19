#ifndef TESTS_PARTITIONS_H
#define TESTS_PARTITIONS_H

/**
 * @brief The numbers of tests to run for each patition scheme.
 * This can be defined using compiler arguments */
#ifndef PARTITION_TESTS
#define PARTITION_TESTS 1000
#endif

void partition_lomuto_tests(void);

#endif /* TESTS_PARTITIONS_H */
