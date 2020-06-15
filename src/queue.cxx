#include "queue.hxx"

queue::queue(const Geometry geometry, int x)
        :head(x)
{
    q.push_back(head);
}

void queue::addToQueue(int i)
{
    q.push_back(i);
};

int queue::getLastItemIndex() {
    int answer = q[0];
    for (int i = 0; i+1 < q.size();i++){
        int temp = q[i];
        q[i] = q[i + 1];
        q[i + 1] = temp;

    }
    q.pop_back();
    return answer;
}
