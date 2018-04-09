//
// Created by JHKim on 16/11/2017.
//
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <boost/dynamic_bitset.hpp>
using std::vector;
using std::map;
using std::set;
using boost::dynamic_bitset;
using std::cout;
using std::endl;

typedef int vid_t;
typedef int weight_t;
typedef float prob_t;
typedef std::string string;

const int vidSize= sizeof(vid_t);
const int weightSize = sizeof(weight_t);
const int probSize = sizeof(prob_t);

#endif
