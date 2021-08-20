#pragma once

using namespace std;

#include <random>
#include <algorithm>
#include <vector>

template <typename It>
void mt_shuffle(It first, It last)
{
	random_device rd;
	mt19937 g(rd());
	shuffle(first, last, g);
}

template <typename T>
void move_from_end_at(vector<T> &v, typename vector<T>::iterator it)
{
	if (it != end(v)) {
		v.insert(it, move(v.back()));
		v.pop_back();
	}
}
