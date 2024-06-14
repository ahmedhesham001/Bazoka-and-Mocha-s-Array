/* TYPE OF CONTAINER
1. Simple ======> pair
2. Associative ======> map, set, multimap, multiset
3. Sequence ======> vector, deque, list, stack, queue, priority_queue
4. Container Adaptor ======> stack, queue, priority_queue
5. Unordered =====> Unordered map, Unordered set, Unordered multimap, Unordered multiset
================================================================================================================================
                                                                Vector
Vector is a dynamic array
v.push_back(5); store in the back of the vector
vector<int>v(5) =======> default value = 0
vector<int>v(5,100) =======> default value = 100
v.size(),v.capacity,v.swap(),v.max_size,v.empty() (bool value)
v.insert(v.begin(),x) ======> put the x in the front
sort(v.begin(),v.end()) ====> ascending
sort(v.rbegin(),v.rend()) ====> descending
min_element(v.begin(),v.end())
==================================================================================
to print vector element without loop:
copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
================================================================================================================================
Deque (Deck) =======> v.push_back,v.push_front OR v.emplace_back,v.emplace_front (faster than push).
v.pop_back,v.pop_front
================================================================================================================================
                                                                list
List ======================> Very fast in adding or removing from any position
l.remove(x); ==========> deleting the x as a value from all content in the list
l.erase(l.begin(),l.end()); ===========> delete the list values;
to erase some of values we can't write l.erase(l.begin()+1,l.end()-1)
auto it = l.begin();
it++;
l.erase(it,l.end());
list time ==========> O(1)
search =============> linearly O(n)
has no random access
====================================
l.assign(no. of repeat, repeated num);
l.merge(l2)=============> concat in l and sorting and clear l2
l.splice(l.begin(),l2)=======> concat in l at begin without sorting
l.unique()==========> remove duplicated elements
l.remove_if() ===========> present bool value
l.sort() ============> without algorithm
l.sort(greater<int>()) ============> sorting descending
================================================================================================================================
                                                                forward list
push_front() only
emplace_after(),emplace_front(),insert_after(),erase_after(),splice_after()
before_begin(),begin()

================================================================================================================================
                                                                    Set & Unordered set
                                                                    ======================
                                                                            Set
set is based on a balanced binary tree and its operations work in O(log(n)) time.
set structure is that it maintains the order of the elements and provides functions that are not available in unordered_set.
A set can be used mostly like a vector, but it is not possible to access the elements using the [] notation.
all their elements are distinct. Thus,the function count always returns either 0 (the element is not in the set) or 1 (the element is in the set).
        set<int> s;
        s.insert(5);
        s.insert(5);
        s.insert(5);
        cout << s.count(5) << "\n"; // 1
============================================
            multiset<int> s;
            s.insert(5);
            s.insert(5);
            s.insert(5);
            cout << s.count(5) << "\n"; // 3
The function erase removes all instances of an element from a multiset:
            s.erase(5);
            cout << s.count(5) << "\n"; // 0
Often, only one instance should be removed, which can be done as follows:
            s.erase(s.find(5));
            cout << s.count(5) << "\n"; // 2

                                                                    ======================
                                                                    unordered_set
unordered_set uses hashing, and its operations work in O(1) time on average.
unordered_set can be more efficient.
================================================================================================================================
                                                                    Map
A map is a generalized array that consists of key-value-pairs.
the structure map is based on a balanced binary tree and accessing elements takes O(log(n)) time, while the structure unordered_map
uses hashing and accessing elements takes O(1) time on average.

map<string,int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;
cout << m["banana"] << "\n"; // 3

If the value of a key is requested but the map does not contain it, the key is automatically added to the map with a default value.

map<string,int> m;
cout << m["aybabtu"] << "\n"; // 0

The function count checks if a key exists in a map:

if (m.count("aybabtu")) {
// key exists
}

The following code prints all the keys and values in a map:
for (auto x : m) {
cout << x.first << " " << x.second << "\n";
================================================================================================================================
                                                                    Iterators and ranges
An iterator is a variable that points to an element in a data structure.
The following code prints all the elements in a vector:

vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << "\n";
    }

The function find(x) returns an iterator that points to an element whose value is x. However, if the set does not contain x, the iterator will be end.

auto it = s.find(x);
if (it == s.end()) {
// x is not found
}
*/
#include <bits/stdc++.h>
#define ll long long
#define vi(v) vector<int>v
#define deck(d) deque<int>d;
#define li list<int>l;
#define fli forward_list<int>fl;
#define stck stack<int>st;
#define print(v) copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
#define input(v) copy(v.begin(),v.end(),istream_iterator<int>(cin));
#define copy1(v1,v2) copy(v1.begin(),v1.end(),back_inserter(v2));
#define limit ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
void bs(int n,vector<int>v,int x,int y){
    int m,cnt= v.size(),f=0;
    sort(v.begin(), v.end());
    auto l= lower_bound(v.begin(), v.end(),x);
    auto r= upper_bound(v.begin(), v.end(),y);
    cout<<r-l<<" ";
}
void sonic() {
    int n;
    cin>>n;
    deck(v);
    deck(vs);
    deck(vsub);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
        vs.push_back(x);
    }
    sort(vs.begin(), vs.end());
    for(int i=0;i<n;i++){
            vsub.clear();
            vsub.push_back(v[0]);
            v.pop_front();
            for(int j=0;j<vsub.size();j++){
                v.push_back(vsub[j]);
            }
            if(v==vs){
                cout<<"YES\n";return;
            }
    }
    cout<<"NO\n";
}
ll fac(int n){
    if(n==0)
        return 1;
    return n*fac(n-1);
}
bool isprime(ll x){
    if(x<=1)return 0;
    if(x<=3)return 1;
    if(x%2==0)return 0;
    for(ll i=3;i*i<x;i+=6){
        if(x%i==0||x%(i+2)==0)return 0;
    }
    return 1;
}
int main() {
    limit
    int t;
    cin>>t;
    while(t--)
    sonic();
}
