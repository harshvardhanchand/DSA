// hashing is the fastest searching method
//  having O(1) time complexity
// drawback we have to create a big array i.e excess wasted space
// We can reduce hash table by various methods like h(x) = x%10 it can make the function many-one
// There are broadly two types of hashing
// Open hashing
// Closed hashing
// Chaining
// Size of hash table is same but the number of collisions is different for open and closed hashing
// Open hashing is used when we don't know the size of the hash table
// Closed hashing is used when we know the size of the hash table
// Chaining is used when we know the size of the hash table
// In chaining we have to create a linked list for each index of the hash table and then we can search the element in the linked list
// loading factor is the number of elements in the hash table divided by the size of the hash table
// Average time complexity of chaining is 1 + ln(n)/2 (successful search ) where n is the size of the hash table
// unsuccessful 1+ ln(n) (searching)

// Linear probing is a technique used to resolve collisions in hash tables.
// Linear probing is a closed hashing technique.
// Linear probing is used when we know the size of the hash table.
// formula for linear probing is h(x) = (h(x) + i) %mod m where h(x) is the hash function and i is the index of the current element.
//  For unsuccesful search we have to go to the next index of the hash table.
// If we get an empty space then search is unsuccessful.
// If we get a collision then search is unsuccessful.
// If we get a match then search is successful.
// loading factor in linear probing should be less than or equal to 0.5.
// t =1/loading factor *ln(1/1-loading factor)  avg succesful
// t= 1/1-loading factor  avg unsuccessful
// in double hashing we have to create a second hash function
// There are two other ideas for hash function which are folding hashing and midsquare
// In midsquare method we have to create a hash function which is a function of the key
// key is squared and then we have to take the mod of the hash table size
// In folding hashing we have to create a hash function which is a function of the key
// In folding we pair up digits from left to right and take their sum and then we have to take the mod of the hash table size