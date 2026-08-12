class TreeAncestor {
public:

    // up[node][j] =
    // node se 2^j steps upar wala ancestor
    vector<vector<int>> up;

    int LOG;

    TreeAncestor(int n, vector<int>& parent) {

        // Maximum k kitna ho sakta hai uske according
        // log2(n) levels enough hain
        LOG = 20;

        up.resize(n, vector<int>(LOG, -1));

        // 2^0 = 1 step ancestor
        for(int node = 0; node < n; node++) {
            up[node][0] = parent[node];
        }

        // Binary lifting table build karo
        for(int j = 1; j < LOG; j++) {

            for(int node = 0; node < n; node++) {

                int middle = up[node][j - 1];

                if(middle != -1) {
                    up[node][j] = up[middle][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        // k ke bits check karo
        for(int j = 0; j < LOG; j++) {

            // Agar k ka j-th bit set hai
            if(k & (1 << j)) {

                node = up[node][j];

                // Ancestor exist nahi karta
                if(node == -1)
                    return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */