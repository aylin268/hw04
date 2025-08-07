#include "Heap.h"
#include <iostream>
#include <cassert>
#include <stdexcept>
using namespace std;

    //heap class interface 
    // Heap(size_t capacity);
    // Heap(const Heap& other);
    // Heap(Heap&& other);
    // ~Heap();

    // size_t       capacity() const;
    // size_t       count() const;
    // const Entry& lookup(size_t index) const;
    // Entry        pop();
    // Entry        pushpop(const std::string& value, float score);
    // void         push(const std::string& value, float score);
    // const Entry& top() const;

int main() {

    // float f_1 = 0.0041
    // float f_2 = 0.0041
    // float f_3 = 0.2664
    // float f_4 = 0.4469
    // float f_5 = 0.5786
    // float f_6 =
    // float f_7 =
    // float f_8 =

    Heap heap(8);

    assert(heap.capacity() == 8);
    assert(heap.count() == 0);

    // exceptions (basic) (incomplete)
    //heap.pop(); (good)

    //push tests
    heap.push("ab", 1.0); //works
    assert(heap.top().score == 1.0);
    assert(heap.top().value == "ab");

    heap.push("cd", 0.2664);
    heap.push("ef", 0.5786);
    heap.push("gh", 0.4469);
    heap.push("ij", 0.7247);
    heap.push("kl", 0.8985);
    heap.push("mn", 0.0041);
    heap.push("op", 0.0041);

    assert(heap.capacity() == 8);
    assert(heap.count() == 8);
    assert(heap.count() == heap.capacity());

    // cout << heap.lookup(0).score << endl;
    cout << "printing after multiple pushes:\n";
    cout << heap.lookup(0).score << endl;
    cout << (heap.lookup(1).score ) << endl;
    cout << (heap.lookup(2).score )<< endl;
    cout << (heap.lookup(3).score )<< endl;
    cout << (heap.lookup(4).score )<< endl;
    cout << (heap.lookup(5).score )<< endl;
    cout << (heap.lookup(6).score )<< endl;
    cout << (heap.lookup(7).score )<< endl;
    // (binary tree seems is valid for this case)

    assert(heap.lookup(0).value == "mn");
    assert(heap.lookup(1).value == "op");
    assert(heap.lookup(2).value == "cd");
    assert(heap.lookup(3).value == "gh");
    assert(heap.lookup(4).value == "ij");
    assert(heap.lookup(5).value == "kl");
    assert(heap.lookup(6).value == "ef");
    assert(heap.lookup(7).value == "ab");

    assert(heap.top().value == "mn");

    //should throw exception
    //heap.push("op", 0.0041); //std::overflow
    //cout << heap.lookup(-1).score << endl; //std::out_of_range
    //cout << heap.lookup(8).score << endl; //std::out_of_range

    cout << "push tests complete\n";

    //copy constructor
    Heap heap_copy(heap);

    assert(heap_copy.lookup(0).value == "mn");
    assert(heap_copy.lookup(1).value == "op");
    assert(heap_copy.lookup(2).value == "cd");
    assert(heap_copy.lookup(3).value == "gh");
    assert(heap_copy.lookup(4).value == "ij");
    assert(heap_copy.lookup(5).value == "kl");
    assert(heap_copy.lookup(6).value == "ef");
    assert(heap_copy.lookup(7).value == "ab");

    assert(heap_copy.top().value == "mn");
    cout << "copy constructor test complete\n";


    // //move constructor
    // Heap heap_move(std::move(heap));
    // assert(heap_move.lookup(0).value == "mn");
    // assert(heap_move.lookup(1).value == "op");
    // assert(heap_move.lookup(2).value == "cd");
    // assert(heap_move.lookup(3).value == "gh");
    // assert(heap_move.lookup(4).value == "ij");
    // assert(heap_move.lookup(5).value == "kl");
    // assert(heap_move.lookup(6).value == "ef");
    // assert(heap_move.lookup(7).value == "ab");
    // cout << "move constructor test complete\n";


    //pop tests

    // pop #1
    cout << "pop1 \n";
    cout << "pop score: " <<  heap.pop().score << endl; //should be 0.0041
    cout  << "new top: " << heap.top().value << endl; //should be op
    assert(heap.capacity() == 8);
    assert(heap.count() == 7);

    // (tree looks ok)
    // cout << heap.lookup(0).score << endl;
    // cout << (heap.lookup(1).score ) << endl;
    // cout << (heap.lookup(2).score )<< endl;
    // cout << (heap.lookup(3).score )<< endl;
    // cout << (heap.lookup(4).score )<< endl;
    // cout << (heap.lookup(5).score )<< endl;
    // cout << (heap.lookup(6).score )<< endl;
    // cout << (heap.lookup(7).score )<< endl; //throws

    //pop #2
    cout << "pop2 \n";
    cout << "pop score: " <<  heap.pop().score << " should be 0.0041" << endl;
    cout  << "new top: " << heap.top().score << " should be 0.2664" << endl; 
    cout  << "new top: " << heap.top().value << " should be cd" << endl; 
    assert(heap.capacity() == 8);
    assert(heap.count() == 6);

    // (tree looks ok)
    // cout << heap.lookup(0).score << endl;
    // cout << (heap.lookup(1).score ) << endl;
    // cout << (heap.lookup(2).score )<< endl;
    // cout << (heap.lookup(3).score )<< endl;
    // cout << (heap.lookup(4).score )<< endl;
    // cout << (heap.lookup(5).score )<< endl;
    // cout << (heap.lookup(6).score )<< endl; //throws

    cout << "remaining pops\n";
    cout << "pop 3: " <<  heap.pop().score << " should be 0.2664" << endl;
    cout << "pop 4: " <<  heap.pop().score << " should be 0.4469" << endl;
    cout << "pop 5: " <<  heap.pop().score << " should be 0.5786" << endl;
    cout << "pop 6: " <<  heap.pop().score << " should be 0.7247" << endl;
    cout << "pop 7: " <<  heap.pop().score << " should be 0.8985" << endl;
    cout << "pop 8: " <<  heap.pop().score << " should be 1" << endl;
    cout << "all pops complete\n";

    assert(heap.capacity() == 8);
    assert(heap.count() == 0);

    //repopulate heap
    cout << "repopulating heap\n";

    heap.push("ab", 1.0); //works
    assert(heap.top().score == 1.0);
    assert(heap.top().value == "ab");

    heap.push("cd", 0.2664);
    heap.push("ef", 0.5786);
    heap.push("gh", 0.4469);
    heap.push("ij", 0.7247);
    heap.push("kl", 0.8985);
    heap.push("mn", 0.0041);
    heap.push("op", 0.0041);

    assert(heap.capacity() == 8);
    assert(heap.count() == 8);
    assert(heap.count() == heap.capacity());

    //pop pop push
    heap.pop();
    heap.pop();
    heap.push("qr", 0.0);

    assert(heap.capacity() == 8);
    assert(heap.count() == 7);

    //tree looks good
    // cout << heap.lookup(0).score << endl;
    // cout << (heap.lookup(1).score ) << endl;
    // cout << (heap.lookup(2).score )<< endl;
    // cout << (heap.lookup(3).score )<< endl;
    // cout << (heap.lookup(4).score )<< endl;
    // cout << (heap.lookup(5).score )<< endl;
    // cout << (heap.lookup(6).score )<< endl;

    //pushpop tests
    //Entry        pushpop(const std::string& value, float score);

    //pushpop 1
    cout << "pushpop 1\n";
    heap.pushpop("st", 0.1);

    assert(heap.capacity() == 8);
    assert(heap.count() == 7);

    //tree looks good
    // cout << heap.lookup(0).score << endl;
    // cout << (heap.lookup(1).score ) << endl;
    // cout << (heap.lookup(2).score )<< endl;
    // cout << (heap.lookup(3).score )<< endl;
    // cout << (heap.lookup(4).score )<< endl;
    // cout << (heap.lookup(5).score )<< endl;
    // cout << (heap.lookup(6).score )<< endl;


    //pushpop 2
    cout << "pushpop 2\n";
    heap.pushpop("uv", 0.8);

    assert(heap.capacity() == 8);
    assert(heap.count() == 7);

    //tree look good
    // cout << heap.lookup(0).score << endl;
    // cout << (heap.lookup(1).score ) << endl;
    // cout << (heap.lookup(2).score )<< endl;
    // cout << (heap.lookup(3).score )<< endl;
    // cout << (heap.lookup(4).score )<< endl;
    // cout << (heap.lookup(5).score )<< endl;
    // cout << (heap.lookup(6).score )<< endl;

    cout << "All Tests Complete" << endl;
    return 0;
}
