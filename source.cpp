/*
 * source.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: jianwei
 */

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using std::vector;
using std::pair;

using point = pair<int,int>;

bool operator<(const pair<int,int> & p1, const pair<int,int> & p2) {
	if (p1.first != p2.first)
		return p1.first < p2.first;
	else if (p1.second != p2.second)
		return p1.second < p2.second;
	else
		return false;
}

class solution {
public:
	bool isReflected(const vector<point> & points) {
		std::set<point> pts;
		for (auto pt : points)
			pts.insert(pt);
		auto first = pts.begin();
		auto last = pts.rbegin();
		int mid = (first->first+last->first)/2;
		for (auto it = pts.begin(); it != pts.end(); ++it) {
			if (pts.find(std::make_pair(2*mid-it->first, it->second)) == pts.end())
				return false;
		}
		return true;
	}
};

int main() {
	vector<point> points;
	points.push_back(std::make_pair(1,1));
	points.push_back(std::make_pair(-1,1));
	
	solution soln;
	bool isReflected = soln.isReflected(points);
	if (isReflected)
		std::cout << "These points are reflected!" << std::endl;
	else
		std::cout << "These points are NOT reflected!" << std::endl;
}
