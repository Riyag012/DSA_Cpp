#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
/*
In C++, a hashmap is a data structure that stores key-value pairs, allowing for fast access, insertion, and deletion. The most commonly used hashmap implementation in C++ is std::unordered_map, which is part of the C++ Standard Library. Here's how it works:

-> Key-Value Pair: Each element in a hashmap consists of a key and a value. You can access the value by providing the key.
-> Hash Function: The key is passed through a hash function to compute a hash code, which determines where the key-value pair will be stored in memory.
-> Fast Access: Due to hashing, lookup, insertion, and deletion are typically done in O(1) time on average, making hashmaps very efficient.


std::unordered_map does not maintain the order of elements.
It uses hashing to store elements, which allows efficient operations.
Collisions can occur when two keys have the same hash value, and these are typically handled with techniques like chaining.
*/
int main(){
    // creation
    unordered_map<string, int> m;

    //insertion
    //1.
    pair<string, int> p = make_pair("riya", 2);
    m.insert(p);

    //2
    m["mera"] = 1;

    //3
    pair<string, int> pair2("love", 3);
    m.insert(pair2);

    //search
    cout<< m["mera"]<<endl;
    cout<< m.at("riya")<<endl;

    // cout<< m.at("unknownKey")<<endl; // error and code terminates
    cout<< m["unknownKey"]<<endl; //creates a hashmap and assings it value 0

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("riya")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //itertor
    // for (auto i:m){
    //     cout<< i.first << " " <<i.second<<endl;
    // }

    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<< it->first<<" "<<it->second<<endl;
        it++;
    }



    return 0;
}