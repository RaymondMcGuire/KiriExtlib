/***
 * @Author: Xu.WANG
 * @Date: 2021-11-24 14:59:53
 * @LastEditTime: 2021-11-24 16:23:02
 * @LastEditors: Xu.WANG
 * @Description:
 */
/***************************************************************************
 *   Developer: Francisco Martínez del Río (2012)                          *
 *   fmartin@ujaen.es                                                      *
 *   Version: 1.0                                                          *
 *                                                                         *
 *   This is a public domain program                                       *
 ***************************************************************************/

// Utility functions

#ifndef UTILITIES_H
#define UTILITIES_H

#include <algorithm>
#include <bop12/point_2.h>
#include <bop12/segment_2.h>

namespace cbop
{

	int findIntersection(const Segment_2 &seg0, const Segment_2 &seg1, Point_2 &ip0, Point_2 &ip1);

	/** Signed area of the triangle (p0, p1, p2) */
	inline float signedArea(const Point_2 &p0, const Point_2 &p1, const Point_2 &p2)
	{
		return (p0.x() - p2.x()) * (p1.y() - p2.y()) - (p1.x() - p2.x()) * (p0.y() - p2.y());
	}

	/** Signed area of the triangle ( (0,0), p1, p2) */
	inline float signedArea(const Point_2 &p1, const Point_2 &p2)
	{
		return -p2.x() * (p1.y() - p2.y()) - -p2.y() * (p1.x() - p2.x());
	}

	/** Sign of triangle (p1, p2, o) */
	inline int sign(const Point_2 &p1, const Point_2 &p2, const Point_2 &o)
	{
		float det = (p1.x() - o.x()) * (p2.y() - o.y()) - (p2.x() - o.x()) * (p1.y() - o.y());
		return (det < 0 ? -1 : (det > 0 ? +1 : 0));
	}

	inline bool pointInTriangle(const Segment_2 &s, const Point_2 &o, const Point_2 &p)
	{
		int x = sign(s.source(), s.target(), p);
		return ((x == sign(s.target(), o, p)) && (x == sign(o, s.source(), p)));
	}

} // end of namespace cbop
#endif
