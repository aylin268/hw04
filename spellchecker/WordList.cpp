#include "WordList.h"
#include "Point.h"
#include <cctype>
#include <stdexcept>
#include <cmath>
#include <algorithm>




WordList::WordList(std::istream& stream){
    std::string word;
    std::set<std::string> seen;
    while (stream >> word) {
        bool valid = true;
        for (char c : word) {
            if (!std::islower(c)) {
                valid = false;
                break;
            }
        }
        if (valid && seen.find(word) == seen.end()) {
            mWords.push_back(word);
            seen.insert(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff)const{
    Heap heap(maxcount);

    for (const std::string& word : mWords) {
        if (word.length() != points.size()) continue;

        float scoreSum = 0.0f;

        for (size_t i = 0; i < points.size(); ++i) {
            Point letterPos = QWERTY[word[i] - 'a'];
            float dx = points[i].x - letterPos.x;
            float dy = points[i].y - letterPos.y;
            float d2 = dx * dx + dy * dy;
            float s = 1.0f / (10.0f * d2 + 1.0f);
            scoreSum += s;
        }

        float avgScore = scoreSum / points.size();
        if (avgScore < cutoff) continue;

        if (heap.count() < heap.capacity()) {
            heap.push(word, avgScore);
        } else if (avgScore > heap.top().score) {
            heap.pushpop(word, avgScore);
        }
    }

    return heap;
}
