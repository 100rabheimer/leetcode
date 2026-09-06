class CustomStack {
public:
    vector<int> st;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
        }
    }

    int pop() {
        if (st.empty()) {
            return -1;
        }

        int top = st.back();
        st.pop_back();

        return top;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)st.size());

        for (int i = 0; i < limit; i++) {
            st[i] += val;
        }
    }
};