#include "ge211.hxx"
#include "geometry.hxx"
#include "vector"



struct queue
{

    queue(Geometry const geometry, int index);

    void addToQueue(int i);

    int getLastItemIndex();

    int head;

    int tail;

    std::vector<int> q;

};