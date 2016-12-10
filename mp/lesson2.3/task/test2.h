#pragma once


void test()
{
	SmallAllocator A1;
	int * A1_P1 = (int *) A1.Alloc(10 * sizeof(int));
	for(unsigned int i = 0; i < 10; i++) A1_P1[i] = i;

	int * A1_P2 = (int *) A1.Alloc(10 * sizeof(int));
	for(unsigned int i = 0; i < 10; i++) A1_P2[i] = 2 * i;

	for(unsigned int i = 0; i < 10; i++) if(A1_P1[i] != i) std::cout << "ERROR 1" << std::endl;
	for(unsigned int i = 0; i < 10; i++) if(A1_P2[i] != 2 * i) std::cout << "ERROR 2" << std::endl;

	A1_P1 = (int *) A1.ReAlloc(A1_P1, 20 * sizeof(int));
	for(unsigned int i = 0; i < 10; i++) if(A1_P1[i] != i) std::cout << "ERROR 3" << std::endl;
	for(unsigned int i = 10; i < 20; i++) A1_P1[i] = i;

	for(unsigned int i = 0; i < 20; i++) if(A1_P1[i] != i) std::cout << "ERROR 4" << std::endl;
	for(unsigned int i = 0; i < 10; i++) if(A1_P2[i] != 2 * i) std::cout << "ERROR 5" << std::endl;
}
