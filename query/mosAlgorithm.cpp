// 使用例は以下のmain関数に記載

// Mo's algorithm
struct Mo {
    int n;
    vector<pair<int, int>> lr;

    explicit Mo(int n) : n(n) {}

    // 区間[l,r)のクエリを追加する
    void add(int l, int r) { /* [l, r) */
        lr.emplace_back(l, r);
    }

    // 全てのクエリを処理する
    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        int q = (int) lr.size();
        int bs = n / min< int >(n, sqrt(q));
        vector< int > ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if(ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        int l = 0, r = 0;
        for(auto idx : ord) {
            while(l > lr[idx].first) add_left(--l);
            while(r < lr[idx].second) add_right(r++);
            while(l < lr[idx].first) erase_left(l++);
            while(r > lr[idx].second) erase_right(--r);
            out(idx);
        }
    }

    // 全てのクエリを処理する
    template< typename A, typename E, typename O >
        void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
};


// ABC242_G
// 数列Aが与えられたとき、区間[l,r]に同じ数字の2つからなるペアは最大で何組作れるか？
// 例:
// A = { 1, 2, 3, 2, 3, 1, 3, 1, 2, 3 }
// [l,r] = [1,10]
// 1が3つ、2が3つ、3が4つなので答えは4

// int main(void) {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     Mo mo(n);

//     int Q;
//     cin >> Q;
//     for (int i = 0; i < Q; i++) {
//         int l,r;
//         cin >> l >> r;
//         --l;
//         mo.add(l,r);
//     }

//     // Mo's algorithmの実装
//     vector<int> cnt(n+1), ans(Q);
//     int sum = 0;

//     auto add = [&](int i){
//         cnt[a[i]]++;
//         if (cnt[a[i]]%2 == 0) ++sum;
//     };
//     auto erase = [&](int i){
//         if (cnt[a[i]]%2 == 0) --sum;
//         cnt[a[i]]--;
//     };
//     auto out = [&](int q){
//         ans[q] = sum;
//     };
//     mo.build(add,erase,out);



//     for (auto p : ans) cout << p << endl;
    
//     return 0;
// }