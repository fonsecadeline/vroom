#ifndef TSP_H
#define TSP_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

#include "../../structures/abstract/undirected_graph.h"
#include "../vrp.h"
#include "./heuristics/christofides.h"
#include "./heuristics/local_search.h"

class tsp : public vrp {
private:
  index_t _vehicle_rank;
  // Holds the matching from index in _matrix to rank in input::_jobs.
  std::vector<index_t> _job_ranks;
  bool _is_symmetric;
  bool _has_start;
  index_t _start;
  bool _has_end;
  index_t _end;
  matrix<cost_t> _matrix;
  matrix<cost_t> _symmetrized_matrix;
  bool _round_trip;

public:
  tsp(const input& input, std::vector<index_t> job_ranks, index_t vehicle_rank);

  cost_t cost(const std::list<index_t>& tour) const;

  cost_t symmetrized_cost(const std::list<index_t>& tour) const;

  virtual solution solve(unsigned nb_threads) const override;
};

#endif
