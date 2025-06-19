#include "headers/PrimeSieve.hpp"

#include <gtest/gtest.h>

TEST(Sieve, Prime)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::bitset<SIZE> sieve;
    sieveEratosthenes(sieve);
    printPrimes(sieve);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "The prime numbers in the range 2 to 1024 are:\n    2    3    5    7   11   13   17   19   23   29\n   31   37   41   43   47   53   59   61   67   71\n   73   79   83   89   97  101  103  107  109  113\n  127  131  137  139  149  151  157  163  167  173\n  179  181  191  193  197  199  211  223  227  229\n  233  239  241  251  257  263  269  271  277  281\n  283  293  307  311  313  317  331  337  347  349\n  353  359  367  373  379  383  389  397  401  409\n  419  421  431  433  439  443  449  457  461  463\n  467  479  487  491  499  503  509  521  523  541\n  547  557  563  569  571  577  587  593  599  601\n  607  613  617  619  631  641  643  647  653  659\n  661  673  677  683  691  701  709  719  727  733\n  739  743  751  757  761  769  773  787  797  809\n  811  821  823  827  829  839  853  857  859  863\n  877  881  883  887  907  911  919  929  937  941\n  947  953  967  971  977  983  991  997 1009 1013\n 1019 1021\n");
}

TEST(Sieve, NotPrime)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::bitset<SIZE> sieve;
    sieveEratosthenes(sieve);
    tryPrimes(sieve, 2);
    tryPrimes(sieve, 3);
    tryPrimes(sieve, 4);
    tryPrimes(sieve, 378);
    tryPrimes(sieve, 1024);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "2 is a prime number\n3 is a prime number\n4 is not a prime number\nThe unique prime factorization of 4 is: 2 * 2 * \n378 is not a prime number\nThe unique prime factorization of 378 is: 2 * 3 * 3 * 3 * 7 * \n1024 is not a prime number\nThe unique prime factorization of 1024 is: 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * \n"); 
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

