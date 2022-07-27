#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// setting in windows
// set file in .hpp format

// Works like set in c

// If I want add duplicate elements, so I have to use pair or anything to correctly indentify an element
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
// tree_order_statistics_node_update> PBDS;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> PBDS;


int main()
{
    PBDS st;
    st.insert(1);
    st.insert(3);
    st.insert(4);
    st.insert(10);
    st.insert(15);

    for(int i=0; i< st.size(); i++)
    {
        cout<<i<<" "<<*st.find_by_order(i)<<"\n";
    }
    cout<<st.order_of_key(5)<<"\n";
    return 0;
}

// Inversion Count
