class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
int maxSize;
    CustomStack(int maxSize) {
          this->maxSize = maxSize;
  // maxSize ki zarurat is approach mein directly nahi hai
    }

    void push(int x) {
        if(st.size() == maxSize)
    return;
        // normal stack mein push
        st.push_back(x);

        // is element ke liye initially koi increment nahi
        inc.push_back(0);
    }

    int pop() {
        if (st.empty()) {
            return -1;
        }

        int i = st.size() - 1;

        // is element ka pending increment
        int add = inc[i];

        // actual answer
        int answer = st[i] + add;

        // agar neeche element exist karta hai,
        // current ka increment usko pass karo
        if (i > 0) {
            inc[i - 1] += add;
        }

        // top element remove
        st.pop_back();
        inc.pop_back();

        return answer;
    }

    void increment(int k, int val) {
        if (st.empty()) {
            return;
        }

        // bottom k elements mein se
        // sabse upar wale affected element ka index
        int i = min(k, (int)st.size()) - 1;

        // bas marker lagao
        inc[i] += val;
    }
};