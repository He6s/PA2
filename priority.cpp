/*
* File:        priority.cpp
* Description: Implements a priority ordering structure specially made for determining the
*              order of neighbours visited in PA2's filler::fill function.
*              Note that this does NOT serve the same purpose as the stack/queue
*              ordering structure which you have also been asked to implement.
*
*              Ignoring resize costs, any single insertion or removal operation
*              should cost at most O(n), where n is the number of PixelPoints
*              stored in the collection.
*
* Date:        2022-02-10 02:04
*
*/

#include "priority.h"
#include <assert.h>

using namespace cs221util;
using namespace std;

/*
*  Default constructor
*  Initializes refcolor to the default color according to the HSLAPixel implementation.
*/
PriorityNeighbours::PriorityNeighbours() {
    // complete your implementation below
    refcolor = HSLAPixel();
}

/*
*  Parameterized constructor
*  Initializes refcolor to the supplied value.
*/
PriorityNeighbours::PriorityNeighbours(HSLAPixel ref) {
    // complete your implementation below
    refcolor = ref;
}

/*
*  Inserts an item into the collection
*  PARAM: p - item to be inserted
*  POST:  the collection contains p, along with all previously existing items.
*/
void PriorityNeighbours::Insert(PixelPoint p) {
    // complete your implementation below
    if (IsEmpty()) {
        points.push_back(p);
        return;
    }
    int i = 0;
    while (true) {
        if (p.y > points.at(i).y) {
            i++;
            continue;
        }
        if (p.x > points.at(i).x) {
            i++;
            continue;
        }
        auto position = points.begin() + i;
        points.insert(position, p);
        return;
    }
}

/*
*  Removes and returns an item from the collection satisfying the priority condition
*  PRE:    the collection is not empty (but it would be good to check anyway!).
*  POST:   the item satisfying the priority condition is removed from the collection.
*  RETURN: the item satisfying the priority condition
*
*  Priority condition:
*    The PixelPoint in the collection whose color is the minimum distance away
*    from the reference color is the priority item to be returned.
*
*    In case of multiple items with the same priority value (i.e. minimal distance
*    away from the reference color), the one with the minimal y-coordinate will be
*    selected.
*    In case of multiple items with the same priority value and the same y-coordinate,
*    the one with the minimal x-coordinate will be selected.
*
*    ***ATTENTION*** The dist() function in HSLAPixel.h will be very helpful!
*
*  Combined with Insert(), think about the time complexity of maintaining the
*  priority order and/or accessing the priority element in this specific application!
*/
PixelPoint PriorityNeighbours::Remove() {
    // complete your implementation below
    if (IsEmpty()) {
        return;
    }
    int i = 0;
    PixelPoint p;
    double dist;
    p = points.at(i);
    dist = abs(dist(p.color) - dist(ref));
    i++;
    while (points.at(i) != NULL) {
        if (abs(dist(points.at(i).color) - dist(ref)) < dist) {
            p = points.at(i);
            dist = abs(dist(points.at(i).color) - dist(ref));
        }
        i++;
    }
    points.erase(points.begin() + i - 1);
    return p;
}

/*
*  Checks if the collection is empty
*  RETURN: true, if the collection is empty
*          false, otherwise
*/
bool PriorityNeighbours::IsEmpty() const {
    // complete your implementation below
    return points.empty();
}

/*
*  Returns the value of the reference color
*/
HSLAPixel PriorityNeighbours::GetReferenceColor() const {
    // complete your implementation below
    return refcolor;
}

/*
*  Sets the reference color attribute
*  POST: refcolor is set to the supplied value
*/
void PriorityNeighbours::SetReferenceColor(HSLAPixel ref) {
    // complete your implementation below
    refcolor = ref;
}