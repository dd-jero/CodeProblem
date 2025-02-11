#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    using pii = pair<int, int>;
    set<pii, greater<>> s;
    long long current_sum = 0;
    long long min_sum = LLONG_MAX;

    // Initialize the first window
    for (int i = 0; i < K; ++i) {
        s.insert({ A[i], i + 1 });
    }

    // Calculate initial sum of distances
    if (s.size() >= 2) {
        auto prev = s.begin();
        auto curr = prev;
        ++curr;
        while (curr != s.end()) {
            current_sum += abs(prev->second - curr->second);
            ++prev;
            ++curr;
        }
    }
    min_sum = current_sum;

    // Slide the window
    for (int i = K; i < N; ++i) {
        // Remove the leftmost element
        int left_val = A[i - K];
        int left_pos = (i - K) + 1;
        auto it = s.find({ left_val, left_pos });

        if (it != s.end()) {
            auto prev_it = s.end();
            auto next_it = s.end();

            if (it != s.begin()) {
                prev_it = prev(it);
            }
            next_it = next(it);

            // Subtract distances involving the removed element
            if (prev_it != s.end()) {
                current_sum -= abs(prev_it->second - it->second);
            }
            if (next_it != s.end()) {
                current_sum -= abs(it->second - next_it->second);
            }

            // Add distance between prev and next if they exist
            if (prev_it != s.end() && next_it != s.end()) {
                current_sum += abs(prev_it->second - next_it->second);
            }

            s.erase(it);
        }

        // Add the new right element
        int new_val = A[i];
        int new_pos = i + 1;
        auto new_it = s.insert({ new_val, new_pos }).first;

        auto new_prev = s.end();
        auto new_next = s.end();

        if (new_it != s.begin()) {
            new_prev = prev(new_it);
        }
        new_next = next(new_it);

        // Subtract existing distance between new_prev and new_next if any
        if (new_prev != s.end() && new_next != s.end()) {
            current_sum -= abs(new_prev->second - new_next->second);
        }

        // Add new distances
        if (new_prev != s.end()) {
            current_sum += abs(new_prev->second - new_pos);
        }
        if (new_next != s.end()) {
            current_sum += abs(new_pos - new_next->second);
        }

        // Update minimum sum
        min_sum = min(min_sum, current_sum);
    }

    cout << min_sum << '\n';

    return 0;
}
