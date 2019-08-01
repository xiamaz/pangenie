#ifndef EMISSIONPROBABILITYCOMPUTER_H
#define EMISSIONPROBABILITYCOMPUTER_H

#include <vector>
#include <string>
#include <unordered_map>
#include "uniquekmers.hpp"
#include "copynumber.hpp"
#include "columnindexer.hpp"

/** 
* Computes the emission probabilities for a variant position.
**/

typedef std::vector<std::vector<long double>> ProbabilityMatrix;

class EmissionProbabilityComputer {
public:
	/**
	* @param uniquekmers all unique kmers for this position
	* @param columnindexer for this position
	 **/
	EmissionProbabilityComputer(UniqueKmers* uniquekmers, ColumnIndexer* columnindexer);
	/** get emission probability for a state in the HMM **/
	long double get_emission_probability(size_t state) const;

private:
	UniqueKmers* uniquekmers;
	bool all_zeros;
	ColumnIndexer* columnindexer;
	ProbabilityMatrix state_to_prob;
	long double compute_emission_probability(unsigned char allele1, unsigned char allele2);
};
# endif // EMISSIONPROBABILITYCOMPUTER_H
