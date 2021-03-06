#ifndef HWSPMVFACTORY_H_
#define HWSPMVFACTORY_H_

#include <string>
#include "HardwareSpMV.h"

class HWSpMVFactory {
public:
	HWSpMVFactory();
	virtual ~HWSpMVFactory();

	static HardwareSpMV * make(unsigned int aBase, unsigned int aReset,
			SparseMatrix * A, SpMVData *x, SpMVData *y);

	static std::string name(unsigned int aBase);

};

#endif /* HWSPMVFACTORY_H_ */
