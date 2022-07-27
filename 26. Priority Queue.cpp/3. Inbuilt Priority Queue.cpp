#include<iostream>
using namespace std;
#include <queue>


int main()
{
    priority_queue<int> pq;
    pq.emplace(5);
    pq.emplace(4);
    pq.emplace(3);
    pq.emplace(2);
    pq.emplace(1);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    priority_queue<int, vector<int>, greater<int> > p;

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);

	while(!p.empty()) {
		cout << p.top() <<" ";
		p.pop();
	}
}